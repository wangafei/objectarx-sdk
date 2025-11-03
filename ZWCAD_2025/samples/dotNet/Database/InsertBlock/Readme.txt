Description: 
This application implements three commands to demonstrate the Creation, modification and deletion of entities.

To run the sample:
Please use Visual Studio 2017 to open the solution called "DotNetSamples.sln"，then build the application.

To use InsertBlock.dll:
1. Start ZWCAD and open a new drawing.
2. Run NETLOAD command and load the InsertBlock.dll file in the output directory.
3. Execute the "CreateBlockTest1" command, which creates a simple block called "MyBlock1".
4. Execute the "CreateBlockTest2" command, which creates a block called "MyBlock2" by the entitiy(s) in the selection set and adds an attribute to the block.
5. Execute the "InsertBlockTest" command, which inserts the block with the with the corresponding parameters entered.