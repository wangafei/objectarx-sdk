/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC3DDWFNAVTREE_H
#define GC3DDWFNAVTREE_H

class Gc3dDwfNavTreeNode : public GcRxObject
{
public:
  virtual const GcString&     displayName() const = 0;
  virtual const GcArray<long>& keys() const = 0;
  virtual       int           nDescendants() const = 0;
  virtual       bool          isGroup() const = 0;
  virtual const GcArray<const Gc3dDwfNavTreeNode*>& children() const = 0;
  virtual       bool          isBlock() const = 0;
  virtual       bool          addChild(const Gc3dDwfNavTreeNode* node) = 0;
  virtual       bool          removeChild(const Gc3dDwfNavTreeNode* node) = 0;
};

#endif 