
using GrxCAD.Runtime;
using GrxCAD.ApplicationServices;

[assembly: CommandClass(typeof(hello.HelloCmd))]

namespace hello
{
  public class HelloCmd
  {
    [CommandMethod("Hello")]
    static public void DoIt()
    {

      try
      {
        Application.DocumentManager.MdiActiveDocument.Editor.WriteMessage("Hello dotnet");
      }
      catch (System.Exception ex)
      {
        System.Windows.Forms.MessageBox.Show(ex.ToString());
      }
    }
  }
}
