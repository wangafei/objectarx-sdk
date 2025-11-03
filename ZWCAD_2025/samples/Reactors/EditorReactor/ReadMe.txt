Description: 
This application demonstrates the use of the AcEditorReactor class which serves as a base class for custom classes that receive notification of AcEditor events. 

To run the sample:
Please use Visual Studio 2017 to open the solution called "Samples.sln" and switch to the configuration that matches with the ZWCAD version，then build the application.

To use EditorReactor.zrx:
1. Start ZWCAD and open a new drawing.
2. Run APPLOAD command and load the EditorReactor.zrx file in the output directory.
3. Execute the "AddEditorReactor" command to add the EditorReactor(Execute the "RemoveEditorReactor" to remove). Execute a command at will, and you will find the EditorReactor will be triggered at the beginning and end of the command. For the detailed scenarios that will trigger the reactor, see the description of this class and its methods in the development document.