Description: 
This application implements three commands to demonstrate the deep clone operation of the dwg datababe objects, and the zrx interfaces involed are:  AcDbDatabase::deepCloneObjects, AcDbDatabase::wblock and AcDbDatabase::wblockCloneObjects.

To run the sample:
Please use Visual Studio 2017 to open the solution called "Samples.sln" and switch to the configuration that matches with the ZWCAD version，then build the application.

To use DeepClone.zrx:
1. Start ZWCAD and open a new drawing and draw some entities.
2. Run APPLOAD command and load the DeepClone.zrx file in the output directory.
3. Execute the "DeepCloneDiffOwnerObjects" command, which clones entity(s) selected according to the prompts to the model space and the paper space.
4. Execute the "wblockSample" command, which wblocks objects from the external dwg file to the target database. If the wblock is successful, the target database is saved as "TestWblock.dwg" in the document directory.
5. Execute the "wblockCloneObjectsSample" command, which wblocks objects from the external dwg file to the current database. 