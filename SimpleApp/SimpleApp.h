/***************************************************************************	Apple Macintosh Developer Technical Support****	Simple App Framework****	by Matthew Xavier Mora, Apple Developer Technical Support mxmora@apple.com****	File:		SimpleApp.h****	Copyright � 1995-1996 Apple Computer, Inc.**	All rights reserved.****	You may incorporate this sample code into your applications without**	restriction, though the sample code has been provided "AS IS" and the**	responsibility for its operation is 100% yours.  However, what you are**	not permitted to do is to redistribute the source as "DSC Sample Code"**	after having made changes. If you're going to re-distribute the source,**	we require that you make it clear in the source that the code was**	descended from Apple Sample Code, but that you've made changes.****************************************************************************/#include <Lists.h>#include <AppleEvents.h>#include <Drag.h>#ifndef __SIMPLEAPP__#define __SIMPLEAPP__/*---------------------------------------------------------------------------------- */#pragma mark Defines/*---------------------------------------------------------------------------------- */#define	kMagicSig 				(0x4D584D21)	/* 'MXM!' our magic signature */#define	kMaxMenus 				(20)#define	kMaxMenuItems 			(128)#define	kMaxButtons 			(128)#define	kMaxEventProcs 			(10)#define	kAppleEventLoadingErr 	(129)#define kScrollBarType			'scrl'#define	kEventPassThru 			(true)		/* This lets the event pass thru to the default handler */#define	kEventOverRide 			(false)		/* This overides the event and doesn't call to the default handler */#define	kUpArrow 				(30)#define	kDownArrow 				(31)#define	kEnterKey 				(0x03)#define	kReturnKey 				(0x0D)#define	kTabKey 				(0x09)#define	kAppleNum 				(128)#define	kFileNum 				(129)#define	kEditNum 				(130)#define	kMenuStartID 			(127)#define	kMargin 				(5)#define	kUseStandardMenu 		(true)#define	kErrorBase				( 0 ) 	//	Base value for SimpleApp Error Numbers#define	kSAStandardDebugAlert 	( 9999)#define	kSANonFatalError 		( kErrorBase )#define	kSAFatalError 			( kErrorBase - 1 )#define	kSABadSelectorErr		( kErrorBase - 2 )#define	kSABadProcPtr			( kErrorBase - 3 )	#define	kNotOurWindowError 		( kErrorBase - 4 )	#define	kNotValidObject			( kErrorBase - 5 )	#define	kSAInObject 			(1)#define	kSANotInObject 			(2)#define	kSAObjectWasHit 		(3)#define	kSAObjectWasNotHit 		(4)#define kSANoCommandKey 		( 0 )    // value for no command key equivalent#define kAboutText 		(1)#define kButtonName 	(2)#define kStaticStrings 	(1000)/*---------------------------------------------------------------------------------- */#pragma mark typedefs/*---------------------------------------------------------------------------------- */typedef			Str255 StringArray;typedef			StringArray *StringArrayPtr,**StringArrayHandle ;typedef			ControlRef ControlArray[];typedef			ControlArray *ControlArrayPtr,**ControlArrayHandle;				typedef	struct	GroupRec 			GroupRec,		*GroupRecPtr,		**GroupRecHandle;typedef	struct	ObjectItemRec 		ObjectItemRec,	*ObjectItemRecPtr,	**ObjectItemRecHandle;typedef struct	MenuItemRec 		MenuItemRec,	*MenuItemRecPtr ,	**MenuItemRecHandle ;typedef struct	ButtonItemRec 		ButtonItemRec,	*ButtonItemRecPtr,	**ButtonItemRecHandle;typedef			ButtonItemRecHandle ButtonItemRef;typedef			ObjectItemRecHandle ObjectItemRef;typedef pascal SInt16  	(* MenuHitProc)  	( SInt32 modifiers);typedef pascal SInt16  	(* MenuUpdateProc )	( SInt32 modifiers);typedef pascal SInt16  	(* ButtonHitProc)	( ButtonItemRef me,SInt32 modifiers) ;typedef pascal SInt16  	(* ButtonUpdateProc)( ButtonItemRef me,SInt32 modifiers);typedef pascal void   	(* MyActionProc)	( ControlHandle control,SInt16 part);typedef pascal Boolean 	(* AboutProc) 		( SInt32 data);typedef pascal Boolean 	(* PreGroupHitProc)		(SInt32 modifiers ,Point pt, ControlArrayPtr cap , SInt16 count) ;typedef pascal SInt16 	(* PostGroupHitProc)	( SInt32 modifiers ,ControlRef cr,ButtonItemRecHandle brh, SInt16 item);typedef pascal SInt16 	(* GroupUpdateProc)		( WindowRef wind,GroupRecHandle grh );typedef pascal SInt16 	(*	WindowHitProc)		( SInt32 modifiers);typedef pascal SInt16 	(*	ListHitProc )		( SInt32 modifiers) ;typedef pascal SInt16 	(*	EditFieldHitProc)	( SInt32 modifiers) ;typedef pascal SInt16 	(*	WindowUpdateProc)	( SInt32 modifiers) ;typedef pascal SInt16 	(*	ListUpdateProc)		( SInt32 modifiers) ;typedef pascal void	 	(*	ListDrawCellProc)	( Point thecell, Rect *bounds ,ListRef listID );typedef pascal SInt16 	(*	EditFieldUpdateProc)( SInt32 modifiers) ;typedef pascal SInt16 	(*	WindowIdleProc)		( SInt32 modifiers ) ;typedef pascal SInt16 	(*	ListIdleProc )		( SInt32 modifiers ) ;typedef pascal SInt16 	(*	EditFieldIdleProc)	( SInt32 modifiers ) ;typedef pascal SInt16 	(*	WindowGrowProc)		( EventRecord *event );typedef pascal SInt16 	(*	WindowZoomProc)		( EventRecord *event );typedef pascal SInt16 	(*	WindowActivateProc)	( Boolean isActivating ) ;		typedef pascal SInt16 	(*	TextFieldHitProc)	( SInt32 modifiers) ;typedef pascal SInt16 	(*	TextFieldUpdateProc)( SInt32 modifiers) ;typedef pascal SInt16 	(*	EventProcs )		( EventRecord *event) ;typedef pascal Boolean	(*	PreEventProc ) 		(EventRecord * event,long refCon);typedef pascal SInt16 	(*	TerminateProc)		( SInt32 flags) ;typedef pascal SInt16 	(*	InitializeProc)		( SInt32 flags) ;typedef pascal SInt16 	(*	LowMemProc)			( SInt32 flags ) ;typedef pascal SInt16 	(*	MenuEventProc)		( SInt32 menuResult);typedef pascal void	 	(*	WindowCloseProc)	( WindowRef * theWindow);/* generic object stuff */typedef pascal Handle	(* ObjectInitProc)		( ObjectItemRecHandle orh);typedef pascal OSErr 	(* ObjectDisposeProc)	( ObjectItemRecHandle orh);typedef pascal SInt16 	(* ObjectHitProc ) 		( Point *pt,SInt32 modifiers, ObjectItemRecHandle me);typedef pascal SInt16 	(* ObjectTrackProc ) 	( Point *pt,SInt32 modifiers, ObjectItemRecHandle me);typedef pascal SInt16 	(* ObjectUpdateProc)	( WindowRef window, RgnHandle update,ObjectItemRecHandle me) ;typedef pascal void  	(* ObjectKeyProc )		( char keyCode, char theChar,SInt32 modifiers);typedef pascal void  	(* ObjectIdleProc )		( ObjectItemRecHandle orh);typedef pascal SInt16 	(* ObjectEditProc )		( ObjectItemRecHandle orh,SInt16 editAction);typedef pascal SInt16 	(* 	GetDragDataProc)	  (ObjectItemRef orh,OSType * theType,Ptr * data,long * len,long * flags);typedef pascal SInt16 	(* 	PutDragDataProc )	  (ObjectItemRef orh,OSType theType,Ptr data,long len,long flags);typedef pascal SInt16 	(* 	CalcObjectRegionProc) (ObjectItemRef orh,RgnHandle theRgn);typedef pascal SInt16 	(* 	ObjectReceiveProc)	  (ObjectItemRef orh,DragReference theDrag);/* Apple Event Stuff */typedef pascal OSErr 	(* OpenDocProc ) 	( AppleEvent *ae, AppleEvent * AEreply,SInt32 handlerRefcon);typedef pascal OSErr 	(* OpenAppProc ) 	( AppleEvent *ae, AppleEvent * AEreply, SInt32 handlerRefcon);typedef pascal OSErr 	(* QuitAppProc ) 	( AppleEvent *ae, AppleEvent * AEreply, SInt32 handlerRefcon);typedef pascal OSErr 	(* PrintDocProc ) 	( AppleEvent *ae, AppleEvent * AEreply, SInt32 handlerRefcon);typedef pascal SInt16 	(* ScriptProc ) 	( SInt16 resId);typedef pascal OSErr 	(* OpenFileProc) 	(FSSpecPtr myFSSPtr);typedef pascal OSErr 	(*	NewDocProc ) 	(long refCon);struct MenuItemRec {	SInt16 			menuID  ;	SInt16 			menuItem  ;	Handle 			menuObject  ;	MenuHitProc 	menuHit  ;	MenuUpdateProc 	menuUpdate  ;};struct	GroupRec {	long 				groupType;	GroupRecHandle 		nextGroup;	short 				groupID;	WindowRef 			window ;	Str255 				groupTitle;	long  				groupRefCon;	short 				groupControlCount; 	StringArrayPtr 		groupControlnames; 	Rect 				groupBounds ; 	short 				groupHSpacing;	short 				groupVSpacing ;	short 				groupFlags;	PreGroupHitProc 	groupPreHit ; 	PostGroupHitProc 	groupPostHit ; 	GroupUpdateProc 	groupUpdate ;	ControlArrayPtr 	groupControlArray;};			struct ButtonItemRec {	long				buttonType;	ButtonItemRef		nextButton  ;	SInt16 				buttonID  ;	ControlRef 			buttonObject  ;	long				buttonRefCon;	GroupRecHandle		buttonGroup;	ButtonHitProc 		buttonHit  ;	ButtonUpdateProc	buttonUpdate  ;};struct ObjectItemRec {	long				objectType;	ObjectItemRef		nextObject;	SInt16				objectID;	Handle				objectHandle;	Str255				objectName;	Rect				objectRect;	UInt8				objectCmdKey;	WindowRef			objectOwner;	GroupRecHandle		objectGroup;	ObjectInitProc		objectInit;	ObjectDisposeProc	objectDispose;	ObjectHitProc		objectHit;	ObjectHitProc		objectTrack;	ObjectUpdateProc	objectUpdate;	ObjectIdleProc		objectIdle;	ObjectKeyProc		objectKey;	ObjectEditProc		objectEdit;	UInt32				objectRefCon;	UInt32				objectFlags;	SInt16				objectState;};/*				buttonType:longint; 				nextButton: ButtonItemRecHandle;				buttonID: integer;				buttonObject: ControlHandle;				buttonRefCon	: longint;				buttonGroup:GroupRecHandle;				buttonHit: ButtonHitProc;				buttonUpdate: ButtonUpdateProc;								*/typedef struct 	ScrollItemRec ScrollItemRec,*ScrollItemRecPtr, **ScrollItemRecHandle;					struct		ScrollItemRec {	SInt32 scrollType;	ScrollItemRecHandle nextScroll;	SInt16 scrollID;	ControlHandle scrollObject;	MyActionProc scrollHit;	MyActionProc scrollUpdate;	MyActionProc scrollIndicator;	MyActionProc scrollButton;};struct PrintAreaRec {		Rect windowPrintRect  ;		SInt16 windowPrintHorz  ;		SInt16 windowPrintVert  ;		SInt16 windowPrintLineHeight  ;		SInt16 windowPrintMaxVert  ;		SInt16 windowPrintMargin  ;};typedef struct PrintAreaRec PrintAreaRec ,* PrintAreaRecPtr,**PrintAreaRecHandle;typedef struct	ListItemRec ListItemRec,*ListItemRecPtr,**ListItemRecHandle ;struct	ListItemRec {	ListItemRecHandle nextList  ;	ListRef listObject  ;	SInt16 listID  ;	ListHitProc listHit  ;	ListUpdateProc listUpdate  ;	ListIdleProc listIdle  ;};typedef struct	EditFieldItemRec EditFieldItemRec,*EditFieldItemRecPtr,**EditFieldItemRecHandle ;struct EditFieldItemRec {	EditFieldItemRecHandle nextEdit  ;	SInt16 editFieldID  ;	SInt32 editFieldFlags ;	TEHandle editFieldObject  ;	EditFieldHitProc editFieldHit  ;	EditFieldUpdateProc editFieldUpdate  ;	EditFieldIdleProc editFieldIdle  ;}; enum { 		EditType,		ListType,	  	ButtonType} ;typedef SInt8 contentItemType;		struct	ContentRec {	SInt16 contentCount  ;	contentItemType kind  ;	union {		EditFieldItemRec efr  ;		ListItemRec lir  ;		ButtonItemRec bir ; 			};};typedef struct 	ContentRec ContentRec,*	ContentRecPtr;		typedef ContentRec WindowItemsArray[];typedef ContentRec * WindowItemsArrayPtr;struct WindowItemRec {		SInt32 					windowMagic  ; /* Signature so we know our windows */		SInt16 					windowID  ;		WindowRef 				windowObject  ;		WindowHitProc 			windowHit  ;		WindowUpdateProc 		windowUpdate  ;		WindowIdleProc 			windowIdle  ;		WindowGrowProc 			windowGrow  ;		WindowActivateProc 		windowActivate  ;		WindowCloseProc			windowClose;		WindowZoomProc			windowZoom;		PrintAreaRec 			windowPrintAreaRec  ;		FSSpec 					windowFSSpec  ;		SInt16                   windowRefNum;		ListItemRecHandle 		windowLists  ;		EditFieldItemRecHandle 	windowEdits  ;		ButtonItemRecHandle 	windowButtons  ;		ScrollItemRecHandle     windowScroll;		Boolean 				windowHasControls  ;		Boolean 				windowHasLists  ;		Boolean 				windowHasEditField  ;		SInt16 					windowItemCount  ;		WindowItemsArrayPtr 	windowItems  ;};typedef struct WindowItemRec WindowItemRec, *WindowItemRecPtr,**WindowItemRecHandle;		struct ProcTableRec {	EventProcs 		EventProcsArray[kMaxEventProcs];	TerminateProc 	Terminate ;	InitializeProc 	Initialize;	LowMemProc 		LowMem ;	MenuEventProc 	MenuEvent ;	AboutProc 		About;	OpenFileProc    openFile;	OpenDocProc 	openDocAE ;	OpenAppProc 	openAppAE;	QuitAppProc 	quitAppAE;	PrintDocProc 	printDocAE;	NewDocProc   	newDoc;};#if __POWERPC__// they are in the TOC#else#define gSACurrentWindow 	GSACURRENTWINDOW#define gSACurControl 		GSACURCONTROL#define gSAVPageSize 		GSAVPAGESIZE#define gSAHPageSize 		GSAHPAGESIZE#define gSAVLineSize 		GSAVLINESIZE#define gSAHLineSize		GSAHLINESIZE#define gSAEvent 			GSAEVENT#define gSAProcs    		GSAPROCS#define gSAMac	    		GSAMAC#define gSAIsInBackground   GSAISINBACKGROUND#endiftypedef struct ProcTableRec ProcTableRec, *ProcTablePtr;/*---------------------------------------------------------------------------------- */#pragma mark Globals/*---------------------------------------------------------------------------------- */extern	ListRef 		gSAMyList  ;extern	SInt16 			gSATerminateReason ; 	/* When Quiting this tells us why we are quiting */extern	Boolean 		gSADebug ;			/* Activate Debug Alerts. May make this an SInt16 */										/* for levels of debug */extern	ProcTableRec	gSAProcs  ;extern	Boolean 		gOApped  ;extern	Boolean 		gSADone  ;extern	Boolean 		gSAHasAppleEvents  ;extern	Boolean 		gSAHasTE  ;extern	Boolean 		gSAHasList  ;extern	MenuRef 		gSAAppleMenu  ;extern	MenuRef 		gSAFileMenu  ;extern	MenuRef 		gSAEditMenu  ;extern	EventRecord 	gSAEvent  ;extern	Boolean 		gSAHasControls  ;extern	WindowRef 		gSACurrentWindow  ;extern	SInt16 			gSADefaultFont  ;extern	SInt16 			gsADefaultSize  ;extern	SysEnvRec 		gSAMac  ;extern	WindowItemRecHandle gSACurWRecHandle  ;extern	SInt16 			gSAWindowID  ;extern	TEHandle 		gSACurTE  ;extern 	ControlHandle 	gSACurControl;extern	ListRef 		gSACurList  ;extern 	SInt16 			gSACurrentItem;extern 	Boolean			gSAIsInBackground;/*---------------------------------------------------------------------------------- */#pragma mark Prototypes/*---------------------------------------------------------------------------------- */pascal	SInt16	SAExecuteScript(SInt16 resID);pascal	void	SAMoveObject (ObjectItemRecHandle orh,SInt16 h,SInt16 v, Boolean reDraw);pascal	void	SADrawGroup(GroupRecHandle	grh,RgnHandle update);pascal	void	InitSimpleApp (SInt16 masters ,  Boolean wantsStandardMenu);pascal	void	Run(void);pascal	void	CloseSimpleApp(void);pascal  void	SADoWindowClose(WindowRef * theWindow);pascal	SInt16 DefaultMenuHit ( SInt32 modifiers);pascal	SInt16 InstallFontMenu(SInt16 menuID,							   ConstStr255Param name,							  MenuHitProc menuHit,							  MenuUpdateProc menuUpdate);pascal	SInt16 InstallMenu (SInt16 menuID,							ConstStr255Param menuTitle,							Boolean	Hierarchical,							MenuHitProc	menuHit,							MenuUpdateProc	menuUpdate );								pascal	SInt16 InstallResourceMenu (SInt16 menuID,									ConstStr255Param menuTitle,									OSType	resourceType,									SInt16	afterItem,									MenuHitProc	menuHit,									MenuUpdateProc	menuUpdate);pascal	SInt16 InstallMenuItem (SInt16 menuID, 								SInt16 MenuItem,								ConstStr255Param menuTitle, 								UInt8 mark,								UInt8 cmdChar,								MenuHitProc menuHit,								MenuUpdateProc menuUpdate);pascal	SInt16 InstallPushButton (SInt32 *buttonID,								 WindowRef window,								 ConstStr255Param name,								 Rect *r,								 UInt8 cmdKey,								 ButtonHitProc bhp ,								 ButtonUpdateProc bup  );								 pascal 	SInt16 InstallCustomObject (SInt32 * objectID,									WindowRef window ,									ConstStr255Param name ,									Rect * r ,									UInt8 cmdKey ,									ObjectInitProc oip ,									ObjectDisposeProc odp ,									ObjectHitProc ohp ,									ObjectTrackProc otp ,									ObjectUpdateProc oup ,									long refCon);									pascal SInt16 InstallControl (SInt32 * buttonID,							 WindowRef window,							 ConstStr255Param name,							 Rect *  r ,							 UInt8 cmdKey,							 SInt16 controlType,							 ButtonHitProc bhp ,							 ButtonUpdateProc bup );							 pascal SInt16 InstallCheckBox (SInt32 *buttonID,							 WindowRef window,							 ConstStr255Param name,							 Rect *  r ,							 UInt8 cmdKey,							 SInt16 initialValue, 							 ButtonHitProc bhp ,  /* set to nil for default checkbox action */							 ButtonUpdateProc bup );							 pascal	SInt16 InstallScrollBar (SInt32 * buttonID,								 WindowRef window,								 ConstStr255Param name,								 Rect *r,								 UInt8 cmdKey,								 MyActionProc scrollHitProc ,								 MyActionProc scrollButtonProc ,								 MyActionProc  scrollIndicatorProc);pascal SInt16 InstallPopUp (long	*theButtonID,							WindowRef window,							ConstStr255Param name,							Rect * r,							SInt16 options,							SInt16 styles,							SInt16 MenuID,							OSType resID,							ButtonHitProc bhp, 							ButtonUpdateProc bup 							);								 pascal SInt16 InstallRadioGroup (SInt16 theGroupID,								WindowRef window, 								SInt16 count, 								ConstStr255Param title,								StringArrayPtr names,								Rect * r, 								SInt16 defaultItem,								SInt16 hSpacing,								SInt16 vSpacing,								SInt16 buttonHeight,								SInt16 buttonWidth,								PreGroupHitProc PreGHP, 								PostGroupHitProc PostGHP, 								GroupUpdateProc gup );pascal	SInt16 CreateDocumentWindow (ConstStr255Param name  ,									Rect * bounds  ,									Boolean visable );pascal void SAInitScripting(void);									pascal	SInt16 GetDocumentWindow (  SInt16 resID);pascal	void Print (Str255 s );   				/* Print no CR */pascal	void PrintLine (Str255 s);				/* Print with CR */pascal	void PrintTextHandle (Handle text  ); 	/* Print a buffer full of text with CR */pascal	void SetRectLocation ( Rect *r,SInt16 h, SInt16 v);			/* This Sets a rects anchor point */pascal	void SetRectDimensions (Rect *r,SInt16 h, SInt16 v);			/* This Sets its size without changing its position */pascal	void GetPrintArea (WindowRef window ,Rect * bounds );pascal	void SetPrintArea (WindowRef window, Rect * bounds );pascal	EditFieldItemRecHandle SAGetEditField (WindowRef wind,SInt16 editID) ;pascal	void 	SASetFocus (WindowRef theWindow, EditFieldItemRecHandle efrh);pascal	SInt16	AttachMenuToItem(SInt16 menuIDToAdd,SInt16 AttachMenuID,SInt16 AttachItem);pascal	SInt16 InstallEditField (SInt32 * editID , 								WindowRef window,								ConstStr255Param name  ,								Rect * r,								EditFieldHitProc hitProc  ,								EditFieldUpdateProc updateProc  ,								ObjectKeyProc	keyProc	,								SInt32 flags  );pascal	SInt16 InstallList (SInt32 * listID  , 							WindowRef window,							Rect * r,							ListHitProc lhp  , 							ListUpdateProc lup  ,							ListDrawCellProc ldcp  , 							SInt32 flags );							pascal SInt16 	InstallPopUp(SInt32 *buttonID,							 WindowRef window,							 ConstStr255Param name,							 Rect *r,							 SInt16 options,							 SInt16 styles,							 SInt16 MenuID,							 OSType resID,							 ButtonHitProc bhp,							 ButtonHitProc bup);pascal	SInt16 GetTEString (SInt16 editFieldID  ,ConstStr255Param s  ) ;pascal	OSErr AddStringToList (ListRef listID  ,ConstStr255Param s  );pascal	void BlastString (SInt16 h, SInt16 v  ,Str255 s  ); /* These will blast text at the location specified. It erases as it draws */pascal	void BlastText (SInt16 h,SInt16 v  ,Handle text  );pascal	void InstallIdleProc(EventProcs  ip);pascal  void SetMyTitle(Str255 title);pascal  void SAEnableMe(void);pascal  void SADisableMe(void);pascal  void SAEnableObject(SInt32 thing);pascal  void SADisableObject(SInt32 thing);pascal  void SADisableMe();pascal 	ButtonItemRecHandle SAGetGroupItem(WindowRef wind,SInt16 groupID,SInt16 item);pascal	SInt16 SADrawObject(ObjectItemRecHandle orh,RgnHandle update);pascal 	SInt16 InstallStaticText(SInt32 * textID,WindowRef window,ConstStr255Param s ,Rect *r);pascal  void  ErrorMessage(ConstStr255Param msg,SInt32 error,SInt16 flags);pascal	Handle SAGetObjectHandle(long thing);pascal  void   SetWindowHitProc 	(WindowRef window,WindowHitProc 	theProc );pascal  void   SetWindowUpdateProc	(WindowRef window,WindowUpdateProc 	theProc );pascal  void   SetWindowIdleProc	(WindowRef window,WindowIdleProc 	theProc );pascal  void   SetWindowGrowProc	(WindowRef window,WindowGrowProc 	theProc );pascal  void   SetWindowActivateProc(WindowRef window,WindowActivateProc theProc );pascal  void   SetWindowCloseProc 	(WindowRef window,WindowCloseProc 	theProc );pascal  void   SetWindowZoomProc 	(WindowRef window,WindowZoomProc 	theProc );pascal  void   SetWindowFSSpec 		(WindowRef window,FSSpecPtr   FSSpec);pascal 	OSErr  GetWindowFSSpec 		(WindowRef window,FSSpecPtr  theFSSpec );pascal	WindowCloseProc  GetWindowCloseProc (WindowRef window);pascal 	void  	SelectFile(void);pascal 	void 	SetOpenFileProc (OpenFileProc openFile);pascal  void InstallPreEventHandler (PreEventProc eventHandler,long refCon);pascal short SASetSleepValue(short sleep);// drag stuffpascal OSErr SADoWindowContentDrag (WindowPtr theWindow, EventRecord *theEvent);pascal OSErr SAInstallDragHandlers (WindowPtr theWindow,DragTrackingHandlerProcPtr track,DragReceiveHandlerProcPtr receive);pascal OSErr SAInstallStandardDragHandlers (WindowPtr theWindow);pascal OSErr SAAddDataType(WindowPtr theWindow,OSType theType);pascal OSErr SAAddWindowDragDataTypes(WindowPtr theWindow,OSType theType);	pascal OSErr InstallDragObject(long * ObjectID,WindowRef window,ConstStr255Param name,Rect * r,GetDragDataProc gdp,PutDragDataProc pdp,ObjectReceiveProc orp, long refCon);#endif	