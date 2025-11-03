Imports System
Imports GrxCAD

Imports GrxCAD.Runtime

Imports GrxCAD.DatabaseServices
Imports GrxCAD.Geometry

Imports GrxCAD.ApplicationServices
Imports GrxCAD.EditorInput

' This line is not mandatory, but improves loading performances
<Assembly: CommandClass(GetType(GRXTest.MyCommands))> 

Namespace GRXTest
    Public Class MyCommands

        <CommandMethod("vbhello", CommandFlags.Modal)> _
        Public Sub RunMRLCommand() ' This method can have any name
            Dim doc As GrxCAD.ApplicationServices.Document
            Dim ent As Entity


            doc = GrxCAD.ApplicationServices.Application.DocumentManager.MdiActiveDocument
            doc.Editor.WriteMessage("hello vb.net")
        End Sub

    End Class
End Namespace
