Description: 
This application demonstrates how to use the interfaces about the entity selection, interactive, system variable operation, such as acedGetXXX, acedEntSel, acedSSGet, acedSetVar and so on.

To run the sample:
Please use Visual Studio 2017 to open the solution called "Samples.sln" and switch to the configuration that matches with the ZWCAD version，then build the application.

To use Interaction.zrx:
1. Start ZWCAD and open a new drawing .
2. Run APPLOAD command and load the Interaction.zrx file in the output directory.
3. Execute the "TestGet-XXX" commands, which demonstrate the use of the various common interactive interfaces.
4. Draw some entites and execute the "SSGET_-XXX" or "EntSelTest" commands which demonstrate the use of the interfaces about the selection. 
5. Execute the "SetSysVar-XXX" or "GetSysVar-XXX" commands, which demonstrate the use of the interfaces about the system variable operation. 