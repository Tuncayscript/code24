! ###########################################################################
!     RESUME : For a given array of values 'xx_value' for the               !
!              abscissa, then return the ordinate array values of           !
!              'yy_value' based on a linear interpolation within a          !
!              table of pair values [xold_vec, yold_vec]. This              !
!              subroutine assumes that the values in the array              !
!              xold_vec increases monotonically with yold_vec. There        !
!              is a trick to increase efficiency by remembering the         !
!              table points used in the last call                           !
!              (ilastval). Actually, it does not make a huge                !
!              difference. However, this should be used with                !
!              care. Whenever the data set is changed it is highly          !
!              recommended to set ilastval as a negative number (e.g.:      !
!              islastval = -999) in order to reset the table                !
!              indexing. The values xold_vec and yold_vec are arrays        !
!              and their length is nold_vec. If an interpolated point       !
!              lies outside the pair of elements (xold_vec,yold_vec),       !
!              then a zero value is returned.                               !
!                                                                           !
!     Input           arguments = 6                                         !
!     Output          arguments = 3                                         !
!     Optional        arguments = 1                                         !
!     Total number of arguments = 10                                        !
!                                                                           ! 
!     INPUT  : 01) xx_value  -> New interpolated x array with points        !
!              02) nxyvalue  -> # of elements in xx_value and yy_value      !
!              02) xold_vec  -> Old x vector (abcissas)                     !
!              03) yold_vec  -> Old y vector (ordenadas)                    !
!              04) nold_vec  -> # of elements in xold_vec and yold_vec      !
!              05) ilastval  -> Last integer number used and stored         !
!              07) verbosity -> Print & Check screen                        !
!                                                                           !
!     OUTPUT : 01) yy_value -> New interpolated y array with points         !
!              02) ilastval  -> Last integer number used and stored         !
!              03) IsKeepOn  -> [1: Executed, 0: Problem]                   !  
!                                                                           !
!     PYTHON : Python compatibility using f2py revised. Better usage        !
!              with numpy.                                                  !
!                                                                           !
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
SUBROUTINE LINinterpol( xx_value,yy_value,nxyvalue,xold_vec,yold_vec,       &
                        nold_vec,ilastval,IsKeepOn,verbosity )

    use ModDataType

    implicit none
    integer  (kind=IB), intent(in out) :: ilastval
    integer  (kind=IB), intent(in) :: nold_vec, nxyvalue
    integer  (kind=IB), intent(out) :: IsKeepOn
    integer  (kind=IB), optional :: verbosity
    integer  (kind=IB) :: in_loop1,in_loop2,ilastnum,IsShowOn

    real     (kind=RP), dimension(0:nold_vec-1), intent(in) :: xold_vec,yold_vec
    real     (kind=RP), dimension(0:nxyvalue-1), intent(in) :: xx_value
    real     (kind=RP), dimension(0:nxyvalue-1), intent(out) :: yy_value

    real     (kind=RP) :: width_dx
    character (len=CH) :: W1aux,W2aux,W3aux,W4aux

    !f2py real     (kind=RP), intent(in) :: xold_vec
    !f2py real     (kind=RP), intent(in) :: yold_vec
    !f2py integer  (kind=IB), intent(hide), depend(xold_vec) :: nold_vec=shape(xold_vec,0)

    !f2py real     (kind=RP), intent(in)  :: xx_value 
    !f2py real     (kind=RP), intent(out) :: yy_value 
    !f2py integer  (kind=IB), intent(hide), depend(xx_value) :: nxyvalue=shape(xx_value,0)

    !f2py integer  (kind=IB), intent(out) :: IsKeepOn
    !f2py integer  (kind=IB), intent(out) :: ilastval

    !f2py integer  (kind=IB), optional :: verbosity=0
    
    save ilastnum
    data ilastnum/1/

    if ( ilastval < 0_IB ) then
        ilastnum = -1_IB
        ilastval = -1_IB
    else
        ilastval = ilastnum
    end if

    if ( present(verbosity) ) then
        IsShowOn = verbosity
    else
        IsShowOn = 0_IB
    end if

    IsKeepOn = 1_IB
    if ( nold_vec < 1 ) then
       if ( IsShowOn == 1_IB ) then
          write (*,'(4x,a)') '[PROBLEM_INT] @@@@@@@@@@@@@@@@@@@@@@@@'
          write (*,'(4x,a)') '[LINinterpol] nold_vec < 1 dimension @'
       end if
       yy_value = -999.0_RP    
       IsKeepOn = 0_IB
       return
    end if
    
! *** Start the search from the last point of table use index ***************
    do in_loop2=0,nxyvalue-1
    
! --- Warranty that ilastnum cannot start with a higher value than nold_vec !
       if ( ilastnum + 1 > nold_vec-1 ) then
          ilastnum = nold_vec - 1
       end if
! --- Warranty that ilastnum cannot start with a higher value than nold_vec !

       if ( xx_value(in_loop2) <= xold_vec(ilastnum+1) ) then

