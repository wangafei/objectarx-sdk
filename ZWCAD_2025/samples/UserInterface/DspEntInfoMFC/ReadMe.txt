Description: 
This application implements a command called "DispEntInfoMFC"  to demonstrate the use of the modeless dialog inherited from CDialog class.

To run the sample:
Please use Visual Studio 2017 to open the solution called "Samples.sln" and switch to the configuration that matches with the ZWCAD version，then build the application.

To use DspEntInfoMFC.zrx:
1. Start ZWCAD and open a new drawing and draw some entities.
2. Run APPLOAD command and load the DspEntInfoMFC.zrx file in the output directory.
3. Execute the "DispEntInfoMFC" command and click the "Select entity" button on the dialog box to select a entity, and the dialog box will dispslay the basic information of the selected entity.