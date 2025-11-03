Description: 
This application implements three commands to demonstrate the deep clone operation of the dwg datababe objects, and the zrx interfaces involed are: Database.DeepCloneObjects, Database.Wblock and Database.WblockCloneObjects.

To run the sample:
Please use Visual Studio 2017 to open the solution called "DotNetSamples.sln"，then build the application.

To use DeepClone.dll:
1. Start ZWCAD and open a new drawing and draw some entities..
2. Run NETLOAD command and load the DeepClone.dll file in the output directory.
3. Execute the "DeepCloneDiffOwnerObjects" command, which clones entity(s) selected according to the prompts to the model space and the paper space.
4. Execute the "WblockSample" command, which wblocks objects from the external dwg file to the target database. If the wblock is successful, the target database is saved as "XXXX_WblockTest.dwg" in the document directory.
5. Execute the "WblockCloneObjectsSample" command, which wblocks objects from the external dwg file to the current database. 