Description: 
This application demonstrates how to receive notification of the Editor events. 

To run the sample:
Please use Visual Studio 2017 to open the solution called "DotNetSamples.sln"，then build the application.

To use EditorReactor.dll:
1. Start ZWCAD and open a new drawing.
2. Run NETLOAD command and load the EditorReactor.dll file in the output directory.
3. Execute the "EditorReactorOnOff" command to add the EditorReactor(Execute the "EditorReactorOnOff" agagin to remove). Execute a command at will, and you will find the EditorReactor will be triggered at the beginning and end of the command. For the detailed scenarios that will trigger the reactor, see the description of this class and its methods in the development document.