/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#pragma pack (push, 8)
#pragma warning (disable: 4312)

#ifdef _MANAGED
#pragma warning( disable : 4561 )
#endif

#ifdef _FULLDEBUG_
#define GC_FULL_DEBUG 1
#pragma message ("Warning! _FULLDEBUG_ is deprecated.")
#endif

//#ifndef GC_FULL_DEBUG
//#pragma comment (lib ,"rxapi.lib")
//#pragma comment (lib ,"gcdb.lib")
//#pragma comment (lib ,"gcge.lib")
//#pragma comment (lib ,"acISMobj.lib")
//#pragma comment (lib ,"gcgiapi.lib")
//#pragma comment (lib ,"gxdb.lib")
//#pragma comment (lib ,"gc1st.lib") 
//#ifdef _BREP_SUPPORT_
//	#pragma comment (lib ,"gcgex.lib")
//	#pragma comment (lib ,"gcbr.lib")
//#endif 
//#else 
//#pragma comment (lib ,"rxapi.lib")
//#pragma comment (lib ,"gcdb.lib")
//#pragma comment (lib ,"gcge.lib")
//#pragma comment (lib ,"acISMobj.lib")
//#pragma comment (lib ,"gcgiapi.lib")
//#pragma comment (lib ,"gxdb.lib")
//#pragma comment (lib ,"gc1st.lib") 
//#ifdef _BREP_SUPPORT_
//	#pragma comment (lib ,"gcgex.lib")
//	#pragma comment (lib ,"gcbr.lib")
//#endif 
//#endif 
//
//#ifdef _HLR_SUPPORT_
//	#pragma comment (lib ,"GsdkHlrApi.lib")
//#endif
//
//#ifdef _AMODELER_SUPPORT_
//	#pragma comment (lib, "aecmodeler.lib")
//#endif 
//
//#pragma comment (lib, "gcdbmgd.lib")

#include "gcmem.h"
#include "gsoft.h"
#include "gsoftabb.h"
#include "gcadstrc.h"
#include "rxdefs.h"
#include "rxnames.h"
#include "rxboiler.h"
#include "rxclass.h"
#include "GcDbClassIter.h"
#include "rxdict.h"
#include "rxobject.h"
#include "rxsrvice.h"
#include "rxkernel.h"
#include "rxdlinkr.h"
#include "rxregsvc.h"
#include "rxevent.h"
#include "rxiter.h"
#include "rxditer.h"
#include "appinfo.h"
#include "rxprotevnt.h"

#include "PAL/api/codepgid.h"	
#include "GcHeapOpers.h"
#include "GcString.h"
#include "GdGChar.h"
#include "gcly.h"

#include "gcarray.h"
#include "dbhandle.h"
#include "dbid.h"
#include "dbidar.h"
#include "dbcolor.h"
#include "dbptrar.h"
#include "drawable.h"
#include "dbsecurity.h"
#include "dbboiler.h"
#include "gcdb.h"
#include "gcdbabb.h"
#include "dbAlignment.h"
#include "dbfiler.h"
#include "dbintar.h"
#include "dbsubeid.h"
#include "dbaudita.h"
#include "dbmain.h"
#include "dbdict.h"
#include "dbdate.h"
#include "dbsymtb.h"
#include "dbsymutl.h"
#include "dbdictdflt.h"
#include "dbDictUtil.h"
#include "dbcurve.h"
#include "dbmtext.h"
#include "dbdim.h"
#include "dbDimData.h"
#include "dbents.h"
#include "dbeval.h"
#include "GcField.h"
#include "DbField.h"
#include "dbtable.h"
#include "dbTableStyle.h"
#include "dbdynblk.h"
#include "dbproxy.h"
#include "dbfcf.h"
#include "dbapserv.h"
#include "dbgroup.h"
#include "dbhatch.h"
#include "dblead.h"
#include "dbelipse.h"
#include "dbspline.h"
#include "dbray.h"
#include "dbsol3d.h"
#include "dbregion.h"
#include "dbacis.h"
#include "dbbody.h"
#include "dbframe.h"
#include "dbole.h"
#include "imgdef.h"
#include "imgvars.h"
#include "dbimage.h"
#include "imgent.h"
#include "dblstate.h"
#include "dbmstyle.h"
#include "dbmline.h"
#include "dbxline.h"
#include "dbxrecrd.h"
#include "gchapi.h"
#include "dbDataTable.h"
#include "dbfilter.h"
#ifndef _MANAGED
#include "dbgrip.h"
#endif
#include "dbappgrip.h"
#include "dbidmap.h"
#include "dbindex.h"
#include "dblaymgrrctr.h"
#include "dblayout.h"
#include "dbmaterial.h"
#include "dbpl.h"
#include "dbtrans.h"
#include "sorttab.h"
#include "xreflock.h"

