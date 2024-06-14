! ###########################################################################
!     RESUME : Define type of variables to be used in functions,            !
!              subroutines or other modules.                                !
!                                                                           !
!                                                                           !
!              This module is defined to simplify to single precision real  !
!              variables.                                                   !
!                                                                           !
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
MODULE ModDataType

  !use, intrinsic :: iso_fortran_env, only: RP => real64
  
  integer  (kind=4), parameter :: IB=4,SP=4,RP=8,LB=8,QP=16,CH=300,ST=4,    &
                                  EC=1200

END MODULE ModDataType
