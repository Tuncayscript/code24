with Ada.Characters.Handling;
with Ada.Text_IO; use Ada.Text_IO;
pragma Warnings (Off, Ada.Text_IO);

with Code.Compilation_Units;
with Code.Declarations;
with Code.Elements;
with Code.Expressions;
with Code.Iterator;

with DOM.Core.Nodes;
with DOM.Core.Documents;
with DOM.Core.Elements;

package body XML_Support is

   ------------------------------
   --  Local subprogram specs  --
   ------------------------------

   --  Wide_String => String conversion.
   function "+" (Item : Wide_String) return String;

   --  Traits (see Code spec) are an additional classification
   --  mechanism that lets Code use fewer high-level elements. Not
   --  every A_Definition element supports traits, and not every trait
   --  is applicable in all circumstances. This code assumes that the
   --  Code tree is well-formed, so if a trait is present it is legal
   --  and we just add the corresponding attribute to the DOM tree.
   procedure Add_Trait (K : Code.Trait_Kinds; To : DOM.Core.Node);

   --  Conversion of Code enumeration literals, typically A_Thing or
   --  An_Object, to our canonical form (leading article removed, all
   --  lower case).
   function To_Tag_Name (Image : String) return String;

   --  Tree traversal
   procedure Pre (Element : in Code.Element;
                  Control : in out Code.Traverse_Control;
                  State : in out Info);
   procedure Post (Element : in Code.Element;
                   Control : in out Code.Traverse_Control;
                   State : in out Info);
   procedure Traverse_Tree_For_XML is new Code.Iterator.Traverse_Element
     (XML_Support.Info,
      XML_Support.Pre,
      XML_Support.Post);


   ---------------------------------------
   --  Spec subprogram implementations  --
   ---------------------------------------

   procedure Add_Compilation_Unit (The_Unit : Code.Compilation_Unit;
                                   To : in out Info) is
      The_Control : Code.Traverse_Control := Code.Continue;
      Starting : constant DOM.Core.Node := To.Current;
      --  Remember the starting node (will be <Code/>)
      Unit : DOM.Core.Node;
   begin

      --  Add the <compilation_unit/> element.
      Unit := DOM.Core.Nodes.Append_Child
        (Starting,
         DOM.Core.Documents.Create_Element (To.Document, "compilation_unit"));
      DOM.Core.Elements.Set_Attribute
        (Unit,
         "unit",
         +Code.Compilation_Units.Unit_Full_Name (The_Unit));
      DOM.Core.Elements.Set_Attribute
        (Unit,
         "file",
         +Code.Compilation_Units.Text_Name (The_Unit));

      --  Add the context clauses (if any).
      declare
         Context_Clauses : constant Code.Context_Clause_List
           := Code.Elements.Context_Clause_Elements
           (Compilation_Unit => The_Unit,
            Include_Pragmas => True);
         Context : constant DOM.Core.Node
           := DOM.Core.Nodes.Append_Child
           (Unit,
            DOM.Core.Documents.Create_Element (To.Document,
                                               "context_clauses"));
      begin
         for C in Context_Clauses'Range loop
            To.Current := Context;
            Traverse_Tree_For_XML (Context_Clauses (C),
                                   The_Control,
                                   To);
         end loop;
      end;

      --  Add the declaration.
      To.Current := DOM.Core.Nodes.Append_Child
        (Unit,
         DOM.Core.Documents.Create_Element (To.Document, "unit_declaration"));
      Traverse_Tree_For_XML (Code.Elements.Unit_Declaration (The_Unit),
                             The_Control,
                             To);

      --  Add the compilation pragmas (if any).
      declare
         Compilation_Pragmas : constant Code.Pragma_Element_List
           := Code.Elements.Compilation_Pragmas (The_Unit);
         Pragmas : constant DOM.Core.Node
           := DOM.Core.Nodes.Append_Child
           (Unit,
            DOM.Core.Documents.Create_Element (To.Document,
                                               "compilation_pragmas"));
      begin
         for C in Compilation_Pragmas'Range loop
            To.Current := Pragmas;
            Traverse_Tree_For_XML (Compilation_Pragmas (C),
                                   The_Control,
                                   To);
         end loop;
      end;

      --  Restore the starting node.
      To.Current := Starting;

   end Add_Compilation_Unit;


   procedure Initialize (XI : in out Info;
                         Document : DOM.Core.Node) is
   begin
      XI.Document := Document;
      XI.Current := DOM.Core.Nodes.Append_Child
        (XI.Document,
         DOM.Core.Documents.Create_Element (XI.Document, "Code"));
   end Initialize;


   procedure Finalize (XI : in out Info) is
      pragma Unreferenced (XI);
   begin
      null;
   end Finalize;


   ----------------------------------------
   --  Local subprogram implementations  --
   ----------------------------------------

   function "+" (Item : Wide_String) return String is
   begin
      return Ada.Characters.Handling.To_String (Item);
   end "+";


   procedure Add_Trait (K : Code.Trait_Kinds; To : DOM.Core.Node) is
   begin
      case K is
         when Code.Not_A_Trait | Code.An_Ordinary_Trait => null;
         when Code.An_Aliased_Trait =>
            DOM.Core.Elements.Set_Attribute (To, "aliased", "true");
         when Code.An_Access_Definition_Trait =>
            DOM.Core.Elements.Set_Attribute (To, "access", "true");
         when Code.A_Null_Exclusion_Trait =>
            DOM.Core.Elements.Set_Attribute (To, "not_null", "true");
         when Code.A_Reverse_Trait =>
            DOM.Core.Elements.Set_Attribute (To, "reverse", "true");
         when Code.A_Private_Trait =>
            DOM.Core.Elements.Set_Attribute (To, "private", "true");
         when Code.A_Limited_Trait =>
            DOM.Core.Elements.Set_Attribute (To, "limited", "true");
         when Code.A_Limited_Private_Trait =>
            DOM.Core.Elements.Set_Attribute (To, "limited", "true");
            DOM.Core.Elements.Set_Attribute (To, "private", "true");
         when Code.An_Abstract_Trait =>
            DOM.Core.Elements.Set_Attribute (To, "abstract", "true");
         when Code.An_Abstract_Private_Trait =>
            DOM.Core.Elements.Set_Attribute (To, "abstract", "true");
            DOM.Core.Elements.Set_Attribute (To, "private", "true");
         when Code.An_Abstract_Limited_Trait =>
            DOM.Core.Elements.Set_Attribute (To, "abstract", "true");
            DOM.Core.Elements.Set_Attribute (To, "limited", "true");
         when Code.An_Abstract_Limited_Private_Trait =>
            DOM.Core.Elements.Set_Attribute (To, "abstract", "true");
            DOM.Core.Elements.Set_Attribute (To, "limited", "true");
            DOM.Core.Elements.Set_Attribute (To, "private", "true");
         when Code.A_Variable_Declaration =>
            DOM.Core.Elements.Set_Attribute (To, "variable", "true");
         when Code.A_Constraint =>
            DOM.Core.Elements.Set_Attribute (To, "const");
            DOM.Core.Elements.Set_Attribute (To, "constraint");
         when Code.An_Association =>
            DOM.Core.Elements.Set_Attribute (To, "associate");
      end case;
   end Add_Trait;


   procedure Pre (Element : in Code.Element;
                  Control : in out Code.Traverse_Control;
                  State : in out Info) is
      pragma Unreferenced (Control);
      Tmp : DOM.Core.Node;
      use Code;
      use type DOM.Core.Node;
   begin

      --  Put_Line ("Pre (" & Code.Elements.Element_Kind (Element)'Img & ")");
      case Code.Elements.Element_Kind (Element) is

         when A_Pragma =>                  -- Code.Elements
            State.Current :=
              DOM.Core.Nodes.Append_Child
              (State.Current,
               DOM.Core.Documents.Create_Element
                 (State.Document,
                  To_Tag_Name
                       (Pragma_Kinds'Image
                          (Code.Elements.Pragma_Kind (Element)))));
            Tmp :=
              DOM.Core.Nodes.Append_Child
              (State.Current,
               DOM.Core.Documents.Create_Text_Node
                 (State.Document,
                  +Code.Elements.Pragma_Name_Image (Element)));

         when A_Defining_Name =>           -- Code.Declarations
            State.Current :=
            DOM.Core.Nodes.Append_Child
            (State.Current,
             DOM.Core.Documents.Create_Element
               (State.Document,
                To_Tag_Name
                       (Defining_Name_Kinds'Image
                          (Code.Elements.Defining_Name_Kind (Element)))));
            Tmp :=
              DOM.Core.Nodes.Append_Child
              (State.Current,
               DOM.Core.Documents.Create_Text_Node
                 (State.Document,
                  +Code.Declarations.Defining_Name_Image (Element)));

            case Code.Elements.Defining_Name_Kind (Element) is
               when A_Defining_Operator_Symbol =>
                  DOM.Core.Elements.Set_Attribute
                    (State.Current,
                     "operator_kind",
                     To_Tag_Name
                       (Operator_Kinds'Image
                          (Code.Elements.Operator_Kind (Element))));
               when others => null;
            end case;

         when A_Declaration =>             -- Code.Declarations
            State.Current :=
            DOM.Core.Nodes.Append_Child
            (State.Current,
             DOM.Core.Documents.Create_Element
               (State.Document,
                To_Tag_Name
                  (Declaration_Kinds'Image
                     (Code.Elements.Declaration_Kind (Element)))));

            --  Trait handling
            case Code.Elements.Declaration_Kind (Element) is
               when A_Private_Type_Declaration =>
                  Add_Trait (Code.Elements.Trait_Kind (Element),
                             State.Current);
               when A_Private_Extension_Declaration =>
                  Add_Trait (Code.Elements.Trait_Kind (Element),
                             State.Current);
               when A_Variable_Declaration =>
                  Add_Trait (Code.Elements.Trait_Kind (Element),
                             State.Current);
               when A_Constant_Declaration =>
                  Add_Trait (Code.Elements.Trait_Kind (Element),
                             State.Current);
               when A_Deferred_Constant_Declaration =>
                  Add_Trait (Code.Elements.Trait_Kind (Element),
                             State.Current);
               when A_Discriminant_Specification =>
                  Add_Trait (Code.Elements.Trait_Kind (Element),
                             State.Current);
               when A_Loop_Parameter_Specification =>
                  Add_Trait (Code.Elements.Trait_Kind (Element),
                             State.Current);
               when A_Procedure_Declaration |
                 A_Function_Declaration =>
                  Add_Trait (Code.Elements.Trait_Kind (Element),
                             State.Current);
               when A_Parameter_Specification =>
                  Add_Trait (Code.Elements.Trait_Kind (Element),
                             State.Current);
                  case Code.Elements.Mode_Kind (Element) is
                     when An_In_Mode =>
                        DOM.Core.Elements.Set_Attribute
                          (State.Current, "mode", "in");
                     when An_Out_Mode =>
                        DOM.Core.Elements.Set_Attribute
                          (State.Current, "mode", "out");
                     when An_In_Out_Mode =>
                        DOM.Core.Elements.Set_Attribute
                          (State.Current, "mode", "inout");
                     when others => null;
                  end case;
               when A_Formal_Object_Declaration =>
                  case Code.Elements.Mode_Kind (Element) is
                     when An_In_Mode =>
                        DOM.Core.Elements.Set_Attribute
                          (State.Current, "mode", "in");
                     when An_Out_Mode =>
                        DOM.Core.Elements.Set_Attribute
                          (State.Current, "mode", "out");
                     when An_In_Out_Mode =>
                        DOM.Core.Elements.Set_Attribute
                          (State.Current, "mode", "inout");
                     when others => null;
                  end case;
               when A_Formal_Procedure_Declaration |
                 A_Formal_Function_Declaration =>
                  --  Should be Subprogram_Default_Kind
                  --  XXX what sense of 'should'?
                  case Code.Elements.Default_Kind (Element) is
                     when A_Name_Default =>
                        DOM.Core.Elements.Set_Attribute
                          (State.Current, "default", "name");
                     when A_Box_Default =>
                        DOM.Core.Elements.Set_Attribute
                          (State.Current, "default", "box");
                     when A_Null_Default =>
                        DOM.Core.Elements.Set_Attribute
                          (State.Current, "default", "null"); -- 2005
                     when others => null;
                  end case;
               when others => null;
            end case;

         when A_Definition =>              -- Code.Definitions
            State.Current :=
            DOM.Core.Nodes.Append_Child
            (State.Current,
             DOM.Core.Documents.Create_Element
               (State.Document,
                To_Tag_Name
                  (Definition_Kinds'Image
                     (Code.Elements.Definition_Kind (Element)))));

            case Code.Elements.Definition_Kind (Element) is

               when A_Type_Definition =>
                  Tmp :=
                    DOM.Core.Nodes.Append_Child
                    (State.Current,
                     DOM.Core.Documents.Create_Element
                       (State.Document,
                        To_Tag_Name
                          (Type_Kinds'Image
                             (Code.Elements.Type_Kind (Element)))));
                  case Code.Elements.Type_Kind (Element) is
                     when An_Access_Type_Definition =>
                        DOM.Core.Elements.Set_Attribute
                          (Tmp,
                           "kind",
                           To_Tag_Name
                             (Access_Type_Kinds'Image
                                (Code.Elements.Access_Type_Kind (Element))));
                        --  It seems more reasonable to add the
                        --  'not_null' attribute to the
                        --  <access_type_definition/> element than to
                        --  the enclosing <type_definition/>.
                        Add_Trait (Code.Elements.Trait_Kind (Element),
                                   Tmp);
                     when A_Derived_Type_Definition |
                       A_Derived_Record_Extension_Definition |
                       A_Record_Type_Definition |
                       A_Tagged_Record_Type_Definition =>
                        Add_Trait (Code.Elements.Trait_Kind (Element),
                                   State.Current);
                     when A_Root_Type_Definition =>
                        DOM.Core.Elements.Set_Attribute
                          (Tmp,
                           "kind",
                           To_Tag_Name
                             (Root_Type_Kinds'Image
                                (Code.Elements.Root_Type_Kind (Element))));
                     when An_Interface_Type_Definition =>
                        --  2005: Interface_Kinds
                        DOM.Core.Elements.Set_Attribute
                          (Tmp,
                           "kind",
                           To_Tag_Name
                             (Interface_Kinds'Image
                                (Code.Elements.Interface_Kind (Element))));
                     when others => null;
                  end case;

               when A_Constraint =>
                  DOM.Core.Elements.Set_Attribute
                    (State.Current,
                     "kind",
                     To_Tag_Name
                       (Constraint_Kinds'Image
                          (Code.Elements.Constraint_Kind (Element))));

               when A_Formal_Type_Definition =>
                  Tmp :=
                    DOM.Core.Nodes.Append_Child
                    (State.Current,
                     DOM.Core.Documents.Create_Element
                       (State.Document,
                        To_Tag_Name
                          (Formal_Type_Kinds'Image
                             (Code.Elements.Formal_Type_Kind (Element)))));
                  case Code.Elements.Formal_Type_Kind (Element) is
                     when  A_Formal_Access_Type_Definition =>
                        DOM.Core.Elements.Set_Attribute
                          (Tmp,
                           "kind",
                           To_Tag_Name
                             (Access_Type_Kinds'Image
                                (Code.Elements.Access_Type_Kind (Element))));
                     when A_Formal_Private_Type_Definition |
                       A_Formal_Tagged_Private_Type_Definition |
                       A_Formal_Derived_Type_Definition =>
                        Add_Trait (Code.Elements.Trait_Kind (Element),
                                   State.Current);
                     when A_Formal_Interface_Type_Definition =>
                        --  2005: Interface_Kinds
                        DOM.Core.Elements.Set_Attribute
                          (Tmp,
                           "kind",
                           To_Tag_Name
                             (Interface_Kinds'Image
                                (Code.Elements.Interface_Kind (Element))));
                     when others => null;
                  end case;

               when A_Discrete_Subtype_Definition |
                 A_Discrete_Range =>
                  DOM.Core.Elements.Set_Attribute
                    (State.Current,
                     "kind",
                     To_Tag_Name
                       (Discrete_Range_Kinds'Image
                          (Code.Elements.Discrete_Range_Kind (Element))));

               when A_Component_Definition |
                 A_Private_Type_Definition |
                 A_Tagged_Private_Type_Definition |
                 A_Private_Extension_Definition =>
                  Add_Trait (Code.Elements.Trait_Kind (Element),
                             State.Current);

               when An_Access_Definition =>
                  --  2005: Access_Definition_Kinds
                  DOM.Core.Elements.Set_Attribute
                    (State.Current,
                     "kind",
                     To_Tag_Name
                       (Access_Definition_Kinds'Image
                          (Code.Elements.Access_Definition_Kind (Element))));

               when others => null;

            end case;

         when An_Expression =>             -- Code.Expressions
            State.Current :=
            DOM.Core.Nodes.Append_Child
            (State.Current,
             DOM.Core.Documents.Create_Element
               (State.Document,
                To_Tag_Name
                  (Expression_Kinds'Image
                     (Code.Elements.Expression_Kind (Element)))));
            case Code.Elements.Expression_Kind (Element) is
               when An_Attribute_Reference =>
                  Tmp :=
                    DOM.Core.Nodes.Append_Child
                    (State.Current,
                     DOM.Core.Documents.Create_Text_Node
                       (State.Document,
                        To_Tag_Name
                          (Attribute_Kinds'Image
                             (Code.Elements.Attribute_Kind (Element)))));
               when An_Identifier |
                 An_Operator_Symbol |
                 A_Character_Literal |
                 An_Enumeration_Literal =>
                  Tmp :=
                    DOM.Core.Nodes.Append_Child
                    (State.Current,
                     DOM.Core.Documents.Create_Text_Node
                       (State.Document,
                        +Code.Expressions.Name_Image (Element)));
               when An_Integer_Literal |
                 A_Real_Literal |
                 A_String_Literal =>
                  Tmp :=
                    DOM.Core.Nodes.Append_Child
                    (State.Current,
                     DOM.Core.Documents.Create_Text_Node
                       (State.Document,
                        +Code.Expressions.Value_Image (Element)));
               when A_Function_Call =>
                  if Code.Expressions.Is_Prefix_Call (Element) then
                     DOM.Core.Elements.Set_Attribute
                       (State.Current,
                        "prefixed",
                        "true");
                  else
                     DOM.Core.Elements.Set_Attribute
                       (State.Current,
                        "prefixed",
                        "false");
                  end if;
               when others => null;
            end case;

         when An_Association =>            -- Code.Expressions
            State.Current :=
            DOM.Core.Nodes.Append_Child
            (State.Current,
             DOM.Core.Documents.Create_Element
               (State.Document,
                To_Tag_Name
                  (Association_Kinds'Image
                     (Code.Elements.Association_Kind (Element)))));

         when A_Statement =>               -- Code.Statements
            State.Current :=
            DOM.Core.Nodes.Append_Child
            (State.Current,
             DOM.Core.Documents.Create_Element
               (State.Document,
                To_Tag_Name
                  (Statement_Kinds'Image
                     (Code.Elements.Statement_Kind (Element)))));

         when A_Path =>                    -- Code.Statements
            State.Current :=
            DOM.Core.Nodes.Append_Child
            (State.Current,
             DOM.Core.Documents.Create_Element
               (State.Document,
                To_Tag_Name
                  (Path_Kinds'Image
                     (Code.Elements.Path_Kind (Element)))));

         when A_Clause =>                  -- Code.Clauses
            State.Current :=
            DOM.Core.Nodes.Append_Child
            (State.Current,
             DOM.Core.Documents.Create_Element
               (State.Document,
                To_Tag_Name
                  (Clause_Kinds'Image
                     (Code.Elements.Clause_Kind (Element)))));
            case Code.Elements.Clause_Kind (Element) is
               when A_Representation_Clause =>
                  DOM.Core.Elements.Set_Attribute
                    (State.Current,
                     "representation_kind",
                     To_Tag_Name
                       (Representation_Clause_Kinds'Image
                          (Code.Elements.Representation_Clause_Kind
                             (Element))));
               when others => null;
            end case;

         when An_Exception_Handler =>
            --  Doesn't seem to be a Statement in spite of indication
            --  in Code.
            State.Current :=
            DOM.Core.Nodes.Append_Child
            (State.Current,
             DOM.Core.Documents.Create_Element
               (State.Document, "exception_handler"));

         --  --  --|A2015 start
         --  when An_Expression_Path =>        -- Code.Expressions
         --     null;
         --  --  --|A2015 end

         when Not_An_Element =>
            null;

      end case;

   end Pre;


   procedure Post (Element : in Code.Element;
                   Control : in out Code.Traverse_Control;
                   State : in out Info) is
      pragma Unreferenced (Element);
      pragma Unreferenced (Control);
   begin
      --  Put_Line ("Post (" & Code.Elements.Element_Kind (Element)'Img & ")");
      State.Current := DOM.Core.Nodes.Parent_Node (State.Current);
   end Post;


   function To_Tag_Name (Image : String) return String is
      Result : constant String := Ada.Characters.Handling.To_Lower (Image);
   begin
      if Result (1 .. 2) = "a_" then
         return Result (3 .. Result'Last);
      elsif Result (1 .. 3) = "an_" then
         return Result (4 .. Result'Last);
      else
         return Result;
      end if;
   end To_Tag_Name;


end XML_Support;
