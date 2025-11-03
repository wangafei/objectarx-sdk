Imports System
Imports ZwSoft.ZwCAD.Runtime
Imports ZwSoft.ZwCAD.ApplicationServices
Imports ZwSoft.ZwCAD.DatabaseServices
Imports ZwSoft.ZwCAD.Geometry
Imports ZwSoft.ZwCAD.EditorInput

<Assembly: CommandClass(GetType($safeprojectname$.Commands))>

Namespace $safeprojectname$
    Public Class Commands
        <CommandMethod("TestVBGroup", "HelloVB", CommandFlags.Modal)>
        Public Sub HelloVB()
            Dim db As Database
            db = HostApplicationServices.WorkingDatabase
            Dim doc As Document
            doc = Application.DocumentManager.GetDocument(db)
            Dim ed As ZwSoft.ZwCAD.EditorInput.Editor
            ed = doc.Editor

            ed.WriteMessage("\nHello World!")
        End Sub
    End Class

End Namespace
