with Code;
with DOM.Core;

package XML_Support is

   type Info is private;

   procedure Initialize (XI : in out Info;
                         Document : DOM.Core.Node);

   procedure Add_Compilation_Unit (The_Unit : Asis.Compilation_Unit;
                                   To : in out Info);

   procedure Finalize (XI : in out Info);

private

   type Info is record
      Document : DOM.Core.Document;
      Current : DOM.Core.Node;
   end record;

end XML_Support;