#include "gcgiutil.h"
#include "dbcfilrs.h"
#include "dblyfilt.h"
#include "dblyindx.h"
#include "dbspfilt.h"
#include "dbspindx.h"
#include "dbplhldr.h"
#include "dbxutil.h"
#include "idgraph.h"
#include "summinfo.h"
#include "textengine.h"
#include "graph.h"
#include "xgraph.h"
#include "dbplotsettings.h"
#include "dbplotsetval.h"
#include "GcDbLMgr.h"
#include "gcappvar.h"


#include "gcgi.h"
#include "GcGiLineAttributes.h"
#include "GcGiLineAttrUtils.h"
#include "gcgimaterial.h"
#include "GcGiStyleAttributes.h"
#include "linetypeengine.h"

#include "gcutil.h"
#include "gcestext.h"
#include "gdsdef.h"
#include "gcdbgds.h"
#include "gcutgds.h"
#include "gds.h"
#include "gdscodes.h"
#include "gdsmigr.h"
#include "migrtion.h"

#include "dbobjptr.h"

#include "geassign.h"
#include "geblok2d.h"
#include "geblok3d.h"
#include "geell2d.h"
#include "geell3d.h"
#include "gecone.h"
#include "gecylndr.h"
#include "gesphere.h"
#include "getorus.h"
#include "geray2d.h"
#include "geray3d.h"
#include "gessint.h"
#include "gedwgio.h"
#include "gedxfio.h"
#include "gefiler.h"
#include "gecspl2d.h"
#include "gecspl3d.h"
#include "gepos2d.h"
#include "gepos3d.h"
#include "geoffc2d.h"
#include "geoffc3d.h"
#include "geoffsf.h"
#include "genurb2d.h"
#include "genurb3d.h"
#include "genurbsf.h"	
#include "gecsint.h"
#include "geextc2d.h"
#include "geextc3d.h"
#include "geextsf.h"
#include "gecomp2d.h"
#include "gecomp3d.h"
#include "gecint2d.h"
#include "gecint3d.h"
#include "gescl2d.h"
#include "gescl3d.h"
#include "geclip2d.h"
#include "gexbndsf.h"
#include "gecbndry.h"
#include "geapln3d.h"
#include "gearc2d.h"
#include "gearc3d.h"
#include "gebndpln.h"
#include "gecurv2d.h"
#include "gecurv3d.h"
#include "gedblar.h"
#include "gedll.h"
#include "geent2d.h"
#include "geent3d.h"
#include "gefileio.h"
#include "gegbl.h"
#include "gegblabb.h"
#include "gegblge.h"
#include "gegblnew.h"
#include "geintarr.h"
#include "geintrvl.h"
#include "gekvec.h"
#include "gelent2d.h"
#include "gelent3d.h"
#include "gelibver.h"
#include "geline2d.h"
#include "geline3d.h"
#include "gelnsg2d.h"
#include "gelnsg3d.h"
#include "gemat2d.h"
#include "gemat3d.h"
#include "gepent2d.h"
#include "gepent3d.h"
#include "geplanar.h"
#include "geplane.h"
#include "geplin2d.h"
#include "geplin3d.h"
#include "gepnt2d.h"
#include "gepnt3d.h"
#include "geponc2d.h"
#include "geponc3d.h"
#include "geponsrf.h"
#include "gept2dar.h"
#include "gept3dar.h"
#include "gesent2d.h"
#include "gesent3d.h"
#include "gesurf.h"
#include "getol.h"
#include "gevc2dar.h"
#include "gevc3dar.h"
#include "gevec2d.h"
#include "gevec3d.h"
#include "gevptar.h"

