with Ada.Characters.Handling;
with Ada.Command_Line;
with Ada.Exceptions;
with Ada.Text_IO; use Ada.Text_IO;
with GNAT.Command_Line;
with GNAT.Directory_Operations;
with GNAT.OS_Lib;

with Code; use Code;
with Code.Ada_Environments;
with Code.Compilation_Units;
with Code.Exceptions;
with Code.Implementation;

with DOM.Core.Nodes;

with XML_Support;

procedure Code2XML is

   function "+" (Item : String) return Wide_String
     renames Ada.Characters.Handling.To_Wide_String;

   procedure Usage;
   procedure Usage is
   begin
      Put_Line (Standard_Error,
                "usage: " &
                  Ada.Command_Line.Command_Name
                  & " [flags] directory|unit.adt");
      Put_Line (Standard_Error, "flags:");
      Put_Line (Standard_Error, "-h          produce this output");
   end Usage;

   --  Some global variables.
   SS_Context : Code.Context;

   XI : XML_Support.Info;
   Impl : DOM.Core.DOM_Implementation;
   Doc : DOM.Core.Document;

begin

   Code.Implementation.Initialize ("-Code05");

   begin
      loop
         case GNAT.Command_Line.Getopt ("h") is
            when ASCII.NUL => exit;
            when 'h' =>
               Usage;
               return;
            when others => null;
               --  can't actually happen, raises Invalid_Switch
         end case;
      end loop;
   exception
      when GNAT.Command_Line.Invalid_Switch =>
         Usage;
         Ada.Command_Line.Set_Exit_Status (Ada.Command_Line.Failure);
         return;
   end;

   declare
      File_Name : constant String := GNAT.Command_Line.Get_Argument;
   begin
      if File_Name'Length = 0 then
         Usage;
         Ada.Command_Line.Set_Exit_Status (Ada.Command_Line.Failure);
         return;
      elsif GNAT.OS_Lib.Is_Directory (File_Name) then
         Code.Ada_Environments.Associate
           (The_Context => SS_Context,
            Name => "SS_Context",
            Parameters  => "-SN -CA -FT -T" & (+File_Name));
      elsif GNAT.Directory_Operations.File_Extension (File_Name) = ".adt" then
         Code.Ada_Environments.Associate
           (The_Context => SS_Context,
            Name => "SS_Context",
            Parameters  => "-SN -C1 " & (+File_Name));
      else
         Usage;
         Ada.Command_Line.Set_Exit_Status (Ada.Command_Line.Failure);
         return;
      end if;
   end;

   Code.Ada_Environments.Open (SS_Context);

   Doc  := DOM.Core.Create_Document (Impl);
   XML_Support.Initialize (XI, Doc);

   declare
      Next_Unit : Code.Compilation_Unit;
      All_Units : constant Code.Compilation_Unit_List
        := Code.Compilation_Units.Compilation_Units (SS_Context);
   begin
      for I in All_Units'Range loop
         Next_Unit := All_Units (I);
         if Code.Compilation_Units.Unit_Origin (Next_Unit)
           = Code.An_Application_Unit then
            XML_Support.Add_Compilation_Unit (The_Unit => Next_Unit,
                                              To => XI);
         end if;
      end loop;
   end;

   XML_Support.Finalize (XI);

   Code.Ada_Environments.Close (SS_Context);
   Code.Ada_Environments.Dissociate (SS_Context);
   Code.Implementation.Finalize ("");

   DOM.Core.Nodes.Print (Doc,
                         Print_Comments => True,
                         Print_XML_PI => True,
                         EOL_Sequence => "");

exception

   when Code.Exceptions.Code_Inappropriate_Compilation_Unit =>
      Put_Line (Standard_Error,
                "The input does not contain any Ada unit.");
      Usage;
      Ada.Command_Line.Set_Exit_Status (Ada.Command_Line.Failure);

   when Code.Exceptions.Code_Failed |
        Code.Exceptions.Code_Inappropriate_Element |
        Code.Exceptions.Code_Inappropriate_Context =>
      Put_Line (Standard_Error,
                Ada.Characters.Handling.To_String
                  (Code.Implementation.Diagnosis));
      Ada.Command_Line.Set_Exit_Status (Ada.Command_Line.Failure);

   when E : others =>
      Put_Line (Standard_Error,
                "exception received : " &
                 Ada.Exceptions.Exception_Message (E));
      Ada.Command_Line.Set_Exit_Status (Ada.Command_Line.Failure);

end Code2XML;