! *** Search down the table from point of last use **************************

          in_loop1 = ilastnum + 1
          do while ( in_loop1 >= 0 .AND. xx_value(in_loop2) < xold_vec(in_loop1) )
             in_loop1 = in_loop1 - 1
             
             if ( in_loop1 < 0_IB ) then
                if ( IsShowOn == 1_IB ) then
                   write (W1aux,'(e14.4)') xx_value(in_loop2)
                   write (W2aux,'(e14.4)') xold_vec(0)
                   write (*,'(4x,a)')                                       &
                                     '[PROBLEM_INT] @@@@@@@@@@@@@@@@@@@@@@@@'
                   write (*,'(4x,a)')                                       &
                                     '[LINinterpol] Out of allowed range @@@'
                   write (*,'(4x,4(a))')                                    &
                               '[LINinterpol] ',trim(adjustl(W1aux)),' < ', &
                        trim(adjustl(W2aux))
                   !write (*,'(4x,a)')                                       &
                   !                  '[LINinterpol] LINinterpol set = 0.0 @@'
                end if
                !yy_value(in_loop2) = 0.0_RP
                !return
             end if
             
          end do
          
       else

! *** Search up the table from point of last use ****************************

          in_loop1 = ilastnum - 1
          do while ( in_loop1 <= nold_vec-1 .AND.                           &
                     xx_value(in_loop2) > xold_vec(in_loop1+1) )
             in_loop1 = in_loop1 + 1
             if ( in_loop1 > nold_vec-1 ) then
                if ( IsShowOn == 1_IB ) then
                   write (W1aux,'(e14.4)') xx_value(in_loop2)
                   write (W2aux,'(e14.4)') xold_vec(nold_vec-1)
                   write (*,'(4x,a)')                                       &
                                     '[PROBLEM_INT] @@@@@@@@@@@@@@@@@@@@@@@@'
                   write (*,'(4x,a)')                                       &
                                     '[LINinterpol] Out of allowed range @@@'
                   write (*,'(4x,4(a))')                                    &
                               '[LINinterpol] ',trim(adjustl(W2aux)),' < ', &
                               trim(adjustl(W1aux))
                   !write (*,'(4x,a)')                                       &
                   !            '[LINinterpol] LINinterpol set = 0.0 @@'
                end if
                !yy_value(in_loop2) = 0.0_RP
                !return
             end if
          end do
          
       end if

! *** Bounding points found, interpolate ************************************

       if ( in_loop1 > nold_vec-2 ) then
          in_loop1 = nold_vec-2
          !in_loop2 = nold_vec-1
       end if
       if ( in_loop1 < 0_IB ) then
          in_loop1 = 0_IB
          !in_loop2 = 1_IB
       end if

       !write (*,*) in_loop1,in_loop2,xold_vec(in_loop1),xx_value(in_loop2),xold_vec(in_loop1+1)
       
       width_dx = ( xx_value(in_loop2)   - xold_vec(in_loop1) )             &
                / ( xold_vec(in_loop1+1) - xold_vec(in_loop1) )
       yy_value(in_loop2) = (1-width_dx) * yold_vec(in_loop1)               &
                          + width_dx * yold_vec(in_loop1+1)
       ilastnum = in_loop1
       
       if ( IsShowOn == 1_IB ) then
          if ( in_loop2 == 1_IB ) then
             write (*,'(4x,a)') '[LINinterpol]'
          end if
          write (W1aux,'(f15.4)') xx_value(in_loop2)
          write (W2aux,'(f15.4)') yy_value(in_loop2)
          write (W3aux,'(i15)') ilastnum
          write (W4aux,'(i15)') ilastval
          write (*,'(4x,a,a,a,a)') '... xx_value(in_loop2): ',              &
                  trim(adjustl(W1aux)),' ==> yy_value: ',trim(adjustl(W2aux))
          write (*,'(4x,a,a)') '... ilastnum: ',trim(adjustl(W3aux))
          write (*,'(4x,a,a)') '... ilastval: ',trim(adjustl(W4aux))
       end if

    end do
    if ( IsShowOn == 1_IB ) then
       write (*,'(4x,a)') '[LINinterpol]'
    end if

    ilastval = ilastnum

    return

END SUBROUTINE LINinterpol
! ###########################################################################

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
SUBROUTINE author_LINterpol( a )
  use ModDataType

  implicit none
  
  character (len=21), intent(out) :: a

  !f2py intent(out) :: a

  a = 'Written by Tunjay Akbarli'
  
END SUBROUTINE author_LINterpol

! *** Test ******************************************************************
!          PROGRAM GeneralTest
!            use ModDataType
!            implicit none
!            integer  (kind=IB) :: i,j,n
!            integer  (kind=IB), parameter :: Nl_max=80000
!            integer  (kind=IB) :: IsKeepOn,Int_Type,ilastval
!            real     (kind=RP), dimension(Nl_max) :: l,f,e,m
!            real     (kind=RP) :: int,lambda_i,lambda_f,ll1,ff1,ll2,ff2
!
!           END PROGRAM GeneralTest
! *** Test ******************************************************************

! *** Number : 002                                                          !
!
! 1) LINinterpol
! 2) author_LINterpol