#ifdef _MANAGED
#include <vcclr.h>
//#include "mgdinterop.h"
#endif

#ifdef __ATLCOM_H__
#ifndef _GCRXAPP
#include "axdb.h"		
#else
#include "gcadi.h"		
#endif 
#include "oleaprot.h"
#include "category.h"
#include "gxobjref.h"
#include "gxboiler.h"
#ifndef _GCRXAPP
#include "acpi.h"
#else
#include "gcpi.h"
#endif
#include "opmdialog.h"
#include "opmimp.h"
#include "opmdrvr.h"
#include "opmext.h"
#include "gxtempl.h"
#include "gxpnt2d.h"
#include "gxpnt3d.h"
#include "gxmat3d.h"
#include "gxlock.h"
#include "dynprops.h"
#ifndef _GCRXAPP
#include "acpexctl.h"	
#include "acpp.h"		
#else
#include "gcpexctl.h"	
#include "gcpp.h"		
#endif	
#endif 

#include "gcut.h"
#include "gcutmem.h"
#include "gcutmigr.h"

#include "gcgs.h"		

#include "inetstrc.h"

#include "gcsymutl.h"	
#include "dbxEntryPoint.h"

#ifdef _DBX_HOST_APPLICATION_
#include "truetypetext.h"
#include "dbhaext.h"
#include "gcdbxref.h"
#endif 

#ifdef _BREP_SUPPORT_
#include "brbctrav.h"
#include "brbetrav.h"
#include "brbftrav.h"
#include "brbrep.h"
#include "brbstrav.h"
#include "brbvtrav.h"
#include "brcplx.h"
#include "brcstrav.h"
#include "bredge.h"
#include "brelem.h"
#include "brelem2d.h"
#include "breltrav.h"
#include "brent.h"
#include "brentrav.h"
#include "brface.h"
#include "brfltrav.h"
#include "brgbl.h"
#include "brhit.h"
#include "brletrav.h"
#include "brloop.h"
#include "brlvtrav.h"
#include "brm2dctl.h"
#include "brmctl.h"
#include "brment.h"
#include "brmesh.h"
#include "brmesh2d.h"
#include "brmetrav.h"
#include "brnode.h"
#include "brprops.h"
#include "brsftrav.h"
#include "brshell.h"
#include "brtrav.h"
#include "brvetrav.h"
#include "brvltrav.h"
#include "brvtx.h"
#endif 

#ifdef _HLR_SUPPORT_
#include "Hlr.h"
#include "BasePex.h"
#endif 

#ifdef _AMODELER_SUPPORT_
#include "amodeler.h"
#include "body.h"
#include "callback.h"
#include "check.h"
#include "circle3d.h"
#include "color.h"
#include "curve.h"
#include "darray.h"
#include "deviat.h"
#include "dxfinpln.h"
#include "dxfout.h"
#include "edge.h"
#include "entity.h"
#include "enums.h"
#include "epsilon.h"
#include "errcodes.h"
#include "face.h"
#include "flags.h"
#include "global.h"
#include "interval.h"
#include "ipoint2d.h"
#include "ipoint3d.h"
#include "ivect2d.h"
#include "ivect3d.h"
#include "line3d.h"
#include "massert.h"
#include "morphmap.h"
#include "plane.h"
#include "point2d.h"
#include "point3d.h"
#include "surface.h"
#include "transf3d.h"
#include "util.h"
#include "vector2d.h"
#include "vector3d.h"
#include "vertdata.h"
#include "vertex.h"
#include "vertsurf.h"
#include "wallcrnr.h"
#endif 

#pragma pack (pop)