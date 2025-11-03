Description: 
This application demonstrates the use of the AcEdInputContextReactor class which provides reactors for notification of user prompts that are starting and completing.

To run the sample:
Please use Visual Studio 2017 to open the solution called "Samples.sln" and switch to the configuration that matches with the ZWCAD version，then build the application.

To use InputContextReactor.zrx:
1. Start ZWCAD and open a new drawing.
2. Run APPLOAD command and load the InputContextReactor.zrx file in the output directory.
3. Execute the "AddReactor" command to add the InputContextReactor(Execute the "RemoveReactor" to remove). Executing commands or the user interaction (such as select, getpoint and so on) will trigger the InputContextReactor. For the detailed scenarios that will trigger the reactor, see the description of this class and its methods in the development document.