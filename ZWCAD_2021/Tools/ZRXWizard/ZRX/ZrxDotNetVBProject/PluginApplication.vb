Imports System
Imports ZwSoft.ZwCAD.Runtime
Imports ZwSoft.ZwCAD.ApplicationServices
Imports ZwSoft.ZwCAD.DatabaseServices
Imports ZwSoft.ZwCAD.Geometry
Imports ZwSoft.ZwCAD.EditorInput


<Assembly: ExtensionApplication(GetType($safeprojectname$.PluginApplication))>

Namespace $safeprojectname$
    Public Class PluginApplication
        Implements IExtensionApplication

        Public Sub Initialize() Implements IExtensionApplication.Initialize
            'Add your initialize code here.

        End Sub

        Public Sub Terminate() Implements IExtensionApplication.Terminate
            'Add your uninitialize code here.

        End Sub

    End Class

End Namespace
