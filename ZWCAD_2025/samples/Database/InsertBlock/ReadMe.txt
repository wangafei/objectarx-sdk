Description: 
This application implements three commands to demonstrate the example of modifying entitiy(s) through the resbuf linked list rather than object interfaces, and the zrx interfaces involed are:  acdbEntMake, acdbEntMod, acdbEntUpd.

To run the sample:
Please use Visual Studio 2017 to open the solution called "Samples.sln" and switch to the configuration that matches with the ZWCAD version，then build the application.

To use InsertBlock.zrx:
1. Start ZWCAD and open a new drawing .
2. Run APPLOAD command and load the InsertBlock.zrx file in the output directory.
3. Execute the "createBlockTest1" command, which creates a simple block called "szBlock1".
4. Execute the "createBlockTest2" command, which creates a block called "szBlock2" by the entitiy(s) in the selection set and adds an attribute to the block.
5. Execute the "insertBlockTest" command, which inserts the block with the with the corresponding parameters entered.