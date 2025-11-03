#ifndef GC3DDWFNAVTREE_H
#define GC3DDWFNAVTREE_H

class Gc3dDwfNavTreeNode : public GcRxObject
{
public:
    /// <summary>
    /// This method is called to get the display name of the tree node
    /// </summary>
    ///
    /// <returns>
    /// returns the name of the tree node.
    /// </returns>
    virtual const GcString&     displayName() const = 0;

    /// <summary>
    /// This method is called to get the graphic identifiers for this tree 
    /// node
    /// </summary>
    ///
    /// <returns>
    /// returns the graphic identifiers for this tree node
    /// </returns>
    virtual const GcArray<long>& keys() const = 0;

    /// <summary>
    /// This method is called to get the number of descendants for this
    /// tree node. Number of descendants includes children, grandchildren
    /// and so on recursively.
    /// </summary>
    ///
    /// <returns>
    /// returns the number of descendants in the tree node.
    /// </returns>
    virtual       int           nDescendants() const = 0;

    /// <summary>
    /// This method is called to get the flag to see if this node should
    /// be displayed as a group or not. The default implementation appends
    /// the number of descendants to the display name
    /// </summary>
    ///
    /// <returns>
    /// returns true if tree node is a group.
    /// </returns>
    virtual       bool          isGroup() const = 0;

    /// <summary>
    /// This method is called to get an array of all the tree node children
    /// of this tree node.
    /// </summary>
    ///
    /// <returns>
    /// returns a array of all the children of this tree node.
    /// </returns>
    virtual const GcArray<const Gc3dDwfNavTreeNode*>& children() const = 0;

    /// <summary>
    /// This method is called to get the flag to see if node is grouped
    /// by block. If this is true, all the descendants graphics will be grouped
    /// together into this tree node, which will have no descendants.
    /// </summary>
    ///
    /// <returns>
    /// returns true if node is grouped by block.
    /// </returns>
    virtual       bool          isBlock() const = 0;
    /// <summary>
    /// Call this method to add a child to the root node. When trying to
    /// register the Gc3dDwfNavTreeNode root in the AcDMMSheetReactorInfo, only
    /// the first client wins. In order for other clients who are registered 
    /// after the first client, to add or remove children, Clients can choose
    /// to implement addChild and removeChild methods.
    /// </summary>
    ///
    /// <param name="root">
    /// a pointer to an Gc3dDwfNavTreeNode object that the clients wants
    /// to add to the navigation tree.
    /// </param>
    ///
    /// <returns>
    /// returns true if successfully adds the Gc3dDwfNavTreeNode node as child
    /// to the root node
    /// </returns>
    ///
    virtual       bool          addChild(const Gc3dDwfNavTreeNode* node) = 0;
    /// <summary>
    /// Call this method to remoave a child from the root node. When trying to
    /// register the Gc3dDwfNavTreeNode root in the AcDMMSheetReactorInfo, only
    /// the first client wins. In order for other clients who are registered 
    /// after the first client, to add or remove children, Clients can choose
    /// to implement addChild and removeChild methods.
    /// </summary>
    ///
    /// <param name="root">
    /// a pointer to an Gc3dDwfNavTreeNode object that the clients wants
    /// to remove from the navigation tree
    /// </param>
    ///
    /// <returns>
    /// returns true if successfully removes the Gc3dDwfNavTreeNode node from
    /// the navigation tree
    /// </returns>
    ///
    virtual       bool          removeChild(const Gc3dDwfNavTreeNode* node) = 0;
};

#endif //GC3DDWFNAVTREE_H
