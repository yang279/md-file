#include "kiwi.h"

class BinarySchema {
public:
  bool parse(kiwi::ByteBuffer &bb);
  const kiwi::BinarySchema &underlyingSchema() const { return _schema; }
  bool skipPaintField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipPaintFilterMessageField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipColorStopField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipImageMessageField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipPathField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipGUIDPathField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipVectorDataField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipArcDataField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipEffectField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipSymbolDataField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipLayoutGridField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipGridTrackSizingField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipExportConstraintField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipExportSettingsField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipFontNameField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipTextDataField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipHyperlinkBoxField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipFontMetaDataField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipDecorationField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipGlyphField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipParagraphStyleField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipBaselineField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipKeyTriggerField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipPrototypeDeviceField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipPrototypeInteractionField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipConditionalActionsField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipVideoPlaybackField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipVariableWidthPointField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipPrototypeSelectedStateField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipPrototypeStateChangeField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipPrototypeActionField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipPrototypeEventField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipComponentPropDefField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipComponentPropRefField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipComponentPropValueField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipInstanceSwapPreferredValueField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipComponentPropPreferredValuesField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipComponentPropAssignmentField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipBlobField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipPixsoNodeField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipProdModeField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipBlockMarkerParamsField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipProdLayoutParamField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipProdLayoutIntervalField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipProdAdjustSizeField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipProdMovingField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipProdRotateField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipProdTableCellField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipProdTextStyleField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipProdScoreBarField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipProdDragBarField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipProdScalingFactorField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipProdTDCElementinfoField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipProdTwoDimChartField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipGuideField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipOverlayBackgroundAppearanceField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipNumberField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipParentIndexField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipUserInfoField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipViewportField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipMouseField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipClickField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipScrollPositionField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipTriggeredOverlayDataField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipHyperlinkField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipSharedStyleMasterDataField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipSharedStyleReferenceField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipPixsoMsgField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipVectorStyleDataField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipTextStyleDataField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipPropValueDataField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipSceneGraphQueryField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipPrototypeStartPointField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipConnectLineInfoField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipObjSnapConnlineField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipConnlineTextInfoField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipVectorPaintField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipVectorStyleField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipPluginDataField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipPluginRelaunchDataField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipPlaceHolderField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipSpotlightField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipFileMetaField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipEditInfoField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipSymbolLinkField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipDeveloperRelatedLinkField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipFontVariationField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipPathTextInfoField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipGlyphPoseField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipRadialRepeatDataField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipTransformModifierField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipAssetIDField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipVariableSetModeField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipVariableDataValuesField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipVariableDataValuesEntryField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipVariableDataMapField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipVariableDataMapEntryField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipVariableDataField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipVariableAnyValueField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipExpressionField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipAssetRefField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipVariableFontStyleField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipVariableMapField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipColorStopVarField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipVariableModeBySetMapField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipVariableModeBySetMapEntryField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipVariableMapValueField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipVariableIdOrVariableOverrideIdField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipVariableOverrideIdField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipPrototypeVariableTargetField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipTriggeredSetVariableActionDataField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipTriggeredSetVariableModeActionDataField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipNodeFieldAliasField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipCodeSyntaxMapField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipCodeSyntaxMapEntryField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipDeliverInfoField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipAnnotationPropertyField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipAnnotationCategoryCustomField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipAnnotationCategoryField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipAnnotationCategoriesField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipAnnotationField(kiwi::ByteBuffer &bb, uint32_t id) const;

private:
  kiwi::BinarySchema _schema;
  uint32_t _indexPaint = 0;
  uint32_t _indexPaintFilterMessage = 0;
  uint32_t _indexColorStop = 0;
  uint32_t _indexImageMessage = 0;
  uint32_t _indexPath = 0;
  uint32_t _indexGUIDPath = 0;
  uint32_t _indexVectorData = 0;
  uint32_t _indexArcData = 0;
  uint32_t _indexEffect = 0;
  uint32_t _indexSymbolData = 0;
  uint32_t _indexLayoutGrid = 0;
  uint32_t _indexGridTrackSizing = 0;
  uint32_t _indexExportConstraint = 0;
  uint32_t _indexExportSettings = 0;
  uint32_t _indexFontName = 0;
  uint32_t _indexTextData = 0;
  uint32_t _indexHyperlinkBox = 0;
  uint32_t _indexFontMetaData = 0;
  uint32_t _indexDecoration = 0;
  uint32_t _indexGlyph = 0;
  uint32_t _indexParagraphStyle = 0;
  uint32_t _indexBaseline = 0;
  uint32_t _indexKeyTrigger = 0;
  uint32_t _indexPrototypeDevice = 0;
  uint32_t _indexPrototypeInteraction = 0;
  uint32_t _indexConditionalActions = 0;
  uint32_t _indexVideoPlayback = 0;
  uint32_t _indexVariableWidthPoint = 0;
  uint32_t _indexPrototypeSelectedState = 0;
  uint32_t _indexPrototypeStateChange = 0;
  uint32_t _indexPrototypeAction = 0;
  uint32_t _indexPrototypeEvent = 0;
  uint32_t _indexComponentPropDef = 0;
  uint32_t _indexComponentPropRef = 0;
  uint32_t _indexComponentPropValue = 0;
  uint32_t _indexInstanceSwapPreferredValue = 0;
  uint32_t _indexComponentPropPreferredValues = 0;
  uint32_t _indexComponentPropAssignment = 0;
  uint32_t _indexBlob = 0;
  uint32_t _indexPixsoNode = 0;
  uint32_t _indexProdMode = 0;
  uint32_t _indexBlockMarkerParams = 0;
  uint32_t _indexProdLayoutParam = 0;
  uint32_t _indexProdLayoutInterval = 0;
  uint32_t _indexProdAdjustSize = 0;
  uint32_t _indexProdMoving = 0;
  uint32_t _indexProdRotate = 0;
  uint32_t _indexProdTableCell = 0;
  uint32_t _indexProdTextStyle = 0;
  uint32_t _indexProdScoreBar = 0;
  uint32_t _indexProdDragBar = 0;
  uint32_t _indexProdScalingFactor = 0;
  uint32_t _indexProdTDCElementinfo = 0;
  uint32_t _indexProdTwoDimChart = 0;
  uint32_t _indexGuide = 0;
  uint32_t _indexOverlayBackgroundAppearance = 0;
  uint32_t _indexNumber = 0;
  uint32_t _indexParentIndex = 0;
  uint32_t _indexUserInfo = 0;
  uint32_t _indexViewport = 0;
  uint32_t _indexMouse = 0;
  uint32_t _indexClick = 0;
  uint32_t _indexScrollPosition = 0;
  uint32_t _indexTriggeredOverlayData = 0;
  uint32_t _indexHyperlink = 0;
  uint32_t _indexSharedStyleMasterData = 0;
  uint32_t _indexSharedStyleReference = 0;
  uint32_t _indexPixsoMsg = 0;
  uint32_t _indexVectorStyleData = 0;
  uint32_t _indexTextStyleData = 0;
  uint32_t _indexPropValueData = 0;
  uint32_t _indexSceneGraphQuery = 0;
  uint32_t _indexPrototypeStartPoint = 0;
  uint32_t _indexConnectLineInfo = 0;
  uint32_t _indexObjSnapConnline = 0;
  uint32_t _indexConnlineTextInfo = 0;
  uint32_t _indexVectorPaint = 0;
  uint32_t _indexVectorStyle = 0;
  uint32_t _indexPluginData = 0;
  uint32_t _indexPluginRelaunchData = 0;
  uint32_t _indexPlaceHolder = 0;
  uint32_t _indexSpotlight = 0;
  uint32_t _indexFileMeta = 0;
  uint32_t _indexEditInfo = 0;
  uint32_t _indexSymbolLink = 0;
  uint32_t _indexDeveloperRelatedLink = 0;
  uint32_t _indexFontVariation = 0;
  uint32_t _indexPathTextInfo = 0;
  uint32_t _indexGlyphPose = 0;
  uint32_t _indexRadialRepeatData = 0;
  uint32_t _indexTransformModifier = 0;
  uint32_t _indexAssetID = 0;
  uint32_t _indexVariableSetMode = 0;
  uint32_t _indexVariableDataValues = 0;
  uint32_t _indexVariableDataValuesEntry = 0;
  uint32_t _indexVariableDataMap = 0;
  uint32_t _indexVariableDataMapEntry = 0;
  uint32_t _indexVariableData = 0;
  uint32_t _indexVariableAnyValue = 0;
  uint32_t _indexExpression = 0;
  uint32_t _indexAssetRef = 0;
  uint32_t _indexVariableFontStyle = 0;
  uint32_t _indexVariableMap = 0;
  uint32_t _indexColorStopVar = 0;
  uint32_t _indexVariableModeBySetMap = 0;
  uint32_t _indexVariableModeBySetMapEntry = 0;
  uint32_t _indexVariableMapValue = 0;
  uint32_t _indexVariableIdOrVariableOverrideId = 0;
  uint32_t _indexVariableOverrideId = 0;
  uint32_t _indexPrototypeVariableTarget = 0;
  uint32_t _indexTriggeredSetVariableActionData = 0;
  uint32_t _indexTriggeredSetVariableModeActionData = 0;
  uint32_t _indexNodeFieldAlias = 0;
  uint32_t _indexCodeSyntaxMap = 0;
  uint32_t _indexCodeSyntaxMapEntry = 0;
  uint32_t _indexDeliverInfo = 0;
  uint32_t _indexAnnotationProperty = 0;
  uint32_t _indexAnnotationCategoryCustom = 0;
  uint32_t _indexAnnotationCategory = 0;
  uint32_t _indexAnnotationCategories = 0;
  uint32_t _indexAnnotation = 0;
};

enum class PixsoMsgType : uint32_t {
  JOIN_START = 1,
  NODE_CHANGES = 2,
  USER_CHANGES = 3,
  JOIN_END = 4,
  SIGNAL = 5,
  STYLE = 6,
  STYLE_SET = 7,
  JOIN_START_SKIP_RELOAD = 8,
  NOTIFY_SHOULD_UPGRADE = 9,
  UPGRADE_DONE = 10,
  UPGRADE_REFRESH = 11,
  SCENE_GRAPH_QUERY = 12,
  SCENE_GRAPH_REPLY = 13,
  FIC_DOCUMENT = 14,
  UPDATE_VERSION = 15,
  PIX_DOCUMENT = 16,
  SPOTLIGHT_OPEN = 17,
  SPOTLIGHT_CLOSE = 18,
  COMPONENT_QUERY = 19,
  COMPONENT_REPLY = 20,
};

enum class NodePhase : uint32_t {
  MODIFY = 0,
  CREATED = 1,
  REMOVED = 2,
};

enum class NodeType : uint32_t {
  NONE = 1,
  DOCUMENT = 2,
  CANVAS = 3,
  GROUP = 4,
  FRAME = 5,
  BOOLEAN_OPERATION = 6,
  VECTOR = 7,
  STAR = 8,
  LINE = 9,
  ELLIPSE = 10,
  RECTANGLE = 11,
  REGULAR_POLYGON = 12,
  ROUNDED_RECTANGLE = 13,
  TEXT = 14,
  SLICE = 15,
  SYMBOL = 16,
  INSTANCE = 17,
  CONNECTLINE = 18,
  DIRECTORY = 19,
  PROD_RECTANGLE = 20,
  PROD_ELLIPSE = 21,
  PROD_STAT = 22,
  PROD_POLYGON = 23,
  PROD_DROPDOWNBOX = 24,
  PROD_EMBEDDEDSVGICON = 25,
  PROD_SIDEMENU = 26,
  PROD_LISTMENU = 27,
  PROD_FIRSTNAVIGATIONBAR = 28,
  PROD_SECONDNAVIGATIONBAR = 29,
  PROD_LEFTNAVIGATIONBAR = 30,
  PROD_DOWNNAVIGATIONBAR = 31,
  PROD_TABLE = 32,
  PROD_TABLECELL = 33,
  PROD_NAVIGATIONBARITEM = 34,
  PROD_LISTOPTION = 35,
  PROD_LINE = 36,
  PROD_TEXT = 37,
  PROD_NAVIGATIONBAROPTION = 38,
  PROD_MENUOPTION = 39,
  PROD_RADIOICONNODE = 40,
  PROD_PLACEHOLDER = 41,
  PROD_IMAGEPLACEHOLDER = 42,
  PROD_PRIMARYBUTTON = 43,
  PROD_BUTTON = 44,
  PROD_CHECKBOX = 45,
  PROD_RADIO = 46,
  PROD_SWITCH = 47,
  PROD_TEXTALERT = 48,
  PROD_SEARCHBOX = 49,
  PROD_INPUTBOX = 50,
  PROD_PASSWORDINPUTBOX = 51,
  PROD_ICONLIST = 52,
  PROD_SWITCHLIST = 53,
  PROD_TOAST = 54,
  PROD_ALERT = 55,
  PROD_INPUTALERT = 56,
  PROD_BOTTONALERT = 57,
  PROD_CARD = 58,
  PROD_LARGECARD = 59,
  PROD_MASK = 60,
  PROD_STATESBAR = 61,
  PROD_TITLESBAR = 62,
  PROD_IMAGE = 63,
  PROD_TITLESBAR2 = 64,
  PROD_THREEBUTTONSALERT = 65,
  PROD_TICKALERT = 66,
  PROD_INPUTRANGESEARCH = 67,
  PROD_INPUTDROP = 68,
  PROD_INPUTDATA = 69,
  PROD_INPUTMULROW = 70,
  PROD_INPUTVERIFICATION = 71,
  PROD_MENUOPTIONECOMPONENT = 72,
  PROD_SIDENAVIGATBAR = 73,
  PROD_DATASELECTOR = 74,
  PROD_PAGERCOMPONENT = 75,
  PROD_STEPPER = 76,
  PROD_MAPCOMPONENT = 77,
  PROD_HISTOGRAM = 78,
  PROD_PIECHART = 79,
  PROD_LINECHART = 80,
  PROD_ICONBUTTON = 81,
  PROD_MOREBUTTON = 82,
  PROD_SCOREBAR = 83,
  PROD_PROCESSBAR = 84,
  PROD_DRAGBAR = 85,
  PROD_SVGFRAME = 86,
  PROD_LARGECARD3 = 87,
  PROD_LARGECARD4 = 88,
  PROD_TOASTLOADING = 89,
  PROD_SIDENAVIGATBAR2 = 90,
  PROD_PAGERCOMPONENT2 = 91,
  PROD_ITEMTABLE = 92,
  PROD_LABEL = 93,
  PROD_TOASTSUCCESSPC = 94,
  PROD_TOASTDEFEATERPC = 95,
  PROD_TOASTWARNPC = 96,
  PROD_TOASTNOTICEPC = 97,
  PROD_TOASTLOADINGPC = 98,
  PROD_TOASTSINGLEBUTTONPC = 99,
  PROD_TOASTDOUBLEBUTTONPC = 100,
  PROD_TOASTTIPSPC = 101,
  PROD_PLUSNAVIGATBAR = 102,
  PROD_STEPPER2 = 103,
  SECTION = 104,
  PROD_BREADCRUMB = 105,
  PROD_BREADCRUMBITEM = 106,
  PROD_IBUTTON = 107,
  PROD_IPLACEHOLDER = 108,
  PROD_IMASK = 109,
  PROD_ISTATUSBAR = 110,
  PROD_IINPUTBOX = 111,
  PROD_IRADIOANDCHECKBUTTON = 112,
  PROD_IRADIOBUTTON = 113,
  PROD_ISTEPPER = 114,
  PROD_VIEWPORTTEXT = 115,
  PROD_RECTBOX = 116,
  PROD_SELECTBOX = 117,
  PROD_SELECTOPTION = 118,
  PROD_SMARTTABLE = 119,
  PROD_SMARTTABLECELL = 120,
  PROD_BLOCK = 121,
  PROD_BLOCKDOCUMENT = 122,
  PROD_TOPBARPC = 123,
  PROD_TOPBARITEMPC = 124,
  PROD_TOPBAROPTIONPC = 125,
  PROD_TOPBARMD = 126,
  PROD_DROPDOWNBOXSIMPLE = 127,
  PROD_SELECTBOXSTYLE1 = 128,
  PROD_LISTOPTIONMENU = 129,
  PROD_SIDEBARPC = 130,
  PROD_SIDEBARITEMPC = 131,
  PROD_SIDEBAROPTIONPC = 132,
  PROD_IPAGERCOMPONENT = 133,
  PROD_SIDENBMD = 134,
  PROD_SIDENBITEMMD = 135,
  PROD_DOWNNBMD = 136,
  PROD_DOWNNBITEMMD = 137,
  PROD_LABELMD = 138,
  PROD_LABELPC = 139,
  PROD_LABELITEM = 140,
  PROD_DYNAMICPANEL = 141,
  PROD_DYNAMICPANELSTATE = 142,
  PROD_HOTZONE = 143,
  PROD_TAG = 144,
  PROD_TAGITEM = 145,
  PROD_AVATAR = 146,
  PROD_HOTZONE_FIX = 147,
  PROD_LEFTPANELSVGICON = 148,
  PROD_BUBBLEPANEL = 149,
  PROD_TWODIMCHART = 150,
  PATH_TEXT = 151,
  RADIAL_PATTERN = 152,
  VARIABLE = 153,
  VARIABLE_SET = 154,
  TRANSFORM = 155,
  PROD_TREE = 156,
  PROD_TREEOPTION = 157,
  PROD_BLOCKMARKER = 158,
};

enum class MarkerSide : uint32_t {
  BLOCKSIDE = 0,
  TARGETSIDE = 1,
};

enum class ProdLayoutMode : uint32_t {
  NONE = 1,
  LINEAR = 2,
};

enum class ProdLayoutSizeMode : uint32_t {
  FIXEDNUM = 1,
  WRAPCONTENT = 2,
  MATCHPARENT = 3,
};

enum class ProdChangeLocationType : uint32_t {
  MOVE = 1,
  MOVETO = 2,
};

enum class ProdRotationType : uint32_t {
  ROTATE = 1,
  ROTATETO = 2,
};

enum class ProdAdjustSizeType : uint32_t {
  ADJUST = 1,
  ADJUSTTO = 2,
};

enum class ProdAdjustBaseType : uint32_t {
  LEFTTOP = 1,
  TOP = 2,
  RIGHTTOP = 3,
  LEFT = 4,
  CENTER = 5,
  RIGHT = 6,
  LEFTBOTTOM = 7,
  BOTTOM = 8,
  RIGHTBOTTOM = 9,
};

enum class ProdAdjustUnitType : uint32_t {
  PERCENTAGE = 1,
  PIXEL = 2,
};

enum class ProdViewportOrientation : uint32_t {
  Horizontal = 1,
  Vertical = 2,
};

enum class ProdBlockStyleType : uint32_t {
  DEFAULT = 0,
  H1 = 1,
  H2 = 2,
  H3 = 3,
};

enum class BooleanOperation : uint32_t {
  UNION = 1,
  INTERSECT = 2,
  SUBTRACT = 3,
  XOR = 4,
};

enum class BlendMode : uint32_t {
  PASS_THROUGH = 1,
  NORMAL = 2,
  DARKEN = 3,
  MULTIPLY = 4,
  LINEAR_BURN = 5,
  COLOR_BURN = 6,
  LIGHTEN = 7,
  SCREEN = 8,
  LINEAR_DODGE = 9,
  COLOR_DODGE = 10,
  OVERLAY = 11,
  SOFT_LIGHT = 12,
  HARD_LIGHT = 13,
  DIFFERENCE = 14,
  EXCLUSION = 15,
  HUE = 16,
  SATURATION = 17,
  COLOR = 18,
  LUMINOSITY = 19,
};

enum class NoiseType : uint32_t {
  MULTITONE = 0,
  MONOTONE = 1,
  DUOTONE = 2,
};

enum class EffectType : uint32_t {
  INNER_SHADOW = 1,
  DROP_SHADOW = 2,
  FOREGROUND_BLUR = 3,
  BACKGROUND_BLUR = 4,
  MOTION_BLUR = 5,
  GLASS = 6,
  GRAIN = 7,
  NOISE = 8,
  ZOOM_BLUR = 9,
};

enum class StackCounterAlign : uint32_t {
  MIN = 1,
  CENTER = 2,
  MAX = 3,
  STRETCH = 4,
};

enum class StackAlignItemMode : uint32_t {
  MIN = 1,
  CENTER = 2,
  MAX = 3,
  SPACE_EVENLY = 4,
};

enum class StackSize : uint32_t {
  FIXED = 1,
  RESIZE_TO_FIT = 2,
};

enum class StackJustify : uint32_t {
  MIN = 1,
  CENTER = 2,
  MAX = 3,
  SPACE_EVENLY = 4,
};

enum class StackMode : uint32_t {
  NONE = 1,
  HORIZONTAL = 2,
  VERTICAL = 3,
  GRID = 4,
};

enum class StrokeAlign : uint32_t {
  CENTER = 1,
  INSIDE = 2,
  OUTSIDE = 3,
};

enum class StrokeCap : uint32_t {
  NONE = 1,
  ROUND = 2,
  SQUARE = 3,
  ARROW_LINES = 4,
  ARROW_EQUILATERAL = 5,
  TRIANGLE_FILLED = 6,
  DIAMOND_FILLED = 7,
  HOLLOW_ROUND = 8,
  SOLID_ROUND = 9,
  VERTICAL_LINE = 10,
};

enum class StrokeJoin : uint32_t {
  MITER = 1,
  BEVEL = 2,
  ROUND = 3,
};

enum class StyleType : uint32_t {
  NONE = 1,
  FILL = 2,
  STROKE = 3,
  TEXT = 4,
  EFFECT = 5,
  EXPORT = 6,
  GRID = 7,
};

enum class LayoutGridType : uint32_t {
  MIN = 1,
  CENTER = 2,
  STRETCH = 3,
  MAX = 4,
};

enum class Axis : uint32_t {
  X = 1,
  Y = 2,
};

enum class LayoutGridPattern : uint32_t {
  STRIPES = 1,
  GRID = 2,
};

enum class GridChildAlign : uint32_t {
  MIN = 1,
  CENTER = 2,
  MAX = 3,
};

enum class GridTrackSizingType : uint32_t {
  FLEX = 1,
  FIXED = 2,
};

enum class ImageType : uint32_t {
  PNG = 1,
  JPEG = 2,
  SVG = 3,
  PDF = 4,
  SKETCH = 5,
  EPS = 6,
  TIFF = 7,
  WEBP = 8,
};

enum class ExportConstraintType : uint32_t {
  CONTENT_SCALE = 1,
  CONTENT_WIDTH = 2,
  CONTENT_HEIGHT = 3,
};

enum class ExportSVGIDMode : uint32_t {
  IF_NEEDED = 1,
  ALWAYS = 2,
};

enum class FontVariantCaps : uint32_t {
  NORMAL = 1,
  SMALL = 2,
  ALL_SMALL = 3,
  PETITE = 4,
  ALL_PETITE = 5,
  UNICASE = 6,
  TITLING = 7,
};

enum class FontVariantNumericFigure : uint32_t {
  NORMAL = 1,
  LINING = 2,
  OLDSTYLE = 3,
};

enum class FontVariantNumericFraction : uint32_t {
  NORMAL = 1,
  DIAGONAL = 2,
  STACKED = 3,
};

enum class FontVariantNumericSpacing : uint32_t {
  NORMAL = 1,
  PROPORTIONAL = 2,
  TABULAR = 3,
};

enum class FontVariantPosition : uint32_t {
  NORMAL = 1,
  SUB = 2,
  SUPER = 3,
};

enum class TextAlignHorizontal : uint32_t {
  LEFT = 1,
  CENTER = 2,
  RIGHT = 3,
  JUSTIFIED = 4,
};

enum class TextAlignVertical : uint32_t {
  TOP = 1,
  CENTER = 2,
  BOTTOM = 3,
};

enum class TextAutoResize : uint32_t {
  NONE = 1,
  WIDTH_AND_HEIGHT = 2,
  HEIGHT = 3,
};

enum class TextCase : uint32_t {
  ORIGINAL = 1,
  UPPER = 2,
  LOWER = 3,
  TITLE = 4,
  SMALL_CAPS = 5,
  SMALL_CAPS_FORCED = 6,
};

enum class FontStyle : uint32_t {
  NORMAL = 1,
  ITALIC = 2,
};

enum class TextDecoration : uint32_t {
  NONE = 1,
  UNDERLINE = 2,
  STRIKETHROUGH = 3,
};

enum class ConstraintType : uint32_t {
  MIN = 1,
  CENTER = 2,
  MAX = 3,
  STRETCH = 4,
  SCALE = 5,
  FIXED_MIN = 6,
  FIXED_MAX = 7,
};

enum class TriggerDevice : uint32_t {
  KEYBOARD = 1,
  UNKNOWN_CONTROLLER = 2,
  XBOX_ONE = 3,
  PS4 = 4,
  SWITCH_PRO = 5,
};

enum class InteractionType : uint32_t {
  ON_CLICK = 1,
  AFTER_TIMEOUT = 2,
  MOUSE_IN = 3,
  MOUSE_OUT = 4,
  ON_HOVER = 5,
  MOUSE_DOWN = 6,
  MOUSE_UP = 7,
  ON_PRESS = 8,
  NONE = 9,
  DRAG = 10,
  ON_KEY_DOWN = 11,
  ON_VOICE = 12,
  ON_DOUBLECLICK = 13,
  SIDE_LEFT = 14,
  SIDE_RIGHT = 15,
  SIDE_UP = 16,
  SIDE_DOWN = 17,
};

enum class ConnectionType : uint32_t {
  NONE = 1,
  INTERNAL_NODE = 2,
  URL = 3,
  BACK = 4,
  CLOSE = 5,
  SCROLLTO = 6,
  SETSHOWHIDE = 7,
  CHANGESIZE = 8,
  CHANGELOCATION = 9,
  CHANGEDYNAMICPANELSTATE = 10,
  ROTATION = 11,
  WAIT = 12,
  UPDATE_MEDIA_RUNTIME = 13,
  CONDITIONAL = 14,
  SET_VARIABLE = 15,
  SET_VARIABLE_MODE = 16,
  SET_ENABLE_STATE = 17,
  SET_SELECTED_STATE = 18,
  SET_SWITCH_STATE = 19,
};

enum class PrototypeStateAction : uint32_t {
  TRUE_STATE = 1,
  FALSE_STATE = 2,
  TOGGLE = 3,
};

enum class PrototypeSelectedStateType : uint32_t {
  SELECT_GUID = 1,
  SWITCH_STATUS = 2,
  CHECKBOX_STATE = 3,
};

enum class EasingType : uint32_t {
  LINEAR = 1,
  IN_CUBIC = 2,
  OUT_CUBIC = 3,
  INOUT_CUBIC = 4,
  INBACK_CUBIC = 5,
  OUTBACK_CUBIC = 6,
  INOUTBACK_CUBIC = 7,
  CUSTOM_CUBIC = 8,
  NONE = 9,
  SPRING = 10,
  GENTLE_SPRING = 11,
  CUSTOM_SPRING = 12,
  SPRING_PRESET_ONE = 13,
  SPRING_PRESET_TWO = 14,
  SPRING_PRESET_THREE = 15,
};

enum class PrototypeDeviceType : uint32_t {
  NONE = 1,
  PRESET = 2,
  CUSTOM = 3,
  PRESENTATION = 4,
};

enum class PrototypeShowHide : uint32_t {
  SHOW = 1,
  HIDE = 2,
  SWITCH = 3,
};

enum class DeviceRotation : uint32_t {
  NONE = 1,
  CCW_90 = 2,
};

enum class TransitionType : uint32_t {
  INSTANT_TRANSITION = 1,
  DISSOLVE = 2,
  SMART_ANIMATE = 3,
  SLIDE_FROM_LEFT = 4,
  SLIDE_FROM_RIGHT = 5,
  SLIDE_FROM_TOP = 6,
  SLIDE_FROM_BOTTOM = 7,
  PUSH_FROM_LEFT = 8,
  PUSH_FROM_RIGHT = 9,
  PUSH_FROM_TOP = 10,
  PUSH_FROM_BOTTOM = 11,
  MOVE_FROM_LEFT = 12,
  MOVE_FROM_RIGHT = 13,
  MOVE_FROM_TOP = 14,
  MOVE_FROM_BOTTOM = 15,
  SLIDE_OUT_TO_LEFT = 16,
  SLIDE_OUT_TO_RIGHT = 17,
  SLIDE_OUT_TO_TOP = 18,
  SLIDE_OUT_TO_BOTTOM = 19,
  MOVE_OUT_TO_LEFT = 20,
  MOVE_OUT_TO_RIGHT = 21,
  MOVE_OUT_TO_TOP = 22,
  MOVE_OUT_TO_BOTTOM = 23,
  MAGIC_MOVE = 24,
  SCROLL_ANIMATE = 25,
  LAYER_DISSOLVE = 26,
};

enum class OverlayBackgroundInteraction : uint32_t {
  NONE = 1,
  CLOSE_ON_CLICK_OUTSIDE = 2,
};

enum class OverlayBackgroundType : uint32_t {
  NONE = 1,
  SOLID_COLOR = 2,
};

enum class OverlayPositionType : uint32_t {
  CENTER = 1,
  TOP_LEFT = 2,
  TOP_CENTER = 3,
  TOP_RIGHT = 4,
  BOTTOM_LEFT = 5,
  BOTTOM_CENTER = 6,
  BOTTOM_RIGHT = 7,
  MANUAL = 8,
};

enum class ScrollDirection : uint32_t {
  NONE = 1,
  HORIZONTAL = 2,
  VERTICAL = 3,
  BOTH = 4,
};

enum class NavigationType : uint32_t {
  NAVIGATE = 1,
  OVERLAY = 2,
  SWAP = 3,
  SWAP_STATE = 4,
  SCROLL_TO = 5,
  SHOW_HIDE = 6,
};

enum class MediaAction : uint32_t {
  PLAY = 1,
  PAUSE = 2,
  TOGGLE_PLAY_PAUSE = 3,
  MUTE = 4,
  UNMUTE = 5,
  TOGGLE_MUTE_UNMUTE = 6,
  SKIP_FORWARD = 7,
  SKIP_BACKWARD = 8,
  SKIP_TO = 9,
};

enum class NumberUnits : uint32_t {
  RAW = 1,
  PIXELS = 2,
  PERCENT = 3,
};

enum class ScrollBehavior : uint32_t {
  SCROLLS = 1,
  FIXED_WHEN_CHILD_OF_SCROLLING_FRAME = 2,
};

enum class PatternAlignment : uint32_t {
  START = 0,
  CENTER = 1,
  END = 2,
};

enum class PatternTileType : uint32_t {
  RECTANGULAR = 0,
  HORIZONTAL_HEXAGONAL = 1,
  VERTICAL_HEXAGONAL = 2,
};

enum class PaintType : uint32_t {
  SOLID = 1,
  GRADIENT_LINEAR = 2,
  GRADIENT_RADIAL = 3,
  GRADIENT_ANGULAR = 4,
  GRADIENT_DIAMOND = 5,
  IMAGE = 6,
  EMOJI = 7,
  GIF = 8,
  VIDEO = 9,
  PATTERN = 10,
};

enum class ImageScaleMode : uint32_t {
  STRETCH = 1,
  FIT = 2,
  FILL = 3,
  TILE = 4,
};

enum class ScrollBar : uint32_t {
  AUTOSHOW = 1,
  SHOW = 2,
  HIDE = 3,
};

enum class ComponentStateType : uint32_t {
  DEFAULT_STATE = 0,
  HOVER_STATE = 1,
  ACTIVE_STATE = 2,
  DISABLED_STATE = 3,
};

enum class MouseCursor : uint32_t {
  DEFAULT = 1,
  CROSSHAIR = 2,
  EYEDROPPER = 3,
  HAND = 4,
  PAINT_BUCKET = 5,
  PEN = 6,
  PENCIL = 7,
};

enum class Access : uint32_t {
  READ_ONLY = 1,
  READ_WRITE = 2,
};

enum class StyleSetType : uint32_t {
  PERSONAL = 1,
  TEAM = 2,
  CUSTOM = 3,
  FREQUENCY = 4,
  TEMPORARY = 5,
};

enum class StyleSetContentType : uint32_t {
  SOLID = 1,
  GRADIENT = 2,
  IMAGE = 3,
};

enum class WindingRule : uint32_t {
  NONZERO = 1,
  ODD = 2,
  INVERSE_NONZERO = 3,
  INVERSE_ODD = 4,
};

enum class VectorMirror : uint32_t {
  NONE = 1,
  ANGLE = 2,
  ANGLE_AND_LENGTH = 3,
  RIGHT_ANGLE = 4,
};

enum class OverflowType : uint32_t {
  NONE = 1,
  HORIZONTAL = 2,
  VERTICAL = 3,
  HORIZONTAL_AND_VERTICAL = 4,
};

enum class ConnectLineType : uint32_t {
  StraightLine = 1,
  Curve = 2,
  RightAngle = 3,
  FilletPlotLine = 4,
};

enum class ConnLineTextAngleType : uint32_t {
  Horizontal = 1,
  TangentAngle = 2,
};

enum class ConnectPointType : uint32_t {
  None = 1,
  BeginPt = 2,
  EndPt = 3,
};

enum class SnapToObjType : uint32_t {
  None = 1,
  CenterPt = 2,
  Outline = 3,
  Vertex = 4,
  Inside = 5,
  WholeShape = 6,
};

enum class ExportImageQualityOp : uint32_t {
  ExportQuality_Origin = 1,
  ExportQuality_High = 2,
  ExportQuality_Mid = 3,
  ExportQuality_Low = 4,
};

enum class TextListStyle : uint32_t {
  PLAIN = 0,
  ORDERED_LIST = 1,
  UNORDERED_LIST = 2,
};

enum class TextTruncation : uint32_t {
  DISABLED = 0,
  ENDING = 1,
};

enum class MaskType : uint32_t {
  ALPHA = 0,
  OUTLINE = 1,
  LUMINANCE = 2,
};

enum class LeadingTrim : uint32_t {
  NONE = 0,
  CAP_HEIGHT = 1,
};

enum class OpenTypeFeature : uint32_t {
  PCAP = 0,
  C2PC = 1,
  CASE = 2,
  CPSP = 3,
  TITL = 4,
  UNIC = 5,
  ZERO = 6,
  SINF = 7,
  ORDN = 8,
  AFRC = 9,
  DNOM = 10,
  NUMR = 11,
  LIGA = 12,
  CLIG = 13,
  DLIG = 14,
  HLIG = 15,
  RLIG = 16,
  AALT = 17,
  CALT = 18,
  RCLT = 19,
  SALT = 20,
  RVRN = 21,
  VERT = 22,
  SWSH = 23,
  CSWH = 24,
  NALT = 25,
  CCMP = 26,
  STCH = 27,
  HIST = 28,
  SIZE = 29,
  ORNM = 30,
  ITAL = 31,
  RAND = 32,
  DTLS = 33,
  FLAC = 34,
  MGRK = 35,
  SSTY = 36,
  KERN = 37,
  FWID = 38,
  HWID = 39,
  HALT = 40,
  TWID = 41,
  QWID = 42,
  PWID = 43,
  JUST = 44,
  LFBD = 45,
  OPBD = 46,
  RTBD = 47,
  PALT = 48,
  PKNA = 49,
  LTRA = 50,
  LTRM = 51,
  RTLA = 52,
  RTLM = 53,
  ABRV = 54,
  ABVM = 55,
  ABVS = 56,
  VALT = 57,
  VHAL = 58,
  BLWF = 59,
  BLWM = 60,
  BLWS = 61,
  AKHN = 62,
  CJCT = 63,
  CFAR = 64,
  CPCT = 65,
  CURS = 66,
  DIST = 67,
  EXPT = 68,
  FALT = 69,
  FINA = 70,
  FIN2 = 71,
  FIN3 = 72,
  HALF = 73,
  HALN = 74,
  HKNA = 75,
  HNGL = 76,
  HOJO = 77,
  INIT = 78,
  ISOL = 79,
  JP78 = 80,
  JP83 = 81,
  JP90 = 82,
  JP04 = 83,
  LJMO = 84,
  LOCL = 85,
  MARK = 86,
  MEDI = 87,
  MED2 = 88,
  MKMK = 89,
  NLCK = 90,
  NUKT = 91,
  PREF = 92,
  PRES = 93,
  VPAL = 94,
  PSTF = 95,
  PSTS = 96,
  RKRF = 97,
  RPHF = 98,
  RUBY = 99,
  SMPL = 100,
  TJMO = 101,
  TNAM = 102,
  TRAD = 103,
  VATU = 104,
  VJMO = 105,
  VKNA = 106,
  VKRN = 107,
  VRTR = 108,
  VRT2 = 109,
  SS01 = 110,
  SS02 = 111,
  SS03 = 112,
  SS04 = 113,
  SS05 = 114,
  SS06 = 115,
  SS07 = 116,
  SS08 = 117,
  SS09 = 118,
  SS10 = 119,
  SS11 = 120,
  SS12 = 121,
  SS13 = 122,
  SS14 = 123,
  SS15 = 124,
  SS16 = 125,
  SS17 = 126,
  SS18 = 127,
  SS19 = 128,
  SS20 = 129,
  CV01 = 130,
  CV02 = 131,
  CV03 = 132,
  CV04 = 133,
  CV05 = 134,
  CV06 = 135,
  CV07 = 136,
  CV08 = 137,
  CV09 = 138,
  CV10 = 139,
  CV11 = 140,
  CV12 = 141,
  CV13 = 142,
  CV14 = 143,
  CV15 = 144,
  CV16 = 145,
  CV17 = 146,
  CV18 = 147,
  CV19 = 148,
  CV20 = 149,
  CV21 = 150,
  CV22 = 151,
  CV23 = 152,
  CV24 = 153,
  CV25 = 154,
  CV26 = 155,
  CV27 = 156,
  CV28 = 157,
  CV29 = 158,
  CV30 = 159,
  CV31 = 160,
  CV32 = 161,
  CV33 = 162,
  CV34 = 163,
  CV35 = 164,
  CV36 = 165,
  CV37 = 166,
  CV38 = 167,
  CV39 = 168,
  CV40 = 169,
  CV41 = 170,
  CV42 = 171,
  CV43 = 172,
  CV44 = 173,
  CV45 = 174,
  CV46 = 175,
  CV47 = 176,
  CV48 = 177,
  CV49 = 178,
  CV50 = 179,
  CV51 = 180,
  CV52 = 181,
  CV53 = 182,
  CV54 = 183,
  CV55 = 184,
  CV56 = 185,
  CV57 = 186,
  CV58 = 187,
  CV59 = 188,
  CV60 = 189,
  CV61 = 190,
  CV62 = 191,
  CV63 = 192,
  CV64 = 193,
  CV65 = 194,
  CV66 = 195,
  CV67 = 196,
  CV68 = 197,
  CV69 = 198,
  CV70 = 199,
  CV71 = 200,
  CV72 = 201,
  CV73 = 202,
  CV74 = 203,
  CV75 = 204,
  CV76 = 205,
  CV77 = 206,
  CV78 = 207,
  CV79 = 208,
  CV80 = 209,
  CV81 = 210,
  CV82 = 211,
  CV83 = 212,
  CV84 = 213,
  CV85 = 214,
  CV86 = 215,
  CV87 = 216,
  CV88 = 217,
  CV89 = 218,
  CV90 = 219,
  CV91 = 220,
  CV92 = 221,
  CV93 = 222,
  CV94 = 223,
  CV95 = 224,
  CV96 = 225,
  CV97 = 226,
  CV98 = 227,
  CV99 = 228,
};

enum class InstanceSwapPreferredValueType : uint32_t {
  COMPONENT = 0,
  STATE_GROUP = 1,
};

enum class ComponentPropType : uint32_t {
  BOOL = 0,
  TEXT = 1,
  COLOR = 2,
  INSTANCE_SWAP = 3,
};

enum class ComponentPropNodeField : uint32_t {
  VISIBLE = 0,
  TEXT_DATA = 1,
  OVERRIDDEN_SYMBOL_ID = 2,
  INHERIT_FILL_STYLE_ID = 3,
};

enum class FileSource : uint32_t {
  PixDoc = 0,
  Figma = 1,
  Sketch = 2,
  Axure = 3,
  XD = 4,
  MG = 5,
};

enum class FontIncorrect : uint32_t {
  None = 0,
  ImportDoc = 1,
};

enum class WorkState : uint32_t {
  ORIGIN = 0,
  DESIGN = 1,
  DEV = 2,
};

enum class WrapMode : uint32_t {
  NO_WRAP = 0,
  WRAP = 1,
};

enum class StackAlign : uint32_t {
  AUTO = 0,
  SPACE_BETWEEN = 1,
};

enum class Directionality : uint32_t {
  AUTO = 0,
  LTR = 1,
  RTL = 2,
};

enum class VariableDataType : uint32_t {
  BOOLEAN = 0,
  FLOAT = 1,
  STRING = 2,
  ALIAS = 3,
  COLOR = 4,
  EXPRESSION = 5,
  MAP = 6,
  SYMBOL_ID = 7,
  FONT_STYLE = 8,
  TEXT_DATA = 9,
  INVALID = 10,
  NODE_FIELD_ALIAS = 11,
};

enum class VariableResolvedDataType : uint32_t {
  BOOLEAN = 0,
  FLOAT = 1,
  STRING = 2,
  COLOR = 4,
  MAP = 5,
  SYMBOL_ID = 6,
  FONT_STYLE = 7,
  TEXT_DATA = 8,
};

enum class VariableField : uint32_t {
  MISSING = 0,
  CORNER_RADIUS = 1,
  PARAGRAPH_SPACING = 2,
  PARAGRAPH_INDENT = 3,
  STROKE_WEIGHT = 4,
  STACK_SPACING = 5,
  STACK_PADDING_LEFT = 6,
  STACK_PADDING_TOP = 7,
  STACK_PADDING_RIGHT = 8,
  STACK_PADDING_BOTTOM = 9,
  VISIBLE = 10,
  TEXT_DATA = 11,
  WIDTH = 12,
  HEIGHT = 13,
  RECTANGLE_TOP_LEFT_CORNER_RADIUS = 14,
  RECTANGLE_TOP_RIGHT_CORNER_RADIUS = 15,
  RECTANGLE_BOTTOM_LEFT_CORNER_RADIUS = 16,
  RECTANGLE_BOTTOM_RIGHT_CORNER_RADIUS = 17,
  BORDER_TOP_WEIGHT = 18,
  BORDER_BOTTOM_WEIGHT = 19,
  BORDER_LEFT_WEIGHT = 20,
  BORDER_RIGHT_WEIGHT = 21,
  VARIANT_PROPERTIES = 22,
  STACK_COUNTER_SPACING = 23,
  MIN_WIDTH = 24,
  MAX_WIDTH = 25,
  MIN_HEIGHT = 26,
  MAX_HEIGHT = 27,
  FONT_FAMILY = 28,
  FONT_STYLE = 29,
  FONT_VARIATIONS = 30,
  OPACITY = 31,
  FONT_SIZE = 32,
  LETTER_SPACING = 34,
  LINE_HEIGHT = 36,
};

enum class VariableScope : uint32_t {
  ALL_SCOPES = 0,
  TEXT_CONTENT = 1,
  CORNER_RADIUS = 2,
  WIDTH_HEIGHT = 3,
  GAP = 4,
  ALL_FILLS = 5,
  FRAME_FILL = 6,
  SHAPE_FILL = 7,
  TEXT_FILL = 8,
  STROKE = 9,
  STROKE_FLOAT = 10,
  EFFECT_FLOAT = 11,
  EFFECT_COLOR = 12,
  OPACITY = 13,
  FONT_STYLE = 14,
  FONT_FAMILY = 15,
  FONT_SIZE = 16,
  LINE_HEIGHT = 17,
  LETTER_SPACING = 18,
  PARAGRAPH_SPACING = 19,
  PARAGRAPH_INDENT = 20,
  FONT_VARIATIONS = 21,
};

enum class ExpressionFunction : uint32_t {
  ADDITION = 0,
  SUBTRACTION = 1,
  RESOLVE_VARIANT = 2,
  MULTIPLY = 3,
  DIVIDE = 4,
  EQUALS = 5,
  NOT_EQUAL = 6,
  LESS_THAN = 7,
  LESS_THAN_OR_EQUAL = 8,
  GREATER_THAN = 9,
  GREATER_THAN_OR_EQUAL = 10,
  AND = 11,
  OR = 12,
  NOT = 13,
  STRINGIFY = 14,
  TERNARY = 15,
  VAR_MODE_LOOKUP = 16,
  NEGATE = 17,
  IS_TRUTHY = 18,
};

enum class NodeFieldAliasType : uint32_t {
  MISSING = 0,
  COMPONENT_PROP_ASSIGNMENTS = 1,
};

enum class CodeSyntaxPlatform : uint32_t {
  WEB = 0,
  ANDROID = 1,
  iOS = 2,
};

enum class TransformModifierType : uint32_t {
  REPEAT = 0,
  SYMMETRY = 1,
  SKEW = 2,
};

enum class RepeatType : uint32_t {
  RADIAL = 0,
  LINEAR = 1,
};

enum class UnitType : uint32_t {
  PIXELS = 0,
  RELATIVE = 1,
};

enum class RepeatOrder : uint32_t {
  FORWARD = 0,
  REVERSE = 1,
};

enum class AnnotationPropertyType : uint32_t {
  FILL = 0,
  STROKE = 1,
  WIDTH = 2,
  HEIGHT = 3,
  MIN_WIDTH = 4,
  MIN_HEIGHT = 5,
  MAX_WIDTH = 6,
  MAX_HEIGHT = 7,
  STROKE_WIDTH = 8,
  CORNER_RADIUS = 9,
  EFFECT = 10,
  TEXT_STYLE = 11,
  TEXT_ALIGN_HORIZONTAL = 12,
  FONT_FAMILY = 13,
  FONT_SIZE = 14,
  FONT_WEIGHT = 15,
  LINE_HEIGHT = 16,
  LETTER_SPACING = 17,
  STACK_SPACING = 18,
  STACK_PADDING = 19,
  STACK_MODE = 20,
  STACK_ALIGNMENT = 21,
  OPACITY = 22,
  COMPONENT = 23,
  FONT_STYLE = 24,
  GRID_ROW_GAP = 25,
  GRID_COLUMN_GAP = 26,
  GRID_ROW_COUNT = 27,
  GRID_COLUMN_COUNT = 28,
  GRID_ROW_ANCHOR_INDEX = 29,
  GRID_COLUMN_ANCHOR_INDEX = 30,
  GRID_ROW_SPAN = 31,
  GRID_COLUMN_SPAN = 32,
};

enum class AnnotationCategoryPreset : uint32_t {
  NONE = 0,
  ACCESSIBILITY = 1,
  BEHAVIOR = 2,
  CONTENT = 3,
  DEVELOPMENT = 4,
  INTERACTION = 5,
};

enum class BlurOpType : uint32_t {
  NORMAL = 0,
  PROGRESSIVE = 1,
};

class Paint;
class PaintFilterMessage;
class ColorStop;
class ImageMessage;
class Path;
class GUIDPath;
class VectorData;
class ArcData;
class Effect;
class SymbolData;
class LayoutGrid;
class GridTrackSizing;
class ExportConstraint;
class ExportSettings;
class FontName;
class TextData;
class HyperlinkBox;
class FontMetaData;
class Decoration;
class Glyph;
class ParagraphStyle;
class Baseline;
class KeyTrigger;
class PrototypeDevice;
class PrototypeInteraction;
class ConditionalActions;
class VideoPlayback;
class VariableWidthPoint;
class PrototypeSelectedState;
class PrototypeStateChange;
class PrototypeAction;
class PrototypeEvent;
class ComponentPropDef;
class ComponentPropRef;
class ComponentPropValue;
class InstanceSwapPreferredValue;
class ComponentPropPreferredValues;
class ComponentPropAssignment;
class Blob;
class PixsoNode;
class ProdMode;
class BlockMarkerParams;
class ProdLayoutParam;
class ProdLayoutInterval;
class ProdAdjustSize;
class ProdMoving;
class ProdRotate;
class ProdTableCell;
class ProdTextStyle;
class ProdScoreBar;
class ProdDragBar;
class ProdScalingFactor;
class ProdTDCElementinfo;
class ProdTwoDimChart;
class Guide;
class OverlayBackgroundAppearance;
class Number;
class ParentIndex;
class UserInfo;
class Viewport;
class Mouse;
class Click;
class ScrollPosition;
class TriggeredOverlayData;
class Hyperlink;
class SharedStyleMasterData;
class SharedStyleReference;
class PixsoMsg;
class VectorStyleData;
class TextStyleData;
class PropValueData;
class SceneGraphQuery;
class PrototypeStartPoint;
class ConnectLineInfo;
class ObjSnapConnline;
class ConnlineTextInfo;
class VectorPaint;
class VectorStyle;
class PluginData;
class PluginRelaunchData;
class PlaceHolder;
class Spotlight;
class FileMeta;
class EditInfo;
class SymbolLink;
class DeveloperRelatedLink;
class FontVariation;
class PathTextInfo;
class GlyphPose;
class RadialRepeatData;
class TransformModifier;
class AssetID;
class VariableSetMode;
class VariableDataValues;
class VariableDataValuesEntry;
class VariableDataMap;
class VariableDataMapEntry;
class VariableData;
class VariableAnyValue;
class Expression;
class AssetRef;
class VariableFontStyle;
class VariableMap;
class ColorStopVar;
class VariableModeBySetMap;
class VariableModeBySetMapEntry;
class VariableMapValue;
class VariableIdOrVariableOverrideId;
class VariableOverrideId;
class PrototypeVariableTarget;
class TriggeredSetVariableActionData;
class TriggeredSetVariableModeActionData;
class NodeFieldAlias;
class CodeSyntaxMap;
class CodeSyntaxMapEntry;
class DeliverInfo;
class AnnotationProperty;
class AnnotationCategoryCustom;
class AnnotationCategory;
class AnnotationCategories;
class Annotation;
class GUID;
class Vector;
class Matrix;
class Matrix3f;
class Color;
class Rect;
class CommandNum;

class Paint {
public:
  Paint() { (void)_flags; }

  PaintType *type();
  const PaintType *type() const;
  void set_type(const PaintType &value);

  Color *color();
  const Color *color() const;
  void set_color(Color *value);

  float *opacity();
  const float *opacity() const;
  void set_opacity(const float &value);

  bool *visible();
  const bool *visible() const;
  void set_visible(const bool &value);

  BlendMode *blendMode();
  const BlendMode *blendMode() const;
  void set_blendMode(const BlendMode &value);

  kiwi::Array<ColorStop> *stops();
  const kiwi::Array<ColorStop> *stops() const;
  kiwi::Array<ColorStop> &set_stops(kiwi::MemoryPool &pool, uint32_t count);

  Matrix *transform();
  const Matrix *transform() const;
  void set_transform(Matrix *value);

  ImageMessage *image();
  const ImageMessage *image() const;
  void set_image(ImageMessage *value);

  ImageMessage *imageThumbnail();
  const ImageMessage *imageThumbnail() const;
  void set_imageThumbnail(ImageMessage *value);

  ImageMessage *animatedImage();
  const ImageMessage *animatedImage() const;
  void set_animatedImage(ImageMessage *value);

  int32_t *animationFrame();
  const int32_t *animationFrame() const;
  void set_animationFrame(const int32_t &value);

  ImageScaleMode *imageScaleMode();
  const ImageScaleMode *imageScaleMode() const;
  void set_imageScaleMode(const ImageScaleMode &value);

  float *rotation();
  const float *rotation() const;
  void set_rotation(const float &value);

  float *scale();
  const float *scale() const;
  void set_scale(const float &value);

  PaintFilterMessage *paintFilter();
  const PaintFilterMessage *paintFilter() const;
  void set_paintFilter(PaintFilterMessage *value);

  kiwi::Array<int32_t> *emojiCodePoints();
  const kiwi::Array<int32_t> *emojiCodePoints() const;
  kiwi::Array<int32_t> &set_emojiCodePoints(kiwi::MemoryPool &pool, uint32_t count);

  int32_t *originalImageWidth();
  const int32_t *originalImageWidth() const;
  void set_originalImageWidth(const int32_t &value);

  int32_t *originalImageHeight();
  const int32_t *originalImageHeight() const;
  void set_originalImageHeight(const int32_t &value);

  ImageMessage *video();
  const ImageMessage *video() const;
  void set_video(ImageMessage *value);

  VariableData *colorVar();
  const VariableData *colorVar() const;
  void set_colorVar(VariableData *value);

  kiwi::Array<ColorStopVar> *stopsVar();
  const kiwi::Array<ColorStopVar> *stopsVar() const;
  kiwi::Array<ColorStopVar> &set_stopsVar(kiwi::MemoryPool &pool, uint32_t count);

  Vector *patternSpacing();
  const Vector *patternSpacing() const;
  void set_patternSpacing(Vector *value);

  PatternTileType *patternTileType();
  const PatternTileType *patternTileType() const;
  void set_patternTileType(const PatternTileType &value);

  PatternAlignment *verticalAlignment();
  const PatternAlignment *verticalAlignment() const;
  void set_verticalAlignment(const PatternAlignment &value);

  PatternAlignment *horizontalAlignment();
  const PatternAlignment *horizontalAlignment() const;
  void set_horizontalAlignment(const PatternAlignment &value);

  GUID *sourceNodeId();
  const GUID *sourceNodeId() const;
  void set_sourceNodeId(GUID *value);

  float *spacing();
  const float *spacing() const;
  void set_spacing(const float &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  PaintType _data_type = {};
  Color *_data_color = {};
  BlendMode _data_blendMode = {};
  kiwi::Array<ColorStop> _data_stops = {};
  Matrix *_data_transform = {};
  ImageMessage *_data_image = {};
  ImageMessage *_data_imageThumbnail = {};
  ImageMessage *_data_animatedImage = {};
  ImageScaleMode _data_imageScaleMode = {};
  PaintFilterMessage *_data_paintFilter = {};
  kiwi::Array<int32_t> _data_emojiCodePoints = {};
  ImageMessage *_data_video = {};
  VariableData *_data_colorVar = {};
  kiwi::Array<ColorStopVar> _data_stopsVar = {};
  Vector *_data_patternSpacing = {};
  PatternTileType _data_patternTileType = {};
  PatternAlignment _data_verticalAlignment = {};
  PatternAlignment _data_horizontalAlignment = {};
  GUID *_data_sourceNodeId = {};
  float _data_opacity = {};
  int32_t _data_animationFrame = {};
  float _data_rotation = {};
  float _data_scale = {};
  int32_t _data_originalImageWidth = {};
  int32_t _data_originalImageHeight = {};
  float _data_spacing = {};
  bool _data_visible = {};
};

class PaintFilterMessage {
public:
  PaintFilterMessage() { (void)_flags; }

  float *tint();
  const float *tint() const;
  void set_tint(const float &value);

  float *shadows();
  const float *shadows() const;
  void set_shadows(const float &value);

  float *highlights();
  const float *highlights() const;
  void set_highlights(const float &value);

  float *exposure();
  const float *exposure() const;
  void set_exposure(const float &value);

  float *temperature();
  const float *temperature() const;
  void set_temperature(const float &value);

  float *vibrance();
  const float *vibrance() const;
  void set_vibrance(const float &value);

  float *contrast();
  const float *contrast() const;
  void set_contrast(const float &value);

  float *hue();
  const float *hue() const;
  void set_hue(const float &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  float _data_tint = {};
  float _data_shadows = {};
  float _data_highlights = {};
  float _data_exposure = {};
  float _data_temperature = {};
  float _data_vibrance = {};
  float _data_contrast = {};
  float _data_hue = {};
};

class ColorStop {
public:
  ColorStop() { (void)_flags; }

  Color *color();
  const Color *color() const;
  void set_color(Color *value);

  float *position();
  const float *position() const;
  void set_position(const float &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  Color *_data_color = {};
  float _data_position = {};
};

class ImageMessage {
public:
  ImageMessage() { (void)_flags; }

  kiwi::Array<uint8_t> *hash();
  const kiwi::Array<uint8_t> *hash() const;
  kiwi::Array<uint8_t> &set_hash(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::String *name();
  const kiwi::String *name() const;
  void set_name(const kiwi::String &value);

  int32_t *dataBlob();
  const int32_t *dataBlob() const;
  void set_dataBlob(const int32_t &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::Array<uint8_t> _data_hash = {};
  kiwi::String _data_name = {};
  int32_t _data_dataBlob = {};
};

class Path {
public:
  Path() { (void)_flags; }

  int32_t *blobIndex();
  const int32_t *blobIndex() const;
  void set_blobIndex(const int32_t &value);

  WindingRule *windingRule();
  const WindingRule *windingRule() const;
  void set_windingRule(const WindingRule &value);

  int32_t *pxTag();
  const int32_t *pxTag() const;
  void set_pxTag(const int32_t &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  WindingRule _data_windingRule = {};
  int32_t _data_blobIndex = {};
  int32_t _data_pxTag = {};
};

class GUIDPath {
public:
  GUIDPath() { (void)_flags; }

  kiwi::Array<GUID> *guids();
  const kiwi::Array<GUID> *guids() const;
  kiwi::Array<GUID> &set_guids(kiwi::MemoryPool &pool, uint32_t count);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::Array<GUID> _data_guids = {};
};

class VectorData {
public:
  VectorData() { (void)_flags; }

  int32_t *vectorNetworkBlob();
  const int32_t *vectorNetworkBlob() const;
  void set_vectorNetworkBlob(const int32_t &value);

  Vector *normalizedSize();
  const Vector *normalizedSize() const;
  void set_normalizedSize(Vector *value);

  kiwi::Array<VectorStyleData> *styleOverrideTable();
  const kiwi::Array<VectorStyleData> *styleOverrideTable() const;
  kiwi::Array<VectorStyleData> &set_styleOverrideTable(kiwi::MemoryPool &pool, uint32_t count);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  Vector *_data_normalizedSize = {};
  kiwi::Array<VectorStyleData> _data_styleOverrideTable = {};
  int32_t _data_vectorNetworkBlob = {};
};

class ArcData {
public:
  ArcData() { (void)_flags; }

  float *startingAngle();
  const float *startingAngle() const;
  void set_startingAngle(const float &value);

  float *endingAngle();
  const float *endingAngle() const;
  void set_endingAngle(const float &value);

  float *innerRadius();
  const float *innerRadius() const;
  void set_innerRadius(const float &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  float _data_startingAngle = {};
  float _data_endingAngle = {};
  float _data_innerRadius = {};
};

class Effect {
public:
  Effect() { (void)_flags; }

  EffectType *type();
  const EffectType *type() const;
  void set_type(const EffectType &value);

  Color *color();
  const Color *color() const;
  void set_color(Color *value);

  Vector *offset();
  const Vector *offset() const;
  void set_offset(Vector *value);

  float *radius();
  const float *radius() const;
  void set_radius(const float &value);

  bool *visible();
  const bool *visible() const;
  void set_visible(const bool &value);

  BlendMode *blendMode();
  const BlendMode *blendMode() const;
  void set_blendMode(const BlendMode &value);

  float *spread();
  const float *spread() const;
  void set_spread(const float &value);

  bool *showShadowBehindNode();
  const bool *showShadowBehindNode() const;
  void set_showShadowBehindNode(const bool &value);

  float *saturation();
  const float *saturation() const;
  void set_saturation(const float &value);

  VariableData *radiusVar();
  const VariableData *radiusVar() const;
  void set_radiusVar(VariableData *value);

  VariableData *colorVar();
  const VariableData *colorVar() const;
  void set_colorVar(VariableData *value);

  VariableData *spreadVar();
  const VariableData *spreadVar() const;
  void set_spreadVar(VariableData *value);

  VariableData *xVar();
  const VariableData *xVar() const;
  void set_xVar(VariableData *value);

  VariableData *yVar();
  const VariableData *yVar() const;
  void set_yVar(VariableData *value);

  float *refractionRadius();
  const float *refractionRadius() const;
  void set_refractionRadius(const float &value);

  float *specularAngle();
  const float *specularAngle() const;
  void set_specularAngle(const float &value);

  float *specularIntensity();
  const float *specularIntensity() const;
  void set_specularIntensity(const float &value);

  float *chromaticAberration();
  const float *chromaticAberration() const;
  void set_chromaticAberration(const float &value);

  float *refractionIntensity();
  const float *refractionIntensity() const;
  void set_refractionIntensity(const float &value);

  float *brightness();
  const float *brightness() const;
  void set_brightness(const float &value);

  bool *uniformLight();
  const bool *uniformLight() const;
  void set_uniformLight(const bool &value);

  BlurOpType *blurOpType();
  const BlurOpType *blurOpType() const;
  void set_blurOpType(const BlurOpType &value);

  float *startRadius();
  const float *startRadius() const;
  void set_startRadius(const float &value);

  Matrix *transform();
  const Matrix *transform() const;
  void set_transform(Matrix *value);

  float *bevelSize();
  const float *bevelSize() const;
  void set_bevelSize(const float &value);

  Vector *noiseSize();
  const Vector *noiseSize() const;
  void set_noiseSize(Vector *value);

  float *density();
  const float *density() const;
  void set_density(const float &value);

  NoiseType *noiseType();
  const NoiseType *noiseType() const;
  void set_noiseType(const NoiseType &value);

  float *opacity();
  const float *opacity() const;
  void set_opacity(const float &value);

  Color *secondaryColor();
  const Color *secondaryColor() const;
  void set_secondaryColor(Color *value);

  bool *clipToShape();
  const bool *clipToShape() const;
  void set_clipToShape(const bool &value);

  int32_t *seed();
  const int32_t *seed() const;
  void set_seed(const int32_t &value);

  bool *isImpact();
  const bool *isImpact() const;
  void set_isImpact(const bool &value);

  float *samplingRange();
  const float *samplingRange() const;
  void set_samplingRange(const float &value);

  float *splay();
  const float *splay() const;
  void set_splay(const float &value);

  bool *isConvex();
  const bool *isConvex() const;
  void set_isConvex(const bool &value);

  Vector *center();
  const Vector *center() const;
  void set_center(Vector *value);

  float *motionAngle();
  const float *motionAngle() const;
  void set_motionAngle(const float &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[2] = {};
  EffectType _data_type = {};
  Color *_data_color = {};
  Vector *_data_offset = {};
  BlendMode _data_blendMode = {};
  VariableData *_data_radiusVar = {};
  VariableData *_data_colorVar = {};
  VariableData *_data_spreadVar = {};
  VariableData *_data_xVar = {};
  VariableData *_data_yVar = {};
  BlurOpType _data_blurOpType = {};
  Matrix *_data_transform = {};
  Vector *_data_noiseSize = {};
  NoiseType _data_noiseType = {};
  Color *_data_secondaryColor = {};
  Vector *_data_center = {};
  float _data_radius = {};
  float _data_spread = {};
  float _data_saturation = {};
  float _data_refractionRadius = {};
  float _data_specularAngle = {};
  float _data_specularIntensity = {};
  float _data_chromaticAberration = {};
  float _data_refractionIntensity = {};
  float _data_brightness = {};
  float _data_startRadius = {};
  float _data_bevelSize = {};
  float _data_density = {};
  float _data_opacity = {};
  int32_t _data_seed = {};
  float _data_samplingRange = {};
  float _data_splay = {};
  float _data_motionAngle = {};
  bool _data_visible = {};
  bool _data_showShadowBehindNode = {};
  bool _data_uniformLight = {};
  bool _data_clipToShape = {};
  bool _data_isImpact = {};
  bool _data_isConvex = {};
};

class SymbolData {
public:
  SymbolData() { (void)_flags; }

  GUID *symbolID();
  const GUID *symbolID() const;
  void set_symbolID(GUID *value);

  kiwi::Array<PixsoNode> *symbolOverrides();
  const kiwi::Array<PixsoNode> *symbolOverrides() const;
  kiwi::Array<PixsoNode> &set_symbolOverrides(kiwi::MemoryPool &pool, uint32_t count);

  float *uniformScaleFactor();
  const float *uniformScaleFactor() const;
  void set_uniformScaleFactor(const float &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  GUID *_data_symbolID = {};
  kiwi::Array<PixsoNode> _data_symbolOverrides = {};
  float _data_uniformScaleFactor = {};
};

class LayoutGrid {
public:
  LayoutGrid() { (void)_flags; }

  LayoutGridType *type();
  const LayoutGridType *type() const;
  void set_type(const LayoutGridType &value);

  Axis *axis();
  const Axis *axis() const;
  void set_axis(const Axis &value);

  bool *visible();
  const bool *visible() const;
  void set_visible(const bool &value);

  int32_t *numSections();
  const int32_t *numSections() const;
  void set_numSections(const int32_t &value);

  float *offset();
  const float *offset() const;
  void set_offset(const float &value);

  float *sectionSize();
  const float *sectionSize() const;
  void set_sectionSize(const float &value);

  float *gutterSize();
  const float *gutterSize() const;
  void set_gutterSize(const float &value);

  Color *color();
  const Color *color() const;
  void set_color(Color *value);

  LayoutGridPattern *pattern();
  const LayoutGridPattern *pattern() const;
  void set_pattern(const LayoutGridPattern &value);

  VariableData *numSectionsVar();
  const VariableData *numSectionsVar() const;
  void set_numSectionsVar(VariableData *value);

  VariableData *offsetVar();
  const VariableData *offsetVar() const;
  void set_offsetVar(VariableData *value);

  VariableData *sectionSizeVar();
  const VariableData *sectionSizeVar() const;
  void set_sectionSizeVar(VariableData *value);

  VariableData *gutterSizeVar();
  const VariableData *gutterSizeVar() const;
  void set_gutterSizeVar(VariableData *value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  LayoutGridType _data_type = {};
  Axis _data_axis = {};
  Color *_data_color = {};
  LayoutGridPattern _data_pattern = {};
  VariableData *_data_numSectionsVar = {};
  VariableData *_data_offsetVar = {};
  VariableData *_data_sectionSizeVar = {};
  VariableData *_data_gutterSizeVar = {};
  int32_t _data_numSections = {};
  float _data_offset = {};
  float _data_sectionSize = {};
  float _data_gutterSize = {};
  bool _data_visible = {};
};

class GridTrackSizing {
public:
  GridTrackSizing() { (void)_flags; }

  GUID *id();
  const GUID *id() const;
  void set_id(GUID *value);

  GridTrackSizingType *type();
  const GridTrackSizingType *type() const;
  void set_type(const GridTrackSizingType &value);

  float *value();
  const float *value() const;
  void set_value(const float &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  GUID *_data_id = {};
  GridTrackSizingType _data_type = {};
  float _data_value = {};
};

class ExportConstraint {
public:
  ExportConstraint() { (void)_flags; }

  ExportConstraintType *type();
  const ExportConstraintType *type() const;
  void set_type(const ExportConstraintType &value);

  float *value();
  const float *value() const;
  void set_value(const float &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  ExportConstraintType _data_type = {};
  float _data_value = {};
};

class ExportSettings {
public:
  ExportSettings() { (void)_flags; }

  kiwi::String *suffix();
  const kiwi::String *suffix() const;
  void set_suffix(const kiwi::String &value);

  ImageType *imageType();
  const ImageType *imageType() const;
  void set_imageType(const ImageType &value);

  ExportConstraint *constraint();
  const ExportConstraint *constraint() const;
  void set_constraint(ExportConstraint *value);

  bool *svgDataName();
  const bool *svgDataName() const;
  void set_svgDataName(const bool &value);

  ExportSVGIDMode *svgIDMode();
  const ExportSVGIDMode *svgIDMode() const;
  void set_svgIDMode(const ExportSVGIDMode &value);

  bool *svgOutlineText();
  const bool *svgOutlineText() const;
  void set_svgOutlineText(const bool &value);

  bool *contentsOnly();
  const bool *contentsOnly() const;
  void set_contentsOnly(const bool &value);

  bool *svgForceStrokeMasks();
  const bool *svgForceStrokeMasks() const;
  void set_svgForceStrokeMasks(const bool &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::String _data_suffix = {};
  ImageType _data_imageType = {};
  ExportConstraint *_data_constraint = {};
  ExportSVGIDMode _data_svgIDMode = {};
  bool _data_svgDataName = {};
  bool _data_svgOutlineText = {};
  bool _data_contentsOnly = {};
  bool _data_svgForceStrokeMasks = {};
};

class FontName {
public:
  FontName() { (void)_flags; }

  kiwi::String *family();
  const kiwi::String *family() const;
  void set_family(const kiwi::String &value);

  kiwi::String *style();
  const kiwi::String *style() const;
  void set_style(const kiwi::String &value);

  kiwi::String *postscript();
  const kiwi::String *postscript() const;
  void set_postscript(const kiwi::String &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::String _data_family = {};
  kiwi::String _data_style = {};
  kiwi::String _data_postscript = {};
};

class TextData {
public:
  TextData() { (void)_flags; }

  kiwi::String *characters();
  const kiwi::String *characters() const;
  void set_characters(const kiwi::String &value);

  kiwi::Array<int32_t> *characterStyleIDs();
  const kiwi::Array<int32_t> *characterStyleIDs() const;
  kiwi::Array<int32_t> &set_characterStyleIDs(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<TextStyleData> *styleOverrideTable();
  const kiwi::Array<TextStyleData> *styleOverrideTable() const;
  kiwi::Array<TextStyleData> &set_styleOverrideTable(kiwi::MemoryPool &pool, uint32_t count);

  Vector *layoutSize();
  const Vector *layoutSize() const;
  void set_layoutSize(Vector *value);

  kiwi::Array<Baseline> *baselines();
  const kiwi::Array<Baseline> *baselines() const;
  kiwi::Array<Baseline> &set_baselines(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<Glyph> *glyphs();
  const kiwi::Array<Glyph> *glyphs() const;
  kiwi::Array<Glyph> &set_glyphs(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<Decoration> *decorations();
  const kiwi::Array<Decoration> *decorations() const;
  kiwi::Array<Decoration> &set_decorations(kiwi::MemoryPool &pool, uint32_t count);

  int32_t *layoutVersion();
  const int32_t *layoutVersion() const;
  void set_layoutVersion(const int32_t &value);

  kiwi::Array<FontMetaData> *fontMetaData();
  const kiwi::Array<FontMetaData> *fontMetaData() const;
  kiwi::Array<FontMetaData> &set_fontMetaData(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<FontName> *fallbackFonts();
  const kiwi::Array<FontName> *fallbackFonts() const;
  kiwi::Array<FontName> &set_fallbackFonts(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<HyperlinkBox> *hyperlinkBoxes();
  const kiwi::Array<HyperlinkBox> *hyperlinkBoxes() const;
  kiwi::Array<HyperlinkBox> &set_hyperlinkBoxes(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<ParagraphStyle> *paragraphStyle();
  const kiwi::Array<ParagraphStyle> *paragraphStyle() const;
  kiwi::Array<ParagraphStyle> &set_paragraphStyle(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<PlaceHolder> *placeHolders();
  const kiwi::Array<PlaceHolder> *placeHolders() const;
  kiwi::Array<PlaceHolder> &set_placeHolders(kiwi::MemoryPool &pool, uint32_t count);

  int32_t *truncationStartIndex();
  const int32_t *truncationStartIndex() const;
  void set_truncationStartIndex(const int32_t &value);

  float *truncatedHeight();
  const float *truncatedHeight() const;
  void set_truncatedHeight(const float &value);

  kiwi::Array<GlyphPose> *glyphPoses();
  const kiwi::Array<GlyphPose> *glyphPoses() const;
  kiwi::Array<GlyphPose> &set_glyphPoses(kiwi::MemoryPool &pool, uint32_t count);

  bool *isDirty();
  const bool *isDirty() const;
  void set_isDirty(const bool &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::String _data_characters = {};
  kiwi::Array<int32_t> _data_characterStyleIDs = {};
  kiwi::Array<TextStyleData> _data_styleOverrideTable = {};
  Vector *_data_layoutSize = {};
  kiwi::Array<Baseline> _data_baselines = {};
  kiwi::Array<Glyph> _data_glyphs = {};
  kiwi::Array<Decoration> _data_decorations = {};
  kiwi::Array<FontMetaData> _data_fontMetaData = {};
  kiwi::Array<FontName> _data_fallbackFonts = {};
  kiwi::Array<HyperlinkBox> _data_hyperlinkBoxes = {};
  kiwi::Array<ParagraphStyle> _data_paragraphStyle = {};
  kiwi::Array<PlaceHolder> _data_placeHolders = {};
  kiwi::Array<GlyphPose> _data_glyphPoses = {};
  int32_t _data_layoutVersion = {};
  int32_t _data_truncationStartIndex = {};
  float _data_truncatedHeight = {};
  bool _data_isDirty = {};
};

class HyperlinkBox {
public:
  HyperlinkBox() { (void)_flags; }

  Rect *bounds();
  const Rect *bounds() const;
  void set_bounds(Rect *value);

  kiwi::String *url();
  const kiwi::String *url() const;
  void set_url(const kiwi::String &value);

  GUID *guid();
  const GUID *guid() const;
  void set_guid(GUID *value);

  int32_t *hyperlinkID();
  const int32_t *hyperlinkID() const;
  void set_hyperlinkID(const int32_t &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  Rect *_data_bounds = {};
  kiwi::String _data_url = {};
  GUID *_data_guid = {};
  int32_t _data_hyperlinkID = {};
};

class FontMetaData {
public:
  FontMetaData() { (void)_flags; }

  FontName *key();
  const FontName *key() const;
  void set_key(FontName *value);

  float *fontLineHeight();
  const float *fontLineHeight() const;
  void set_fontLineHeight(const float &value);

  kiwi::Array<uint8_t> *fontDigest();
  const kiwi::Array<uint8_t> *fontDigest() const;
  kiwi::Array<uint8_t> &set_fontDigest(kiwi::MemoryPool &pool, uint32_t count);

  FontStyle *fontStyle();
  const FontStyle *fontStyle() const;
  void set_fontStyle(const FontStyle &value);

  int32_t *fontWeight();
  const int32_t *fontWeight() const;
  void set_fontWeight(const int32_t &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  FontName *_data_key = {};
  kiwi::Array<uint8_t> _data_fontDigest = {};
  FontStyle _data_fontStyle = {};
  float _data_fontLineHeight = {};
  int32_t _data_fontWeight = {};
};

class Decoration {
public:
  Decoration() { (void)_flags; }

  kiwi::Array<Rect> *rects();
  const kiwi::Array<Rect> *rects() const;
  kiwi::Array<Rect> &set_rects(kiwi::MemoryPool &pool, uint32_t count);

  int32_t *styleID();
  const int32_t *styleID() const;
  void set_styleID(const int32_t &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::Array<Rect> _data_rects = {};
  int32_t _data_styleID = {};
};

class Glyph {
public:
  Glyph() { (void)_flags; }

  int32_t *blobIndex();
  const int32_t *blobIndex() const;
  void set_blobIndex(const int32_t &value);

  Vector *position();
  const Vector *position() const;
  void set_position(Vector *value);

  int32_t *styleID();
  const int32_t *styleID() const;
  void set_styleID(const int32_t &value);

  float *fontSize();
  const float *fontSize() const;
  void set_fontSize(const float &value);

  int32_t *firstCharacter();
  const int32_t *firstCharacter() const;
  void set_firstCharacter(const int32_t &value);

  float *advance();
  const float *advance() const;
  void set_advance(const float &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  Vector *_data_position = {};
  int32_t _data_blobIndex = {};
  int32_t _data_styleID = {};
  float _data_fontSize = {};
  int32_t _data_firstCharacter = {};
  float _data_advance = {};
};

class ParagraphStyle {
public:
  ParagraphStyle() { (void)_flags; }

  TextListStyle *listType();
  const TextListStyle *listType() const;
  void set_listType(const TextListStyle &value);

  uint32_t *indentationLevel();
  const uint32_t *indentationLevel() const;
  void set_indentationLevel(const uint32_t &value);

  uint32_t *listStartOffset();
  const uint32_t *listStartOffset() const;
  void set_listStartOffset(const uint32_t &value);

  bool *isFirstLineOfList();
  const bool *isFirstLineOfList() const;
  void set_isFirstLineOfList(const bool &value);

  Directionality *sourceDirectionality();
  const Directionality *sourceDirectionality() const;
  void set_sourceDirectionality(const Directionality &value);

  Directionality *directionality();
  const Directionality *directionality() const;
  void set_directionality(const Directionality &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  TextListStyle _data_listType = {};
  Directionality _data_sourceDirectionality = {};
  Directionality _data_directionality = {};
  uint32_t _data_indentationLevel = {};
  uint32_t _data_listStartOffset = {};
  bool _data_isFirstLineOfList = {};
};

class Baseline {
public:
  Baseline() { (void)_flags; }

  Vector *position();
  const Vector *position() const;
  void set_position(Vector *value);

  float *width();
  const float *width() const;
  void set_width(const float &value);

  float *lineY();
  const float *lineY() const;
  void set_lineY(const float &value);

  float *lineHeight();
  const float *lineHeight() const;
  void set_lineHeight(const float &value);

  float *lineAscent();
  const float *lineAscent() const;
  void set_lineAscent(const float &value);

  int32_t *firstCharacter();
  const int32_t *firstCharacter() const;
  void set_firstCharacter(const int32_t &value);

  int32_t *endCharacter();
  const int32_t *endCharacter() const;
  void set_endCharacter(const int32_t &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  Vector *_data_position = {};
  float _data_width = {};
  float _data_lineY = {};
  float _data_lineHeight = {};
  float _data_lineAscent = {};
  int32_t _data_firstCharacter = {};
  int32_t _data_endCharacter = {};
};

class KeyTrigger {
public:
  KeyTrigger() { (void)_flags; }

  kiwi::Array<int32_t> *keyCodes();
  const kiwi::Array<int32_t> *keyCodes() const;
  kiwi::Array<int32_t> &set_keyCodes(kiwi::MemoryPool &pool, uint32_t count);

  TriggerDevice *triggerDevice();
  const TriggerDevice *triggerDevice() const;
  void set_triggerDevice(const TriggerDevice &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::Array<int32_t> _data_keyCodes = {};
  TriggerDevice _data_triggerDevice = {};
};

class PrototypeDevice {
public:
  PrototypeDevice() { (void)_flags; }

  PrototypeDeviceType *type();
  const PrototypeDeviceType *type() const;
  void set_type(const PrototypeDeviceType &value);

  Vector *size();
  const Vector *size() const;
  void set_size(Vector *value);

  kiwi::String *presetIdentifier();
  const kiwi::String *presetIdentifier() const;
  void set_presetIdentifier(const kiwi::String &value);

  DeviceRotation *rotation();
  const DeviceRotation *rotation() const;
  void set_rotation(const DeviceRotation &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  PrototypeDeviceType _data_type = {};
  Vector *_data_size = {};
  kiwi::String _data_presetIdentifier = {};
  DeviceRotation _data_rotation = {};
};

class PrototypeInteraction {
public:
  PrototypeInteraction() { (void)_flags; }

  GUID *id();
  const GUID *id() const;
  void set_id(GUID *value);

  PrototypeEvent *event();
  const PrototypeEvent *event() const;
  void set_event(PrototypeEvent *value);

  kiwi::Array<PrototypeAction> *actions();
  const kiwi::Array<PrototypeAction> *actions() const;
  kiwi::Array<PrototypeAction> &set_actions(kiwi::MemoryPool &pool, uint32_t count);

  bool *isDeleted();
  const bool *isDeleted() const;
  void set_isDeleted(const bool &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  GUID *_data_id = {};
  PrototypeEvent *_data_event = {};
  kiwi::Array<PrototypeAction> _data_actions = {};
  bool _data_isDeleted = {};
};

class ConditionalActions {
public:
  ConditionalActions() { (void)_flags; }

  kiwi::Array<PrototypeAction> *actions();
  const kiwi::Array<PrototypeAction> *actions() const;
  kiwi::Array<PrototypeAction> &set_actions(kiwi::MemoryPool &pool, uint32_t count);

  VariableData *condition();
  const VariableData *condition() const;
  void set_condition(VariableData *value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::Array<PrototypeAction> _data_actions = {};
  VariableData *_data_condition = {};
};

class VideoPlayback {
public:
  VideoPlayback() { (void)_flags; }

  bool *autoplay();
  const bool *autoplay() const;
  void set_autoplay(const bool &value);

  bool *mediaLoop();
  const bool *mediaLoop() const;
  void set_mediaLoop(const bool &value);

  bool *muted();
  const bool *muted() const;
  void set_muted(const bool &value);

  bool *showControls();
  const bool *showControls() const;
  void set_showControls(const bool &value);

  int32_t *startTimeMs();
  const int32_t *startTimeMs() const;
  void set_startTimeMs(const int32_t &value);

  int32_t *endTimeMs();
  const int32_t *endTimeMs() const;
  void set_endTimeMs(const int32_t &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  int32_t _data_startTimeMs = {};
  int32_t _data_endTimeMs = {};
  bool _data_autoplay = {};
  bool _data_mediaLoop = {};
  bool _data_muted = {};
  bool _data_showControls = {};
};

class VariableWidthPoint {
public:
  VariableWidthPoint() { (void)_flags; }

  float *position();
  const float *position() const;
  void set_position(const float &value);

  float *ascent();
  const float *ascent() const;
  void set_ascent(const float &value);

  float *descent();
  const float *descent() const;
  void set_descent(const float &value);

  int32_t *segmentId();
  const int32_t *segmentId() const;
  void set_segmentId(const int32_t &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  float _data_position = {};
  float _data_ascent = {};
  float _data_descent = {};
  int32_t _data_segmentId = {};
};

class PrototypeSelectedState {
public:
  PrototypeSelectedState() { (void)_flags; }

  GUID *nodeID();
  const GUID *nodeID() const;
  void set_nodeID(GUID *value);

  PrototypeSelectedStateType *stateType();
  const PrototypeSelectedStateType *stateType() const;
  void set_stateType(const PrototypeSelectedStateType &value);

  GUID *selectGUID();
  const GUID *selectGUID() const;
  void set_selectGUID(GUID *value);

  PrototypeStateAction *stateAction();
  const PrototypeStateAction *stateAction() const;
  void set_stateAction(const PrototypeStateAction &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  GUID *_data_nodeID = {};
  PrototypeSelectedStateType _data_stateType = {};
  GUID *_data_selectGUID = {};
  PrototypeStateAction _data_stateAction = {};
};

class PrototypeStateChange {
public:
  PrototypeStateChange() { (void)_flags; }

  PrototypeStateAction *targetStateAction();
  const PrototypeStateAction *targetStateAction() const;
  void set_targetStateAction(const PrototypeStateAction &value);

  kiwi::Array<PrototypeSelectedState> *selectedStates();
  const kiwi::Array<PrototypeSelectedState> *selectedStates() const;
  kiwi::Array<PrototypeSelectedState> &set_selectedStates(kiwi::MemoryPool &pool, uint32_t count);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  PrototypeStateAction _data_targetStateAction = {};
  kiwi::Array<PrototypeSelectedState> _data_selectedStates = {};
};

class PrototypeAction {
public:
  PrototypeAction() { (void)_flags; }

  GUID *transitionNodeID();
  const GUID *transitionNodeID() const;
  void set_transitionNodeID(GUID *value);

  TransitionType *transitionType();
  const TransitionType *transitionType() const;
  void set_transitionType(const TransitionType &value);

  float *transitionDuration();
  const float *transitionDuration() const;
  void set_transitionDuration(const float &value);

  EasingType *easingType();
  const EasingType *easingType() const;
  void set_easingType(const EasingType &value);

  bool *transitionShouldSmartAnimate();
  const bool *transitionShouldSmartAnimate() const;
  void set_transitionShouldSmartAnimate(const bool &value);

  ConnectionType *connectionType();
  const ConnectionType *connectionType() const;
  void set_connectionType(const ConnectionType &value);

  kiwi::String *connectionURL();
  const kiwi::String *connectionURL() const;
  void set_connectionURL(const kiwi::String &value);

  Vector *overlayRelativePosition();
  const Vector *overlayRelativePosition() const;
  void set_overlayRelativePosition(Vector *value);

  NavigationType *navigationType();
  const NavigationType *navigationType() const;
  void set_navigationType(const NavigationType &value);

  bool *transitionPreserveScroll();
  const bool *transitionPreserveScroll() const;
  void set_transitionPreserveScroll(const bool &value);

  kiwi::Array<float> *easingFunction();
  const kiwi::Array<float> *easingFunction() const;
  kiwi::Array<float> &set_easingFunction(kiwi::MemoryPool &pool, uint32_t count);

  OverflowType *overflowType();
  const OverflowType *overflowType() const;
  void set_overflowType(const OverflowType &value);

  Vector *extraScrollOffset();
  const Vector *extraScrollOffset() const;
  void set_extraScrollOffset(Vector *value);

  PrototypeShowHide *showHide();
  const PrototypeShowHide *showHide() const;
  void set_showHide(const PrototypeShowHide &value);

  ProdAdjustSize *adjustSize();
  const ProdAdjustSize *adjustSize() const;
  void set_adjustSize(ProdAdjustSize *value);

  ProdMoving *moving();
  const ProdMoving *moving() const;
  void set_moving(ProdMoving *value);

  kiwi::String *dynamicPanelStateStr();
  const kiwi::String *dynamicPanelStateStr() const;
  void set_dynamicPanelStateStr(const kiwi::String &value);

  ProdRotate *rotation();
  const ProdRotate *rotation() const;
  void set_rotation(ProdRotate *value);

  float *waitingTime();
  const float *waitingTime() const;
  void set_waitingTime(const float &value);

  bool *isLooping();
  const bool *isLooping() const;
  void set_isLooping(const bool &value);

  float *loopingDuration();
  const float *loopingDuration() const;
  void set_loopingDuration(const float &value);

  PrototypeVariableTarget *targetVariable();
  const PrototypeVariableTarget *targetVariable() const;
  void set_targetVariable(PrototypeVariableTarget *value);

  VariableData *targetVariableData();
  const VariableData *targetVariableData() const;
  void set_targetVariableData(VariableData *value);

  AssetID *targetVariableSetID();
  const AssetID *targetVariableSetID() const;
  void set_targetVariableSetID(AssetID *value);

  GUID *targetVariableModeID();
  const GUID *targetVariableModeID() const;
  void set_targetVariableModeID(GUID *value);

  kiwi::Array<ConditionalActions> *conditionalActions();
  const kiwi::Array<ConditionalActions> *conditionalActions() const;
  kiwi::Array<ConditionalActions> &set_conditionalActions(kiwi::MemoryPool &pool, uint32_t count);

  bool *transitionResetVideoPosition();
  const bool *transitionResetVideoPosition() const;
  void set_transitionResetVideoPosition(const bool &value);

  bool *transitionResetScrollPosition();
  const bool *transitionResetScrollPosition() const;
  void set_transitionResetScrollPosition(const bool &value);

  bool *transitionResetInteractiveComponents();
  const bool *transitionResetInteractiveComponents() const;
  void set_transitionResetInteractiveComponents(const bool &value);

  bool *DisplayTopLevel();
  const bool *DisplayTopLevel() const;
  void set_DisplayTopLevel(const bool &value);

  float *mediaSkipToTime();
  const float *mediaSkipToTime() const;
  void set_mediaSkipToTime(const float &value);

  float *mediaSkipByAmount();
  const float *mediaSkipByAmount() const;
  void set_mediaSkipByAmount(const float &value);

  MediaAction *mediaAction();
  const MediaAction *mediaAction() const;
  void set_mediaAction(const MediaAction &value);

  PrototypeStateChange *stateChange();
  const PrototypeStateChange *stateChange() const;
  void set_stateChange(PrototypeStateChange *value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[2] = {};
  GUID *_data_transitionNodeID = {};
  TransitionType _data_transitionType = {};
  EasingType _data_easingType = {};
  ConnectionType _data_connectionType = {};
  kiwi::String _data_connectionURL = {};
  Vector *_data_overlayRelativePosition = {};
  NavigationType _data_navigationType = {};
  kiwi::Array<float> _data_easingFunction = {};
  OverflowType _data_overflowType = {};
  Vector *_data_extraScrollOffset = {};
  PrototypeShowHide _data_showHide = {};
  ProdAdjustSize *_data_adjustSize = {};
  ProdMoving *_data_moving = {};
  kiwi::String _data_dynamicPanelStateStr = {};
  ProdRotate *_data_rotation = {};
  PrototypeVariableTarget *_data_targetVariable = {};
  VariableData *_data_targetVariableData = {};
  AssetID *_data_targetVariableSetID = {};
  GUID *_data_targetVariableModeID = {};
  kiwi::Array<ConditionalActions> _data_conditionalActions = {};
  MediaAction _data_mediaAction = {};
  PrototypeStateChange *_data_stateChange = {};
  float _data_transitionDuration = {};
  float _data_waitingTime = {};
  float _data_loopingDuration = {};
  float _data_mediaSkipToTime = {};
  float _data_mediaSkipByAmount = {};
  bool _data_transitionShouldSmartAnimate = {};
  bool _data_transitionPreserveScroll = {};
  bool _data_isLooping = {};
  bool _data_transitionResetVideoPosition = {};
  bool _data_transitionResetScrollPosition = {};
  bool _data_transitionResetInteractiveComponents = {};
  bool _data_DisplayTopLevel = {};
};

class PrototypeEvent {
public:
  PrototypeEvent() { (void)_flags; }

  InteractionType *interactionType();
  const InteractionType *interactionType() const;
  void set_interactionType(const InteractionType &value);

  bool *interactionMaintained();
  const bool *interactionMaintained() const;
  void set_interactionMaintained(const bool &value);

  float *interactionDuration();
  const float *interactionDuration() const;
  void set_interactionDuration(const float &value);

  KeyTrigger *keyTrigger();
  const KeyTrigger *keyTrigger() const;
  void set_keyTrigger(KeyTrigger *value);

  kiwi::String *voiceEventPhrase();
  const kiwi::String *voiceEventPhrase() const;
  void set_voiceEventPhrase(const kiwi::String &value);

  float *transitionTimeout();
  const float *transitionTimeout() const;
  void set_transitionTimeout(const float &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  InteractionType _data_interactionType = {};
  KeyTrigger *_data_keyTrigger = {};
  kiwi::String _data_voiceEventPhrase = {};
  float _data_interactionDuration = {};
  float _data_transitionTimeout = {};
  bool _data_interactionMaintained = {};
};

class ComponentPropDef {
public:
  ComponentPropDef() { (void)_flags; }

  GUID *id();
  const GUID *id() const;
  void set_id(GUID *value);

  kiwi::String *name();
  const kiwi::String *name() const;
  void set_name(const kiwi::String &value);

  ComponentPropValue *initialValue();
  const ComponentPropValue *initialValue() const;
  void set_initialValue(ComponentPropValue *value);

  kiwi::String *sortPosition();
  const kiwi::String *sortPosition() const;
  void set_sortPosition(const kiwi::String &value);

  GUID *parentPropDefId();
  const GUID *parentPropDefId() const;
  void set_parentPropDefId(GUID *value);

  ComponentPropType *type();
  const ComponentPropType *type() const;
  void set_type(const ComponentPropType &value);

  ComponentPropPreferredValues *preferredValues();
  const ComponentPropPreferredValues *preferredValues() const;
  void set_preferredValues(ComponentPropPreferredValues *value);

  bool *isDeleted();
  const bool *isDeleted() const;
  void set_isDeleted(const bool &value);

  VariableData *varValue();
  const VariableData *varValue() const;
  void set_varValue(VariableData *value);

  kiwi::String *aliasName();
  const kiwi::String *aliasName() const;
  void set_aliasName(const kiwi::String &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  GUID *_data_id = {};
  kiwi::String _data_name = {};
  ComponentPropValue *_data_initialValue = {};
  kiwi::String _data_sortPosition = {};
  GUID *_data_parentPropDefId = {};
  ComponentPropType _data_type = {};
  ComponentPropPreferredValues *_data_preferredValues = {};
  VariableData *_data_varValue = {};
  kiwi::String _data_aliasName = {};
  bool _data_isDeleted = {};
};

class ComponentPropRef {
public:
  ComponentPropRef() { (void)_flags; }

  GUID *defID();
  const GUID *defID() const;
  void set_defID(GUID *value);

  kiwi::String *zombieFallbackName();
  const kiwi::String *zombieFallbackName() const;
  void set_zombieFallbackName(const kiwi::String &value);

  ComponentPropNodeField *componentPropNodeField();
  const ComponentPropNodeField *componentPropNodeField() const;
  void set_componentPropNodeField(const ComponentPropNodeField &value);

  uint32_t *nodeField();
  const uint32_t *nodeField() const;
  void set_nodeField(const uint32_t &value);

  bool *isDeleted();
  const bool *isDeleted() const;
  void set_isDeleted(const bool &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  GUID *_data_defID = {};
  kiwi::String _data_zombieFallbackName = {};
  ComponentPropNodeField _data_componentPropNodeField = {};
  uint32_t _data_nodeField = {};
  bool _data_isDeleted = {};
};

class ComponentPropValue {
public:
  ComponentPropValue() { (void)_flags; }

  TextData *textValue();
  const TextData *textValue() const;
  void set_textValue(TextData *value);

  GUID *guidValue();
  const GUID *guidValue() const;
  void set_guidValue(GUID *value);

  bool *boolValue();
  const bool *boolValue() const;
  void set_boolValue(const bool &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  TextData *_data_textValue = {};
  GUID *_data_guidValue = {};
  bool _data_boolValue = {};
};

class InstanceSwapPreferredValue {
public:
  InstanceSwapPreferredValue() { (void)_flags; }

  InstanceSwapPreferredValueType *type();
  const InstanceSwapPreferredValueType *type() const;
  void set_type(const InstanceSwapPreferredValueType &value);

  kiwi::String *key();
  const kiwi::String *key() const;
  void set_key(const kiwi::String &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  InstanceSwapPreferredValueType _data_type = {};
  kiwi::String _data_key = {};
};

class ComponentPropPreferredValues {
public:
  ComponentPropPreferredValues() { (void)_flags; }

  kiwi::Array<kiwi::String> *stringValues();
  const kiwi::Array<kiwi::String> *stringValues() const;
  kiwi::Array<kiwi::String> &set_stringValues(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<InstanceSwapPreferredValue> *instanceSwapValues();
  const kiwi::Array<InstanceSwapPreferredValue> *instanceSwapValues() const;
  kiwi::Array<InstanceSwapPreferredValue> &set_instanceSwapValues(kiwi::MemoryPool &pool, uint32_t count);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::Array<kiwi::String> _data_stringValues = {};
  kiwi::Array<InstanceSwapPreferredValue> _data_instanceSwapValues = {};
};

class ComponentPropAssignment {
public:
  ComponentPropAssignment() { (void)_flags; }

  GUID *defID();
  const GUID *defID() const;
  void set_defID(GUID *value);

  ComponentPropValue *value();
  const ComponentPropValue *value() const;
  void set_value(ComponentPropValue *value);

  VariableData *varValue();
  const VariableData *varValue() const;
  void set_varValue(VariableData *value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  GUID *_data_defID = {};
  ComponentPropValue *_data_value = {};
  VariableData *_data_varValue = {};
};

class Blob {
public:
  Blob() { (void)_flags; }

  kiwi::Array<uint8_t> *bytes();
  const kiwi::Array<uint8_t> *bytes() const;
  kiwi::Array<uint8_t> &set_bytes(kiwi::MemoryPool &pool, uint32_t count);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::Array<uint8_t> _data_bytes = {};
};

class PixsoNode {
public:
  PixsoNode() { (void)_flags; }

  GUID *guid();
  const GUID *guid() const;
  void set_guid(GUID *value);

  GUIDPath *guidPath();
  const GUIDPath *guidPath() const;
  void set_guidPath(GUIDPath *value);

  ParentIndex *parentIndex();
  const ParentIndex *parentIndex() const;
  void set_parentIndex(ParentIndex *value);

  NodePhase *phase();
  const NodePhase *phase() const;
  void set_phase(const NodePhase &value);

  Matrix *transform();
  const Matrix *transform() const;
  void set_transform(Matrix *value);

  NodeType *type();
  const NodeType *type() const;
  void set_type(const NodeType &value);

  kiwi::String *name();
  const kiwi::String *name() const;
  void set_name(const kiwi::String &value);

  VectorData *vectorData();
  const VectorData *vectorData() const;
  void set_vectorData(VectorData *value);

  kiwi::String *version();
  const kiwi::String *version() const;
  void set_version(const kiwi::String &value);

  bool *visible();
  const bool *visible() const;
  void set_visible(const bool &value);

  int32_t *count();
  const int32_t *count() const;
  void set_count(const int32_t &value);

  Vector *size();
  const Vector *size() const;
  void set_size(Vector *value);

  BooleanOperation *booleanOperation();
  const BooleanOperation *booleanOperation() const;
  void set_booleanOperation(const BooleanOperation &value);

  ArcData *arcData();
  const ArcData *arcData() const;
  void set_arcData(ArcData *value);

  BlendMode *blendMode();
  const BlendMode *blendMode() const;
  void set_blendMode(const BlendMode &value);

  float *cornerRadius();
  const float *cornerRadius() const;
  void set_cornerRadius(const float &value);

  float *cornerSmoothing();
  const float *cornerSmoothing() const;
  void set_cornerSmoothing(const float &value);

  float *opacity();
  const float *opacity() const;
  void set_opacity(const float &value);

  bool *locked();
  const bool *locked() const;
  void set_locked(const bool &value);

  kiwi::Array<Effect> *effects();
  const kiwi::Array<Effect> *effects() const;
  kiwi::Array<Effect> &set_effects(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<Path> *fillGeometry();
  const kiwi::Array<Path> *fillGeometry() const;
  kiwi::Array<Path> &set_fillGeometry(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<Paint> *fillPaints();
  const kiwi::Array<Paint> *fillPaints() const;
  kiwi::Array<Paint> &set_fillPaints(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<float> *dashPattern();
  const kiwi::Array<float> *dashPattern() const;
  kiwi::Array<float> &set_dashPattern(kiwi::MemoryPool &pool, uint32_t count);

  StackCounterAlign *stackCounterAlign();
  const StackCounterAlign *stackCounterAlign() const;
  void set_stackCounterAlign(const StackCounterAlign &value);

  StackSize *stackCounterSizing();
  const StackSize *stackCounterSizing() const;
  void set_stackCounterSizing(const StackSize &value);

  StackSize *stackHeight();
  const StackSize *stackHeight() const;
  void set_stackHeight(const StackSize &value);

  float *stackHorizontalPadding();
  const float *stackHorizontalPadding() const;
  void set_stackHorizontalPadding(const float &value);

  StackJustify *stackJustify();
  const StackJustify *stackJustify() const;
  void set_stackJustify(const StackJustify &value);

  StackMode *stackMode();
  const StackMode *stackMode() const;
  void set_stackMode(const StackMode &value);

  float *stackPadding();
  const float *stackPadding() const;
  void set_stackPadding(const float &value);

  float *stackSpacing();
  const float *stackSpacing() const;
  void set_stackSpacing(const float &value);

  float *stackVerticalPadding();
  const float *stackVerticalPadding() const;
  void set_stackVerticalPadding(const float &value);

  StackSize *stackWidth();
  const StackSize *stackWidth() const;
  void set_stackWidth(const StackSize &value);

  StrokeAlign *strokeAlign();
  const StrokeAlign *strokeAlign() const;
  void set_strokeAlign(const StrokeAlign &value);

  StrokeCap *strokeCap();
  const StrokeCap *strokeCap() const;
  void set_strokeCap(const StrokeCap &value);

  kiwi::Array<Path> *strokeGeometry();
  const kiwi::Array<Path> *strokeGeometry() const;
  kiwi::Array<Path> &set_strokeGeometry(kiwi::MemoryPool &pool, uint32_t count);

  StrokeJoin *strokeJoin();
  const StrokeJoin *strokeJoin() const;
  void set_strokeJoin(const StrokeJoin &value);

  kiwi::Array<Paint> *strokePaints();
  const kiwi::Array<Paint> *strokePaints() const;
  kiwi::Array<Paint> &set_strokePaints(kiwi::MemoryPool &pool, uint32_t count);

  float *strokeWeight();
  const float *strokeWeight() const;
  void set_strokeWeight(const float &value);

  kiwi::String *styleDescription();
  const kiwi::String *styleDescription() const;
  void set_styleDescription(const kiwi::String &value);

  int32_t *styleID();
  const int32_t *styleID() const;
  void set_styleID(const int32_t &value);

  StyleType *styleType();
  const StyleType *styleType() const;
  void set_styleType(const StyleType &value);

  SymbolData *symbolData();
  const SymbolData *symbolData() const;
  void set_symbolData(SymbolData *value);

  kiwi::String *symbolDescription();
  const kiwi::String *symbolDescription() const;
  void set_symbolDescription(const kiwi::String &value);

  kiwi::Array<LayoutGrid> *layoutGrids();
  const kiwi::Array<LayoutGrid> *layoutGrids() const;
  kiwi::Array<LayoutGrid> &set_layoutGrids(kiwi::MemoryPool &pool, uint32_t count);

  bool *mask();
  const bool *mask() const;
  void set_mask(const bool &value);

  bool *maskIsOutline();
  const bool *maskIsOutline() const;
  void set_maskIsOutline(const bool &value);

  float *starInnerScale();
  const float *starInnerScale() const;
  void set_starInnerScale(const float &value);

  float *miterLimit();
  const float *miterLimit() const;
  void set_miterLimit(const float &value);

  Color *backgroundColor();
  const Color *backgroundColor() const;
  void set_backgroundColor(Color *value);

  bool *backgroundEnabled();
  const bool *backgroundEnabled() const;
  void set_backgroundEnabled(const bool &value);

  float *backgroundOpacity();
  const float *backgroundOpacity() const;
  void set_backgroundOpacity(const float &value);

  kiwi::Array<Paint> *backgroundPaints();
  const kiwi::Array<Paint> *backgroundPaints() const;
  kiwi::Array<Paint> &set_backgroundPaints(kiwi::MemoryPool &pool, uint32_t count);

  bool *exportBackgroundDisabled();
  const bool *exportBackgroundDisabled() const;
  void set_exportBackgroundDisabled(const bool &value);

  bool *exportContentsOnly();
  const bool *exportContentsOnly() const;
  void set_exportContentsOnly(const bool &value);

  kiwi::Array<ExportSettings> *exportSettings();
  const kiwi::Array<ExportSettings> *exportSettings() const;
  kiwi::Array<ExportSettings> &set_exportSettings(kiwi::MemoryPool &pool, uint32_t count);

  bool *exportTextAsSVGText();
  const bool *exportTextAsSVGText() const;
  void set_exportTextAsSVGText(const bool &value);

  FontName *fontName();
  const FontName *fontName() const;
  void set_fontName(FontName *value);

  float *fontSize();
  const float *fontSize() const;
  void set_fontSize(const float &value);

  kiwi::String *fontVersion();
  const kiwi::String *fontVersion() const;
  void set_fontVersion(const kiwi::String &value);

  float *paragraphIndent();
  const float *paragraphIndent() const;
  void set_paragraphIndent(const float &value);

  float *paragraphSpacing();
  const float *paragraphSpacing() const;
  void set_paragraphSpacing(const float &value);

  TextAlignHorizontal *textAlignHorizontal();
  const TextAlignHorizontal *textAlignHorizontal() const;
  void set_textAlignHorizontal(const TextAlignHorizontal &value);

  TextAlignVertical *textAlignVertical();
  const TextAlignVertical *textAlignVertical() const;
  void set_textAlignVertical(const TextAlignVertical &value);

  TextAutoResize *textAutoResize();
  const TextAutoResize *textAutoResize() const;
  void set_textAutoResize(const TextAutoResize &value);

  TextCase *textCase();
  const TextCase *textCase() const;
  void set_textCase(const TextCase &value);

  TextData *textData();
  const TextData *textData() const;
  void set_textData(TextData *value);

  TextDecoration *textDecoration();
  const TextDecoration *textDecoration() const;
  void set_textDecoration(const TextDecoration &value);

  float *textTracking();
  const float *textTracking() const;
  void set_textTracking(const float &value);

  int32_t *textUserLayoutVersion();
  const int32_t *textUserLayoutVersion() const;
  void set_textUserLayoutVersion(const int32_t &value);

  Number *letterSpacing();
  const Number *letterSpacing() const;
  void set_letterSpacing(Number *value);

  Number *lineHeight();
  const Number *lineHeight() const;
  void set_lineHeight(Number *value);

  ConstraintType *horizontalConstraint();
  const ConstraintType *horizontalConstraint() const;
  void set_horizontalConstraint(const ConstraintType &value);

  ConstraintType *verticalConstraint();
  const ConstraintType *verticalConstraint() const;
  void set_verticalConstraint(const ConstraintType &value);

  kiwi::Array<PixsoNode> *derivedSymbolData();
  const kiwi::Array<PixsoNode> *derivedSymbolData() const;
  kiwi::Array<PixsoNode> &set_derivedSymbolData(kiwi::MemoryPool &pool, uint32_t count);

  int32_t *derivedSymbolDataLayoutVersion();
  const int32_t *derivedSymbolDataLayoutVersion() const;
  void set_derivedSymbolDataLayoutVersion(const int32_t &value);

  kiwi::String *componentKey();
  const kiwi::String *componentKey() const;
  void set_componentKey(const kiwi::String &value);

  GUID *inheritEffectStyleID();
  const GUID *inheritEffectStyleID() const;
  void set_inheritEffectStyleID(GUID *value);

  GUID *inheritExportStyleID();
  const GUID *inheritExportStyleID() const;
  void set_inheritExportStyleID(GUID *value);

  GUID *inheritFillStyleID();
  const GUID *inheritFillStyleID() const;
  void set_inheritFillStyleID(GUID *value);

  GUID *inheritFillStyleIDForBackground();
  const GUID *inheritFillStyleIDForBackground() const;
  void set_inheritFillStyleIDForBackground(GUID *value);

  GUID *inheritFillStyleIDForStroke();
  const GUID *inheritFillStyleIDForStroke() const;
  void set_inheritFillStyleIDForStroke(GUID *value);

  GUID *inheritGridStyleID();
  const GUID *inheritGridStyleID() const;
  void set_inheritGridStyleID(GUID *value);

  GUID *inheritStrokeStyleID();
  const GUID *inheritStrokeStyleID() const;
  void set_inheritStrokeStyleID(GUID *value);

  GUID *inheritTextStyleID();
  const GUID *inheritTextStyleID() const;
  void set_inheritTextStyleID(GUID *value);

  float *interactionDuration();
  const float *interactionDuration() const;
  void set_interactionDuration(const float &value);

  bool *interactionMaintained();
  const bool *interactionMaintained() const;
  void set_interactionMaintained(const bool &value);

  GUID *overriddenSymbolID();
  const GUID *overriddenSymbolID() const;
  void set_overriddenSymbolID(GUID *value);

  GUID *overrideKey();
  const GUID *overrideKey() const;
  void set_overrideKey(GUID *value);

  KeyTrigger *keyTrigger();
  const KeyTrigger *keyTrigger() const;
  void set_keyTrigger(KeyTrigger *value);

  NavigationType *navigationType();
  const NavigationType *navigationType() const;
  void set_navigationType(const NavigationType &value);

  InteractionType *interactionType();
  const InteractionType *interactionType() const;
  void set_interactionType(const InteractionType &value);

  ConnectionType *connectionType();
  const ConnectionType *connectionType() const;
  void set_connectionType(const ConnectionType &value);

  kiwi::String *connectionURL();
  const kiwi::String *connectionURL() const;
  void set_connectionURL(const kiwi::String &value);

  EasingType *easingType();
  const EasingType *easingType() const;
  void set_easingType(const EasingType &value);

  bool *proportionsConstrained();
  const bool *proportionsConstrained() const;
  void set_proportionsConstrained(const bool &value);

  Color *prototypeBackgroundColor();
  const Color *prototypeBackgroundColor() const;
  void set_prototypeBackgroundColor(Color *value);

  PrototypeDevice *prototypeDevice();
  const PrototypeDevice *prototypeDevice() const;
  void set_prototypeDevice(PrototypeDevice *value);

  kiwi::Array<PrototypeInteraction> *prototypeInteractions();
  const kiwi::Array<PrototypeInteraction> *prototypeInteractions() const;
  kiwi::Array<PrototypeInteraction> &set_prototypeInteractions(kiwi::MemoryPool &pool, uint32_t count);

  GUID *prototypeStartNodeID();
  const GUID *prototypeStartNodeID() const;
  void set_prototypeStartNodeID(GUID *value);

  OverlayBackgroundAppearance *overlayBackgroundAppearance();
  const OverlayBackgroundAppearance *overlayBackgroundAppearance() const;
  void set_overlayBackgroundAppearance(OverlayBackgroundAppearance *value);

  OverlayBackgroundInteraction *overlayBackgroundInteraction();
  const OverlayBackgroundInteraction *overlayBackgroundInteraction() const;
  void set_overlayBackgroundInteraction(const OverlayBackgroundInteraction &value);

  OverlayPositionType *overlayPositionType();
  const OverlayPositionType *overlayPositionType() const;
  void set_overlayPositionType(const OverlayPositionType &value);

  Vector *overlayRelativePosition();
  const Vector *overlayRelativePosition() const;
  void set_overlayRelativePosition(Vector *value);

  float *transitionDuration();
  const float *transitionDuration() const;
  void set_transitionDuration(const float &value);

  GUID *transitionNodeID();
  const GUID *transitionNodeID() const;
  void set_transitionNodeID(GUID *value);

  bool *transitionPreserveScroll();
  const bool *transitionPreserveScroll() const;
  void set_transitionPreserveScroll(const bool &value);

  bool *transitionShouldSmartAnimate();
  const bool *transitionShouldSmartAnimate() const;
  void set_transitionShouldSmartAnimate(const bool &value);

  float *transitionTimeout();
  const float *transitionTimeout() const;
  void set_transitionTimeout(const float &value);

  TransitionType *transitionType();
  const TransitionType *transitionType() const;
  void set_transitionType(const TransitionType &value);

  ScrollBehavior *scrollBehavior();
  const ScrollBehavior *scrollBehavior() const;
  void set_scrollBehavior(const ScrollBehavior &value);

  ScrollDirection *scrollDirection();
  const ScrollDirection *scrollDirection() const;
  void set_scrollDirection(const ScrollDirection &value);

  float *rectangleBottomLeftCornerRadius();
  const float *rectangleBottomLeftCornerRadius() const;
  void set_rectangleBottomLeftCornerRadius(const float &value);

  float *rectangleBottomRightCornerRadius();
  const float *rectangleBottomRightCornerRadius() const;
  void set_rectangleBottomRightCornerRadius(const float &value);

  bool *rectangleCornerRadiiIndependent();
  const bool *rectangleCornerRadiiIndependent() const;
  void set_rectangleCornerRadiiIndependent(const bool &value);

  bool *rectangleCornerToolIndependent();
  const bool *rectangleCornerToolIndependent() const;
  void set_rectangleCornerToolIndependent(const bool &value);

  float *rectangleTopLeftCornerRadius();
  const float *rectangleTopLeftCornerRadius() const;
  void set_rectangleTopLeftCornerRadius(const float &value);

  float *rectangleTopRightCornerRadius();
  const float *rectangleTopRightCornerRadius() const;
  void set_rectangleTopRightCornerRadius(const float &value);

  bool *frameMaskDisabled();
  const bool *frameMaskDisabled() const;
  void set_frameMaskDisabled(const bool &value);

  Hyperlink *hyperlink();
  const Hyperlink *hyperlink() const;
  void set_hyperlink(Hyperlink *value);

  SharedStyleMasterData *sharedStyleMasterData();
  const SharedStyleMasterData *sharedStyleMasterData() const;
  void set_sharedStyleMasterData(SharedStyleMasterData *value);

  SharedStyleReference *sharedStyleReference();
  const SharedStyleReference *sharedStyleReference() const;
  void set_sharedStyleReference(SharedStyleReference *value);

  bool *autoRename();
  const bool *autoRename() const;
  void set_autoRename(const bool &value);

  VectorMirror *handleMirroring();
  const VectorMirror *handleMirroring() const;
  void set_handleMirroring(const VectorMirror &value);

  bool *internalOnly();
  const bool *internalOnly() const;
  void set_internalOnly(const bool &value);

  bool *isSoftDeletedStyle();
  const bool *isSoftDeletedStyle() const;
  void set_isSoftDeletedStyle(const bool &value);

  bool *isNonUpdateable();
  const bool *isNonUpdateable() const;
  void set_isNonUpdateable(const bool &value);

  bool *isPublishable();
  const bool *isPublishable() const;
  void set_isPublishable(const bool &value);

  kiwi::String *publishFile();
  const kiwi::String *publishFile() const;
  void set_publishFile(const kiwi::String &value);

  GUID *publishID();
  const GUID *publishID() const;
  void set_publishID(GUID *value);

  kiwi::String *publishedVersion();
  const kiwi::String *publishedVersion() const;
  void set_publishedVersion(const kiwi::String &value);

  bool *isSymbolPublishable();
  const bool *isSymbolPublishable() const;
  void set_isSymbolPublishable(const bool &value);

  kiwi::String *sharedSymbolVersion();
  const kiwi::String *sharedSymbolVersion() const;
  void set_sharedSymbolVersion(const kiwi::String &value);

  kiwi::Array<GUID> *ancestorPathBeforeDeletion();
  const kiwi::Array<GUID> *ancestorPathBeforeDeletion() const;
  kiwi::Array<GUID> &set_ancestorPathBeforeDeletion(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<Guide> *guides();
  const kiwi::Array<Guide> *guides() const;
  kiwi::Array<Guide> &set_guides(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<PropValueData> *stateGroupPropertyValueOrders();
  const kiwi::Array<PropValueData> *stateGroupPropertyValueOrders() const;
  kiwi::Array<PropValueData> &set_stateGroupPropertyValueOrders(kiwi::MemoryPool &pool, uint32_t count);

  bool *isStateGroup();
  const bool *isStateGroup() const;
  void set_isStateGroup(const bool &value);

  float *stackPaddingRight();
  const float *stackPaddingRight() const;
  void set_stackPaddingRight(const float &value);

  float *stackPaddingLeft();
  const float *stackPaddingLeft() const;
  void set_stackPaddingLeft(const float &value);

  float *stackPaddingTop();
  const float *stackPaddingTop() const;
  void set_stackPaddingTop(const float &value);

  float *stackPaddingBottom();
  const float *stackPaddingBottom() const;
  void set_stackPaddingBottom(const float &value);

  StackSize *stackPrimarySizing();
  const StackSize *stackPrimarySizing() const;
  void set_stackPrimarySizing(const StackSize &value);

  StackSize *stackChildPrimarySizing();
  const StackSize *stackChildPrimarySizing() const;
  void set_stackChildPrimarySizing(const StackSize &value);

  StackSize *stackChildCounterSizing();
  const StackSize *stackChildCounterSizing() const;
  void set_stackChildCounterSizing(const StackSize &value);

  StackAlignItemMode *stackPrimaryAlignItems();
  const StackAlignItemMode *stackPrimaryAlignItems() const;
  void set_stackPrimaryAlignItems(const StackAlignItemMode &value);

  StackAlignItemMode *stackCounterAlignItems();
  const StackAlignItemMode *stackCounterAlignItems() const;
  void set_stackCounterAlignItems(const StackAlignItemMode &value);

  PrototypeStartPoint *prototypeStartPt();
  const PrototypeStartPoint *prototypeStartPt() const;
  void set_prototypeStartPt(PrototypeStartPoint *value);

  StrokeCap *dashCap();
  const StrokeCap *dashCap() const;
  void set_dashCap(const StrokeCap &value);

  ConnectLineInfo *connectlineInfo();
  const ConnectLineInfo *connectlineInfo() const;
  void set_connectlineInfo(ConnectLineInfo *value);

  kiwi::Array<ObjSnapConnline> *objSnapConnline();
  const kiwi::Array<ObjSnapConnline> *objSnapConnline() const;
  kiwi::Array<ObjSnapConnline> &set_objSnapConnline(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<ConnlineTextInfo> *connlineTextInfos();
  const kiwi::Array<ConnlineTextInfo> *connlineTextInfos() const;
  kiwi::Array<ConnlineTextInfo> &set_connlineTextInfos(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<VectorPaint> *vectorPaints();
  const kiwi::Array<VectorPaint> *vectorPaints() const;
  kiwi::Array<VectorPaint> &set_vectorPaints(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<VectorStyle> *vectorStyles();
  const kiwi::Array<VectorStyle> *vectorStyles() const;
  kiwi::Array<VectorStyle> &set_vectorStyles(kiwi::MemoryPool &pool, uint32_t count);

  float *borderTopWeight();
  const float *borderTopWeight() const;
  void set_borderTopWeight(const float &value);

  float *borderBottomWeight();
  const float *borderBottomWeight() const;
  void set_borderBottomWeight(const float &value);

  float *borderLeftWeight();
  const float *borderLeftWeight() const;
  void set_borderLeftWeight(const float &value);

  float *borderRightWeight();
  const float *borderRightWeight() const;
  void set_borderRightWeight(const float &value);

  bool *borderStrokeWeightsIndependent();
  const bool *borderStrokeWeightsIndependent() const;
  void set_borderStrokeWeightsIndependent(const bool &value);

  kiwi::Array<PluginData> *pluginData();
  const kiwi::Array<PluginData> *pluginData() const;
  kiwi::Array<PluginData> &set_pluginData(kiwi::MemoryPool &pool, uint32_t count);

  bool *showInSlice();
  const bool *showInSlice() const;
  void set_showInSlice(const bool &value);

  ExportImageQualityOp *exportImageQuality();
  const ExportImageQualityOp *exportImageQuality() const;
  void set_exportImageQuality(const ExportImageQualityOp &value);

  kiwi::Array<Path> *strokePaddingPath();
  const kiwi::Array<Path> *strokePaddingPath() const;
  kiwi::Array<Path> &set_strokePaddingPath(kiwi::MemoryPool &pool, uint32_t count);

  bool *autoLayoutAbsolutePos();
  const bool *autoLayoutAbsolutePos() const;
  void set_autoLayoutAbsolutePos(const bool &value);

  bool *autoLayoutItemReverseDraw();
  const bool *autoLayoutItemReverseDraw() const;
  void set_autoLayoutItemReverseDraw(const bool &value);

  kiwi::Array<PluginRelaunchData> *pluginRelaunchData();
  const kiwi::Array<PluginRelaunchData> *pluginRelaunchData() const;
  kiwi::Array<PluginRelaunchData> &set_pluginRelaunchData(kiwi::MemoryPool &pool, uint32_t count);

  bool *autoLayoutIncludeBorders();
  const bool *autoLayoutIncludeBorders() const;
  void set_autoLayoutIncludeBorders(const bool &value);

  ProdMode *prodMode();
  const ProdMode *prodMode() const;
  void set_prodMode(ProdMode *value);

  bool *exportCutPix();
  const bool *exportCutPix() const;
  void set_exportCutPix(const bool &value);

  bool *exportKeepNameGroup();
  const bool *exportKeepNameGroup() const;
  void set_exportKeepNameGroup(const bool &value);

  TextTruncation *textTruncation();
  const TextTruncation *textTruncation() const;
  void set_textTruncation(const TextTruncation &value);

  MaskType *maskType();
  const MaskType *maskType() const;
  void set_maskType(const MaskType &value);

  LeadingTrim *leadingTrim();
  const LeadingTrim *leadingTrim() const;
  void set_leadingTrim(const LeadingTrim &value);

  bool *hangingPunctuation();
  const bool *hangingPunctuation() const;
  void set_hangingPunctuation(const bool &value);

  bool *hangingList();
  const bool *hangingList() const;
  void set_hangingList(const bool &value);

  FontVariantNumericFigure *fontVariantNumericFigure();
  const FontVariantNumericFigure *fontVariantNumericFigure() const;
  void set_fontVariantNumericFigure(const FontVariantNumericFigure &value);

  FontVariantNumericSpacing *fontVariantNumericSpacing();
  const FontVariantNumericSpacing *fontVariantNumericSpacing() const;
  void set_fontVariantNumericSpacing(const FontVariantNumericSpacing &value);

  FontVariantNumericFraction *fontVariantNumericFraction();
  const FontVariantNumericFraction *fontVariantNumericFraction() const;
  void set_fontVariantNumericFraction(const FontVariantNumericFraction &value);

  FontVariantPosition *fontVariantPosition();
  const FontVariantPosition *fontVariantPosition() const;
  void set_fontVariantPosition(const FontVariantPosition &value);

  kiwi::Array<OpenTypeFeature> *toggledOnOTFeatures();
  const kiwi::Array<OpenTypeFeature> *toggledOnOTFeatures() const;
  kiwi::Array<OpenTypeFeature> &set_toggledOnOTFeatures(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<OpenTypeFeature> *toggledOffOTFeatures();
  const kiwi::Array<OpenTypeFeature> *toggledOffOTFeatures() const;
  kiwi::Array<OpenTypeFeature> &set_toggledOffOTFeatures(kiwi::MemoryPool &pool, uint32_t count);

  int32_t *maxLines();
  const int32_t *maxLines() const;
  void set_maxLines(const int32_t &value);

  WorkState *sectionState();
  const WorkState *sectionState() const;
  void set_sectionState(const WorkState &value);

  EditInfo *editInfo();
  const EditInfo *editInfo() const;
  void set_editInfo(EditInfo *value);

  float *stackCounterSpacing();
  const float *stackCounterSpacing() const;
  void set_stackCounterSpacing(const float &value);

  StackAlign *stackCounterAlignContent();
  const StackAlign *stackCounterAlignContent() const;
  void set_stackCounterAlignContent(const StackAlign &value);

  WrapMode *stackWrap();
  const WrapMode *stackWrap() const;
  void set_stackWrap(const WrapMode &value);

  Vector *minSize();
  const Vector *minSize() const;
  void set_minSize(Vector *value);

  Vector *maxSize();
  const Vector *maxSize() const;
  void set_maxSize(Vector *value);

  kiwi::Array<ComponentPropDef> *componentPropDef();
  const kiwi::Array<ComponentPropDef> *componentPropDef() const;
  kiwi::Array<ComponentPropDef> &set_componentPropDef(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<ComponentPropRef> *componentPropRef();
  const kiwi::Array<ComponentPropRef> *componentPropRef() const;
  kiwi::Array<ComponentPropRef> &set_componentPropRef(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<ComponentPropAssignment> *componentPropAssignment();
  const kiwi::Array<ComponentPropAssignment> *componentPropAssignment() const;
  kiwi::Array<ComponentPropAssignment> &set_componentPropAssignment(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<SymbolLink> *symbolLinks();
  const kiwi::Array<SymbolLink> *symbolLinks() const;
  kiwi::Array<SymbolLink> &set_symbolLinks(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::String *description();
  const kiwi::String *description() const;
  void set_description(const kiwi::String &value);

  bool *exportNameByVariantProp();
  const bool *exportNameByVariantProp() const;
  void set_exportNameByVariantProp(const bool &value);

  bool *propsAreBubbled();
  const bool *propsAreBubbled() const;
  void set_propsAreBubbled(const bool &value);

  bool *showMask();
  const bool *showMask() const;
  void set_showMask(const bool &value);

  bool *componentOverrideHierarchy();
  const bool *componentOverrideHierarchy() const;
  void set_componentOverrideHierarchy(const bool &value);

  kiwi::Array<DeveloperRelatedLink> *developerRelatedLinks();
  const kiwi::Array<DeveloperRelatedLink> *developerRelatedLinks() const;
  kiwi::Array<DeveloperRelatedLink> &set_developerRelatedLinks(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<FontVariation> *fontVariations();
  const kiwi::Array<FontVariation> *fontVariations() const;
  kiwi::Array<FontVariation> &set_fontVariations(kiwi::MemoryPool &pool, uint32_t count);

  PathTextInfo *pathTextInfo();
  const PathTextInfo *pathTextInfo() const;
  void set_pathTextInfo(PathTextInfo *value);

  bool *detachOpticalSizeFromFontSize();
  const bool *detachOpticalSizeFromFontSize() const;
  void set_detachOpticalSizeFromFontSize(const bool &value);

  RadialRepeatData *radialRepeatData();
  const RadialRepeatData *radialRepeatData() const;
  void set_radialRepeatData(RadialRepeatData *value);

  int32_t *overrideLevel();
  const int32_t *overrideLevel() const;
  void set_overrideLevel(const int32_t &value);

  VariableData *variableData();
  const VariableData *variableData() const;
  void set_variableData(VariableData *value);

  VariableDataMap *variableConsumptionMap();
  const VariableDataMap *variableConsumptionMap() const;
  void set_variableConsumptionMap(VariableDataMap *value);

  VariableModeBySetMap *variableModeBySetMap();
  const VariableModeBySetMap *variableModeBySetMap() const;
  void set_variableModeBySetMap(VariableModeBySetMap *value);

  kiwi::Array<VariableSetMode> *variableSetModes();
  const kiwi::Array<VariableSetMode> *variableSetModes() const;
  kiwi::Array<VariableSetMode> &set_variableSetModes(kiwi::MemoryPool &pool, uint32_t count);

  AssetID *variableSetID();
  const AssetID *variableSetID() const;
  void set_variableSetID(AssetID *value);

  VariableResolvedDataType *variableResolvedType();
  const VariableResolvedDataType *variableResolvedType() const;
  void set_variableResolvedType(const VariableResolvedDataType &value);

  VariableDataValues *variableDataValues();
  const VariableDataValues *variableDataValues() const;
  void set_variableDataValues(VariableDataValues *value);

  kiwi::String *variableTokenName();
  const kiwi::String *variableTokenName() const;
  void set_variableTokenName(const kiwi::String &value);

  kiwi::Array<VariableScope> *variableScopes();
  const kiwi::Array<VariableScope> *variableScopes() const;
  kiwi::Array<VariableScope> &set_variableScopes(kiwi::MemoryPool &pool, uint32_t count);

  CodeSyntaxMap *codeSyntax();
  const CodeSyntaxMap *codeSyntax() const;
  void set_codeSyntax(CodeSyntaxMap *value);

  AssetID *backingVariableSetId();
  const AssetID *backingVariableSetId() const;
  void set_backingVariableSetId(AssetID *value);

  VariableIdOrVariableOverrideId *backingVariableId();
  const VariableIdOrVariableOverrideId *backingVariableId() const;
  void set_backingVariableId(VariableIdOrVariableOverrideId *value);

  kiwi::String *rootVariableKey();
  const kiwi::String *rootVariableKey() const;
  void set_rootVariableKey(const kiwi::String &value);

  kiwi::String *userFacingVersion();
  const kiwi::String *userFacingVersion() const;
  void set_userFacingVersion(const kiwi::String &value);

  kiwi::String *key();
  const kiwi::String *key() const;
  void set_key(const kiwi::String &value);

  bool *isSoftDeleted();
  const bool *isSoftDeleted() const;
  void set_isSoftDeleted(const bool &value);

  kiwi::String *sortPosition();
  const kiwi::String *sortPosition() const;
  void set_sortPosition(const kiwi::String &value);

  kiwi::String *sourceLibraryKey();
  const kiwi::String *sourceLibraryKey() const;
  void set_sourceLibraryKey(const kiwi::String &value);

  DeliverInfo *deliverInfo();
  const DeliverInfo *deliverInfo() const;
  void set_deliverInfo(DeliverInfo *value);

  Matrix3f *deformationTransform();
  const Matrix3f *deformationTransform() const;
  void set_deformationTransform(Matrix3f *value);

  kiwi::Array<TransformModifier> *transformModifiers();
  const kiwi::Array<TransformModifier> *transformModifiers() const;
  kiwi::Array<TransformModifier> &set_transformModifiers(kiwi::MemoryPool &pool, uint32_t count);

  bool *groupIncludeInvisible();
  const bool *groupIncludeInvisible() const;
  void set_groupIncludeInvisible(const bool &value);

  GUID *variableSymbolID();
  const GUID *variableSymbolID() const;
  void set_variableSymbolID(GUID *value);

  kiwi::Array<Annotation> *annotations();
  const kiwi::Array<Annotation> *annotations() const;
  kiwi::Array<Annotation> &set_annotations(kiwi::MemoryPool &pool, uint32_t count);

  AnnotationCategories *annotationCategories();
  const AnnotationCategories *annotationCategories() const;
  void set_annotationCategories(AnnotationCategories *value);

  GUID *gridRowAnchor();
  const GUID *gridRowAnchor() const;
  void set_gridRowAnchor(GUID *value);

  GUID *gridColumnAnchor();
  const GUID *gridColumnAnchor() const;
  void set_gridColumnAnchor(GUID *value);

  uint32_t *gridRowSpan();
  const uint32_t *gridRowSpan() const;
  void set_gridRowSpan(const uint32_t &value);

  uint32_t *gridColumnSpan();
  const uint32_t *gridColumnSpan() const;
  void set_gridColumnSpan(const uint32_t &value);

  GridChildAlign *gridChildVerticalAlign();
  const GridChildAlign *gridChildVerticalAlign() const;
  void set_gridChildVerticalAlign(const GridChildAlign &value);

  GridChildAlign *gridChildHorizontalAlign();
  const GridChildAlign *gridChildHorizontalAlign() const;
  void set_gridChildHorizontalAlign(const GridChildAlign &value);

  kiwi::Array<GUID> *gridRows();
  const kiwi::Array<GUID> *gridRows() const;
  kiwi::Array<GUID> &set_gridRows(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<GUID> *gridColumns();
  const kiwi::Array<GUID> *gridColumns() const;
  kiwi::Array<GUID> &set_gridColumns(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<GridTrackSizing> *gridRowsSizing();
  const kiwi::Array<GridTrackSizing> *gridRowsSizing() const;
  kiwi::Array<GridTrackSizing> &set_gridRowsSizing(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<GridTrackSizing> *gridColumnsSizing();
  const kiwi::Array<GridTrackSizing> *gridColumnsSizing() const;
  kiwi::Array<GridTrackSizing> &set_gridColumnsSizing(kiwi::MemoryPool &pool, uint32_t count);

  bool *autoCornerRadius();
  const bool *autoCornerRadius() const;
  void set_autoCornerRadius(const bool &value);

  Vector *targetAspectRatio();
  const Vector *targetAspectRatio() const;
  void set_targetAspectRatio(Vector *value);

  kiwi::String *aliasName();
  const kiwi::String *aliasName() const;
  void set_aliasName(const kiwi::String &value);

  bool *simplifyInstancePanels();
  const bool *simplifyInstancePanels() const;
  void set_simplifyInstancePanels(const bool &value);

  Vector *rotationOrigin();
  const Vector *rotationOrigin() const;
  void set_rotationOrigin(Vector *value);

  VideoPlayback *videoPlayback();
  const VideoPlayback *videoPlayback() const;
  void set_videoPlayback(VideoPlayback *value);

  kiwi::Array<VariableWidthPoint> *variableWidths();
  const kiwi::Array<VariableWidthPoint> *variableWidths() const;
  kiwi::Array<VariableWidthPoint> &set_variableWidths(kiwi::MemoryPool &pool, uint32_t count);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[8] = {};
  GUID *_data_guid = {};
  GUIDPath *_data_guidPath = {};
  ParentIndex *_data_parentIndex = {};
  NodePhase _data_phase = {};
  Matrix *_data_transform = {};
  NodeType _data_type = {};
  kiwi::String _data_name = {};
  VectorData *_data_vectorData = {};
  kiwi::String _data_version = {};
  Vector *_data_size = {};
  BooleanOperation _data_booleanOperation = {};
  ArcData *_data_arcData = {};
  BlendMode _data_blendMode = {};
  kiwi::Array<Effect> _data_effects = {};
  kiwi::Array<Path> _data_fillGeometry = {};
  kiwi::Array<Paint> _data_fillPaints = {};
  kiwi::Array<float> _data_dashPattern = {};
  StackCounterAlign _data_stackCounterAlign = {};
  StackSize _data_stackCounterSizing = {};
  StackSize _data_stackHeight = {};
  StackJustify _data_stackJustify = {};
  StackMode _data_stackMode = {};
  StackSize _data_stackWidth = {};
  StrokeAlign _data_strokeAlign = {};
  StrokeCap _data_strokeCap = {};
  kiwi::Array<Path> _data_strokeGeometry = {};
  StrokeJoin _data_strokeJoin = {};
  kiwi::Array<Paint> _data_strokePaints = {};
  kiwi::String _data_styleDescription = {};
  StyleType _data_styleType = {};
  SymbolData *_data_symbolData = {};
  kiwi::String _data_symbolDescription = {};
  kiwi::Array<LayoutGrid> _data_layoutGrids = {};
  Color *_data_backgroundColor = {};
  kiwi::Array<Paint> _data_backgroundPaints = {};
  kiwi::Array<ExportSettings> _data_exportSettings = {};
  FontName *_data_fontName = {};
  kiwi::String _data_fontVersion = {};
  TextAlignHorizontal _data_textAlignHorizontal = {};
  TextAlignVertical _data_textAlignVertical = {};
  TextAutoResize _data_textAutoResize = {};
  TextCase _data_textCase = {};
  TextData *_data_textData = {};
  TextDecoration _data_textDecoration = {};
  Number *_data_letterSpacing = {};
  Number *_data_lineHeight = {};
  ConstraintType _data_horizontalConstraint = {};
  ConstraintType _data_verticalConstraint = {};
  kiwi::Array<PixsoNode> _data_derivedSymbolData = {};
  kiwi::String _data_componentKey = {};
  GUID *_data_inheritEffectStyleID = {};
  GUID *_data_inheritExportStyleID = {};
  GUID *_data_inheritFillStyleID = {};
  GUID *_data_inheritFillStyleIDForBackground = {};
  GUID *_data_inheritFillStyleIDForStroke = {};
  GUID *_data_inheritGridStyleID = {};
  GUID *_data_inheritStrokeStyleID = {};
  GUID *_data_inheritTextStyleID = {};
  GUID *_data_overriddenSymbolID = {};
  GUID *_data_overrideKey = {};
  KeyTrigger *_data_keyTrigger = {};
  NavigationType _data_navigationType = {};
  InteractionType _data_interactionType = {};
  ConnectionType _data_connectionType = {};
  kiwi::String _data_connectionURL = {};
  EasingType _data_easingType = {};
  Color *_data_prototypeBackgroundColor = {};
  PrototypeDevice *_data_prototypeDevice = {};
  kiwi::Array<PrototypeInteraction> _data_prototypeInteractions = {};
  GUID *_data_prototypeStartNodeID = {};
  OverlayBackgroundAppearance *_data_overlayBackgroundAppearance = {};
  OverlayBackgroundInteraction _data_overlayBackgroundInteraction = {};
  OverlayPositionType _data_overlayPositionType = {};
  Vector *_data_overlayRelativePosition = {};
  GUID *_data_transitionNodeID = {};
  TransitionType _data_transitionType = {};
  ScrollBehavior _data_scrollBehavior = {};
  ScrollDirection _data_scrollDirection = {};
  Hyperlink *_data_hyperlink = {};
  SharedStyleMasterData *_data_sharedStyleMasterData = {};
  SharedStyleReference *_data_sharedStyleReference = {};
  VectorMirror _data_handleMirroring = {};
  kiwi::String _data_publishFile = {};
  GUID *_data_publishID = {};
  kiwi::String _data_publishedVersion = {};
  kiwi::String _data_sharedSymbolVersion = {};
  kiwi::Array<GUID> _data_ancestorPathBeforeDeletion = {};
  kiwi::Array<Guide> _data_guides = {};
  kiwi::Array<PropValueData> _data_stateGroupPropertyValueOrders = {};
  StackSize _data_stackPrimarySizing = {};
  StackSize _data_stackChildPrimarySizing = {};
  StackSize _data_stackChildCounterSizing = {};
  StackAlignItemMode _data_stackPrimaryAlignItems = {};
  StackAlignItemMode _data_stackCounterAlignItems = {};
  PrototypeStartPoint *_data_prototypeStartPt = {};
  StrokeCap _data_dashCap = {};
  ConnectLineInfo *_data_connectlineInfo = {};
  kiwi::Array<ObjSnapConnline> _data_objSnapConnline = {};
  kiwi::Array<ConnlineTextInfo> _data_connlineTextInfos = {};
  kiwi::Array<VectorPaint> _data_vectorPaints = {};
  kiwi::Array<VectorStyle> _data_vectorStyles = {};
  kiwi::Array<PluginData> _data_pluginData = {};
  ExportImageQualityOp _data_exportImageQuality = {};
  kiwi::Array<Path> _data_strokePaddingPath = {};
  kiwi::Array<PluginRelaunchData> _data_pluginRelaunchData = {};
  ProdMode *_data_prodMode = {};
  TextTruncation _data_textTruncation = {};
  MaskType _data_maskType = {};
  LeadingTrim _data_leadingTrim = {};
  FontVariantNumericFigure _data_fontVariantNumericFigure = {};
  FontVariantNumericSpacing _data_fontVariantNumericSpacing = {};
  FontVariantNumericFraction _data_fontVariantNumericFraction = {};
  FontVariantPosition _data_fontVariantPosition = {};
  kiwi::Array<OpenTypeFeature> _data_toggledOnOTFeatures = {};
  kiwi::Array<OpenTypeFeature> _data_toggledOffOTFeatures = {};
  WorkState _data_sectionState = {};
  EditInfo *_data_editInfo = {};
  StackAlign _data_stackCounterAlignContent = {};
  WrapMode _data_stackWrap = {};
  Vector *_data_minSize = {};
  Vector *_data_maxSize = {};
  kiwi::Array<ComponentPropDef> _data_componentPropDef = {};
  kiwi::Array<ComponentPropRef> _data_componentPropRef = {};
  kiwi::Array<ComponentPropAssignment> _data_componentPropAssignment = {};
  kiwi::Array<SymbolLink> _data_symbolLinks = {};
  kiwi::String _data_description = {};
  kiwi::Array<DeveloperRelatedLink> _data_developerRelatedLinks = {};
  kiwi::Array<FontVariation> _data_fontVariations = {};
  PathTextInfo *_data_pathTextInfo = {};
  RadialRepeatData *_data_radialRepeatData = {};
  VariableData *_data_variableData = {};
  VariableDataMap *_data_variableConsumptionMap = {};
  VariableModeBySetMap *_data_variableModeBySetMap = {};
  kiwi::Array<VariableSetMode> _data_variableSetModes = {};
  AssetID *_data_variableSetID = {};
  VariableResolvedDataType _data_variableResolvedType = {};
  VariableDataValues *_data_variableDataValues = {};
  kiwi::String _data_variableTokenName = {};
  kiwi::Array<VariableScope> _data_variableScopes = {};
  CodeSyntaxMap *_data_codeSyntax = {};
  AssetID *_data_backingVariableSetId = {};
  VariableIdOrVariableOverrideId *_data_backingVariableId = {};
  kiwi::String _data_rootVariableKey = {};
  kiwi::String _data_userFacingVersion = {};
  kiwi::String _data_key = {};
  kiwi::String _data_sortPosition = {};
  kiwi::String _data_sourceLibraryKey = {};
  DeliverInfo *_data_deliverInfo = {};
  Matrix3f *_data_deformationTransform = {};
  kiwi::Array<TransformModifier> _data_transformModifiers = {};
  GUID *_data_variableSymbolID = {};
  kiwi::Array<Annotation> _data_annotations = {};
  AnnotationCategories *_data_annotationCategories = {};
  GUID *_data_gridRowAnchor = {};
  GUID *_data_gridColumnAnchor = {};
  GridChildAlign _data_gridChildVerticalAlign = {};
  GridChildAlign _data_gridChildHorizontalAlign = {};
  kiwi::Array<GUID> _data_gridRows = {};
  kiwi::Array<GUID> _data_gridColumns = {};
  kiwi::Array<GridTrackSizing> _data_gridRowsSizing = {};
  kiwi::Array<GridTrackSizing> _data_gridColumnsSizing = {};
  Vector *_data_targetAspectRatio = {};
  kiwi::String _data_aliasName = {};
  Vector *_data_rotationOrigin = {};
  VideoPlayback *_data_videoPlayback = {};
  kiwi::Array<VariableWidthPoint> _data_variableWidths = {};
  int32_t _data_count = {};
  float _data_cornerRadius = {};
  float _data_cornerSmoothing = {};
  float _data_opacity = {};
  float _data_stackHorizontalPadding = {};
  float _data_stackPadding = {};
  float _data_stackSpacing = {};
  float _data_stackVerticalPadding = {};
  float _data_strokeWeight = {};
  int32_t _data_styleID = {};
  float _data_starInnerScale = {};
  float _data_miterLimit = {};
  float _data_backgroundOpacity = {};
  float _data_fontSize = {};
  float _data_paragraphIndent = {};
  float _data_paragraphSpacing = {};
  float _data_textTracking = {};
  int32_t _data_textUserLayoutVersion = {};
  int32_t _data_derivedSymbolDataLayoutVersion = {};
  float _data_interactionDuration = {};
  float _data_transitionDuration = {};
  float _data_transitionTimeout = {};
  float _data_rectangleBottomLeftCornerRadius = {};
  float _data_rectangleBottomRightCornerRadius = {};
  float _data_rectangleTopLeftCornerRadius = {};
  float _data_rectangleTopRightCornerRadius = {};
  float _data_stackPaddingRight = {};
  float _data_stackPaddingLeft = {};
  float _data_stackPaddingTop = {};
  float _data_stackPaddingBottom = {};
  float _data_borderTopWeight = {};
  float _data_borderBottomWeight = {};
  float _data_borderLeftWeight = {};
  float _data_borderRightWeight = {};
  int32_t _data_maxLines = {};
  float _data_stackCounterSpacing = {};
  int32_t _data_overrideLevel = {};
  uint32_t _data_gridRowSpan = {};
  uint32_t _data_gridColumnSpan = {};
  bool _data_visible = {};
  bool _data_locked = {};
  bool _data_mask = {};
  bool _data_maskIsOutline = {};
  bool _data_backgroundEnabled = {};
  bool _data_exportBackgroundDisabled = {};
  bool _data_exportContentsOnly = {};
  bool _data_exportTextAsSVGText = {};
  bool _data_interactionMaintained = {};
  bool _data_proportionsConstrained = {};
  bool _data_transitionPreserveScroll = {};
  bool _data_transitionShouldSmartAnimate = {};
  bool _data_rectangleCornerRadiiIndependent = {};
  bool _data_rectangleCornerToolIndependent = {};
  bool _data_frameMaskDisabled = {};
  bool _data_autoRename = {};
  bool _data_internalOnly = {};
  bool _data_isSoftDeletedStyle = {};
  bool _data_isNonUpdateable = {};
  bool _data_isPublishable = {};
  bool _data_isSymbolPublishable = {};
  bool _data_isStateGroup = {};
  bool _data_borderStrokeWeightsIndependent = {};
  bool _data_showInSlice = {};
  bool _data_autoLayoutAbsolutePos = {};
  bool _data_autoLayoutItemReverseDraw = {};
  bool _data_autoLayoutIncludeBorders = {};
  bool _data_exportCutPix = {};
  bool _data_exportKeepNameGroup = {};
  bool _data_hangingPunctuation = {};
  bool _data_hangingList = {};
  bool _data_exportNameByVariantProp = {};
  bool _data_propsAreBubbled = {};
  bool _data_showMask = {};
  bool _data_componentOverrideHierarchy = {};
  bool _data_detachOpticalSizeFromFontSize = {};
  bool _data_isSoftDeleted = {};
  bool _data_groupIncludeInvisible = {};
  bool _data_autoCornerRadius = {};
  bool _data_simplifyInstancePanels = {};
};

class ProdMode {
public:
  ProdMode() { (void)_flags; }

  ProdTextStyle *textStyle();
  const ProdTextStyle *textStyle() const;
  void set_textStyle(ProdTextStyle *value);

  float *navigationItemInterval();
  const float *navigationItemInterval() const;
  void set_navigationItemInterval(const float &value);

  kiwi::String *prodContent();
  const kiwi::String *prodContent() const;
  void set_prodContent(const kiwi::String &value);

  ParentIndex *hostIndex();
  const ParentIndex *hostIndex() const;
  void set_hostIndex(ParentIndex *value);

  int32_t *tableRowCount();
  const int32_t *tableRowCount() const;
  void set_tableRowCount(const int32_t &value);

  int32_t *tableColCount();
  const int32_t *tableColCount() const;
  void set_tableColCount(const int32_t &value);

  GUID *dropListOptionSelectID();
  const GUID *dropListOptionSelectID() const;
  void set_dropListOptionSelectID(GUID *value);

  bool *dropListExpand();
  const bool *dropListExpand() const;
  void set_dropListExpand(const bool &value);

  ProdTextStyle *activeTextStyle();
  const ProdTextStyle *activeTextStyle() const;
  void set_activeTextStyle(ProdTextStyle *value);

  Vector *tableSize();
  const Vector *tableSize() const;
  void set_tableSize(Vector *value);

  Paint *tableCellFillPaint();
  const Paint *tableCellFillPaint() const;
  void set_tableCellFillPaint(Paint *value);

  Vector *navigationItemSize();
  const Vector *navigationItemSize() const;
  void set_navigationItemSize(Vector *value);

  bool *navigationOptionExpand();
  const bool *navigationOptionExpand() const;
  void set_navigationOptionExpand(const bool &value);

  bool *componentLibrarySwitch();
  const bool *componentLibrarySwitch() const;
  void set_componentLibrarySwitch(const bool &value);

  ProdScoreBar *scoreBar();
  const ProdScoreBar *scoreBar() const;
  void set_scoreBar(ProdScoreBar *value);

  float *navigationItemRatio();
  const float *navigationItemRatio() const;
  void set_navigationItemRatio(const float &value);

  ProdDragBar *dragBar();
  const ProdDragBar *dragBar() const;
  void set_dragBar(ProdDragBar *value);

  ProdTableCell *tableCell();
  const ProdTableCell *tableCell() const;
  void set_tableCell(ProdTableCell *value);

  int32_t *tableBorderStyle();
  const int32_t *tableBorderStyle() const;
  void set_tableBorderStyle(const int32_t &value);

  int32_t *embeddedIconPositionFlag();
  const int32_t *embeddedIconPositionFlag() const;
  void set_embeddedIconPositionFlag(const int32_t &value);

  float *recordHeight();
  const float *recordHeight() const;
  void set_recordHeight(const float &value);

  int32_t *selectForm();
  const int32_t *selectForm() const;
  void set_selectForm(const int32_t &value);

  int32_t *layoutMethod();
  const int32_t *layoutMethod() const;
  void set_layoutMethod(const int32_t &value);

  int32_t *layerPosition();
  const int32_t *layerPosition() const;
  void set_layerPosition(const int32_t &value);

  ProdViewportOrientation *viewportOrientation();
  const ProdViewportOrientation *viewportOrientation() const;
  void set_viewportOrientation(const ProdViewportOrientation &value);

  kiwi::Array<NodeType> *vNodeType();
  const kiwi::Array<NodeType> *vNodeType() const;
  kiwi::Array<NodeType> &set_vNodeType(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::String *stringIconSVG();
  const kiwi::String *stringIconSVG() const;
  void set_stringIconSVG(const kiwi::String &value);

  bool *tableHeaderVisible();
  const bool *tableHeaderVisible() const;
  void set_tableHeaderVisible(const bool &value);

  float *recordWidth();
  const float *recordWidth() const;
  void set_recordWidth(const float &value);

  int32_t *recodeCount();
  const int32_t *recodeCount() const;
  void set_recodeCount(const int32_t &value);

  int32_t *selectIndex();
  const int32_t *selectIndex() const;
  void set_selectIndex(const int32_t &value);

  ProdLayoutParam *layoutParam();
  const ProdLayoutParam *layoutParam() const;
  void set_layoutParam(ProdLayoutParam *value);

  ProdBlockStyleType *blockStyleType();
  const ProdBlockStyleType *blockStyleType() const;
  void set_blockStyleType(const ProdBlockStyleType &value);

  float *distance();
  const float *distance() const;
  void set_distance(const float &value);

  bool *hoverTrigger();
  const bool *hoverTrigger() const;
  void set_hoverTrigger(const bool &value);

  bool *fitContent();
  const bool *fitContent() const;
  void set_fitContent(const bool &value);

  kiwi::String *stringIconName();
  const kiwi::String *stringIconName() const;
  void set_stringIconName(const kiwi::String &value);

  ProdTwoDimChart *twoDimChart();
  const ProdTwoDimChart *twoDimChart() const;
  void set_twoDimChart(ProdTwoDimChart *value);

  kiwi::Array<GUID> *extraGuids();
  const kiwi::Array<GUID> *extraGuids() const;
  kiwi::Array<GUID> &set_extraGuids(kiwi::MemoryPool &pool, uint32_t count);

  bool *tableSelectColVisible();
  const bool *tableSelectColVisible() const;
  void set_tableSelectColVisible(const bool &value);

  ScrollBar *frameScrollBarVisible();
  const ScrollBar *frameScrollBarVisible() const;
  void set_frameScrollBarVisible(const ScrollBar &value);

  int32_t *checkBoxState();
  const int32_t *checkBoxState() const;
  void set_checkBoxState(const int32_t &value);

  ComponentStateType *componentState();
  const ComponentStateType *componentState() const;
  void set_componentState(const ComponentStateType &value);

  bool *iconSwitch();
  const bool *iconSwitch() const;
  void set_iconSwitch(const bool &value);

  bool *checkBoxSwitch();
  const bool *checkBoxSwitch() const;
  void set_checkBoxSwitch(const bool &value);

  bool *flodingSymbolSwitch();
  const bool *flodingSymbolSwitch() const;
  void set_flodingSymbolSwitch(const bool &value);

  bool *checkBoxHited();
  const bool *checkBoxHited() const;
  void set_checkBoxHited(const bool &value);

  float *layerlndent();
  const float *layerlndent() const;
  void set_layerlndent(const float &value);

  int32_t *foldingSymbolType();
  const int32_t *foldingSymbolType() const;
  void set_foldingSymbolType(const int32_t &value);

  kiwi::Array<GUID> *blockMarkerIds();
  const kiwi::Array<GUID> *blockMarkerIds() const;
  kiwi::Array<GUID> &set_blockMarkerIds(kiwi::MemoryPool &pool, uint32_t count);

  BlockMarkerParams *blockMarkerParams();
  const BlockMarkerParams *blockMarkerParams() const;
  void set_blockMarkerParams(BlockMarkerParams *value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[2] = {};
  ProdTextStyle *_data_textStyle = {};
  kiwi::String _data_prodContent = {};
  ParentIndex *_data_hostIndex = {};
  GUID *_data_dropListOptionSelectID = {};
  ProdTextStyle *_data_activeTextStyle = {};
  Vector *_data_tableSize = {};
  Paint *_data_tableCellFillPaint = {};
  Vector *_data_navigationItemSize = {};
  ProdScoreBar *_data_scoreBar = {};
  ProdDragBar *_data_dragBar = {};
  ProdTableCell *_data_tableCell = {};
  ProdViewportOrientation _data_viewportOrientation = {};
  kiwi::Array<NodeType> _data_vNodeType = {};
  kiwi::String _data_stringIconSVG = {};
  ProdLayoutParam *_data_layoutParam = {};
  ProdBlockStyleType _data_blockStyleType = {};
  kiwi::String _data_stringIconName = {};
  ProdTwoDimChart *_data_twoDimChart = {};
  kiwi::Array<GUID> _data_extraGuids = {};
  ScrollBar _data_frameScrollBarVisible = {};
  ComponentStateType _data_componentState = {};
  kiwi::Array<GUID> _data_blockMarkerIds = {};
  BlockMarkerParams *_data_blockMarkerParams = {};
  float _data_navigationItemInterval = {};
  int32_t _data_tableRowCount = {};
  int32_t _data_tableColCount = {};
  float _data_navigationItemRatio = {};
  int32_t _data_tableBorderStyle = {};
  int32_t _data_embeddedIconPositionFlag = {};
  float _data_recordHeight = {};
  int32_t _data_selectForm = {};
  int32_t _data_layoutMethod = {};
  int32_t _data_layerPosition = {};
  float _data_recordWidth = {};
  int32_t _data_recodeCount = {};
  int32_t _data_selectIndex = {};
  float _data_distance = {};
  int32_t _data_checkBoxState = {};
  float _data_layerlndent = {};
  int32_t _data_foldingSymbolType = {};
  bool _data_dropListExpand = {};
  bool _data_navigationOptionExpand = {};
  bool _data_componentLibrarySwitch = {};
  bool _data_tableHeaderVisible = {};
  bool _data_hoverTrigger = {};
  bool _data_fitContent = {};
  bool _data_tableSelectColVisible = {};
  bool _data_iconSwitch = {};
  bool _data_checkBoxSwitch = {};
  bool _data_flodingSymbolSwitch = {};
  bool _data_checkBoxHited = {};
};

class BlockMarkerParams {
public:
  BlockMarkerParams() { (void)_flags; }

  GUID *relatedMarkerId();
  const GUID *relatedMarkerId() const;
  void set_relatedMarkerId(GUID *value);

  MarkerSide *markerSide();
  const MarkerSide *markerSide() const;
  void set_markerSide(const MarkerSide &value);

  GUID *boundNodeId();
  const GUID *boundNodeId() const;
  void set_boundNodeId(GUID *value);

  int32_t *markerIndex();
  const int32_t *markerIndex() const;
  void set_markerIndex(const int32_t &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  GUID *_data_relatedMarkerId = {};
  MarkerSide _data_markerSide = {};
  GUID *_data_boundNodeId = {};
  int32_t _data_markerIndex = {};
};

class ProdLayoutParam {
public:
  ProdLayoutParam() { (void)_flags; }

  ProdLayoutMode *layoutMode();
  const ProdLayoutMode *layoutMode() const;
  void set_layoutMode(const ProdLayoutMode &value);

  ProdLayoutSizeMode *witdhMode();
  const ProdLayoutSizeMode *witdhMode() const;
  void set_witdhMode(const ProdLayoutSizeMode &value);

  ProdLayoutSizeMode *heightMode();
  const ProdLayoutSizeMode *heightMode() const;
  void set_heightMode(const ProdLayoutSizeMode &value);

  ProdLayoutInterval *margin();
  const ProdLayoutInterval *margin() const;
  void set_margin(ProdLayoutInterval *value);

  ProdLayoutInterval *padding();
  const ProdLayoutInterval *padding() const;
  void set_padding(ProdLayoutInterval *value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  ProdLayoutMode _data_layoutMode = {};
  ProdLayoutSizeMode _data_witdhMode = {};
  ProdLayoutSizeMode _data_heightMode = {};
  ProdLayoutInterval *_data_margin = {};
  ProdLayoutInterval *_data_padding = {};
};

class ProdLayoutInterval {
public:
  ProdLayoutInterval() { (void)_flags; }

  float *left();
  const float *left() const;
  void set_left(const float &value);

  float *top();
  const float *top() const;
  void set_top(const float &value);

  float *right();
  const float *right() const;
  void set_right(const float &value);

  float *bottom();
  const float *bottom() const;
  void set_bottom(const float &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  float _data_left = {};
  float _data_top = {};
  float _data_right = {};
  float _data_bottom = {};
};

class ProdAdjustSize {
public:
  ProdAdjustSize() { (void)_flags; }

  ProdAdjustSizeType *adjustSizeType();
  const ProdAdjustSizeType *adjustSizeType() const;
  void set_adjustSizeType(const ProdAdjustSizeType &value);

  ProdAdjustBaseType *baseDirection();
  const ProdAdjustBaseType *baseDirection() const;
  void set_baseDirection(const ProdAdjustBaseType &value);

  float *width();
  const float *width() const;
  void set_width(const float &value);

  float *height();
  const float *height() const;
  void set_height(const float &value);

  ProdAdjustUnitType *widthUnit();
  const ProdAdjustUnitType *widthUnit() const;
  void set_widthUnit(const ProdAdjustUnitType &value);

  ProdAdjustUnitType *heightUnit();
  const ProdAdjustUnitType *heightUnit() const;
  void set_heightUnit(const ProdAdjustUnitType &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  ProdAdjustSizeType _data_adjustSizeType = {};
  ProdAdjustBaseType _data_baseDirection = {};
  ProdAdjustUnitType _data_widthUnit = {};
  ProdAdjustUnitType _data_heightUnit = {};
  float _data_width = {};
  float _data_height = {};
};

class ProdMoving {
public:
  ProdMoving() { (void)_flags; }

  ProdChangeLocationType *adjustSizeType();
  const ProdChangeLocationType *adjustSizeType() const;
  void set_adjustSizeType(const ProdChangeLocationType &value);

  float *x();
  const float *x() const;
  void set_x(const float &value);

  float *y();
  const float *y() const;
  void set_y(const float &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  ProdChangeLocationType _data_adjustSizeType = {};
  float _data_x = {};
  float _data_y = {};
};

class ProdRotate {
public:
  ProdRotate() { (void)_flags; }

  ProdRotationType *rotationType();
  const ProdRotationType *rotationType() const;
  void set_rotationType(const ProdRotationType &value);

  float *anlge();
  const float *anlge() const;
  void set_anlge(const float &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  ProdRotationType _data_rotationType = {};
  float _data_anlge = {};
};

class ProdTableCell {
public:
  ProdTableCell() { (void)_flags; }

  int32_t *cellSizeRow();
  const int32_t *cellSizeRow() const;
  void set_cellSizeRow(const int32_t &value);

  int32_t *cellSizeCol();
  const int32_t *cellSizeCol() const;
  void set_cellSizeCol(const int32_t &value);

  GUID *mergeToGuid();
  const GUID *mergeToGuid() const;
  void set_mergeToGuid(GUID *value);

  uint32_t *cellHAlign();
  const uint32_t *cellHAlign() const;
  void set_cellHAlign(const uint32_t &value);

  uint32_t *cellVAlign();
  const uint32_t *cellVAlign() const;
  void set_cellVAlign(const uint32_t &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  GUID *_data_mergeToGuid = {};
  int32_t _data_cellSizeRow = {};
  int32_t _data_cellSizeCol = {};
  uint32_t _data_cellHAlign = {};
  uint32_t _data_cellVAlign = {};
};

class ProdTextStyle {
public:
  ProdTextStyle() { (void)_flags; }

  FontName *fontName();
  const FontName *fontName() const;
  void set_fontName(FontName *value);

  Paint *fillPaint();
  const Paint *fillPaint() const;
  void set_fillPaint(Paint *value);

  float *fontSize();
  const float *fontSize() const;
  void set_fontSize(const float &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  FontName *_data_fontName = {};
  Paint *_data_fillPaint = {};
  float _data_fontSize = {};
};

class ProdScoreBar {
public:
  ProdScoreBar() { (void)_flags; }

  int32_t *numPath();
  const int32_t *numPath() const;
  void set_numPath(const int32_t &value);

  float *score();
  const float *score() const;
  void set_score(const float &value);

  ProdScalingFactor *scalingFactor();
  const ProdScalingFactor *scalingFactor() const;
  void set_scalingFactor(ProdScalingFactor *value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  ProdScalingFactor *_data_scalingFactor = {};
  int32_t _data_numPath = {};
  float _data_score = {};
};

class ProdDragBar {
public:
  ProdDragBar() { (void)_flags; }

  float *radius();
  const float *radius() const;
  void set_radius(const float &value);

  ProdScalingFactor *scalingFactor();
  const ProdScalingFactor *scalingFactor() const;
  void set_scalingFactor(ProdScalingFactor *value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  ProdScalingFactor *_data_scalingFactor = {};
  float _data_radius = {};
};

class ProdScalingFactor {
public:
  ProdScalingFactor() { (void)_flags; }

  float *wScalingFactor();
  const float *wScalingFactor() const;
  void set_wScalingFactor(const float &value);

  float *hScalingFactor();
  const float *hScalingFactor() const;
  void set_hScalingFactor(const float &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  float _data_wScalingFactor = {};
  float _data_hScalingFactor = {};
};

class ProdTDCElementinfo {
public:
  ProdTDCElementinfo() { (void)_flags; }

  kiwi::String *firstVar();
  const kiwi::String *firstVar() const;
  void set_firstVar(const kiwi::String &value);

  kiwi::String *secondVar();
  const kiwi::String *secondVar() const;
  void set_secondVar(const kiwi::String &value);

  float *value();
  const float *value() const;
  void set_value(const float &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::String _data_firstVar = {};
  kiwi::String _data_secondVar = {};
  float _data_value = {};
};

class ProdTwoDimChart {
public:
  ProdTwoDimChart() { (void)_flags; }

  kiwi::Array<ProdTDCElementinfo> *TDCElementInfo();
  const kiwi::Array<ProdTDCElementinfo> *TDCElementInfo() const;
  kiwi::Array<ProdTDCElementinfo> &set_TDCElementInfo(kiwi::MemoryPool &pool, uint32_t count);

  bool *axisSwitch();
  const bool *axisSwitch() const;
  void set_axisSwitch(const bool &value);

  bool *gridSwitch();
  const bool *gridSwitch() const;
  void set_gridSwitch(const bool &value);

  bool *titleSwitch();
  const bool *titleSwitch() const;
  void set_titleSwitch(const bool &value);

  bool *legendSwitch();
  const bool *legendSwitch() const;
  void set_legendSwitch(const bool &value);

  bool *dataLableSwitch();
  const bool *dataLableSwitch() const;
  void set_dataLableSwitch(const bool &value);

  bool *dataWinSwitch();
  const bool *dataWinSwitch() const;
  void set_dataWinSwitch(const bool &value);

  int32_t *legendDir();
  const int32_t *legendDir() const;
  void set_legendDir(const int32_t &value);

  int32_t *colNum();
  const int32_t *colNum() const;
  void set_colNum(const int32_t &value);

  int32_t *rowNum();
  const int32_t *rowNum() const;
  void set_rowNum(const int32_t &value);

  int32_t *chartMode();
  const int32_t *chartMode() const;
  void set_chartMode(const int32_t &value);

  kiwi::Array<float> *drawArea();
  const kiwi::Array<float> *drawArea() const;
  kiwi::Array<float> &set_drawArea(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<float> *legendSymPos();
  const kiwi::Array<float> *legendSymPos() const;
  kiwi::Array<float> &set_legendSymPos(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<float> *axisScale();
  const kiwi::Array<float> *axisScale() const;
  kiwi::Array<float> &set_axisScale(kiwi::MemoryPool &pool, uint32_t count);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::Array<ProdTDCElementinfo> _data_TDCElementInfo = {};
  kiwi::Array<float> _data_drawArea = {};
  kiwi::Array<float> _data_legendSymPos = {};
  kiwi::Array<float> _data_axisScale = {};
  int32_t _data_legendDir = {};
  int32_t _data_colNum = {};
  int32_t _data_rowNum = {};
  int32_t _data_chartMode = {};
  bool _data_axisSwitch = {};
  bool _data_gridSwitch = {};
  bool _data_titleSwitch = {};
  bool _data_legendSwitch = {};
  bool _data_dataLableSwitch = {};
  bool _data_dataWinSwitch = {};
};

class Guide {
public:
  Guide() { (void)_flags; }

  Axis *axis();
  const Axis *axis() const;
  void set_axis(const Axis &value);

  float *offset();
  const float *offset() const;
  void set_offset(const float &value);

  GUID *guid();
  const GUID *guid() const;
  void set_guid(GUID *value);

  float *distance();
  const float *distance() const;
  void set_distance(const float &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  Axis _data_axis = {};
  GUID *_data_guid = {};
  float _data_offset = {};
  float _data_distance = {};
};

class OverlayBackgroundAppearance {
public:
  OverlayBackgroundAppearance() { (void)_flags; }

  OverlayBackgroundType *backgroundType();
  const OverlayBackgroundType *backgroundType() const;
  void set_backgroundType(const OverlayBackgroundType &value);

  Color *backgroundColor();
  const Color *backgroundColor() const;
  void set_backgroundColor(Color *value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  OverlayBackgroundType _data_backgroundType = {};
  Color *_data_backgroundColor = {};
};

class Number {
public:
  Number() { (void)_flags; }

  float *value();
  const float *value() const;
  void set_value(const float &value);

  NumberUnits *units();
  const NumberUnits *units() const;
  void set_units(const NumberUnits &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  NumberUnits _data_units = {};
  float _data_value = {};
};

class ParentIndex {
public:
  ParentIndex() { (void)_flags; }

  GUID *guid();
  const GUID *guid() const;
  void set_guid(GUID *value);

  kiwi::String *position();
  const kiwi::String *position() const;
  void set_position(const kiwi::String &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  GUID *_data_guid = {};
  kiwi::String _data_position = {};
};

class UserInfo {
public:
  UserInfo() { (void)_flags; }

  uint32_t *sessionID();
  const uint32_t *sessionID() const;
  void set_sessionID(const uint32_t &value);

  bool *connected();
  const bool *connected() const;
  void set_connected(const bool &value);

  kiwi::String *name();
  const kiwi::String *name() const;
  void set_name(const kiwi::String &value);

  Color *color();
  const Color *color() const;
  void set_color(Color *value);

  kiwi::String *imageURL();
  const kiwi::String *imageURL() const;
  void set_imageURL(const kiwi::String &value);

  Viewport *viewport();
  const Viewport *viewport() const;
  void set_viewport(Viewport *value);

  Mouse *mouse();
  const Mouse *mouse() const;
  void set_mouse(Mouse *value);

  kiwi::Array<GUID> *selection();
  const kiwi::Array<GUID> *selection() const;
  kiwi::Array<GUID> &set_selection(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<uint32_t> *observing();
  const kiwi::Array<uint32_t> *observing() const;
  kiwi::Array<uint32_t> &set_observing(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::String *deviceName();
  const kiwi::String *deviceName() const;
  void set_deviceName(const kiwi::String &value);

  kiwi::Array<Click> *recentClicks();
  const kiwi::Array<Click> *recentClicks() const;
  kiwi::Array<Click> &set_recentClicks(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<ScrollPosition> *scrollPositions();
  const kiwi::Array<ScrollPosition> *scrollPositions() const;
  kiwi::Array<ScrollPosition> &set_scrollPositions(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::String *userID();
  const kiwi::String *userID() const;
  void set_userID(const kiwi::String &value);

  GUID *lastTriggeredHotspot();
  const GUID *lastTriggeredHotspot() const;
  void set_lastTriggeredHotspot(GUID *value);

  GUID *lastTriggeredPrototypeInteractionID();
  const GUID *lastTriggeredPrototypeInteractionID() const;
  void set_lastTriggeredPrototypeInteractionID(GUID *value);

  kiwi::Array<TriggeredOverlayData> *triggeredOverlaysData();
  const kiwi::Array<TriggeredOverlayData> *triggeredOverlaysData() const;
  kiwi::Array<TriggeredOverlayData> &set_triggeredOverlaysData(kiwi::MemoryPool &pool, uint32_t count);

  Spotlight *spotlight();
  const Spotlight *spotlight() const;
  void set_spotlight(Spotlight *value);

  GUID *lastTriggeredFlowStartPointId();
  const GUID *lastTriggeredFlowStartPointId() const;
  void set_lastTriggeredFlowStartPointId(GUID *value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::String _data_name = {};
  Color *_data_color = {};
  kiwi::String _data_imageURL = {};
  Viewport *_data_viewport = {};
  Mouse *_data_mouse = {};
  kiwi::Array<GUID> _data_selection = {};
  kiwi::Array<uint32_t> _data_observing = {};
  kiwi::String _data_deviceName = {};
  kiwi::Array<Click> _data_recentClicks = {};
  kiwi::Array<ScrollPosition> _data_scrollPositions = {};
  kiwi::String _data_userID = {};
  GUID *_data_lastTriggeredHotspot = {};
  GUID *_data_lastTriggeredPrototypeInteractionID = {};
  kiwi::Array<TriggeredOverlayData> _data_triggeredOverlaysData = {};
  Spotlight *_data_spotlight = {};
  GUID *_data_lastTriggeredFlowStartPointId = {};
  uint32_t _data_sessionID = {};
  bool _data_connected = {};
};

class Viewport {
public:
  Viewport() { (void)_flags; }

  Rect *canvasSpaceBounds();
  const Rect *canvasSpaceBounds() const;
  void set_canvasSpaceBounds(Rect *value);

  bool *pixelPreview();
  const bool *pixelPreview() const;
  void set_pixelPreview(const bool &value);

  float *pixelDensity();
  const float *pixelDensity() const;
  void set_pixelDensity(const float &value);

  GUID *canvasGuid();
  const GUID *canvasGuid() const;
  void set_canvasGuid(GUID *value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  Rect *_data_canvasSpaceBounds = {};
  GUID *_data_canvasGuid = {};
  float _data_pixelDensity = {};
  bool _data_pixelPreview = {};
};

class Mouse {
public:
  Mouse() { (void)_flags; }

  MouseCursor *cursor();
  const MouseCursor *cursor() const;
  void set_cursor(const MouseCursor &value);

  Vector *canvasSpaceLocation();
  const Vector *canvasSpaceLocation() const;
  void set_canvasSpaceLocation(Vector *value);

  Rect *canvasSpaceSelectionBox();
  const Rect *canvasSpaceSelectionBox() const;
  void set_canvasSpaceSelectionBox(Rect *value);

  GUID *canvasGuid();
  const GUID *canvasGuid() const;
  void set_canvasGuid(GUID *value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  MouseCursor _data_cursor = {};
  Vector *_data_canvasSpaceLocation = {};
  Rect *_data_canvasSpaceSelectionBox = {};
  GUID *_data_canvasGuid = {};
};

class Click {
public:
  Click() { (void)_flags; }

  uint32_t *id();
  const uint32_t *id() const;
  void set_id(const uint32_t &value);

  Vector *point();
  const Vector *point() const;
  void set_point(Vector *value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  Vector *_data_point = {};
  uint32_t _data_id = {};
};

class ScrollPosition {
public:
  ScrollPosition() { (void)_flags; }

  GUID *node();
  const GUID *node() const;
  void set_node(GUID *value);

  Vector *scrollOffset();
  const Vector *scrollOffset() const;
  void set_scrollOffset(Vector *value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  GUID *_data_node = {};
  Vector *_data_scrollOffset = {};
};

class TriggeredOverlayData {
public:
  TriggeredOverlayData() { (void)_flags; }

  GUID *overlayGuid();
  const GUID *overlayGuid() const;
  void set_overlayGuid(GUID *value);

  GUID *hotspotGuid();
  const GUID *hotspotGuid() const;
  void set_hotspotGuid(GUID *value);

  GUID *swapGuid();
  const GUID *swapGuid() const;
  void set_swapGuid(GUID *value);

  GUID *prototypeInteractionGuid();
  const GUID *prototypeInteractionGuid() const;
  void set_prototypeInteractionGuid(GUID *value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  GUID *_data_overlayGuid = {};
  GUID *_data_hotspotGuid = {};
  GUID *_data_swapGuid = {};
  GUID *_data_prototypeInteractionGuid = {};
};

class Hyperlink {
public:
  Hyperlink() { (void)_flags; }

  kiwi::String *url();
  const kiwi::String *url() const;
  void set_url(const kiwi::String &value);

  GUID *guid();
  const GUID *guid() const;
  void set_guid(GUID *value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::String _data_url = {};
  GUID *_data_guid = {};
};

class SharedStyleMasterData {
public:
  SharedStyleMasterData() { (void)_flags; }

  kiwi::String *styleKey();
  const kiwi::String *styleKey() const;
  void set_styleKey(const kiwi::String &value);

  kiwi::String *sortPosition();
  const kiwi::String *sortPosition() const;
  void set_sortPosition(const kiwi::String &value);

  kiwi::String *fileKey();
  const kiwi::String *fileKey() const;
  void set_fileKey(const kiwi::String &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::String _data_styleKey = {};
  kiwi::String _data_sortPosition = {};
  kiwi::String _data_fileKey = {};
};

class SharedStyleReference {
public:
  SharedStyleReference() { (void)_flags; }

  kiwi::String *styleKey();
  const kiwi::String *styleKey() const;
  void set_styleKey(const kiwi::String &value);

  kiwi::String *versionHash();
  const kiwi::String *versionHash() const;
  void set_versionHash(const kiwi::String &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::String _data_styleKey = {};
  kiwi::String _data_versionHash = {};
};

class PixsoMsg {
public:
  PixsoMsg() { (void)_flags; }

  PixsoMsgType *type();
  const PixsoMsgType *type() const;
  void set_type(const PixsoMsgType &value);

  int32_t *sessionID();
  const int32_t *sessionID() const;
  void set_sessionID(const int32_t &value);

  kiwi::Array<PixsoNode> *pixsoNodes();
  const kiwi::Array<PixsoNode> *pixsoNodes() const;
  kiwi::Array<PixsoNode> &set_pixsoNodes(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<Blob> *blobs();
  const kiwi::Array<Blob> *blobs() const;
  kiwi::Array<Blob> &set_blobs(kiwi::MemoryPool &pool, uint32_t count);

  int32_t *ackID();
  const int32_t *ackID() const;
  void set_ackID(const int32_t &value);

  kiwi::Array<UserInfo> *userInfos();
  const kiwi::Array<UserInfo> *userInfos() const;
  kiwi::Array<UserInfo> &set_userInfos(kiwi::MemoryPool &pool, uint32_t count);

  Access *access();
  const Access *access() const;
  void set_access(const Access &value);

  uint32_t *fileVersion();
  const uint32_t *fileVersion() const;
  void set_fileVersion(const uint32_t &value);

  kiwi::String *styleSetName();
  const kiwi::String *styleSetName() const;
  void set_styleSetName(const kiwi::String &value);

  StyleSetType *styleSetType();
  const StyleSetType *styleSetType() const;
  void set_styleSetType(const StyleSetType &value);

  StyleSetContentType *styleSetContentType();
  const StyleSetContentType *styleSetContentType() const;
  void set_styleSetContentType(const StyleSetContentType &value);

  GUID *pastePageId();
  const GUID *pastePageId() const;
  void set_pastePageId(GUID *value);

  kiwi::Array<SceneGraphQuery> *sceneGraphQueries();
  const kiwi::Array<SceneGraphQuery> *sceneGraphQueries() const;
  kiwi::Array<SceneGraphQuery> &set_sceneGraphQueries(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::String *signalName();
  const kiwi::String *signalName() const;
  void set_signalName(const kiwi::String &value);

  kiwi::String *signalPayload();
  const kiwi::String *signalPayload() const;
  void set_signalPayload(const kiwi::String &value);

  kiwi::String *createVersion();
  const kiwi::String *createVersion() const;
  void set_createVersion(const kiwi::String &value);

  kiwi::String *lastOpenVersion();
  const kiwi::String *lastOpenVersion() const;
  void set_lastOpenVersion(const kiwi::String &value);

  CommandNum *cmdNum();
  const CommandNum *cmdNum() const;
  void set_cmdNum(CommandNum *value);

  FileMeta *fileMeta();
  const FileMeta *fileMeta() const;
  void set_fileMeta(FileMeta *value);

  kiwi::String *pasteFileKey();
  const kiwi::String *pasteFileKey() const;
  void set_pasteFileKey(const kiwi::String &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  PixsoMsgType _data_type = {};
  kiwi::Array<PixsoNode> _data_pixsoNodes = {};
  kiwi::Array<Blob> _data_blobs = {};
  kiwi::Array<UserInfo> _data_userInfos = {};
  Access _data_access = {};
  kiwi::String _data_styleSetName = {};
  StyleSetType _data_styleSetType = {};
  StyleSetContentType _data_styleSetContentType = {};
  GUID *_data_pastePageId = {};
  kiwi::Array<SceneGraphQuery> _data_sceneGraphQueries = {};
  kiwi::String _data_signalName = {};
  kiwi::String _data_signalPayload = {};
  kiwi::String _data_createVersion = {};
  kiwi::String _data_lastOpenVersion = {};
  CommandNum *_data_cmdNum = {};
  FileMeta *_data_fileMeta = {};
  kiwi::String _data_pasteFileKey = {};
  int32_t _data_sessionID = {};
  int32_t _data_ackID = {};
  uint32_t _data_fileVersion = {};
};

class VectorStyleData {
public:
  VectorStyleData() { (void)_flags; }

  int32_t *styleID();
  const int32_t *styleID() const;
  void set_styleID(const int32_t &value);

  float *cornerRadius();
  const float *cornerRadius() const;
  void set_cornerRadius(const float &value);

  StrokeCap *strokeCap();
  const StrokeCap *strokeCap() const;
  void set_strokeCap(const StrokeCap &value);

  StrokeJoin *strokeJoin();
  const StrokeJoin *strokeJoin() const;
  void set_strokeJoin(const StrokeJoin &value);

  VectorMirror *handleMirroring();
  const VectorMirror *handleMirroring() const;
  void set_handleMirroring(const VectorMirror &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  StrokeCap _data_strokeCap = {};
  StrokeJoin _data_strokeJoin = {};
  VectorMirror _data_handleMirroring = {};
  int32_t _data_styleID = {};
  float _data_cornerRadius = {};
};

class TextStyleData {
public:
  TextStyleData() { (void)_flags; }

  int32_t *styleID();
  const int32_t *styleID() const;
  void set_styleID(const int32_t &value);

  float *fontSize();
  const float *fontSize() const;
  void set_fontSize(const float &value);

  float *paragraphIndent();
  const float *paragraphIndent() const;
  void set_paragraphIndent(const float &value);

  float *paragraphSpacing();
  const float *paragraphSpacing() const;
  void set_paragraphSpacing(const float &value);

  Number *letterSpacing();
  const Number *letterSpacing() const;
  void set_letterSpacing(Number *value);

  Number *lineHeight();
  const Number *lineHeight() const;
  void set_lineHeight(Number *value);

  TextCase *textCase();
  const TextCase *textCase() const;
  void set_textCase(const TextCase &value);

  TextDecoration *textDecoration();
  const TextDecoration *textDecoration() const;
  void set_textDecoration(const TextDecoration &value);

  TextAlignHorizontal *textAlignHorizontal();
  const TextAlignHorizontal *textAlignHorizontal() const;
  void set_textAlignHorizontal(const TextAlignHorizontal &value);

  TextAlignVertical *textAlignVertical();
  const TextAlignVertical *textAlignVertical() const;
  void set_textAlignVertical(const TextAlignVertical &value);

  TextAutoResize *textAutoResize();
  const TextAutoResize *textAutoResize() const;
  void set_textAutoResize(const TextAutoResize &value);

  FontName *fontName();
  const FontName *fontName() const;
  void set_fontName(FontName *value);

  Hyperlink *hyperlink();
  const Hyperlink *hyperlink() const;
  void set_hyperlink(Hyperlink *value);

  kiwi::Array<Paint> *fillPaints();
  const kiwi::Array<Paint> *fillPaints() const;
  kiwi::Array<Paint> &set_fillPaints(kiwi::MemoryPool &pool, uint32_t count);

  GUID *inheritFillStyleID();
  const GUID *inheritFillStyleID() const;
  void set_inheritFillStyleID(GUID *value);

  GUID *inheritTextStyleID();
  const GUID *inheritTextStyleID() const;
  void set_inheritTextStyleID(GUID *value);

  FontVariantNumericFigure *fontVariantNumericFigure();
  const FontVariantNumericFigure *fontVariantNumericFigure() const;
  void set_fontVariantNumericFigure(const FontVariantNumericFigure &value);

  FontVariantNumericSpacing *fontVariantNumericSpacing();
  const FontVariantNumericSpacing *fontVariantNumericSpacing() const;
  void set_fontVariantNumericSpacing(const FontVariantNumericSpacing &value);

  FontVariantNumericFraction *fontVariantNumericFraction();
  const FontVariantNumericFraction *fontVariantNumericFraction() const;
  void set_fontVariantNumericFraction(const FontVariantNumericFraction &value);

  FontVariantPosition *fontVariantPosition();
  const FontVariantPosition *fontVariantPosition() const;
  void set_fontVariantPosition(const FontVariantPosition &value);

  kiwi::Array<OpenTypeFeature> *toggledOnOTFeatures();
  const kiwi::Array<OpenTypeFeature> *toggledOnOTFeatures() const;
  kiwi::Array<OpenTypeFeature> &set_toggledOnOTFeatures(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<OpenTypeFeature> *toggledOffOTFeatures();
  const kiwi::Array<OpenTypeFeature> *toggledOffOTFeatures() const;
  kiwi::Array<OpenTypeFeature> &set_toggledOffOTFeatures(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<FontVariation> *fontVariations();
  const kiwi::Array<FontVariation> *fontVariations() const;
  kiwi::Array<FontVariation> &set_fontVariations(kiwi::MemoryPool &pool, uint32_t count);

  bool *detachOpticalSizeFromFontSize();
  const bool *detachOpticalSizeFromFontSize() const;
  void set_detachOpticalSizeFromFontSize(const bool &value);

  VariableDataMap *variableConsumptionMap();
  const VariableDataMap *variableConsumptionMap() const;
  void set_variableConsumptionMap(VariableDataMap *value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  Number *_data_letterSpacing = {};
  Number *_data_lineHeight = {};
  TextCase _data_textCase = {};
  TextDecoration _data_textDecoration = {};
  TextAlignHorizontal _data_textAlignHorizontal = {};
  TextAlignVertical _data_textAlignVertical = {};
  TextAutoResize _data_textAutoResize = {};
  FontName *_data_fontName = {};
  Hyperlink *_data_hyperlink = {};
  kiwi::Array<Paint> _data_fillPaints = {};
  GUID *_data_inheritFillStyleID = {};
  GUID *_data_inheritTextStyleID = {};
  FontVariantNumericFigure _data_fontVariantNumericFigure = {};
  FontVariantNumericSpacing _data_fontVariantNumericSpacing = {};
  FontVariantNumericFraction _data_fontVariantNumericFraction = {};
  FontVariantPosition _data_fontVariantPosition = {};
  kiwi::Array<OpenTypeFeature> _data_toggledOnOTFeatures = {};
  kiwi::Array<OpenTypeFeature> _data_toggledOffOTFeatures = {};
  kiwi::Array<FontVariation> _data_fontVariations = {};
  VariableDataMap *_data_variableConsumptionMap = {};
  int32_t _data_styleID = {};
  float _data_fontSize = {};
  float _data_paragraphIndent = {};
  float _data_paragraphSpacing = {};
  bool _data_detachOpticalSizeFromFontSize = {};
};

class PropValueData {
public:
  PropValueData() { (void)_flags; }

  kiwi::String *property();
  const kiwi::String *property() const;
  void set_property(const kiwi::String &value);

  kiwi::Array<kiwi::String> *values();
  const kiwi::Array<kiwi::String> *values() const;
  kiwi::Array<kiwi::String> &set_values(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::String *aliasProperty();
  const kiwi::String *aliasProperty() const;
  void set_aliasProperty(const kiwi::String &value);

  kiwi::Array<kiwi::String> *aliasValues();
  const kiwi::Array<kiwi::String> *aliasValues() const;
  kiwi::Array<kiwi::String> &set_aliasValues(kiwi::MemoryPool &pool, uint32_t count);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::String _data_property = {};
  kiwi::Array<kiwi::String> _data_values = {};
  kiwi::String _data_aliasProperty = {};
  kiwi::Array<kiwi::String> _data_aliasValues = {};
};

class SceneGraphQuery {
public:
  SceneGraphQuery() { (void)_flags; }

  int32_t *depth();
  const int32_t *depth() const;
  void set_depth(const int32_t &value);

  GUID *startingNode();
  const GUID *startingNode() const;
  void set_startingNode(GUID *value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  GUID *_data_startingNode = {};
  int32_t _data_depth = {};
};

class PrototypeStartPoint {
public:
  PrototypeStartPoint() { (void)_flags; }

  kiwi::String *description();
  const kiwi::String *description() const;
  void set_description(const kiwi::String &value);

  kiwi::String *name();
  const kiwi::String *name() const;
  void set_name(const kiwi::String &value);

  kiwi::String *position();
  const kiwi::String *position() const;
  void set_position(const kiwi::String &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::String _data_description = {};
  kiwi::String _data_name = {};
  kiwi::String _data_position = {};
};

class ConnectLineInfo {
public:
  ConnectLineInfo() { (void)_flags; }

  ConnectLineType *connlineType();
  const ConnectLineType *connlineType() const;
  void set_connlineType(const ConnectLineType &value);

  bool *isFree();
  const bool *isFree() const;
  void set_isFree(const bool &value);

  kiwi::Array<GUID> *connlineSnapObj();
  const kiwi::Array<GUID> *connlineSnapObj() const;
  kiwi::Array<GUID> &set_connlineSnapObj(kiwi::MemoryPool &pool, uint32_t count);

  ConnLineTextAngleType *textAngleType();
  const ConnLineTextAngleType *textAngleType() const;
  void set_textAngleType(const ConnLineTextAngleType &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  ConnectLineType _data_connlineType = {};
  kiwi::Array<GUID> _data_connlineSnapObj = {};
  ConnLineTextAngleType _data_textAngleType = {};
  bool _data_isFree = {};
};

class ObjSnapConnline {
public:
  ObjSnapConnline() { (void)_flags; }

  GUID *guid();
  const GUID *guid() const;
  void set_guid(GUID *value);

  ConnectPointType *connectPointType();
  const ConnectPointType *connectPointType() const;
  void set_connectPointType(const ConnectPointType &value);

  SnapToObjType *snapToObjType();
  const SnapToObjType *snapToObjType() const;
  void set_snapToObjType(const SnapToObjType &value);

  Vector *rate();
  const Vector *rate() const;
  void set_rate(Vector *value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  GUID *_data_guid = {};
  ConnectPointType _data_connectPointType = {};
  SnapToObjType _data_snapToObjType = {};
  Vector *_data_rate = {};
};

class ConnlineTextInfo {
public:
  ConnlineTextInfo() { (void)_flags; }

  GUID *textGuid();
  const GUID *textGuid() const;
  void set_textGuid(GUID *value);

  float *rate();
  const float *rate() const;
  void set_rate(const float &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  GUID *_data_textGuid = {};
  float _data_rate = {};
};

class VectorPaint {
public:
  VectorPaint() { (void)_flags; }

  int32_t *regionId();
  const int32_t *regionId() const;
  void set_regionId(const int32_t &value);

  kiwi::Array<Paint> *paints();
  const kiwi::Array<Paint> *paints() const;
  kiwi::Array<Paint> &set_paints(kiwi::MemoryPool &pool, uint32_t count);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::Array<Paint> _data_paints = {};
  int32_t _data_regionId = {};
};

class VectorStyle {
public:
  VectorStyle() { (void)_flags; }

  int32_t *regionId();
  const int32_t *regionId() const;
  void set_regionId(const int32_t &value);

  GUID *id();
  const GUID *id() const;
  void set_id(GUID *value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  GUID *_data_id = {};
  int32_t _data_regionId = {};
};

class PluginData {
public:
  PluginData() { (void)_flags; }

  kiwi::String *pluginID();
  const kiwi::String *pluginID() const;
  void set_pluginID(const kiwi::String &value);

  kiwi::String *value();
  const kiwi::String *value() const;
  void set_value(const kiwi::String &value);

  kiwi::String *key();
  const kiwi::String *key() const;
  void set_key(const kiwi::String &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::String _data_pluginID = {};
  kiwi::String _data_value = {};
  kiwi::String _data_key = {};
};

class PluginRelaunchData {
public:
  PluginRelaunchData() { (void)_flags; }

  kiwi::String *pluginID();
  const kiwi::String *pluginID() const;
  void set_pluginID(const kiwi::String &value);

  kiwi::String *message();
  const kiwi::String *message() const;
  void set_message(const kiwi::String &value);

  kiwi::String *command();
  const kiwi::String *command() const;
  void set_command(const kiwi::String &value);

  bool *isDeleted();
  const bool *isDeleted() const;
  void set_isDeleted(const bool &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::String _data_pluginID = {};
  kiwi::String _data_message = {};
  kiwi::String _data_command = {};
  bool _data_isDeleted = {};
};

class PlaceHolder {
public:
  PlaceHolder() { (void)_flags; }

  kiwi::Array<int32_t> *emojiCodePoints();
  const kiwi::Array<int32_t> *emojiCodePoints() const;
  kiwi::Array<int32_t> &set_emojiCodePoints(kiwi::MemoryPool &pool, uint32_t count);

  Rect *bound();
  const Rect *bound() const;
  void set_bound(Rect *value);

  int32_t *firstCharacter();
  const int32_t *firstCharacter() const;
  void set_firstCharacter(const int32_t &value);

  GlyphPose *pose();
  const GlyphPose *pose() const;
  void set_pose(GlyphPose *value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::Array<int32_t> _data_emojiCodePoints = {};
  Rect *_data_bound = {};
  GlyphPose *_data_pose = {};
  int32_t _data_firstCharacter = {};
};

class Spotlight {
public:
  Spotlight() { (void)_flags; }

  uint32_t *sessionID();
  const uint32_t *sessionID() const;
  void set_sessionID(const uint32_t &value);

  kiwi::String *userID();
  const kiwi::String *userID() const;
  void set_userID(const kiwi::String &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::String _data_userID = {};
  uint32_t _data_sessionID = {};
};

class FileMeta {
public:
  FileMeta() { (void)_flags; }

  FileSource *fileSource();
  const FileSource *fileSource() const;
  void set_fileSource(const FileSource &value);

  FontIncorrect *fontIncorrect();
  const FontIncorrect *fontIncorrect() const;
  void set_fontIncorrect(const FontIncorrect &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  FileSource _data_fileSource = {};
  FontIncorrect _data_fontIncorrect = {};
};

class EditInfo {
public:
  EditInfo() { (void)_flags; }

  kiwi::String *userID();
  const kiwi::String *userID() const;
  void set_userID(const kiwi::String &value);

  uint32_t *lastEditedAt();
  const uint32_t *lastEditedAt() const;
  void set_lastEditedAt(const uint32_t &value);

  uint32_t *createAt();
  const uint32_t *createAt() const;
  void set_createAt(const uint32_t &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::String _data_userID = {};
  uint32_t _data_lastEditedAt = {};
  uint32_t _data_createAt = {};
};

class SymbolLink {
public:
  SymbolLink() { (void)_flags; }

  kiwi::String *uri();
  const kiwi::String *uri() const;
  void set_uri(const kiwi::String &value);

  kiwi::String *displayName();
  const kiwi::String *displayName() const;
  void set_displayName(const kiwi::String &value);

  kiwi::String *displayText();
  const kiwi::String *displayText() const;
  void set_displayText(const kiwi::String &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::String _data_uri = {};
  kiwi::String _data_displayName = {};
  kiwi::String _data_displayText = {};
};

class DeveloperRelatedLink {
public:
  DeveloperRelatedLink() { (void)_flags; }

  kiwi::String *linkName();
  const kiwi::String *linkName() const;
  void set_linkName(const kiwi::String &value);

  kiwi::String *linkUrl();
  const kiwi::String *linkUrl() const;
  void set_linkUrl(const kiwi::String &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::String _data_linkName = {};
  kiwi::String _data_linkUrl = {};
};

class FontVariation {
public:
  FontVariation() { (void)_flags; }

  uint32_t *axisTag();
  const uint32_t *axisTag() const;
  void set_axisTag(const uint32_t &value);

  kiwi::String *axisName();
  const kiwi::String *axisName() const;
  void set_axisName(const kiwi::String &value);

  float *value();
  const float *value() const;
  void set_value(const float &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::String _data_axisName = {};
  uint32_t _data_axisTag = {};
  float _data_value = {};
};

class PathTextInfo {
public:
  PathTextInfo() { (void)_flags; }

  bool *flipGlyphs();
  const bool *flipGlyphs() const;
  void set_flipGlyphs(const bool &value);

  bool *reverse();
  const bool *reverse() const;
  void set_reverse(const bool &value);

  float *hOffset();
  const float *hOffset() const;
  void set_hOffset(const float &value);

  float *vOffset();
  const float *vOffset() const;
  void set_vOffset(const float &value);

  float *tValue();
  const float *tValue() const;
  void set_tValue(const float &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  float _data_hOffset = {};
  float _data_vOffset = {};
  float _data_tValue = {};
  bool _data_flipGlyphs = {};
  bool _data_reverse = {};
};

class GlyphPose {
public:
  GlyphPose() { (void)_flags; }

  float *x();
  const float *x() const;
  void set_x(const float &value);

  float *y();
  const float *y() const;
  void set_y(const float &value);

  float *angle();
  const float *angle() const;
  void set_angle(const float &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  float _data_x = {};
  float _data_y = {};
  float _data_angle = {};
};

class RadialRepeatData {
public:
  RadialRepeatData() { (void)_flags; }

  int32_t *copies();
  const int32_t *copies() const;
  void set_copies(const int32_t &value);

  float *radius();
  const float *radius() const;
  void set_radius(const float &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  int32_t _data_copies = {};
  float _data_radius = {};
};

class TransformModifier {
public:
  TransformModifier() { (void)_flags; }

  TransformModifierType *type();
  const TransformModifierType *type() const;
  void set_type(const TransformModifierType &value);

  Vector *offset();
  const Vector *offset() const;
  void set_offset(Vector *value);

  bool *visible();
  const bool *visible() const;
  void set_visible(const bool &value);

  uint32_t *count();
  const uint32_t *count() const;
  void set_count(const uint32_t &value);

  RepeatType *repeatType();
  const RepeatType *repeatType() const;
  void set_repeatType(const RepeatType &value);

  Axis *axis();
  const Axis *axis() const;
  void set_axis(const Axis &value);

  UnitType *unitType();
  const UnitType *unitType() const;
  void set_unitType(const UnitType &value);

  RepeatOrder *order();
  const RepeatOrder *order() const;
  void set_order(const RepeatOrder &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  TransformModifierType _data_type = {};
  Vector *_data_offset = {};
  RepeatType _data_repeatType = {};
  Axis _data_axis = {};
  UnitType _data_unitType = {};
  RepeatOrder _data_order = {};
  uint32_t _data_count = {};
  bool _data_visible = {};
};

class AssetID {
public:
  AssetID() { (void)_flags; }

  GUID *guid();
  const GUID *guid() const;
  void set_guid(GUID *value);

  AssetRef *assetRef();
  const AssetRef *assetRef() const;
  void set_assetRef(AssetRef *value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  GUID *_data_guid = {};
  AssetRef *_data_assetRef = {};
};

class VariableSetMode {
public:
  VariableSetMode() { (void)_flags; }

  GUID *id();
  const GUID *id() const;
  void set_id(GUID *value);

  kiwi::String *name();
  const kiwi::String *name() const;
  void set_name(const kiwi::String &value);

  kiwi::String *sortPosition();
  const kiwi::String *sortPosition() const;
  void set_sortPosition(const kiwi::String &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  GUID *_data_id = {};
  kiwi::String _data_name = {};
  kiwi::String _data_sortPosition = {};
};

class VariableDataValues {
public:
  VariableDataValues() { (void)_flags; }

  kiwi::Array<VariableDataValuesEntry> *entries();
  const kiwi::Array<VariableDataValuesEntry> *entries() const;
  kiwi::Array<VariableDataValuesEntry> &set_entries(kiwi::MemoryPool &pool, uint32_t count);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::Array<VariableDataValuesEntry> _data_entries = {};
};

class VariableDataValuesEntry {
public:
  VariableDataValuesEntry() { (void)_flags; }

  GUID *modeID();
  const GUID *modeID() const;
  void set_modeID(GUID *value);

  VariableData *variableData();
  const VariableData *variableData() const;
  void set_variableData(VariableData *value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  GUID *_data_modeID = {};
  VariableData *_data_variableData = {};
};

class VariableDataMap {
public:
  VariableDataMap() { (void)_flags; }

  kiwi::Array<VariableDataMapEntry> *entries();
  const kiwi::Array<VariableDataMapEntry> *entries() const;
  kiwi::Array<VariableDataMapEntry> &set_entries(kiwi::MemoryPool &pool, uint32_t count);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::Array<VariableDataMapEntry> _data_entries = {};
};

class VariableDataMapEntry {
public:
  VariableDataMapEntry() { (void)_flags; }

  uint32_t *nodeField();
  const uint32_t *nodeField() const;
  void set_nodeField(const uint32_t &value);

  VariableData *variableData();
  const VariableData *variableData() const;
  void set_variableData(VariableData *value);

  VariableField *variableField();
  const VariableField *variableField() const;
  void set_variableField(const VariableField &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  VariableData *_data_variableData = {};
  VariableField _data_variableField = {};
  uint32_t _data_nodeField = {};
};

class VariableData {
public:
  VariableData() { (void)_flags; }

  VariableAnyValue *value();
  const VariableAnyValue *value() const;
  void set_value(VariableAnyValue *value);

  VariableDataType *dataType();
  const VariableDataType *dataType() const;
  void set_dataType(const VariableDataType &value);

  VariableResolvedDataType *resolvedDataType();
  const VariableResolvedDataType *resolvedDataType() const;
  void set_resolvedDataType(const VariableResolvedDataType &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  VariableAnyValue *_data_value = {};
  VariableDataType _data_dataType = {};
  VariableResolvedDataType _data_resolvedDataType = {};
};

class VariableAnyValue {
public:
  VariableAnyValue() { (void)_flags; }

  bool *boolValue();
  const bool *boolValue() const;
  void set_boolValue(const bool &value);

  kiwi::String *textValue();
  const kiwi::String *textValue() const;
  void set_textValue(const kiwi::String &value);

  float *floatValue();
  const float *floatValue() const;
  void set_floatValue(const float &value);

  AssetID *alias();
  const AssetID *alias() const;
  void set_alias(AssetID *value);

  Color *colorValue();
  const Color *colorValue() const;
  void set_colorValue(Color *value);

  Expression *expressionValue();
  const Expression *expressionValue() const;
  void set_expressionValue(Expression *value);

  VariableMap *mapValue();
  const VariableMap *mapValue() const;
  void set_mapValue(VariableMap *value);

  AssetID *symbolIdValue();
  const AssetID *symbolIdValue() const;
  void set_symbolIdValue(AssetID *value);

  VariableFontStyle *fontStyleValue();
  const VariableFontStyle *fontStyleValue() const;
  void set_fontStyleValue(VariableFontStyle *value);

  TextData *textDataValue();
  const TextData *textDataValue() const;
  void set_textDataValue(TextData *value);

  NodeFieldAlias *nodeFieldAliasValue();
  const NodeFieldAlias *nodeFieldAliasValue() const;
  void set_nodeFieldAliasValue(NodeFieldAlias *value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::String _data_textValue = {};
  AssetID *_data_alias = {};
  Color *_data_colorValue = {};
  Expression *_data_expressionValue = {};
  VariableMap *_data_mapValue = {};
  AssetID *_data_symbolIdValue = {};
  VariableFontStyle *_data_fontStyleValue = {};
  TextData *_data_textDataValue = {};
  NodeFieldAlias *_data_nodeFieldAliasValue = {};
  float _data_floatValue = {};
  bool _data_boolValue = {};
};

class Expression {
public:
  Expression() { (void)_flags; }

  ExpressionFunction *expressionFunction();
  const ExpressionFunction *expressionFunction() const;
  void set_expressionFunction(const ExpressionFunction &value);

  kiwi::Array<VariableData> *expressionArguments();
  const kiwi::Array<VariableData> *expressionArguments() const;
  kiwi::Array<VariableData> &set_expressionArguments(kiwi::MemoryPool &pool, uint32_t count);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  ExpressionFunction _data_expressionFunction = {};
  kiwi::Array<VariableData> _data_expressionArguments = {};
};

class AssetRef {
public:
  AssetRef() { (void)_flags; }

  kiwi::String *key();
  const kiwi::String *key() const;
  void set_key(const kiwi::String &value);

  kiwi::String *version();
  const kiwi::String *version() const;
  void set_version(const kiwi::String &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::String _data_key = {};
  kiwi::String _data_version = {};
};

class VariableFontStyle {
public:
  VariableFontStyle() { (void)_flags; }

  VariableData *asString();
  const VariableData *asString() const;
  void set_asString(VariableData *value);

  VariableData *asFloat();
  const VariableData *asFloat() const;
  void set_asFloat(VariableData *value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  VariableData *_data_asString = {};
  VariableData *_data_asFloat = {};
};

class VariableMap {
public:
  VariableMap() { (void)_flags; }

  kiwi::Array<VariableMapValue> *values();
  const kiwi::Array<VariableMapValue> *values() const;
  kiwi::Array<VariableMapValue> &set_values(kiwi::MemoryPool &pool, uint32_t count);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::Array<VariableMapValue> _data_values = {};
};

class ColorStopVar {
public:
  ColorStopVar() { (void)_flags; }

  Color *color();
  const Color *color() const;
  void set_color(Color *value);

  VariableData *colorVar();
  const VariableData *colorVar() const;
  void set_colorVar(VariableData *value);

  float *position();
  const float *position() const;
  void set_position(const float &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  Color *_data_color = {};
  VariableData *_data_colorVar = {};
  float _data_position = {};
};

class VariableModeBySetMap {
public:
  VariableModeBySetMap() { (void)_flags; }

  kiwi::Array<VariableModeBySetMapEntry> *entries();
  const kiwi::Array<VariableModeBySetMapEntry> *entries() const;
  kiwi::Array<VariableModeBySetMapEntry> &set_entries(kiwi::MemoryPool &pool, uint32_t count);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::Array<VariableModeBySetMapEntry> _data_entries = {};
};

class VariableModeBySetMapEntry {
public:
  VariableModeBySetMapEntry() { (void)_flags; }

  AssetID *variableSetID();
  const AssetID *variableSetID() const;
  void set_variableSetID(AssetID *value);

  GUID *variableModeID();
  const GUID *variableModeID() const;
  void set_variableModeID(GUID *value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  AssetID *_data_variableSetID = {};
  GUID *_data_variableModeID = {};
};

class VariableMapValue {
public:
  VariableMapValue() { (void)_flags; }

  kiwi::String *key();
  const kiwi::String *key() const;
  void set_key(const kiwi::String &value);

  VariableData *value();
  const VariableData *value() const;
  void set_value(VariableData *value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::String _data_key = {};
  VariableData *_data_value = {};
};

class VariableIdOrVariableOverrideId {
public:
  VariableIdOrVariableOverrideId() { (void)_flags; }

  AssetID *variableId();
  const AssetID *variableId() const;
  void set_variableId(AssetID *value);

  VariableOverrideId *variableOverrideId();
  const VariableOverrideId *variableOverrideId() const;
  void set_variableOverrideId(VariableOverrideId *value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  AssetID *_data_variableId = {};
  VariableOverrideId *_data_variableOverrideId = {};
};

class VariableOverrideId {
public:
  VariableOverrideId() { (void)_flags; }

  GUID *guid();
  const GUID *guid() const;
  void set_guid(GUID *value);

  AssetRef *assetRef();
  const AssetRef *assetRef() const;
  void set_assetRef(AssetRef *value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  GUID *_data_guid = {};
  AssetRef *_data_assetRef = {};
};

class PrototypeVariableTarget {
public:
  PrototypeVariableTarget() { (void)_flags; }

  AssetID *id();
  const AssetID *id() const;
  void set_id(AssetID *value);

  NodeFieldAlias *nodeFieldAlias();
  const NodeFieldAlias *nodeFieldAlias() const;
  void set_nodeFieldAlias(NodeFieldAlias *value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  AssetID *_data_id = {};
  NodeFieldAlias *_data_nodeFieldAlias = {};
};

class TriggeredSetVariableActionData {
public:
  TriggeredSetVariableActionData() { (void)_flags; }

  GUID *nodeForFindingTopmostScreenId();
  const GUID *nodeForFindingTopmostScreenId() const;
  void set_nodeForFindingTopmostScreenId(GUID *value);

  kiwi::String *targetVariableId();
  const kiwi::String *targetVariableId() const;
  void set_targetVariableId(const kiwi::String &value);

  kiwi::String *targetVariableData();
  const kiwi::String *targetVariableData() const;
  void set_targetVariableData(const kiwi::String &value);

  kiwi::String *resolvedVariableModes();
  const kiwi::String *resolvedVariableModes() const;
  void set_resolvedVariableModes(const kiwi::String &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  GUID *_data_nodeForFindingTopmostScreenId = {};
  kiwi::String _data_targetVariableId = {};
  kiwi::String _data_targetVariableData = {};
  kiwi::String _data_resolvedVariableModes = {};
};

class TriggeredSetVariableModeActionData {
public:
  TriggeredSetVariableModeActionData() { (void)_flags; }

  GUID *nodeForFindingTopmostScreenId();
  const GUID *nodeForFindingTopmostScreenId() const;
  void set_nodeForFindingTopmostScreenId(GUID *value);

  kiwi::String *targetVariableSetKey();
  const kiwi::String *targetVariableSetKey() const;
  void set_targetVariableSetKey(const kiwi::String &value);

  kiwi::String *targetVariableModeId();
  const kiwi::String *targetVariableModeId() const;
  void set_targetVariableModeId(const kiwi::String &value);

  AssetID *targetVariableSetId();
  const AssetID *targetVariableSetId() const;
  void set_targetVariableSetId(AssetID *value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  GUID *_data_nodeForFindingTopmostScreenId = {};
  kiwi::String _data_targetVariableSetKey = {};
  kiwi::String _data_targetVariableModeId = {};
  AssetID *_data_targetVariableSetId = {};
};

class NodeFieldAlias {
public:
  NodeFieldAlias() { (void)_flags; }

  GUIDPath *stablePathToNode();
  const GUIDPath *stablePathToNode() const;
  void set_stablePathToNode(GUIDPath *value);

  NodeFieldAliasType *nodeField();
  const NodeFieldAliasType *nodeField() const;
  void set_nodeField(const NodeFieldAliasType &value);

  kiwi::String *indexOrKey();
  const kiwi::String *indexOrKey() const;
  void set_indexOrKey(const kiwi::String &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  GUIDPath *_data_stablePathToNode = {};
  NodeFieldAliasType _data_nodeField = {};
  kiwi::String _data_indexOrKey = {};
};

class CodeSyntaxMap {
public:
  CodeSyntaxMap() { (void)_flags; }

  kiwi::Array<CodeSyntaxMapEntry> *entries();
  const kiwi::Array<CodeSyntaxMapEntry> *entries() const;
  kiwi::Array<CodeSyntaxMapEntry> &set_entries(kiwi::MemoryPool &pool, uint32_t count);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::Array<CodeSyntaxMapEntry> _data_entries = {};
};

class CodeSyntaxMapEntry {
public:
  CodeSyntaxMapEntry() { (void)_flags; }

  CodeSyntaxPlatform *platform();
  const CodeSyntaxPlatform *platform() const;
  void set_platform(const CodeSyntaxPlatform &value);

  kiwi::String *value();
  const kiwi::String *value() const;
  void set_value(const kiwi::String &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  CodeSyntaxPlatform _data_platform = {};
  kiwi::String _data_value = {};
};

class DeliverInfo {
public:
  DeliverInfo() { (void)_flags; }

  kiwi::String *publishedVersion();
  const kiwi::String *publishedVersion() const;
  void set_publishedVersion(const kiwi::String &value);

  kiwi::String *currentVersion();
  const kiwi::String *currentVersion() const;
  void set_currentVersion(const kiwi::String &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::String _data_publishedVersion = {};
  kiwi::String _data_currentVersion = {};
};

class AnnotationProperty {
public:
  AnnotationProperty() { (void)_flags; }

  AnnotationPropertyType *type();
  const AnnotationPropertyType *type() const;
  void set_type(const AnnotationPropertyType &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  AnnotationPropertyType _data_type = {};
};

class AnnotationCategoryCustom {
public:
  AnnotationCategoryCustom() { (void)_flags; }

  Color *color();
  const Color *color() const;
  void set_color(Color *value);

  kiwi::String *label();
  const kiwi::String *label() const;
  void set_label(const kiwi::String &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  Color *_data_color = {};
  kiwi::String _data_label = {};
};

class AnnotationCategory {
public:
  AnnotationCategory() { (void)_flags; }

  GUID *id();
  const GUID *id() const;
  void set_id(GUID *value);

  AnnotationCategoryPreset *preset();
  const AnnotationCategoryPreset *preset() const;
  void set_preset(const AnnotationCategoryPreset &value);

  AnnotationCategoryCustom *custom();
  const AnnotationCategoryCustom *custom() const;
  void set_custom(AnnotationCategoryCustom *value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  GUID *_data_id = {};
  AnnotationCategoryPreset _data_preset = {};
  AnnotationCategoryCustom *_data_custom = {};
};

class AnnotationCategories {
public:
  AnnotationCategories() { (void)_flags; }

  kiwi::Array<AnnotationCategory> *items();
  const kiwi::Array<AnnotationCategory> *items() const;
  kiwi::Array<AnnotationCategory> &set_items(kiwi::MemoryPool &pool, uint32_t count);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::Array<AnnotationCategory> _data_items = {};
};

class Annotation {
public:
  Annotation() { (void)_flags; }

  kiwi::String *label();
  const kiwi::String *label() const;
  void set_label(const kiwi::String &value);

  kiwi::Array<AnnotationProperty> *properties();
  const kiwi::Array<AnnotationProperty> *properties() const;
  kiwi::Array<AnnotationProperty> &set_properties(kiwi::MemoryPool &pool, uint32_t count);

  GUID *categoryId();
  const GUID *categoryId() const;
  void set_categoryId(GUID *value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  kiwi::String _data_label = {};
  kiwi::Array<AnnotationProperty> _data_properties = {};
  GUID *_data_categoryId = {};
};

class GUID {
public:
  GUID() { (void)_flags; }

  uint32_t *sessionID();
  const uint32_t *sessionID() const;
  void set_sessionID(const uint32_t &value);

  uint32_t *localID();
  const uint32_t *localID() const;
  void set_localID(const uint32_t &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  uint32_t _data_sessionID = {};
  uint32_t _data_localID = {};
};

class Vector {
public:
  Vector() { (void)_flags; }

  float *x();
  const float *x() const;
  void set_x(const float &value);

  float *y();
  const float *y() const;
  void set_y(const float &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  float _data_x = {};
  float _data_y = {};
};

class Matrix {
public:
  Matrix() { (void)_flags; }

  float *m00();
  const float *m00() const;
  void set_m00(const float &value);

  float *m01();
  const float *m01() const;
  void set_m01(const float &value);

  float *m02();
  const float *m02() const;
  void set_m02(const float &value);

  float *m10();
  const float *m10() const;
  void set_m10(const float &value);

  float *m11();
  const float *m11() const;
  void set_m11(const float &value);

  float *m12();
  const float *m12() const;
  void set_m12(const float &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  float _data_m00 = {};
  float _data_m01 = {};
  float _data_m02 = {};
  float _data_m10 = {};
  float _data_m11 = {};
  float _data_m12 = {};
};

class Matrix3f {
public:
  Matrix3f() { (void)_flags; }

  float *m00();
  const float *m00() const;
  void set_m00(const float &value);

  float *m01();
  const float *m01() const;
  void set_m01(const float &value);

  float *m02();
  const float *m02() const;
  void set_m02(const float &value);

  float *m10();
  const float *m10() const;
  void set_m10(const float &value);

  float *m11();
  const float *m11() const;
  void set_m11(const float &value);

  float *m12();
  const float *m12() const;
  void set_m12(const float &value);

  float *m20();
  const float *m20() const;
  void set_m20(const float &value);

  float *m21();
  const float *m21() const;
  void set_m21(const float &value);

  float *m22();
  const float *m22() const;
  void set_m22(const float &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  float _data_m00 = {};
  float _data_m01 = {};
  float _data_m02 = {};
  float _data_m10 = {};
  float _data_m11 = {};
  float _data_m12 = {};
  float _data_m20 = {};
  float _data_m21 = {};
  float _data_m22 = {};
};

class Color {
public:
  Color() { (void)_flags; }

  float *r();
  const float *r() const;
  void set_r(const float &value);

  float *g();
  const float *g() const;
  void set_g(const float &value);

  float *b();
  const float *b() const;
  void set_b(const float &value);

  float *a();
  const float *a() const;
  void set_a(const float &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  float _data_r = {};
  float _data_g = {};
  float _data_b = {};
  float _data_a = {};
};

class Rect {
public:
  Rect() { (void)_flags; }

  float *x();
  const float *x() const;
  void set_x(const float &value);

  float *y();
  const float *y() const;
  void set_y(const float &value);

  float *w();
  const float *w() const;
  void set_w(const float &value);

  float *h();
  const float *h() const;
  void set_h(const float &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  float _data_x = {};
  float _data_y = {};
  float _data_w = {};
  float _data_h = {};
};

class CommandNum {
public:
  CommandNum() { (void)_flags; }

  uint32_t *round();
  const uint32_t *round() const;
  void set_round(const uint32_t &value);

  uint32_t *count();
  const uint32_t *count() const;
  void set_count(const uint32_t &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  uint32_t _data_round = {};
  uint32_t _data_count = {};
};

#ifdef IMPLEMENT_SCHEMA_H

bool BinarySchema::parse(kiwi::ByteBuffer &bb) {
  if (!_schema.parse(bb)) return false;
  _schema.findDefinition("Paint", _indexPaint);
  _schema.findDefinition("PaintFilterMessage", _indexPaintFilterMessage);
  _schema.findDefinition("ColorStop", _indexColorStop);
  _schema.findDefinition("ImageMessage", _indexImageMessage);
  _schema.findDefinition("Path", _indexPath);
  _schema.findDefinition("GUIDPath", _indexGUIDPath);
  _schema.findDefinition("VectorData", _indexVectorData);
  _schema.findDefinition("ArcData", _indexArcData);
  _schema.findDefinition("Effect", _indexEffect);
  _schema.findDefinition("SymbolData", _indexSymbolData);
  _schema.findDefinition("LayoutGrid", _indexLayoutGrid);
  _schema.findDefinition("GridTrackSizing", _indexGridTrackSizing);
  _schema.findDefinition("ExportConstraint", _indexExportConstraint);
  _schema.findDefinition("ExportSettings", _indexExportSettings);
  _schema.findDefinition("FontName", _indexFontName);
  _schema.findDefinition("TextData", _indexTextData);
  _schema.findDefinition("HyperlinkBox", _indexHyperlinkBox);
  _schema.findDefinition("FontMetaData", _indexFontMetaData);
  _schema.findDefinition("Decoration", _indexDecoration);
  _schema.findDefinition("Glyph", _indexGlyph);
  _schema.findDefinition("ParagraphStyle", _indexParagraphStyle);
  _schema.findDefinition("Baseline", _indexBaseline);
  _schema.findDefinition("KeyTrigger", _indexKeyTrigger);
  _schema.findDefinition("PrototypeDevice", _indexPrototypeDevice);
  _schema.findDefinition("PrototypeInteraction", _indexPrototypeInteraction);
  _schema.findDefinition("ConditionalActions", _indexConditionalActions);
  _schema.findDefinition("VideoPlayback", _indexVideoPlayback);
  _schema.findDefinition("VariableWidthPoint", _indexVariableWidthPoint);
  _schema.findDefinition("PrototypeSelectedState", _indexPrototypeSelectedState);
  _schema.findDefinition("PrototypeStateChange", _indexPrototypeStateChange);
  _schema.findDefinition("PrototypeAction", _indexPrototypeAction);
  _schema.findDefinition("PrototypeEvent", _indexPrototypeEvent);
  _schema.findDefinition("ComponentPropDef", _indexComponentPropDef);
  _schema.findDefinition("ComponentPropRef", _indexComponentPropRef);
  _schema.findDefinition("ComponentPropValue", _indexComponentPropValue);
  _schema.findDefinition("InstanceSwapPreferredValue", _indexInstanceSwapPreferredValue);
  _schema.findDefinition("ComponentPropPreferredValues", _indexComponentPropPreferredValues);
  _schema.findDefinition("ComponentPropAssignment", _indexComponentPropAssignment);
  _schema.findDefinition("Blob", _indexBlob);
  _schema.findDefinition("PixsoNode", _indexPixsoNode);
  _schema.findDefinition("ProdMode", _indexProdMode);
  _schema.findDefinition("BlockMarkerParams", _indexBlockMarkerParams);
  _schema.findDefinition("ProdLayoutParam", _indexProdLayoutParam);
  _schema.findDefinition("ProdLayoutInterval", _indexProdLayoutInterval);
  _schema.findDefinition("ProdAdjustSize", _indexProdAdjustSize);
  _schema.findDefinition("ProdMoving", _indexProdMoving);
  _schema.findDefinition("ProdRotate", _indexProdRotate);
  _schema.findDefinition("ProdTableCell", _indexProdTableCell);
  _schema.findDefinition("ProdTextStyle", _indexProdTextStyle);
  _schema.findDefinition("ProdScoreBar", _indexProdScoreBar);
  _schema.findDefinition("ProdDragBar", _indexProdDragBar);
  _schema.findDefinition("ProdScalingFactor", _indexProdScalingFactor);
  _schema.findDefinition("ProdTDCElementinfo", _indexProdTDCElementinfo);
  _schema.findDefinition("ProdTwoDimChart", _indexProdTwoDimChart);
  _schema.findDefinition("Guide", _indexGuide);
  _schema.findDefinition("OverlayBackgroundAppearance", _indexOverlayBackgroundAppearance);
  _schema.findDefinition("Number", _indexNumber);
  _schema.findDefinition("ParentIndex", _indexParentIndex);
  _schema.findDefinition("UserInfo", _indexUserInfo);
  _schema.findDefinition("Viewport", _indexViewport);
  _schema.findDefinition("Mouse", _indexMouse);
  _schema.findDefinition("Click", _indexClick);
  _schema.findDefinition("ScrollPosition", _indexScrollPosition);
  _schema.findDefinition("TriggeredOverlayData", _indexTriggeredOverlayData);
  _schema.findDefinition("Hyperlink", _indexHyperlink);
  _schema.findDefinition("SharedStyleMasterData", _indexSharedStyleMasterData);
  _schema.findDefinition("SharedStyleReference", _indexSharedStyleReference);
  _schema.findDefinition("PixsoMsg", _indexPixsoMsg);
  _schema.findDefinition("VectorStyleData", _indexVectorStyleData);
  _schema.findDefinition("TextStyleData", _indexTextStyleData);
  _schema.findDefinition("PropValueData", _indexPropValueData);
  _schema.findDefinition("SceneGraphQuery", _indexSceneGraphQuery);
  _schema.findDefinition("PrototypeStartPoint", _indexPrototypeStartPoint);
  _schema.findDefinition("ConnectLineInfo", _indexConnectLineInfo);
  _schema.findDefinition("ObjSnapConnline", _indexObjSnapConnline);
  _schema.findDefinition("ConnlineTextInfo", _indexConnlineTextInfo);
  _schema.findDefinition("VectorPaint", _indexVectorPaint);
  _schema.findDefinition("VectorStyle", _indexVectorStyle);
  _schema.findDefinition("PluginData", _indexPluginData);
  _schema.findDefinition("PluginRelaunchData", _indexPluginRelaunchData);
  _schema.findDefinition("PlaceHolder", _indexPlaceHolder);
  _schema.findDefinition("Spotlight", _indexSpotlight);
  _schema.findDefinition("FileMeta", _indexFileMeta);
  _schema.findDefinition("EditInfo", _indexEditInfo);
  _schema.findDefinition("SymbolLink", _indexSymbolLink);
  _schema.findDefinition("DeveloperRelatedLink", _indexDeveloperRelatedLink);
  _schema.findDefinition("FontVariation", _indexFontVariation);
  _schema.findDefinition("PathTextInfo", _indexPathTextInfo);
  _schema.findDefinition("GlyphPose", _indexGlyphPose);
  _schema.findDefinition("RadialRepeatData", _indexRadialRepeatData);
  _schema.findDefinition("TransformModifier", _indexTransformModifier);
  _schema.findDefinition("AssetID", _indexAssetID);
  _schema.findDefinition("VariableSetMode", _indexVariableSetMode);
  _schema.findDefinition("VariableDataValues", _indexVariableDataValues);
  _schema.findDefinition("VariableDataValuesEntry", _indexVariableDataValuesEntry);
  _schema.findDefinition("VariableDataMap", _indexVariableDataMap);
  _schema.findDefinition("VariableDataMapEntry", _indexVariableDataMapEntry);
  _schema.findDefinition("VariableData", _indexVariableData);
  _schema.findDefinition("VariableAnyValue", _indexVariableAnyValue);
  _schema.findDefinition("Expression", _indexExpression);
  _schema.findDefinition("AssetRef", _indexAssetRef);
  _schema.findDefinition("VariableFontStyle", _indexVariableFontStyle);
  _schema.findDefinition("VariableMap", _indexVariableMap);
  _schema.findDefinition("ColorStopVar", _indexColorStopVar);
  _schema.findDefinition("VariableModeBySetMap", _indexVariableModeBySetMap);
  _schema.findDefinition("VariableModeBySetMapEntry", _indexVariableModeBySetMapEntry);
  _schema.findDefinition("VariableMapValue", _indexVariableMapValue);
  _schema.findDefinition("VariableIdOrVariableOverrideId", _indexVariableIdOrVariableOverrideId);
  _schema.findDefinition("VariableOverrideId", _indexVariableOverrideId);
  _schema.findDefinition("PrototypeVariableTarget", _indexPrototypeVariableTarget);
  _schema.findDefinition("TriggeredSetVariableActionData", _indexTriggeredSetVariableActionData);
  _schema.findDefinition("TriggeredSetVariableModeActionData", _indexTriggeredSetVariableModeActionData);
  _schema.findDefinition("NodeFieldAlias", _indexNodeFieldAlias);
  _schema.findDefinition("CodeSyntaxMap", _indexCodeSyntaxMap);
  _schema.findDefinition("CodeSyntaxMapEntry", _indexCodeSyntaxMapEntry);
  _schema.findDefinition("DeliverInfo", _indexDeliverInfo);
  _schema.findDefinition("AnnotationProperty", _indexAnnotationProperty);
  _schema.findDefinition("AnnotationCategoryCustom", _indexAnnotationCategoryCustom);
  _schema.findDefinition("AnnotationCategory", _indexAnnotationCategory);
  _schema.findDefinition("AnnotationCategories", _indexAnnotationCategories);
  _schema.findDefinition("Annotation", _indexAnnotation);
  return true;
}

bool BinarySchema::skipPaintField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexPaint, id);
}

bool BinarySchema::skipPaintFilterMessageField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexPaintFilterMessage, id);
}

bool BinarySchema::skipColorStopField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexColorStop, id);
}

bool BinarySchema::skipImageMessageField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexImageMessage, id);
}

bool BinarySchema::skipPathField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexPath, id);
}

bool BinarySchema::skipGUIDPathField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexGUIDPath, id);
}

bool BinarySchema::skipVectorDataField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexVectorData, id);
}

bool BinarySchema::skipArcDataField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexArcData, id);
}

bool BinarySchema::skipEffectField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexEffect, id);
}

bool BinarySchema::skipSymbolDataField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexSymbolData, id);
}

bool BinarySchema::skipLayoutGridField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexLayoutGrid, id);
}

bool BinarySchema::skipGridTrackSizingField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexGridTrackSizing, id);
}

bool BinarySchema::skipExportConstraintField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexExportConstraint, id);
}

bool BinarySchema::skipExportSettingsField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexExportSettings, id);
}

bool BinarySchema::skipFontNameField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexFontName, id);
}

bool BinarySchema::skipTextDataField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexTextData, id);
}

bool BinarySchema::skipHyperlinkBoxField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexHyperlinkBox, id);
}

bool BinarySchema::skipFontMetaDataField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexFontMetaData, id);
}

bool BinarySchema::skipDecorationField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexDecoration, id);
}

bool BinarySchema::skipGlyphField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexGlyph, id);
}

bool BinarySchema::skipParagraphStyleField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexParagraphStyle, id);
}

bool BinarySchema::skipBaselineField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexBaseline, id);
}

bool BinarySchema::skipKeyTriggerField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexKeyTrigger, id);
}

bool BinarySchema::skipPrototypeDeviceField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexPrototypeDevice, id);
}

bool BinarySchema::skipPrototypeInteractionField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexPrototypeInteraction, id);
}

bool BinarySchema::skipConditionalActionsField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexConditionalActions, id);
}

bool BinarySchema::skipVideoPlaybackField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexVideoPlayback, id);
}

bool BinarySchema::skipVariableWidthPointField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexVariableWidthPoint, id);
}

bool BinarySchema::skipPrototypeSelectedStateField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexPrototypeSelectedState, id);
}

bool BinarySchema::skipPrototypeStateChangeField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexPrototypeStateChange, id);
}

bool BinarySchema::skipPrototypeActionField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexPrototypeAction, id);
}

bool BinarySchema::skipPrototypeEventField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexPrototypeEvent, id);
}

bool BinarySchema::skipComponentPropDefField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexComponentPropDef, id);
}

bool BinarySchema::skipComponentPropRefField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexComponentPropRef, id);
}

bool BinarySchema::skipComponentPropValueField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexComponentPropValue, id);
}

bool BinarySchema::skipInstanceSwapPreferredValueField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexInstanceSwapPreferredValue, id);
}

bool BinarySchema::skipComponentPropPreferredValuesField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexComponentPropPreferredValues, id);
}

bool BinarySchema::skipComponentPropAssignmentField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexComponentPropAssignment, id);
}

bool BinarySchema::skipBlobField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexBlob, id);
}

bool BinarySchema::skipPixsoNodeField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexPixsoNode, id);
}

bool BinarySchema::skipProdModeField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexProdMode, id);
}

bool BinarySchema::skipBlockMarkerParamsField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexBlockMarkerParams, id);
}

bool BinarySchema::skipProdLayoutParamField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexProdLayoutParam, id);
}

bool BinarySchema::skipProdLayoutIntervalField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexProdLayoutInterval, id);
}

bool BinarySchema::skipProdAdjustSizeField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexProdAdjustSize, id);
}

bool BinarySchema::skipProdMovingField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexProdMoving, id);
}

bool BinarySchema::skipProdRotateField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexProdRotate, id);
}

bool BinarySchema::skipProdTableCellField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexProdTableCell, id);
}

bool BinarySchema::skipProdTextStyleField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexProdTextStyle, id);
}

bool BinarySchema::skipProdScoreBarField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexProdScoreBar, id);
}

bool BinarySchema::skipProdDragBarField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexProdDragBar, id);
}

bool BinarySchema::skipProdScalingFactorField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexProdScalingFactor, id);
}

bool BinarySchema::skipProdTDCElementinfoField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexProdTDCElementinfo, id);
}

bool BinarySchema::skipProdTwoDimChartField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexProdTwoDimChart, id);
}

bool BinarySchema::skipGuideField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexGuide, id);
}

bool BinarySchema::skipOverlayBackgroundAppearanceField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexOverlayBackgroundAppearance, id);
}

bool BinarySchema::skipNumberField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexNumber, id);
}

bool BinarySchema::skipParentIndexField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexParentIndex, id);
}

bool BinarySchema::skipUserInfoField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexUserInfo, id);
}

bool BinarySchema::skipViewportField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexViewport, id);
}

bool BinarySchema::skipMouseField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexMouse, id);
}

bool BinarySchema::skipClickField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexClick, id);
}

bool BinarySchema::skipScrollPositionField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexScrollPosition, id);
}

bool BinarySchema::skipTriggeredOverlayDataField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexTriggeredOverlayData, id);
}

bool BinarySchema::skipHyperlinkField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexHyperlink, id);
}

bool BinarySchema::skipSharedStyleMasterDataField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexSharedStyleMasterData, id);
}

bool BinarySchema::skipSharedStyleReferenceField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexSharedStyleReference, id);
}

bool BinarySchema::skipPixsoMsgField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexPixsoMsg, id);
}

bool BinarySchema::skipVectorStyleDataField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexVectorStyleData, id);
}

bool BinarySchema::skipTextStyleDataField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexTextStyleData, id);
}

bool BinarySchema::skipPropValueDataField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexPropValueData, id);
}

bool BinarySchema::skipSceneGraphQueryField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexSceneGraphQuery, id);
}

bool BinarySchema::skipPrototypeStartPointField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexPrototypeStartPoint, id);
}

bool BinarySchema::skipConnectLineInfoField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexConnectLineInfo, id);
}

bool BinarySchema::skipObjSnapConnlineField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexObjSnapConnline, id);
}

bool BinarySchema::skipConnlineTextInfoField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexConnlineTextInfo, id);
}

bool BinarySchema::skipVectorPaintField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexVectorPaint, id);
}

bool BinarySchema::skipVectorStyleField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexVectorStyle, id);
}

bool BinarySchema::skipPluginDataField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexPluginData, id);
}

bool BinarySchema::skipPluginRelaunchDataField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexPluginRelaunchData, id);
}

bool BinarySchema::skipPlaceHolderField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexPlaceHolder, id);
}

bool BinarySchema::skipSpotlightField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexSpotlight, id);
}

bool BinarySchema::skipFileMetaField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexFileMeta, id);
}

bool BinarySchema::skipEditInfoField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexEditInfo, id);
}

bool BinarySchema::skipSymbolLinkField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexSymbolLink, id);
}

bool BinarySchema::skipDeveloperRelatedLinkField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexDeveloperRelatedLink, id);
}

bool BinarySchema::skipFontVariationField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexFontVariation, id);
}

bool BinarySchema::skipPathTextInfoField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexPathTextInfo, id);
}

bool BinarySchema::skipGlyphPoseField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexGlyphPose, id);
}

bool BinarySchema::skipRadialRepeatDataField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexRadialRepeatData, id);
}

bool BinarySchema::skipTransformModifierField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexTransformModifier, id);
}

bool BinarySchema::skipAssetIDField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexAssetID, id);
}

bool BinarySchema::skipVariableSetModeField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexVariableSetMode, id);
}

bool BinarySchema::skipVariableDataValuesField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexVariableDataValues, id);
}

bool BinarySchema::skipVariableDataValuesEntryField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexVariableDataValuesEntry, id);
}

bool BinarySchema::skipVariableDataMapField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexVariableDataMap, id);
}

bool BinarySchema::skipVariableDataMapEntryField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexVariableDataMapEntry, id);
}

bool BinarySchema::skipVariableDataField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexVariableData, id);
}

bool BinarySchema::skipVariableAnyValueField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexVariableAnyValue, id);
}

bool BinarySchema::skipExpressionField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexExpression, id);
}

bool BinarySchema::skipAssetRefField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexAssetRef, id);
}

bool BinarySchema::skipVariableFontStyleField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexVariableFontStyle, id);
}

bool BinarySchema::skipVariableMapField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexVariableMap, id);
}

bool BinarySchema::skipColorStopVarField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexColorStopVar, id);
}

bool BinarySchema::skipVariableModeBySetMapField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexVariableModeBySetMap, id);
}

bool BinarySchema::skipVariableModeBySetMapEntryField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexVariableModeBySetMapEntry, id);
}

bool BinarySchema::skipVariableMapValueField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexVariableMapValue, id);
}

bool BinarySchema::skipVariableIdOrVariableOverrideIdField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexVariableIdOrVariableOverrideId, id);
}

bool BinarySchema::skipVariableOverrideIdField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexVariableOverrideId, id);
}

bool BinarySchema::skipPrototypeVariableTargetField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexPrototypeVariableTarget, id);
}

bool BinarySchema::skipTriggeredSetVariableActionDataField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexTriggeredSetVariableActionData, id);
}

bool BinarySchema::skipTriggeredSetVariableModeActionDataField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexTriggeredSetVariableModeActionData, id);
}

bool BinarySchema::skipNodeFieldAliasField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexNodeFieldAlias, id);
}

bool BinarySchema::skipCodeSyntaxMapField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexCodeSyntaxMap, id);
}

bool BinarySchema::skipCodeSyntaxMapEntryField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexCodeSyntaxMapEntry, id);
}

bool BinarySchema::skipDeliverInfoField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexDeliverInfo, id);
}

bool BinarySchema::skipAnnotationPropertyField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexAnnotationProperty, id);
}

bool BinarySchema::skipAnnotationCategoryCustomField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexAnnotationCategoryCustom, id);
}

bool BinarySchema::skipAnnotationCategoryField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexAnnotationCategory, id);
}

bool BinarySchema::skipAnnotationCategoriesField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexAnnotationCategories, id);
}

bool BinarySchema::skipAnnotationField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexAnnotation, id);
}

PaintType *Paint::type() {
  return _flags[0] & 1 ? &_data_type : nullptr;
}

const PaintType *Paint::type() const {
  return _flags[0] & 1 ? &_data_type : nullptr;
}

void Paint::set_type(const PaintType &value) {
  _flags[0] |= 1; _data_type = value;
}

Color *Paint::color() {
  return _data_color;
}

const Color *Paint::color() const {
  return _data_color;
}

void Paint::set_color(Color *value) {
  _data_color = value;
}

float *Paint::opacity() {
  return _flags[0] & 4 ? &_data_opacity : nullptr;
}

const float *Paint::opacity() const {
  return _flags[0] & 4 ? &_data_opacity : nullptr;
}

void Paint::set_opacity(const float &value) {
  _flags[0] |= 4; _data_opacity = value;
}

bool *Paint::visible() {
  return _flags[0] & 8 ? &_data_visible : nullptr;
}

const bool *Paint::visible() const {
  return _flags[0] & 8 ? &_data_visible : nullptr;
}

void Paint::set_visible(const bool &value) {
  _flags[0] |= 8; _data_visible = value;
}

BlendMode *Paint::blendMode() {
  return _flags[0] & 16 ? &_data_blendMode : nullptr;
}

const BlendMode *Paint::blendMode() const {
  return _flags[0] & 16 ? &_data_blendMode : nullptr;
}

void Paint::set_blendMode(const BlendMode &value) {
  _flags[0] |= 16; _data_blendMode = value;
}

kiwi::Array<ColorStop> *Paint::stops() {
  return _flags[0] & 32 ? &_data_stops : nullptr;
}

const kiwi::Array<ColorStop> *Paint::stops() const {
  return _flags[0] & 32 ? &_data_stops : nullptr;
}

kiwi::Array<ColorStop> &Paint::set_stops(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 32; return _data_stops = pool.array<ColorStop>(count);
}

Matrix *Paint::transform() {
  return _data_transform;
}

const Matrix *Paint::transform() const {
  return _data_transform;
}

void Paint::set_transform(Matrix *value) {
  _data_transform = value;
}

ImageMessage *Paint::image() {
  return _data_image;
}

const ImageMessage *Paint::image() const {
  return _data_image;
}

void Paint::set_image(ImageMessage *value) {
  _data_image = value;
}

ImageMessage *Paint::imageThumbnail() {
  return _data_imageThumbnail;
}

const ImageMessage *Paint::imageThumbnail() const {
  return _data_imageThumbnail;
}

void Paint::set_imageThumbnail(ImageMessage *value) {
  _data_imageThumbnail = value;
}

ImageMessage *Paint::animatedImage() {
  return _data_animatedImage;
}

const ImageMessage *Paint::animatedImage() const {
  return _data_animatedImage;
}

void Paint::set_animatedImage(ImageMessage *value) {
  _data_animatedImage = value;
}

int32_t *Paint::animationFrame() {
  return _flags[0] & 1024 ? &_data_animationFrame : nullptr;
}

const int32_t *Paint::animationFrame() const {
  return _flags[0] & 1024 ? &_data_animationFrame : nullptr;
}

void Paint::set_animationFrame(const int32_t &value) {
  _flags[0] |= 1024; _data_animationFrame = value;
}

ImageScaleMode *Paint::imageScaleMode() {
  return _flags[0] & 2048 ? &_data_imageScaleMode : nullptr;
}

const ImageScaleMode *Paint::imageScaleMode() const {
  return _flags[0] & 2048 ? &_data_imageScaleMode : nullptr;
}

void Paint::set_imageScaleMode(const ImageScaleMode &value) {
  _flags[0] |= 2048; _data_imageScaleMode = value;
}

float *Paint::rotation() {
  return _flags[0] & 4096 ? &_data_rotation : nullptr;
}

const float *Paint::rotation() const {
  return _flags[0] & 4096 ? &_data_rotation : nullptr;
}

void Paint::set_rotation(const float &value) {
  _flags[0] |= 4096; _data_rotation = value;
}

float *Paint::scale() {
  return _flags[0] & 8192 ? &_data_scale : nullptr;
}

const float *Paint::scale() const {
  return _flags[0] & 8192 ? &_data_scale : nullptr;
}

void Paint::set_scale(const float &value) {
  _flags[0] |= 8192; _data_scale = value;
}

PaintFilterMessage *Paint::paintFilter() {
  return _data_paintFilter;
}

const PaintFilterMessage *Paint::paintFilter() const {
  return _data_paintFilter;
}

void Paint::set_paintFilter(PaintFilterMessage *value) {
  _data_paintFilter = value;
}

kiwi::Array<int32_t> *Paint::emojiCodePoints() {
  return _flags[0] & 32768 ? &_data_emojiCodePoints : nullptr;
}

const kiwi::Array<int32_t> *Paint::emojiCodePoints() const {
  return _flags[0] & 32768 ? &_data_emojiCodePoints : nullptr;
}

kiwi::Array<int32_t> &Paint::set_emojiCodePoints(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 32768; return _data_emojiCodePoints = pool.array<int32_t>(count);
}

int32_t *Paint::originalImageWidth() {
  return _flags[0] & 65536 ? &_data_originalImageWidth : nullptr;
}

const int32_t *Paint::originalImageWidth() const {
  return _flags[0] & 65536 ? &_data_originalImageWidth : nullptr;
}

void Paint::set_originalImageWidth(const int32_t &value) {
  _flags[0] |= 65536; _data_originalImageWidth = value;
}

int32_t *Paint::originalImageHeight() {
  return _flags[0] & 131072 ? &_data_originalImageHeight : nullptr;
}

const int32_t *Paint::originalImageHeight() const {
  return _flags[0] & 131072 ? &_data_originalImageHeight : nullptr;
}

void Paint::set_originalImageHeight(const int32_t &value) {
  _flags[0] |= 131072; _data_originalImageHeight = value;
}

ImageMessage *Paint::video() {
  return _data_video;
}

const ImageMessage *Paint::video() const {
  return _data_video;
}

void Paint::set_video(ImageMessage *value) {
  _data_video = value;
}

VariableData *Paint::colorVar() {
  return _data_colorVar;
}

const VariableData *Paint::colorVar() const {
  return _data_colorVar;
}

void Paint::set_colorVar(VariableData *value) {
  _data_colorVar = value;
}

kiwi::Array<ColorStopVar> *Paint::stopsVar() {
  return _flags[0] & 1048576 ? &_data_stopsVar : nullptr;
}

const kiwi::Array<ColorStopVar> *Paint::stopsVar() const {
  return _flags[0] & 1048576 ? &_data_stopsVar : nullptr;
}

kiwi::Array<ColorStopVar> &Paint::set_stopsVar(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 1048576; return _data_stopsVar = pool.array<ColorStopVar>(count);
}

Vector *Paint::patternSpacing() {
  return _data_patternSpacing;
}

const Vector *Paint::patternSpacing() const {
  return _data_patternSpacing;
}

void Paint::set_patternSpacing(Vector *value) {
  _data_patternSpacing = value;
}

PatternTileType *Paint::patternTileType() {
  return _flags[0] & 4194304 ? &_data_patternTileType : nullptr;
}

const PatternTileType *Paint::patternTileType() const {
  return _flags[0] & 4194304 ? &_data_patternTileType : nullptr;
}

void Paint::set_patternTileType(const PatternTileType &value) {
  _flags[0] |= 4194304; _data_patternTileType = value;
}

PatternAlignment *Paint::verticalAlignment() {
  return _flags[0] & 8388608 ? &_data_verticalAlignment : nullptr;
}

const PatternAlignment *Paint::verticalAlignment() const {
  return _flags[0] & 8388608 ? &_data_verticalAlignment : nullptr;
}

void Paint::set_verticalAlignment(const PatternAlignment &value) {
  _flags[0] |= 8388608; _data_verticalAlignment = value;
}

PatternAlignment *Paint::horizontalAlignment() {
  return _flags[0] & 16777216 ? &_data_horizontalAlignment : nullptr;
}

const PatternAlignment *Paint::horizontalAlignment() const {
  return _flags[0] & 16777216 ? &_data_horizontalAlignment : nullptr;
}

void Paint::set_horizontalAlignment(const PatternAlignment &value) {
  _flags[0] |= 16777216; _data_horizontalAlignment = value;
}

GUID *Paint::sourceNodeId() {
  return _data_sourceNodeId;
}

const GUID *Paint::sourceNodeId() const {
  return _data_sourceNodeId;
}

void Paint::set_sourceNodeId(GUID *value) {
  _data_sourceNodeId = value;
}

float *Paint::spacing() {
  return _flags[0] & 67108864 ? &_data_spacing : nullptr;
}

const float *Paint::spacing() const {
  return _flags[0] & 67108864 ? &_data_spacing : nullptr;
}

void Paint::set_spacing(const float &value) {
  _flags[0] |= 67108864; _data_spacing = value;
}

bool Paint::encode(kiwi::ByteBuffer &_bb) {
  if (type() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(static_cast<uint32_t>(_data_type));
  }
  if (color() != nullptr) {
    _bb.writeVarUint(2);
    if (!_data_color->encode(_bb)) return false;
  }
  if (opacity() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeVarFloat(_data_opacity);
  }
  if (visible() != nullptr) {
    _bb.writeVarUint(4);
    _bb.writeByte(_data_visible);
  }
  if (blendMode() != nullptr) {
    _bb.writeVarUint(5);
    _bb.writeVarUint(static_cast<uint32_t>(_data_blendMode));
  }
  if (stops() != nullptr) {
    _bb.writeVarUint(6);
    _bb.writeVarUint(_data_stops.size());
    for (ColorStop &_it : _data_stops) if (!_it.encode(_bb)) return false;
  }
  if (transform() != nullptr) {
    _bb.writeVarUint(7);
    if (!_data_transform->encode(_bb)) return false;
  }
  if (image() != nullptr) {
    _bb.writeVarUint(8);
    if (!_data_image->encode(_bb)) return false;
  }
  if (imageThumbnail() != nullptr) {
    _bb.writeVarUint(9);
    if (!_data_imageThumbnail->encode(_bb)) return false;
  }
  if (animatedImage() != nullptr) {
    _bb.writeVarUint(10);
    if (!_data_animatedImage->encode(_bb)) return false;
  }
  if (animationFrame() != nullptr) {
    _bb.writeVarUint(11);
    _bb.writeVarInt(_data_animationFrame);
  }
  if (imageScaleMode() != nullptr) {
    _bb.writeVarUint(12);
    _bb.writeVarUint(static_cast<uint32_t>(_data_imageScaleMode));
  }
  if (rotation() != nullptr) {
    _bb.writeVarUint(13);
    _bb.writeVarFloat(_data_rotation);
  }
  if (scale() != nullptr) {
    _bb.writeVarUint(14);
    _bb.writeVarFloat(_data_scale);
  }
  if (paintFilter() != nullptr) {
    _bb.writeVarUint(15);
    if (!_data_paintFilter->encode(_bb)) return false;
  }
  if (emojiCodePoints() != nullptr) {
    _bb.writeVarUint(16);
    _bb.writeVarUint(_data_emojiCodePoints.size());
    for (int32_t &_it : _data_emojiCodePoints) _bb.writeVarInt(_it);
  }
  if (originalImageWidth() != nullptr) {
    _bb.writeVarUint(17);
    _bb.writeVarInt(_data_originalImageWidth);
  }
  if (originalImageHeight() != nullptr) {
    _bb.writeVarUint(18);
    _bb.writeVarInt(_data_originalImageHeight);
  }
  if (video() != nullptr) {
    _bb.writeVarUint(19);
    if (!_data_video->encode(_bb)) return false;
  }
  if (colorVar() != nullptr) {
    _bb.writeVarUint(20);
    if (!_data_colorVar->encode(_bb)) return false;
  }
  if (stopsVar() != nullptr) {
    _bb.writeVarUint(21);
    _bb.writeVarUint(_data_stopsVar.size());
    for (ColorStopVar &_it : _data_stopsVar) if (!_it.encode(_bb)) return false;
  }
  if (patternSpacing() != nullptr) {
    _bb.writeVarUint(22);
    if (!_data_patternSpacing->encode(_bb)) return false;
  }
  if (patternTileType() != nullptr) {
    _bb.writeVarUint(23);
    _bb.writeVarUint(static_cast<uint32_t>(_data_patternTileType));
  }
  if (verticalAlignment() != nullptr) {
    _bb.writeVarUint(24);
    _bb.writeVarUint(static_cast<uint32_t>(_data_verticalAlignment));
  }
  if (horizontalAlignment() != nullptr) {
    _bb.writeVarUint(25);
    _bb.writeVarUint(static_cast<uint32_t>(_data_horizontalAlignment));
  }
  if (sourceNodeId() != nullptr) {
    _bb.writeVarUint(26);
    if (!_data_sourceNodeId->encode(_bb)) return false;
  }
  if (spacing() != nullptr) {
    _bb.writeVarUint(27);
    _bb.writeVarFloat(_data_spacing);
  }
  _bb.writeVarUint(0);
  return true;
}

bool Paint::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_type))) return false;
        set_type(_data_type);
        break;
      }
      case 2: {
        _data_color = _pool.allocate<Color>();
        if (!_data_color->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 3: {
        if (!_bb.readVarFloat(_data_opacity)) return false;
        set_opacity(_data_opacity);
        break;
      }
      case 4: {
        if (!_bb.readByte(_data_visible)) return false;
        set_visible(_data_visible);
        break;
      }
      case 5: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_blendMode))) return false;
        set_blendMode(_data_blendMode);
        break;
      }
      case 6: {
        if (!_bb.readVarUint(_count)) return false;
        for (ColorStop &_it : set_stops(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 7: {
        _data_transform = _pool.allocate<Matrix>();
        if (!_data_transform->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 8: {
        _data_image = _pool.allocate<ImageMessage>();
        if (!_data_image->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 9: {
        _data_imageThumbnail = _pool.allocate<ImageMessage>();
        if (!_data_imageThumbnail->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 10: {
        _data_animatedImage = _pool.allocate<ImageMessage>();
        if (!_data_animatedImage->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 11: {
        if (!_bb.readVarInt(_data_animationFrame)) return false;
        set_animationFrame(_data_animationFrame);
        break;
      }
      case 12: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_imageScaleMode))) return false;
        set_imageScaleMode(_data_imageScaleMode);
        break;
      }
      case 13: {
        if (!_bb.readVarFloat(_data_rotation)) return false;
        set_rotation(_data_rotation);
        break;
      }
      case 14: {
        if (!_bb.readVarFloat(_data_scale)) return false;
        set_scale(_data_scale);
        break;
      }
      case 15: {
        _data_paintFilter = _pool.allocate<PaintFilterMessage>();
        if (!_data_paintFilter->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 16: {
        if (!_bb.readVarUint(_count)) return false;
        for (int32_t &_it : set_emojiCodePoints(_pool, _count)) if (!_bb.readVarInt(_it)) return false;
        break;
      }
      case 17: {
        if (!_bb.readVarInt(_data_originalImageWidth)) return false;
        set_originalImageWidth(_data_originalImageWidth);
        break;
      }
      case 18: {
        if (!_bb.readVarInt(_data_originalImageHeight)) return false;
        set_originalImageHeight(_data_originalImageHeight);
        break;
      }
      case 19: {
        _data_video = _pool.allocate<ImageMessage>();
        if (!_data_video->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 20: {
        _data_colorVar = _pool.allocate<VariableData>();
        if (!_data_colorVar->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 21: {
        if (!_bb.readVarUint(_count)) return false;
        for (ColorStopVar &_it : set_stopsVar(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 22: {
        _data_patternSpacing = _pool.allocate<Vector>();
        if (!_data_patternSpacing->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 23: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_patternTileType))) return false;
        set_patternTileType(_data_patternTileType);
        break;
      }
      case 24: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_verticalAlignment))) return false;
        set_verticalAlignment(_data_verticalAlignment);
        break;
      }
      case 25: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_horizontalAlignment))) return false;
        set_horizontalAlignment(_data_horizontalAlignment);
        break;
      }
      case 26: {
        _data_sourceNodeId = _pool.allocate<GUID>();
        if (!_data_sourceNodeId->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 27: {
        if (!_bb.readVarFloat(_data_spacing)) return false;
        set_spacing(_data_spacing);
        break;
      }
      default: {
        if (!_schema || !_schema->skipPaintField(_bb, _type)) return false;
        break;
      }
    }
  }
}

float *PaintFilterMessage::tint() {
  return _flags[0] & 1 ? &_data_tint : nullptr;
}

const float *PaintFilterMessage::tint() const {
  return _flags[0] & 1 ? &_data_tint : nullptr;
}

void PaintFilterMessage::set_tint(const float &value) {
  _flags[0] |= 1; _data_tint = value;
}

float *PaintFilterMessage::shadows() {
  return _flags[0] & 2 ? &_data_shadows : nullptr;
}

const float *PaintFilterMessage::shadows() const {
  return _flags[0] & 2 ? &_data_shadows : nullptr;
}

void PaintFilterMessage::set_shadows(const float &value) {
  _flags[0] |= 2; _data_shadows = value;
}

float *PaintFilterMessage::highlights() {
  return _flags[0] & 4 ? &_data_highlights : nullptr;
}

const float *PaintFilterMessage::highlights() const {
  return _flags[0] & 4 ? &_data_highlights : nullptr;
}

void PaintFilterMessage::set_highlights(const float &value) {
  _flags[0] |= 4; _data_highlights = value;
}

float *PaintFilterMessage::exposure() {
  return _flags[0] & 8 ? &_data_exposure : nullptr;
}

const float *PaintFilterMessage::exposure() const {
  return _flags[0] & 8 ? &_data_exposure : nullptr;
}

void PaintFilterMessage::set_exposure(const float &value) {
  _flags[0] |= 8; _data_exposure = value;
}

float *PaintFilterMessage::temperature() {
  return _flags[0] & 16 ? &_data_temperature : nullptr;
}

const float *PaintFilterMessage::temperature() const {
  return _flags[0] & 16 ? &_data_temperature : nullptr;
}

void PaintFilterMessage::set_temperature(const float &value) {
  _flags[0] |= 16; _data_temperature = value;
}

float *PaintFilterMessage::vibrance() {
  return _flags[0] & 32 ? &_data_vibrance : nullptr;
}

const float *PaintFilterMessage::vibrance() const {
  return _flags[0] & 32 ? &_data_vibrance : nullptr;
}

void PaintFilterMessage::set_vibrance(const float &value) {
  _flags[0] |= 32; _data_vibrance = value;
}

float *PaintFilterMessage::contrast() {
  return _flags[0] & 64 ? &_data_contrast : nullptr;
}

const float *PaintFilterMessage::contrast() const {
  return _flags[0] & 64 ? &_data_contrast : nullptr;
}

void PaintFilterMessage::set_contrast(const float &value) {
  _flags[0] |= 64; _data_contrast = value;
}

float *PaintFilterMessage::hue() {
  return _flags[0] & 128 ? &_data_hue : nullptr;
}

const float *PaintFilterMessage::hue() const {
  return _flags[0] & 128 ? &_data_hue : nullptr;
}

void PaintFilterMessage::set_hue(const float &value) {
  _flags[0] |= 128; _data_hue = value;
}

bool PaintFilterMessage::encode(kiwi::ByteBuffer &_bb) {
  if (tint() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarFloat(_data_tint);
  }
  if (shadows() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarFloat(_data_shadows);
  }
  if (highlights() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeVarFloat(_data_highlights);
  }
  if (exposure() != nullptr) {
    _bb.writeVarUint(4);
    _bb.writeVarFloat(_data_exposure);
  }
  if (temperature() != nullptr) {
    _bb.writeVarUint(5);
    _bb.writeVarFloat(_data_temperature);
  }
  if (vibrance() != nullptr) {
    _bb.writeVarUint(6);
    _bb.writeVarFloat(_data_vibrance);
  }
  if (contrast() != nullptr) {
    _bb.writeVarUint(7);
    _bb.writeVarFloat(_data_contrast);
  }
  if (hue() != nullptr) {
    _bb.writeVarUint(8);
    _bb.writeVarFloat(_data_hue);
  }
  _bb.writeVarUint(0);
  return true;
}

bool PaintFilterMessage::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarFloat(_data_tint)) return false;
        set_tint(_data_tint);
        break;
      }
      case 2: {
        if (!_bb.readVarFloat(_data_shadows)) return false;
        set_shadows(_data_shadows);
        break;
      }
      case 3: {
        if (!_bb.readVarFloat(_data_highlights)) return false;
        set_highlights(_data_highlights);
        break;
      }
      case 4: {
        if (!_bb.readVarFloat(_data_exposure)) return false;
        set_exposure(_data_exposure);
        break;
      }
      case 5: {
        if (!_bb.readVarFloat(_data_temperature)) return false;
        set_temperature(_data_temperature);
        break;
      }
      case 6: {
        if (!_bb.readVarFloat(_data_vibrance)) return false;
        set_vibrance(_data_vibrance);
        break;
      }
      case 7: {
        if (!_bb.readVarFloat(_data_contrast)) return false;
        set_contrast(_data_contrast);
        break;
      }
      case 8: {
        if (!_bb.readVarFloat(_data_hue)) return false;
        set_hue(_data_hue);
        break;
      }
      default: {
        if (!_schema || !_schema->skipPaintFilterMessageField(_bb, _type)) return false;
        break;
      }
    }
  }
}

Color *ColorStop::color() {
  return _data_color;
}

const Color *ColorStop::color() const {
  return _data_color;
}

void ColorStop::set_color(Color *value) {
  _data_color = value;
}

float *ColorStop::position() {
  return _flags[0] & 2 ? &_data_position : nullptr;
}

const float *ColorStop::position() const {
  return _flags[0] & 2 ? &_data_position : nullptr;
}

void ColorStop::set_position(const float &value) {
  _flags[0] |= 2; _data_position = value;
}

bool ColorStop::encode(kiwi::ByteBuffer &_bb) {
  if (color() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_color->encode(_bb)) return false;
  }
  if (position() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarFloat(_data_position);
  }
  _bb.writeVarUint(0);
  return true;
}

bool ColorStop::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_color = _pool.allocate<Color>();
        if (!_data_color->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        if (!_bb.readVarFloat(_data_position)) return false;
        set_position(_data_position);
        break;
      }
      default: {
        if (!_schema || !_schema->skipColorStopField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::Array<uint8_t> *ImageMessage::hash() {
  return _flags[0] & 1 ? &_data_hash : nullptr;
}

const kiwi::Array<uint8_t> *ImageMessage::hash() const {
  return _flags[0] & 1 ? &_data_hash : nullptr;
}

kiwi::Array<uint8_t> &ImageMessage::set_hash(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 1; return _data_hash = pool.array<uint8_t>(count);
}

kiwi::String *ImageMessage::name() {
  return _flags[0] & 2 ? &_data_name : nullptr;
}

const kiwi::String *ImageMessage::name() const {
  return _flags[0] & 2 ? &_data_name : nullptr;
}

void ImageMessage::set_name(const kiwi::String &value) {
  _flags[0] |= 2; _data_name = value;
}

int32_t *ImageMessage::dataBlob() {
  return _flags[0] & 4 ? &_data_dataBlob : nullptr;
}

const int32_t *ImageMessage::dataBlob() const {
  return _flags[0] & 4 ? &_data_dataBlob : nullptr;
}

void ImageMessage::set_dataBlob(const int32_t &value) {
  _flags[0] |= 4; _data_dataBlob = value;
}

bool ImageMessage::encode(kiwi::ByteBuffer &_bb) {
  if (hash() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(_data_hash.size());
    for (uint8_t &_it : _data_hash) _bb.writeByte(_it);
  }
  if (name() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeString(_data_name.c_str());
  }
  if (dataBlob() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeVarInt(_data_dataBlob);
  }
  _bb.writeVarUint(0);
  return true;
}

bool ImageMessage::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(_count)) return false;
        for (uint8_t &_it : set_hash(_pool, _count)) if (!_bb.readByte(_it)) return false;
        break;
      }
      case 2: {
        if (!_bb.readString(_data_name, _pool)) return false;
        set_name(_data_name);
        break;
      }
      case 3: {
        if (!_bb.readVarInt(_data_dataBlob)) return false;
        set_dataBlob(_data_dataBlob);
        break;
      }
      default: {
        if (!_schema || !_schema->skipImageMessageField(_bb, _type)) return false;
        break;
      }
    }
  }
}

int32_t *Path::blobIndex() {
  return _flags[0] & 1 ? &_data_blobIndex : nullptr;
}

const int32_t *Path::blobIndex() const {
  return _flags[0] & 1 ? &_data_blobIndex : nullptr;
}

void Path::set_blobIndex(const int32_t &value) {
  _flags[0] |= 1; _data_blobIndex = value;
}

WindingRule *Path::windingRule() {
  return _flags[0] & 2 ? &_data_windingRule : nullptr;
}

const WindingRule *Path::windingRule() const {
  return _flags[0] & 2 ? &_data_windingRule : nullptr;
}

void Path::set_windingRule(const WindingRule &value) {
  _flags[0] |= 2; _data_windingRule = value;
}

int32_t *Path::pxTag() {
  return _flags[0] & 4 ? &_data_pxTag : nullptr;
}

const int32_t *Path::pxTag() const {
  return _flags[0] & 4 ? &_data_pxTag : nullptr;
}

void Path::set_pxTag(const int32_t &value) {
  _flags[0] |= 4; _data_pxTag = value;
}

bool Path::encode(kiwi::ByteBuffer &_bb) {
  if (blobIndex() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarInt(_data_blobIndex);
  }
  if (windingRule() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarUint(static_cast<uint32_t>(_data_windingRule));
  }
  if (pxTag() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeVarInt(_data_pxTag);
  }
  _bb.writeVarUint(0);
  return true;
}

bool Path::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarInt(_data_blobIndex)) return false;
        set_blobIndex(_data_blobIndex);
        break;
      }
      case 2: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_windingRule))) return false;
        set_windingRule(_data_windingRule);
        break;
      }
      case 3: {
        if (!_bb.readVarInt(_data_pxTag)) return false;
        set_pxTag(_data_pxTag);
        break;
      }
      default: {
        if (!_schema || !_schema->skipPathField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::Array<GUID> *GUIDPath::guids() {
  return _flags[0] & 1 ? &_data_guids : nullptr;
}

const kiwi::Array<GUID> *GUIDPath::guids() const {
  return _flags[0] & 1 ? &_data_guids : nullptr;
}

kiwi::Array<GUID> &GUIDPath::set_guids(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 1; return _data_guids = pool.array<GUID>(count);
}

bool GUIDPath::encode(kiwi::ByteBuffer &_bb) {
  if (guids() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(_data_guids.size());
    for (GUID &_it : _data_guids) if (!_it.encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool GUIDPath::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(_count)) return false;
        for (GUID &_it : set_guids(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipGUIDPathField(_bb, _type)) return false;
        break;
      }
    }
  }
}

int32_t *VectorData::vectorNetworkBlob() {
  return _flags[0] & 1 ? &_data_vectorNetworkBlob : nullptr;
}

const int32_t *VectorData::vectorNetworkBlob() const {
  return _flags[0] & 1 ? &_data_vectorNetworkBlob : nullptr;
}

void VectorData::set_vectorNetworkBlob(const int32_t &value) {
  _flags[0] |= 1; _data_vectorNetworkBlob = value;
}

Vector *VectorData::normalizedSize() {
  return _data_normalizedSize;
}

const Vector *VectorData::normalizedSize() const {
  return _data_normalizedSize;
}

void VectorData::set_normalizedSize(Vector *value) {
  _data_normalizedSize = value;
}

kiwi::Array<VectorStyleData> *VectorData::styleOverrideTable() {
  return _flags[0] & 4 ? &_data_styleOverrideTable : nullptr;
}

const kiwi::Array<VectorStyleData> *VectorData::styleOverrideTable() const {
  return _flags[0] & 4 ? &_data_styleOverrideTable : nullptr;
}

kiwi::Array<VectorStyleData> &VectorData::set_styleOverrideTable(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 4; return _data_styleOverrideTable = pool.array<VectorStyleData>(count);
}

bool VectorData::encode(kiwi::ByteBuffer &_bb) {
  if (vectorNetworkBlob() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarInt(_data_vectorNetworkBlob);
  }
  if (normalizedSize() != nullptr) {
    _bb.writeVarUint(2);
    if (!_data_normalizedSize->encode(_bb)) return false;
  }
  if (styleOverrideTable() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeVarUint(_data_styleOverrideTable.size());
    for (VectorStyleData &_it : _data_styleOverrideTable) if (!_it.encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool VectorData::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarInt(_data_vectorNetworkBlob)) return false;
        set_vectorNetworkBlob(_data_vectorNetworkBlob);
        break;
      }
      case 2: {
        _data_normalizedSize = _pool.allocate<Vector>();
        if (!_data_normalizedSize->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 3: {
        if (!_bb.readVarUint(_count)) return false;
        for (VectorStyleData &_it : set_styleOverrideTable(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipVectorDataField(_bb, _type)) return false;
        break;
      }
    }
  }
}

float *ArcData::startingAngle() {
  return _flags[0] & 1 ? &_data_startingAngle : nullptr;
}

const float *ArcData::startingAngle() const {
  return _flags[0] & 1 ? &_data_startingAngle : nullptr;
}

void ArcData::set_startingAngle(const float &value) {
  _flags[0] |= 1; _data_startingAngle = value;
}

float *ArcData::endingAngle() {
  return _flags[0] & 2 ? &_data_endingAngle : nullptr;
}

const float *ArcData::endingAngle() const {
  return _flags[0] & 2 ? &_data_endingAngle : nullptr;
}

void ArcData::set_endingAngle(const float &value) {
  _flags[0] |= 2; _data_endingAngle = value;
}

float *ArcData::innerRadius() {
  return _flags[0] & 4 ? &_data_innerRadius : nullptr;
}

const float *ArcData::innerRadius() const {
  return _flags[0] & 4 ? &_data_innerRadius : nullptr;
}

void ArcData::set_innerRadius(const float &value) {
  _flags[0] |= 4; _data_innerRadius = value;
}

bool ArcData::encode(kiwi::ByteBuffer &_bb) {
  if (startingAngle() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarFloat(_data_startingAngle);
  }
  if (endingAngle() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarFloat(_data_endingAngle);
  }
  if (innerRadius() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeVarFloat(_data_innerRadius);
  }
  _bb.writeVarUint(0);
  return true;
}

bool ArcData::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarFloat(_data_startingAngle)) return false;
        set_startingAngle(_data_startingAngle);
        break;
      }
      case 2: {
        if (!_bb.readVarFloat(_data_endingAngle)) return false;
        set_endingAngle(_data_endingAngle);
        break;
      }
      case 3: {
        if (!_bb.readVarFloat(_data_innerRadius)) return false;
        set_innerRadius(_data_innerRadius);
        break;
      }
      default: {
        if (!_schema || !_schema->skipArcDataField(_bb, _type)) return false;
        break;
      }
    }
  }
}

EffectType *Effect::type() {
  return _flags[0] & 1 ? &_data_type : nullptr;
}

const EffectType *Effect::type() const {
  return _flags[0] & 1 ? &_data_type : nullptr;
}

void Effect::set_type(const EffectType &value) {
  _flags[0] |= 1; _data_type = value;
}

Color *Effect::color() {
  return _data_color;
}

const Color *Effect::color() const {
  return _data_color;
}

void Effect::set_color(Color *value) {
  _data_color = value;
}

Vector *Effect::offset() {
  return _data_offset;
}

const Vector *Effect::offset() const {
  return _data_offset;
}

void Effect::set_offset(Vector *value) {
  _data_offset = value;
}

float *Effect::radius() {
  return _flags[0] & 8 ? &_data_radius : nullptr;
}

const float *Effect::radius() const {
  return _flags[0] & 8 ? &_data_radius : nullptr;
}

void Effect::set_radius(const float &value) {
  _flags[0] |= 8; _data_radius = value;
}

bool *Effect::visible() {
  return _flags[0] & 16 ? &_data_visible : nullptr;
}

const bool *Effect::visible() const {
  return _flags[0] & 16 ? &_data_visible : nullptr;
}

void Effect::set_visible(const bool &value) {
  _flags[0] |= 16; _data_visible = value;
}

BlendMode *Effect::blendMode() {
  return _flags[0] & 32 ? &_data_blendMode : nullptr;
}

const BlendMode *Effect::blendMode() const {
  return _flags[0] & 32 ? &_data_blendMode : nullptr;
}

void Effect::set_blendMode(const BlendMode &value) {
  _flags[0] |= 32; _data_blendMode = value;
}

float *Effect::spread() {
  return _flags[0] & 64 ? &_data_spread : nullptr;
}

const float *Effect::spread() const {
  return _flags[0] & 64 ? &_data_spread : nullptr;
}

void Effect::set_spread(const float &value) {
  _flags[0] |= 64; _data_spread = value;
}

bool *Effect::showShadowBehindNode() {
  return _flags[0] & 128 ? &_data_showShadowBehindNode : nullptr;
}

const bool *Effect::showShadowBehindNode() const {
  return _flags[0] & 128 ? &_data_showShadowBehindNode : nullptr;
}

void Effect::set_showShadowBehindNode(const bool &value) {
  _flags[0] |= 128; _data_showShadowBehindNode = value;
}

float *Effect::saturation() {
  return _flags[0] & 256 ? &_data_saturation : nullptr;
}

const float *Effect::saturation() const {
  return _flags[0] & 256 ? &_data_saturation : nullptr;
}

void Effect::set_saturation(const float &value) {
  _flags[0] |= 256; _data_saturation = value;
}

VariableData *Effect::radiusVar() {
  return _data_radiusVar;
}

const VariableData *Effect::radiusVar() const {
  return _data_radiusVar;
}

void Effect::set_radiusVar(VariableData *value) {
  _data_radiusVar = value;
}

VariableData *Effect::colorVar() {
  return _data_colorVar;
}

const VariableData *Effect::colorVar() const {
  return _data_colorVar;
}

void Effect::set_colorVar(VariableData *value) {
  _data_colorVar = value;
}

VariableData *Effect::spreadVar() {
  return _data_spreadVar;
}

const VariableData *Effect::spreadVar() const {
  return _data_spreadVar;
}

void Effect::set_spreadVar(VariableData *value) {
  _data_spreadVar = value;
}

VariableData *Effect::xVar() {
  return _data_xVar;
}

const VariableData *Effect::xVar() const {
  return _data_xVar;
}

void Effect::set_xVar(VariableData *value) {
  _data_xVar = value;
}

VariableData *Effect::yVar() {
  return _data_yVar;
}

const VariableData *Effect::yVar() const {
  return _data_yVar;
}

void Effect::set_yVar(VariableData *value) {
  _data_yVar = value;
}

float *Effect::refractionRadius() {
  return _flags[0] & 16384 ? &_data_refractionRadius : nullptr;
}

const float *Effect::refractionRadius() const {
  return _flags[0] & 16384 ? &_data_refractionRadius : nullptr;
}

void Effect::set_refractionRadius(const float &value) {
  _flags[0] |= 16384; _data_refractionRadius = value;
}

float *Effect::specularAngle() {
  return _flags[0] & 32768 ? &_data_specularAngle : nullptr;
}

const float *Effect::specularAngle() const {
  return _flags[0] & 32768 ? &_data_specularAngle : nullptr;
}

void Effect::set_specularAngle(const float &value) {
  _flags[0] |= 32768; _data_specularAngle = value;
}

float *Effect::specularIntensity() {
  return _flags[0] & 65536 ? &_data_specularIntensity : nullptr;
}

const float *Effect::specularIntensity() const {
  return _flags[0] & 65536 ? &_data_specularIntensity : nullptr;
}

void Effect::set_specularIntensity(const float &value) {
  _flags[0] |= 65536; _data_specularIntensity = value;
}

float *Effect::chromaticAberration() {
  return _flags[0] & 131072 ? &_data_chromaticAberration : nullptr;
}

const float *Effect::chromaticAberration() const {
  return _flags[0] & 131072 ? &_data_chromaticAberration : nullptr;
}

void Effect::set_chromaticAberration(const float &value) {
  _flags[0] |= 131072; _data_chromaticAberration = value;
}

float *Effect::refractionIntensity() {
  return _flags[0] & 262144 ? &_data_refractionIntensity : nullptr;
}

const float *Effect::refractionIntensity() const {
  return _flags[0] & 262144 ? &_data_refractionIntensity : nullptr;
}

void Effect::set_refractionIntensity(const float &value) {
  _flags[0] |= 262144; _data_refractionIntensity = value;
}

float *Effect::brightness() {
  return _flags[0] & 524288 ? &_data_brightness : nullptr;
}

const float *Effect::brightness() const {
  return _flags[0] & 524288 ? &_data_brightness : nullptr;
}

void Effect::set_brightness(const float &value) {
  _flags[0] |= 524288; _data_brightness = value;
}

bool *Effect::uniformLight() {
  return _flags[0] & 1048576 ? &_data_uniformLight : nullptr;
}

const bool *Effect::uniformLight() const {
  return _flags[0] & 1048576 ? &_data_uniformLight : nullptr;
}

void Effect::set_uniformLight(const bool &value) {
  _flags[0] |= 1048576; _data_uniformLight = value;
}

BlurOpType *Effect::blurOpType() {
  return _flags[0] & 2097152 ? &_data_blurOpType : nullptr;
}

const BlurOpType *Effect::blurOpType() const {
  return _flags[0] & 2097152 ? &_data_blurOpType : nullptr;
}

void Effect::set_blurOpType(const BlurOpType &value) {
  _flags[0] |= 2097152; _data_blurOpType = value;
}

float *Effect::startRadius() {
  return _flags[0] & 4194304 ? &_data_startRadius : nullptr;
}

const float *Effect::startRadius() const {
  return _flags[0] & 4194304 ? &_data_startRadius : nullptr;
}

void Effect::set_startRadius(const float &value) {
  _flags[0] |= 4194304; _data_startRadius = value;
}

Matrix *Effect::transform() {
  return _data_transform;
}

const Matrix *Effect::transform() const {
  return _data_transform;
}

void Effect::set_transform(Matrix *value) {
  _data_transform = value;
}

float *Effect::bevelSize() {
  return _flags[0] & 16777216 ? &_data_bevelSize : nullptr;
}

const float *Effect::bevelSize() const {
  return _flags[0] & 16777216 ? &_data_bevelSize : nullptr;
}

void Effect::set_bevelSize(const float &value) {
  _flags[0] |= 16777216; _data_bevelSize = value;
}

Vector *Effect::noiseSize() {
  return _data_noiseSize;
}

const Vector *Effect::noiseSize() const {
  return _data_noiseSize;
}

void Effect::set_noiseSize(Vector *value) {
  _data_noiseSize = value;
}

float *Effect::density() {
  return _flags[0] & 67108864 ? &_data_density : nullptr;
}

const float *Effect::density() const {
  return _flags[0] & 67108864 ? &_data_density : nullptr;
}

void Effect::set_density(const float &value) {
  _flags[0] |= 67108864; _data_density = value;
}

NoiseType *Effect::noiseType() {
  return _flags[0] & 134217728 ? &_data_noiseType : nullptr;
}

const NoiseType *Effect::noiseType() const {
  return _flags[0] & 134217728 ? &_data_noiseType : nullptr;
}

void Effect::set_noiseType(const NoiseType &value) {
  _flags[0] |= 134217728; _data_noiseType = value;
}

float *Effect::opacity() {
  return _flags[0] & 268435456 ? &_data_opacity : nullptr;
}

const float *Effect::opacity() const {
  return _flags[0] & 268435456 ? &_data_opacity : nullptr;
}

void Effect::set_opacity(const float &value) {
  _flags[0] |= 268435456; _data_opacity = value;
}

Color *Effect::secondaryColor() {
  return _data_secondaryColor;
}

const Color *Effect::secondaryColor() const {
  return _data_secondaryColor;
}

void Effect::set_secondaryColor(Color *value) {
  _data_secondaryColor = value;
}

bool *Effect::clipToShape() {
  return _flags[0] & 1073741824 ? &_data_clipToShape : nullptr;
}

const bool *Effect::clipToShape() const {
  return _flags[0] & 1073741824 ? &_data_clipToShape : nullptr;
}

void Effect::set_clipToShape(const bool &value) {
  _flags[0] |= 1073741824; _data_clipToShape = value;
}

int32_t *Effect::seed() {
  return _flags[0] & 2147483648 ? &_data_seed : nullptr;
}

const int32_t *Effect::seed() const {
  return _flags[0] & 2147483648 ? &_data_seed : nullptr;
}

void Effect::set_seed(const int32_t &value) {
  _flags[0] |= 2147483648; _data_seed = value;
}

bool *Effect::isImpact() {
  return _flags[1] & 1 ? &_data_isImpact : nullptr;
}

const bool *Effect::isImpact() const {
  return _flags[1] & 1 ? &_data_isImpact : nullptr;
}

void Effect::set_isImpact(const bool &value) {
  _flags[1] |= 1; _data_isImpact = value;
}

float *Effect::samplingRange() {
  return _flags[1] & 2 ? &_data_samplingRange : nullptr;
}

const float *Effect::samplingRange() const {
  return _flags[1] & 2 ? &_data_samplingRange : nullptr;
}

void Effect::set_samplingRange(const float &value) {
  _flags[1] |= 2; _data_samplingRange = value;
}

float *Effect::splay() {
  return _flags[1] & 4 ? &_data_splay : nullptr;
}

const float *Effect::splay() const {
  return _flags[1] & 4 ? &_data_splay : nullptr;
}

void Effect::set_splay(const float &value) {
  _flags[1] |= 4; _data_splay = value;
}

bool *Effect::isConvex() {
  return _flags[1] & 8 ? &_data_isConvex : nullptr;
}

const bool *Effect::isConvex() const {
  return _flags[1] & 8 ? &_data_isConvex : nullptr;
}

void Effect::set_isConvex(const bool &value) {
  _flags[1] |= 8; _data_isConvex = value;
}

Vector *Effect::center() {
  return _data_center;
}

const Vector *Effect::center() const {
  return _data_center;
}

void Effect::set_center(Vector *value) {
  _data_center = value;
}

float *Effect::motionAngle() {
  return _flags[1] & 32 ? &_data_motionAngle : nullptr;
}

const float *Effect::motionAngle() const {
  return _flags[1] & 32 ? &_data_motionAngle : nullptr;
}

void Effect::set_motionAngle(const float &value) {
  _flags[1] |= 32; _data_motionAngle = value;
}

bool Effect::encode(kiwi::ByteBuffer &_bb) {
  if (type() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(static_cast<uint32_t>(_data_type));
  }
  if (color() != nullptr) {
    _bb.writeVarUint(2);
    if (!_data_color->encode(_bb)) return false;
  }
  if (offset() != nullptr) {
    _bb.writeVarUint(3);
    if (!_data_offset->encode(_bb)) return false;
  }
  if (radius() != nullptr) {
    _bb.writeVarUint(4);
    _bb.writeVarFloat(_data_radius);
  }
  if (visible() != nullptr) {
    _bb.writeVarUint(5);
    _bb.writeByte(_data_visible);
  }
  if (blendMode() != nullptr) {
    _bb.writeVarUint(6);
    _bb.writeVarUint(static_cast<uint32_t>(_data_blendMode));
  }
  if (spread() != nullptr) {
    _bb.writeVarUint(7);
    _bb.writeVarFloat(_data_spread);
  }
  if (showShadowBehindNode() != nullptr) {
    _bb.writeVarUint(8);
    _bb.writeByte(_data_showShadowBehindNode);
  }
  if (saturation() != nullptr) {
    _bb.writeVarUint(9);
    _bb.writeVarFloat(_data_saturation);
  }
  if (radiusVar() != nullptr) {
    _bb.writeVarUint(10);
    if (!_data_radiusVar->encode(_bb)) return false;
  }
  if (colorVar() != nullptr) {
    _bb.writeVarUint(11);
    if (!_data_colorVar->encode(_bb)) return false;
  }
  if (spreadVar() != nullptr) {
    _bb.writeVarUint(12);
    if (!_data_spreadVar->encode(_bb)) return false;
  }
  if (xVar() != nullptr) {
    _bb.writeVarUint(13);
    if (!_data_xVar->encode(_bb)) return false;
  }
  if (yVar() != nullptr) {
    _bb.writeVarUint(14);
    if (!_data_yVar->encode(_bb)) return false;
  }
  if (refractionRadius() != nullptr) {
    _bb.writeVarUint(15);
    _bb.writeVarFloat(_data_refractionRadius);
  }
  if (specularAngle() != nullptr) {
    _bb.writeVarUint(16);
    _bb.writeVarFloat(_data_specularAngle);
  }
  if (specularIntensity() != nullptr) {
    _bb.writeVarUint(17);
    _bb.writeVarFloat(_data_specularIntensity);
  }
  if (chromaticAberration() != nullptr) {
    _bb.writeVarUint(18);
    _bb.writeVarFloat(_data_chromaticAberration);
  }
  if (refractionIntensity() != nullptr) {
    _bb.writeVarUint(19);
    _bb.writeVarFloat(_data_refractionIntensity);
  }
  if (brightness() != nullptr) {
    _bb.writeVarUint(20);
    _bb.writeVarFloat(_data_brightness);
  }
  if (uniformLight() != nullptr) {
    _bb.writeVarUint(21);
    _bb.writeByte(_data_uniformLight);
  }
  if (blurOpType() != nullptr) {
    _bb.writeVarUint(22);
    _bb.writeVarUint(static_cast<uint32_t>(_data_blurOpType));
  }
  if (startRadius() != nullptr) {
    _bb.writeVarUint(23);
    _bb.writeVarFloat(_data_startRadius);
  }
  if (transform() != nullptr) {
    _bb.writeVarUint(24);
    if (!_data_transform->encode(_bb)) return false;
  }
  if (bevelSize() != nullptr) {
    _bb.writeVarUint(25);
    _bb.writeVarFloat(_data_bevelSize);
  }
  if (noiseSize() != nullptr) {
    _bb.writeVarUint(26);
    if (!_data_noiseSize->encode(_bb)) return false;
  }
  if (density() != nullptr) {
    _bb.writeVarUint(27);
    _bb.writeVarFloat(_data_density);
  }
  if (noiseType() != nullptr) {
    _bb.writeVarUint(28);
    _bb.writeVarUint(static_cast<uint32_t>(_data_noiseType));
  }
  if (opacity() != nullptr) {
    _bb.writeVarUint(29);
    _bb.writeVarFloat(_data_opacity);
  }
  if (secondaryColor() != nullptr) {
    _bb.writeVarUint(30);
    if (!_data_secondaryColor->encode(_bb)) return false;
  }
  if (clipToShape() != nullptr) {
    _bb.writeVarUint(31);
    _bb.writeByte(_data_clipToShape);
  }
  if (seed() != nullptr) {
    _bb.writeVarUint(32);
    _bb.writeVarInt(_data_seed);
  }
  if (isImpact() != nullptr) {
    _bb.writeVarUint(33);
    _bb.writeByte(_data_isImpact);
  }
  if (samplingRange() != nullptr) {
    _bb.writeVarUint(34);
    _bb.writeVarFloat(_data_samplingRange);
  }
  if (splay() != nullptr) {
    _bb.writeVarUint(35);
    _bb.writeVarFloat(_data_splay);
  }
  if (isConvex() != nullptr) {
    _bb.writeVarUint(36);
    _bb.writeByte(_data_isConvex);
  }
  if (center() != nullptr) {
    _bb.writeVarUint(37);
    if (!_data_center->encode(_bb)) return false;
  }
  if (motionAngle() != nullptr) {
    _bb.writeVarUint(38);
    _bb.writeVarFloat(_data_motionAngle);
  }
  _bb.writeVarUint(0);
  return true;
}

bool Effect::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_type))) return false;
        set_type(_data_type);
        break;
      }
      case 2: {
        _data_color = _pool.allocate<Color>();
        if (!_data_color->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 3: {
        _data_offset = _pool.allocate<Vector>();
        if (!_data_offset->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 4: {
        if (!_bb.readVarFloat(_data_radius)) return false;
        set_radius(_data_radius);
        break;
      }
      case 5: {
        if (!_bb.readByte(_data_visible)) return false;
        set_visible(_data_visible);
        break;
      }
      case 6: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_blendMode))) return false;
        set_blendMode(_data_blendMode);
        break;
      }
      case 7: {
        if (!_bb.readVarFloat(_data_spread)) return false;
        set_spread(_data_spread);
        break;
      }
      case 8: {
        if (!_bb.readByte(_data_showShadowBehindNode)) return false;
        set_showShadowBehindNode(_data_showShadowBehindNode);
        break;
      }
      case 9: {
        if (!_bb.readVarFloat(_data_saturation)) return false;
        set_saturation(_data_saturation);
        break;
      }
      case 10: {
        _data_radiusVar = _pool.allocate<VariableData>();
        if (!_data_radiusVar->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 11: {
        _data_colorVar = _pool.allocate<VariableData>();
        if (!_data_colorVar->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 12: {
        _data_spreadVar = _pool.allocate<VariableData>();
        if (!_data_spreadVar->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 13: {
        _data_xVar = _pool.allocate<VariableData>();
        if (!_data_xVar->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 14: {
        _data_yVar = _pool.allocate<VariableData>();
        if (!_data_yVar->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 15: {
        if (!_bb.readVarFloat(_data_refractionRadius)) return false;
        set_refractionRadius(_data_refractionRadius);
        break;
      }
      case 16: {
        if (!_bb.readVarFloat(_data_specularAngle)) return false;
        set_specularAngle(_data_specularAngle);
        break;
      }
      case 17: {
        if (!_bb.readVarFloat(_data_specularIntensity)) return false;
        set_specularIntensity(_data_specularIntensity);
        break;
      }
      case 18: {
        if (!_bb.readVarFloat(_data_chromaticAberration)) return false;
        set_chromaticAberration(_data_chromaticAberration);
        break;
      }
      case 19: {
        if (!_bb.readVarFloat(_data_refractionIntensity)) return false;
        set_refractionIntensity(_data_refractionIntensity);
        break;
      }
      case 20: {
        if (!_bb.readVarFloat(_data_brightness)) return false;
        set_brightness(_data_brightness);
        break;
      }
      case 21: {
        if (!_bb.readByte(_data_uniformLight)) return false;
        set_uniformLight(_data_uniformLight);
        break;
      }
      case 22: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_blurOpType))) return false;
        set_blurOpType(_data_blurOpType);
        break;
      }
      case 23: {
        if (!_bb.readVarFloat(_data_startRadius)) return false;
        set_startRadius(_data_startRadius);
        break;
      }
      case 24: {
        _data_transform = _pool.allocate<Matrix>();
        if (!_data_transform->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 25: {
        if (!_bb.readVarFloat(_data_bevelSize)) return false;
        set_bevelSize(_data_bevelSize);
        break;
      }
      case 26: {
        _data_noiseSize = _pool.allocate<Vector>();
        if (!_data_noiseSize->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 27: {
        if (!_bb.readVarFloat(_data_density)) return false;
        set_density(_data_density);
        break;
      }
      case 28: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_noiseType))) return false;
        set_noiseType(_data_noiseType);
        break;
      }
      case 29: {
        if (!_bb.readVarFloat(_data_opacity)) return false;
        set_opacity(_data_opacity);
        break;
      }
      case 30: {
        _data_secondaryColor = _pool.allocate<Color>();
        if (!_data_secondaryColor->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 31: {
        if (!_bb.readByte(_data_clipToShape)) return false;
        set_clipToShape(_data_clipToShape);
        break;
      }
      case 32: {
        if (!_bb.readVarInt(_data_seed)) return false;
        set_seed(_data_seed);
        break;
      }
      case 33: {
        if (!_bb.readByte(_data_isImpact)) return false;
        set_isImpact(_data_isImpact);
        break;
      }
      case 34: {
        if (!_bb.readVarFloat(_data_samplingRange)) return false;
        set_samplingRange(_data_samplingRange);
        break;
      }
      case 35: {
        if (!_bb.readVarFloat(_data_splay)) return false;
        set_splay(_data_splay);
        break;
      }
      case 36: {
        if (!_bb.readByte(_data_isConvex)) return false;
        set_isConvex(_data_isConvex);
        break;
      }
      case 37: {
        _data_center = _pool.allocate<Vector>();
        if (!_data_center->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 38: {
        if (!_bb.readVarFloat(_data_motionAngle)) return false;
        set_motionAngle(_data_motionAngle);
        break;
      }
      default: {
        if (!_schema || !_schema->skipEffectField(_bb, _type)) return false;
        break;
      }
    }
  }
}

GUID *SymbolData::symbolID() {
  return _data_symbolID;
}

const GUID *SymbolData::symbolID() const {
  return _data_symbolID;
}

void SymbolData::set_symbolID(GUID *value) {
  _data_symbolID = value;
}

kiwi::Array<PixsoNode> *SymbolData::symbolOverrides() {
  return _flags[0] & 2 ? &_data_symbolOverrides : nullptr;
}

const kiwi::Array<PixsoNode> *SymbolData::symbolOverrides() const {
  return _flags[0] & 2 ? &_data_symbolOverrides : nullptr;
}

kiwi::Array<PixsoNode> &SymbolData::set_symbolOverrides(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 2; return _data_symbolOverrides = pool.array<PixsoNode>(count);
}

float *SymbolData::uniformScaleFactor() {
  return _flags[0] & 4 ? &_data_uniformScaleFactor : nullptr;
}

const float *SymbolData::uniformScaleFactor() const {
  return _flags[0] & 4 ? &_data_uniformScaleFactor : nullptr;
}

void SymbolData::set_uniformScaleFactor(const float &value) {
  _flags[0] |= 4; _data_uniformScaleFactor = value;
}

bool SymbolData::encode(kiwi::ByteBuffer &_bb) {
  if (symbolID() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_symbolID->encode(_bb)) return false;
  }
  if (symbolOverrides() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarUint(_data_symbolOverrides.size());
    for (PixsoNode &_it : _data_symbolOverrides) if (!_it.encode(_bb)) return false;
  }
  if (uniformScaleFactor() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeVarFloat(_data_uniformScaleFactor);
  }
  _bb.writeVarUint(0);
  return true;
}

bool SymbolData::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_symbolID = _pool.allocate<GUID>();
        if (!_data_symbolID->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        if (!_bb.readVarUint(_count)) return false;
        for (PixsoNode &_it : set_symbolOverrides(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 3: {
        if (!_bb.readVarFloat(_data_uniformScaleFactor)) return false;
        set_uniformScaleFactor(_data_uniformScaleFactor);
        break;
      }
      default: {
        if (!_schema || !_schema->skipSymbolDataField(_bb, _type)) return false;
        break;
      }
    }
  }
}

LayoutGridType *LayoutGrid::type() {
  return _flags[0] & 1 ? &_data_type : nullptr;
}

const LayoutGridType *LayoutGrid::type() const {
  return _flags[0] & 1 ? &_data_type : nullptr;
}

void LayoutGrid::set_type(const LayoutGridType &value) {
  _flags[0] |= 1; _data_type = value;
}

Axis *LayoutGrid::axis() {
  return _flags[0] & 2 ? &_data_axis : nullptr;
}

const Axis *LayoutGrid::axis() const {
  return _flags[0] & 2 ? &_data_axis : nullptr;
}

void LayoutGrid::set_axis(const Axis &value) {
  _flags[0] |= 2; _data_axis = value;
}

bool *LayoutGrid::visible() {
  return _flags[0] & 4 ? &_data_visible : nullptr;
}

const bool *LayoutGrid::visible() const {
  return _flags[0] & 4 ? &_data_visible : nullptr;
}

void LayoutGrid::set_visible(const bool &value) {
  _flags[0] |= 4; _data_visible = value;
}

int32_t *LayoutGrid::numSections() {
  return _flags[0] & 8 ? &_data_numSections : nullptr;
}

const int32_t *LayoutGrid::numSections() const {
  return _flags[0] & 8 ? &_data_numSections : nullptr;
}

void LayoutGrid::set_numSections(const int32_t &value) {
  _flags[0] |= 8; _data_numSections = value;
}

float *LayoutGrid::offset() {
  return _flags[0] & 16 ? &_data_offset : nullptr;
}

const float *LayoutGrid::offset() const {
  return _flags[0] & 16 ? &_data_offset : nullptr;
}

void LayoutGrid::set_offset(const float &value) {
  _flags[0] |= 16; _data_offset = value;
}

float *LayoutGrid::sectionSize() {
  return _flags[0] & 32 ? &_data_sectionSize : nullptr;
}

const float *LayoutGrid::sectionSize() const {
  return _flags[0] & 32 ? &_data_sectionSize : nullptr;
}

void LayoutGrid::set_sectionSize(const float &value) {
  _flags[0] |= 32; _data_sectionSize = value;
}

float *LayoutGrid::gutterSize() {
  return _flags[0] & 64 ? &_data_gutterSize : nullptr;
}

const float *LayoutGrid::gutterSize() const {
  return _flags[0] & 64 ? &_data_gutterSize : nullptr;
}

void LayoutGrid::set_gutterSize(const float &value) {
  _flags[0] |= 64; _data_gutterSize = value;
}

Color *LayoutGrid::color() {
  return _data_color;
}

const Color *LayoutGrid::color() const {
  return _data_color;
}

void LayoutGrid::set_color(Color *value) {
  _data_color = value;
}

LayoutGridPattern *LayoutGrid::pattern() {
  return _flags[0] & 256 ? &_data_pattern : nullptr;
}

const LayoutGridPattern *LayoutGrid::pattern() const {
  return _flags[0] & 256 ? &_data_pattern : nullptr;
}

void LayoutGrid::set_pattern(const LayoutGridPattern &value) {
  _flags[0] |= 256; _data_pattern = value;
}

VariableData *LayoutGrid::numSectionsVar() {
  return _data_numSectionsVar;
}

const VariableData *LayoutGrid::numSectionsVar() const {
  return _data_numSectionsVar;
}

void LayoutGrid::set_numSectionsVar(VariableData *value) {
  _data_numSectionsVar = value;
}

VariableData *LayoutGrid::offsetVar() {
  return _data_offsetVar;
}

const VariableData *LayoutGrid::offsetVar() const {
  return _data_offsetVar;
}

void LayoutGrid::set_offsetVar(VariableData *value) {
  _data_offsetVar = value;
}

VariableData *LayoutGrid::sectionSizeVar() {
  return _data_sectionSizeVar;
}

const VariableData *LayoutGrid::sectionSizeVar() const {
  return _data_sectionSizeVar;
}

void LayoutGrid::set_sectionSizeVar(VariableData *value) {
  _data_sectionSizeVar = value;
}

VariableData *LayoutGrid::gutterSizeVar() {
  return _data_gutterSizeVar;
}

const VariableData *LayoutGrid::gutterSizeVar() const {
  return _data_gutterSizeVar;
}

void LayoutGrid::set_gutterSizeVar(VariableData *value) {
  _data_gutterSizeVar = value;
}

bool LayoutGrid::encode(kiwi::ByteBuffer &_bb) {
  if (type() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(static_cast<uint32_t>(_data_type));
  }
  if (axis() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarUint(static_cast<uint32_t>(_data_axis));
  }
  if (visible() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeByte(_data_visible);
  }
  if (numSections() != nullptr) {
    _bb.writeVarUint(4);
    _bb.writeVarInt(_data_numSections);
  }
  if (offset() != nullptr) {
    _bb.writeVarUint(5);
    _bb.writeVarFloat(_data_offset);
  }
  if (sectionSize() != nullptr) {
    _bb.writeVarUint(6);
    _bb.writeVarFloat(_data_sectionSize);
  }
  if (gutterSize() != nullptr) {
    _bb.writeVarUint(7);
    _bb.writeVarFloat(_data_gutterSize);
  }
  if (color() != nullptr) {
    _bb.writeVarUint(8);
    if (!_data_color->encode(_bb)) return false;
  }
  if (pattern() != nullptr) {
    _bb.writeVarUint(9);
    _bb.writeVarUint(static_cast<uint32_t>(_data_pattern));
  }
  if (numSectionsVar() != nullptr) {
    _bb.writeVarUint(10);
    if (!_data_numSectionsVar->encode(_bb)) return false;
  }
  if (offsetVar() != nullptr) {
    _bb.writeVarUint(11);
    if (!_data_offsetVar->encode(_bb)) return false;
  }
  if (sectionSizeVar() != nullptr) {
    _bb.writeVarUint(12);
    if (!_data_sectionSizeVar->encode(_bb)) return false;
  }
  if (gutterSizeVar() != nullptr) {
    _bb.writeVarUint(13);
    if (!_data_gutterSizeVar->encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool LayoutGrid::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_type))) return false;
        set_type(_data_type);
        break;
      }
      case 2: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_axis))) return false;
        set_axis(_data_axis);
        break;
      }
      case 3: {
        if (!_bb.readByte(_data_visible)) return false;
        set_visible(_data_visible);
        break;
      }
      case 4: {
        if (!_bb.readVarInt(_data_numSections)) return false;
        set_numSections(_data_numSections);
        break;
      }
      case 5: {
        if (!_bb.readVarFloat(_data_offset)) return false;
        set_offset(_data_offset);
        break;
      }
      case 6: {
        if (!_bb.readVarFloat(_data_sectionSize)) return false;
        set_sectionSize(_data_sectionSize);
        break;
      }
      case 7: {
        if (!_bb.readVarFloat(_data_gutterSize)) return false;
        set_gutterSize(_data_gutterSize);
        break;
      }
      case 8: {
        _data_color = _pool.allocate<Color>();
        if (!_data_color->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 9: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_pattern))) return false;
        set_pattern(_data_pattern);
        break;
      }
      case 10: {
        _data_numSectionsVar = _pool.allocate<VariableData>();
        if (!_data_numSectionsVar->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 11: {
        _data_offsetVar = _pool.allocate<VariableData>();
        if (!_data_offsetVar->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 12: {
        _data_sectionSizeVar = _pool.allocate<VariableData>();
        if (!_data_sectionSizeVar->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 13: {
        _data_gutterSizeVar = _pool.allocate<VariableData>();
        if (!_data_gutterSizeVar->decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipLayoutGridField(_bb, _type)) return false;
        break;
      }
    }
  }
}

GUID *GridTrackSizing::id() {
  return _data_id;
}

const GUID *GridTrackSizing::id() const {
  return _data_id;
}

void GridTrackSizing::set_id(GUID *value) {
  _data_id = value;
}

GridTrackSizingType *GridTrackSizing::type() {
  return _flags[0] & 2 ? &_data_type : nullptr;
}

const GridTrackSizingType *GridTrackSizing::type() const {
  return _flags[0] & 2 ? &_data_type : nullptr;
}

void GridTrackSizing::set_type(const GridTrackSizingType &value) {
  _flags[0] |= 2; _data_type = value;
}

float *GridTrackSizing::value() {
  return _flags[0] & 4 ? &_data_value : nullptr;
}

const float *GridTrackSizing::value() const {
  return _flags[0] & 4 ? &_data_value : nullptr;
}

void GridTrackSizing::set_value(const float &value) {
  _flags[0] |= 4; _data_value = value;
}

bool GridTrackSizing::encode(kiwi::ByteBuffer &_bb) {
  if (id() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_id->encode(_bb)) return false;
  }
  if (type() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarUint(static_cast<uint32_t>(_data_type));
  }
  if (value() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeVarFloat(_data_value);
  }
  _bb.writeVarUint(0);
  return true;
}

bool GridTrackSizing::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_id = _pool.allocate<GUID>();
        if (!_data_id->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_type))) return false;
        set_type(_data_type);
        break;
      }
      case 3: {
        if (!_bb.readVarFloat(_data_value)) return false;
        set_value(_data_value);
        break;
      }
      default: {
        if (!_schema || !_schema->skipGridTrackSizingField(_bb, _type)) return false;
        break;
      }
    }
  }
}

ExportConstraintType *ExportConstraint::type() {
  return _flags[0] & 1 ? &_data_type : nullptr;
}

const ExportConstraintType *ExportConstraint::type() const {
  return _flags[0] & 1 ? &_data_type : nullptr;
}

void ExportConstraint::set_type(const ExportConstraintType &value) {
  _flags[0] |= 1; _data_type = value;
}

float *ExportConstraint::value() {
  return _flags[0] & 2 ? &_data_value : nullptr;
}

const float *ExportConstraint::value() const {
  return _flags[0] & 2 ? &_data_value : nullptr;
}

void ExportConstraint::set_value(const float &value) {
  _flags[0] |= 2; _data_value = value;
}

bool ExportConstraint::encode(kiwi::ByteBuffer &_bb) {
  if (type() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(static_cast<uint32_t>(_data_type));
  }
  if (value() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarFloat(_data_value);
  }
  _bb.writeVarUint(0);
  return true;
}

bool ExportConstraint::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_type))) return false;
        set_type(_data_type);
        break;
      }
      case 2: {
        if (!_bb.readVarFloat(_data_value)) return false;
        set_value(_data_value);
        break;
      }
      default: {
        if (!_schema || !_schema->skipExportConstraintField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::String *ExportSettings::suffix() {
  return _flags[0] & 1 ? &_data_suffix : nullptr;
}

const kiwi::String *ExportSettings::suffix() const {
  return _flags[0] & 1 ? &_data_suffix : nullptr;
}

void ExportSettings::set_suffix(const kiwi::String &value) {
  _flags[0] |= 1; _data_suffix = value;
}

ImageType *ExportSettings::imageType() {
  return _flags[0] & 2 ? &_data_imageType : nullptr;
}

const ImageType *ExportSettings::imageType() const {
  return _flags[0] & 2 ? &_data_imageType : nullptr;
}

void ExportSettings::set_imageType(const ImageType &value) {
  _flags[0] |= 2; _data_imageType = value;
}

ExportConstraint *ExportSettings::constraint() {
  return _data_constraint;
}

const ExportConstraint *ExportSettings::constraint() const {
  return _data_constraint;
}

void ExportSettings::set_constraint(ExportConstraint *value) {
  _data_constraint = value;
}

bool *ExportSettings::svgDataName() {
  return _flags[0] & 8 ? &_data_svgDataName : nullptr;
}

const bool *ExportSettings::svgDataName() const {
  return _flags[0] & 8 ? &_data_svgDataName : nullptr;
}

void ExportSettings::set_svgDataName(const bool &value) {
  _flags[0] |= 8; _data_svgDataName = value;
}

ExportSVGIDMode *ExportSettings::svgIDMode() {
  return _flags[0] & 16 ? &_data_svgIDMode : nullptr;
}

const ExportSVGIDMode *ExportSettings::svgIDMode() const {
  return _flags[0] & 16 ? &_data_svgIDMode : nullptr;
}

void ExportSettings::set_svgIDMode(const ExportSVGIDMode &value) {
  _flags[0] |= 16; _data_svgIDMode = value;
}

bool *ExportSettings::svgOutlineText() {
  return _flags[0] & 32 ? &_data_svgOutlineText : nullptr;
}

const bool *ExportSettings::svgOutlineText() const {
  return _flags[0] & 32 ? &_data_svgOutlineText : nullptr;
}

void ExportSettings::set_svgOutlineText(const bool &value) {
  _flags[0] |= 32; _data_svgOutlineText = value;
}

bool *ExportSettings::contentsOnly() {
  return _flags[0] & 64 ? &_data_contentsOnly : nullptr;
}

const bool *ExportSettings::contentsOnly() const {
  return _flags[0] & 64 ? &_data_contentsOnly : nullptr;
}

void ExportSettings::set_contentsOnly(const bool &value) {
  _flags[0] |= 64; _data_contentsOnly = value;
}

bool *ExportSettings::svgForceStrokeMasks() {
  return _flags[0] & 128 ? &_data_svgForceStrokeMasks : nullptr;
}

const bool *ExportSettings::svgForceStrokeMasks() const {
  return _flags[0] & 128 ? &_data_svgForceStrokeMasks : nullptr;
}

void ExportSettings::set_svgForceStrokeMasks(const bool &value) {
  _flags[0] |= 128; _data_svgForceStrokeMasks = value;
}

bool ExportSettings::encode(kiwi::ByteBuffer &_bb) {
  if (suffix() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeString(_data_suffix.c_str());
  }
  if (imageType() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarUint(static_cast<uint32_t>(_data_imageType));
  }
  if (constraint() != nullptr) {
    _bb.writeVarUint(3);
    if (!_data_constraint->encode(_bb)) return false;
  }
  if (svgDataName() != nullptr) {
    _bb.writeVarUint(4);
    _bb.writeByte(_data_svgDataName);
  }
  if (svgIDMode() != nullptr) {
    _bb.writeVarUint(5);
    _bb.writeVarUint(static_cast<uint32_t>(_data_svgIDMode));
  }
  if (svgOutlineText() != nullptr) {
    _bb.writeVarUint(6);
    _bb.writeByte(_data_svgOutlineText);
  }
  if (contentsOnly() != nullptr) {
    _bb.writeVarUint(7);
    _bb.writeByte(_data_contentsOnly);
  }
  if (svgForceStrokeMasks() != nullptr) {
    _bb.writeVarUint(8);
    _bb.writeByte(_data_svgForceStrokeMasks);
  }
  _bb.writeVarUint(0);
  return true;
}

bool ExportSettings::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readString(_data_suffix, _pool)) return false;
        set_suffix(_data_suffix);
        break;
      }
      case 2: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_imageType))) return false;
        set_imageType(_data_imageType);
        break;
      }
      case 3: {
        _data_constraint = _pool.allocate<ExportConstraint>();
        if (!_data_constraint->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 4: {
        if (!_bb.readByte(_data_svgDataName)) return false;
        set_svgDataName(_data_svgDataName);
        break;
      }
      case 5: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_svgIDMode))) return false;
        set_svgIDMode(_data_svgIDMode);
        break;
      }
      case 6: {
        if (!_bb.readByte(_data_svgOutlineText)) return false;
        set_svgOutlineText(_data_svgOutlineText);
        break;
      }
      case 7: {
        if (!_bb.readByte(_data_contentsOnly)) return false;
        set_contentsOnly(_data_contentsOnly);
        break;
      }
      case 8: {
        if (!_bb.readByte(_data_svgForceStrokeMasks)) return false;
        set_svgForceStrokeMasks(_data_svgForceStrokeMasks);
        break;
      }
      default: {
        if (!_schema || !_schema->skipExportSettingsField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::String *FontName::family() {
  return _flags[0] & 1 ? &_data_family : nullptr;
}

const kiwi::String *FontName::family() const {
  return _flags[0] & 1 ? &_data_family : nullptr;
}

void FontName::set_family(const kiwi::String &value) {
  _flags[0] |= 1; _data_family = value;
}

kiwi::String *FontName::style() {
  return _flags[0] & 2 ? &_data_style : nullptr;
}

const kiwi::String *FontName::style() const {
  return _flags[0] & 2 ? &_data_style : nullptr;
}

void FontName::set_style(const kiwi::String &value) {
  _flags[0] |= 2; _data_style = value;
}

kiwi::String *FontName::postscript() {
  return _flags[0] & 4 ? &_data_postscript : nullptr;
}

const kiwi::String *FontName::postscript() const {
  return _flags[0] & 4 ? &_data_postscript : nullptr;
}

void FontName::set_postscript(const kiwi::String &value) {
  _flags[0] |= 4; _data_postscript = value;
}

bool FontName::encode(kiwi::ByteBuffer &_bb) {
  if (family() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeString(_data_family.c_str());
  }
  if (style() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeString(_data_style.c_str());
  }
  if (postscript() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeString(_data_postscript.c_str());
  }
  _bb.writeVarUint(0);
  return true;
}

bool FontName::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readString(_data_family, _pool)) return false;
        set_family(_data_family);
        break;
      }
      case 2: {
        if (!_bb.readString(_data_style, _pool)) return false;
        set_style(_data_style);
        break;
      }
      case 3: {
        if (!_bb.readString(_data_postscript, _pool)) return false;
        set_postscript(_data_postscript);
        break;
      }
      default: {
        if (!_schema || !_schema->skipFontNameField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::String *TextData::characters() {
  return _flags[0] & 1 ? &_data_characters : nullptr;
}

const kiwi::String *TextData::characters() const {
  return _flags[0] & 1 ? &_data_characters : nullptr;
}

void TextData::set_characters(const kiwi::String &value) {
  _flags[0] |= 1; _data_characters = value;
}

kiwi::Array<int32_t> *TextData::characterStyleIDs() {
  return _flags[0] & 2 ? &_data_characterStyleIDs : nullptr;
}

const kiwi::Array<int32_t> *TextData::characterStyleIDs() const {
  return _flags[0] & 2 ? &_data_characterStyleIDs : nullptr;
}

kiwi::Array<int32_t> &TextData::set_characterStyleIDs(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 2; return _data_characterStyleIDs = pool.array<int32_t>(count);
}

kiwi::Array<TextStyleData> *TextData::styleOverrideTable() {
  return _flags[0] & 4 ? &_data_styleOverrideTable : nullptr;
}

const kiwi::Array<TextStyleData> *TextData::styleOverrideTable() const {
  return _flags[0] & 4 ? &_data_styleOverrideTable : nullptr;
}

kiwi::Array<TextStyleData> &TextData::set_styleOverrideTable(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 4; return _data_styleOverrideTable = pool.array<TextStyleData>(count);
}

Vector *TextData::layoutSize() {
  return _data_layoutSize;
}

const Vector *TextData::layoutSize() const {
  return _data_layoutSize;
}

void TextData::set_layoutSize(Vector *value) {
  _data_layoutSize = value;
}

kiwi::Array<Baseline> *TextData::baselines() {
  return _flags[0] & 16 ? &_data_baselines : nullptr;
}

const kiwi::Array<Baseline> *TextData::baselines() const {
  return _flags[0] & 16 ? &_data_baselines : nullptr;
}

kiwi::Array<Baseline> &TextData::set_baselines(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 16; return _data_baselines = pool.array<Baseline>(count);
}

kiwi::Array<Glyph> *TextData::glyphs() {
  return _flags[0] & 32 ? &_data_glyphs : nullptr;
}

const kiwi::Array<Glyph> *TextData::glyphs() const {
  return _flags[0] & 32 ? &_data_glyphs : nullptr;
}

kiwi::Array<Glyph> &TextData::set_glyphs(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 32; return _data_glyphs = pool.array<Glyph>(count);
}

kiwi::Array<Decoration> *TextData::decorations() {
  return _flags[0] & 64 ? &_data_decorations : nullptr;
}

const kiwi::Array<Decoration> *TextData::decorations() const {
  return _flags[0] & 64 ? &_data_decorations : nullptr;
}

kiwi::Array<Decoration> &TextData::set_decorations(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 64; return _data_decorations = pool.array<Decoration>(count);
}

int32_t *TextData::layoutVersion() {
  return _flags[0] & 128 ? &_data_layoutVersion : nullptr;
}

const int32_t *TextData::layoutVersion() const {
  return _flags[0] & 128 ? &_data_layoutVersion : nullptr;
}

void TextData::set_layoutVersion(const int32_t &value) {
  _flags[0] |= 128; _data_layoutVersion = value;
}

kiwi::Array<FontMetaData> *TextData::fontMetaData() {
  return _flags[0] & 256 ? &_data_fontMetaData : nullptr;
}

const kiwi::Array<FontMetaData> *TextData::fontMetaData() const {
  return _flags[0] & 256 ? &_data_fontMetaData : nullptr;
}

kiwi::Array<FontMetaData> &TextData::set_fontMetaData(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 256; return _data_fontMetaData = pool.array<FontMetaData>(count);
}

kiwi::Array<FontName> *TextData::fallbackFonts() {
  return _flags[0] & 512 ? &_data_fallbackFonts : nullptr;
}

const kiwi::Array<FontName> *TextData::fallbackFonts() const {
  return _flags[0] & 512 ? &_data_fallbackFonts : nullptr;
}

kiwi::Array<FontName> &TextData::set_fallbackFonts(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 512; return _data_fallbackFonts = pool.array<FontName>(count);
}

kiwi::Array<HyperlinkBox> *TextData::hyperlinkBoxes() {
  return _flags[0] & 1024 ? &_data_hyperlinkBoxes : nullptr;
}

const kiwi::Array<HyperlinkBox> *TextData::hyperlinkBoxes() const {
  return _flags[0] & 1024 ? &_data_hyperlinkBoxes : nullptr;
}

kiwi::Array<HyperlinkBox> &TextData::set_hyperlinkBoxes(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 1024; return _data_hyperlinkBoxes = pool.array<HyperlinkBox>(count);
}

kiwi::Array<ParagraphStyle> *TextData::paragraphStyle() {
  return _flags[0] & 2048 ? &_data_paragraphStyle : nullptr;
}

const kiwi::Array<ParagraphStyle> *TextData::paragraphStyle() const {
  return _flags[0] & 2048 ? &_data_paragraphStyle : nullptr;
}

kiwi::Array<ParagraphStyle> &TextData::set_paragraphStyle(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 2048; return _data_paragraphStyle = pool.array<ParagraphStyle>(count);
}

kiwi::Array<PlaceHolder> *TextData::placeHolders() {
  return _flags[0] & 4096 ? &_data_placeHolders : nullptr;
}

const kiwi::Array<PlaceHolder> *TextData::placeHolders() const {
  return _flags[0] & 4096 ? &_data_placeHolders : nullptr;
}

kiwi::Array<PlaceHolder> &TextData::set_placeHolders(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 4096; return _data_placeHolders = pool.array<PlaceHolder>(count);
}

int32_t *TextData::truncationStartIndex() {
  return _flags[0] & 8192 ? &_data_truncationStartIndex : nullptr;
}

const int32_t *TextData::truncationStartIndex() const {
  return _flags[0] & 8192 ? &_data_truncationStartIndex : nullptr;
}

void TextData::set_truncationStartIndex(const int32_t &value) {
  _flags[0] |= 8192; _data_truncationStartIndex = value;
}

float *TextData::truncatedHeight() {
  return _flags[0] & 16384 ? &_data_truncatedHeight : nullptr;
}

const float *TextData::truncatedHeight() const {
  return _flags[0] & 16384 ? &_data_truncatedHeight : nullptr;
}

void TextData::set_truncatedHeight(const float &value) {
  _flags[0] |= 16384; _data_truncatedHeight = value;
}

kiwi::Array<GlyphPose> *TextData::glyphPoses() {
  return _flags[0] & 32768 ? &_data_glyphPoses : nullptr;
}

const kiwi::Array<GlyphPose> *TextData::glyphPoses() const {
  return _flags[0] & 32768 ? &_data_glyphPoses : nullptr;
}

kiwi::Array<GlyphPose> &TextData::set_glyphPoses(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 32768; return _data_glyphPoses = pool.array<GlyphPose>(count);
}

bool *TextData::isDirty() {
  return _flags[0] & 65536 ? &_data_isDirty : nullptr;
}

const bool *TextData::isDirty() const {
  return _flags[0] & 65536 ? &_data_isDirty : nullptr;
}

void TextData::set_isDirty(const bool &value) {
  _flags[0] |= 65536; _data_isDirty = value;
}

bool TextData::encode(kiwi::ByteBuffer &_bb) {
  if (characters() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeString(_data_characters.c_str());
  }
  if (characterStyleIDs() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarUint(_data_characterStyleIDs.size());
    for (int32_t &_it : _data_characterStyleIDs) _bb.writeVarInt(_it);
  }
  if (styleOverrideTable() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeVarUint(_data_styleOverrideTable.size());
    for (TextStyleData &_it : _data_styleOverrideTable) if (!_it.encode(_bb)) return false;
  }
  if (layoutSize() != nullptr) {
    _bb.writeVarUint(4);
    if (!_data_layoutSize->encode(_bb)) return false;
  }
  if (baselines() != nullptr) {
    _bb.writeVarUint(5);
    _bb.writeVarUint(_data_baselines.size());
    for (Baseline &_it : _data_baselines) if (!_it.encode(_bb)) return false;
  }
  if (glyphs() != nullptr) {
    _bb.writeVarUint(6);
    _bb.writeVarUint(_data_glyphs.size());
    for (Glyph &_it : _data_glyphs) if (!_it.encode(_bb)) return false;
  }
  if (decorations() != nullptr) {
    _bb.writeVarUint(7);
    _bb.writeVarUint(_data_decorations.size());
    for (Decoration &_it : _data_decorations) if (!_it.encode(_bb)) return false;
  }
  if (layoutVersion() != nullptr) {
    _bb.writeVarUint(8);
    _bb.writeVarInt(_data_layoutVersion);
  }
  if (fontMetaData() != nullptr) {
    _bb.writeVarUint(9);
    _bb.writeVarUint(_data_fontMetaData.size());
    for (FontMetaData &_it : _data_fontMetaData) if (!_it.encode(_bb)) return false;
  }
  if (fallbackFonts() != nullptr) {
    _bb.writeVarUint(10);
    _bb.writeVarUint(_data_fallbackFonts.size());
    for (FontName &_it : _data_fallbackFonts) if (!_it.encode(_bb)) return false;
  }
  if (hyperlinkBoxes() != nullptr) {
    _bb.writeVarUint(11);
    _bb.writeVarUint(_data_hyperlinkBoxes.size());
    for (HyperlinkBox &_it : _data_hyperlinkBoxes) if (!_it.encode(_bb)) return false;
  }
  if (paragraphStyle() != nullptr) {
    _bb.writeVarUint(12);
    _bb.writeVarUint(_data_paragraphStyle.size());
    for (ParagraphStyle &_it : _data_paragraphStyle) if (!_it.encode(_bb)) return false;
  }
  if (placeHolders() != nullptr) {
    _bb.writeVarUint(13);
    _bb.writeVarUint(_data_placeHolders.size());
    for (PlaceHolder &_it : _data_placeHolders) if (!_it.encode(_bb)) return false;
  }
  if (truncationStartIndex() != nullptr) {
    _bb.writeVarUint(14);
    _bb.writeVarInt(_data_truncationStartIndex);
  }
  if (truncatedHeight() != nullptr) {
    _bb.writeVarUint(15);
    _bb.writeVarFloat(_data_truncatedHeight);
  }
  if (glyphPoses() != nullptr) {
    _bb.writeVarUint(16);
    _bb.writeVarUint(_data_glyphPoses.size());
    for (GlyphPose &_it : _data_glyphPoses) if (!_it.encode(_bb)) return false;
  }
  if (isDirty() != nullptr) {
    _bb.writeVarUint(17);
    _bb.writeByte(_data_isDirty);
  }
  _bb.writeVarUint(0);
  return true;
}

bool TextData::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readString(_data_characters, _pool)) return false;
        set_characters(_data_characters);
        break;
      }
      case 2: {
        if (!_bb.readVarUint(_count)) return false;
        for (int32_t &_it : set_characterStyleIDs(_pool, _count)) if (!_bb.readVarInt(_it)) return false;
        break;
      }
      case 3: {
        if (!_bb.readVarUint(_count)) return false;
        for (TextStyleData &_it : set_styleOverrideTable(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 4: {
        _data_layoutSize = _pool.allocate<Vector>();
        if (!_data_layoutSize->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 5: {
        if (!_bb.readVarUint(_count)) return false;
        for (Baseline &_it : set_baselines(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 6: {
        if (!_bb.readVarUint(_count)) return false;
        for (Glyph &_it : set_glyphs(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 7: {
        if (!_bb.readVarUint(_count)) return false;
        for (Decoration &_it : set_decorations(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 8: {
        if (!_bb.readVarInt(_data_layoutVersion)) return false;
        set_layoutVersion(_data_layoutVersion);
        break;
      }
      case 9: {
        if (!_bb.readVarUint(_count)) return false;
        for (FontMetaData &_it : set_fontMetaData(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 10: {
        if (!_bb.readVarUint(_count)) return false;
        for (FontName &_it : set_fallbackFonts(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 11: {
        if (!_bb.readVarUint(_count)) return false;
        for (HyperlinkBox &_it : set_hyperlinkBoxes(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 12: {
        if (!_bb.readVarUint(_count)) return false;
        for (ParagraphStyle &_it : set_paragraphStyle(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 13: {
        if (!_bb.readVarUint(_count)) return false;
        for (PlaceHolder &_it : set_placeHolders(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 14: {
        if (!_bb.readVarInt(_data_truncationStartIndex)) return false;
        set_truncationStartIndex(_data_truncationStartIndex);
        break;
      }
      case 15: {
        if (!_bb.readVarFloat(_data_truncatedHeight)) return false;
        set_truncatedHeight(_data_truncatedHeight);
        break;
      }
      case 16: {
        if (!_bb.readVarUint(_count)) return false;
        for (GlyphPose &_it : set_glyphPoses(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 17: {
        if (!_bb.readByte(_data_isDirty)) return false;
        set_isDirty(_data_isDirty);
        break;
      }
      default: {
        if (!_schema || !_schema->skipTextDataField(_bb, _type)) return false;
        break;
      }
    }
  }
}

Rect *HyperlinkBox::bounds() {
  return _data_bounds;
}

const Rect *HyperlinkBox::bounds() const {
  return _data_bounds;
}

void HyperlinkBox::set_bounds(Rect *value) {
  _data_bounds = value;
}

kiwi::String *HyperlinkBox::url() {
  return _flags[0] & 2 ? &_data_url : nullptr;
}

const kiwi::String *HyperlinkBox::url() const {
  return _flags[0] & 2 ? &_data_url : nullptr;
}

void HyperlinkBox::set_url(const kiwi::String &value) {
  _flags[0] |= 2; _data_url = value;
}

GUID *HyperlinkBox::guid() {
  return _data_guid;
}

const GUID *HyperlinkBox::guid() const {
  return _data_guid;
}

void HyperlinkBox::set_guid(GUID *value) {
  _data_guid = value;
}

int32_t *HyperlinkBox::hyperlinkID() {
  return _flags[0] & 8 ? &_data_hyperlinkID : nullptr;
}

const int32_t *HyperlinkBox::hyperlinkID() const {
  return _flags[0] & 8 ? &_data_hyperlinkID : nullptr;
}

void HyperlinkBox::set_hyperlinkID(const int32_t &value) {
  _flags[0] |= 8; _data_hyperlinkID = value;
}

bool HyperlinkBox::encode(kiwi::ByteBuffer &_bb) {
  if (bounds() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_bounds->encode(_bb)) return false;
  }
  if (url() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeString(_data_url.c_str());
  }
  if (guid() != nullptr) {
    _bb.writeVarUint(3);
    if (!_data_guid->encode(_bb)) return false;
  }
  if (hyperlinkID() != nullptr) {
    _bb.writeVarUint(4);
    _bb.writeVarInt(_data_hyperlinkID);
  }
  _bb.writeVarUint(0);
  return true;
}

bool HyperlinkBox::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_bounds = _pool.allocate<Rect>();
        if (!_data_bounds->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        if (!_bb.readString(_data_url, _pool)) return false;
        set_url(_data_url);
        break;
      }
      case 3: {
        _data_guid = _pool.allocate<GUID>();
        if (!_data_guid->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 4: {
        if (!_bb.readVarInt(_data_hyperlinkID)) return false;
        set_hyperlinkID(_data_hyperlinkID);
        break;
      }
      default: {
        if (!_schema || !_schema->skipHyperlinkBoxField(_bb, _type)) return false;
        break;
      }
    }
  }
}

FontName *FontMetaData::key() {
  return _data_key;
}

const FontName *FontMetaData::key() const {
  return _data_key;
}

void FontMetaData::set_key(FontName *value) {
  _data_key = value;
}

float *FontMetaData::fontLineHeight() {
  return _flags[0] & 2 ? &_data_fontLineHeight : nullptr;
}

const float *FontMetaData::fontLineHeight() const {
  return _flags[0] & 2 ? &_data_fontLineHeight : nullptr;
}

void FontMetaData::set_fontLineHeight(const float &value) {
  _flags[0] |= 2; _data_fontLineHeight = value;
}

kiwi::Array<uint8_t> *FontMetaData::fontDigest() {
  return _flags[0] & 4 ? &_data_fontDigest : nullptr;
}

const kiwi::Array<uint8_t> *FontMetaData::fontDigest() const {
  return _flags[0] & 4 ? &_data_fontDigest : nullptr;
}

kiwi::Array<uint8_t> &FontMetaData::set_fontDigest(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 4; return _data_fontDigest = pool.array<uint8_t>(count);
}

FontStyle *FontMetaData::fontStyle() {
  return _flags[0] & 8 ? &_data_fontStyle : nullptr;
}

const FontStyle *FontMetaData::fontStyle() const {
  return _flags[0] & 8 ? &_data_fontStyle : nullptr;
}

void FontMetaData::set_fontStyle(const FontStyle &value) {
  _flags[0] |= 8; _data_fontStyle = value;
}

int32_t *FontMetaData::fontWeight() {
  return _flags[0] & 16 ? &_data_fontWeight : nullptr;
}

const int32_t *FontMetaData::fontWeight() const {
  return _flags[0] & 16 ? &_data_fontWeight : nullptr;
}

void FontMetaData::set_fontWeight(const int32_t &value) {
  _flags[0] |= 16; _data_fontWeight = value;
}

bool FontMetaData::encode(kiwi::ByteBuffer &_bb) {
  if (key() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_key->encode(_bb)) return false;
  }
  if (fontLineHeight() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarFloat(_data_fontLineHeight);
  }
  if (fontDigest() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeVarUint(_data_fontDigest.size());
    for (uint8_t &_it : _data_fontDigest) _bb.writeByte(_it);
  }
  if (fontStyle() != nullptr) {
    _bb.writeVarUint(4);
    _bb.writeVarUint(static_cast<uint32_t>(_data_fontStyle));
  }
  if (fontWeight() != nullptr) {
    _bb.writeVarUint(5);
    _bb.writeVarInt(_data_fontWeight);
  }
  _bb.writeVarUint(0);
  return true;
}

bool FontMetaData::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_key = _pool.allocate<FontName>();
        if (!_data_key->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        if (!_bb.readVarFloat(_data_fontLineHeight)) return false;
        set_fontLineHeight(_data_fontLineHeight);
        break;
      }
      case 3: {
        if (!_bb.readVarUint(_count)) return false;
        for (uint8_t &_it : set_fontDigest(_pool, _count)) if (!_bb.readByte(_it)) return false;
        break;
      }
      case 4: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_fontStyle))) return false;
        set_fontStyle(_data_fontStyle);
        break;
      }
      case 5: {
        if (!_bb.readVarInt(_data_fontWeight)) return false;
        set_fontWeight(_data_fontWeight);
        break;
      }
      default: {
        if (!_schema || !_schema->skipFontMetaDataField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::Array<Rect> *Decoration::rects() {
  return _flags[0] & 1 ? &_data_rects : nullptr;
}

const kiwi::Array<Rect> *Decoration::rects() const {
  return _flags[0] & 1 ? &_data_rects : nullptr;
}

kiwi::Array<Rect> &Decoration::set_rects(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 1; return _data_rects = pool.array<Rect>(count);
}

int32_t *Decoration::styleID() {
  return _flags[0] & 2 ? &_data_styleID : nullptr;
}

const int32_t *Decoration::styleID() const {
  return _flags[0] & 2 ? &_data_styleID : nullptr;
}

void Decoration::set_styleID(const int32_t &value) {
  _flags[0] |= 2; _data_styleID = value;
}

bool Decoration::encode(kiwi::ByteBuffer &_bb) {
  if (rects() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(_data_rects.size());
    for (Rect &_it : _data_rects) if (!_it.encode(_bb)) return false;
  }
  if (styleID() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarInt(_data_styleID);
  }
  _bb.writeVarUint(0);
  return true;
}

bool Decoration::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(_count)) return false;
        for (Rect &_it : set_rects(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        if (!_bb.readVarInt(_data_styleID)) return false;
        set_styleID(_data_styleID);
        break;
      }
      default: {
        if (!_schema || !_schema->skipDecorationField(_bb, _type)) return false;
        break;
      }
    }
  }
}

int32_t *Glyph::blobIndex() {
  return _flags[0] & 1 ? &_data_blobIndex : nullptr;
}

const int32_t *Glyph::blobIndex() const {
  return _flags[0] & 1 ? &_data_blobIndex : nullptr;
}

void Glyph::set_blobIndex(const int32_t &value) {
  _flags[0] |= 1; _data_blobIndex = value;
}

Vector *Glyph::position() {
  return _data_position;
}

const Vector *Glyph::position() const {
  return _data_position;
}

void Glyph::set_position(Vector *value) {
  _data_position = value;
}

int32_t *Glyph::styleID() {
  return _flags[0] & 4 ? &_data_styleID : nullptr;
}

const int32_t *Glyph::styleID() const {
  return _flags[0] & 4 ? &_data_styleID : nullptr;
}

void Glyph::set_styleID(const int32_t &value) {
  _flags[0] |= 4; _data_styleID = value;
}

float *Glyph::fontSize() {
  return _flags[0] & 8 ? &_data_fontSize : nullptr;
}

const float *Glyph::fontSize() const {
  return _flags[0] & 8 ? &_data_fontSize : nullptr;
}

void Glyph::set_fontSize(const float &value) {
  _flags[0] |= 8; _data_fontSize = value;
}

int32_t *Glyph::firstCharacter() {
  return _flags[0] & 16 ? &_data_firstCharacter : nullptr;
}

const int32_t *Glyph::firstCharacter() const {
  return _flags[0] & 16 ? &_data_firstCharacter : nullptr;
}

void Glyph::set_firstCharacter(const int32_t &value) {
  _flags[0] |= 16; _data_firstCharacter = value;
}

float *Glyph::advance() {
  return _flags[0] & 32 ? &_data_advance : nullptr;
}

const float *Glyph::advance() const {
  return _flags[0] & 32 ? &_data_advance : nullptr;
}

void Glyph::set_advance(const float &value) {
  _flags[0] |= 32; _data_advance = value;
}

bool Glyph::encode(kiwi::ByteBuffer &_bb) {
  if (blobIndex() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarInt(_data_blobIndex);
  }
  if (position() != nullptr) {
    _bb.writeVarUint(2);
    if (!_data_position->encode(_bb)) return false;
  }
  if (styleID() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeVarInt(_data_styleID);
  }
  if (fontSize() != nullptr) {
    _bb.writeVarUint(4);
    _bb.writeVarFloat(_data_fontSize);
  }
  if (firstCharacter() != nullptr) {
    _bb.writeVarUint(5);
    _bb.writeVarInt(_data_firstCharacter);
  }
  if (advance() != nullptr) {
    _bb.writeVarUint(6);
    _bb.writeVarFloat(_data_advance);
  }
  _bb.writeVarUint(0);
  return true;
}

bool Glyph::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarInt(_data_blobIndex)) return false;
        set_blobIndex(_data_blobIndex);
        break;
      }
      case 2: {
        _data_position = _pool.allocate<Vector>();
        if (!_data_position->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 3: {
        if (!_bb.readVarInt(_data_styleID)) return false;
        set_styleID(_data_styleID);
        break;
      }
      case 4: {
        if (!_bb.readVarFloat(_data_fontSize)) return false;
        set_fontSize(_data_fontSize);
        break;
      }
      case 5: {
        if (!_bb.readVarInt(_data_firstCharacter)) return false;
        set_firstCharacter(_data_firstCharacter);
        break;
      }
      case 6: {
        if (!_bb.readVarFloat(_data_advance)) return false;
        set_advance(_data_advance);
        break;
      }
      default: {
        if (!_schema || !_schema->skipGlyphField(_bb, _type)) return false;
        break;
      }
    }
  }
}

TextListStyle *ParagraphStyle::listType() {
  return _flags[0] & 1 ? &_data_listType : nullptr;
}

const TextListStyle *ParagraphStyle::listType() const {
  return _flags[0] & 1 ? &_data_listType : nullptr;
}

void ParagraphStyle::set_listType(const TextListStyle &value) {
  _flags[0] |= 1; _data_listType = value;
}

uint32_t *ParagraphStyle::indentationLevel() {
  return _flags[0] & 2 ? &_data_indentationLevel : nullptr;
}

const uint32_t *ParagraphStyle::indentationLevel() const {
  return _flags[0] & 2 ? &_data_indentationLevel : nullptr;
}

void ParagraphStyle::set_indentationLevel(const uint32_t &value) {
  _flags[0] |= 2; _data_indentationLevel = value;
}

uint32_t *ParagraphStyle::listStartOffset() {
  return _flags[0] & 4 ? &_data_listStartOffset : nullptr;
}

const uint32_t *ParagraphStyle::listStartOffset() const {
  return _flags[0] & 4 ? &_data_listStartOffset : nullptr;
}

void ParagraphStyle::set_listStartOffset(const uint32_t &value) {
  _flags[0] |= 4; _data_listStartOffset = value;
}

bool *ParagraphStyle::isFirstLineOfList() {
  return _flags[0] & 8 ? &_data_isFirstLineOfList : nullptr;
}

const bool *ParagraphStyle::isFirstLineOfList() const {
  return _flags[0] & 8 ? &_data_isFirstLineOfList : nullptr;
}

void ParagraphStyle::set_isFirstLineOfList(const bool &value) {
  _flags[0] |= 8; _data_isFirstLineOfList = value;
}

Directionality *ParagraphStyle::sourceDirectionality() {
  return _flags[0] & 16 ? &_data_sourceDirectionality : nullptr;
}

const Directionality *ParagraphStyle::sourceDirectionality() const {
  return _flags[0] & 16 ? &_data_sourceDirectionality : nullptr;
}

void ParagraphStyle::set_sourceDirectionality(const Directionality &value) {
  _flags[0] |= 16; _data_sourceDirectionality = value;
}

Directionality *ParagraphStyle::directionality() {
  return _flags[0] & 32 ? &_data_directionality : nullptr;
}

const Directionality *ParagraphStyle::directionality() const {
  return _flags[0] & 32 ? &_data_directionality : nullptr;
}

void ParagraphStyle::set_directionality(const Directionality &value) {
  _flags[0] |= 32; _data_directionality = value;
}

bool ParagraphStyle::encode(kiwi::ByteBuffer &_bb) {
  if (listType() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(static_cast<uint32_t>(_data_listType));
  }
  if (indentationLevel() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarUint(_data_indentationLevel);
  }
  if (listStartOffset() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeVarUint(_data_listStartOffset);
  }
  if (isFirstLineOfList() != nullptr) {
    _bb.writeVarUint(4);
    _bb.writeByte(_data_isFirstLineOfList);
  }
  if (sourceDirectionality() != nullptr) {
    _bb.writeVarUint(5);
    _bb.writeVarUint(static_cast<uint32_t>(_data_sourceDirectionality));
  }
  if (directionality() != nullptr) {
    _bb.writeVarUint(6);
    _bb.writeVarUint(static_cast<uint32_t>(_data_directionality));
  }
  _bb.writeVarUint(0);
  return true;
}

bool ParagraphStyle::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_listType))) return false;
        set_listType(_data_listType);
        break;
      }
      case 2: {
        if (!_bb.readVarUint(_data_indentationLevel)) return false;
        set_indentationLevel(_data_indentationLevel);
        break;
      }
      case 3: {
        if (!_bb.readVarUint(_data_listStartOffset)) return false;
        set_listStartOffset(_data_listStartOffset);
        break;
      }
      case 4: {
        if (!_bb.readByte(_data_isFirstLineOfList)) return false;
        set_isFirstLineOfList(_data_isFirstLineOfList);
        break;
      }
      case 5: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_sourceDirectionality))) return false;
        set_sourceDirectionality(_data_sourceDirectionality);
        break;
      }
      case 6: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_directionality))) return false;
        set_directionality(_data_directionality);
        break;
      }
      default: {
        if (!_schema || !_schema->skipParagraphStyleField(_bb, _type)) return false;
        break;
      }
    }
  }
}

Vector *Baseline::position() {
  return _data_position;
}

const Vector *Baseline::position() const {
  return _data_position;
}

void Baseline::set_position(Vector *value) {
  _data_position = value;
}

float *Baseline::width() {
  return _flags[0] & 2 ? &_data_width : nullptr;
}

const float *Baseline::width() const {
  return _flags[0] & 2 ? &_data_width : nullptr;
}

void Baseline::set_width(const float &value) {
  _flags[0] |= 2; _data_width = value;
}

float *Baseline::lineY() {
  return _flags[0] & 4 ? &_data_lineY : nullptr;
}

const float *Baseline::lineY() const {
  return _flags[0] & 4 ? &_data_lineY : nullptr;
}

void Baseline::set_lineY(const float &value) {
  _flags[0] |= 4; _data_lineY = value;
}

float *Baseline::lineHeight() {
  return _flags[0] & 8 ? &_data_lineHeight : nullptr;
}

const float *Baseline::lineHeight() const {
  return _flags[0] & 8 ? &_data_lineHeight : nullptr;
}

void Baseline::set_lineHeight(const float &value) {
  _flags[0] |= 8; _data_lineHeight = value;
}

float *Baseline::lineAscent() {
  return _flags[0] & 16 ? &_data_lineAscent : nullptr;
}

const float *Baseline::lineAscent() const {
  return _flags[0] & 16 ? &_data_lineAscent : nullptr;
}

void Baseline::set_lineAscent(const float &value) {
  _flags[0] |= 16; _data_lineAscent = value;
}

int32_t *Baseline::firstCharacter() {
  return _flags[0] & 32 ? &_data_firstCharacter : nullptr;
}

const int32_t *Baseline::firstCharacter() const {
  return _flags[0] & 32 ? &_data_firstCharacter : nullptr;
}

void Baseline::set_firstCharacter(const int32_t &value) {
  _flags[0] |= 32; _data_firstCharacter = value;
}

int32_t *Baseline::endCharacter() {
  return _flags[0] & 64 ? &_data_endCharacter : nullptr;
}

const int32_t *Baseline::endCharacter() const {
  return _flags[0] & 64 ? &_data_endCharacter : nullptr;
}

void Baseline::set_endCharacter(const int32_t &value) {
  _flags[0] |= 64; _data_endCharacter = value;
}

bool Baseline::encode(kiwi::ByteBuffer &_bb) {
  if (position() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_position->encode(_bb)) return false;
  }
  if (width() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarFloat(_data_width);
  }
  if (lineY() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeVarFloat(_data_lineY);
  }
  if (lineHeight() != nullptr) {
    _bb.writeVarUint(4);
    _bb.writeVarFloat(_data_lineHeight);
  }
  if (lineAscent() != nullptr) {
    _bb.writeVarUint(5);
    _bb.writeVarFloat(_data_lineAscent);
  }
  if (firstCharacter() != nullptr) {
    _bb.writeVarUint(6);
    _bb.writeVarInt(_data_firstCharacter);
  }
  if (endCharacter() != nullptr) {
    _bb.writeVarUint(7);
    _bb.writeVarInt(_data_endCharacter);
  }
  _bb.writeVarUint(0);
  return true;
}

bool Baseline::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_position = _pool.allocate<Vector>();
        if (!_data_position->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        if (!_bb.readVarFloat(_data_width)) return false;
        set_width(_data_width);
        break;
      }
      case 3: {
        if (!_bb.readVarFloat(_data_lineY)) return false;
        set_lineY(_data_lineY);
        break;
      }
      case 4: {
        if (!_bb.readVarFloat(_data_lineHeight)) return false;
        set_lineHeight(_data_lineHeight);
        break;
      }
      case 5: {
        if (!_bb.readVarFloat(_data_lineAscent)) return false;
        set_lineAscent(_data_lineAscent);
        break;
      }
      case 6: {
        if (!_bb.readVarInt(_data_firstCharacter)) return false;
        set_firstCharacter(_data_firstCharacter);
        break;
      }
      case 7: {
        if (!_bb.readVarInt(_data_endCharacter)) return false;
        set_endCharacter(_data_endCharacter);
        break;
      }
      default: {
        if (!_schema || !_schema->skipBaselineField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::Array<int32_t> *KeyTrigger::keyCodes() {
  return _flags[0] & 1 ? &_data_keyCodes : nullptr;
}

const kiwi::Array<int32_t> *KeyTrigger::keyCodes() const {
  return _flags[0] & 1 ? &_data_keyCodes : nullptr;
}

kiwi::Array<int32_t> &KeyTrigger::set_keyCodes(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 1; return _data_keyCodes = pool.array<int32_t>(count);
}

TriggerDevice *KeyTrigger::triggerDevice() {
  return _flags[0] & 2 ? &_data_triggerDevice : nullptr;
}

const TriggerDevice *KeyTrigger::triggerDevice() const {
  return _flags[0] & 2 ? &_data_triggerDevice : nullptr;
}

void KeyTrigger::set_triggerDevice(const TriggerDevice &value) {
  _flags[0] |= 2; _data_triggerDevice = value;
}

bool KeyTrigger::encode(kiwi::ByteBuffer &_bb) {
  if (keyCodes() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(_data_keyCodes.size());
    for (int32_t &_it : _data_keyCodes) _bb.writeVarInt(_it);
  }
  if (triggerDevice() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarUint(static_cast<uint32_t>(_data_triggerDevice));
  }
  _bb.writeVarUint(0);
  return true;
}

bool KeyTrigger::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(_count)) return false;
        for (int32_t &_it : set_keyCodes(_pool, _count)) if (!_bb.readVarInt(_it)) return false;
        break;
      }
      case 2: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_triggerDevice))) return false;
        set_triggerDevice(_data_triggerDevice);
        break;
      }
      default: {
        if (!_schema || !_schema->skipKeyTriggerField(_bb, _type)) return false;
        break;
      }
    }
  }
}

PrototypeDeviceType *PrototypeDevice::type() {
  return _flags[0] & 1 ? &_data_type : nullptr;
}

const PrototypeDeviceType *PrototypeDevice::type() const {
  return _flags[0] & 1 ? &_data_type : nullptr;
}

void PrototypeDevice::set_type(const PrototypeDeviceType &value) {
  _flags[0] |= 1; _data_type = value;
}

Vector *PrototypeDevice::size() {
  return _data_size;
}

const Vector *PrototypeDevice::size() const {
  return _data_size;
}

void PrototypeDevice::set_size(Vector *value) {
  _data_size = value;
}

kiwi::String *PrototypeDevice::presetIdentifier() {
  return _flags[0] & 4 ? &_data_presetIdentifier : nullptr;
}

const kiwi::String *PrototypeDevice::presetIdentifier() const {
  return _flags[0] & 4 ? &_data_presetIdentifier : nullptr;
}

void PrototypeDevice::set_presetIdentifier(const kiwi::String &value) {
  _flags[0] |= 4; _data_presetIdentifier = value;
}

DeviceRotation *PrototypeDevice::rotation() {
  return _flags[0] & 8 ? &_data_rotation : nullptr;
}

const DeviceRotation *PrototypeDevice::rotation() const {
  return _flags[0] & 8 ? &_data_rotation : nullptr;
}

void PrototypeDevice::set_rotation(const DeviceRotation &value) {
  _flags[0] |= 8; _data_rotation = value;
}

bool PrototypeDevice::encode(kiwi::ByteBuffer &_bb) {
  if (type() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(static_cast<uint32_t>(_data_type));
  }
  if (size() != nullptr) {
    _bb.writeVarUint(2);
    if (!_data_size->encode(_bb)) return false;
  }
  if (presetIdentifier() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeString(_data_presetIdentifier.c_str());
  }
  if (rotation() != nullptr) {
    _bb.writeVarUint(4);
    _bb.writeVarUint(static_cast<uint32_t>(_data_rotation));
  }
  _bb.writeVarUint(0);
  return true;
}

bool PrototypeDevice::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_type))) return false;
        set_type(_data_type);
        break;
      }
      case 2: {
        _data_size = _pool.allocate<Vector>();
        if (!_data_size->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 3: {
        if (!_bb.readString(_data_presetIdentifier, _pool)) return false;
        set_presetIdentifier(_data_presetIdentifier);
        break;
      }
      case 4: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_rotation))) return false;
        set_rotation(_data_rotation);
        break;
      }
      default: {
        if (!_schema || !_schema->skipPrototypeDeviceField(_bb, _type)) return false;
        break;
      }
    }
  }
}

GUID *PrototypeInteraction::id() {
  return _data_id;
}

const GUID *PrototypeInteraction::id() const {
  return _data_id;
}

void PrototypeInteraction::set_id(GUID *value) {
  _data_id = value;
}

PrototypeEvent *PrototypeInteraction::event() {
  return _data_event;
}

const PrototypeEvent *PrototypeInteraction::event() const {
  return _data_event;
}

void PrototypeInteraction::set_event(PrototypeEvent *value) {
  _data_event = value;
}

kiwi::Array<PrototypeAction> *PrototypeInteraction::actions() {
  return _flags[0] & 4 ? &_data_actions : nullptr;
}

const kiwi::Array<PrototypeAction> *PrototypeInteraction::actions() const {
  return _flags[0] & 4 ? &_data_actions : nullptr;
}

kiwi::Array<PrototypeAction> &PrototypeInteraction::set_actions(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 4; return _data_actions = pool.array<PrototypeAction>(count);
}

bool *PrototypeInteraction::isDeleted() {
  return _flags[0] & 8 ? &_data_isDeleted : nullptr;
}

const bool *PrototypeInteraction::isDeleted() const {
  return _flags[0] & 8 ? &_data_isDeleted : nullptr;
}

void PrototypeInteraction::set_isDeleted(const bool &value) {
  _flags[0] |= 8; _data_isDeleted = value;
}

bool PrototypeInteraction::encode(kiwi::ByteBuffer &_bb) {
  if (id() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_id->encode(_bb)) return false;
  }
  if (event() != nullptr) {
    _bb.writeVarUint(2);
    if (!_data_event->encode(_bb)) return false;
  }
  if (actions() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeVarUint(_data_actions.size());
    for (PrototypeAction &_it : _data_actions) if (!_it.encode(_bb)) return false;
  }
  if (isDeleted() != nullptr) {
    _bb.writeVarUint(4);
    _bb.writeByte(_data_isDeleted);
  }
  _bb.writeVarUint(0);
  return true;
}

bool PrototypeInteraction::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_id = _pool.allocate<GUID>();
        if (!_data_id->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        _data_event = _pool.allocate<PrototypeEvent>();
        if (!_data_event->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 3: {
        if (!_bb.readVarUint(_count)) return false;
        for (PrototypeAction &_it : set_actions(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 4: {
        if (!_bb.readByte(_data_isDeleted)) return false;
        set_isDeleted(_data_isDeleted);
        break;
      }
      default: {
        if (!_schema || !_schema->skipPrototypeInteractionField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::Array<PrototypeAction> *ConditionalActions::actions() {
  return _flags[0] & 1 ? &_data_actions : nullptr;
}

const kiwi::Array<PrototypeAction> *ConditionalActions::actions() const {
  return _flags[0] & 1 ? &_data_actions : nullptr;
}

kiwi::Array<PrototypeAction> &ConditionalActions::set_actions(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 1; return _data_actions = pool.array<PrototypeAction>(count);
}

VariableData *ConditionalActions::condition() {
  return _data_condition;
}

const VariableData *ConditionalActions::condition() const {
  return _data_condition;
}

void ConditionalActions::set_condition(VariableData *value) {
  _data_condition = value;
}

bool ConditionalActions::encode(kiwi::ByteBuffer &_bb) {
  if (actions() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(_data_actions.size());
    for (PrototypeAction &_it : _data_actions) if (!_it.encode(_bb)) return false;
  }
  if (condition() != nullptr) {
    _bb.writeVarUint(2);
    if (!_data_condition->encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool ConditionalActions::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(_count)) return false;
        for (PrototypeAction &_it : set_actions(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        _data_condition = _pool.allocate<VariableData>();
        if (!_data_condition->decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipConditionalActionsField(_bb, _type)) return false;
        break;
      }
    }
  }
}

bool *VideoPlayback::autoplay() {
  return _flags[0] & 1 ? &_data_autoplay : nullptr;
}

const bool *VideoPlayback::autoplay() const {
  return _flags[0] & 1 ? &_data_autoplay : nullptr;
}

void VideoPlayback::set_autoplay(const bool &value) {
  _flags[0] |= 1; _data_autoplay = value;
}

bool *VideoPlayback::mediaLoop() {
  return _flags[0] & 2 ? &_data_mediaLoop : nullptr;
}

const bool *VideoPlayback::mediaLoop() const {
  return _flags[0] & 2 ? &_data_mediaLoop : nullptr;
}

void VideoPlayback::set_mediaLoop(const bool &value) {
  _flags[0] |= 2; _data_mediaLoop = value;
}

bool *VideoPlayback::muted() {
  return _flags[0] & 4 ? &_data_muted : nullptr;
}

const bool *VideoPlayback::muted() const {
  return _flags[0] & 4 ? &_data_muted : nullptr;
}

void VideoPlayback::set_muted(const bool &value) {
  _flags[0] |= 4; _data_muted = value;
}

bool *VideoPlayback::showControls() {
  return _flags[0] & 8 ? &_data_showControls : nullptr;
}

const bool *VideoPlayback::showControls() const {
  return _flags[0] & 8 ? &_data_showControls : nullptr;
}

void VideoPlayback::set_showControls(const bool &value) {
  _flags[0] |= 8; _data_showControls = value;
}

int32_t *VideoPlayback::startTimeMs() {
  return _flags[0] & 16 ? &_data_startTimeMs : nullptr;
}

const int32_t *VideoPlayback::startTimeMs() const {
  return _flags[0] & 16 ? &_data_startTimeMs : nullptr;
}

void VideoPlayback::set_startTimeMs(const int32_t &value) {
  _flags[0] |= 16; _data_startTimeMs = value;
}

int32_t *VideoPlayback::endTimeMs() {
  return _flags[0] & 32 ? &_data_endTimeMs : nullptr;
}

const int32_t *VideoPlayback::endTimeMs() const {
  return _flags[0] & 32 ? &_data_endTimeMs : nullptr;
}

void VideoPlayback::set_endTimeMs(const int32_t &value) {
  _flags[0] |= 32; _data_endTimeMs = value;
}

bool VideoPlayback::encode(kiwi::ByteBuffer &_bb) {
  if (autoplay() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeByte(_data_autoplay);
  }
  if (mediaLoop() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeByte(_data_mediaLoop);
  }
  if (muted() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeByte(_data_muted);
  }
  if (showControls() != nullptr) {
    _bb.writeVarUint(4);
    _bb.writeByte(_data_showControls);
  }
  if (startTimeMs() != nullptr) {
    _bb.writeVarUint(5);
    _bb.writeVarInt(_data_startTimeMs);
  }
  if (endTimeMs() != nullptr) {
    _bb.writeVarUint(6);
    _bb.writeVarInt(_data_endTimeMs);
  }
  _bb.writeVarUint(0);
  return true;
}

bool VideoPlayback::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readByte(_data_autoplay)) return false;
        set_autoplay(_data_autoplay);
        break;
      }
      case 2: {
        if (!_bb.readByte(_data_mediaLoop)) return false;
        set_mediaLoop(_data_mediaLoop);
        break;
      }
      case 3: {
        if (!_bb.readByte(_data_muted)) return false;
        set_muted(_data_muted);
        break;
      }
      case 4: {
        if (!_bb.readByte(_data_showControls)) return false;
        set_showControls(_data_showControls);
        break;
      }
      case 5: {
        if (!_bb.readVarInt(_data_startTimeMs)) return false;
        set_startTimeMs(_data_startTimeMs);
        break;
      }
      case 6: {
        if (!_bb.readVarInt(_data_endTimeMs)) return false;
        set_endTimeMs(_data_endTimeMs);
        break;
      }
      default: {
        if (!_schema || !_schema->skipVideoPlaybackField(_bb, _type)) return false;
        break;
      }
    }
  }
}

float *VariableWidthPoint::position() {
  return _flags[0] & 1 ? &_data_position : nullptr;
}

const float *VariableWidthPoint::position() const {
  return _flags[0] & 1 ? &_data_position : nullptr;
}

void VariableWidthPoint::set_position(const float &value) {
  _flags[0] |= 1; _data_position = value;
}

float *VariableWidthPoint::ascent() {
  return _flags[0] & 2 ? &_data_ascent : nullptr;
}

const float *VariableWidthPoint::ascent() const {
  return _flags[0] & 2 ? &_data_ascent : nullptr;
}

void VariableWidthPoint::set_ascent(const float &value) {
  _flags[0] |= 2; _data_ascent = value;
}

float *VariableWidthPoint::descent() {
  return _flags[0] & 4 ? &_data_descent : nullptr;
}

const float *VariableWidthPoint::descent() const {
  return _flags[0] & 4 ? &_data_descent : nullptr;
}

void VariableWidthPoint::set_descent(const float &value) {
  _flags[0] |= 4; _data_descent = value;
}

int32_t *VariableWidthPoint::segmentId() {
  return _flags[0] & 8 ? &_data_segmentId : nullptr;
}

const int32_t *VariableWidthPoint::segmentId() const {
  return _flags[0] & 8 ? &_data_segmentId : nullptr;
}

void VariableWidthPoint::set_segmentId(const int32_t &value) {
  _flags[0] |= 8; _data_segmentId = value;
}

bool VariableWidthPoint::encode(kiwi::ByteBuffer &_bb) {
  if (position() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarFloat(_data_position);
  }
  if (ascent() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarFloat(_data_ascent);
  }
  if (descent() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeVarFloat(_data_descent);
  }
  if (segmentId() != nullptr) {
    _bb.writeVarUint(4);
    _bb.writeVarInt(_data_segmentId);
  }
  _bb.writeVarUint(0);
  return true;
}

bool VariableWidthPoint::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarFloat(_data_position)) return false;
        set_position(_data_position);
        break;
      }
      case 2: {
        if (!_bb.readVarFloat(_data_ascent)) return false;
        set_ascent(_data_ascent);
        break;
      }
      case 3: {
        if (!_bb.readVarFloat(_data_descent)) return false;
        set_descent(_data_descent);
        break;
      }
      case 4: {
        if (!_bb.readVarInt(_data_segmentId)) return false;
        set_segmentId(_data_segmentId);
        break;
      }
      default: {
        if (!_schema || !_schema->skipVariableWidthPointField(_bb, _type)) return false;
        break;
      }
    }
  }
}

GUID *PrototypeSelectedState::nodeID() {
  return _data_nodeID;
}

const GUID *PrototypeSelectedState::nodeID() const {
  return _data_nodeID;
}

void PrototypeSelectedState::set_nodeID(GUID *value) {
  _data_nodeID = value;
}

PrototypeSelectedStateType *PrototypeSelectedState::stateType() {
  return _flags[0] & 2 ? &_data_stateType : nullptr;
}

const PrototypeSelectedStateType *PrototypeSelectedState::stateType() const {
  return _flags[0] & 2 ? &_data_stateType : nullptr;
}

void PrototypeSelectedState::set_stateType(const PrototypeSelectedStateType &value) {
  _flags[0] |= 2; _data_stateType = value;
}

GUID *PrototypeSelectedState::selectGUID() {
  return _data_selectGUID;
}

const GUID *PrototypeSelectedState::selectGUID() const {
  return _data_selectGUID;
}

void PrototypeSelectedState::set_selectGUID(GUID *value) {
  _data_selectGUID = value;
}

PrototypeStateAction *PrototypeSelectedState::stateAction() {
  return _flags[0] & 8 ? &_data_stateAction : nullptr;
}

const PrototypeStateAction *PrototypeSelectedState::stateAction() const {
  return _flags[0] & 8 ? &_data_stateAction : nullptr;
}

void PrototypeSelectedState::set_stateAction(const PrototypeStateAction &value) {
  _flags[0] |= 8; _data_stateAction = value;
}

bool PrototypeSelectedState::encode(kiwi::ByteBuffer &_bb) {
  if (nodeID() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_nodeID->encode(_bb)) return false;
  }
  if (stateType() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarUint(static_cast<uint32_t>(_data_stateType));
  }
  if (selectGUID() != nullptr) {
    _bb.writeVarUint(3);
    if (!_data_selectGUID->encode(_bb)) return false;
  }
  if (stateAction() != nullptr) {
    _bb.writeVarUint(4);
    _bb.writeVarUint(static_cast<uint32_t>(_data_stateAction));
  }
  _bb.writeVarUint(0);
  return true;
}

bool PrototypeSelectedState::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_nodeID = _pool.allocate<GUID>();
        if (!_data_nodeID->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_stateType))) return false;
        set_stateType(_data_stateType);
        break;
      }
      case 3: {
        _data_selectGUID = _pool.allocate<GUID>();
        if (!_data_selectGUID->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 4: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_stateAction))) return false;
        set_stateAction(_data_stateAction);
        break;
      }
      default: {
        if (!_schema || !_schema->skipPrototypeSelectedStateField(_bb, _type)) return false;
        break;
      }
    }
  }
}

PrototypeStateAction *PrototypeStateChange::targetStateAction() {
  return _flags[0] & 1 ? &_data_targetStateAction : nullptr;
}

const PrototypeStateAction *PrototypeStateChange::targetStateAction() const {
  return _flags[0] & 1 ? &_data_targetStateAction : nullptr;
}

void PrototypeStateChange::set_targetStateAction(const PrototypeStateAction &value) {
  _flags[0] |= 1; _data_targetStateAction = value;
}

kiwi::Array<PrototypeSelectedState> *PrototypeStateChange::selectedStates() {
  return _flags[0] & 2 ? &_data_selectedStates : nullptr;
}

const kiwi::Array<PrototypeSelectedState> *PrototypeStateChange::selectedStates() const {
  return _flags[0] & 2 ? &_data_selectedStates : nullptr;
}

kiwi::Array<PrototypeSelectedState> &PrototypeStateChange::set_selectedStates(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 2; return _data_selectedStates = pool.array<PrototypeSelectedState>(count);
}

bool PrototypeStateChange::encode(kiwi::ByteBuffer &_bb) {
  if (targetStateAction() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(static_cast<uint32_t>(_data_targetStateAction));
  }
  if (selectedStates() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarUint(_data_selectedStates.size());
    for (PrototypeSelectedState &_it : _data_selectedStates) if (!_it.encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool PrototypeStateChange::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_targetStateAction))) return false;
        set_targetStateAction(_data_targetStateAction);
        break;
      }
      case 2: {
        if (!_bb.readVarUint(_count)) return false;
        for (PrototypeSelectedState &_it : set_selectedStates(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipPrototypeStateChangeField(_bb, _type)) return false;
        break;
      }
    }
  }
}

GUID *PrototypeAction::transitionNodeID() {
  return _data_transitionNodeID;
}

const GUID *PrototypeAction::transitionNodeID() const {
  return _data_transitionNodeID;
}

void PrototypeAction::set_transitionNodeID(GUID *value) {
  _data_transitionNodeID = value;
}

TransitionType *PrototypeAction::transitionType() {
  return _flags[0] & 2 ? &_data_transitionType : nullptr;
}

const TransitionType *PrototypeAction::transitionType() const {
  return _flags[0] & 2 ? &_data_transitionType : nullptr;
}

void PrototypeAction::set_transitionType(const TransitionType &value) {
  _flags[0] |= 2; _data_transitionType = value;
}

float *PrototypeAction::transitionDuration() {
  return _flags[0] & 4 ? &_data_transitionDuration : nullptr;
}

const float *PrototypeAction::transitionDuration() const {
  return _flags[0] & 4 ? &_data_transitionDuration : nullptr;
}

void PrototypeAction::set_transitionDuration(const float &value) {
  _flags[0] |= 4; _data_transitionDuration = value;
}

EasingType *PrototypeAction::easingType() {
  return _flags[0] & 8 ? &_data_easingType : nullptr;
}

const EasingType *PrototypeAction::easingType() const {
  return _flags[0] & 8 ? &_data_easingType : nullptr;
}

void PrototypeAction::set_easingType(const EasingType &value) {
  _flags[0] |= 8; _data_easingType = value;
}

bool *PrototypeAction::transitionShouldSmartAnimate() {
  return _flags[0] & 16 ? &_data_transitionShouldSmartAnimate : nullptr;
}

const bool *PrototypeAction::transitionShouldSmartAnimate() const {
  return _flags[0] & 16 ? &_data_transitionShouldSmartAnimate : nullptr;
}

void PrototypeAction::set_transitionShouldSmartAnimate(const bool &value) {
  _flags[0] |= 16; _data_transitionShouldSmartAnimate = value;
}

ConnectionType *PrototypeAction::connectionType() {
  return _flags[0] & 32 ? &_data_connectionType : nullptr;
}

const ConnectionType *PrototypeAction::connectionType() const {
  return _flags[0] & 32 ? &_data_connectionType : nullptr;
}

void PrototypeAction::set_connectionType(const ConnectionType &value) {
  _flags[0] |= 32; _data_connectionType = value;
}

kiwi::String *PrototypeAction::connectionURL() {
  return _flags[0] & 64 ? &_data_connectionURL : nullptr;
}

const kiwi::String *PrototypeAction::connectionURL() const {
  return _flags[0] & 64 ? &_data_connectionURL : nullptr;
}

void PrototypeAction::set_connectionURL(const kiwi::String &value) {
  _flags[0] |= 64; _data_connectionURL = value;
}

Vector *PrototypeAction::overlayRelativePosition() {
  return _data_overlayRelativePosition;
}

const Vector *PrototypeAction::overlayRelativePosition() const {
  return _data_overlayRelativePosition;
}

void PrototypeAction::set_overlayRelativePosition(Vector *value) {
  _data_overlayRelativePosition = value;
}

NavigationType *PrototypeAction::navigationType() {
  return _flags[0] & 256 ? &_data_navigationType : nullptr;
}

const NavigationType *PrototypeAction::navigationType() const {
  return _flags[0] & 256 ? &_data_navigationType : nullptr;
}

void PrototypeAction::set_navigationType(const NavigationType &value) {
  _flags[0] |= 256; _data_navigationType = value;
}

bool *PrototypeAction::transitionPreserveScroll() {
  return _flags[0] & 512 ? &_data_transitionPreserveScroll : nullptr;
}

const bool *PrototypeAction::transitionPreserveScroll() const {
  return _flags[0] & 512 ? &_data_transitionPreserveScroll : nullptr;
}

void PrototypeAction::set_transitionPreserveScroll(const bool &value) {
  _flags[0] |= 512; _data_transitionPreserveScroll = value;
}

kiwi::Array<float> *PrototypeAction::easingFunction() {
  return _flags[0] & 1024 ? &_data_easingFunction : nullptr;
}

const kiwi::Array<float> *PrototypeAction::easingFunction() const {
  return _flags[0] & 1024 ? &_data_easingFunction : nullptr;
}

kiwi::Array<float> &PrototypeAction::set_easingFunction(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 1024; return _data_easingFunction = pool.array<float>(count);
}

OverflowType *PrototypeAction::overflowType() {
  return _flags[0] & 2048 ? &_data_overflowType : nullptr;
}

const OverflowType *PrototypeAction::overflowType() const {
  return _flags[0] & 2048 ? &_data_overflowType : nullptr;
}

void PrototypeAction::set_overflowType(const OverflowType &value) {
  _flags[0] |= 2048; _data_overflowType = value;
}

Vector *PrototypeAction::extraScrollOffset() {
  return _data_extraScrollOffset;
}

const Vector *PrototypeAction::extraScrollOffset() const {
  return _data_extraScrollOffset;
}

void PrototypeAction::set_extraScrollOffset(Vector *value) {
  _data_extraScrollOffset = value;
}

PrototypeShowHide *PrototypeAction::showHide() {
  return _flags[0] & 8192 ? &_data_showHide : nullptr;
}

const PrototypeShowHide *PrototypeAction::showHide() const {
  return _flags[0] & 8192 ? &_data_showHide : nullptr;
}

void PrototypeAction::set_showHide(const PrototypeShowHide &value) {
  _flags[0] |= 8192; _data_showHide = value;
}

ProdAdjustSize *PrototypeAction::adjustSize() {
  return _data_adjustSize;
}

const ProdAdjustSize *PrototypeAction::adjustSize() const {
  return _data_adjustSize;
}

void PrototypeAction::set_adjustSize(ProdAdjustSize *value) {
  _data_adjustSize = value;
}

ProdMoving *PrototypeAction::moving() {
  return _data_moving;
}

const ProdMoving *PrototypeAction::moving() const {
  return _data_moving;
}

void PrototypeAction::set_moving(ProdMoving *value) {
  _data_moving = value;
}

kiwi::String *PrototypeAction::dynamicPanelStateStr() {
  return _flags[0] & 65536 ? &_data_dynamicPanelStateStr : nullptr;
}

const kiwi::String *PrototypeAction::dynamicPanelStateStr() const {
  return _flags[0] & 65536 ? &_data_dynamicPanelStateStr : nullptr;
}

void PrototypeAction::set_dynamicPanelStateStr(const kiwi::String &value) {
  _flags[0] |= 65536; _data_dynamicPanelStateStr = value;
}

ProdRotate *PrototypeAction::rotation() {
  return _data_rotation;
}

const ProdRotate *PrototypeAction::rotation() const {
  return _data_rotation;
}

void PrototypeAction::set_rotation(ProdRotate *value) {
  _data_rotation = value;
}

float *PrototypeAction::waitingTime() {
  return _flags[0] & 262144 ? &_data_waitingTime : nullptr;
}

const float *PrototypeAction::waitingTime() const {
  return _flags[0] & 262144 ? &_data_waitingTime : nullptr;
}

void PrototypeAction::set_waitingTime(const float &value) {
  _flags[0] |= 262144; _data_waitingTime = value;
}

bool *PrototypeAction::isLooping() {
  return _flags[0] & 524288 ? &_data_isLooping : nullptr;
}

const bool *PrototypeAction::isLooping() const {
  return _flags[0] & 524288 ? &_data_isLooping : nullptr;
}

void PrototypeAction::set_isLooping(const bool &value) {
  _flags[0] |= 524288; _data_isLooping = value;
}

float *PrototypeAction::loopingDuration() {
  return _flags[0] & 1048576 ? &_data_loopingDuration : nullptr;
}

const float *PrototypeAction::loopingDuration() const {
  return _flags[0] & 1048576 ? &_data_loopingDuration : nullptr;
}

void PrototypeAction::set_loopingDuration(const float &value) {
  _flags[0] |= 1048576; _data_loopingDuration = value;
}

PrototypeVariableTarget *PrototypeAction::targetVariable() {
  return _data_targetVariable;
}

const PrototypeVariableTarget *PrototypeAction::targetVariable() const {
  return _data_targetVariable;
}

void PrototypeAction::set_targetVariable(PrototypeVariableTarget *value) {
  _data_targetVariable = value;
}

VariableData *PrototypeAction::targetVariableData() {
  return _data_targetVariableData;
}

const VariableData *PrototypeAction::targetVariableData() const {
  return _data_targetVariableData;
}

void PrototypeAction::set_targetVariableData(VariableData *value) {
  _data_targetVariableData = value;
}

AssetID *PrototypeAction::targetVariableSetID() {
  return _data_targetVariableSetID;
}

const AssetID *PrototypeAction::targetVariableSetID() const {
  return _data_targetVariableSetID;
}

void PrototypeAction::set_targetVariableSetID(AssetID *value) {
  _data_targetVariableSetID = value;
}

GUID *PrototypeAction::targetVariableModeID() {
  return _data_targetVariableModeID;
}

const GUID *PrototypeAction::targetVariableModeID() const {
  return _data_targetVariableModeID;
}

void PrototypeAction::set_targetVariableModeID(GUID *value) {
  _data_targetVariableModeID = value;
}

kiwi::Array<ConditionalActions> *PrototypeAction::conditionalActions() {
  return _flags[0] & 33554432 ? &_data_conditionalActions : nullptr;
}

const kiwi::Array<ConditionalActions> *PrototypeAction::conditionalActions() const {
  return _flags[0] & 33554432 ? &_data_conditionalActions : nullptr;
}

kiwi::Array<ConditionalActions> &PrototypeAction::set_conditionalActions(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 33554432; return _data_conditionalActions = pool.array<ConditionalActions>(count);
}

bool *PrototypeAction::transitionResetVideoPosition() {
  return _flags[0] & 67108864 ? &_data_transitionResetVideoPosition : nullptr;
}

const bool *PrototypeAction::transitionResetVideoPosition() const {
  return _flags[0] & 67108864 ? &_data_transitionResetVideoPosition : nullptr;
}

void PrototypeAction::set_transitionResetVideoPosition(const bool &value) {
  _flags[0] |= 67108864; _data_transitionResetVideoPosition = value;
}

bool *PrototypeAction::transitionResetScrollPosition() {
  return _flags[0] & 134217728 ? &_data_transitionResetScrollPosition : nullptr;
}

const bool *PrototypeAction::transitionResetScrollPosition() const {
  return _flags[0] & 134217728 ? &_data_transitionResetScrollPosition : nullptr;
}

void PrototypeAction::set_transitionResetScrollPosition(const bool &value) {
  _flags[0] |= 134217728; _data_transitionResetScrollPosition = value;
}

bool *PrototypeAction::transitionResetInteractiveComponents() {
  return _flags[0] & 268435456 ? &_data_transitionResetInteractiveComponents : nullptr;
}

const bool *PrototypeAction::transitionResetInteractiveComponents() const {
  return _flags[0] & 268435456 ? &_data_transitionResetInteractiveComponents : nullptr;
}

void PrototypeAction::set_transitionResetInteractiveComponents(const bool &value) {
  _flags[0] |= 268435456; _data_transitionResetInteractiveComponents = value;
}

bool *PrototypeAction::DisplayTopLevel() {
  return _flags[0] & 536870912 ? &_data_DisplayTopLevel : nullptr;
}

const bool *PrototypeAction::DisplayTopLevel() const {
  return _flags[0] & 536870912 ? &_data_DisplayTopLevel : nullptr;
}

void PrototypeAction::set_DisplayTopLevel(const bool &value) {
  _flags[0] |= 536870912; _data_DisplayTopLevel = value;
}

float *PrototypeAction::mediaSkipToTime() {
  return _flags[0] & 1073741824 ? &_data_mediaSkipToTime : nullptr;
}

const float *PrototypeAction::mediaSkipToTime() const {
  return _flags[0] & 1073741824 ? &_data_mediaSkipToTime : nullptr;
}

void PrototypeAction::set_mediaSkipToTime(const float &value) {
  _flags[0] |= 1073741824; _data_mediaSkipToTime = value;
}

float *PrototypeAction::mediaSkipByAmount() {
  return _flags[0] & 2147483648 ? &_data_mediaSkipByAmount : nullptr;
}

const float *PrototypeAction::mediaSkipByAmount() const {
  return _flags[0] & 2147483648 ? &_data_mediaSkipByAmount : nullptr;
}

void PrototypeAction::set_mediaSkipByAmount(const float &value) {
  _flags[0] |= 2147483648; _data_mediaSkipByAmount = value;
}

MediaAction *PrototypeAction::mediaAction() {
  return _flags[1] & 1 ? &_data_mediaAction : nullptr;
}

const MediaAction *PrototypeAction::mediaAction() const {
  return _flags[1] & 1 ? &_data_mediaAction : nullptr;
}

void PrototypeAction::set_mediaAction(const MediaAction &value) {
  _flags[1] |= 1; _data_mediaAction = value;
}

PrototypeStateChange *PrototypeAction::stateChange() {
  return _data_stateChange;
}

const PrototypeStateChange *PrototypeAction::stateChange() const {
  return _data_stateChange;
}

void PrototypeAction::set_stateChange(PrototypeStateChange *value) {
  _data_stateChange = value;
}

bool PrototypeAction::encode(kiwi::ByteBuffer &_bb) {
  if (transitionNodeID() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_transitionNodeID->encode(_bb)) return false;
  }
  if (transitionType() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarUint(static_cast<uint32_t>(_data_transitionType));
  }
  if (transitionDuration() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeVarFloat(_data_transitionDuration);
  }
  if (easingType() != nullptr) {
    _bb.writeVarUint(4);
    _bb.writeVarUint(static_cast<uint32_t>(_data_easingType));
  }
  if (transitionShouldSmartAnimate() != nullptr) {
    _bb.writeVarUint(5);
    _bb.writeByte(_data_transitionShouldSmartAnimate);
  }
  if (connectionType() != nullptr) {
    _bb.writeVarUint(6);
    _bb.writeVarUint(static_cast<uint32_t>(_data_connectionType));
  }
  if (connectionURL() != nullptr) {
    _bb.writeVarUint(7);
    _bb.writeString(_data_connectionURL.c_str());
  }
  if (overlayRelativePosition() != nullptr) {
    _bb.writeVarUint(8);
    if (!_data_overlayRelativePosition->encode(_bb)) return false;
  }
  if (navigationType() != nullptr) {
    _bb.writeVarUint(9);
    _bb.writeVarUint(static_cast<uint32_t>(_data_navigationType));
  }
  if (transitionPreserveScroll() != nullptr) {
    _bb.writeVarUint(10);
    _bb.writeByte(_data_transitionPreserveScroll);
  }
  if (easingFunction() != nullptr) {
    _bb.writeVarUint(11);
    _bb.writeVarUint(_data_easingFunction.size());
    for (float &_it : _data_easingFunction) _bb.writeVarFloat(_it);
  }
  if (overflowType() != nullptr) {
    _bb.writeVarUint(12);
    _bb.writeVarUint(static_cast<uint32_t>(_data_overflowType));
  }
  if (extraScrollOffset() != nullptr) {
    _bb.writeVarUint(13);
    if (!_data_extraScrollOffset->encode(_bb)) return false;
  }
  if (showHide() != nullptr) {
    _bb.writeVarUint(14);
    _bb.writeVarUint(static_cast<uint32_t>(_data_showHide));
  }
  if (adjustSize() != nullptr) {
    _bb.writeVarUint(15);
    if (!_data_adjustSize->encode(_bb)) return false;
  }
  if (moving() != nullptr) {
    _bb.writeVarUint(16);
    if (!_data_moving->encode(_bb)) return false;
  }
  if (dynamicPanelStateStr() != nullptr) {
    _bb.writeVarUint(17);
    _bb.writeString(_data_dynamicPanelStateStr.c_str());
  }
  if (rotation() != nullptr) {
    _bb.writeVarUint(18);
    if (!_data_rotation->encode(_bb)) return false;
  }
  if (waitingTime() != nullptr) {
    _bb.writeVarUint(19);
    _bb.writeVarFloat(_data_waitingTime);
  }
  if (isLooping() != nullptr) {
    _bb.writeVarUint(20);
    _bb.writeByte(_data_isLooping);
  }
  if (loopingDuration() != nullptr) {
    _bb.writeVarUint(21);
    _bb.writeVarFloat(_data_loopingDuration);
  }
  if (targetVariable() != nullptr) {
    _bb.writeVarUint(22);
    if (!_data_targetVariable->encode(_bb)) return false;
  }
  if (targetVariableData() != nullptr) {
    _bb.writeVarUint(23);
    if (!_data_targetVariableData->encode(_bb)) return false;
  }
  if (targetVariableSetID() != nullptr) {
    _bb.writeVarUint(24);
    if (!_data_targetVariableSetID->encode(_bb)) return false;
  }
  if (targetVariableModeID() != nullptr) {
    _bb.writeVarUint(25);
    if (!_data_targetVariableModeID->encode(_bb)) return false;
  }
  if (conditionalActions() != nullptr) {
    _bb.writeVarUint(26);
    _bb.writeVarUint(_data_conditionalActions.size());
    for (ConditionalActions &_it : _data_conditionalActions) if (!_it.encode(_bb)) return false;
  }
  if (transitionResetVideoPosition() != nullptr) {
    _bb.writeVarUint(27);
    _bb.writeByte(_data_transitionResetVideoPosition);
  }
  if (transitionResetScrollPosition() != nullptr) {
    _bb.writeVarUint(28);
    _bb.writeByte(_data_transitionResetScrollPosition);
  }
  if (transitionResetInteractiveComponents() != nullptr) {
    _bb.writeVarUint(29);
    _bb.writeByte(_data_transitionResetInteractiveComponents);
  }
  if (DisplayTopLevel() != nullptr) {
    _bb.writeVarUint(30);
    _bb.writeByte(_data_DisplayTopLevel);
  }
  if (mediaSkipToTime() != nullptr) {
    _bb.writeVarUint(31);
    _bb.writeVarFloat(_data_mediaSkipToTime);
  }
  if (mediaSkipByAmount() != nullptr) {
    _bb.writeVarUint(32);
    _bb.writeVarFloat(_data_mediaSkipByAmount);
  }
  if (mediaAction() != nullptr) {
    _bb.writeVarUint(33);
    _bb.writeVarUint(static_cast<uint32_t>(_data_mediaAction));
  }
  if (stateChange() != nullptr) {
    _bb.writeVarUint(34);
    if (!_data_stateChange->encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool PrototypeAction::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_transitionNodeID = _pool.allocate<GUID>();
        if (!_data_transitionNodeID->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_transitionType))) return false;
        set_transitionType(_data_transitionType);
        break;
      }
      case 3: {
        if (!_bb.readVarFloat(_data_transitionDuration)) return false;
        set_transitionDuration(_data_transitionDuration);
        break;
      }
      case 4: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_easingType))) return false;
        set_easingType(_data_easingType);
        break;
      }
      case 5: {
        if (!_bb.readByte(_data_transitionShouldSmartAnimate)) return false;
        set_transitionShouldSmartAnimate(_data_transitionShouldSmartAnimate);
        break;
      }
      case 6: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_connectionType))) return false;
        set_connectionType(_data_connectionType);
        break;
      }
      case 7: {
        if (!_bb.readString(_data_connectionURL, _pool)) return false;
        set_connectionURL(_data_connectionURL);
        break;
      }
      case 8: {
        _data_overlayRelativePosition = _pool.allocate<Vector>();
        if (!_data_overlayRelativePosition->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 9: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_navigationType))) return false;
        set_navigationType(_data_navigationType);
        break;
      }
      case 10: {
        if (!_bb.readByte(_data_transitionPreserveScroll)) return false;
        set_transitionPreserveScroll(_data_transitionPreserveScroll);
        break;
      }
      case 11: {
        if (!_bb.readVarUint(_count)) return false;
        for (float &_it : set_easingFunction(_pool, _count)) if (!_bb.readVarFloat(_it)) return false;
        break;
      }
      case 12: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_overflowType))) return false;
        set_overflowType(_data_overflowType);
        break;
      }
      case 13: {
        _data_extraScrollOffset = _pool.allocate<Vector>();
        if (!_data_extraScrollOffset->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 14: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_showHide))) return false;
        set_showHide(_data_showHide);
        break;
      }
      case 15: {
        _data_adjustSize = _pool.allocate<ProdAdjustSize>();
        if (!_data_adjustSize->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 16: {
        _data_moving = _pool.allocate<ProdMoving>();
        if (!_data_moving->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 17: {
        if (!_bb.readString(_data_dynamicPanelStateStr, _pool)) return false;
        set_dynamicPanelStateStr(_data_dynamicPanelStateStr);
        break;
      }
      case 18: {
        _data_rotation = _pool.allocate<ProdRotate>();
        if (!_data_rotation->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 19: {
        if (!_bb.readVarFloat(_data_waitingTime)) return false;
        set_waitingTime(_data_waitingTime);
        break;
      }
      case 20: {
        if (!_bb.readByte(_data_isLooping)) return false;
        set_isLooping(_data_isLooping);
        break;
      }
      case 21: {
        if (!_bb.readVarFloat(_data_loopingDuration)) return false;
        set_loopingDuration(_data_loopingDuration);
        break;
      }
      case 22: {
        _data_targetVariable = _pool.allocate<PrototypeVariableTarget>();
        if (!_data_targetVariable->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 23: {
        _data_targetVariableData = _pool.allocate<VariableData>();
        if (!_data_targetVariableData->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 24: {
        _data_targetVariableSetID = _pool.allocate<AssetID>();
        if (!_data_targetVariableSetID->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 25: {
        _data_targetVariableModeID = _pool.allocate<GUID>();
        if (!_data_targetVariableModeID->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 26: {
        if (!_bb.readVarUint(_count)) return false;
        for (ConditionalActions &_it : set_conditionalActions(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 27: {
        if (!_bb.readByte(_data_transitionResetVideoPosition)) return false;
        set_transitionResetVideoPosition(_data_transitionResetVideoPosition);
        break;
      }
      case 28: {
        if (!_bb.readByte(_data_transitionResetScrollPosition)) return false;
        set_transitionResetScrollPosition(_data_transitionResetScrollPosition);
        break;
      }
      case 29: {
        if (!_bb.readByte(_data_transitionResetInteractiveComponents)) return false;
        set_transitionResetInteractiveComponents(_data_transitionResetInteractiveComponents);
        break;
      }
      case 30: {
        if (!_bb.readByte(_data_DisplayTopLevel)) return false;
        set_DisplayTopLevel(_data_DisplayTopLevel);
        break;
      }
      case 31: {
        if (!_bb.readVarFloat(_data_mediaSkipToTime)) return false;
        set_mediaSkipToTime(_data_mediaSkipToTime);
        break;
      }
      case 32: {
        if (!_bb.readVarFloat(_data_mediaSkipByAmount)) return false;
        set_mediaSkipByAmount(_data_mediaSkipByAmount);
        break;
      }
      case 33: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_mediaAction))) return false;
        set_mediaAction(_data_mediaAction);
        break;
      }
      case 34: {
        _data_stateChange = _pool.allocate<PrototypeStateChange>();
        if (!_data_stateChange->decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipPrototypeActionField(_bb, _type)) return false;
        break;
      }
    }
  }
}

InteractionType *PrototypeEvent::interactionType() {
  return _flags[0] & 1 ? &_data_interactionType : nullptr;
}

const InteractionType *PrototypeEvent::interactionType() const {
  return _flags[0] & 1 ? &_data_interactionType : nullptr;
}

void PrototypeEvent::set_interactionType(const InteractionType &value) {
  _flags[0] |= 1; _data_interactionType = value;
}

bool *PrototypeEvent::interactionMaintained() {
  return _flags[0] & 2 ? &_data_interactionMaintained : nullptr;
}

const bool *PrototypeEvent::interactionMaintained() const {
  return _flags[0] & 2 ? &_data_interactionMaintained : nullptr;
}

void PrototypeEvent::set_interactionMaintained(const bool &value) {
  _flags[0] |= 2; _data_interactionMaintained = value;
}

float *PrototypeEvent::interactionDuration() {
  return _flags[0] & 4 ? &_data_interactionDuration : nullptr;
}

const float *PrototypeEvent::interactionDuration() const {
  return _flags[0] & 4 ? &_data_interactionDuration : nullptr;
}

void PrototypeEvent::set_interactionDuration(const float &value) {
  _flags[0] |= 4; _data_interactionDuration = value;
}

KeyTrigger *PrototypeEvent::keyTrigger() {
  return _data_keyTrigger;
}

const KeyTrigger *PrototypeEvent::keyTrigger() const {
  return _data_keyTrigger;
}

void PrototypeEvent::set_keyTrigger(KeyTrigger *value) {
  _data_keyTrigger = value;
}

kiwi::String *PrototypeEvent::voiceEventPhrase() {
  return _flags[0] & 16 ? &_data_voiceEventPhrase : nullptr;
}

const kiwi::String *PrototypeEvent::voiceEventPhrase() const {
  return _flags[0] & 16 ? &_data_voiceEventPhrase : nullptr;
}

void PrototypeEvent::set_voiceEventPhrase(const kiwi::String &value) {
  _flags[0] |= 16; _data_voiceEventPhrase = value;
}

float *PrototypeEvent::transitionTimeout() {
  return _flags[0] & 32 ? &_data_transitionTimeout : nullptr;
}

const float *PrototypeEvent::transitionTimeout() const {
  return _flags[0] & 32 ? &_data_transitionTimeout : nullptr;
}

void PrototypeEvent::set_transitionTimeout(const float &value) {
  _flags[0] |= 32; _data_transitionTimeout = value;
}

bool PrototypeEvent::encode(kiwi::ByteBuffer &_bb) {
  if (interactionType() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(static_cast<uint32_t>(_data_interactionType));
  }
  if (interactionMaintained() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeByte(_data_interactionMaintained);
  }
  if (interactionDuration() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeVarFloat(_data_interactionDuration);
  }
  if (keyTrigger() != nullptr) {
    _bb.writeVarUint(4);
    if (!_data_keyTrigger->encode(_bb)) return false;
  }
  if (voiceEventPhrase() != nullptr) {
    _bb.writeVarUint(5);
    _bb.writeString(_data_voiceEventPhrase.c_str());
  }
  if (transitionTimeout() != nullptr) {
    _bb.writeVarUint(6);
    _bb.writeVarFloat(_data_transitionTimeout);
  }
  _bb.writeVarUint(0);
  return true;
}

bool PrototypeEvent::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_interactionType))) return false;
        set_interactionType(_data_interactionType);
        break;
      }
      case 2: {
        if (!_bb.readByte(_data_interactionMaintained)) return false;
        set_interactionMaintained(_data_interactionMaintained);
        break;
      }
      case 3: {
        if (!_bb.readVarFloat(_data_interactionDuration)) return false;
        set_interactionDuration(_data_interactionDuration);
        break;
      }
      case 4: {
        _data_keyTrigger = _pool.allocate<KeyTrigger>();
        if (!_data_keyTrigger->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 5: {
        if (!_bb.readString(_data_voiceEventPhrase, _pool)) return false;
        set_voiceEventPhrase(_data_voiceEventPhrase);
        break;
      }
      case 6: {
        if (!_bb.readVarFloat(_data_transitionTimeout)) return false;
        set_transitionTimeout(_data_transitionTimeout);
        break;
      }
      default: {
        if (!_schema || !_schema->skipPrototypeEventField(_bb, _type)) return false;
        break;
      }
    }
  }
}

GUID *ComponentPropDef::id() {
  return _data_id;
}

const GUID *ComponentPropDef::id() const {
  return _data_id;
}

void ComponentPropDef::set_id(GUID *value) {
  _data_id = value;
}

kiwi::String *ComponentPropDef::name() {
  return _flags[0] & 2 ? &_data_name : nullptr;
}

const kiwi::String *ComponentPropDef::name() const {
  return _flags[0] & 2 ? &_data_name : nullptr;
}

void ComponentPropDef::set_name(const kiwi::String &value) {
  _flags[0] |= 2; _data_name = value;
}

ComponentPropValue *ComponentPropDef::initialValue() {
  return _data_initialValue;
}

const ComponentPropValue *ComponentPropDef::initialValue() const {
  return _data_initialValue;
}

void ComponentPropDef::set_initialValue(ComponentPropValue *value) {
  _data_initialValue = value;
}

kiwi::String *ComponentPropDef::sortPosition() {
  return _flags[0] & 8 ? &_data_sortPosition : nullptr;
}

const kiwi::String *ComponentPropDef::sortPosition() const {
  return _flags[0] & 8 ? &_data_sortPosition : nullptr;
}

void ComponentPropDef::set_sortPosition(const kiwi::String &value) {
  _flags[0] |= 8; _data_sortPosition = value;
}

GUID *ComponentPropDef::parentPropDefId() {
  return _data_parentPropDefId;
}

const GUID *ComponentPropDef::parentPropDefId() const {
  return _data_parentPropDefId;
}

void ComponentPropDef::set_parentPropDefId(GUID *value) {
  _data_parentPropDefId = value;
}

ComponentPropType *ComponentPropDef::type() {
  return _flags[0] & 32 ? &_data_type : nullptr;
}

const ComponentPropType *ComponentPropDef::type() const {
  return _flags[0] & 32 ? &_data_type : nullptr;
}

void ComponentPropDef::set_type(const ComponentPropType &value) {
  _flags[0] |= 32; _data_type = value;
}

ComponentPropPreferredValues *ComponentPropDef::preferredValues() {
  return _data_preferredValues;
}

const ComponentPropPreferredValues *ComponentPropDef::preferredValues() const {
  return _data_preferredValues;
}

void ComponentPropDef::set_preferredValues(ComponentPropPreferredValues *value) {
  _data_preferredValues = value;
}

bool *ComponentPropDef::isDeleted() {
  return _flags[0] & 128 ? &_data_isDeleted : nullptr;
}

const bool *ComponentPropDef::isDeleted() const {
  return _flags[0] & 128 ? &_data_isDeleted : nullptr;
}

void ComponentPropDef::set_isDeleted(const bool &value) {
  _flags[0] |= 128; _data_isDeleted = value;
}

VariableData *ComponentPropDef::varValue() {
  return _data_varValue;
}

const VariableData *ComponentPropDef::varValue() const {
  return _data_varValue;
}

void ComponentPropDef::set_varValue(VariableData *value) {
  _data_varValue = value;
}

kiwi::String *ComponentPropDef::aliasName() {
  return _flags[0] & 512 ? &_data_aliasName : nullptr;
}

const kiwi::String *ComponentPropDef::aliasName() const {
  return _flags[0] & 512 ? &_data_aliasName : nullptr;
}

void ComponentPropDef::set_aliasName(const kiwi::String &value) {
  _flags[0] |= 512; _data_aliasName = value;
}

bool ComponentPropDef::encode(kiwi::ByteBuffer &_bb) {
  if (id() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_id->encode(_bb)) return false;
  }
  if (name() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeString(_data_name.c_str());
  }
  if (initialValue() != nullptr) {
    _bb.writeVarUint(3);
    if (!_data_initialValue->encode(_bb)) return false;
  }
  if (sortPosition() != nullptr) {
    _bb.writeVarUint(4);
    _bb.writeString(_data_sortPosition.c_str());
  }
  if (parentPropDefId() != nullptr) {
    _bb.writeVarUint(5);
    if (!_data_parentPropDefId->encode(_bb)) return false;
  }
  if (type() != nullptr) {
    _bb.writeVarUint(6);
    _bb.writeVarUint(static_cast<uint32_t>(_data_type));
  }
  if (preferredValues() != nullptr) {
    _bb.writeVarUint(7);
    if (!_data_preferredValues->encode(_bb)) return false;
  }
  if (isDeleted() != nullptr) {
    _bb.writeVarUint(8);
    _bb.writeByte(_data_isDeleted);
  }
  if (varValue() != nullptr) {
    _bb.writeVarUint(9);
    if (!_data_varValue->encode(_bb)) return false;
  }
  if (aliasName() != nullptr) {
    _bb.writeVarUint(10);
    _bb.writeString(_data_aliasName.c_str());
  }
  _bb.writeVarUint(0);
  return true;
}

bool ComponentPropDef::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_id = _pool.allocate<GUID>();
        if (!_data_id->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        if (!_bb.readString(_data_name, _pool)) return false;
        set_name(_data_name);
        break;
      }
      case 3: {
        _data_initialValue = _pool.allocate<ComponentPropValue>();
        if (!_data_initialValue->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 4: {
        if (!_bb.readString(_data_sortPosition, _pool)) return false;
        set_sortPosition(_data_sortPosition);
        break;
      }
      case 5: {
        _data_parentPropDefId = _pool.allocate<GUID>();
        if (!_data_parentPropDefId->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 6: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_type))) return false;
        set_type(_data_type);
        break;
      }
      case 7: {
        _data_preferredValues = _pool.allocate<ComponentPropPreferredValues>();
        if (!_data_preferredValues->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 8: {
        if (!_bb.readByte(_data_isDeleted)) return false;
        set_isDeleted(_data_isDeleted);
        break;
      }
      case 9: {
        _data_varValue = _pool.allocate<VariableData>();
        if (!_data_varValue->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 10: {
        if (!_bb.readString(_data_aliasName, _pool)) return false;
        set_aliasName(_data_aliasName);
        break;
      }
      default: {
        if (!_schema || !_schema->skipComponentPropDefField(_bb, _type)) return false;
        break;
      }
    }
  }
}

GUID *ComponentPropRef::defID() {
  return _data_defID;
}

const GUID *ComponentPropRef::defID() const {
  return _data_defID;
}

void ComponentPropRef::set_defID(GUID *value) {
  _data_defID = value;
}

kiwi::String *ComponentPropRef::zombieFallbackName() {
  return _flags[0] & 2 ? &_data_zombieFallbackName : nullptr;
}

const kiwi::String *ComponentPropRef::zombieFallbackName() const {
  return _flags[0] & 2 ? &_data_zombieFallbackName : nullptr;
}

void ComponentPropRef::set_zombieFallbackName(const kiwi::String &value) {
  _flags[0] |= 2; _data_zombieFallbackName = value;
}

ComponentPropNodeField *ComponentPropRef::componentPropNodeField() {
  return _flags[0] & 4 ? &_data_componentPropNodeField : nullptr;
}

const ComponentPropNodeField *ComponentPropRef::componentPropNodeField() const {
  return _flags[0] & 4 ? &_data_componentPropNodeField : nullptr;
}

void ComponentPropRef::set_componentPropNodeField(const ComponentPropNodeField &value) {
  _flags[0] |= 4; _data_componentPropNodeField = value;
}

uint32_t *ComponentPropRef::nodeField() {
  return _flags[0] & 8 ? &_data_nodeField : nullptr;
}

const uint32_t *ComponentPropRef::nodeField() const {
  return _flags[0] & 8 ? &_data_nodeField : nullptr;
}

void ComponentPropRef::set_nodeField(const uint32_t &value) {
  _flags[0] |= 8; _data_nodeField = value;
}

bool *ComponentPropRef::isDeleted() {
  return _flags[0] & 16 ? &_data_isDeleted : nullptr;
}

const bool *ComponentPropRef::isDeleted() const {
  return _flags[0] & 16 ? &_data_isDeleted : nullptr;
}

void ComponentPropRef::set_isDeleted(const bool &value) {
  _flags[0] |= 16; _data_isDeleted = value;
}

bool ComponentPropRef::encode(kiwi::ByteBuffer &_bb) {
  if (defID() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_defID->encode(_bb)) return false;
  }
  if (zombieFallbackName() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeString(_data_zombieFallbackName.c_str());
  }
  if (componentPropNodeField() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeVarUint(static_cast<uint32_t>(_data_componentPropNodeField));
  }
  if (nodeField() != nullptr) {
    _bb.writeVarUint(4);
    _bb.writeVarUint(_data_nodeField);
  }
  if (isDeleted() != nullptr) {
    _bb.writeVarUint(5);
    _bb.writeByte(_data_isDeleted);
  }
  _bb.writeVarUint(0);
  return true;
}

bool ComponentPropRef::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_defID = _pool.allocate<GUID>();
        if (!_data_defID->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        if (!_bb.readString(_data_zombieFallbackName, _pool)) return false;
        set_zombieFallbackName(_data_zombieFallbackName);
        break;
      }
      case 3: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_componentPropNodeField))) return false;
        set_componentPropNodeField(_data_componentPropNodeField);
        break;
      }
      case 4: {
        if (!_bb.readVarUint(_data_nodeField)) return false;
        set_nodeField(_data_nodeField);
        break;
      }
      case 5: {
        if (!_bb.readByte(_data_isDeleted)) return false;
        set_isDeleted(_data_isDeleted);
        break;
      }
      default: {
        if (!_schema || !_schema->skipComponentPropRefField(_bb, _type)) return false;
        break;
      }
    }
  }
}

TextData *ComponentPropValue::textValue() {
  return _data_textValue;
}

const TextData *ComponentPropValue::textValue() const {
  return _data_textValue;
}

void ComponentPropValue::set_textValue(TextData *value) {
  _data_textValue = value;
}

GUID *ComponentPropValue::guidValue() {
  return _data_guidValue;
}

const GUID *ComponentPropValue::guidValue() const {
  return _data_guidValue;
}

void ComponentPropValue::set_guidValue(GUID *value) {
  _data_guidValue = value;
}

bool *ComponentPropValue::boolValue() {
  return _flags[0] & 4 ? &_data_boolValue : nullptr;
}

const bool *ComponentPropValue::boolValue() const {
  return _flags[0] & 4 ? &_data_boolValue : nullptr;
}

void ComponentPropValue::set_boolValue(const bool &value) {
  _flags[0] |= 4; _data_boolValue = value;
}

bool ComponentPropValue::encode(kiwi::ByteBuffer &_bb) {
  if (textValue() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_textValue->encode(_bb)) return false;
  }
  if (guidValue() != nullptr) {
    _bb.writeVarUint(2);
    if (!_data_guidValue->encode(_bb)) return false;
  }
  if (boolValue() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeByte(_data_boolValue);
  }
  _bb.writeVarUint(0);
  return true;
}

bool ComponentPropValue::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_textValue = _pool.allocate<TextData>();
        if (!_data_textValue->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        _data_guidValue = _pool.allocate<GUID>();
        if (!_data_guidValue->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 3: {
        if (!_bb.readByte(_data_boolValue)) return false;
        set_boolValue(_data_boolValue);
        break;
      }
      default: {
        if (!_schema || !_schema->skipComponentPropValueField(_bb, _type)) return false;
        break;
      }
    }
  }
}

InstanceSwapPreferredValueType *InstanceSwapPreferredValue::type() {
  return _flags[0] & 1 ? &_data_type : nullptr;
}

const InstanceSwapPreferredValueType *InstanceSwapPreferredValue::type() const {
  return _flags[0] & 1 ? &_data_type : nullptr;
}

void InstanceSwapPreferredValue::set_type(const InstanceSwapPreferredValueType &value) {
  _flags[0] |= 1; _data_type = value;
}

kiwi::String *InstanceSwapPreferredValue::key() {
  return _flags[0] & 2 ? &_data_key : nullptr;
}

const kiwi::String *InstanceSwapPreferredValue::key() const {
  return _flags[0] & 2 ? &_data_key : nullptr;
}

void InstanceSwapPreferredValue::set_key(const kiwi::String &value) {
  _flags[0] |= 2; _data_key = value;
}

bool InstanceSwapPreferredValue::encode(kiwi::ByteBuffer &_bb) {
  if (type() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(static_cast<uint32_t>(_data_type));
  }
  if (key() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeString(_data_key.c_str());
  }
  _bb.writeVarUint(0);
  return true;
}

bool InstanceSwapPreferredValue::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_type))) return false;
        set_type(_data_type);
        break;
      }
      case 2: {
        if (!_bb.readString(_data_key, _pool)) return false;
        set_key(_data_key);
        break;
      }
      default: {
        if (!_schema || !_schema->skipInstanceSwapPreferredValueField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::Array<kiwi::String> *ComponentPropPreferredValues::stringValues() {
  return _flags[0] & 1 ? &_data_stringValues : nullptr;
}

const kiwi::Array<kiwi::String> *ComponentPropPreferredValues::stringValues() const {
  return _flags[0] & 1 ? &_data_stringValues : nullptr;
}

kiwi::Array<kiwi::String> &ComponentPropPreferredValues::set_stringValues(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 1; return _data_stringValues = pool.array<kiwi::String>(count);
}

kiwi::Array<InstanceSwapPreferredValue> *ComponentPropPreferredValues::instanceSwapValues() {
  return _flags[0] & 2 ? &_data_instanceSwapValues : nullptr;
}

const kiwi::Array<InstanceSwapPreferredValue> *ComponentPropPreferredValues::instanceSwapValues() const {
  return _flags[0] & 2 ? &_data_instanceSwapValues : nullptr;
}

kiwi::Array<InstanceSwapPreferredValue> &ComponentPropPreferredValues::set_instanceSwapValues(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 2; return _data_instanceSwapValues = pool.array<InstanceSwapPreferredValue>(count);
}

bool ComponentPropPreferredValues::encode(kiwi::ByteBuffer &_bb) {
  if (stringValues() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(_data_stringValues.size());
    for (kiwi::String &_it : _data_stringValues) _bb.writeString(_it.c_str());
  }
  if (instanceSwapValues() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarUint(_data_instanceSwapValues.size());
    for (InstanceSwapPreferredValue &_it : _data_instanceSwapValues) if (!_it.encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool ComponentPropPreferredValues::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(_count)) return false;
        for (kiwi::String &_it : set_stringValues(_pool, _count)) if (!_bb.readString(_it, _pool)) return false;
        break;
      }
      case 2: {
        if (!_bb.readVarUint(_count)) return false;
        for (InstanceSwapPreferredValue &_it : set_instanceSwapValues(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipComponentPropPreferredValuesField(_bb, _type)) return false;
        break;
      }
    }
  }
}

GUID *ComponentPropAssignment::defID() {
  return _data_defID;
}

const GUID *ComponentPropAssignment::defID() const {
  return _data_defID;
}

void ComponentPropAssignment::set_defID(GUID *value) {
  _data_defID = value;
}

ComponentPropValue *ComponentPropAssignment::value() {
  return _data_value;
}

const ComponentPropValue *ComponentPropAssignment::value() const {
  return _data_value;
}

void ComponentPropAssignment::set_value(ComponentPropValue *value) {
  _data_value = value;
}

VariableData *ComponentPropAssignment::varValue() {
  return _data_varValue;
}

const VariableData *ComponentPropAssignment::varValue() const {
  return _data_varValue;
}

void ComponentPropAssignment::set_varValue(VariableData *value) {
  _data_varValue = value;
}

bool ComponentPropAssignment::encode(kiwi::ByteBuffer &_bb) {
  if (defID() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_defID->encode(_bb)) return false;
  }
  if (value() != nullptr) {
    _bb.writeVarUint(2);
    if (!_data_value->encode(_bb)) return false;
  }
  if (varValue() != nullptr) {
    _bb.writeVarUint(3);
    if (!_data_varValue->encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool ComponentPropAssignment::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_defID = _pool.allocate<GUID>();
        if (!_data_defID->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        _data_value = _pool.allocate<ComponentPropValue>();
        if (!_data_value->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 3: {
        _data_varValue = _pool.allocate<VariableData>();
        if (!_data_varValue->decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipComponentPropAssignmentField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::Array<uint8_t> *Blob::bytes() {
  return _flags[0] & 1 ? &_data_bytes : nullptr;
}

const kiwi::Array<uint8_t> *Blob::bytes() const {
  return _flags[0] & 1 ? &_data_bytes : nullptr;
}

kiwi::Array<uint8_t> &Blob::set_bytes(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 1; return _data_bytes = pool.array<uint8_t>(count);
}

bool Blob::encode(kiwi::ByteBuffer &_bb) {
  if (bytes() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(_data_bytes.size());
    for (uint8_t &_it : _data_bytes) _bb.writeByte(_it);
  }
  _bb.writeVarUint(0);
  return true;
}

bool Blob::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(_count)) return false;
        for (uint8_t &_it : set_bytes(_pool, _count)) if (!_bb.readByte(_it)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipBlobField(_bb, _type)) return false;
        break;
      }
    }
  }
}

GUID *PixsoNode::guid() {
  return _data_guid;
}

const GUID *PixsoNode::guid() const {
  return _data_guid;
}

void PixsoNode::set_guid(GUID *value) {
  _data_guid = value;
}

GUIDPath *PixsoNode::guidPath() {
  return _data_guidPath;
}

const GUIDPath *PixsoNode::guidPath() const {
  return _data_guidPath;
}

void PixsoNode::set_guidPath(GUIDPath *value) {
  _data_guidPath = value;
}

ParentIndex *PixsoNode::parentIndex() {
  return _data_parentIndex;
}

const ParentIndex *PixsoNode::parentIndex() const {
  return _data_parentIndex;
}

void PixsoNode::set_parentIndex(ParentIndex *value) {
  _data_parentIndex = value;
}

NodePhase *PixsoNode::phase() {
  return _flags[0] & 8 ? &_data_phase : nullptr;
}

const NodePhase *PixsoNode::phase() const {
  return _flags[0] & 8 ? &_data_phase : nullptr;
}

void PixsoNode::set_phase(const NodePhase &value) {
  _flags[0] |= 8; _data_phase = value;
}

Matrix *PixsoNode::transform() {
  return _data_transform;
}

const Matrix *PixsoNode::transform() const {
  return _data_transform;
}

void PixsoNode::set_transform(Matrix *value) {
  _data_transform = value;
}

NodeType *PixsoNode::type() {
  return _flags[0] & 32 ? &_data_type : nullptr;
}

const NodeType *PixsoNode::type() const {
  return _flags[0] & 32 ? &_data_type : nullptr;
}

void PixsoNode::set_type(const NodeType &value) {
  _flags[0] |= 32; _data_type = value;
}

kiwi::String *PixsoNode::name() {
  return _flags[0] & 64 ? &_data_name : nullptr;
}

const kiwi::String *PixsoNode::name() const {
  return _flags[0] & 64 ? &_data_name : nullptr;
}

void PixsoNode::set_name(const kiwi::String &value) {
  _flags[0] |= 64; _data_name = value;
}

VectorData *PixsoNode::vectorData() {
  return _data_vectorData;
}

const VectorData *PixsoNode::vectorData() const {
  return _data_vectorData;
}

void PixsoNode::set_vectorData(VectorData *value) {
  _data_vectorData = value;
}

kiwi::String *PixsoNode::version() {
  return _flags[0] & 256 ? &_data_version : nullptr;
}

const kiwi::String *PixsoNode::version() const {
  return _flags[0] & 256 ? &_data_version : nullptr;
}

void PixsoNode::set_version(const kiwi::String &value) {
  _flags[0] |= 256; _data_version = value;
}

bool *PixsoNode::visible() {
  return _flags[0] & 512 ? &_data_visible : nullptr;
}

const bool *PixsoNode::visible() const {
  return _flags[0] & 512 ? &_data_visible : nullptr;
}

void PixsoNode::set_visible(const bool &value) {
  _flags[0] |= 512; _data_visible = value;
}

int32_t *PixsoNode::count() {
  return _flags[0] & 1024 ? &_data_count : nullptr;
}

const int32_t *PixsoNode::count() const {
  return _flags[0] & 1024 ? &_data_count : nullptr;
}

void PixsoNode::set_count(const int32_t &value) {
  _flags[0] |= 1024; _data_count = value;
}

Vector *PixsoNode::size() {
  return _data_size;
}

const Vector *PixsoNode::size() const {
  return _data_size;
}

void PixsoNode::set_size(Vector *value) {
  _data_size = value;
}

BooleanOperation *PixsoNode::booleanOperation() {
  return _flags[0] & 4096 ? &_data_booleanOperation : nullptr;
}

const BooleanOperation *PixsoNode::booleanOperation() const {
  return _flags[0] & 4096 ? &_data_booleanOperation : nullptr;
}

void PixsoNode::set_booleanOperation(const BooleanOperation &value) {
  _flags[0] |= 4096; _data_booleanOperation = value;
}

ArcData *PixsoNode::arcData() {
  return _data_arcData;
}

const ArcData *PixsoNode::arcData() const {
  return _data_arcData;
}

void PixsoNode::set_arcData(ArcData *value) {
  _data_arcData = value;
}

BlendMode *PixsoNode::blendMode() {
  return _flags[0] & 16384 ? &_data_blendMode : nullptr;
}

const BlendMode *PixsoNode::blendMode() const {
  return _flags[0] & 16384 ? &_data_blendMode : nullptr;
}

void PixsoNode::set_blendMode(const BlendMode &value) {
  _flags[0] |= 16384; _data_blendMode = value;
}

float *PixsoNode::cornerRadius() {
  return _flags[0] & 32768 ? &_data_cornerRadius : nullptr;
}

const float *PixsoNode::cornerRadius() const {
  return _flags[0] & 32768 ? &_data_cornerRadius : nullptr;
}

void PixsoNode::set_cornerRadius(const float &value) {
  _flags[0] |= 32768; _data_cornerRadius = value;
}

float *PixsoNode::cornerSmoothing() {
  return _flags[0] & 65536 ? &_data_cornerSmoothing : nullptr;
}

const float *PixsoNode::cornerSmoothing() const {
  return _flags[0] & 65536 ? &_data_cornerSmoothing : nullptr;
}

void PixsoNode::set_cornerSmoothing(const float &value) {
  _flags[0] |= 65536; _data_cornerSmoothing = value;
}

float *PixsoNode::opacity() {
  return _flags[0] & 131072 ? &_data_opacity : nullptr;
}

const float *PixsoNode::opacity() const {
  return _flags[0] & 131072 ? &_data_opacity : nullptr;
}

void PixsoNode::set_opacity(const float &value) {
  _flags[0] |= 131072; _data_opacity = value;
}

bool *PixsoNode::locked() {
  return _flags[0] & 262144 ? &_data_locked : nullptr;
}

const bool *PixsoNode::locked() const {
  return _flags[0] & 262144 ? &_data_locked : nullptr;
}

void PixsoNode::set_locked(const bool &value) {
  _flags[0] |= 262144; _data_locked = value;
}

kiwi::Array<Effect> *PixsoNode::effects() {
  return _flags[0] & 524288 ? &_data_effects : nullptr;
}

const kiwi::Array<Effect> *PixsoNode::effects() const {
  return _flags[0] & 524288 ? &_data_effects : nullptr;
}

kiwi::Array<Effect> &PixsoNode::set_effects(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 524288; return _data_effects = pool.array<Effect>(count);
}

kiwi::Array<Path> *PixsoNode::fillGeometry() {
  return _flags[0] & 1048576 ? &_data_fillGeometry : nullptr;
}

const kiwi::Array<Path> *PixsoNode::fillGeometry() const {
  return _flags[0] & 1048576 ? &_data_fillGeometry : nullptr;
}

kiwi::Array<Path> &PixsoNode::set_fillGeometry(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 1048576; return _data_fillGeometry = pool.array<Path>(count);
}

kiwi::Array<Paint> *PixsoNode::fillPaints() {
  return _flags[0] & 2097152 ? &_data_fillPaints : nullptr;
}

const kiwi::Array<Paint> *PixsoNode::fillPaints() const {
  return _flags[0] & 2097152 ? &_data_fillPaints : nullptr;
}

kiwi::Array<Paint> &PixsoNode::set_fillPaints(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 2097152; return _data_fillPaints = pool.array<Paint>(count);
}

kiwi::Array<float> *PixsoNode::dashPattern() {
  return _flags[0] & 4194304 ? &_data_dashPattern : nullptr;
}

const kiwi::Array<float> *PixsoNode::dashPattern() const {
  return _flags[0] & 4194304 ? &_data_dashPattern : nullptr;
}

kiwi::Array<float> &PixsoNode::set_dashPattern(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 4194304; return _data_dashPattern = pool.array<float>(count);
}

StackCounterAlign *PixsoNode::stackCounterAlign() {
  return _flags[0] & 8388608 ? &_data_stackCounterAlign : nullptr;
}

const StackCounterAlign *PixsoNode::stackCounterAlign() const {
  return _flags[0] & 8388608 ? &_data_stackCounterAlign : nullptr;
}

void PixsoNode::set_stackCounterAlign(const StackCounterAlign &value) {
  _flags[0] |= 8388608; _data_stackCounterAlign = value;
}

StackSize *PixsoNode::stackCounterSizing() {
  return _flags[0] & 16777216 ? &_data_stackCounterSizing : nullptr;
}

const StackSize *PixsoNode::stackCounterSizing() const {
  return _flags[0] & 16777216 ? &_data_stackCounterSizing : nullptr;
}

void PixsoNode::set_stackCounterSizing(const StackSize &value) {
  _flags[0] |= 16777216; _data_stackCounterSizing = value;
}

StackSize *PixsoNode::stackHeight() {
  return _flags[0] & 33554432 ? &_data_stackHeight : nullptr;
}

const StackSize *PixsoNode::stackHeight() const {
  return _flags[0] & 33554432 ? &_data_stackHeight : nullptr;
}

void PixsoNode::set_stackHeight(const StackSize &value) {
  _flags[0] |= 33554432; _data_stackHeight = value;
}

float *PixsoNode::stackHorizontalPadding() {
  return _flags[0] & 67108864 ? &_data_stackHorizontalPadding : nullptr;
}

const float *PixsoNode::stackHorizontalPadding() const {
  return _flags[0] & 67108864 ? &_data_stackHorizontalPadding : nullptr;
}

void PixsoNode::set_stackHorizontalPadding(const float &value) {
  _flags[0] |= 67108864; _data_stackHorizontalPadding = value;
}

StackJustify *PixsoNode::stackJustify() {
  return _flags[0] & 134217728 ? &_data_stackJustify : nullptr;
}

const StackJustify *PixsoNode::stackJustify() const {
  return _flags[0] & 134217728 ? &_data_stackJustify : nullptr;
}

void PixsoNode::set_stackJustify(const StackJustify &value) {
  _flags[0] |= 134217728; _data_stackJustify = value;
}

StackMode *PixsoNode::stackMode() {
  return _flags[0] & 268435456 ? &_data_stackMode : nullptr;
}

const StackMode *PixsoNode::stackMode() const {
  return _flags[0] & 268435456 ? &_data_stackMode : nullptr;
}

void PixsoNode::set_stackMode(const StackMode &value) {
  _flags[0] |= 268435456; _data_stackMode = value;
}

float *PixsoNode::stackPadding() {
  return _flags[0] & 536870912 ? &_data_stackPadding : nullptr;
}

const float *PixsoNode::stackPadding() const {
  return _flags[0] & 536870912 ? &_data_stackPadding : nullptr;
}

void PixsoNode::set_stackPadding(const float &value) {
  _flags[0] |= 536870912; _data_stackPadding = value;
}

float *PixsoNode::stackSpacing() {
  return _flags[0] & 1073741824 ? &_data_stackSpacing : nullptr;
}

const float *PixsoNode::stackSpacing() const {
  return _flags[0] & 1073741824 ? &_data_stackSpacing : nullptr;
}

void PixsoNode::set_stackSpacing(const float &value) {
  _flags[0] |= 1073741824; _data_stackSpacing = value;
}

float *PixsoNode::stackVerticalPadding() {
  return _flags[0] & 2147483648 ? &_data_stackVerticalPadding : nullptr;
}

const float *PixsoNode::stackVerticalPadding() const {
  return _flags[0] & 2147483648 ? &_data_stackVerticalPadding : nullptr;
}

void PixsoNode::set_stackVerticalPadding(const float &value) {
  _flags[0] |= 2147483648; _data_stackVerticalPadding = value;
}

StackSize *PixsoNode::stackWidth() {
  return _flags[1] & 1 ? &_data_stackWidth : nullptr;
}

const StackSize *PixsoNode::stackWidth() const {
  return _flags[1] & 1 ? &_data_stackWidth : nullptr;
}

void PixsoNode::set_stackWidth(const StackSize &value) {
  _flags[1] |= 1; _data_stackWidth = value;
}

StrokeAlign *PixsoNode::strokeAlign() {
  return _flags[1] & 2 ? &_data_strokeAlign : nullptr;
}

const StrokeAlign *PixsoNode::strokeAlign() const {
  return _flags[1] & 2 ? &_data_strokeAlign : nullptr;
}

void PixsoNode::set_strokeAlign(const StrokeAlign &value) {
  _flags[1] |= 2; _data_strokeAlign = value;
}

StrokeCap *PixsoNode::strokeCap() {
  return _flags[1] & 4 ? &_data_strokeCap : nullptr;
}

const StrokeCap *PixsoNode::strokeCap() const {
  return _flags[1] & 4 ? &_data_strokeCap : nullptr;
}

void PixsoNode::set_strokeCap(const StrokeCap &value) {
  _flags[1] |= 4; _data_strokeCap = value;
}

kiwi::Array<Path> *PixsoNode::strokeGeometry() {
  return _flags[1] & 8 ? &_data_strokeGeometry : nullptr;
}

const kiwi::Array<Path> *PixsoNode::strokeGeometry() const {
  return _flags[1] & 8 ? &_data_strokeGeometry : nullptr;
}

kiwi::Array<Path> &PixsoNode::set_strokeGeometry(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[1] |= 8; return _data_strokeGeometry = pool.array<Path>(count);
}

StrokeJoin *PixsoNode::strokeJoin() {
  return _flags[1] & 16 ? &_data_strokeJoin : nullptr;
}

const StrokeJoin *PixsoNode::strokeJoin() const {
  return _flags[1] & 16 ? &_data_strokeJoin : nullptr;
}

void PixsoNode::set_strokeJoin(const StrokeJoin &value) {
  _flags[1] |= 16; _data_strokeJoin = value;
}

kiwi::Array<Paint> *PixsoNode::strokePaints() {
  return _flags[1] & 32 ? &_data_strokePaints : nullptr;
}

const kiwi::Array<Paint> *PixsoNode::strokePaints() const {
  return _flags[1] & 32 ? &_data_strokePaints : nullptr;
}

kiwi::Array<Paint> &PixsoNode::set_strokePaints(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[1] |= 32; return _data_strokePaints = pool.array<Paint>(count);
}

float *PixsoNode::strokeWeight() {
  return _flags[1] & 64 ? &_data_strokeWeight : nullptr;
}

const float *PixsoNode::strokeWeight() const {
  return _flags[1] & 64 ? &_data_strokeWeight : nullptr;
}

void PixsoNode::set_strokeWeight(const float &value) {
  _flags[1] |= 64; _data_strokeWeight = value;
}

kiwi::String *PixsoNode::styleDescription() {
  return _flags[1] & 128 ? &_data_styleDescription : nullptr;
}

const kiwi::String *PixsoNode::styleDescription() const {
  return _flags[1] & 128 ? &_data_styleDescription : nullptr;
}

void PixsoNode::set_styleDescription(const kiwi::String &value) {
  _flags[1] |= 128; _data_styleDescription = value;
}

int32_t *PixsoNode::styleID() {
  return _flags[1] & 256 ? &_data_styleID : nullptr;
}

const int32_t *PixsoNode::styleID() const {
  return _flags[1] & 256 ? &_data_styleID : nullptr;
}

void PixsoNode::set_styleID(const int32_t &value) {
  _flags[1] |= 256; _data_styleID = value;
}

StyleType *PixsoNode::styleType() {
  return _flags[1] & 512 ? &_data_styleType : nullptr;
}

const StyleType *PixsoNode::styleType() const {
  return _flags[1] & 512 ? &_data_styleType : nullptr;
}

void PixsoNode::set_styleType(const StyleType &value) {
  _flags[1] |= 512; _data_styleType = value;
}

SymbolData *PixsoNode::symbolData() {
  return _data_symbolData;
}

const SymbolData *PixsoNode::symbolData() const {
  return _data_symbolData;
}

void PixsoNode::set_symbolData(SymbolData *value) {
  _data_symbolData = value;
}

kiwi::String *PixsoNode::symbolDescription() {
  return _flags[1] & 2048 ? &_data_symbolDescription : nullptr;
}

const kiwi::String *PixsoNode::symbolDescription() const {
  return _flags[1] & 2048 ? &_data_symbolDescription : nullptr;
}

void PixsoNode::set_symbolDescription(const kiwi::String &value) {
  _flags[1] |= 2048; _data_symbolDescription = value;
}

kiwi::Array<LayoutGrid> *PixsoNode::layoutGrids() {
  return _flags[1] & 4096 ? &_data_layoutGrids : nullptr;
}

const kiwi::Array<LayoutGrid> *PixsoNode::layoutGrids() const {
  return _flags[1] & 4096 ? &_data_layoutGrids : nullptr;
}

kiwi::Array<LayoutGrid> &PixsoNode::set_layoutGrids(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[1] |= 4096; return _data_layoutGrids = pool.array<LayoutGrid>(count);
}

bool *PixsoNode::mask() {
  return _flags[1] & 8192 ? &_data_mask : nullptr;
}

const bool *PixsoNode::mask() const {
  return _flags[1] & 8192 ? &_data_mask : nullptr;
}

void PixsoNode::set_mask(const bool &value) {
  _flags[1] |= 8192; _data_mask = value;
}

bool *PixsoNode::maskIsOutline() {
  return _flags[1] & 16384 ? &_data_maskIsOutline : nullptr;
}

const bool *PixsoNode::maskIsOutline() const {
  return _flags[1] & 16384 ? &_data_maskIsOutline : nullptr;
}

void PixsoNode::set_maskIsOutline(const bool &value) {
  _flags[1] |= 16384; _data_maskIsOutline = value;
}

float *PixsoNode::starInnerScale() {
  return _flags[1] & 32768 ? &_data_starInnerScale : nullptr;
}

const float *PixsoNode::starInnerScale() const {
  return _flags[1] & 32768 ? &_data_starInnerScale : nullptr;
}

void PixsoNode::set_starInnerScale(const float &value) {
  _flags[1] |= 32768; _data_starInnerScale = value;
}

float *PixsoNode::miterLimit() {
  return _flags[1] & 65536 ? &_data_miterLimit : nullptr;
}

const float *PixsoNode::miterLimit() const {
  return _flags[1] & 65536 ? &_data_miterLimit : nullptr;
}

void PixsoNode::set_miterLimit(const float &value) {
  _flags[1] |= 65536; _data_miterLimit = value;
}

Color *PixsoNode::backgroundColor() {
  return _data_backgroundColor;
}

const Color *PixsoNode::backgroundColor() const {
  return _data_backgroundColor;
}

void PixsoNode::set_backgroundColor(Color *value) {
  _data_backgroundColor = value;
}

bool *PixsoNode::backgroundEnabled() {
  return _flags[1] & 262144 ? &_data_backgroundEnabled : nullptr;
}

const bool *PixsoNode::backgroundEnabled() const {
  return _flags[1] & 262144 ? &_data_backgroundEnabled : nullptr;
}

void PixsoNode::set_backgroundEnabled(const bool &value) {
  _flags[1] |= 262144; _data_backgroundEnabled = value;
}

float *PixsoNode::backgroundOpacity() {
  return _flags[1] & 524288 ? &_data_backgroundOpacity : nullptr;
}

const float *PixsoNode::backgroundOpacity() const {
  return _flags[1] & 524288 ? &_data_backgroundOpacity : nullptr;
}

void PixsoNode::set_backgroundOpacity(const float &value) {
  _flags[1] |= 524288; _data_backgroundOpacity = value;
}

kiwi::Array<Paint> *PixsoNode::backgroundPaints() {
  return _flags[1] & 1048576 ? &_data_backgroundPaints : nullptr;
}

const kiwi::Array<Paint> *PixsoNode::backgroundPaints() const {
  return _flags[1] & 1048576 ? &_data_backgroundPaints : nullptr;
}

kiwi::Array<Paint> &PixsoNode::set_backgroundPaints(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[1] |= 1048576; return _data_backgroundPaints = pool.array<Paint>(count);
}

bool *PixsoNode::exportBackgroundDisabled() {
  return _flags[1] & 2097152 ? &_data_exportBackgroundDisabled : nullptr;
}

const bool *PixsoNode::exportBackgroundDisabled() const {
  return _flags[1] & 2097152 ? &_data_exportBackgroundDisabled : nullptr;
}

void PixsoNode::set_exportBackgroundDisabled(const bool &value) {
  _flags[1] |= 2097152; _data_exportBackgroundDisabled = value;
}

bool *PixsoNode::exportContentsOnly() {
  return _flags[1] & 4194304 ? &_data_exportContentsOnly : nullptr;
}

const bool *PixsoNode::exportContentsOnly() const {
  return _flags[1] & 4194304 ? &_data_exportContentsOnly : nullptr;
}

void PixsoNode::set_exportContentsOnly(const bool &value) {
  _flags[1] |= 4194304; _data_exportContentsOnly = value;
}

kiwi::Array<ExportSettings> *PixsoNode::exportSettings() {
  return _flags[1] & 8388608 ? &_data_exportSettings : nullptr;
}

const kiwi::Array<ExportSettings> *PixsoNode::exportSettings() const {
  return _flags[1] & 8388608 ? &_data_exportSettings : nullptr;
}

kiwi::Array<ExportSettings> &PixsoNode::set_exportSettings(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[1] |= 8388608; return _data_exportSettings = pool.array<ExportSettings>(count);
}

bool *PixsoNode::exportTextAsSVGText() {
  return _flags[1] & 16777216 ? &_data_exportTextAsSVGText : nullptr;
}

const bool *PixsoNode::exportTextAsSVGText() const {
  return _flags[1] & 16777216 ? &_data_exportTextAsSVGText : nullptr;
}

void PixsoNode::set_exportTextAsSVGText(const bool &value) {
  _flags[1] |= 16777216; _data_exportTextAsSVGText = value;
}

FontName *PixsoNode::fontName() {
  return _data_fontName;
}

const FontName *PixsoNode::fontName() const {
  return _data_fontName;
}

void PixsoNode::set_fontName(FontName *value) {
  _data_fontName = value;
}

float *PixsoNode::fontSize() {
  return _flags[1] & 67108864 ? &_data_fontSize : nullptr;
}

const float *PixsoNode::fontSize() const {
  return _flags[1] & 67108864 ? &_data_fontSize : nullptr;
}

void PixsoNode::set_fontSize(const float &value) {
  _flags[1] |= 67108864; _data_fontSize = value;
}

kiwi::String *PixsoNode::fontVersion() {
  return _flags[1] & 134217728 ? &_data_fontVersion : nullptr;
}

const kiwi::String *PixsoNode::fontVersion() const {
  return _flags[1] & 134217728 ? &_data_fontVersion : nullptr;
}

void PixsoNode::set_fontVersion(const kiwi::String &value) {
  _flags[1] |= 134217728; _data_fontVersion = value;
}

float *PixsoNode::paragraphIndent() {
  return _flags[1] & 268435456 ? &_data_paragraphIndent : nullptr;
}

const float *PixsoNode::paragraphIndent() const {
  return _flags[1] & 268435456 ? &_data_paragraphIndent : nullptr;
}

void PixsoNode::set_paragraphIndent(const float &value) {
  _flags[1] |= 268435456; _data_paragraphIndent = value;
}

float *PixsoNode::paragraphSpacing() {
  return _flags[1] & 536870912 ? &_data_paragraphSpacing : nullptr;
}

const float *PixsoNode::paragraphSpacing() const {
  return _flags[1] & 536870912 ? &_data_paragraphSpacing : nullptr;
}

void PixsoNode::set_paragraphSpacing(const float &value) {
  _flags[1] |= 536870912; _data_paragraphSpacing = value;
}

TextAlignHorizontal *PixsoNode::textAlignHorizontal() {
  return _flags[1] & 1073741824 ? &_data_textAlignHorizontal : nullptr;
}

const TextAlignHorizontal *PixsoNode::textAlignHorizontal() const {
  return _flags[1] & 1073741824 ? &_data_textAlignHorizontal : nullptr;
}

void PixsoNode::set_textAlignHorizontal(const TextAlignHorizontal &value) {
  _flags[1] |= 1073741824; _data_textAlignHorizontal = value;
}

TextAlignVertical *PixsoNode::textAlignVertical() {
  return _flags[1] & 2147483648 ? &_data_textAlignVertical : nullptr;
}

const TextAlignVertical *PixsoNode::textAlignVertical() const {
  return _flags[1] & 2147483648 ? &_data_textAlignVertical : nullptr;
}

void PixsoNode::set_textAlignVertical(const TextAlignVertical &value) {
  _flags[1] |= 2147483648; _data_textAlignVertical = value;
}

TextAutoResize *PixsoNode::textAutoResize() {
  return _flags[2] & 1 ? &_data_textAutoResize : nullptr;
}

const TextAutoResize *PixsoNode::textAutoResize() const {
  return _flags[2] & 1 ? &_data_textAutoResize : nullptr;
}

void PixsoNode::set_textAutoResize(const TextAutoResize &value) {
  _flags[2] |= 1; _data_textAutoResize = value;
}

TextCase *PixsoNode::textCase() {
  return _flags[2] & 2 ? &_data_textCase : nullptr;
}

const TextCase *PixsoNode::textCase() const {
  return _flags[2] & 2 ? &_data_textCase : nullptr;
}

void PixsoNode::set_textCase(const TextCase &value) {
  _flags[2] |= 2; _data_textCase = value;
}

TextData *PixsoNode::textData() {
  return _data_textData;
}

const TextData *PixsoNode::textData() const {
  return _data_textData;
}

void PixsoNode::set_textData(TextData *value) {
  _data_textData = value;
}

TextDecoration *PixsoNode::textDecoration() {
  return _flags[2] & 8 ? &_data_textDecoration : nullptr;
}

const TextDecoration *PixsoNode::textDecoration() const {
  return _flags[2] & 8 ? &_data_textDecoration : nullptr;
}

void PixsoNode::set_textDecoration(const TextDecoration &value) {
  _flags[2] |= 8; _data_textDecoration = value;
}

float *PixsoNode::textTracking() {
  return _flags[2] & 16 ? &_data_textTracking : nullptr;
}

const float *PixsoNode::textTracking() const {
  return _flags[2] & 16 ? &_data_textTracking : nullptr;
}

void PixsoNode::set_textTracking(const float &value) {
  _flags[2] |= 16; _data_textTracking = value;
}

int32_t *PixsoNode::textUserLayoutVersion() {
  return _flags[2] & 32 ? &_data_textUserLayoutVersion : nullptr;
}

const int32_t *PixsoNode::textUserLayoutVersion() const {
  return _flags[2] & 32 ? &_data_textUserLayoutVersion : nullptr;
}

void PixsoNode::set_textUserLayoutVersion(const int32_t &value) {
  _flags[2] |= 32; _data_textUserLayoutVersion = value;
}

Number *PixsoNode::letterSpacing() {
  return _data_letterSpacing;
}

const Number *PixsoNode::letterSpacing() const {
  return _data_letterSpacing;
}

void PixsoNode::set_letterSpacing(Number *value) {
  _data_letterSpacing = value;
}

Number *PixsoNode::lineHeight() {
  return _data_lineHeight;
}

const Number *PixsoNode::lineHeight() const {
  return _data_lineHeight;
}

void PixsoNode::set_lineHeight(Number *value) {
  _data_lineHeight = value;
}

ConstraintType *PixsoNode::horizontalConstraint() {
  return _flags[2] & 256 ? &_data_horizontalConstraint : nullptr;
}

const ConstraintType *PixsoNode::horizontalConstraint() const {
  return _flags[2] & 256 ? &_data_horizontalConstraint : nullptr;
}

void PixsoNode::set_horizontalConstraint(const ConstraintType &value) {
  _flags[2] |= 256; _data_horizontalConstraint = value;
}

ConstraintType *PixsoNode::verticalConstraint() {
  return _flags[2] & 512 ? &_data_verticalConstraint : nullptr;
}

const ConstraintType *PixsoNode::verticalConstraint() const {
  return _flags[2] & 512 ? &_data_verticalConstraint : nullptr;
}

void PixsoNode::set_verticalConstraint(const ConstraintType &value) {
  _flags[2] |= 512; _data_verticalConstraint = value;
}

kiwi::Array<PixsoNode> *PixsoNode::derivedSymbolData() {
  return _flags[2] & 1024 ? &_data_derivedSymbolData : nullptr;
}

const kiwi::Array<PixsoNode> *PixsoNode::derivedSymbolData() const {
  return _flags[2] & 1024 ? &_data_derivedSymbolData : nullptr;
}

kiwi::Array<PixsoNode> &PixsoNode::set_derivedSymbolData(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[2] |= 1024; return _data_derivedSymbolData = pool.array<PixsoNode>(count);
}

int32_t *PixsoNode::derivedSymbolDataLayoutVersion() {
  return _flags[2] & 2048 ? &_data_derivedSymbolDataLayoutVersion : nullptr;
}

const int32_t *PixsoNode::derivedSymbolDataLayoutVersion() const {
  return _flags[2] & 2048 ? &_data_derivedSymbolDataLayoutVersion : nullptr;
}

void PixsoNode::set_derivedSymbolDataLayoutVersion(const int32_t &value) {
  _flags[2] |= 2048; _data_derivedSymbolDataLayoutVersion = value;
}

kiwi::String *PixsoNode::componentKey() {
  return _flags[2] & 4096 ? &_data_componentKey : nullptr;
}

const kiwi::String *PixsoNode::componentKey() const {
  return _flags[2] & 4096 ? &_data_componentKey : nullptr;
}

void PixsoNode::set_componentKey(const kiwi::String &value) {
  _flags[2] |= 4096; _data_componentKey = value;
}

GUID *PixsoNode::inheritEffectStyleID() {
  return _data_inheritEffectStyleID;
}

const GUID *PixsoNode::inheritEffectStyleID() const {
  return _data_inheritEffectStyleID;
}

void PixsoNode::set_inheritEffectStyleID(GUID *value) {
  _data_inheritEffectStyleID = value;
}

GUID *PixsoNode::inheritExportStyleID() {
  return _data_inheritExportStyleID;
}

const GUID *PixsoNode::inheritExportStyleID() const {
  return _data_inheritExportStyleID;
}

void PixsoNode::set_inheritExportStyleID(GUID *value) {
  _data_inheritExportStyleID = value;
}

GUID *PixsoNode::inheritFillStyleID() {
  return _data_inheritFillStyleID;
}

const GUID *PixsoNode::inheritFillStyleID() const {
  return _data_inheritFillStyleID;
}

void PixsoNode::set_inheritFillStyleID(GUID *value) {
  _data_inheritFillStyleID = value;
}

GUID *PixsoNode::inheritFillStyleIDForBackground() {
  return _data_inheritFillStyleIDForBackground;
}

const GUID *PixsoNode::inheritFillStyleIDForBackground() const {
  return _data_inheritFillStyleIDForBackground;
}

void PixsoNode::set_inheritFillStyleIDForBackground(GUID *value) {
  _data_inheritFillStyleIDForBackground = value;
}

GUID *PixsoNode::inheritFillStyleIDForStroke() {
  return _data_inheritFillStyleIDForStroke;
}

const GUID *PixsoNode::inheritFillStyleIDForStroke() const {
  return _data_inheritFillStyleIDForStroke;
}

void PixsoNode::set_inheritFillStyleIDForStroke(GUID *value) {
  _data_inheritFillStyleIDForStroke = value;
}

GUID *PixsoNode::inheritGridStyleID() {
  return _data_inheritGridStyleID;
}

const GUID *PixsoNode::inheritGridStyleID() const {
  return _data_inheritGridStyleID;
}

void PixsoNode::set_inheritGridStyleID(GUID *value) {
  _data_inheritGridStyleID = value;
}

GUID *PixsoNode::inheritStrokeStyleID() {
  return _data_inheritStrokeStyleID;
}

const GUID *PixsoNode::inheritStrokeStyleID() const {
  return _data_inheritStrokeStyleID;
}

void PixsoNode::set_inheritStrokeStyleID(GUID *value) {
  _data_inheritStrokeStyleID = value;
}

GUID *PixsoNode::inheritTextStyleID() {
  return _data_inheritTextStyleID;
}

const GUID *PixsoNode::inheritTextStyleID() const {
  return _data_inheritTextStyleID;
}

void PixsoNode::set_inheritTextStyleID(GUID *value) {
  _data_inheritTextStyleID = value;
}

float *PixsoNode::interactionDuration() {
  return _flags[2] & 2097152 ? &_data_interactionDuration : nullptr;
}

const float *PixsoNode::interactionDuration() const {
  return _flags[2] & 2097152 ? &_data_interactionDuration : nullptr;
}

void PixsoNode::set_interactionDuration(const float &value) {
  _flags[2] |= 2097152; _data_interactionDuration = value;
}

bool *PixsoNode::interactionMaintained() {
  return _flags[2] & 4194304 ? &_data_interactionMaintained : nullptr;
}

const bool *PixsoNode::interactionMaintained() const {
  return _flags[2] & 4194304 ? &_data_interactionMaintained : nullptr;
}

void PixsoNode::set_interactionMaintained(const bool &value) {
  _flags[2] |= 4194304; _data_interactionMaintained = value;
}

GUID *PixsoNode::overriddenSymbolID() {
  return _data_overriddenSymbolID;
}

const GUID *PixsoNode::overriddenSymbolID() const {
  return _data_overriddenSymbolID;
}

void PixsoNode::set_overriddenSymbolID(GUID *value) {
  _data_overriddenSymbolID = value;
}

GUID *PixsoNode::overrideKey() {
  return _data_overrideKey;
}

const GUID *PixsoNode::overrideKey() const {
  return _data_overrideKey;
}

void PixsoNode::set_overrideKey(GUID *value) {
  _data_overrideKey = value;
}

KeyTrigger *PixsoNode::keyTrigger() {
  return _data_keyTrigger;
}

const KeyTrigger *PixsoNode::keyTrigger() const {
  return _data_keyTrigger;
}

void PixsoNode::set_keyTrigger(KeyTrigger *value) {
  _data_keyTrigger = value;
}

NavigationType *PixsoNode::navigationType() {
  return _flags[2] & 67108864 ? &_data_navigationType : nullptr;
}

const NavigationType *PixsoNode::navigationType() const {
  return _flags[2] & 67108864 ? &_data_navigationType : nullptr;
}

void PixsoNode::set_navigationType(const NavigationType &value) {
  _flags[2] |= 67108864; _data_navigationType = value;
}

InteractionType *PixsoNode::interactionType() {
  return _flags[2] & 134217728 ? &_data_interactionType : nullptr;
}

const InteractionType *PixsoNode::interactionType() const {
  return _flags[2] & 134217728 ? &_data_interactionType : nullptr;
}

void PixsoNode::set_interactionType(const InteractionType &value) {
  _flags[2] |= 134217728; _data_interactionType = value;
}

ConnectionType *PixsoNode::connectionType() {
  return _flags[2] & 268435456 ? &_data_connectionType : nullptr;
}

const ConnectionType *PixsoNode::connectionType() const {
  return _flags[2] & 268435456 ? &_data_connectionType : nullptr;
}

void PixsoNode::set_connectionType(const ConnectionType &value) {
  _flags[2] |= 268435456; _data_connectionType = value;
}

kiwi::String *PixsoNode::connectionURL() {
  return _flags[2] & 536870912 ? &_data_connectionURL : nullptr;
}

const kiwi::String *PixsoNode::connectionURL() const {
  return _flags[2] & 536870912 ? &_data_connectionURL : nullptr;
}

void PixsoNode::set_connectionURL(const kiwi::String &value) {
  _flags[2] |= 536870912; _data_connectionURL = value;
}

EasingType *PixsoNode::easingType() {
  return _flags[2] & 1073741824 ? &_data_easingType : nullptr;
}

const EasingType *PixsoNode::easingType() const {
  return _flags[2] & 1073741824 ? &_data_easingType : nullptr;
}

void PixsoNode::set_easingType(const EasingType &value) {
  _flags[2] |= 1073741824; _data_easingType = value;
}

bool *PixsoNode::proportionsConstrained() {
  return _flags[2] & 2147483648 ? &_data_proportionsConstrained : nullptr;
}

const bool *PixsoNode::proportionsConstrained() const {
  return _flags[2] & 2147483648 ? &_data_proportionsConstrained : nullptr;
}

void PixsoNode::set_proportionsConstrained(const bool &value) {
  _flags[2] |= 2147483648; _data_proportionsConstrained = value;
}

Color *PixsoNode::prototypeBackgroundColor() {
  return _data_prototypeBackgroundColor;
}

const Color *PixsoNode::prototypeBackgroundColor() const {
  return _data_prototypeBackgroundColor;
}

void PixsoNode::set_prototypeBackgroundColor(Color *value) {
  _data_prototypeBackgroundColor = value;
}

PrototypeDevice *PixsoNode::prototypeDevice() {
  return _data_prototypeDevice;
}

const PrototypeDevice *PixsoNode::prototypeDevice() const {
  return _data_prototypeDevice;
}

void PixsoNode::set_prototypeDevice(PrototypeDevice *value) {
  _data_prototypeDevice = value;
}

kiwi::Array<PrototypeInteraction> *PixsoNode::prototypeInteractions() {
  return _flags[3] & 4 ? &_data_prototypeInteractions : nullptr;
}

const kiwi::Array<PrototypeInteraction> *PixsoNode::prototypeInteractions() const {
  return _flags[3] & 4 ? &_data_prototypeInteractions : nullptr;
}

kiwi::Array<PrototypeInteraction> &PixsoNode::set_prototypeInteractions(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[3] |= 4; return _data_prototypeInteractions = pool.array<PrototypeInteraction>(count);
}

GUID *PixsoNode::prototypeStartNodeID() {
  return _data_prototypeStartNodeID;
}

const GUID *PixsoNode::prototypeStartNodeID() const {
  return _data_prototypeStartNodeID;
}

void PixsoNode::set_prototypeStartNodeID(GUID *value) {
  _data_prototypeStartNodeID = value;
}

OverlayBackgroundAppearance *PixsoNode::overlayBackgroundAppearance() {
  return _data_overlayBackgroundAppearance;
}

const OverlayBackgroundAppearance *PixsoNode::overlayBackgroundAppearance() const {
  return _data_overlayBackgroundAppearance;
}

void PixsoNode::set_overlayBackgroundAppearance(OverlayBackgroundAppearance *value) {
  _data_overlayBackgroundAppearance = value;
}

OverlayBackgroundInteraction *PixsoNode::overlayBackgroundInteraction() {
  return _flags[3] & 32 ? &_data_overlayBackgroundInteraction : nullptr;
}

const OverlayBackgroundInteraction *PixsoNode::overlayBackgroundInteraction() const {
  return _flags[3] & 32 ? &_data_overlayBackgroundInteraction : nullptr;
}

void PixsoNode::set_overlayBackgroundInteraction(const OverlayBackgroundInteraction &value) {
  _flags[3] |= 32; _data_overlayBackgroundInteraction = value;
}

OverlayPositionType *PixsoNode::overlayPositionType() {
  return _flags[3] & 64 ? &_data_overlayPositionType : nullptr;
}

const OverlayPositionType *PixsoNode::overlayPositionType() const {
  return _flags[3] & 64 ? &_data_overlayPositionType : nullptr;
}

void PixsoNode::set_overlayPositionType(const OverlayPositionType &value) {
  _flags[3] |= 64; _data_overlayPositionType = value;
}

Vector *PixsoNode::overlayRelativePosition() {
  return _data_overlayRelativePosition;
}

const Vector *PixsoNode::overlayRelativePosition() const {
  return _data_overlayRelativePosition;
}

void PixsoNode::set_overlayRelativePosition(Vector *value) {
  _data_overlayRelativePosition = value;
}

float *PixsoNode::transitionDuration() {
  return _flags[3] & 256 ? &_data_transitionDuration : nullptr;
}

const float *PixsoNode::transitionDuration() const {
  return _flags[3] & 256 ? &_data_transitionDuration : nullptr;
}

void PixsoNode::set_transitionDuration(const float &value) {
  _flags[3] |= 256; _data_transitionDuration = value;
}

GUID *PixsoNode::transitionNodeID() {
  return _data_transitionNodeID;
}

const GUID *PixsoNode::transitionNodeID() const {
  return _data_transitionNodeID;
}

void PixsoNode::set_transitionNodeID(GUID *value) {
  _data_transitionNodeID = value;
}

bool *PixsoNode::transitionPreserveScroll() {
  return _flags[3] & 1024 ? &_data_transitionPreserveScroll : nullptr;
}

const bool *PixsoNode::transitionPreserveScroll() const {
  return _flags[3] & 1024 ? &_data_transitionPreserveScroll : nullptr;
}

void PixsoNode::set_transitionPreserveScroll(const bool &value) {
  _flags[3] |= 1024; _data_transitionPreserveScroll = value;
}

bool *PixsoNode::transitionShouldSmartAnimate() {
  return _flags[3] & 2048 ? &_data_transitionShouldSmartAnimate : nullptr;
}

const bool *PixsoNode::transitionShouldSmartAnimate() const {
  return _flags[3] & 2048 ? &_data_transitionShouldSmartAnimate : nullptr;
}

void PixsoNode::set_transitionShouldSmartAnimate(const bool &value) {
  _flags[3] |= 2048; _data_transitionShouldSmartAnimate = value;
}

float *PixsoNode::transitionTimeout() {
  return _flags[3] & 4096 ? &_data_transitionTimeout : nullptr;
}

const float *PixsoNode::transitionTimeout() const {
  return _flags[3] & 4096 ? &_data_transitionTimeout : nullptr;
}

void PixsoNode::set_transitionTimeout(const float &value) {
  _flags[3] |= 4096; _data_transitionTimeout = value;
}

TransitionType *PixsoNode::transitionType() {
  return _flags[3] & 8192 ? &_data_transitionType : nullptr;
}

const TransitionType *PixsoNode::transitionType() const {
  return _flags[3] & 8192 ? &_data_transitionType : nullptr;
}

void PixsoNode::set_transitionType(const TransitionType &value) {
  _flags[3] |= 8192; _data_transitionType = value;
}

ScrollBehavior *PixsoNode::scrollBehavior() {
  return _flags[3] & 16384 ? &_data_scrollBehavior : nullptr;
}

const ScrollBehavior *PixsoNode::scrollBehavior() const {
  return _flags[3] & 16384 ? &_data_scrollBehavior : nullptr;
}

void PixsoNode::set_scrollBehavior(const ScrollBehavior &value) {
  _flags[3] |= 16384; _data_scrollBehavior = value;
}

ScrollDirection *PixsoNode::scrollDirection() {
  return _flags[3] & 32768 ? &_data_scrollDirection : nullptr;
}

const ScrollDirection *PixsoNode::scrollDirection() const {
  return _flags[3] & 32768 ? &_data_scrollDirection : nullptr;
}

void PixsoNode::set_scrollDirection(const ScrollDirection &value) {
  _flags[3] |= 32768; _data_scrollDirection = value;
}

float *PixsoNode::rectangleBottomLeftCornerRadius() {
  return _flags[3] & 65536 ? &_data_rectangleBottomLeftCornerRadius : nullptr;
}

const float *PixsoNode::rectangleBottomLeftCornerRadius() const {
  return _flags[3] & 65536 ? &_data_rectangleBottomLeftCornerRadius : nullptr;
}

void PixsoNode::set_rectangleBottomLeftCornerRadius(const float &value) {
  _flags[3] |= 65536; _data_rectangleBottomLeftCornerRadius = value;
}

float *PixsoNode::rectangleBottomRightCornerRadius() {
  return _flags[3] & 131072 ? &_data_rectangleBottomRightCornerRadius : nullptr;
}

const float *PixsoNode::rectangleBottomRightCornerRadius() const {
  return _flags[3] & 131072 ? &_data_rectangleBottomRightCornerRadius : nullptr;
}

void PixsoNode::set_rectangleBottomRightCornerRadius(const float &value) {
  _flags[3] |= 131072; _data_rectangleBottomRightCornerRadius = value;
}

bool *PixsoNode::rectangleCornerRadiiIndependent() {
  return _flags[3] & 262144 ? &_data_rectangleCornerRadiiIndependent : nullptr;
}

const bool *PixsoNode::rectangleCornerRadiiIndependent() const {
  return _flags[3] & 262144 ? &_data_rectangleCornerRadiiIndependent : nullptr;
}

void PixsoNode::set_rectangleCornerRadiiIndependent(const bool &value) {
  _flags[3] |= 262144; _data_rectangleCornerRadiiIndependent = value;
}

bool *PixsoNode::rectangleCornerToolIndependent() {
  return _flags[3] & 524288 ? &_data_rectangleCornerToolIndependent : nullptr;
}

const bool *PixsoNode::rectangleCornerToolIndependent() const {
  return _flags[3] & 524288 ? &_data_rectangleCornerToolIndependent : nullptr;
}

void PixsoNode::set_rectangleCornerToolIndependent(const bool &value) {
  _flags[3] |= 524288; _data_rectangleCornerToolIndependent = value;
}

float *PixsoNode::rectangleTopLeftCornerRadius() {
  return _flags[3] & 1048576 ? &_data_rectangleTopLeftCornerRadius : nullptr;
}

const float *PixsoNode::rectangleTopLeftCornerRadius() const {
  return _flags[3] & 1048576 ? &_data_rectangleTopLeftCornerRadius : nullptr;
}

void PixsoNode::set_rectangleTopLeftCornerRadius(const float &value) {
  _flags[3] |= 1048576; _data_rectangleTopLeftCornerRadius = value;
}

float *PixsoNode::rectangleTopRightCornerRadius() {
  return _flags[3] & 2097152 ? &_data_rectangleTopRightCornerRadius : nullptr;
}

const float *PixsoNode::rectangleTopRightCornerRadius() const {
  return _flags[3] & 2097152 ? &_data_rectangleTopRightCornerRadius : nullptr;
}

void PixsoNode::set_rectangleTopRightCornerRadius(const float &value) {
  _flags[3] |= 2097152; _data_rectangleTopRightCornerRadius = value;
}

bool *PixsoNode::frameMaskDisabled() {
  return _flags[3] & 4194304 ? &_data_frameMaskDisabled : nullptr;
}

const bool *PixsoNode::frameMaskDisabled() const {
  return _flags[3] & 4194304 ? &_data_frameMaskDisabled : nullptr;
}

void PixsoNode::set_frameMaskDisabled(const bool &value) {
  _flags[3] |= 4194304; _data_frameMaskDisabled = value;
}

Hyperlink *PixsoNode::hyperlink() {
  return _data_hyperlink;
}

const Hyperlink *PixsoNode::hyperlink() const {
  return _data_hyperlink;
}

void PixsoNode::set_hyperlink(Hyperlink *value) {
  _data_hyperlink = value;
}

SharedStyleMasterData *PixsoNode::sharedStyleMasterData() {
  return _data_sharedStyleMasterData;
}

const SharedStyleMasterData *PixsoNode::sharedStyleMasterData() const {
  return _data_sharedStyleMasterData;
}

void PixsoNode::set_sharedStyleMasterData(SharedStyleMasterData *value) {
  _data_sharedStyleMasterData = value;
}

SharedStyleReference *PixsoNode::sharedStyleReference() {
  return _data_sharedStyleReference;
}

const SharedStyleReference *PixsoNode::sharedStyleReference() const {
  return _data_sharedStyleReference;
}

void PixsoNode::set_sharedStyleReference(SharedStyleReference *value) {
  _data_sharedStyleReference = value;
}

bool *PixsoNode::autoRename() {
  return _flags[3] & 67108864 ? &_data_autoRename : nullptr;
}

const bool *PixsoNode::autoRename() const {
  return _flags[3] & 67108864 ? &_data_autoRename : nullptr;
}

void PixsoNode::set_autoRename(const bool &value) {
  _flags[3] |= 67108864; _data_autoRename = value;
}

VectorMirror *PixsoNode::handleMirroring() {
  return _flags[3] & 134217728 ? &_data_handleMirroring : nullptr;
}

const VectorMirror *PixsoNode::handleMirroring() const {
  return _flags[3] & 134217728 ? &_data_handleMirroring : nullptr;
}

void PixsoNode::set_handleMirroring(const VectorMirror &value) {
  _flags[3] |= 134217728; _data_handleMirroring = value;
}

bool *PixsoNode::internalOnly() {
  return _flags[3] & 268435456 ? &_data_internalOnly : nullptr;
}

const bool *PixsoNode::internalOnly() const {
  return _flags[3] & 268435456 ? &_data_internalOnly : nullptr;
}

void PixsoNode::set_internalOnly(const bool &value) {
  _flags[3] |= 268435456; _data_internalOnly = value;
}

bool *PixsoNode::isSoftDeletedStyle() {
  return _flags[3] & 536870912 ? &_data_isSoftDeletedStyle : nullptr;
}

const bool *PixsoNode::isSoftDeletedStyle() const {
  return _flags[3] & 536870912 ? &_data_isSoftDeletedStyle : nullptr;
}

void PixsoNode::set_isSoftDeletedStyle(const bool &value) {
  _flags[3] |= 536870912; _data_isSoftDeletedStyle = value;
}

bool *PixsoNode::isNonUpdateable() {
  return _flags[3] & 1073741824 ? &_data_isNonUpdateable : nullptr;
}

const bool *PixsoNode::isNonUpdateable() const {
  return _flags[3] & 1073741824 ? &_data_isNonUpdateable : nullptr;
}

void PixsoNode::set_isNonUpdateable(const bool &value) {
  _flags[3] |= 1073741824; _data_isNonUpdateable = value;
}

bool *PixsoNode::isPublishable() {
  return _flags[3] & 2147483648 ? &_data_isPublishable : nullptr;
}

const bool *PixsoNode::isPublishable() const {
  return _flags[3] & 2147483648 ? &_data_isPublishable : nullptr;
}

void PixsoNode::set_isPublishable(const bool &value) {
  _flags[3] |= 2147483648; _data_isPublishable = value;
}

kiwi::String *PixsoNode::publishFile() {
  return _flags[4] & 1 ? &_data_publishFile : nullptr;
}

const kiwi::String *PixsoNode::publishFile() const {
  return _flags[4] & 1 ? &_data_publishFile : nullptr;
}

void PixsoNode::set_publishFile(const kiwi::String &value) {
  _flags[4] |= 1; _data_publishFile = value;
}

GUID *PixsoNode::publishID() {
  return _data_publishID;
}

const GUID *PixsoNode::publishID() const {
  return _data_publishID;
}

void PixsoNode::set_publishID(GUID *value) {
  _data_publishID = value;
}

kiwi::String *PixsoNode::publishedVersion() {
  return _flags[4] & 4 ? &_data_publishedVersion : nullptr;
}

const kiwi::String *PixsoNode::publishedVersion() const {
  return _flags[4] & 4 ? &_data_publishedVersion : nullptr;
}

void PixsoNode::set_publishedVersion(const kiwi::String &value) {
  _flags[4] |= 4; _data_publishedVersion = value;
}

bool *PixsoNode::isSymbolPublishable() {
  return _flags[4] & 8 ? &_data_isSymbolPublishable : nullptr;
}

const bool *PixsoNode::isSymbolPublishable() const {
  return _flags[4] & 8 ? &_data_isSymbolPublishable : nullptr;
}

void PixsoNode::set_isSymbolPublishable(const bool &value) {
  _flags[4] |= 8; _data_isSymbolPublishable = value;
}

kiwi::String *PixsoNode::sharedSymbolVersion() {
  return _flags[4] & 16 ? &_data_sharedSymbolVersion : nullptr;
}

const kiwi::String *PixsoNode::sharedSymbolVersion() const {
  return _flags[4] & 16 ? &_data_sharedSymbolVersion : nullptr;
}

void PixsoNode::set_sharedSymbolVersion(const kiwi::String &value) {
  _flags[4] |= 16; _data_sharedSymbolVersion = value;
}

kiwi::Array<GUID> *PixsoNode::ancestorPathBeforeDeletion() {
  return _flags[4] & 32 ? &_data_ancestorPathBeforeDeletion : nullptr;
}

const kiwi::Array<GUID> *PixsoNode::ancestorPathBeforeDeletion() const {
  return _flags[4] & 32 ? &_data_ancestorPathBeforeDeletion : nullptr;
}

kiwi::Array<GUID> &PixsoNode::set_ancestorPathBeforeDeletion(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[4] |= 32; return _data_ancestorPathBeforeDeletion = pool.array<GUID>(count);
}

kiwi::Array<Guide> *PixsoNode::guides() {
  return _flags[4] & 64 ? &_data_guides : nullptr;
}

const kiwi::Array<Guide> *PixsoNode::guides() const {
  return _flags[4] & 64 ? &_data_guides : nullptr;
}

kiwi::Array<Guide> &PixsoNode::set_guides(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[4] |= 64; return _data_guides = pool.array<Guide>(count);
}

kiwi::Array<PropValueData> *PixsoNode::stateGroupPropertyValueOrders() {
  return _flags[4] & 128 ? &_data_stateGroupPropertyValueOrders : nullptr;
}

const kiwi::Array<PropValueData> *PixsoNode::stateGroupPropertyValueOrders() const {
  return _flags[4] & 128 ? &_data_stateGroupPropertyValueOrders : nullptr;
}

kiwi::Array<PropValueData> &PixsoNode::set_stateGroupPropertyValueOrders(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[4] |= 128; return _data_stateGroupPropertyValueOrders = pool.array<PropValueData>(count);
}

bool *PixsoNode::isStateGroup() {
  return _flags[4] & 256 ? &_data_isStateGroup : nullptr;
}

const bool *PixsoNode::isStateGroup() const {
  return _flags[4] & 256 ? &_data_isStateGroup : nullptr;
}

void PixsoNode::set_isStateGroup(const bool &value) {
  _flags[4] |= 256; _data_isStateGroup = value;
}

float *PixsoNode::stackPaddingRight() {
  return _flags[4] & 512 ? &_data_stackPaddingRight : nullptr;
}

const float *PixsoNode::stackPaddingRight() const {
  return _flags[4] & 512 ? &_data_stackPaddingRight : nullptr;
}

void PixsoNode::set_stackPaddingRight(const float &value) {
  _flags[4] |= 512; _data_stackPaddingRight = value;
}

float *PixsoNode::stackPaddingLeft() {
  return _flags[4] & 1024 ? &_data_stackPaddingLeft : nullptr;
}

const float *PixsoNode::stackPaddingLeft() const {
  return _flags[4] & 1024 ? &_data_stackPaddingLeft : nullptr;
}

void PixsoNode::set_stackPaddingLeft(const float &value) {
  _flags[4] |= 1024; _data_stackPaddingLeft = value;
}

float *PixsoNode::stackPaddingTop() {
  return _flags[4] & 2048 ? &_data_stackPaddingTop : nullptr;
}

const float *PixsoNode::stackPaddingTop() const {
  return _flags[4] & 2048 ? &_data_stackPaddingTop : nullptr;
}

void PixsoNode::set_stackPaddingTop(const float &value) {
  _flags[4] |= 2048; _data_stackPaddingTop = value;
}

float *PixsoNode::stackPaddingBottom() {
  return _flags[4] & 4096 ? &_data_stackPaddingBottom : nullptr;
}

const float *PixsoNode::stackPaddingBottom() const {
  return _flags[4] & 4096 ? &_data_stackPaddingBottom : nullptr;
}

void PixsoNode::set_stackPaddingBottom(const float &value) {
  _flags[4] |= 4096; _data_stackPaddingBottom = value;
}

StackSize *PixsoNode::stackPrimarySizing() {
  return _flags[4] & 8192 ? &_data_stackPrimarySizing : nullptr;
}

const StackSize *PixsoNode::stackPrimarySizing() const {
  return _flags[4] & 8192 ? &_data_stackPrimarySizing : nullptr;
}

void PixsoNode::set_stackPrimarySizing(const StackSize &value) {
  _flags[4] |= 8192; _data_stackPrimarySizing = value;
}

StackSize *PixsoNode::stackChildPrimarySizing() {
  return _flags[4] & 16384 ? &_data_stackChildPrimarySizing : nullptr;
}

const StackSize *PixsoNode::stackChildPrimarySizing() const {
  return _flags[4] & 16384 ? &_data_stackChildPrimarySizing : nullptr;
}

void PixsoNode::set_stackChildPrimarySizing(const StackSize &value) {
  _flags[4] |= 16384; _data_stackChildPrimarySizing = value;
}

StackSize *PixsoNode::stackChildCounterSizing() {
  return _flags[4] & 32768 ? &_data_stackChildCounterSizing : nullptr;
}

const StackSize *PixsoNode::stackChildCounterSizing() const {
  return _flags[4] & 32768 ? &_data_stackChildCounterSizing : nullptr;
}

void PixsoNode::set_stackChildCounterSizing(const StackSize &value) {
  _flags[4] |= 32768; _data_stackChildCounterSizing = value;
}

StackAlignItemMode *PixsoNode::stackPrimaryAlignItems() {
  return _flags[4] & 65536 ? &_data_stackPrimaryAlignItems : nullptr;
}

const StackAlignItemMode *PixsoNode::stackPrimaryAlignItems() const {
  return _flags[4] & 65536 ? &_data_stackPrimaryAlignItems : nullptr;
}

void PixsoNode::set_stackPrimaryAlignItems(const StackAlignItemMode &value) {
  _flags[4] |= 65536; _data_stackPrimaryAlignItems = value;
}

StackAlignItemMode *PixsoNode::stackCounterAlignItems() {
  return _flags[4] & 131072 ? &_data_stackCounterAlignItems : nullptr;
}

const StackAlignItemMode *PixsoNode::stackCounterAlignItems() const {
  return _flags[4] & 131072 ? &_data_stackCounterAlignItems : nullptr;
}

void PixsoNode::set_stackCounterAlignItems(const StackAlignItemMode &value) {
  _flags[4] |= 131072; _data_stackCounterAlignItems = value;
}

PrototypeStartPoint *PixsoNode::prototypeStartPt() {
  return _data_prototypeStartPt;
}

const PrototypeStartPoint *PixsoNode::prototypeStartPt() const {
  return _data_prototypeStartPt;
}

void PixsoNode::set_prototypeStartPt(PrototypeStartPoint *value) {
  _data_prototypeStartPt = value;
}

StrokeCap *PixsoNode::dashCap() {
  return _flags[4] & 524288 ? &_data_dashCap : nullptr;
}

const StrokeCap *PixsoNode::dashCap() const {
  return _flags[4] & 524288 ? &_data_dashCap : nullptr;
}

void PixsoNode::set_dashCap(const StrokeCap &value) {
  _flags[4] |= 524288; _data_dashCap = value;
}

ConnectLineInfo *PixsoNode::connectlineInfo() {
  return _data_connectlineInfo;
}

const ConnectLineInfo *PixsoNode::connectlineInfo() const {
  return _data_connectlineInfo;
}

void PixsoNode::set_connectlineInfo(ConnectLineInfo *value) {
  _data_connectlineInfo = value;
}

kiwi::Array<ObjSnapConnline> *PixsoNode::objSnapConnline() {
  return _flags[4] & 2097152 ? &_data_objSnapConnline : nullptr;
}

const kiwi::Array<ObjSnapConnline> *PixsoNode::objSnapConnline() const {
  return _flags[4] & 2097152 ? &_data_objSnapConnline : nullptr;
}

kiwi::Array<ObjSnapConnline> &PixsoNode::set_objSnapConnline(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[4] |= 2097152; return _data_objSnapConnline = pool.array<ObjSnapConnline>(count);
}

kiwi::Array<ConnlineTextInfo> *PixsoNode::connlineTextInfos() {
  return _flags[4] & 4194304 ? &_data_connlineTextInfos : nullptr;
}

const kiwi::Array<ConnlineTextInfo> *PixsoNode::connlineTextInfos() const {
  return _flags[4] & 4194304 ? &_data_connlineTextInfos : nullptr;
}

kiwi::Array<ConnlineTextInfo> &PixsoNode::set_connlineTextInfos(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[4] |= 4194304; return _data_connlineTextInfos = pool.array<ConnlineTextInfo>(count);
}

kiwi::Array<VectorPaint> *PixsoNode::vectorPaints() {
  return _flags[4] & 8388608 ? &_data_vectorPaints : nullptr;
}

const kiwi::Array<VectorPaint> *PixsoNode::vectorPaints() const {
  return _flags[4] & 8388608 ? &_data_vectorPaints : nullptr;
}

kiwi::Array<VectorPaint> &PixsoNode::set_vectorPaints(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[4] |= 8388608; return _data_vectorPaints = pool.array<VectorPaint>(count);
}

kiwi::Array<VectorStyle> *PixsoNode::vectorStyles() {
  return _flags[4] & 16777216 ? &_data_vectorStyles : nullptr;
}

const kiwi::Array<VectorStyle> *PixsoNode::vectorStyles() const {
  return _flags[4] & 16777216 ? &_data_vectorStyles : nullptr;
}

kiwi::Array<VectorStyle> &PixsoNode::set_vectorStyles(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[4] |= 16777216; return _data_vectorStyles = pool.array<VectorStyle>(count);
}

float *PixsoNode::borderTopWeight() {
  return _flags[4] & 33554432 ? &_data_borderTopWeight : nullptr;
}

const float *PixsoNode::borderTopWeight() const {
  return _flags[4] & 33554432 ? &_data_borderTopWeight : nullptr;
}

void PixsoNode::set_borderTopWeight(const float &value) {
  _flags[4] |= 33554432; _data_borderTopWeight = value;
}

float *PixsoNode::borderBottomWeight() {
  return _flags[4] & 67108864 ? &_data_borderBottomWeight : nullptr;
}

const float *PixsoNode::borderBottomWeight() const {
  return _flags[4] & 67108864 ? &_data_borderBottomWeight : nullptr;
}

void PixsoNode::set_borderBottomWeight(const float &value) {
  _flags[4] |= 67108864; _data_borderBottomWeight = value;
}

float *PixsoNode::borderLeftWeight() {
  return _flags[4] & 134217728 ? &_data_borderLeftWeight : nullptr;
}

const float *PixsoNode::borderLeftWeight() const {
  return _flags[4] & 134217728 ? &_data_borderLeftWeight : nullptr;
}

void PixsoNode::set_borderLeftWeight(const float &value) {
  _flags[4] |= 134217728; _data_borderLeftWeight = value;
}

float *PixsoNode::borderRightWeight() {
  return _flags[4] & 268435456 ? &_data_borderRightWeight : nullptr;
}

const float *PixsoNode::borderRightWeight() const {
  return _flags[4] & 268435456 ? &_data_borderRightWeight : nullptr;
}

void PixsoNode::set_borderRightWeight(const float &value) {
  _flags[4] |= 268435456; _data_borderRightWeight = value;
}

bool *PixsoNode::borderStrokeWeightsIndependent() {
  return _flags[4] & 536870912 ? &_data_borderStrokeWeightsIndependent : nullptr;
}

const bool *PixsoNode::borderStrokeWeightsIndependent() const {
  return _flags[4] & 536870912 ? &_data_borderStrokeWeightsIndependent : nullptr;
}

void PixsoNode::set_borderStrokeWeightsIndependent(const bool &value) {
  _flags[4] |= 536870912; _data_borderStrokeWeightsIndependent = value;
}

kiwi::Array<PluginData> *PixsoNode::pluginData() {
  return _flags[4] & 1073741824 ? &_data_pluginData : nullptr;
}

const kiwi::Array<PluginData> *PixsoNode::pluginData() const {
  return _flags[4] & 1073741824 ? &_data_pluginData : nullptr;
}

kiwi::Array<PluginData> &PixsoNode::set_pluginData(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[4] |= 1073741824; return _data_pluginData = pool.array<PluginData>(count);
}

bool *PixsoNode::showInSlice() {
  return _flags[4] & 2147483648 ? &_data_showInSlice : nullptr;
}

const bool *PixsoNode::showInSlice() const {
  return _flags[4] & 2147483648 ? &_data_showInSlice : nullptr;
}

void PixsoNode::set_showInSlice(const bool &value) {
  _flags[4] |= 2147483648; _data_showInSlice = value;
}

ExportImageQualityOp *PixsoNode::exportImageQuality() {
  return _flags[5] & 1 ? &_data_exportImageQuality : nullptr;
}

const ExportImageQualityOp *PixsoNode::exportImageQuality() const {
  return _flags[5] & 1 ? &_data_exportImageQuality : nullptr;
}

void PixsoNode::set_exportImageQuality(const ExportImageQualityOp &value) {
  _flags[5] |= 1; _data_exportImageQuality = value;
}

kiwi::Array<Path> *PixsoNode::strokePaddingPath() {
  return _flags[5] & 2 ? &_data_strokePaddingPath : nullptr;
}

const kiwi::Array<Path> *PixsoNode::strokePaddingPath() const {
  return _flags[5] & 2 ? &_data_strokePaddingPath : nullptr;
}

kiwi::Array<Path> &PixsoNode::set_strokePaddingPath(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[5] |= 2; return _data_strokePaddingPath = pool.array<Path>(count);
}

bool *PixsoNode::autoLayoutAbsolutePos() {
  return _flags[5] & 4 ? &_data_autoLayoutAbsolutePos : nullptr;
}

const bool *PixsoNode::autoLayoutAbsolutePos() const {
  return _flags[5] & 4 ? &_data_autoLayoutAbsolutePos : nullptr;
}

void PixsoNode::set_autoLayoutAbsolutePos(const bool &value) {
  _flags[5] |= 4; _data_autoLayoutAbsolutePos = value;
}

bool *PixsoNode::autoLayoutItemReverseDraw() {
  return _flags[5] & 8 ? &_data_autoLayoutItemReverseDraw : nullptr;
}

const bool *PixsoNode::autoLayoutItemReverseDraw() const {
  return _flags[5] & 8 ? &_data_autoLayoutItemReverseDraw : nullptr;
}

void PixsoNode::set_autoLayoutItemReverseDraw(const bool &value) {
  _flags[5] |= 8; _data_autoLayoutItemReverseDraw = value;
}

kiwi::Array<PluginRelaunchData> *PixsoNode::pluginRelaunchData() {
  return _flags[5] & 16 ? &_data_pluginRelaunchData : nullptr;
}

const kiwi::Array<PluginRelaunchData> *PixsoNode::pluginRelaunchData() const {
  return _flags[5] & 16 ? &_data_pluginRelaunchData : nullptr;
}

kiwi::Array<PluginRelaunchData> &PixsoNode::set_pluginRelaunchData(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[5] |= 16; return _data_pluginRelaunchData = pool.array<PluginRelaunchData>(count);
}

bool *PixsoNode::autoLayoutIncludeBorders() {
  return _flags[5] & 32 ? &_data_autoLayoutIncludeBorders : nullptr;
}

const bool *PixsoNode::autoLayoutIncludeBorders() const {
  return _flags[5] & 32 ? &_data_autoLayoutIncludeBorders : nullptr;
}

void PixsoNode::set_autoLayoutIncludeBorders(const bool &value) {
  _flags[5] |= 32; _data_autoLayoutIncludeBorders = value;
}

ProdMode *PixsoNode::prodMode() {
  return _data_prodMode;
}

const ProdMode *PixsoNode::prodMode() const {
  return _data_prodMode;
}

void PixsoNode::set_prodMode(ProdMode *value) {
  _data_prodMode = value;
}

bool *PixsoNode::exportCutPix() {
  return _flags[5] & 128 ? &_data_exportCutPix : nullptr;
}

const bool *PixsoNode::exportCutPix() const {
  return _flags[5] & 128 ? &_data_exportCutPix : nullptr;
}

void PixsoNode::set_exportCutPix(const bool &value) {
  _flags[5] |= 128; _data_exportCutPix = value;
}

bool *PixsoNode::exportKeepNameGroup() {
  return _flags[5] & 256 ? &_data_exportKeepNameGroup : nullptr;
}

const bool *PixsoNode::exportKeepNameGroup() const {
  return _flags[5] & 256 ? &_data_exportKeepNameGroup : nullptr;
}

void PixsoNode::set_exportKeepNameGroup(const bool &value) {
  _flags[5] |= 256; _data_exportKeepNameGroup = value;
}

TextTruncation *PixsoNode::textTruncation() {
  return _flags[5] & 512 ? &_data_textTruncation : nullptr;
}

const TextTruncation *PixsoNode::textTruncation() const {
  return _flags[5] & 512 ? &_data_textTruncation : nullptr;
}

void PixsoNode::set_textTruncation(const TextTruncation &value) {
  _flags[5] |= 512; _data_textTruncation = value;
}

MaskType *PixsoNode::maskType() {
  return _flags[5] & 1024 ? &_data_maskType : nullptr;
}

const MaskType *PixsoNode::maskType() const {
  return _flags[5] & 1024 ? &_data_maskType : nullptr;
}

void PixsoNode::set_maskType(const MaskType &value) {
  _flags[5] |= 1024; _data_maskType = value;
}

LeadingTrim *PixsoNode::leadingTrim() {
  return _flags[5] & 2048 ? &_data_leadingTrim : nullptr;
}

const LeadingTrim *PixsoNode::leadingTrim() const {
  return _flags[5] & 2048 ? &_data_leadingTrim : nullptr;
}

void PixsoNode::set_leadingTrim(const LeadingTrim &value) {
  _flags[5] |= 2048; _data_leadingTrim = value;
}

bool *PixsoNode::hangingPunctuation() {
  return _flags[5] & 4096 ? &_data_hangingPunctuation : nullptr;
}

const bool *PixsoNode::hangingPunctuation() const {
  return _flags[5] & 4096 ? &_data_hangingPunctuation : nullptr;
}

void PixsoNode::set_hangingPunctuation(const bool &value) {
  _flags[5] |= 4096; _data_hangingPunctuation = value;
}

bool *PixsoNode::hangingList() {
  return _flags[5] & 8192 ? &_data_hangingList : nullptr;
}

const bool *PixsoNode::hangingList() const {
  return _flags[5] & 8192 ? &_data_hangingList : nullptr;
}

void PixsoNode::set_hangingList(const bool &value) {
  _flags[5] |= 8192; _data_hangingList = value;
}

FontVariantNumericFigure *PixsoNode::fontVariantNumericFigure() {
  return _flags[5] & 16384 ? &_data_fontVariantNumericFigure : nullptr;
}

const FontVariantNumericFigure *PixsoNode::fontVariantNumericFigure() const {
  return _flags[5] & 16384 ? &_data_fontVariantNumericFigure : nullptr;
}

void PixsoNode::set_fontVariantNumericFigure(const FontVariantNumericFigure &value) {
  _flags[5] |= 16384; _data_fontVariantNumericFigure = value;
}

FontVariantNumericSpacing *PixsoNode::fontVariantNumericSpacing() {
  return _flags[5] & 32768 ? &_data_fontVariantNumericSpacing : nullptr;
}

const FontVariantNumericSpacing *PixsoNode::fontVariantNumericSpacing() const {
  return _flags[5] & 32768 ? &_data_fontVariantNumericSpacing : nullptr;
}

void PixsoNode::set_fontVariantNumericSpacing(const FontVariantNumericSpacing &value) {
  _flags[5] |= 32768; _data_fontVariantNumericSpacing = value;
}

FontVariantNumericFraction *PixsoNode::fontVariantNumericFraction() {
  return _flags[5] & 65536 ? &_data_fontVariantNumericFraction : nullptr;
}

const FontVariantNumericFraction *PixsoNode::fontVariantNumericFraction() const {
  return _flags[5] & 65536 ? &_data_fontVariantNumericFraction : nullptr;
}

void PixsoNode::set_fontVariantNumericFraction(const FontVariantNumericFraction &value) {
  _flags[5] |= 65536; _data_fontVariantNumericFraction = value;
}

FontVariantPosition *PixsoNode::fontVariantPosition() {
  return _flags[5] & 131072 ? &_data_fontVariantPosition : nullptr;
}

const FontVariantPosition *PixsoNode::fontVariantPosition() const {
  return _flags[5] & 131072 ? &_data_fontVariantPosition : nullptr;
}

void PixsoNode::set_fontVariantPosition(const FontVariantPosition &value) {
  _flags[5] |= 131072; _data_fontVariantPosition = value;
}

kiwi::Array<OpenTypeFeature> *PixsoNode::toggledOnOTFeatures() {
  return _flags[5] & 262144 ? &_data_toggledOnOTFeatures : nullptr;
}

const kiwi::Array<OpenTypeFeature> *PixsoNode::toggledOnOTFeatures() const {
  return _flags[5] & 262144 ? &_data_toggledOnOTFeatures : nullptr;
}

kiwi::Array<OpenTypeFeature> &PixsoNode::set_toggledOnOTFeatures(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[5] |= 262144; return _data_toggledOnOTFeatures = pool.array<OpenTypeFeature>(count);
}

kiwi::Array<OpenTypeFeature> *PixsoNode::toggledOffOTFeatures() {
  return _flags[5] & 524288 ? &_data_toggledOffOTFeatures : nullptr;
}

const kiwi::Array<OpenTypeFeature> *PixsoNode::toggledOffOTFeatures() const {
  return _flags[5] & 524288 ? &_data_toggledOffOTFeatures : nullptr;
}

kiwi::Array<OpenTypeFeature> &PixsoNode::set_toggledOffOTFeatures(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[5] |= 524288; return _data_toggledOffOTFeatures = pool.array<OpenTypeFeature>(count);
}

int32_t *PixsoNode::maxLines() {
  return _flags[5] & 1048576 ? &_data_maxLines : nullptr;
}

const int32_t *PixsoNode::maxLines() const {
  return _flags[5] & 1048576 ? &_data_maxLines : nullptr;
}

void PixsoNode::set_maxLines(const int32_t &value) {
  _flags[5] |= 1048576; _data_maxLines = value;
}

WorkState *PixsoNode::sectionState() {
  return _flags[5] & 2097152 ? &_data_sectionState : nullptr;
}

const WorkState *PixsoNode::sectionState() const {
  return _flags[5] & 2097152 ? &_data_sectionState : nullptr;
}

void PixsoNode::set_sectionState(const WorkState &value) {
  _flags[5] |= 2097152; _data_sectionState = value;
}

EditInfo *PixsoNode::editInfo() {
  return _data_editInfo;
}

const EditInfo *PixsoNode::editInfo() const {
  return _data_editInfo;
}

void PixsoNode::set_editInfo(EditInfo *value) {
  _data_editInfo = value;
}

float *PixsoNode::stackCounterSpacing() {
  return _flags[5] & 8388608 ? &_data_stackCounterSpacing : nullptr;
}

const float *PixsoNode::stackCounterSpacing() const {
  return _flags[5] & 8388608 ? &_data_stackCounterSpacing : nullptr;
}

void PixsoNode::set_stackCounterSpacing(const float &value) {
  _flags[5] |= 8388608; _data_stackCounterSpacing = value;
}

StackAlign *PixsoNode::stackCounterAlignContent() {
  return _flags[5] & 16777216 ? &_data_stackCounterAlignContent : nullptr;
}

const StackAlign *PixsoNode::stackCounterAlignContent() const {
  return _flags[5] & 16777216 ? &_data_stackCounterAlignContent : nullptr;
}

void PixsoNode::set_stackCounterAlignContent(const StackAlign &value) {
  _flags[5] |= 16777216; _data_stackCounterAlignContent = value;
}

WrapMode *PixsoNode::stackWrap() {
  return _flags[5] & 33554432 ? &_data_stackWrap : nullptr;
}

const WrapMode *PixsoNode::stackWrap() const {
  return _flags[5] & 33554432 ? &_data_stackWrap : nullptr;
}

void PixsoNode::set_stackWrap(const WrapMode &value) {
  _flags[5] |= 33554432; _data_stackWrap = value;
}

Vector *PixsoNode::minSize() {
  return _data_minSize;
}

const Vector *PixsoNode::minSize() const {
  return _data_minSize;
}

void PixsoNode::set_minSize(Vector *value) {
  _data_minSize = value;
}

Vector *PixsoNode::maxSize() {
  return _data_maxSize;
}

const Vector *PixsoNode::maxSize() const {
  return _data_maxSize;
}

void PixsoNode::set_maxSize(Vector *value) {
  _data_maxSize = value;
}

kiwi::Array<ComponentPropDef> *PixsoNode::componentPropDef() {
  return _flags[5] & 268435456 ? &_data_componentPropDef : nullptr;
}

const kiwi::Array<ComponentPropDef> *PixsoNode::componentPropDef() const {
  return _flags[5] & 268435456 ? &_data_componentPropDef : nullptr;
}

kiwi::Array<ComponentPropDef> &PixsoNode::set_componentPropDef(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[5] |= 268435456; return _data_componentPropDef = pool.array<ComponentPropDef>(count);
}

kiwi::Array<ComponentPropRef> *PixsoNode::componentPropRef() {
  return _flags[5] & 536870912 ? &_data_componentPropRef : nullptr;
}

const kiwi::Array<ComponentPropRef> *PixsoNode::componentPropRef() const {
  return _flags[5] & 536870912 ? &_data_componentPropRef : nullptr;
}

kiwi::Array<ComponentPropRef> &PixsoNode::set_componentPropRef(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[5] |= 536870912; return _data_componentPropRef = pool.array<ComponentPropRef>(count);
}

kiwi::Array<ComponentPropAssignment> *PixsoNode::componentPropAssignment() {
  return _flags[5] & 1073741824 ? &_data_componentPropAssignment : nullptr;
}

const kiwi::Array<ComponentPropAssignment> *PixsoNode::componentPropAssignment() const {
  return _flags[5] & 1073741824 ? &_data_componentPropAssignment : nullptr;
}

kiwi::Array<ComponentPropAssignment> &PixsoNode::set_componentPropAssignment(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[5] |= 1073741824; return _data_componentPropAssignment = pool.array<ComponentPropAssignment>(count);
}

kiwi::Array<SymbolLink> *PixsoNode::symbolLinks() {
  return _flags[5] & 2147483648 ? &_data_symbolLinks : nullptr;
}

const kiwi::Array<SymbolLink> *PixsoNode::symbolLinks() const {
  return _flags[5] & 2147483648 ? &_data_symbolLinks : nullptr;
}

kiwi::Array<SymbolLink> &PixsoNode::set_symbolLinks(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[5] |= 2147483648; return _data_symbolLinks = pool.array<SymbolLink>(count);
}

kiwi::String *PixsoNode::description() {
  return _flags[6] & 1 ? &_data_description : nullptr;
}

const kiwi::String *PixsoNode::description() const {
  return _flags[6] & 1 ? &_data_description : nullptr;
}

void PixsoNode::set_description(const kiwi::String &value) {
  _flags[6] |= 1; _data_description = value;
}

bool *PixsoNode::exportNameByVariantProp() {
  return _flags[6] & 2 ? &_data_exportNameByVariantProp : nullptr;
}

const bool *PixsoNode::exportNameByVariantProp() const {
  return _flags[6] & 2 ? &_data_exportNameByVariantProp : nullptr;
}

void PixsoNode::set_exportNameByVariantProp(const bool &value) {
  _flags[6] |= 2; _data_exportNameByVariantProp = value;
}

bool *PixsoNode::propsAreBubbled() {
  return _flags[6] & 4 ? &_data_propsAreBubbled : nullptr;
}

const bool *PixsoNode::propsAreBubbled() const {
  return _flags[6] & 4 ? &_data_propsAreBubbled : nullptr;
}

void PixsoNode::set_propsAreBubbled(const bool &value) {
  _flags[6] |= 4; _data_propsAreBubbled = value;
}

bool *PixsoNode::showMask() {
  return _flags[6] & 8 ? &_data_showMask : nullptr;
}

const bool *PixsoNode::showMask() const {
  return _flags[6] & 8 ? &_data_showMask : nullptr;
}

void PixsoNode::set_showMask(const bool &value) {
  _flags[6] |= 8; _data_showMask = value;
}

bool *PixsoNode::componentOverrideHierarchy() {
  return _flags[6] & 16 ? &_data_componentOverrideHierarchy : nullptr;
}

const bool *PixsoNode::componentOverrideHierarchy() const {
  return _flags[6] & 16 ? &_data_componentOverrideHierarchy : nullptr;
}

void PixsoNode::set_componentOverrideHierarchy(const bool &value) {
  _flags[6] |= 16; _data_componentOverrideHierarchy = value;
}

kiwi::Array<DeveloperRelatedLink> *PixsoNode::developerRelatedLinks() {
  return _flags[6] & 32 ? &_data_developerRelatedLinks : nullptr;
}

const kiwi::Array<DeveloperRelatedLink> *PixsoNode::developerRelatedLinks() const {
  return _flags[6] & 32 ? &_data_developerRelatedLinks : nullptr;
}

kiwi::Array<DeveloperRelatedLink> &PixsoNode::set_developerRelatedLinks(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[6] |= 32; return _data_developerRelatedLinks = pool.array<DeveloperRelatedLink>(count);
}

kiwi::Array<FontVariation> *PixsoNode::fontVariations() {
  return _flags[6] & 64 ? &_data_fontVariations : nullptr;
}

const kiwi::Array<FontVariation> *PixsoNode::fontVariations() const {
  return _flags[6] & 64 ? &_data_fontVariations : nullptr;
}

kiwi::Array<FontVariation> &PixsoNode::set_fontVariations(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[6] |= 64; return _data_fontVariations = pool.array<FontVariation>(count);
}

PathTextInfo *PixsoNode::pathTextInfo() {
  return _data_pathTextInfo;
}

const PathTextInfo *PixsoNode::pathTextInfo() const {
  return _data_pathTextInfo;
}

void PixsoNode::set_pathTextInfo(PathTextInfo *value) {
  _data_pathTextInfo = value;
}

bool *PixsoNode::detachOpticalSizeFromFontSize() {
  return _flags[6] & 256 ? &_data_detachOpticalSizeFromFontSize : nullptr;
}

const bool *PixsoNode::detachOpticalSizeFromFontSize() const {
  return _flags[6] & 256 ? &_data_detachOpticalSizeFromFontSize : nullptr;
}

void PixsoNode::set_detachOpticalSizeFromFontSize(const bool &value) {
  _flags[6] |= 256; _data_detachOpticalSizeFromFontSize = value;
}

RadialRepeatData *PixsoNode::radialRepeatData() {
  return _data_radialRepeatData;
}

const RadialRepeatData *PixsoNode::radialRepeatData() const {
  return _data_radialRepeatData;
}

void PixsoNode::set_radialRepeatData(RadialRepeatData *value) {
  _data_radialRepeatData = value;
}

int32_t *PixsoNode::overrideLevel() {
  return _flags[6] & 1024 ? &_data_overrideLevel : nullptr;
}

const int32_t *PixsoNode::overrideLevel() const {
  return _flags[6] & 1024 ? &_data_overrideLevel : nullptr;
}

void PixsoNode::set_overrideLevel(const int32_t &value) {
  _flags[6] |= 1024; _data_overrideLevel = value;
}

VariableData *PixsoNode::variableData() {
  return _data_variableData;
}

const VariableData *PixsoNode::variableData() const {
  return _data_variableData;
}

void PixsoNode::set_variableData(VariableData *value) {
  _data_variableData = value;
}

VariableDataMap *PixsoNode::variableConsumptionMap() {
  return _data_variableConsumptionMap;
}

const VariableDataMap *PixsoNode::variableConsumptionMap() const {
  return _data_variableConsumptionMap;
}

void PixsoNode::set_variableConsumptionMap(VariableDataMap *value) {
  _data_variableConsumptionMap = value;
}

VariableModeBySetMap *PixsoNode::variableModeBySetMap() {
  return _data_variableModeBySetMap;
}

const VariableModeBySetMap *PixsoNode::variableModeBySetMap() const {
  return _data_variableModeBySetMap;
}

void PixsoNode::set_variableModeBySetMap(VariableModeBySetMap *value) {
  _data_variableModeBySetMap = value;
}

kiwi::Array<VariableSetMode> *PixsoNode::variableSetModes() {
  return _flags[6] & 16384 ? &_data_variableSetModes : nullptr;
}

const kiwi::Array<VariableSetMode> *PixsoNode::variableSetModes() const {
  return _flags[6] & 16384 ? &_data_variableSetModes : nullptr;
}

kiwi::Array<VariableSetMode> &PixsoNode::set_variableSetModes(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[6] |= 16384; return _data_variableSetModes = pool.array<VariableSetMode>(count);
}

AssetID *PixsoNode::variableSetID() {
  return _data_variableSetID;
}

const AssetID *PixsoNode::variableSetID() const {
  return _data_variableSetID;
}

void PixsoNode::set_variableSetID(AssetID *value) {
  _data_variableSetID = value;
}

VariableResolvedDataType *PixsoNode::variableResolvedType() {
  return _flags[6] & 65536 ? &_data_variableResolvedType : nullptr;
}

const VariableResolvedDataType *PixsoNode::variableResolvedType() const {
  return _flags[6] & 65536 ? &_data_variableResolvedType : nullptr;
}

void PixsoNode::set_variableResolvedType(const VariableResolvedDataType &value) {
  _flags[6] |= 65536; _data_variableResolvedType = value;
}

VariableDataValues *PixsoNode::variableDataValues() {
  return _data_variableDataValues;
}

const VariableDataValues *PixsoNode::variableDataValues() const {
  return _data_variableDataValues;
}

void PixsoNode::set_variableDataValues(VariableDataValues *value) {
  _data_variableDataValues = value;
}

kiwi::String *PixsoNode::variableTokenName() {
  return _flags[6] & 262144 ? &_data_variableTokenName : nullptr;
}

const kiwi::String *PixsoNode::variableTokenName() const {
  return _flags[6] & 262144 ? &_data_variableTokenName : nullptr;
}

void PixsoNode::set_variableTokenName(const kiwi::String &value) {
  _flags[6] |= 262144; _data_variableTokenName = value;
}

kiwi::Array<VariableScope> *PixsoNode::variableScopes() {
  return _flags[6] & 524288 ? &_data_variableScopes : nullptr;
}

const kiwi::Array<VariableScope> *PixsoNode::variableScopes() const {
  return _flags[6] & 524288 ? &_data_variableScopes : nullptr;
}

kiwi::Array<VariableScope> &PixsoNode::set_variableScopes(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[6] |= 524288; return _data_variableScopes = pool.array<VariableScope>(count);
}

CodeSyntaxMap *PixsoNode::codeSyntax() {
  return _data_codeSyntax;
}

const CodeSyntaxMap *PixsoNode::codeSyntax() const {
  return _data_codeSyntax;
}

void PixsoNode::set_codeSyntax(CodeSyntaxMap *value) {
  _data_codeSyntax = value;
}

AssetID *PixsoNode::backingVariableSetId() {
  return _data_backingVariableSetId;
}

const AssetID *PixsoNode::backingVariableSetId() const {
  return _data_backingVariableSetId;
}

void PixsoNode::set_backingVariableSetId(AssetID *value) {
  _data_backingVariableSetId = value;
}

VariableIdOrVariableOverrideId *PixsoNode::backingVariableId() {
  return _data_backingVariableId;
}

const VariableIdOrVariableOverrideId *PixsoNode::backingVariableId() const {
  return _data_backingVariableId;
}

void PixsoNode::set_backingVariableId(VariableIdOrVariableOverrideId *value) {
  _data_backingVariableId = value;
}

kiwi::String *PixsoNode::rootVariableKey() {
  return _flags[6] & 8388608 ? &_data_rootVariableKey : nullptr;
}

const kiwi::String *PixsoNode::rootVariableKey() const {
  return _flags[6] & 8388608 ? &_data_rootVariableKey : nullptr;
}

void PixsoNode::set_rootVariableKey(const kiwi::String &value) {
  _flags[6] |= 8388608; _data_rootVariableKey = value;
}

kiwi::String *PixsoNode::userFacingVersion() {
  return _flags[6] & 16777216 ? &_data_userFacingVersion : nullptr;
}

const kiwi::String *PixsoNode::userFacingVersion() const {
  return _flags[6] & 16777216 ? &_data_userFacingVersion : nullptr;
}

void PixsoNode::set_userFacingVersion(const kiwi::String &value) {
  _flags[6] |= 16777216; _data_userFacingVersion = value;
}

kiwi::String *PixsoNode::key() {
  return _flags[6] & 33554432 ? &_data_key : nullptr;
}

const kiwi::String *PixsoNode::key() const {
  return _flags[6] & 33554432 ? &_data_key : nullptr;
}

void PixsoNode::set_key(const kiwi::String &value) {
  _flags[6] |= 33554432; _data_key = value;
}

bool *PixsoNode::isSoftDeleted() {
  return _flags[6] & 67108864 ? &_data_isSoftDeleted : nullptr;
}

const bool *PixsoNode::isSoftDeleted() const {
  return _flags[6] & 67108864 ? &_data_isSoftDeleted : nullptr;
}

void PixsoNode::set_isSoftDeleted(const bool &value) {
  _flags[6] |= 67108864; _data_isSoftDeleted = value;
}

kiwi::String *PixsoNode::sortPosition() {
  return _flags[6] & 134217728 ? &_data_sortPosition : nullptr;
}

const kiwi::String *PixsoNode::sortPosition() const {
  return _flags[6] & 134217728 ? &_data_sortPosition : nullptr;
}

void PixsoNode::set_sortPosition(const kiwi::String &value) {
  _flags[6] |= 134217728; _data_sortPosition = value;
}

kiwi::String *PixsoNode::sourceLibraryKey() {
  return _flags[6] & 268435456 ? &_data_sourceLibraryKey : nullptr;
}

const kiwi::String *PixsoNode::sourceLibraryKey() const {
  return _flags[6] & 268435456 ? &_data_sourceLibraryKey : nullptr;
}

void PixsoNode::set_sourceLibraryKey(const kiwi::String &value) {
  _flags[6] |= 268435456; _data_sourceLibraryKey = value;
}

DeliverInfo *PixsoNode::deliverInfo() {
  return _data_deliverInfo;
}

const DeliverInfo *PixsoNode::deliverInfo() const {
  return _data_deliverInfo;
}

void PixsoNode::set_deliverInfo(DeliverInfo *value) {
  _data_deliverInfo = value;
}

Matrix3f *PixsoNode::deformationTransform() {
  return _data_deformationTransform;
}

const Matrix3f *PixsoNode::deformationTransform() const {
  return _data_deformationTransform;
}

void PixsoNode::set_deformationTransform(Matrix3f *value) {
  _data_deformationTransform = value;
}

kiwi::Array<TransformModifier> *PixsoNode::transformModifiers() {
  return _flags[6] & 2147483648 ? &_data_transformModifiers : nullptr;
}

const kiwi::Array<TransformModifier> *PixsoNode::transformModifiers() const {
  return _flags[6] & 2147483648 ? &_data_transformModifiers : nullptr;
}

kiwi::Array<TransformModifier> &PixsoNode::set_transformModifiers(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[6] |= 2147483648; return _data_transformModifiers = pool.array<TransformModifier>(count);
}

bool *PixsoNode::groupIncludeInvisible() {
  return _flags[7] & 1 ? &_data_groupIncludeInvisible : nullptr;
}

const bool *PixsoNode::groupIncludeInvisible() const {
  return _flags[7] & 1 ? &_data_groupIncludeInvisible : nullptr;
}

void PixsoNode::set_groupIncludeInvisible(const bool &value) {
  _flags[7] |= 1; _data_groupIncludeInvisible = value;
}

GUID *PixsoNode::variableSymbolID() {
  return _data_variableSymbolID;
}

const GUID *PixsoNode::variableSymbolID() const {
  return _data_variableSymbolID;
}

void PixsoNode::set_variableSymbolID(GUID *value) {
  _data_variableSymbolID = value;
}

kiwi::Array<Annotation> *PixsoNode::annotations() {
  return _flags[7] & 4 ? &_data_annotations : nullptr;
}

const kiwi::Array<Annotation> *PixsoNode::annotations() const {
  return _flags[7] & 4 ? &_data_annotations : nullptr;
}

kiwi::Array<Annotation> &PixsoNode::set_annotations(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[7] |= 4; return _data_annotations = pool.array<Annotation>(count);
}

AnnotationCategories *PixsoNode::annotationCategories() {
  return _data_annotationCategories;
}

const AnnotationCategories *PixsoNode::annotationCategories() const {
  return _data_annotationCategories;
}

void PixsoNode::set_annotationCategories(AnnotationCategories *value) {
  _data_annotationCategories = value;
}

GUID *PixsoNode::gridRowAnchor() {
  return _data_gridRowAnchor;
}

const GUID *PixsoNode::gridRowAnchor() const {
  return _data_gridRowAnchor;
}

void PixsoNode::set_gridRowAnchor(GUID *value) {
  _data_gridRowAnchor = value;
}

GUID *PixsoNode::gridColumnAnchor() {
  return _data_gridColumnAnchor;
}

const GUID *PixsoNode::gridColumnAnchor() const {
  return _data_gridColumnAnchor;
}

void PixsoNode::set_gridColumnAnchor(GUID *value) {
  _data_gridColumnAnchor = value;
}

uint32_t *PixsoNode::gridRowSpan() {
  return _flags[7] & 64 ? &_data_gridRowSpan : nullptr;
}

const uint32_t *PixsoNode::gridRowSpan() const {
  return _flags[7] & 64 ? &_data_gridRowSpan : nullptr;
}

void PixsoNode::set_gridRowSpan(const uint32_t &value) {
  _flags[7] |= 64; _data_gridRowSpan = value;
}

uint32_t *PixsoNode::gridColumnSpan() {
  return _flags[7] & 128 ? &_data_gridColumnSpan : nullptr;
}

const uint32_t *PixsoNode::gridColumnSpan() const {
  return _flags[7] & 128 ? &_data_gridColumnSpan : nullptr;
}

void PixsoNode::set_gridColumnSpan(const uint32_t &value) {
  _flags[7] |= 128; _data_gridColumnSpan = value;
}

GridChildAlign *PixsoNode::gridChildVerticalAlign() {
  return _flags[7] & 256 ? &_data_gridChildVerticalAlign : nullptr;
}

const GridChildAlign *PixsoNode::gridChildVerticalAlign() const {
  return _flags[7] & 256 ? &_data_gridChildVerticalAlign : nullptr;
}

void PixsoNode::set_gridChildVerticalAlign(const GridChildAlign &value) {
  _flags[7] |= 256; _data_gridChildVerticalAlign = value;
}

GridChildAlign *PixsoNode::gridChildHorizontalAlign() {
  return _flags[7] & 512 ? &_data_gridChildHorizontalAlign : nullptr;
}

const GridChildAlign *PixsoNode::gridChildHorizontalAlign() const {
  return _flags[7] & 512 ? &_data_gridChildHorizontalAlign : nullptr;
}

void PixsoNode::set_gridChildHorizontalAlign(const GridChildAlign &value) {
  _flags[7] |= 512; _data_gridChildHorizontalAlign = value;
}

kiwi::Array<GUID> *PixsoNode::gridRows() {
  return _flags[7] & 1024 ? &_data_gridRows : nullptr;
}

const kiwi::Array<GUID> *PixsoNode::gridRows() const {
  return _flags[7] & 1024 ? &_data_gridRows : nullptr;
}

kiwi::Array<GUID> &PixsoNode::set_gridRows(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[7] |= 1024; return _data_gridRows = pool.array<GUID>(count);
}

kiwi::Array<GUID> *PixsoNode::gridColumns() {
  return _flags[7] & 2048 ? &_data_gridColumns : nullptr;
}

const kiwi::Array<GUID> *PixsoNode::gridColumns() const {
  return _flags[7] & 2048 ? &_data_gridColumns : nullptr;
}

kiwi::Array<GUID> &PixsoNode::set_gridColumns(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[7] |= 2048; return _data_gridColumns = pool.array<GUID>(count);
}

kiwi::Array<GridTrackSizing> *PixsoNode::gridRowsSizing() {
  return _flags[7] & 4096 ? &_data_gridRowsSizing : nullptr;
}

const kiwi::Array<GridTrackSizing> *PixsoNode::gridRowsSizing() const {
  return _flags[7] & 4096 ? &_data_gridRowsSizing : nullptr;
}

kiwi::Array<GridTrackSizing> &PixsoNode::set_gridRowsSizing(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[7] |= 4096; return _data_gridRowsSizing = pool.array<GridTrackSizing>(count);
}

kiwi::Array<GridTrackSizing> *PixsoNode::gridColumnsSizing() {
  return _flags[7] & 8192 ? &_data_gridColumnsSizing : nullptr;
}

const kiwi::Array<GridTrackSizing> *PixsoNode::gridColumnsSizing() const {
  return _flags[7] & 8192 ? &_data_gridColumnsSizing : nullptr;
}

kiwi::Array<GridTrackSizing> &PixsoNode::set_gridColumnsSizing(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[7] |= 8192; return _data_gridColumnsSizing = pool.array<GridTrackSizing>(count);
}

bool *PixsoNode::autoCornerRadius() {
  return _flags[7] & 16384 ? &_data_autoCornerRadius : nullptr;
}

const bool *PixsoNode::autoCornerRadius() const {
  return _flags[7] & 16384 ? &_data_autoCornerRadius : nullptr;
}

void PixsoNode::set_autoCornerRadius(const bool &value) {
  _flags[7] |= 16384; _data_autoCornerRadius = value;
}

Vector *PixsoNode::targetAspectRatio() {
  return _data_targetAspectRatio;
}

const Vector *PixsoNode::targetAspectRatio() const {
  return _data_targetAspectRatio;
}

void PixsoNode::set_targetAspectRatio(Vector *value) {
  _data_targetAspectRatio = value;
}

kiwi::String *PixsoNode::aliasName() {
  return _flags[7] & 65536 ? &_data_aliasName : nullptr;
}

const kiwi::String *PixsoNode::aliasName() const {
  return _flags[7] & 65536 ? &_data_aliasName : nullptr;
}

void PixsoNode::set_aliasName(const kiwi::String &value) {
  _flags[7] |= 65536; _data_aliasName = value;
}

bool *PixsoNode::simplifyInstancePanels() {
  return _flags[7] & 131072 ? &_data_simplifyInstancePanels : nullptr;
}

const bool *PixsoNode::simplifyInstancePanels() const {
  return _flags[7] & 131072 ? &_data_simplifyInstancePanels : nullptr;
}

void PixsoNode::set_simplifyInstancePanels(const bool &value) {
  _flags[7] |= 131072; _data_simplifyInstancePanels = value;
}

Vector *PixsoNode::rotationOrigin() {
  return _data_rotationOrigin;
}

const Vector *PixsoNode::rotationOrigin() const {
  return _data_rotationOrigin;
}

void PixsoNode::set_rotationOrigin(Vector *value) {
  _data_rotationOrigin = value;
}

VideoPlayback *PixsoNode::videoPlayback() {
  return _data_videoPlayback;
}

const VideoPlayback *PixsoNode::videoPlayback() const {
  return _data_videoPlayback;
}

void PixsoNode::set_videoPlayback(VideoPlayback *value) {
  _data_videoPlayback = value;
}

kiwi::Array<VariableWidthPoint> *PixsoNode::variableWidths() {
  return _flags[7] & 1048576 ? &_data_variableWidths : nullptr;
}

const kiwi::Array<VariableWidthPoint> *PixsoNode::variableWidths() const {
  return _flags[7] & 1048576 ? &_data_variableWidths : nullptr;
}

kiwi::Array<VariableWidthPoint> &PixsoNode::set_variableWidths(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[7] |= 1048576; return _data_variableWidths = pool.array<VariableWidthPoint>(count);
}

bool PixsoNode::encode(kiwi::ByteBuffer &_bb) {
  if (guid() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_guid->encode(_bb)) return false;
  }
  if (guidPath() != nullptr) {
    _bb.writeVarUint(2);
    if (!_data_guidPath->encode(_bb)) return false;
  }
  if (parentIndex() != nullptr) {
    _bb.writeVarUint(3);
    if (!_data_parentIndex->encode(_bb)) return false;
  }
  if (phase() != nullptr) {
    _bb.writeVarUint(4);
    _bb.writeVarUint(static_cast<uint32_t>(_data_phase));
  }
  if (transform() != nullptr) {
    _bb.writeVarUint(5);
    if (!_data_transform->encode(_bb)) return false;
  }
  if (type() != nullptr) {
    _bb.writeVarUint(6);
    _bb.writeVarUint(static_cast<uint32_t>(_data_type));
  }
  if (name() != nullptr) {
    _bb.writeVarUint(7);
    _bb.writeString(_data_name.c_str());
  }
  if (vectorData() != nullptr) {
    _bb.writeVarUint(8);
    if (!_data_vectorData->encode(_bb)) return false;
  }
  if (version() != nullptr) {
    _bb.writeVarUint(9);
    _bb.writeString(_data_version.c_str());
  }
  if (visible() != nullptr) {
    _bb.writeVarUint(10);
    _bb.writeByte(_data_visible);
  }
  if (count() != nullptr) {
    _bb.writeVarUint(11);
    _bb.writeVarInt(_data_count);
  }
  if (size() != nullptr) {
    _bb.writeVarUint(12);
    if (!_data_size->encode(_bb)) return false;
  }
  if (booleanOperation() != nullptr) {
    _bb.writeVarUint(13);
    _bb.writeVarUint(static_cast<uint32_t>(_data_booleanOperation));
  }
  if (arcData() != nullptr) {
    _bb.writeVarUint(14);
    if (!_data_arcData->encode(_bb)) return false;
  }
  if (blendMode() != nullptr) {
    _bb.writeVarUint(15);
    _bb.writeVarUint(static_cast<uint32_t>(_data_blendMode));
  }
  if (cornerRadius() != nullptr) {
    _bb.writeVarUint(16);
    _bb.writeVarFloat(_data_cornerRadius);
  }
  if (cornerSmoothing() != nullptr) {
    _bb.writeVarUint(17);
    _bb.writeVarFloat(_data_cornerSmoothing);
  }
  if (opacity() != nullptr) {
    _bb.writeVarUint(18);
    _bb.writeVarFloat(_data_opacity);
  }
  if (locked() != nullptr) {
    _bb.writeVarUint(19);
    _bb.writeByte(_data_locked);
  }
  if (effects() != nullptr) {
    _bb.writeVarUint(20);
    _bb.writeVarUint(_data_effects.size());
    for (Effect &_it : _data_effects) if (!_it.encode(_bb)) return false;
  }
  if (fillGeometry() != nullptr) {
    _bb.writeVarUint(21);
    _bb.writeVarUint(_data_fillGeometry.size());
    for (Path &_it : _data_fillGeometry) if (!_it.encode(_bb)) return false;
  }
  if (fillPaints() != nullptr) {
    _bb.writeVarUint(22);
    _bb.writeVarUint(_data_fillPaints.size());
    for (Paint &_it : _data_fillPaints) if (!_it.encode(_bb)) return false;
  }
  if (dashPattern() != nullptr) {
    _bb.writeVarUint(23);
    _bb.writeVarUint(_data_dashPattern.size());
    for (float &_it : _data_dashPattern) _bb.writeVarFloat(_it);
  }
  if (stackCounterAlign() != nullptr) {
    _bb.writeVarUint(24);
    _bb.writeVarUint(static_cast<uint32_t>(_data_stackCounterAlign));
  }
  if (stackCounterSizing() != nullptr) {
    _bb.writeVarUint(25);
    _bb.writeVarUint(static_cast<uint32_t>(_data_stackCounterSizing));
  }
  if (stackHeight() != nullptr) {
    _bb.writeVarUint(26);
    _bb.writeVarUint(static_cast<uint32_t>(_data_stackHeight));
  }
  if (stackHorizontalPadding() != nullptr) {
    _bb.writeVarUint(27);
    _bb.writeVarFloat(_data_stackHorizontalPadding);
  }
  if (stackJustify() != nullptr) {
    _bb.writeVarUint(28);
    _bb.writeVarUint(static_cast<uint32_t>(_data_stackJustify));
  }
  if (stackMode() != nullptr) {
    _bb.writeVarUint(29);
    _bb.writeVarUint(static_cast<uint32_t>(_data_stackMode));
  }
  if (stackPadding() != nullptr) {
    _bb.writeVarUint(30);
    _bb.writeVarFloat(_data_stackPadding);
  }
  if (stackSpacing() != nullptr) {
    _bb.writeVarUint(31);
    _bb.writeVarFloat(_data_stackSpacing);
  }
  if (stackVerticalPadding() != nullptr) {
    _bb.writeVarUint(32);
    _bb.writeVarFloat(_data_stackVerticalPadding);
  }
  if (stackWidth() != nullptr) {
    _bb.writeVarUint(33);
    _bb.writeVarUint(static_cast<uint32_t>(_data_stackWidth));
  }
  if (strokeAlign() != nullptr) {
    _bb.writeVarUint(34);
    _bb.writeVarUint(static_cast<uint32_t>(_data_strokeAlign));
  }
  if (strokeCap() != nullptr) {
    _bb.writeVarUint(35);
    _bb.writeVarUint(static_cast<uint32_t>(_data_strokeCap));
  }
  if (strokeGeometry() != nullptr) {
    _bb.writeVarUint(36);
    _bb.writeVarUint(_data_strokeGeometry.size());
    for (Path &_it : _data_strokeGeometry) if (!_it.encode(_bb)) return false;
  }
  if (strokeJoin() != nullptr) {
    _bb.writeVarUint(37);
    _bb.writeVarUint(static_cast<uint32_t>(_data_strokeJoin));
  }
  if (strokePaints() != nullptr) {
    _bb.writeVarUint(38);
    _bb.writeVarUint(_data_strokePaints.size());
    for (Paint &_it : _data_strokePaints) if (!_it.encode(_bb)) return false;
  }
  if (strokeWeight() != nullptr) {
    _bb.writeVarUint(39);
    _bb.writeVarFloat(_data_strokeWeight);
  }
  if (styleDescription() != nullptr) {
    _bb.writeVarUint(40);
    _bb.writeString(_data_styleDescription.c_str());
  }
  if (styleID() != nullptr) {
    _bb.writeVarUint(41);
    _bb.writeVarInt(_data_styleID);
  }
  if (styleType() != nullptr) {
    _bb.writeVarUint(42);
    _bb.writeVarUint(static_cast<uint32_t>(_data_styleType));
  }
  if (symbolData() != nullptr) {
    _bb.writeVarUint(43);
    if (!_data_symbolData->encode(_bb)) return false;
  }
  if (symbolDescription() != nullptr) {
    _bb.writeVarUint(44);
    _bb.writeString(_data_symbolDescription.c_str());
  }
  if (layoutGrids() != nullptr) {
    _bb.writeVarUint(45);
    _bb.writeVarUint(_data_layoutGrids.size());
    for (LayoutGrid &_it : _data_layoutGrids) if (!_it.encode(_bb)) return false;
  }
  if (mask() != nullptr) {
    _bb.writeVarUint(46);
    _bb.writeByte(_data_mask);
  }
  if (maskIsOutline() != nullptr) {
    _bb.writeVarUint(47);
    _bb.writeByte(_data_maskIsOutline);
  }
  if (starInnerScale() != nullptr) {
    _bb.writeVarUint(48);
    _bb.writeVarFloat(_data_starInnerScale);
  }
  if (miterLimit() != nullptr) {
    _bb.writeVarUint(49);
    _bb.writeVarFloat(_data_miterLimit);
  }
  if (backgroundColor() != nullptr) {
    _bb.writeVarUint(50);
    if (!_data_backgroundColor->encode(_bb)) return false;
  }
  if (backgroundEnabled() != nullptr) {
    _bb.writeVarUint(51);
    _bb.writeByte(_data_backgroundEnabled);
  }
  if (backgroundOpacity() != nullptr) {
    _bb.writeVarUint(52);
    _bb.writeVarFloat(_data_backgroundOpacity);
  }
  if (backgroundPaints() != nullptr) {
    _bb.writeVarUint(53);
    _bb.writeVarUint(_data_backgroundPaints.size());
    for (Paint &_it : _data_backgroundPaints) if (!_it.encode(_bb)) return false;
  }
  if (exportBackgroundDisabled() != nullptr) {
    _bb.writeVarUint(54);
    _bb.writeByte(_data_exportBackgroundDisabled);
  }
  if (exportContentsOnly() != nullptr) {
    _bb.writeVarUint(55);
    _bb.writeByte(_data_exportContentsOnly);
  }
  if (exportSettings() != nullptr) {
    _bb.writeVarUint(56);
    _bb.writeVarUint(_data_exportSettings.size());
    for (ExportSettings &_it : _data_exportSettings) if (!_it.encode(_bb)) return false;
  }
  if (exportTextAsSVGText() != nullptr) {
    _bb.writeVarUint(57);
    _bb.writeByte(_data_exportTextAsSVGText);
  }
  if (fontName() != nullptr) {
    _bb.writeVarUint(58);
    if (!_data_fontName->encode(_bb)) return false;
  }
  if (fontSize() != nullptr) {
    _bb.writeVarUint(59);
    _bb.writeVarFloat(_data_fontSize);
  }
  if (fontVersion() != nullptr) {
    _bb.writeVarUint(60);
    _bb.writeString(_data_fontVersion.c_str());
  }
  if (paragraphIndent() != nullptr) {
    _bb.writeVarUint(61);
    _bb.writeVarFloat(_data_paragraphIndent);
  }
  if (paragraphSpacing() != nullptr) {
    _bb.writeVarUint(62);
    _bb.writeVarFloat(_data_paragraphSpacing);
  }
  if (textAlignHorizontal() != nullptr) {
    _bb.writeVarUint(63);
    _bb.writeVarUint(static_cast<uint32_t>(_data_textAlignHorizontal));
  }
  if (textAlignVertical() != nullptr) {
    _bb.writeVarUint(64);
    _bb.writeVarUint(static_cast<uint32_t>(_data_textAlignVertical));
  }
  if (textAutoResize() != nullptr) {
    _bb.writeVarUint(65);
    _bb.writeVarUint(static_cast<uint32_t>(_data_textAutoResize));
  }
  if (textCase() != nullptr) {
    _bb.writeVarUint(66);
    _bb.writeVarUint(static_cast<uint32_t>(_data_textCase));
  }
  if (textData() != nullptr) {
    _bb.writeVarUint(67);
    if (!_data_textData->encode(_bb)) return false;
  }
  if (textDecoration() != nullptr) {
    _bb.writeVarUint(68);
    _bb.writeVarUint(static_cast<uint32_t>(_data_textDecoration));
  }
  if (textTracking() != nullptr) {
    _bb.writeVarUint(69);
    _bb.writeVarFloat(_data_textTracking);
  }
  if (textUserLayoutVersion() != nullptr) {
    _bb.writeVarUint(70);
    _bb.writeVarInt(_data_textUserLayoutVersion);
  }
  if (letterSpacing() != nullptr) {
    _bb.writeVarUint(71);
    if (!_data_letterSpacing->encode(_bb)) return false;
  }
  if (lineHeight() != nullptr) {
    _bb.writeVarUint(72);
    if (!_data_lineHeight->encode(_bb)) return false;
  }
  if (horizontalConstraint() != nullptr) {
    _bb.writeVarUint(73);
    _bb.writeVarUint(static_cast<uint32_t>(_data_horizontalConstraint));
  }
  if (verticalConstraint() != nullptr) {
    _bb.writeVarUint(74);
    _bb.writeVarUint(static_cast<uint32_t>(_data_verticalConstraint));
  }
  if (derivedSymbolData() != nullptr) {
    _bb.writeVarUint(75);
    _bb.writeVarUint(_data_derivedSymbolData.size());
    for (PixsoNode &_it : _data_derivedSymbolData) if (!_it.encode(_bb)) return false;
  }
  if (derivedSymbolDataLayoutVersion() != nullptr) {
    _bb.writeVarUint(76);
    _bb.writeVarInt(_data_derivedSymbolDataLayoutVersion);
  }
  if (componentKey() != nullptr) {
    _bb.writeVarUint(77);
    _bb.writeString(_data_componentKey.c_str());
  }
  if (inheritEffectStyleID() != nullptr) {
    _bb.writeVarUint(78);
    if (!_data_inheritEffectStyleID->encode(_bb)) return false;
  }
  if (inheritExportStyleID() != nullptr) {
    _bb.writeVarUint(79);
    if (!_data_inheritExportStyleID->encode(_bb)) return false;
  }
  if (inheritFillStyleID() != nullptr) {
    _bb.writeVarUint(80);
    if (!_data_inheritFillStyleID->encode(_bb)) return false;
  }
  if (inheritFillStyleIDForBackground() != nullptr) {
    _bb.writeVarUint(81);
    if (!_data_inheritFillStyleIDForBackground->encode(_bb)) return false;
  }
  if (inheritFillStyleIDForStroke() != nullptr) {
    _bb.writeVarUint(82);
    if (!_data_inheritFillStyleIDForStroke->encode(_bb)) return false;
  }
  if (inheritGridStyleID() != nullptr) {
    _bb.writeVarUint(83);
    if (!_data_inheritGridStyleID->encode(_bb)) return false;
  }
  if (inheritStrokeStyleID() != nullptr) {
    _bb.writeVarUint(84);
    if (!_data_inheritStrokeStyleID->encode(_bb)) return false;
  }
  if (inheritTextStyleID() != nullptr) {
    _bb.writeVarUint(85);
    if (!_data_inheritTextStyleID->encode(_bb)) return false;
  }
  if (interactionDuration() != nullptr) {
    _bb.writeVarUint(86);
    _bb.writeVarFloat(_data_interactionDuration);
  }
  if (interactionMaintained() != nullptr) {
    _bb.writeVarUint(87);
    _bb.writeByte(_data_interactionMaintained);
  }
  if (overriddenSymbolID() != nullptr) {
    _bb.writeVarUint(88);
    if (!_data_overriddenSymbolID->encode(_bb)) return false;
  }
  if (overrideKey() != nullptr) {
    _bb.writeVarUint(89);
    if (!_data_overrideKey->encode(_bb)) return false;
  }
  if (keyTrigger() != nullptr) {
    _bb.writeVarUint(90);
    if (!_data_keyTrigger->encode(_bb)) return false;
  }
  if (navigationType() != nullptr) {
    _bb.writeVarUint(91);
    _bb.writeVarUint(static_cast<uint32_t>(_data_navigationType));
  }
  if (interactionType() != nullptr) {
    _bb.writeVarUint(92);
    _bb.writeVarUint(static_cast<uint32_t>(_data_interactionType));
  }
  if (connectionType() != nullptr) {
    _bb.writeVarUint(93);
    _bb.writeVarUint(static_cast<uint32_t>(_data_connectionType));
  }
  if (connectionURL() != nullptr) {
    _bb.writeVarUint(94);
    _bb.writeString(_data_connectionURL.c_str());
  }
  if (easingType() != nullptr) {
    _bb.writeVarUint(95);
    _bb.writeVarUint(static_cast<uint32_t>(_data_easingType));
  }
  if (proportionsConstrained() != nullptr) {
    _bb.writeVarUint(96);
    _bb.writeByte(_data_proportionsConstrained);
  }
  if (prototypeBackgroundColor() != nullptr) {
    _bb.writeVarUint(97);
    if (!_data_prototypeBackgroundColor->encode(_bb)) return false;
  }
  if (prototypeDevice() != nullptr) {
    _bb.writeVarUint(98);
    if (!_data_prototypeDevice->encode(_bb)) return false;
  }
  if (prototypeInteractions() != nullptr) {
    _bb.writeVarUint(99);
    _bb.writeVarUint(_data_prototypeInteractions.size());
    for (PrototypeInteraction &_it : _data_prototypeInteractions) if (!_it.encode(_bb)) return false;
  }
  if (prototypeStartNodeID() != nullptr) {
    _bb.writeVarUint(100);
    if (!_data_prototypeStartNodeID->encode(_bb)) return false;
  }
  if (overlayBackgroundAppearance() != nullptr) {
    _bb.writeVarUint(101);
    if (!_data_overlayBackgroundAppearance->encode(_bb)) return false;
  }
  if (overlayBackgroundInteraction() != nullptr) {
    _bb.writeVarUint(102);
    _bb.writeVarUint(static_cast<uint32_t>(_data_overlayBackgroundInteraction));
  }
  if (overlayPositionType() != nullptr) {
    _bb.writeVarUint(103);
    _bb.writeVarUint(static_cast<uint32_t>(_data_overlayPositionType));
  }
  if (overlayRelativePosition() != nullptr) {
    _bb.writeVarUint(104);
    if (!_data_overlayRelativePosition->encode(_bb)) return false;
  }
  if (transitionDuration() != nullptr) {
    _bb.writeVarUint(105);
    _bb.writeVarFloat(_data_transitionDuration);
  }
  if (transitionNodeID() != nullptr) {
    _bb.writeVarUint(106);
    if (!_data_transitionNodeID->encode(_bb)) return false;
  }
  if (transitionPreserveScroll() != nullptr) {
    _bb.writeVarUint(107);
    _bb.writeByte(_data_transitionPreserveScroll);
  }
  if (transitionShouldSmartAnimate() != nullptr) {
    _bb.writeVarUint(108);
    _bb.writeByte(_data_transitionShouldSmartAnimate);
  }
  if (transitionTimeout() != nullptr) {
    _bb.writeVarUint(109);
    _bb.writeVarFloat(_data_transitionTimeout);
  }
  if (transitionType() != nullptr) {
    _bb.writeVarUint(110);
    _bb.writeVarUint(static_cast<uint32_t>(_data_transitionType));
  }
  if (scrollBehavior() != nullptr) {
    _bb.writeVarUint(111);
    _bb.writeVarUint(static_cast<uint32_t>(_data_scrollBehavior));
  }
  if (scrollDirection() != nullptr) {
    _bb.writeVarUint(112);
    _bb.writeVarUint(static_cast<uint32_t>(_data_scrollDirection));
  }
  if (rectangleBottomLeftCornerRadius() != nullptr) {
    _bb.writeVarUint(113);
    _bb.writeVarFloat(_data_rectangleBottomLeftCornerRadius);
  }
  if (rectangleBottomRightCornerRadius() != nullptr) {
    _bb.writeVarUint(114);
    _bb.writeVarFloat(_data_rectangleBottomRightCornerRadius);
  }
  if (rectangleCornerRadiiIndependent() != nullptr) {
    _bb.writeVarUint(115);
    _bb.writeByte(_data_rectangleCornerRadiiIndependent);
  }
  if (rectangleCornerToolIndependent() != nullptr) {
    _bb.writeVarUint(116);
    _bb.writeByte(_data_rectangleCornerToolIndependent);
  }
  if (rectangleTopLeftCornerRadius() != nullptr) {
    _bb.writeVarUint(117);
    _bb.writeVarFloat(_data_rectangleTopLeftCornerRadius);
  }
  if (rectangleTopRightCornerRadius() != nullptr) {
    _bb.writeVarUint(118);
    _bb.writeVarFloat(_data_rectangleTopRightCornerRadius);
  }
  if (frameMaskDisabled() != nullptr) {
    _bb.writeVarUint(119);
    _bb.writeByte(_data_frameMaskDisabled);
  }
  if (hyperlink() != nullptr) {
    _bb.writeVarUint(120);
    if (!_data_hyperlink->encode(_bb)) return false;
  }
  if (sharedStyleMasterData() != nullptr) {
    _bb.writeVarUint(121);
    if (!_data_sharedStyleMasterData->encode(_bb)) return false;
  }
  if (sharedStyleReference() != nullptr) {
    _bb.writeVarUint(122);
    if (!_data_sharedStyleReference->encode(_bb)) return false;
  }
  if (autoRename() != nullptr) {
    _bb.writeVarUint(123);
    _bb.writeByte(_data_autoRename);
  }
  if (handleMirroring() != nullptr) {
    _bb.writeVarUint(124);
    _bb.writeVarUint(static_cast<uint32_t>(_data_handleMirroring));
  }
  if (internalOnly() != nullptr) {
    _bb.writeVarUint(125);
    _bb.writeByte(_data_internalOnly);
  }
  if (isSoftDeletedStyle() != nullptr) {
    _bb.writeVarUint(126);
    _bb.writeByte(_data_isSoftDeletedStyle);
  }
  if (isNonUpdateable() != nullptr) {
    _bb.writeVarUint(127);
    _bb.writeByte(_data_isNonUpdateable);
  }
  if (isPublishable() != nullptr) {
    _bb.writeVarUint(128);
    _bb.writeByte(_data_isPublishable);
  }
  if (publishFile() != nullptr) {
    _bb.writeVarUint(129);
    _bb.writeString(_data_publishFile.c_str());
  }
  if (publishID() != nullptr) {
    _bb.writeVarUint(130);
    if (!_data_publishID->encode(_bb)) return false;
  }
  if (publishedVersion() != nullptr) {
    _bb.writeVarUint(131);
    _bb.writeString(_data_publishedVersion.c_str());
  }
  if (isSymbolPublishable() != nullptr) {
    _bb.writeVarUint(132);
    _bb.writeByte(_data_isSymbolPublishable);
  }
  if (sharedSymbolVersion() != nullptr) {
    _bb.writeVarUint(133);
    _bb.writeString(_data_sharedSymbolVersion.c_str());
  }
  if (ancestorPathBeforeDeletion() != nullptr) {
    _bb.writeVarUint(134);
    _bb.writeVarUint(_data_ancestorPathBeforeDeletion.size());
    for (GUID &_it : _data_ancestorPathBeforeDeletion) if (!_it.encode(_bb)) return false;
  }
  if (guides() != nullptr) {
    _bb.writeVarUint(135);
    _bb.writeVarUint(_data_guides.size());
    for (Guide &_it : _data_guides) if (!_it.encode(_bb)) return false;
  }
  if (stateGroupPropertyValueOrders() != nullptr) {
    _bb.writeVarUint(136);
    _bb.writeVarUint(_data_stateGroupPropertyValueOrders.size());
    for (PropValueData &_it : _data_stateGroupPropertyValueOrders) if (!_it.encode(_bb)) return false;
  }
  if (isStateGroup() != nullptr) {
    _bb.writeVarUint(137);
    _bb.writeByte(_data_isStateGroup);
  }
  if (stackPaddingRight() != nullptr) {
    _bb.writeVarUint(138);
    _bb.writeVarFloat(_data_stackPaddingRight);
  }
  if (stackPaddingLeft() != nullptr) {
    _bb.writeVarUint(139);
    _bb.writeVarFloat(_data_stackPaddingLeft);
  }
  if (stackPaddingTop() != nullptr) {
    _bb.writeVarUint(140);
    _bb.writeVarFloat(_data_stackPaddingTop);
  }
  if (stackPaddingBottom() != nullptr) {
    _bb.writeVarUint(141);
    _bb.writeVarFloat(_data_stackPaddingBottom);
  }
  if (stackPrimarySizing() != nullptr) {
    _bb.writeVarUint(142);
    _bb.writeVarUint(static_cast<uint32_t>(_data_stackPrimarySizing));
  }
  if (stackChildPrimarySizing() != nullptr) {
    _bb.writeVarUint(143);
    _bb.writeVarUint(static_cast<uint32_t>(_data_stackChildPrimarySizing));
  }
  if (stackChildCounterSizing() != nullptr) {
    _bb.writeVarUint(144);
    _bb.writeVarUint(static_cast<uint32_t>(_data_stackChildCounterSizing));
  }
  if (stackPrimaryAlignItems() != nullptr) {
    _bb.writeVarUint(145);
    _bb.writeVarUint(static_cast<uint32_t>(_data_stackPrimaryAlignItems));
  }
  if (stackCounterAlignItems() != nullptr) {
    _bb.writeVarUint(146);
    _bb.writeVarUint(static_cast<uint32_t>(_data_stackCounterAlignItems));
  }
  if (prototypeStartPt() != nullptr) {
    _bb.writeVarUint(147);
    if (!_data_prototypeStartPt->encode(_bb)) return false;
  }
  if (dashCap() != nullptr) {
    _bb.writeVarUint(148);
    _bb.writeVarUint(static_cast<uint32_t>(_data_dashCap));
  }
  if (connectlineInfo() != nullptr) {
    _bb.writeVarUint(149);
    if (!_data_connectlineInfo->encode(_bb)) return false;
  }
  if (objSnapConnline() != nullptr) {
    _bb.writeVarUint(150);
    _bb.writeVarUint(_data_objSnapConnline.size());
    for (ObjSnapConnline &_it : _data_objSnapConnline) if (!_it.encode(_bb)) return false;
  }
  if (connlineTextInfos() != nullptr) {
    _bb.writeVarUint(151);
    _bb.writeVarUint(_data_connlineTextInfos.size());
    for (ConnlineTextInfo &_it : _data_connlineTextInfos) if (!_it.encode(_bb)) return false;
  }
  if (vectorPaints() != nullptr) {
    _bb.writeVarUint(152);
    _bb.writeVarUint(_data_vectorPaints.size());
    for (VectorPaint &_it : _data_vectorPaints) if (!_it.encode(_bb)) return false;
  }
  if (vectorStyles() != nullptr) {
    _bb.writeVarUint(153);
    _bb.writeVarUint(_data_vectorStyles.size());
    for (VectorStyle &_it : _data_vectorStyles) if (!_it.encode(_bb)) return false;
  }
  if (borderTopWeight() != nullptr) {
    _bb.writeVarUint(154);
    _bb.writeVarFloat(_data_borderTopWeight);
  }
  if (borderBottomWeight() != nullptr) {
    _bb.writeVarUint(155);
    _bb.writeVarFloat(_data_borderBottomWeight);
  }
  if (borderLeftWeight() != nullptr) {
    _bb.writeVarUint(156);
    _bb.writeVarFloat(_data_borderLeftWeight);
  }
  if (borderRightWeight() != nullptr) {
    _bb.writeVarUint(157);
    _bb.writeVarFloat(_data_borderRightWeight);
  }
  if (borderStrokeWeightsIndependent() != nullptr) {
    _bb.writeVarUint(158);
    _bb.writeByte(_data_borderStrokeWeightsIndependent);
  }
  if (pluginData() != nullptr) {
    _bb.writeVarUint(159);
    _bb.writeVarUint(_data_pluginData.size());
    for (PluginData &_it : _data_pluginData) if (!_it.encode(_bb)) return false;
  }
  if (showInSlice() != nullptr) {
    _bb.writeVarUint(160);
    _bb.writeByte(_data_showInSlice);
  }
  if (exportImageQuality() != nullptr) {
    _bb.writeVarUint(161);
    _bb.writeVarUint(static_cast<uint32_t>(_data_exportImageQuality));
  }
  if (strokePaddingPath() != nullptr) {
    _bb.writeVarUint(162);
    _bb.writeVarUint(_data_strokePaddingPath.size());
    for (Path &_it : _data_strokePaddingPath) if (!_it.encode(_bb)) return false;
  }
  if (autoLayoutAbsolutePos() != nullptr) {
    _bb.writeVarUint(163);
    _bb.writeByte(_data_autoLayoutAbsolutePos);
  }
  if (autoLayoutItemReverseDraw() != nullptr) {
    _bb.writeVarUint(164);
    _bb.writeByte(_data_autoLayoutItemReverseDraw);
  }
  if (pluginRelaunchData() != nullptr) {
    _bb.writeVarUint(165);
    _bb.writeVarUint(_data_pluginRelaunchData.size());
    for (PluginRelaunchData &_it : _data_pluginRelaunchData) if (!_it.encode(_bb)) return false;
  }
  if (autoLayoutIncludeBorders() != nullptr) {
    _bb.writeVarUint(166);
    _bb.writeByte(_data_autoLayoutIncludeBorders);
  }
  if (prodMode() != nullptr) {
    _bb.writeVarUint(167);
    if (!_data_prodMode->encode(_bb)) return false;
  }
  if (exportCutPix() != nullptr) {
    _bb.writeVarUint(168);
    _bb.writeByte(_data_exportCutPix);
  }
  if (exportKeepNameGroup() != nullptr) {
    _bb.writeVarUint(169);
    _bb.writeByte(_data_exportKeepNameGroup);
  }
  if (textTruncation() != nullptr) {
    _bb.writeVarUint(170);
    _bb.writeVarUint(static_cast<uint32_t>(_data_textTruncation));
  }
  if (maskType() != nullptr) {
    _bb.writeVarUint(171);
    _bb.writeVarUint(static_cast<uint32_t>(_data_maskType));
  }
  if (leadingTrim() != nullptr) {
    _bb.writeVarUint(172);
    _bb.writeVarUint(static_cast<uint32_t>(_data_leadingTrim));
  }
  if (hangingPunctuation() != nullptr) {
    _bb.writeVarUint(173);
    _bb.writeByte(_data_hangingPunctuation);
  }
  if (hangingList() != nullptr) {
    _bb.writeVarUint(174);
    _bb.writeByte(_data_hangingList);
  }
  if (fontVariantNumericFigure() != nullptr) {
    _bb.writeVarUint(175);
    _bb.writeVarUint(static_cast<uint32_t>(_data_fontVariantNumericFigure));
  }
  if (fontVariantNumericSpacing() != nullptr) {
    _bb.writeVarUint(176);
    _bb.writeVarUint(static_cast<uint32_t>(_data_fontVariantNumericSpacing));
  }
  if (fontVariantNumericFraction() != nullptr) {
    _bb.writeVarUint(177);
    _bb.writeVarUint(static_cast<uint32_t>(_data_fontVariantNumericFraction));
  }
  if (fontVariantPosition() != nullptr) {
    _bb.writeVarUint(178);
    _bb.writeVarUint(static_cast<uint32_t>(_data_fontVariantPosition));
  }
  if (toggledOnOTFeatures() != nullptr) {
    _bb.writeVarUint(179);
    _bb.writeVarUint(_data_toggledOnOTFeatures.size());
    for (OpenTypeFeature &_it : _data_toggledOnOTFeatures) _bb.writeVarUint(static_cast<uint32_t>(_it));
  }
  if (toggledOffOTFeatures() != nullptr) {
    _bb.writeVarUint(180);
    _bb.writeVarUint(_data_toggledOffOTFeatures.size());
    for (OpenTypeFeature &_it : _data_toggledOffOTFeatures) _bb.writeVarUint(static_cast<uint32_t>(_it));
  }
  if (maxLines() != nullptr) {
    _bb.writeVarUint(181);
    _bb.writeVarInt(_data_maxLines);
  }
  if (sectionState() != nullptr) {
    _bb.writeVarUint(182);
    _bb.writeVarUint(static_cast<uint32_t>(_data_sectionState));
  }
  if (editInfo() != nullptr) {
    _bb.writeVarUint(183);
    if (!_data_editInfo->encode(_bb)) return false;
  }
  if (stackCounterSpacing() != nullptr) {
    _bb.writeVarUint(184);
    _bb.writeVarFloat(_data_stackCounterSpacing);
  }
  if (stackCounterAlignContent() != nullptr) {
    _bb.writeVarUint(185);
    _bb.writeVarUint(static_cast<uint32_t>(_data_stackCounterAlignContent));
  }
  if (stackWrap() != nullptr) {
    _bb.writeVarUint(186);
    _bb.writeVarUint(static_cast<uint32_t>(_data_stackWrap));
  }
  if (minSize() != nullptr) {
    _bb.writeVarUint(187);
    if (!_data_minSize->encode(_bb)) return false;
  }
  if (maxSize() != nullptr) {
    _bb.writeVarUint(188);
    if (!_data_maxSize->encode(_bb)) return false;
  }
  if (componentPropDef() != nullptr) {
    _bb.writeVarUint(189);
    _bb.writeVarUint(_data_componentPropDef.size());
    for (ComponentPropDef &_it : _data_componentPropDef) if (!_it.encode(_bb)) return false;
  }
  if (componentPropRef() != nullptr) {
    _bb.writeVarUint(190);
    _bb.writeVarUint(_data_componentPropRef.size());
    for (ComponentPropRef &_it : _data_componentPropRef) if (!_it.encode(_bb)) return false;
  }
  if (componentPropAssignment() != nullptr) {
    _bb.writeVarUint(191);
    _bb.writeVarUint(_data_componentPropAssignment.size());
    for (ComponentPropAssignment &_it : _data_componentPropAssignment) if (!_it.encode(_bb)) return false;
  }
  if (symbolLinks() != nullptr) {
    _bb.writeVarUint(192);
    _bb.writeVarUint(_data_symbolLinks.size());
    for (SymbolLink &_it : _data_symbolLinks) if (!_it.encode(_bb)) return false;
  }
  if (description() != nullptr) {
    _bb.writeVarUint(193);
    _bb.writeString(_data_description.c_str());
  }
  if (exportNameByVariantProp() != nullptr) {
    _bb.writeVarUint(194);
    _bb.writeByte(_data_exportNameByVariantProp);
  }
  if (propsAreBubbled() != nullptr) {
    _bb.writeVarUint(195);
    _bb.writeByte(_data_propsAreBubbled);
  }
  if (showMask() != nullptr) {
    _bb.writeVarUint(196);
    _bb.writeByte(_data_showMask);
  }
  if (componentOverrideHierarchy() != nullptr) {
    _bb.writeVarUint(197);
    _bb.writeByte(_data_componentOverrideHierarchy);
  }
  if (developerRelatedLinks() != nullptr) {
    _bb.writeVarUint(198);
    _bb.writeVarUint(_data_developerRelatedLinks.size());
    for (DeveloperRelatedLink &_it : _data_developerRelatedLinks) if (!_it.encode(_bb)) return false;
  }
  if (fontVariations() != nullptr) {
    _bb.writeVarUint(199);
    _bb.writeVarUint(_data_fontVariations.size());
    for (FontVariation &_it : _data_fontVariations) if (!_it.encode(_bb)) return false;
  }
  if (pathTextInfo() != nullptr) {
    _bb.writeVarUint(200);
    if (!_data_pathTextInfo->encode(_bb)) return false;
  }
  if (detachOpticalSizeFromFontSize() != nullptr) {
    _bb.writeVarUint(201);
    _bb.writeByte(_data_detachOpticalSizeFromFontSize);
  }
  if (radialRepeatData() != nullptr) {
    _bb.writeVarUint(202);
    if (!_data_radialRepeatData->encode(_bb)) return false;
  }
  if (overrideLevel() != nullptr) {
    _bb.writeVarUint(203);
    _bb.writeVarInt(_data_overrideLevel);
  }
  if (variableData() != nullptr) {
    _bb.writeVarUint(204);
    if (!_data_variableData->encode(_bb)) return false;
  }
  if (variableConsumptionMap() != nullptr) {
    _bb.writeVarUint(205);
    if (!_data_variableConsumptionMap->encode(_bb)) return false;
  }
  if (variableModeBySetMap() != nullptr) {
    _bb.writeVarUint(206);
    if (!_data_variableModeBySetMap->encode(_bb)) return false;
  }
  if (variableSetModes() != nullptr) {
    _bb.writeVarUint(207);
    _bb.writeVarUint(_data_variableSetModes.size());
    for (VariableSetMode &_it : _data_variableSetModes) if (!_it.encode(_bb)) return false;
  }
  if (variableSetID() != nullptr) {
    _bb.writeVarUint(208);
    if (!_data_variableSetID->encode(_bb)) return false;
  }
  if (variableResolvedType() != nullptr) {
    _bb.writeVarUint(209);
    _bb.writeVarUint(static_cast<uint32_t>(_data_variableResolvedType));
  }
  if (variableDataValues() != nullptr) {
    _bb.writeVarUint(210);
    if (!_data_variableDataValues->encode(_bb)) return false;
  }
  if (variableTokenName() != nullptr) {
    _bb.writeVarUint(211);
    _bb.writeString(_data_variableTokenName.c_str());
  }
  if (variableScopes() != nullptr) {
    _bb.writeVarUint(212);
    _bb.writeVarUint(_data_variableScopes.size());
    for (VariableScope &_it : _data_variableScopes) _bb.writeVarUint(static_cast<uint32_t>(_it));
  }
  if (codeSyntax() != nullptr) {
    _bb.writeVarUint(213);
    if (!_data_codeSyntax->encode(_bb)) return false;
  }
  if (backingVariableSetId() != nullptr) {
    _bb.writeVarUint(214);
    if (!_data_backingVariableSetId->encode(_bb)) return false;
  }
  if (backingVariableId() != nullptr) {
    _bb.writeVarUint(215);
    if (!_data_backingVariableId->encode(_bb)) return false;
  }
  if (rootVariableKey() != nullptr) {
    _bb.writeVarUint(216);
    _bb.writeString(_data_rootVariableKey.c_str());
  }
  if (userFacingVersion() != nullptr) {
    _bb.writeVarUint(217);
    _bb.writeString(_data_userFacingVersion.c_str());
  }
  if (key() != nullptr) {
    _bb.writeVarUint(218);
    _bb.writeString(_data_key.c_str());
  }
  if (isSoftDeleted() != nullptr) {
    _bb.writeVarUint(219);
    _bb.writeByte(_data_isSoftDeleted);
  }
  if (sortPosition() != nullptr) {
    _bb.writeVarUint(220);
    _bb.writeString(_data_sortPosition.c_str());
  }
  if (sourceLibraryKey() != nullptr) {
    _bb.writeVarUint(221);
    _bb.writeString(_data_sourceLibraryKey.c_str());
  }
  if (deliverInfo() != nullptr) {
    _bb.writeVarUint(222);
    if (!_data_deliverInfo->encode(_bb)) return false;
  }
  if (deformationTransform() != nullptr) {
    _bb.writeVarUint(223);
    if (!_data_deformationTransform->encode(_bb)) return false;
  }
  if (transformModifiers() != nullptr) {
    _bb.writeVarUint(224);
    _bb.writeVarUint(_data_transformModifiers.size());
    for (TransformModifier &_it : _data_transformModifiers) if (!_it.encode(_bb)) return false;
  }
  if (groupIncludeInvisible() != nullptr) {
    _bb.writeVarUint(225);
    _bb.writeByte(_data_groupIncludeInvisible);
  }
  if (variableSymbolID() != nullptr) {
    _bb.writeVarUint(226);
    if (!_data_variableSymbolID->encode(_bb)) return false;
  }
  if (annotations() != nullptr) {
    _bb.writeVarUint(227);
    _bb.writeVarUint(_data_annotations.size());
    for (Annotation &_it : _data_annotations) if (!_it.encode(_bb)) return false;
  }
  if (annotationCategories() != nullptr) {
    _bb.writeVarUint(228);
    if (!_data_annotationCategories->encode(_bb)) return false;
  }
  if (gridRowAnchor() != nullptr) {
    _bb.writeVarUint(229);
    if (!_data_gridRowAnchor->encode(_bb)) return false;
  }
  if (gridColumnAnchor() != nullptr) {
    _bb.writeVarUint(230);
    if (!_data_gridColumnAnchor->encode(_bb)) return false;
  }
  if (gridRowSpan() != nullptr) {
    _bb.writeVarUint(231);
    _bb.writeVarUint(_data_gridRowSpan);
  }
  if (gridColumnSpan() != nullptr) {
    _bb.writeVarUint(232);
    _bb.writeVarUint(_data_gridColumnSpan);
  }
  if (gridChildVerticalAlign() != nullptr) {
    _bb.writeVarUint(233);
    _bb.writeVarUint(static_cast<uint32_t>(_data_gridChildVerticalAlign));
  }
  if (gridChildHorizontalAlign() != nullptr) {
    _bb.writeVarUint(234);
    _bb.writeVarUint(static_cast<uint32_t>(_data_gridChildHorizontalAlign));
  }
  if (gridRows() != nullptr) {
    _bb.writeVarUint(235);
    _bb.writeVarUint(_data_gridRows.size());
    for (GUID &_it : _data_gridRows) if (!_it.encode(_bb)) return false;
  }
  if (gridColumns() != nullptr) {
    _bb.writeVarUint(236);
    _bb.writeVarUint(_data_gridColumns.size());
    for (GUID &_it : _data_gridColumns) if (!_it.encode(_bb)) return false;
  }
  if (gridRowsSizing() != nullptr) {
    _bb.writeVarUint(237);
    _bb.writeVarUint(_data_gridRowsSizing.size());
    for (GridTrackSizing &_it : _data_gridRowsSizing) if (!_it.encode(_bb)) return false;
  }
  if (gridColumnsSizing() != nullptr) {
    _bb.writeVarUint(238);
    _bb.writeVarUint(_data_gridColumnsSizing.size());
    for (GridTrackSizing &_it : _data_gridColumnsSizing) if (!_it.encode(_bb)) return false;
  }
  if (autoCornerRadius() != nullptr) {
    _bb.writeVarUint(239);
    _bb.writeByte(_data_autoCornerRadius);
  }
  if (targetAspectRatio() != nullptr) {
    _bb.writeVarUint(240);
    if (!_data_targetAspectRatio->encode(_bb)) return false;
  }
  if (aliasName() != nullptr) {
    _bb.writeVarUint(241);
    _bb.writeString(_data_aliasName.c_str());
  }
  if (simplifyInstancePanels() != nullptr) {
    _bb.writeVarUint(242);
    _bb.writeByte(_data_simplifyInstancePanels);
  }
  if (rotationOrigin() != nullptr) {
    _bb.writeVarUint(243);
    if (!_data_rotationOrigin->encode(_bb)) return false;
  }
  if (videoPlayback() != nullptr) {
    _bb.writeVarUint(244);
    if (!_data_videoPlayback->encode(_bb)) return false;
  }
  if (variableWidths() != nullptr) {
    _bb.writeVarUint(245);
    _bb.writeVarUint(_data_variableWidths.size());
    for (VariableWidthPoint &_it : _data_variableWidths) if (!_it.encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool PixsoNode::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_guid = _pool.allocate<GUID>();
        if (!_data_guid->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        _data_guidPath = _pool.allocate<GUIDPath>();
        if (!_data_guidPath->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 3: {
        _data_parentIndex = _pool.allocate<ParentIndex>();
        if (!_data_parentIndex->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 4: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_phase))) return false;
        set_phase(_data_phase);
        break;
      }
      case 5: {
        _data_transform = _pool.allocate<Matrix>();
        if (!_data_transform->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 6: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_type))) return false;
        set_type(_data_type);
        break;
      }
      case 7: {
        if (!_bb.readString(_data_name, _pool)) return false;
        set_name(_data_name);
        break;
      }
      case 8: {
        _data_vectorData = _pool.allocate<VectorData>();
        if (!_data_vectorData->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 9: {
        if (!_bb.readString(_data_version, _pool)) return false;
        set_version(_data_version);
        break;
      }
      case 10: {
        if (!_bb.readByte(_data_visible)) return false;
        set_visible(_data_visible);
        break;
      }
      case 11: {
        if (!_bb.readVarInt(_data_count)) return false;
        set_count(_data_count);
        break;
      }
      case 12: {
        _data_size = _pool.allocate<Vector>();
        if (!_data_size->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 13: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_booleanOperation))) return false;
        set_booleanOperation(_data_booleanOperation);
        break;
      }
      case 14: {
        _data_arcData = _pool.allocate<ArcData>();
        if (!_data_arcData->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 15: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_blendMode))) return false;
        set_blendMode(_data_blendMode);
        break;
      }
      case 16: {
        if (!_bb.readVarFloat(_data_cornerRadius)) return false;
        set_cornerRadius(_data_cornerRadius);
        break;
      }
      case 17: {
        if (!_bb.readVarFloat(_data_cornerSmoothing)) return false;
        set_cornerSmoothing(_data_cornerSmoothing);
        break;
      }
      case 18: {
        if (!_bb.readVarFloat(_data_opacity)) return false;
        set_opacity(_data_opacity);
        break;
      }
      case 19: {
        if (!_bb.readByte(_data_locked)) return false;
        set_locked(_data_locked);
        break;
      }
      case 20: {
        if (!_bb.readVarUint(_count)) return false;
        for (Effect &_it : set_effects(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 21: {
        if (!_bb.readVarUint(_count)) return false;
        for (Path &_it : set_fillGeometry(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 22: {
        if (!_bb.readVarUint(_count)) return false;
        for (Paint &_it : set_fillPaints(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 23: {
        if (!_bb.readVarUint(_count)) return false;
        for (float &_it : set_dashPattern(_pool, _count)) if (!_bb.readVarFloat(_it)) return false;
        break;
      }
      case 24: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_stackCounterAlign))) return false;
        set_stackCounterAlign(_data_stackCounterAlign);
        break;
      }
      case 25: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_stackCounterSizing))) return false;
        set_stackCounterSizing(_data_stackCounterSizing);
        break;
      }
      case 26: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_stackHeight))) return false;
        set_stackHeight(_data_stackHeight);
        break;
      }
      case 27: {
        if (!_bb.readVarFloat(_data_stackHorizontalPadding)) return false;
        set_stackHorizontalPadding(_data_stackHorizontalPadding);
        break;
      }
      case 28: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_stackJustify))) return false;
        set_stackJustify(_data_stackJustify);
        break;
      }
      case 29: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_stackMode))) return false;
        set_stackMode(_data_stackMode);
        break;
      }
      case 30: {
        if (!_bb.readVarFloat(_data_stackPadding)) return false;
        set_stackPadding(_data_stackPadding);
        break;
      }
      case 31: {
        if (!_bb.readVarFloat(_data_stackSpacing)) return false;
        set_stackSpacing(_data_stackSpacing);
        break;
      }
      case 32: {
        if (!_bb.readVarFloat(_data_stackVerticalPadding)) return false;
        set_stackVerticalPadding(_data_stackVerticalPadding);
        break;
      }
      case 33: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_stackWidth))) return false;
        set_stackWidth(_data_stackWidth);
        break;
      }
      case 34: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_strokeAlign))) return false;
        set_strokeAlign(_data_strokeAlign);
        break;
      }
      case 35: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_strokeCap))) return false;
        set_strokeCap(_data_strokeCap);
        break;
      }
      case 36: {
        if (!_bb.readVarUint(_count)) return false;
        for (Path &_it : set_strokeGeometry(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 37: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_strokeJoin))) return false;
        set_strokeJoin(_data_strokeJoin);
        break;
      }
      case 38: {
        if (!_bb.readVarUint(_count)) return false;
        for (Paint &_it : set_strokePaints(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 39: {
        if (!_bb.readVarFloat(_data_strokeWeight)) return false;
        set_strokeWeight(_data_strokeWeight);
        break;
      }
      case 40: {
        if (!_bb.readString(_data_styleDescription, _pool)) return false;
        set_styleDescription(_data_styleDescription);
        break;
      }
      case 41: {
        if (!_bb.readVarInt(_data_styleID)) return false;
        set_styleID(_data_styleID);
        break;
      }
      case 42: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_styleType))) return false;
        set_styleType(_data_styleType);
        break;
      }
      case 43: {
        _data_symbolData = _pool.allocate<SymbolData>();
        if (!_data_symbolData->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 44: {
        if (!_bb.readString(_data_symbolDescription, _pool)) return false;
        set_symbolDescription(_data_symbolDescription);
        break;
      }
      case 45: {
        if (!_bb.readVarUint(_count)) return false;
        for (LayoutGrid &_it : set_layoutGrids(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 46: {
        if (!_bb.readByte(_data_mask)) return false;
        set_mask(_data_mask);
        break;
      }
      case 47: {
        if (!_bb.readByte(_data_maskIsOutline)) return false;
        set_maskIsOutline(_data_maskIsOutline);
        break;
      }
      case 48: {
        if (!_bb.readVarFloat(_data_starInnerScale)) return false;
        set_starInnerScale(_data_starInnerScale);
        break;
      }
      case 49: {
        if (!_bb.readVarFloat(_data_miterLimit)) return false;
        set_miterLimit(_data_miterLimit);
        break;
      }
      case 50: {
        _data_backgroundColor = _pool.allocate<Color>();
        if (!_data_backgroundColor->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 51: {
        if (!_bb.readByte(_data_backgroundEnabled)) return false;
        set_backgroundEnabled(_data_backgroundEnabled);
        break;
      }
      case 52: {
        if (!_bb.readVarFloat(_data_backgroundOpacity)) return false;
        set_backgroundOpacity(_data_backgroundOpacity);
        break;
      }
      case 53: {
        if (!_bb.readVarUint(_count)) return false;
        for (Paint &_it : set_backgroundPaints(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 54: {
        if (!_bb.readByte(_data_exportBackgroundDisabled)) return false;
        set_exportBackgroundDisabled(_data_exportBackgroundDisabled);
        break;
      }
      case 55: {
        if (!_bb.readByte(_data_exportContentsOnly)) return false;
        set_exportContentsOnly(_data_exportContentsOnly);
        break;
      }
      case 56: {
        if (!_bb.readVarUint(_count)) return false;
        for (ExportSettings &_it : set_exportSettings(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 57: {
        if (!_bb.readByte(_data_exportTextAsSVGText)) return false;
        set_exportTextAsSVGText(_data_exportTextAsSVGText);
        break;
      }
      case 58: {
        _data_fontName = _pool.allocate<FontName>();
        if (!_data_fontName->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 59: {
        if (!_bb.readVarFloat(_data_fontSize)) return false;
        set_fontSize(_data_fontSize);
        break;
      }
      case 60: {
        if (!_bb.readString(_data_fontVersion, _pool)) return false;
        set_fontVersion(_data_fontVersion);
        break;
      }
      case 61: {
        if (!_bb.readVarFloat(_data_paragraphIndent)) return false;
        set_paragraphIndent(_data_paragraphIndent);
        break;
      }
      case 62: {
        if (!_bb.readVarFloat(_data_paragraphSpacing)) return false;
        set_paragraphSpacing(_data_paragraphSpacing);
        break;
      }
      case 63: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_textAlignHorizontal))) return false;
        set_textAlignHorizontal(_data_textAlignHorizontal);
        break;
      }
      case 64: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_textAlignVertical))) return false;
        set_textAlignVertical(_data_textAlignVertical);
        break;
      }
      case 65: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_textAutoResize))) return false;
        set_textAutoResize(_data_textAutoResize);
        break;
      }
      case 66: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_textCase))) return false;
        set_textCase(_data_textCase);
        break;
      }
      case 67: {
        _data_textData = _pool.allocate<TextData>();
        if (!_data_textData->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 68: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_textDecoration))) return false;
        set_textDecoration(_data_textDecoration);
        break;
      }
      case 69: {
        if (!_bb.readVarFloat(_data_textTracking)) return false;
        set_textTracking(_data_textTracking);
        break;
      }
      case 70: {
        if (!_bb.readVarInt(_data_textUserLayoutVersion)) return false;
        set_textUserLayoutVersion(_data_textUserLayoutVersion);
        break;
      }
      case 71: {
        _data_letterSpacing = _pool.allocate<Number>();
        if (!_data_letterSpacing->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 72: {
        _data_lineHeight = _pool.allocate<Number>();
        if (!_data_lineHeight->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 73: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_horizontalConstraint))) return false;
        set_horizontalConstraint(_data_horizontalConstraint);
        break;
      }
      case 74: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_verticalConstraint))) return false;
        set_verticalConstraint(_data_verticalConstraint);
        break;
      }
      case 75: {
        if (!_bb.readVarUint(_count)) return false;
        for (PixsoNode &_it : set_derivedSymbolData(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 76: {
        if (!_bb.readVarInt(_data_derivedSymbolDataLayoutVersion)) return false;
        set_derivedSymbolDataLayoutVersion(_data_derivedSymbolDataLayoutVersion);
        break;
      }
      case 77: {
        if (!_bb.readString(_data_componentKey, _pool)) return false;
        set_componentKey(_data_componentKey);
        break;
      }
      case 78: {
        _data_inheritEffectStyleID = _pool.allocate<GUID>();
        if (!_data_inheritEffectStyleID->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 79: {
        _data_inheritExportStyleID = _pool.allocate<GUID>();
        if (!_data_inheritExportStyleID->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 80: {
        _data_inheritFillStyleID = _pool.allocate<GUID>();
        if (!_data_inheritFillStyleID->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 81: {
        _data_inheritFillStyleIDForBackground = _pool.allocate<GUID>();
        if (!_data_inheritFillStyleIDForBackground->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 82: {
        _data_inheritFillStyleIDForStroke = _pool.allocate<GUID>();
        if (!_data_inheritFillStyleIDForStroke->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 83: {
        _data_inheritGridStyleID = _pool.allocate<GUID>();
        if (!_data_inheritGridStyleID->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 84: {
        _data_inheritStrokeStyleID = _pool.allocate<GUID>();
        if (!_data_inheritStrokeStyleID->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 85: {
        _data_inheritTextStyleID = _pool.allocate<GUID>();
        if (!_data_inheritTextStyleID->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 86: {
        if (!_bb.readVarFloat(_data_interactionDuration)) return false;
        set_interactionDuration(_data_interactionDuration);
        break;
      }
      case 87: {
        if (!_bb.readByte(_data_interactionMaintained)) return false;
        set_interactionMaintained(_data_interactionMaintained);
        break;
      }
      case 88: {
        _data_overriddenSymbolID = _pool.allocate<GUID>();
        if (!_data_overriddenSymbolID->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 89: {
        _data_overrideKey = _pool.allocate<GUID>();
        if (!_data_overrideKey->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 90: {
        _data_keyTrigger = _pool.allocate<KeyTrigger>();
        if (!_data_keyTrigger->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 91: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_navigationType))) return false;
        set_navigationType(_data_navigationType);
        break;
      }
      case 92: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_interactionType))) return false;
        set_interactionType(_data_interactionType);
        break;
      }
      case 93: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_connectionType))) return false;
        set_connectionType(_data_connectionType);
        break;
      }
      case 94: {
        if (!_bb.readString(_data_connectionURL, _pool)) return false;
        set_connectionURL(_data_connectionURL);
        break;
      }
      case 95: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_easingType))) return false;
        set_easingType(_data_easingType);
        break;
      }
      case 96: {
        if (!_bb.readByte(_data_proportionsConstrained)) return false;
        set_proportionsConstrained(_data_proportionsConstrained);
        break;
      }
      case 97: {
        _data_prototypeBackgroundColor = _pool.allocate<Color>();
        if (!_data_prototypeBackgroundColor->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 98: {
        _data_prototypeDevice = _pool.allocate<PrototypeDevice>();
        if (!_data_prototypeDevice->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 99: {
        if (!_bb.readVarUint(_count)) return false;
        for (PrototypeInteraction &_it : set_prototypeInteractions(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 100: {
        _data_prototypeStartNodeID = _pool.allocate<GUID>();
        if (!_data_prototypeStartNodeID->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 101: {
        _data_overlayBackgroundAppearance = _pool.allocate<OverlayBackgroundAppearance>();
        if (!_data_overlayBackgroundAppearance->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 102: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_overlayBackgroundInteraction))) return false;
        set_overlayBackgroundInteraction(_data_overlayBackgroundInteraction);
        break;
      }
      case 103: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_overlayPositionType))) return false;
        set_overlayPositionType(_data_overlayPositionType);
        break;
      }
      case 104: {
        _data_overlayRelativePosition = _pool.allocate<Vector>();
        if (!_data_overlayRelativePosition->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 105: {
        if (!_bb.readVarFloat(_data_transitionDuration)) return false;
        set_transitionDuration(_data_transitionDuration);
        break;
      }
      case 106: {
        _data_transitionNodeID = _pool.allocate<GUID>();
        if (!_data_transitionNodeID->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 107: {
        if (!_bb.readByte(_data_transitionPreserveScroll)) return false;
        set_transitionPreserveScroll(_data_transitionPreserveScroll);
        break;
      }
      case 108: {
        if (!_bb.readByte(_data_transitionShouldSmartAnimate)) return false;
        set_transitionShouldSmartAnimate(_data_transitionShouldSmartAnimate);
        break;
      }
      case 109: {
        if (!_bb.readVarFloat(_data_transitionTimeout)) return false;
        set_transitionTimeout(_data_transitionTimeout);
        break;
      }
      case 110: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_transitionType))) return false;
        set_transitionType(_data_transitionType);
        break;
      }
      case 111: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_scrollBehavior))) return false;
        set_scrollBehavior(_data_scrollBehavior);
        break;
      }
      case 112: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_scrollDirection))) return false;
        set_scrollDirection(_data_scrollDirection);
        break;
      }
      case 113: {
        if (!_bb.readVarFloat(_data_rectangleBottomLeftCornerRadius)) return false;
        set_rectangleBottomLeftCornerRadius(_data_rectangleBottomLeftCornerRadius);
        break;
      }
      case 114: {
        if (!_bb.readVarFloat(_data_rectangleBottomRightCornerRadius)) return false;
        set_rectangleBottomRightCornerRadius(_data_rectangleBottomRightCornerRadius);
        break;
      }
      case 115: {
        if (!_bb.readByte(_data_rectangleCornerRadiiIndependent)) return false;
        set_rectangleCornerRadiiIndependent(_data_rectangleCornerRadiiIndependent);
        break;
      }
      case 116: {
        if (!_bb.readByte(_data_rectangleCornerToolIndependent)) return false;
        set_rectangleCornerToolIndependent(_data_rectangleCornerToolIndependent);
        break;
      }
      case 117: {
        if (!_bb.readVarFloat(_data_rectangleTopLeftCornerRadius)) return false;
        set_rectangleTopLeftCornerRadius(_data_rectangleTopLeftCornerRadius);
        break;
      }
      case 118: {
        if (!_bb.readVarFloat(_data_rectangleTopRightCornerRadius)) return false;
        set_rectangleTopRightCornerRadius(_data_rectangleTopRightCornerRadius);
        break;
      }
      case 119: {
        if (!_bb.readByte(_data_frameMaskDisabled)) return false;
        set_frameMaskDisabled(_data_frameMaskDisabled);
        break;
      }
      case 120: {
        _data_hyperlink = _pool.allocate<Hyperlink>();
        if (!_data_hyperlink->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 121: {
        _data_sharedStyleMasterData = _pool.allocate<SharedStyleMasterData>();
        if (!_data_sharedStyleMasterData->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 122: {
        _data_sharedStyleReference = _pool.allocate<SharedStyleReference>();
        if (!_data_sharedStyleReference->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 123: {
        if (!_bb.readByte(_data_autoRename)) return false;
        set_autoRename(_data_autoRename);
        break;
      }
      case 124: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_handleMirroring))) return false;
        set_handleMirroring(_data_handleMirroring);
        break;
      }
      case 125: {
        if (!_bb.readByte(_data_internalOnly)) return false;
        set_internalOnly(_data_internalOnly);
        break;
      }
      case 126: {
        if (!_bb.readByte(_data_isSoftDeletedStyle)) return false;
        set_isSoftDeletedStyle(_data_isSoftDeletedStyle);
        break;
      }
      case 127: {
        if (!_bb.readByte(_data_isNonUpdateable)) return false;
        set_isNonUpdateable(_data_isNonUpdateable);
        break;
      }
      case 128: {
        if (!_bb.readByte(_data_isPublishable)) return false;
        set_isPublishable(_data_isPublishable);
        break;
      }
      case 129: {
        if (!_bb.readString(_data_publishFile, _pool)) return false;
        set_publishFile(_data_publishFile);
        break;
      }
      case 130: {
        _data_publishID = _pool.allocate<GUID>();
        if (!_data_publishID->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 131: {
        if (!_bb.readString(_data_publishedVersion, _pool)) return false;
        set_publishedVersion(_data_publishedVersion);
        break;
      }
      case 132: {
        if (!_bb.readByte(_data_isSymbolPublishable)) return false;
        set_isSymbolPublishable(_data_isSymbolPublishable);
        break;
      }
      case 133: {
        if (!_bb.readString(_data_sharedSymbolVersion, _pool)) return false;
        set_sharedSymbolVersion(_data_sharedSymbolVersion);
        break;
      }
      case 134: {
        if (!_bb.readVarUint(_count)) return false;
        for (GUID &_it : set_ancestorPathBeforeDeletion(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 135: {
        if (!_bb.readVarUint(_count)) return false;
        for (Guide &_it : set_guides(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 136: {
        if (!_bb.readVarUint(_count)) return false;
        for (PropValueData &_it : set_stateGroupPropertyValueOrders(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 137: {
        if (!_bb.readByte(_data_isStateGroup)) return false;
        set_isStateGroup(_data_isStateGroup);
        break;
      }
      case 138: {
        if (!_bb.readVarFloat(_data_stackPaddingRight)) return false;
        set_stackPaddingRight(_data_stackPaddingRight);
        break;
      }
      case 139: {
        if (!_bb.readVarFloat(_data_stackPaddingLeft)) return false;
        set_stackPaddingLeft(_data_stackPaddingLeft);
        break;
      }
      case 140: {
        if (!_bb.readVarFloat(_data_stackPaddingTop)) return false;
        set_stackPaddingTop(_data_stackPaddingTop);
        break;
      }
      case 141: {
        if (!_bb.readVarFloat(_data_stackPaddingBottom)) return false;
        set_stackPaddingBottom(_data_stackPaddingBottom);
        break;
      }
      case 142: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_stackPrimarySizing))) return false;
        set_stackPrimarySizing(_data_stackPrimarySizing);
        break;
      }
      case 143: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_stackChildPrimarySizing))) return false;
        set_stackChildPrimarySizing(_data_stackChildPrimarySizing);
        break;
      }
      case 144: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_stackChildCounterSizing))) return false;
        set_stackChildCounterSizing(_data_stackChildCounterSizing);
        break;
      }
      case 145: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_stackPrimaryAlignItems))) return false;
        set_stackPrimaryAlignItems(_data_stackPrimaryAlignItems);
        break;
      }
      case 146: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_stackCounterAlignItems))) return false;
        set_stackCounterAlignItems(_data_stackCounterAlignItems);
        break;
      }
      case 147: {
        _data_prototypeStartPt = _pool.allocate<PrototypeStartPoint>();
        if (!_data_prototypeStartPt->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 148: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_dashCap))) return false;
        set_dashCap(_data_dashCap);
        break;
      }
      case 149: {
        _data_connectlineInfo = _pool.allocate<ConnectLineInfo>();
        if (!_data_connectlineInfo->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 150: {
        if (!_bb.readVarUint(_count)) return false;
        for (ObjSnapConnline &_it : set_objSnapConnline(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 151: {
        if (!_bb.readVarUint(_count)) return false;
        for (ConnlineTextInfo &_it : set_connlineTextInfos(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 152: {
        if (!_bb.readVarUint(_count)) return false;
        for (VectorPaint &_it : set_vectorPaints(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 153: {
        if (!_bb.readVarUint(_count)) return false;
        for (VectorStyle &_it : set_vectorStyles(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 154: {
        if (!_bb.readVarFloat(_data_borderTopWeight)) return false;
        set_borderTopWeight(_data_borderTopWeight);
        break;
      }
      case 155: {
        if (!_bb.readVarFloat(_data_borderBottomWeight)) return false;
        set_borderBottomWeight(_data_borderBottomWeight);
        break;
      }
      case 156: {
        if (!_bb.readVarFloat(_data_borderLeftWeight)) return false;
        set_borderLeftWeight(_data_borderLeftWeight);
        break;
      }
      case 157: {
        if (!_bb.readVarFloat(_data_borderRightWeight)) return false;
        set_borderRightWeight(_data_borderRightWeight);
        break;
      }
      case 158: {
        if (!_bb.readByte(_data_borderStrokeWeightsIndependent)) return false;
        set_borderStrokeWeightsIndependent(_data_borderStrokeWeightsIndependent);
        break;
      }
      case 159: {
        if (!_bb.readVarUint(_count)) return false;
        for (PluginData &_it : set_pluginData(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 160: {
        if (!_bb.readByte(_data_showInSlice)) return false;
        set_showInSlice(_data_showInSlice);
        break;
      }
      case 161: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_exportImageQuality))) return false;
        set_exportImageQuality(_data_exportImageQuality);
        break;
      }
      case 162: {
        if (!_bb.readVarUint(_count)) return false;
        for (Path &_it : set_strokePaddingPath(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 163: {
        if (!_bb.readByte(_data_autoLayoutAbsolutePos)) return false;
        set_autoLayoutAbsolutePos(_data_autoLayoutAbsolutePos);
        break;
      }
      case 164: {
        if (!_bb.readByte(_data_autoLayoutItemReverseDraw)) return false;
        set_autoLayoutItemReverseDraw(_data_autoLayoutItemReverseDraw);
        break;
      }
      case 165: {
        if (!_bb.readVarUint(_count)) return false;
        for (PluginRelaunchData &_it : set_pluginRelaunchData(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 166: {
        if (!_bb.readByte(_data_autoLayoutIncludeBorders)) return false;
        set_autoLayoutIncludeBorders(_data_autoLayoutIncludeBorders);
        break;
      }
      case 167: {
        _data_prodMode = _pool.allocate<ProdMode>();
        if (!_data_prodMode->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 168: {
        if (!_bb.readByte(_data_exportCutPix)) return false;
        set_exportCutPix(_data_exportCutPix);
        break;
      }
      case 169: {
        if (!_bb.readByte(_data_exportKeepNameGroup)) return false;
        set_exportKeepNameGroup(_data_exportKeepNameGroup);
        break;
      }
      case 170: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_textTruncation))) return false;
        set_textTruncation(_data_textTruncation);
        break;
      }
      case 171: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_maskType))) return false;
        set_maskType(_data_maskType);
        break;
      }
      case 172: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_leadingTrim))) return false;
        set_leadingTrim(_data_leadingTrim);
        break;
      }
      case 173: {
        if (!_bb.readByte(_data_hangingPunctuation)) return false;
        set_hangingPunctuation(_data_hangingPunctuation);
        break;
      }
      case 174: {
        if (!_bb.readByte(_data_hangingList)) return false;
        set_hangingList(_data_hangingList);
        break;
      }
      case 175: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_fontVariantNumericFigure))) return false;
        set_fontVariantNumericFigure(_data_fontVariantNumericFigure);
        break;
      }
      case 176: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_fontVariantNumericSpacing))) return false;
        set_fontVariantNumericSpacing(_data_fontVariantNumericSpacing);
        break;
      }
      case 177: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_fontVariantNumericFraction))) return false;
        set_fontVariantNumericFraction(_data_fontVariantNumericFraction);
        break;
      }
      case 178: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_fontVariantPosition))) return false;
        set_fontVariantPosition(_data_fontVariantPosition);
        break;
      }
      case 179: {
        if (!_bb.readVarUint(_count)) return false;
        for (OpenTypeFeature &_it : set_toggledOnOTFeatures(_pool, _count)) if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_it))) return false;
        break;
      }
      case 180: {
        if (!_bb.readVarUint(_count)) return false;
        for (OpenTypeFeature &_it : set_toggledOffOTFeatures(_pool, _count)) if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_it))) return false;
        break;
      }
      case 181: {
        if (!_bb.readVarInt(_data_maxLines)) return false;
        set_maxLines(_data_maxLines);
        break;
      }
      case 182: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_sectionState))) return false;
        set_sectionState(_data_sectionState);
        break;
      }
      case 183: {
        _data_editInfo = _pool.allocate<EditInfo>();
        if (!_data_editInfo->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 184: {
        if (!_bb.readVarFloat(_data_stackCounterSpacing)) return false;
        set_stackCounterSpacing(_data_stackCounterSpacing);
        break;
      }
      case 185: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_stackCounterAlignContent))) return false;
        set_stackCounterAlignContent(_data_stackCounterAlignContent);
        break;
      }
      case 186: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_stackWrap))) return false;
        set_stackWrap(_data_stackWrap);
        break;
      }
      case 187: {
        _data_minSize = _pool.allocate<Vector>();
        if (!_data_minSize->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 188: {
        _data_maxSize = _pool.allocate<Vector>();
        if (!_data_maxSize->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 189: {
        if (!_bb.readVarUint(_count)) return false;
        for (ComponentPropDef &_it : set_componentPropDef(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 190: {
        if (!_bb.readVarUint(_count)) return false;
        for (ComponentPropRef &_it : set_componentPropRef(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 191: {
        if (!_bb.readVarUint(_count)) return false;
        for (ComponentPropAssignment &_it : set_componentPropAssignment(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 192: {
        if (!_bb.readVarUint(_count)) return false;
        for (SymbolLink &_it : set_symbolLinks(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 193: {
        if (!_bb.readString(_data_description, _pool)) return false;
        set_description(_data_description);
        break;
      }
      case 194: {
        if (!_bb.readByte(_data_exportNameByVariantProp)) return false;
        set_exportNameByVariantProp(_data_exportNameByVariantProp);
        break;
      }
      case 195: {
        if (!_bb.readByte(_data_propsAreBubbled)) return false;
        set_propsAreBubbled(_data_propsAreBubbled);
        break;
      }
      case 196: {
        if (!_bb.readByte(_data_showMask)) return false;
        set_showMask(_data_showMask);
        break;
      }
      case 197: {
        if (!_bb.readByte(_data_componentOverrideHierarchy)) return false;
        set_componentOverrideHierarchy(_data_componentOverrideHierarchy);
        break;
      }
      case 198: {
        if (!_bb.readVarUint(_count)) return false;
        for (DeveloperRelatedLink &_it : set_developerRelatedLinks(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 199: {
        if (!_bb.readVarUint(_count)) return false;
        for (FontVariation &_it : set_fontVariations(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 200: {
        _data_pathTextInfo = _pool.allocate<PathTextInfo>();
        if (!_data_pathTextInfo->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 201: {
        if (!_bb.readByte(_data_detachOpticalSizeFromFontSize)) return false;
        set_detachOpticalSizeFromFontSize(_data_detachOpticalSizeFromFontSize);
        break;
      }
      case 202: {
        _data_radialRepeatData = _pool.allocate<RadialRepeatData>();
        if (!_data_radialRepeatData->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 203: {
        if (!_bb.readVarInt(_data_overrideLevel)) return false;
        set_overrideLevel(_data_overrideLevel);
        break;
      }
      case 204: {
        _data_variableData = _pool.allocate<VariableData>();
        if (!_data_variableData->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 205: {
        _data_variableConsumptionMap = _pool.allocate<VariableDataMap>();
        if (!_data_variableConsumptionMap->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 206: {
        _data_variableModeBySetMap = _pool.allocate<VariableModeBySetMap>();
        if (!_data_variableModeBySetMap->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 207: {
        if (!_bb.readVarUint(_count)) return false;
        for (VariableSetMode &_it : set_variableSetModes(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 208: {
        _data_variableSetID = _pool.allocate<AssetID>();
        if (!_data_variableSetID->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 209: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_variableResolvedType))) return false;
        set_variableResolvedType(_data_variableResolvedType);
        break;
      }
      case 210: {
        _data_variableDataValues = _pool.allocate<VariableDataValues>();
        if (!_data_variableDataValues->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 211: {
        if (!_bb.readString(_data_variableTokenName, _pool)) return false;
        set_variableTokenName(_data_variableTokenName);
        break;
      }
      case 212: {
        if (!_bb.readVarUint(_count)) return false;
        for (VariableScope &_it : set_variableScopes(_pool, _count)) if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_it))) return false;
        break;
      }
      case 213: {
        _data_codeSyntax = _pool.allocate<CodeSyntaxMap>();
        if (!_data_codeSyntax->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 214: {
        _data_backingVariableSetId = _pool.allocate<AssetID>();
        if (!_data_backingVariableSetId->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 215: {
        _data_backingVariableId = _pool.allocate<VariableIdOrVariableOverrideId>();
        if (!_data_backingVariableId->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 216: {
        if (!_bb.readString(_data_rootVariableKey, _pool)) return false;
        set_rootVariableKey(_data_rootVariableKey);
        break;
      }
      case 217: {
        if (!_bb.readString(_data_userFacingVersion, _pool)) return false;
        set_userFacingVersion(_data_userFacingVersion);
        break;
      }
      case 218: {
        if (!_bb.readString(_data_key, _pool)) return false;
        set_key(_data_key);
        break;
      }
      case 219: {
        if (!_bb.readByte(_data_isSoftDeleted)) return false;
        set_isSoftDeleted(_data_isSoftDeleted);
        break;
      }
      case 220: {
        if (!_bb.readString(_data_sortPosition, _pool)) return false;
        set_sortPosition(_data_sortPosition);
        break;
      }
      case 221: {
        if (!_bb.readString(_data_sourceLibraryKey, _pool)) return false;
        set_sourceLibraryKey(_data_sourceLibraryKey);
        break;
      }
      case 222: {
        _data_deliverInfo = _pool.allocate<DeliverInfo>();
        if (!_data_deliverInfo->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 223: {
        _data_deformationTransform = _pool.allocate<Matrix3f>();
        if (!_data_deformationTransform->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 224: {
        if (!_bb.readVarUint(_count)) return false;
        for (TransformModifier &_it : set_transformModifiers(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 225: {
        if (!_bb.readByte(_data_groupIncludeInvisible)) return false;
        set_groupIncludeInvisible(_data_groupIncludeInvisible);
        break;
      }
      case 226: {
        _data_variableSymbolID = _pool.allocate<GUID>();
        if (!_data_variableSymbolID->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 227: {
        if (!_bb.readVarUint(_count)) return false;
        for (Annotation &_it : set_annotations(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 228: {
        _data_annotationCategories = _pool.allocate<AnnotationCategories>();
        if (!_data_annotationCategories->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 229: {
        _data_gridRowAnchor = _pool.allocate<GUID>();
        if (!_data_gridRowAnchor->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 230: {
        _data_gridColumnAnchor = _pool.allocate<GUID>();
        if (!_data_gridColumnAnchor->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 231: {
        if (!_bb.readVarUint(_data_gridRowSpan)) return false;
        set_gridRowSpan(_data_gridRowSpan);
        break;
      }
      case 232: {
        if (!_bb.readVarUint(_data_gridColumnSpan)) return false;
        set_gridColumnSpan(_data_gridColumnSpan);
        break;
      }
      case 233: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_gridChildVerticalAlign))) return false;
        set_gridChildVerticalAlign(_data_gridChildVerticalAlign);
        break;
      }
      case 234: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_gridChildHorizontalAlign))) return false;
        set_gridChildHorizontalAlign(_data_gridChildHorizontalAlign);
        break;
      }
      case 235: {
        if (!_bb.readVarUint(_count)) return false;
        for (GUID &_it : set_gridRows(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 236: {
        if (!_bb.readVarUint(_count)) return false;
        for (GUID &_it : set_gridColumns(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 237: {
        if (!_bb.readVarUint(_count)) return false;
        for (GridTrackSizing &_it : set_gridRowsSizing(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 238: {
        if (!_bb.readVarUint(_count)) return false;
        for (GridTrackSizing &_it : set_gridColumnsSizing(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 239: {
        if (!_bb.readByte(_data_autoCornerRadius)) return false;
        set_autoCornerRadius(_data_autoCornerRadius);
        break;
      }
      case 240: {
        _data_targetAspectRatio = _pool.allocate<Vector>();
        if (!_data_targetAspectRatio->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 241: {
        if (!_bb.readString(_data_aliasName, _pool)) return false;
        set_aliasName(_data_aliasName);
        break;
      }
      case 242: {
        if (!_bb.readByte(_data_simplifyInstancePanels)) return false;
        set_simplifyInstancePanels(_data_simplifyInstancePanels);
        break;
      }
      case 243: {
        _data_rotationOrigin = _pool.allocate<Vector>();
        if (!_data_rotationOrigin->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 244: {
        _data_videoPlayback = _pool.allocate<VideoPlayback>();
        if (!_data_videoPlayback->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 245: {
        if (!_bb.readVarUint(_count)) return false;
        for (VariableWidthPoint &_it : set_variableWidths(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipPixsoNodeField(_bb, _type)) return false;
        break;
      }
    }
  }
}

ProdTextStyle *ProdMode::textStyle() {
  return _data_textStyle;
}

const ProdTextStyle *ProdMode::textStyle() const {
  return _data_textStyle;
}

void ProdMode::set_textStyle(ProdTextStyle *value) {
  _data_textStyle = value;
}

float *ProdMode::navigationItemInterval() {
  return _flags[0] & 2 ? &_data_navigationItemInterval : nullptr;
}

const float *ProdMode::navigationItemInterval() const {
  return _flags[0] & 2 ? &_data_navigationItemInterval : nullptr;
}

void ProdMode::set_navigationItemInterval(const float &value) {
  _flags[0] |= 2; _data_navigationItemInterval = value;
}

kiwi::String *ProdMode::prodContent() {
  return _flags[0] & 4 ? &_data_prodContent : nullptr;
}

const kiwi::String *ProdMode::prodContent() const {
  return _flags[0] & 4 ? &_data_prodContent : nullptr;
}

void ProdMode::set_prodContent(const kiwi::String &value) {
  _flags[0] |= 4; _data_prodContent = value;
}

ParentIndex *ProdMode::hostIndex() {
  return _data_hostIndex;
}

const ParentIndex *ProdMode::hostIndex() const {
  return _data_hostIndex;
}

void ProdMode::set_hostIndex(ParentIndex *value) {
  _data_hostIndex = value;
}

int32_t *ProdMode::tableRowCount() {
  return _flags[0] & 16 ? &_data_tableRowCount : nullptr;
}

const int32_t *ProdMode::tableRowCount() const {
  return _flags[0] & 16 ? &_data_tableRowCount : nullptr;
}

void ProdMode::set_tableRowCount(const int32_t &value) {
  _flags[0] |= 16; _data_tableRowCount = value;
}

int32_t *ProdMode::tableColCount() {
  return _flags[0] & 32 ? &_data_tableColCount : nullptr;
}

const int32_t *ProdMode::tableColCount() const {
  return _flags[0] & 32 ? &_data_tableColCount : nullptr;
}

void ProdMode::set_tableColCount(const int32_t &value) {
  _flags[0] |= 32; _data_tableColCount = value;
}

GUID *ProdMode::dropListOptionSelectID() {
  return _data_dropListOptionSelectID;
}

const GUID *ProdMode::dropListOptionSelectID() const {
  return _data_dropListOptionSelectID;
}

void ProdMode::set_dropListOptionSelectID(GUID *value) {
  _data_dropListOptionSelectID = value;
}

bool *ProdMode::dropListExpand() {
  return _flags[0] & 128 ? &_data_dropListExpand : nullptr;
}

const bool *ProdMode::dropListExpand() const {
  return _flags[0] & 128 ? &_data_dropListExpand : nullptr;
}

void ProdMode::set_dropListExpand(const bool &value) {
  _flags[0] |= 128; _data_dropListExpand = value;
}

ProdTextStyle *ProdMode::activeTextStyle() {
  return _data_activeTextStyle;
}

const ProdTextStyle *ProdMode::activeTextStyle() const {
  return _data_activeTextStyle;
}

void ProdMode::set_activeTextStyle(ProdTextStyle *value) {
  _data_activeTextStyle = value;
}

Vector *ProdMode::tableSize() {
  return _data_tableSize;
}

const Vector *ProdMode::tableSize() const {
  return _data_tableSize;
}

void ProdMode::set_tableSize(Vector *value) {
  _data_tableSize = value;
}

Paint *ProdMode::tableCellFillPaint() {
  return _data_tableCellFillPaint;
}

const Paint *ProdMode::tableCellFillPaint() const {
  return _data_tableCellFillPaint;
}

void ProdMode::set_tableCellFillPaint(Paint *value) {
  _data_tableCellFillPaint = value;
}

Vector *ProdMode::navigationItemSize() {
  return _data_navigationItemSize;
}

const Vector *ProdMode::navigationItemSize() const {
  return _data_navigationItemSize;
}

void ProdMode::set_navigationItemSize(Vector *value) {
  _data_navigationItemSize = value;
}

bool *ProdMode::navigationOptionExpand() {
  return _flags[0] & 4096 ? &_data_navigationOptionExpand : nullptr;
}

const bool *ProdMode::navigationOptionExpand() const {
  return _flags[0] & 4096 ? &_data_navigationOptionExpand : nullptr;
}

void ProdMode::set_navigationOptionExpand(const bool &value) {
  _flags[0] |= 4096; _data_navigationOptionExpand = value;
}

bool *ProdMode::componentLibrarySwitch() {
  return _flags[0] & 8192 ? &_data_componentLibrarySwitch : nullptr;
}

const bool *ProdMode::componentLibrarySwitch() const {
  return _flags[0] & 8192 ? &_data_componentLibrarySwitch : nullptr;
}

void ProdMode::set_componentLibrarySwitch(const bool &value) {
  _flags[0] |= 8192; _data_componentLibrarySwitch = value;
}

ProdScoreBar *ProdMode::scoreBar() {
  return _data_scoreBar;
}

const ProdScoreBar *ProdMode::scoreBar() const {
  return _data_scoreBar;
}

void ProdMode::set_scoreBar(ProdScoreBar *value) {
  _data_scoreBar = value;
}

float *ProdMode::navigationItemRatio() {
  return _flags[0] & 32768 ? &_data_navigationItemRatio : nullptr;
}

const float *ProdMode::navigationItemRatio() const {
  return _flags[0] & 32768 ? &_data_navigationItemRatio : nullptr;
}

void ProdMode::set_navigationItemRatio(const float &value) {
  _flags[0] |= 32768; _data_navigationItemRatio = value;
}

ProdDragBar *ProdMode::dragBar() {
  return _data_dragBar;
}

const ProdDragBar *ProdMode::dragBar() const {
  return _data_dragBar;
}

void ProdMode::set_dragBar(ProdDragBar *value) {
  _data_dragBar = value;
}

ProdTableCell *ProdMode::tableCell() {
  return _data_tableCell;
}

const ProdTableCell *ProdMode::tableCell() const {
  return _data_tableCell;
}

void ProdMode::set_tableCell(ProdTableCell *value) {
  _data_tableCell = value;
}

int32_t *ProdMode::tableBorderStyle() {
  return _flags[0] & 262144 ? &_data_tableBorderStyle : nullptr;
}

const int32_t *ProdMode::tableBorderStyle() const {
  return _flags[0] & 262144 ? &_data_tableBorderStyle : nullptr;
}

void ProdMode::set_tableBorderStyle(const int32_t &value) {
  _flags[0] |= 262144; _data_tableBorderStyle = value;
}

int32_t *ProdMode::embeddedIconPositionFlag() {
  return _flags[0] & 524288 ? &_data_embeddedIconPositionFlag : nullptr;
}

const int32_t *ProdMode::embeddedIconPositionFlag() const {
  return _flags[0] & 524288 ? &_data_embeddedIconPositionFlag : nullptr;
}

void ProdMode::set_embeddedIconPositionFlag(const int32_t &value) {
  _flags[0] |= 524288; _data_embeddedIconPositionFlag = value;
}

float *ProdMode::recordHeight() {
  return _flags[0] & 1048576 ? &_data_recordHeight : nullptr;
}

const float *ProdMode::recordHeight() const {
  return _flags[0] & 1048576 ? &_data_recordHeight : nullptr;
}

void ProdMode::set_recordHeight(const float &value) {
  _flags[0] |= 1048576; _data_recordHeight = value;
}

int32_t *ProdMode::selectForm() {
  return _flags[0] & 2097152 ? &_data_selectForm : nullptr;
}

const int32_t *ProdMode::selectForm() const {
  return _flags[0] & 2097152 ? &_data_selectForm : nullptr;
}

void ProdMode::set_selectForm(const int32_t &value) {
  _flags[0] |= 2097152; _data_selectForm = value;
}

int32_t *ProdMode::layoutMethod() {
  return _flags[0] & 4194304 ? &_data_layoutMethod : nullptr;
}

const int32_t *ProdMode::layoutMethod() const {
  return _flags[0] & 4194304 ? &_data_layoutMethod : nullptr;
}

void ProdMode::set_layoutMethod(const int32_t &value) {
  _flags[0] |= 4194304; _data_layoutMethod = value;
}

int32_t *ProdMode::layerPosition() {
  return _flags[0] & 8388608 ? &_data_layerPosition : nullptr;
}

const int32_t *ProdMode::layerPosition() const {
  return _flags[0] & 8388608 ? &_data_layerPosition : nullptr;
}

void ProdMode::set_layerPosition(const int32_t &value) {
  _flags[0] |= 8388608; _data_layerPosition = value;
}

ProdViewportOrientation *ProdMode::viewportOrientation() {
  return _flags[0] & 16777216 ? &_data_viewportOrientation : nullptr;
}

const ProdViewportOrientation *ProdMode::viewportOrientation() const {
  return _flags[0] & 16777216 ? &_data_viewportOrientation : nullptr;
}

void ProdMode::set_viewportOrientation(const ProdViewportOrientation &value) {
  _flags[0] |= 16777216; _data_viewportOrientation = value;
}

kiwi::Array<NodeType> *ProdMode::vNodeType() {
  return _flags[0] & 33554432 ? &_data_vNodeType : nullptr;
}

const kiwi::Array<NodeType> *ProdMode::vNodeType() const {
  return _flags[0] & 33554432 ? &_data_vNodeType : nullptr;
}

kiwi::Array<NodeType> &ProdMode::set_vNodeType(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 33554432; return _data_vNodeType = pool.array<NodeType>(count);
}

kiwi::String *ProdMode::stringIconSVG() {
  return _flags[0] & 67108864 ? &_data_stringIconSVG : nullptr;
}

const kiwi::String *ProdMode::stringIconSVG() const {
  return _flags[0] & 67108864 ? &_data_stringIconSVG : nullptr;
}

void ProdMode::set_stringIconSVG(const kiwi::String &value) {
  _flags[0] |= 67108864; _data_stringIconSVG = value;
}

bool *ProdMode::tableHeaderVisible() {
  return _flags[0] & 134217728 ? &_data_tableHeaderVisible : nullptr;
}

const bool *ProdMode::tableHeaderVisible() const {
  return _flags[0] & 134217728 ? &_data_tableHeaderVisible : nullptr;
}

void ProdMode::set_tableHeaderVisible(const bool &value) {
  _flags[0] |= 134217728; _data_tableHeaderVisible = value;
}

float *ProdMode::recordWidth() {
  return _flags[0] & 268435456 ? &_data_recordWidth : nullptr;
}

const float *ProdMode::recordWidth() const {
  return _flags[0] & 268435456 ? &_data_recordWidth : nullptr;
}

void ProdMode::set_recordWidth(const float &value) {
  _flags[0] |= 268435456; _data_recordWidth = value;
}

int32_t *ProdMode::recodeCount() {
  return _flags[0] & 536870912 ? &_data_recodeCount : nullptr;
}

const int32_t *ProdMode::recodeCount() const {
  return _flags[0] & 536870912 ? &_data_recodeCount : nullptr;
}

void ProdMode::set_recodeCount(const int32_t &value) {
  _flags[0] |= 536870912; _data_recodeCount = value;
}

int32_t *ProdMode::selectIndex() {
  return _flags[0] & 1073741824 ? &_data_selectIndex : nullptr;
}

const int32_t *ProdMode::selectIndex() const {
  return _flags[0] & 1073741824 ? &_data_selectIndex : nullptr;
}

void ProdMode::set_selectIndex(const int32_t &value) {
  _flags[0] |= 1073741824; _data_selectIndex = value;
}

ProdLayoutParam *ProdMode::layoutParam() {
  return _data_layoutParam;
}

const ProdLayoutParam *ProdMode::layoutParam() const {
  return _data_layoutParam;
}

void ProdMode::set_layoutParam(ProdLayoutParam *value) {
  _data_layoutParam = value;
}

ProdBlockStyleType *ProdMode::blockStyleType() {
  return _flags[1] & 1 ? &_data_blockStyleType : nullptr;
}

const ProdBlockStyleType *ProdMode::blockStyleType() const {
  return _flags[1] & 1 ? &_data_blockStyleType : nullptr;
}

void ProdMode::set_blockStyleType(const ProdBlockStyleType &value) {
  _flags[1] |= 1; _data_blockStyleType = value;
}

float *ProdMode::distance() {
  return _flags[1] & 2 ? &_data_distance : nullptr;
}

const float *ProdMode::distance() const {
  return _flags[1] & 2 ? &_data_distance : nullptr;
}

void ProdMode::set_distance(const float &value) {
  _flags[1] |= 2; _data_distance = value;
}

bool *ProdMode::hoverTrigger() {
  return _flags[1] & 4 ? &_data_hoverTrigger : nullptr;
}

const bool *ProdMode::hoverTrigger() const {
  return _flags[1] & 4 ? &_data_hoverTrigger : nullptr;
}

void ProdMode::set_hoverTrigger(const bool &value) {
  _flags[1] |= 4; _data_hoverTrigger = value;
}

bool *ProdMode::fitContent() {
  return _flags[1] & 8 ? &_data_fitContent : nullptr;
}

const bool *ProdMode::fitContent() const {
  return _flags[1] & 8 ? &_data_fitContent : nullptr;
}

void ProdMode::set_fitContent(const bool &value) {
  _flags[1] |= 8; _data_fitContent = value;
}

kiwi::String *ProdMode::stringIconName() {
  return _flags[1] & 16 ? &_data_stringIconName : nullptr;
}

const kiwi::String *ProdMode::stringIconName() const {
  return _flags[1] & 16 ? &_data_stringIconName : nullptr;
}

void ProdMode::set_stringIconName(const kiwi::String &value) {
  _flags[1] |= 16; _data_stringIconName = value;
}

ProdTwoDimChart *ProdMode::twoDimChart() {
  return _data_twoDimChart;
}

const ProdTwoDimChart *ProdMode::twoDimChart() const {
  return _data_twoDimChart;
}

void ProdMode::set_twoDimChart(ProdTwoDimChart *value) {
  _data_twoDimChart = value;
}

kiwi::Array<GUID> *ProdMode::extraGuids() {
  return _flags[1] & 64 ? &_data_extraGuids : nullptr;
}

const kiwi::Array<GUID> *ProdMode::extraGuids() const {
  return _flags[1] & 64 ? &_data_extraGuids : nullptr;
}

kiwi::Array<GUID> &ProdMode::set_extraGuids(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[1] |= 64; return _data_extraGuids = pool.array<GUID>(count);
}

bool *ProdMode::tableSelectColVisible() {
  return _flags[1] & 128 ? &_data_tableSelectColVisible : nullptr;
}

const bool *ProdMode::tableSelectColVisible() const {
  return _flags[1] & 128 ? &_data_tableSelectColVisible : nullptr;
}

void ProdMode::set_tableSelectColVisible(const bool &value) {
  _flags[1] |= 128; _data_tableSelectColVisible = value;
}

ScrollBar *ProdMode::frameScrollBarVisible() {
  return _flags[1] & 256 ? &_data_frameScrollBarVisible : nullptr;
}

const ScrollBar *ProdMode::frameScrollBarVisible() const {
  return _flags[1] & 256 ? &_data_frameScrollBarVisible : nullptr;
}

void ProdMode::set_frameScrollBarVisible(const ScrollBar &value) {
  _flags[1] |= 256; _data_frameScrollBarVisible = value;
}

int32_t *ProdMode::checkBoxState() {
  return _flags[1] & 512 ? &_data_checkBoxState : nullptr;
}

const int32_t *ProdMode::checkBoxState() const {
  return _flags[1] & 512 ? &_data_checkBoxState : nullptr;
}

void ProdMode::set_checkBoxState(const int32_t &value) {
  _flags[1] |= 512; _data_checkBoxState = value;
}

ComponentStateType *ProdMode::componentState() {
  return _flags[1] & 1024 ? &_data_componentState : nullptr;
}

const ComponentStateType *ProdMode::componentState() const {
  return _flags[1] & 1024 ? &_data_componentState : nullptr;
}

void ProdMode::set_componentState(const ComponentStateType &value) {
  _flags[1] |= 1024; _data_componentState = value;
}

bool *ProdMode::iconSwitch() {
  return _flags[1] & 2048 ? &_data_iconSwitch : nullptr;
}

const bool *ProdMode::iconSwitch() const {
  return _flags[1] & 2048 ? &_data_iconSwitch : nullptr;
}

void ProdMode::set_iconSwitch(const bool &value) {
  _flags[1] |= 2048; _data_iconSwitch = value;
}

bool *ProdMode::checkBoxSwitch() {
  return _flags[1] & 4096 ? &_data_checkBoxSwitch : nullptr;
}

const bool *ProdMode::checkBoxSwitch() const {
  return _flags[1] & 4096 ? &_data_checkBoxSwitch : nullptr;
}

void ProdMode::set_checkBoxSwitch(const bool &value) {
  _flags[1] |= 4096; _data_checkBoxSwitch = value;
}

bool *ProdMode::flodingSymbolSwitch() {
  return _flags[1] & 8192 ? &_data_flodingSymbolSwitch : nullptr;
}

const bool *ProdMode::flodingSymbolSwitch() const {
  return _flags[1] & 8192 ? &_data_flodingSymbolSwitch : nullptr;
}

void ProdMode::set_flodingSymbolSwitch(const bool &value) {
  _flags[1] |= 8192; _data_flodingSymbolSwitch = value;
}

bool *ProdMode::checkBoxHited() {
  return _flags[1] & 16384 ? &_data_checkBoxHited : nullptr;
}

const bool *ProdMode::checkBoxHited() const {
  return _flags[1] & 16384 ? &_data_checkBoxHited : nullptr;
}

void ProdMode::set_checkBoxHited(const bool &value) {
  _flags[1] |= 16384; _data_checkBoxHited = value;
}

float *ProdMode::layerlndent() {
  return _flags[1] & 32768 ? &_data_layerlndent : nullptr;
}

const float *ProdMode::layerlndent() const {
  return _flags[1] & 32768 ? &_data_layerlndent : nullptr;
}

void ProdMode::set_layerlndent(const float &value) {
  _flags[1] |= 32768; _data_layerlndent = value;
}

int32_t *ProdMode::foldingSymbolType() {
  return _flags[1] & 65536 ? &_data_foldingSymbolType : nullptr;
}

const int32_t *ProdMode::foldingSymbolType() const {
  return _flags[1] & 65536 ? &_data_foldingSymbolType : nullptr;
}

void ProdMode::set_foldingSymbolType(const int32_t &value) {
  _flags[1] |= 65536; _data_foldingSymbolType = value;
}

kiwi::Array<GUID> *ProdMode::blockMarkerIds() {
  return _flags[1] & 131072 ? &_data_blockMarkerIds : nullptr;
}

const kiwi::Array<GUID> *ProdMode::blockMarkerIds() const {
  return _flags[1] & 131072 ? &_data_blockMarkerIds : nullptr;
}

kiwi::Array<GUID> &ProdMode::set_blockMarkerIds(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[1] |= 131072; return _data_blockMarkerIds = pool.array<GUID>(count);
}

BlockMarkerParams *ProdMode::blockMarkerParams() {
  return _data_blockMarkerParams;
}

const BlockMarkerParams *ProdMode::blockMarkerParams() const {
  return _data_blockMarkerParams;
}

void ProdMode::set_blockMarkerParams(BlockMarkerParams *value) {
  _data_blockMarkerParams = value;
}

bool ProdMode::encode(kiwi::ByteBuffer &_bb) {
  if (textStyle() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_textStyle->encode(_bb)) return false;
  }
  if (navigationItemInterval() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarFloat(_data_navigationItemInterval);
  }
  if (prodContent() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeString(_data_prodContent.c_str());
  }
  if (hostIndex() != nullptr) {
    _bb.writeVarUint(4);
    if (!_data_hostIndex->encode(_bb)) return false;
  }
  if (tableRowCount() != nullptr) {
    _bb.writeVarUint(5);
    _bb.writeVarInt(_data_tableRowCount);
  }
  if (tableColCount() != nullptr) {
    _bb.writeVarUint(6);
    _bb.writeVarInt(_data_tableColCount);
  }
  if (dropListOptionSelectID() != nullptr) {
    _bb.writeVarUint(7);
    if (!_data_dropListOptionSelectID->encode(_bb)) return false;
  }
  if (dropListExpand() != nullptr) {
    _bb.writeVarUint(8);
    _bb.writeByte(_data_dropListExpand);
  }
  if (activeTextStyle() != nullptr) {
    _bb.writeVarUint(9);
    if (!_data_activeTextStyle->encode(_bb)) return false;
  }
  if (tableSize() != nullptr) {
    _bb.writeVarUint(10);
    if (!_data_tableSize->encode(_bb)) return false;
  }
  if (tableCellFillPaint() != nullptr) {
    _bb.writeVarUint(11);
    if (!_data_tableCellFillPaint->encode(_bb)) return false;
  }
  if (navigationItemSize() != nullptr) {
    _bb.writeVarUint(12);
    if (!_data_navigationItemSize->encode(_bb)) return false;
  }
  if (navigationOptionExpand() != nullptr) {
    _bb.writeVarUint(13);
    _bb.writeByte(_data_navigationOptionExpand);
  }
  if (componentLibrarySwitch() != nullptr) {
    _bb.writeVarUint(14);
    _bb.writeByte(_data_componentLibrarySwitch);
  }
  if (scoreBar() != nullptr) {
    _bb.writeVarUint(15);
    if (!_data_scoreBar->encode(_bb)) return false;
  }
  if (navigationItemRatio() != nullptr) {
    _bb.writeVarUint(16);
    _bb.writeVarFloat(_data_navigationItemRatio);
  }
  if (dragBar() != nullptr) {
    _bb.writeVarUint(17);
    if (!_data_dragBar->encode(_bb)) return false;
  }
  if (tableCell() != nullptr) {
    _bb.writeVarUint(18);
    if (!_data_tableCell->encode(_bb)) return false;
  }
  if (tableBorderStyle() != nullptr) {
    _bb.writeVarUint(19);
    _bb.writeVarInt(_data_tableBorderStyle);
  }
  if (embeddedIconPositionFlag() != nullptr) {
    _bb.writeVarUint(20);
    _bb.writeVarInt(_data_embeddedIconPositionFlag);
  }
  if (recordHeight() != nullptr) {
    _bb.writeVarUint(21);
    _bb.writeVarFloat(_data_recordHeight);
  }
  if (selectForm() != nullptr) {
    _bb.writeVarUint(22);
    _bb.writeVarInt(_data_selectForm);
  }
  if (layoutMethod() != nullptr) {
    _bb.writeVarUint(23);
    _bb.writeVarInt(_data_layoutMethod);
  }
  if (layerPosition() != nullptr) {
    _bb.writeVarUint(24);
    _bb.writeVarInt(_data_layerPosition);
  }
  if (viewportOrientation() != nullptr) {
    _bb.writeVarUint(25);
    _bb.writeVarUint(static_cast<uint32_t>(_data_viewportOrientation));
  }
  if (vNodeType() != nullptr) {
    _bb.writeVarUint(26);
    _bb.writeVarUint(_data_vNodeType.size());
    for (NodeType &_it : _data_vNodeType) _bb.writeVarUint(static_cast<uint32_t>(_it));
  }
  if (stringIconSVG() != nullptr) {
    _bb.writeVarUint(27);
    _bb.writeString(_data_stringIconSVG.c_str());
  }
  if (tableHeaderVisible() != nullptr) {
    _bb.writeVarUint(28);
    _bb.writeByte(_data_tableHeaderVisible);
  }
  if (recordWidth() != nullptr) {
    _bb.writeVarUint(29);
    _bb.writeVarFloat(_data_recordWidth);
  }
  if (recodeCount() != nullptr) {
    _bb.writeVarUint(30);
    _bb.writeVarInt(_data_recodeCount);
  }
  if (selectIndex() != nullptr) {
    _bb.writeVarUint(31);
    _bb.writeVarInt(_data_selectIndex);
  }
  if (layoutParam() != nullptr) {
    _bb.writeVarUint(32);
    if (!_data_layoutParam->encode(_bb)) return false;
  }
  if (blockStyleType() != nullptr) {
    _bb.writeVarUint(33);
    _bb.writeVarUint(static_cast<uint32_t>(_data_blockStyleType));
  }
  if (distance() != nullptr) {
    _bb.writeVarUint(34);
    _bb.writeVarFloat(_data_distance);
  }
  if (hoverTrigger() != nullptr) {
    _bb.writeVarUint(35);
    _bb.writeByte(_data_hoverTrigger);
  }
  if (fitContent() != nullptr) {
    _bb.writeVarUint(36);
    _bb.writeByte(_data_fitContent);
  }
  if (stringIconName() != nullptr) {
    _bb.writeVarUint(37);
    _bb.writeString(_data_stringIconName.c_str());
  }
  if (twoDimChart() != nullptr) {
    _bb.writeVarUint(38);
    if (!_data_twoDimChart->encode(_bb)) return false;
  }
  if (extraGuids() != nullptr) {
    _bb.writeVarUint(39);
    _bb.writeVarUint(_data_extraGuids.size());
    for (GUID &_it : _data_extraGuids) if (!_it.encode(_bb)) return false;
  }
  if (tableSelectColVisible() != nullptr) {
    _bb.writeVarUint(40);
    _bb.writeByte(_data_tableSelectColVisible);
  }
  if (frameScrollBarVisible() != nullptr) {
    _bb.writeVarUint(41);
    _bb.writeVarUint(static_cast<uint32_t>(_data_frameScrollBarVisible));
  }
  if (checkBoxState() != nullptr) {
    _bb.writeVarUint(42);
    _bb.writeVarInt(_data_checkBoxState);
  }
  if (componentState() != nullptr) {
    _bb.writeVarUint(43);
    _bb.writeVarUint(static_cast<uint32_t>(_data_componentState));
  }
  if (iconSwitch() != nullptr) {
    _bb.writeVarUint(44);
    _bb.writeByte(_data_iconSwitch);
  }
  if (checkBoxSwitch() != nullptr) {
    _bb.writeVarUint(45);
    _bb.writeByte(_data_checkBoxSwitch);
  }
  if (flodingSymbolSwitch() != nullptr) {
    _bb.writeVarUint(46);
    _bb.writeByte(_data_flodingSymbolSwitch);
  }
  if (checkBoxHited() != nullptr) {
    _bb.writeVarUint(47);
    _bb.writeByte(_data_checkBoxHited);
  }
  if (layerlndent() != nullptr) {
    _bb.writeVarUint(48);
    _bb.writeVarFloat(_data_layerlndent);
  }
  if (foldingSymbolType() != nullptr) {
    _bb.writeVarUint(49);
    _bb.writeVarInt(_data_foldingSymbolType);
  }
  if (blockMarkerIds() != nullptr) {
    _bb.writeVarUint(50);
    _bb.writeVarUint(_data_blockMarkerIds.size());
    for (GUID &_it : _data_blockMarkerIds) if (!_it.encode(_bb)) return false;
  }
  if (blockMarkerParams() != nullptr) {
    _bb.writeVarUint(51);
    if (!_data_blockMarkerParams->encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool ProdMode::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_textStyle = _pool.allocate<ProdTextStyle>();
        if (!_data_textStyle->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        if (!_bb.readVarFloat(_data_navigationItemInterval)) return false;
        set_navigationItemInterval(_data_navigationItemInterval);
        break;
      }
      case 3: {
        if (!_bb.readString(_data_prodContent, _pool)) return false;
        set_prodContent(_data_prodContent);
        break;
      }
      case 4: {
        _data_hostIndex = _pool.allocate<ParentIndex>();
        if (!_data_hostIndex->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 5: {
        if (!_bb.readVarInt(_data_tableRowCount)) return false;
        set_tableRowCount(_data_tableRowCount);
        break;
      }
      case 6: {
        if (!_bb.readVarInt(_data_tableColCount)) return false;
        set_tableColCount(_data_tableColCount);
        break;
      }
      case 7: {
        _data_dropListOptionSelectID = _pool.allocate<GUID>();
        if (!_data_dropListOptionSelectID->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 8: {
        if (!_bb.readByte(_data_dropListExpand)) return false;
        set_dropListExpand(_data_dropListExpand);
        break;
      }
      case 9: {
        _data_activeTextStyle = _pool.allocate<ProdTextStyle>();
        if (!_data_activeTextStyle->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 10: {
        _data_tableSize = _pool.allocate<Vector>();
        if (!_data_tableSize->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 11: {
        _data_tableCellFillPaint = _pool.allocate<Paint>();
        if (!_data_tableCellFillPaint->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 12: {
        _data_navigationItemSize = _pool.allocate<Vector>();
        if (!_data_navigationItemSize->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 13: {
        if (!_bb.readByte(_data_navigationOptionExpand)) return false;
        set_navigationOptionExpand(_data_navigationOptionExpand);
        break;
      }
      case 14: {
        if (!_bb.readByte(_data_componentLibrarySwitch)) return false;
        set_componentLibrarySwitch(_data_componentLibrarySwitch);
        break;
      }
      case 15: {
        _data_scoreBar = _pool.allocate<ProdScoreBar>();
        if (!_data_scoreBar->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 16: {
        if (!_bb.readVarFloat(_data_navigationItemRatio)) return false;
        set_navigationItemRatio(_data_navigationItemRatio);
        break;
      }
      case 17: {
        _data_dragBar = _pool.allocate<ProdDragBar>();
        if (!_data_dragBar->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 18: {
        _data_tableCell = _pool.allocate<ProdTableCell>();
        if (!_data_tableCell->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 19: {
        if (!_bb.readVarInt(_data_tableBorderStyle)) return false;
        set_tableBorderStyle(_data_tableBorderStyle);
        break;
      }
      case 20: {
        if (!_bb.readVarInt(_data_embeddedIconPositionFlag)) return false;
        set_embeddedIconPositionFlag(_data_embeddedIconPositionFlag);
        break;
      }
      case 21: {
        if (!_bb.readVarFloat(_data_recordHeight)) return false;
        set_recordHeight(_data_recordHeight);
        break;
      }
      case 22: {
        if (!_bb.readVarInt(_data_selectForm)) return false;
        set_selectForm(_data_selectForm);
        break;
      }
      case 23: {
        if (!_bb.readVarInt(_data_layoutMethod)) return false;
        set_layoutMethod(_data_layoutMethod);
        break;
      }
      case 24: {
        if (!_bb.readVarInt(_data_layerPosition)) return false;
        set_layerPosition(_data_layerPosition);
        break;
      }
      case 25: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_viewportOrientation))) return false;
        set_viewportOrientation(_data_viewportOrientation);
        break;
      }
      case 26: {
        if (!_bb.readVarUint(_count)) return false;
        for (NodeType &_it : set_vNodeType(_pool, _count)) if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_it))) return false;
        break;
      }
      case 27: {
        if (!_bb.readString(_data_stringIconSVG, _pool)) return false;
        set_stringIconSVG(_data_stringIconSVG);
        break;
      }
      case 28: {
        if (!_bb.readByte(_data_tableHeaderVisible)) return false;
        set_tableHeaderVisible(_data_tableHeaderVisible);
        break;
      }
      case 29: {
        if (!_bb.readVarFloat(_data_recordWidth)) return false;
        set_recordWidth(_data_recordWidth);
        break;
      }
      case 30: {
        if (!_bb.readVarInt(_data_recodeCount)) return false;
        set_recodeCount(_data_recodeCount);
        break;
      }
      case 31: {
        if (!_bb.readVarInt(_data_selectIndex)) return false;
        set_selectIndex(_data_selectIndex);
        break;
      }
      case 32: {
        _data_layoutParam = _pool.allocate<ProdLayoutParam>();
        if (!_data_layoutParam->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 33: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_blockStyleType))) return false;
        set_blockStyleType(_data_blockStyleType);
        break;
      }
      case 34: {
        if (!_bb.readVarFloat(_data_distance)) return false;
        set_distance(_data_distance);
        break;
      }
      case 35: {
        if (!_bb.readByte(_data_hoverTrigger)) return false;
        set_hoverTrigger(_data_hoverTrigger);
        break;
      }
      case 36: {
        if (!_bb.readByte(_data_fitContent)) return false;
        set_fitContent(_data_fitContent);
        break;
      }
      case 37: {
        if (!_bb.readString(_data_stringIconName, _pool)) return false;
        set_stringIconName(_data_stringIconName);
        break;
      }
      case 38: {
        _data_twoDimChart = _pool.allocate<ProdTwoDimChart>();
        if (!_data_twoDimChart->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 39: {
        if (!_bb.readVarUint(_count)) return false;
        for (GUID &_it : set_extraGuids(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 40: {
        if (!_bb.readByte(_data_tableSelectColVisible)) return false;
        set_tableSelectColVisible(_data_tableSelectColVisible);
        break;
      }
      case 41: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_frameScrollBarVisible))) return false;
        set_frameScrollBarVisible(_data_frameScrollBarVisible);
        break;
      }
      case 42: {
        if (!_bb.readVarInt(_data_checkBoxState)) return false;
        set_checkBoxState(_data_checkBoxState);
        break;
      }
      case 43: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_componentState))) return false;
        set_componentState(_data_componentState);
        break;
      }
      case 44: {
        if (!_bb.readByte(_data_iconSwitch)) return false;
        set_iconSwitch(_data_iconSwitch);
        break;
      }
      case 45: {
        if (!_bb.readByte(_data_checkBoxSwitch)) return false;
        set_checkBoxSwitch(_data_checkBoxSwitch);
        break;
      }
      case 46: {
        if (!_bb.readByte(_data_flodingSymbolSwitch)) return false;
        set_flodingSymbolSwitch(_data_flodingSymbolSwitch);
        break;
      }
      case 47: {
        if (!_bb.readByte(_data_checkBoxHited)) return false;
        set_checkBoxHited(_data_checkBoxHited);
        break;
      }
      case 48: {
        if (!_bb.readVarFloat(_data_layerlndent)) return false;
        set_layerlndent(_data_layerlndent);
        break;
      }
      case 49: {
        if (!_bb.readVarInt(_data_foldingSymbolType)) return false;
        set_foldingSymbolType(_data_foldingSymbolType);
        break;
      }
      case 50: {
        if (!_bb.readVarUint(_count)) return false;
        for (GUID &_it : set_blockMarkerIds(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 51: {
        _data_blockMarkerParams = _pool.allocate<BlockMarkerParams>();
        if (!_data_blockMarkerParams->decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipProdModeField(_bb, _type)) return false;
        break;
      }
    }
  }
}

GUID *BlockMarkerParams::relatedMarkerId() {
  return _data_relatedMarkerId;
}

const GUID *BlockMarkerParams::relatedMarkerId() const {
  return _data_relatedMarkerId;
}

void BlockMarkerParams::set_relatedMarkerId(GUID *value) {
  _data_relatedMarkerId = value;
}

MarkerSide *BlockMarkerParams::markerSide() {
  return _flags[0] & 2 ? &_data_markerSide : nullptr;
}

const MarkerSide *BlockMarkerParams::markerSide() const {
  return _flags[0] & 2 ? &_data_markerSide : nullptr;
}

void BlockMarkerParams::set_markerSide(const MarkerSide &value) {
  _flags[0] |= 2; _data_markerSide = value;
}

GUID *BlockMarkerParams::boundNodeId() {
  return _data_boundNodeId;
}

const GUID *BlockMarkerParams::boundNodeId() const {
  return _data_boundNodeId;
}

void BlockMarkerParams::set_boundNodeId(GUID *value) {
  _data_boundNodeId = value;
}

int32_t *BlockMarkerParams::markerIndex() {
  return _flags[0] & 8 ? &_data_markerIndex : nullptr;
}

const int32_t *BlockMarkerParams::markerIndex() const {
  return _flags[0] & 8 ? &_data_markerIndex : nullptr;
}

void BlockMarkerParams::set_markerIndex(const int32_t &value) {
  _flags[0] |= 8; _data_markerIndex = value;
}

bool BlockMarkerParams::encode(kiwi::ByteBuffer &_bb) {
  if (relatedMarkerId() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_relatedMarkerId->encode(_bb)) return false;
  }
  if (markerSide() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarUint(static_cast<uint32_t>(_data_markerSide));
  }
  if (boundNodeId() != nullptr) {
    _bb.writeVarUint(3);
    if (!_data_boundNodeId->encode(_bb)) return false;
  }
  if (markerIndex() != nullptr) {
    _bb.writeVarUint(4);
    _bb.writeVarInt(_data_markerIndex);
  }
  _bb.writeVarUint(0);
  return true;
}

bool BlockMarkerParams::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_relatedMarkerId = _pool.allocate<GUID>();
        if (!_data_relatedMarkerId->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_markerSide))) return false;
        set_markerSide(_data_markerSide);
        break;
      }
      case 3: {
        _data_boundNodeId = _pool.allocate<GUID>();
        if (!_data_boundNodeId->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 4: {
        if (!_bb.readVarInt(_data_markerIndex)) return false;
        set_markerIndex(_data_markerIndex);
        break;
      }
      default: {
        if (!_schema || !_schema->skipBlockMarkerParamsField(_bb, _type)) return false;
        break;
      }
    }
  }
}

ProdLayoutMode *ProdLayoutParam::layoutMode() {
  return _flags[0] & 1 ? &_data_layoutMode : nullptr;
}

const ProdLayoutMode *ProdLayoutParam::layoutMode() const {
  return _flags[0] & 1 ? &_data_layoutMode : nullptr;
}

void ProdLayoutParam::set_layoutMode(const ProdLayoutMode &value) {
  _flags[0] |= 1; _data_layoutMode = value;
}

ProdLayoutSizeMode *ProdLayoutParam::witdhMode() {
  return _flags[0] & 2 ? &_data_witdhMode : nullptr;
}

const ProdLayoutSizeMode *ProdLayoutParam::witdhMode() const {
  return _flags[0] & 2 ? &_data_witdhMode : nullptr;
}

void ProdLayoutParam::set_witdhMode(const ProdLayoutSizeMode &value) {
  _flags[0] |= 2; _data_witdhMode = value;
}

ProdLayoutSizeMode *ProdLayoutParam::heightMode() {
  return _flags[0] & 4 ? &_data_heightMode : nullptr;
}

const ProdLayoutSizeMode *ProdLayoutParam::heightMode() const {
  return _flags[0] & 4 ? &_data_heightMode : nullptr;
}

void ProdLayoutParam::set_heightMode(const ProdLayoutSizeMode &value) {
  _flags[0] |= 4; _data_heightMode = value;
}

ProdLayoutInterval *ProdLayoutParam::margin() {
  return _data_margin;
}

const ProdLayoutInterval *ProdLayoutParam::margin() const {
  return _data_margin;
}

void ProdLayoutParam::set_margin(ProdLayoutInterval *value) {
  _data_margin = value;
}

ProdLayoutInterval *ProdLayoutParam::padding() {
  return _data_padding;
}

const ProdLayoutInterval *ProdLayoutParam::padding() const {
  return _data_padding;
}

void ProdLayoutParam::set_padding(ProdLayoutInterval *value) {
  _data_padding = value;
}

bool ProdLayoutParam::encode(kiwi::ByteBuffer &_bb) {
  if (layoutMode() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(static_cast<uint32_t>(_data_layoutMode));
  }
  if (witdhMode() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarUint(static_cast<uint32_t>(_data_witdhMode));
  }
  if (heightMode() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeVarUint(static_cast<uint32_t>(_data_heightMode));
  }
  if (margin() != nullptr) {
    _bb.writeVarUint(4);
    if (!_data_margin->encode(_bb)) return false;
  }
  if (padding() != nullptr) {
    _bb.writeVarUint(5);
    if (!_data_padding->encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool ProdLayoutParam::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_layoutMode))) return false;
        set_layoutMode(_data_layoutMode);
        break;
      }
      case 2: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_witdhMode))) return false;
        set_witdhMode(_data_witdhMode);
        break;
      }
      case 3: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_heightMode))) return false;
        set_heightMode(_data_heightMode);
        break;
      }
      case 4: {
        _data_margin = _pool.allocate<ProdLayoutInterval>();
        if (!_data_margin->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 5: {
        _data_padding = _pool.allocate<ProdLayoutInterval>();
        if (!_data_padding->decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipProdLayoutParamField(_bb, _type)) return false;
        break;
      }
    }
  }
}

float *ProdLayoutInterval::left() {
  return _flags[0] & 1 ? &_data_left : nullptr;
}

const float *ProdLayoutInterval::left() const {
  return _flags[0] & 1 ? &_data_left : nullptr;
}

void ProdLayoutInterval::set_left(const float &value) {
  _flags[0] |= 1; _data_left = value;
}

float *ProdLayoutInterval::top() {
  return _flags[0] & 2 ? &_data_top : nullptr;
}

const float *ProdLayoutInterval::top() const {
  return _flags[0] & 2 ? &_data_top : nullptr;
}

void ProdLayoutInterval::set_top(const float &value) {
  _flags[0] |= 2; _data_top = value;
}

float *ProdLayoutInterval::right() {
  return _flags[0] & 4 ? &_data_right : nullptr;
}

const float *ProdLayoutInterval::right() const {
  return _flags[0] & 4 ? &_data_right : nullptr;
}

void ProdLayoutInterval::set_right(const float &value) {
  _flags[0] |= 4; _data_right = value;
}

float *ProdLayoutInterval::bottom() {
  return _flags[0] & 8 ? &_data_bottom : nullptr;
}

const float *ProdLayoutInterval::bottom() const {
  return _flags[0] & 8 ? &_data_bottom : nullptr;
}

void ProdLayoutInterval::set_bottom(const float &value) {
  _flags[0] |= 8; _data_bottom = value;
}

bool ProdLayoutInterval::encode(kiwi::ByteBuffer &_bb) {
  if (left() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarFloat(_data_left);
  }
  if (top() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarFloat(_data_top);
  }
  if (right() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeVarFloat(_data_right);
  }
  if (bottom() != nullptr) {
    _bb.writeVarUint(4);
    _bb.writeVarFloat(_data_bottom);
  }
  _bb.writeVarUint(0);
  return true;
}

bool ProdLayoutInterval::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarFloat(_data_left)) return false;
        set_left(_data_left);
        break;
      }
      case 2: {
        if (!_bb.readVarFloat(_data_top)) return false;
        set_top(_data_top);
        break;
      }
      case 3: {
        if (!_bb.readVarFloat(_data_right)) return false;
        set_right(_data_right);
        break;
      }
      case 4: {
        if (!_bb.readVarFloat(_data_bottom)) return false;
        set_bottom(_data_bottom);
        break;
      }
      default: {
        if (!_schema || !_schema->skipProdLayoutIntervalField(_bb, _type)) return false;
        break;
      }
    }
  }
}

ProdAdjustSizeType *ProdAdjustSize::adjustSizeType() {
  return _flags[0] & 1 ? &_data_adjustSizeType : nullptr;
}

const ProdAdjustSizeType *ProdAdjustSize::adjustSizeType() const {
  return _flags[0] & 1 ? &_data_adjustSizeType : nullptr;
}

void ProdAdjustSize::set_adjustSizeType(const ProdAdjustSizeType &value) {
  _flags[0] |= 1; _data_adjustSizeType = value;
}

ProdAdjustBaseType *ProdAdjustSize::baseDirection() {
  return _flags[0] & 2 ? &_data_baseDirection : nullptr;
}

const ProdAdjustBaseType *ProdAdjustSize::baseDirection() const {
  return _flags[0] & 2 ? &_data_baseDirection : nullptr;
}

void ProdAdjustSize::set_baseDirection(const ProdAdjustBaseType &value) {
  _flags[0] |= 2; _data_baseDirection = value;
}

float *ProdAdjustSize::width() {
  return _flags[0] & 4 ? &_data_width : nullptr;
}

const float *ProdAdjustSize::width() const {
  return _flags[0] & 4 ? &_data_width : nullptr;
}

void ProdAdjustSize::set_width(const float &value) {
  _flags[0] |= 4; _data_width = value;
}

float *ProdAdjustSize::height() {
  return _flags[0] & 8 ? &_data_height : nullptr;
}

const float *ProdAdjustSize::height() const {
  return _flags[0] & 8 ? &_data_height : nullptr;
}

void ProdAdjustSize::set_height(const float &value) {
  _flags[0] |= 8; _data_height = value;
}

ProdAdjustUnitType *ProdAdjustSize::widthUnit() {
  return _flags[0] & 16 ? &_data_widthUnit : nullptr;
}

const ProdAdjustUnitType *ProdAdjustSize::widthUnit() const {
  return _flags[0] & 16 ? &_data_widthUnit : nullptr;
}

void ProdAdjustSize::set_widthUnit(const ProdAdjustUnitType &value) {
  _flags[0] |= 16; _data_widthUnit = value;
}

ProdAdjustUnitType *ProdAdjustSize::heightUnit() {
  return _flags[0] & 32 ? &_data_heightUnit : nullptr;
}

const ProdAdjustUnitType *ProdAdjustSize::heightUnit() const {
  return _flags[0] & 32 ? &_data_heightUnit : nullptr;
}

void ProdAdjustSize::set_heightUnit(const ProdAdjustUnitType &value) {
  _flags[0] |= 32; _data_heightUnit = value;
}

bool ProdAdjustSize::encode(kiwi::ByteBuffer &_bb) {
  if (adjustSizeType() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(static_cast<uint32_t>(_data_adjustSizeType));
  }
  if (baseDirection() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarUint(static_cast<uint32_t>(_data_baseDirection));
  }
  if (width() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeVarFloat(_data_width);
  }
  if (height() != nullptr) {
    _bb.writeVarUint(4);
    _bb.writeVarFloat(_data_height);
  }
  if (widthUnit() != nullptr) {
    _bb.writeVarUint(5);
    _bb.writeVarUint(static_cast<uint32_t>(_data_widthUnit));
  }
  if (heightUnit() != nullptr) {
    _bb.writeVarUint(6);
    _bb.writeVarUint(static_cast<uint32_t>(_data_heightUnit));
  }
  _bb.writeVarUint(0);
  return true;
}

bool ProdAdjustSize::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_adjustSizeType))) return false;
        set_adjustSizeType(_data_adjustSizeType);
        break;
      }
      case 2: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_baseDirection))) return false;
        set_baseDirection(_data_baseDirection);
        break;
      }
      case 3: {
        if (!_bb.readVarFloat(_data_width)) return false;
        set_width(_data_width);
        break;
      }
      case 4: {
        if (!_bb.readVarFloat(_data_height)) return false;
        set_height(_data_height);
        break;
      }
      case 5: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_widthUnit))) return false;
        set_widthUnit(_data_widthUnit);
        break;
      }
      case 6: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_heightUnit))) return false;
        set_heightUnit(_data_heightUnit);
        break;
      }
      default: {
        if (!_schema || !_schema->skipProdAdjustSizeField(_bb, _type)) return false;
        break;
      }
    }
  }
}

ProdChangeLocationType *ProdMoving::adjustSizeType() {
  return _flags[0] & 1 ? &_data_adjustSizeType : nullptr;
}

const ProdChangeLocationType *ProdMoving::adjustSizeType() const {
  return _flags[0] & 1 ? &_data_adjustSizeType : nullptr;
}

void ProdMoving::set_adjustSizeType(const ProdChangeLocationType &value) {
  _flags[0] |= 1; _data_adjustSizeType = value;
}

float *ProdMoving::x() {
  return _flags[0] & 2 ? &_data_x : nullptr;
}

const float *ProdMoving::x() const {
  return _flags[0] & 2 ? &_data_x : nullptr;
}

void ProdMoving::set_x(const float &value) {
  _flags[0] |= 2; _data_x = value;
}

float *ProdMoving::y() {
  return _flags[0] & 4 ? &_data_y : nullptr;
}

const float *ProdMoving::y() const {
  return _flags[0] & 4 ? &_data_y : nullptr;
}

void ProdMoving::set_y(const float &value) {
  _flags[0] |= 4; _data_y = value;
}

bool ProdMoving::encode(kiwi::ByteBuffer &_bb) {
  if (adjustSizeType() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(static_cast<uint32_t>(_data_adjustSizeType));
  }
  if (x() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarFloat(_data_x);
  }
  if (y() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeVarFloat(_data_y);
  }
  _bb.writeVarUint(0);
  return true;
}

bool ProdMoving::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_adjustSizeType))) return false;
        set_adjustSizeType(_data_adjustSizeType);
        break;
      }
      case 2: {
        if (!_bb.readVarFloat(_data_x)) return false;
        set_x(_data_x);
        break;
      }
      case 3: {
        if (!_bb.readVarFloat(_data_y)) return false;
        set_y(_data_y);
        break;
      }
      default: {
        if (!_schema || !_schema->skipProdMovingField(_bb, _type)) return false;
        break;
      }
    }
  }
}

ProdRotationType *ProdRotate::rotationType() {
  return _flags[0] & 1 ? &_data_rotationType : nullptr;
}

const ProdRotationType *ProdRotate::rotationType() const {
  return _flags[0] & 1 ? &_data_rotationType : nullptr;
}

void ProdRotate::set_rotationType(const ProdRotationType &value) {
  _flags[0] |= 1; _data_rotationType = value;
}

float *ProdRotate::anlge() {
  return _flags[0] & 2 ? &_data_anlge : nullptr;
}

const float *ProdRotate::anlge() const {
  return _flags[0] & 2 ? &_data_anlge : nullptr;
}

void ProdRotate::set_anlge(const float &value) {
  _flags[0] |= 2; _data_anlge = value;
}

bool ProdRotate::encode(kiwi::ByteBuffer &_bb) {
  if (rotationType() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(static_cast<uint32_t>(_data_rotationType));
  }
  if (anlge() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarFloat(_data_anlge);
  }
  _bb.writeVarUint(0);
  return true;
}

bool ProdRotate::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_rotationType))) return false;
        set_rotationType(_data_rotationType);
        break;
      }
      case 2: {
        if (!_bb.readVarFloat(_data_anlge)) return false;
        set_anlge(_data_anlge);
        break;
      }
      default: {
        if (!_schema || !_schema->skipProdRotateField(_bb, _type)) return false;
        break;
      }
    }
  }
}

int32_t *ProdTableCell::cellSizeRow() {
  return _flags[0] & 1 ? &_data_cellSizeRow : nullptr;
}

const int32_t *ProdTableCell::cellSizeRow() const {
  return _flags[0] & 1 ? &_data_cellSizeRow : nullptr;
}

void ProdTableCell::set_cellSizeRow(const int32_t &value) {
  _flags[0] |= 1; _data_cellSizeRow = value;
}

int32_t *ProdTableCell::cellSizeCol() {
  return _flags[0] & 2 ? &_data_cellSizeCol : nullptr;
}

const int32_t *ProdTableCell::cellSizeCol() const {
  return _flags[0] & 2 ? &_data_cellSizeCol : nullptr;
}

void ProdTableCell::set_cellSizeCol(const int32_t &value) {
  _flags[0] |= 2; _data_cellSizeCol = value;
}

GUID *ProdTableCell::mergeToGuid() {
  return _data_mergeToGuid;
}

const GUID *ProdTableCell::mergeToGuid() const {
  return _data_mergeToGuid;
}

void ProdTableCell::set_mergeToGuid(GUID *value) {
  _data_mergeToGuid = value;
}

uint32_t *ProdTableCell::cellHAlign() {
  return _flags[0] & 8 ? &_data_cellHAlign : nullptr;
}

const uint32_t *ProdTableCell::cellHAlign() const {
  return _flags[0] & 8 ? &_data_cellHAlign : nullptr;
}

void ProdTableCell::set_cellHAlign(const uint32_t &value) {
  _flags[0] |= 8; _data_cellHAlign = value;
}

uint32_t *ProdTableCell::cellVAlign() {
  return _flags[0] & 16 ? &_data_cellVAlign : nullptr;
}

const uint32_t *ProdTableCell::cellVAlign() const {
  return _flags[0] & 16 ? &_data_cellVAlign : nullptr;
}

void ProdTableCell::set_cellVAlign(const uint32_t &value) {
  _flags[0] |= 16; _data_cellVAlign = value;
}

bool ProdTableCell::encode(kiwi::ByteBuffer &_bb) {
  if (cellSizeRow() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarInt(_data_cellSizeRow);
  }
  if (cellSizeCol() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarInt(_data_cellSizeCol);
  }
  if (mergeToGuid() != nullptr) {
    _bb.writeVarUint(3);
    if (!_data_mergeToGuid->encode(_bb)) return false;
  }
  if (cellHAlign() != nullptr) {
    _bb.writeVarUint(4);
    _bb.writeVarUint(_data_cellHAlign);
  }
  if (cellVAlign() != nullptr) {
    _bb.writeVarUint(5);
    _bb.writeVarUint(_data_cellVAlign);
  }
  _bb.writeVarUint(0);
  return true;
}

bool ProdTableCell::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarInt(_data_cellSizeRow)) return false;
        set_cellSizeRow(_data_cellSizeRow);
        break;
      }
      case 2: {
        if (!_bb.readVarInt(_data_cellSizeCol)) return false;
        set_cellSizeCol(_data_cellSizeCol);
        break;
      }
      case 3: {
        _data_mergeToGuid = _pool.allocate<GUID>();
        if (!_data_mergeToGuid->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 4: {
        if (!_bb.readVarUint(_data_cellHAlign)) return false;
        set_cellHAlign(_data_cellHAlign);
        break;
      }
      case 5: {
        if (!_bb.readVarUint(_data_cellVAlign)) return false;
        set_cellVAlign(_data_cellVAlign);
        break;
      }
      default: {
        if (!_schema || !_schema->skipProdTableCellField(_bb, _type)) return false;
        break;
      }
    }
  }
}

FontName *ProdTextStyle::fontName() {
  return _data_fontName;
}

const FontName *ProdTextStyle::fontName() const {
  return _data_fontName;
}

void ProdTextStyle::set_fontName(FontName *value) {
  _data_fontName = value;
}

Paint *ProdTextStyle::fillPaint() {
  return _data_fillPaint;
}

const Paint *ProdTextStyle::fillPaint() const {
  return _data_fillPaint;
}

void ProdTextStyle::set_fillPaint(Paint *value) {
  _data_fillPaint = value;
}

float *ProdTextStyle::fontSize() {
  return _flags[0] & 4 ? &_data_fontSize : nullptr;
}

const float *ProdTextStyle::fontSize() const {
  return _flags[0] & 4 ? &_data_fontSize : nullptr;
}

void ProdTextStyle::set_fontSize(const float &value) {
  _flags[0] |= 4; _data_fontSize = value;
}

bool ProdTextStyle::encode(kiwi::ByteBuffer &_bb) {
  if (fontName() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_fontName->encode(_bb)) return false;
  }
  if (fillPaint() != nullptr) {
    _bb.writeVarUint(2);
    if (!_data_fillPaint->encode(_bb)) return false;
  }
  if (fontSize() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeVarFloat(_data_fontSize);
  }
  _bb.writeVarUint(0);
  return true;
}

bool ProdTextStyle::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_fontName = _pool.allocate<FontName>();
        if (!_data_fontName->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        _data_fillPaint = _pool.allocate<Paint>();
        if (!_data_fillPaint->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 3: {
        if (!_bb.readVarFloat(_data_fontSize)) return false;
        set_fontSize(_data_fontSize);
        break;
      }
      default: {
        if (!_schema || !_schema->skipProdTextStyleField(_bb, _type)) return false;
        break;
      }
    }
  }
}

int32_t *ProdScoreBar::numPath() {
  return _flags[0] & 1 ? &_data_numPath : nullptr;
}

const int32_t *ProdScoreBar::numPath() const {
  return _flags[0] & 1 ? &_data_numPath : nullptr;
}

void ProdScoreBar::set_numPath(const int32_t &value) {
  _flags[0] |= 1; _data_numPath = value;
}

float *ProdScoreBar::score() {
  return _flags[0] & 2 ? &_data_score : nullptr;
}

const float *ProdScoreBar::score() const {
  return _flags[0] & 2 ? &_data_score : nullptr;
}

void ProdScoreBar::set_score(const float &value) {
  _flags[0] |= 2; _data_score = value;
}

ProdScalingFactor *ProdScoreBar::scalingFactor() {
  return _data_scalingFactor;
}

const ProdScalingFactor *ProdScoreBar::scalingFactor() const {
  return _data_scalingFactor;
}

void ProdScoreBar::set_scalingFactor(ProdScalingFactor *value) {
  _data_scalingFactor = value;
}

bool ProdScoreBar::encode(kiwi::ByteBuffer &_bb) {
  if (numPath() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarInt(_data_numPath);
  }
  if (score() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarFloat(_data_score);
  }
  if (scalingFactor() != nullptr) {
    _bb.writeVarUint(3);
    if (!_data_scalingFactor->encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool ProdScoreBar::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarInt(_data_numPath)) return false;
        set_numPath(_data_numPath);
        break;
      }
      case 2: {
        if (!_bb.readVarFloat(_data_score)) return false;
        set_score(_data_score);
        break;
      }
      case 3: {
        _data_scalingFactor = _pool.allocate<ProdScalingFactor>();
        if (!_data_scalingFactor->decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipProdScoreBarField(_bb, _type)) return false;
        break;
      }
    }
  }
}

float *ProdDragBar::radius() {
  return _flags[0] & 1 ? &_data_radius : nullptr;
}

const float *ProdDragBar::radius() const {
  return _flags[0] & 1 ? &_data_radius : nullptr;
}

void ProdDragBar::set_radius(const float &value) {
  _flags[0] |= 1; _data_radius = value;
}

ProdScalingFactor *ProdDragBar::scalingFactor() {
  return _data_scalingFactor;
}

const ProdScalingFactor *ProdDragBar::scalingFactor() const {
  return _data_scalingFactor;
}

void ProdDragBar::set_scalingFactor(ProdScalingFactor *value) {
  _data_scalingFactor = value;
}

bool ProdDragBar::encode(kiwi::ByteBuffer &_bb) {
  if (radius() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarFloat(_data_radius);
  }
  if (scalingFactor() != nullptr) {
    _bb.writeVarUint(2);
    if (!_data_scalingFactor->encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool ProdDragBar::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarFloat(_data_radius)) return false;
        set_radius(_data_radius);
        break;
      }
      case 2: {
        _data_scalingFactor = _pool.allocate<ProdScalingFactor>();
        if (!_data_scalingFactor->decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipProdDragBarField(_bb, _type)) return false;
        break;
      }
    }
  }
}

float *ProdScalingFactor::wScalingFactor() {
  return _flags[0] & 1 ? &_data_wScalingFactor : nullptr;
}

const float *ProdScalingFactor::wScalingFactor() const {
  return _flags[0] & 1 ? &_data_wScalingFactor : nullptr;
}

void ProdScalingFactor::set_wScalingFactor(const float &value) {
  _flags[0] |= 1; _data_wScalingFactor = value;
}

float *ProdScalingFactor::hScalingFactor() {
  return _flags[0] & 2 ? &_data_hScalingFactor : nullptr;
}

const float *ProdScalingFactor::hScalingFactor() const {
  return _flags[0] & 2 ? &_data_hScalingFactor : nullptr;
}

void ProdScalingFactor::set_hScalingFactor(const float &value) {
  _flags[0] |= 2; _data_hScalingFactor = value;
}

bool ProdScalingFactor::encode(kiwi::ByteBuffer &_bb) {
  if (wScalingFactor() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarFloat(_data_wScalingFactor);
  }
  if (hScalingFactor() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarFloat(_data_hScalingFactor);
  }
  _bb.writeVarUint(0);
  return true;
}

bool ProdScalingFactor::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarFloat(_data_wScalingFactor)) return false;
        set_wScalingFactor(_data_wScalingFactor);
        break;
      }
      case 2: {
        if (!_bb.readVarFloat(_data_hScalingFactor)) return false;
        set_hScalingFactor(_data_hScalingFactor);
        break;
      }
      default: {
        if (!_schema || !_schema->skipProdScalingFactorField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::String *ProdTDCElementinfo::firstVar() {
  return _flags[0] & 1 ? &_data_firstVar : nullptr;
}

const kiwi::String *ProdTDCElementinfo::firstVar() const {
  return _flags[0] & 1 ? &_data_firstVar : nullptr;
}

void ProdTDCElementinfo::set_firstVar(const kiwi::String &value) {
  _flags[0] |= 1; _data_firstVar = value;
}

kiwi::String *ProdTDCElementinfo::secondVar() {
  return _flags[0] & 2 ? &_data_secondVar : nullptr;
}

const kiwi::String *ProdTDCElementinfo::secondVar() const {
  return _flags[0] & 2 ? &_data_secondVar : nullptr;
}

void ProdTDCElementinfo::set_secondVar(const kiwi::String &value) {
  _flags[0] |= 2; _data_secondVar = value;
}

float *ProdTDCElementinfo::value() {
  return _flags[0] & 4 ? &_data_value : nullptr;
}

const float *ProdTDCElementinfo::value() const {
  return _flags[0] & 4 ? &_data_value : nullptr;
}

void ProdTDCElementinfo::set_value(const float &value) {
  _flags[0] |= 4; _data_value = value;
}

bool ProdTDCElementinfo::encode(kiwi::ByteBuffer &_bb) {
  if (firstVar() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeString(_data_firstVar.c_str());
  }
  if (secondVar() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeString(_data_secondVar.c_str());
  }
  if (value() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeVarFloat(_data_value);
  }
  _bb.writeVarUint(0);
  return true;
}

bool ProdTDCElementinfo::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readString(_data_firstVar, _pool)) return false;
        set_firstVar(_data_firstVar);
        break;
      }
      case 2: {
        if (!_bb.readString(_data_secondVar, _pool)) return false;
        set_secondVar(_data_secondVar);
        break;
      }
      case 3: {
        if (!_bb.readVarFloat(_data_value)) return false;
        set_value(_data_value);
        break;
      }
      default: {
        if (!_schema || !_schema->skipProdTDCElementinfoField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::Array<ProdTDCElementinfo> *ProdTwoDimChart::TDCElementInfo() {
  return _flags[0] & 1 ? &_data_TDCElementInfo : nullptr;
}

const kiwi::Array<ProdTDCElementinfo> *ProdTwoDimChart::TDCElementInfo() const {
  return _flags[0] & 1 ? &_data_TDCElementInfo : nullptr;
}

kiwi::Array<ProdTDCElementinfo> &ProdTwoDimChart::set_TDCElementInfo(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 1; return _data_TDCElementInfo = pool.array<ProdTDCElementinfo>(count);
}

bool *ProdTwoDimChart::axisSwitch() {
  return _flags[0] & 2 ? &_data_axisSwitch : nullptr;
}

const bool *ProdTwoDimChart::axisSwitch() const {
  return _flags[0] & 2 ? &_data_axisSwitch : nullptr;
}

void ProdTwoDimChart::set_axisSwitch(const bool &value) {
  _flags[0] |= 2; _data_axisSwitch = value;
}

bool *ProdTwoDimChart::gridSwitch() {
  return _flags[0] & 4 ? &_data_gridSwitch : nullptr;
}

const bool *ProdTwoDimChart::gridSwitch() const {
  return _flags[0] & 4 ? &_data_gridSwitch : nullptr;
}

void ProdTwoDimChart::set_gridSwitch(const bool &value) {
  _flags[0] |= 4; _data_gridSwitch = value;
}

bool *ProdTwoDimChart::titleSwitch() {
  return _flags[0] & 8 ? &_data_titleSwitch : nullptr;
}

const bool *ProdTwoDimChart::titleSwitch() const {
  return _flags[0] & 8 ? &_data_titleSwitch : nullptr;
}

void ProdTwoDimChart::set_titleSwitch(const bool &value) {
  _flags[0] |= 8; _data_titleSwitch = value;
}

bool *ProdTwoDimChart::legendSwitch() {
  return _flags[0] & 16 ? &_data_legendSwitch : nullptr;
}

const bool *ProdTwoDimChart::legendSwitch() const {
  return _flags[0] & 16 ? &_data_legendSwitch : nullptr;
}

void ProdTwoDimChart::set_legendSwitch(const bool &value) {
  _flags[0] |= 16; _data_legendSwitch = value;
}

bool *ProdTwoDimChart::dataLableSwitch() {
  return _flags[0] & 32 ? &_data_dataLableSwitch : nullptr;
}

const bool *ProdTwoDimChart::dataLableSwitch() const {
  return _flags[0] & 32 ? &_data_dataLableSwitch : nullptr;
}

void ProdTwoDimChart::set_dataLableSwitch(const bool &value) {
  _flags[0] |= 32; _data_dataLableSwitch = value;
}

bool *ProdTwoDimChart::dataWinSwitch() {
  return _flags[0] & 64 ? &_data_dataWinSwitch : nullptr;
}

const bool *ProdTwoDimChart::dataWinSwitch() const {
  return _flags[0] & 64 ? &_data_dataWinSwitch : nullptr;
}

void ProdTwoDimChart::set_dataWinSwitch(const bool &value) {
  _flags[0] |= 64; _data_dataWinSwitch = value;
}

int32_t *ProdTwoDimChart::legendDir() {
  return _flags[0] & 128 ? &_data_legendDir : nullptr;
}

const int32_t *ProdTwoDimChart::legendDir() const {
  return _flags[0] & 128 ? &_data_legendDir : nullptr;
}

void ProdTwoDimChart::set_legendDir(const int32_t &value) {
  _flags[0] |= 128; _data_legendDir = value;
}

int32_t *ProdTwoDimChart::colNum() {
  return _flags[0] & 256 ? &_data_colNum : nullptr;
}

const int32_t *ProdTwoDimChart::colNum() const {
  return _flags[0] & 256 ? &_data_colNum : nullptr;
}

void ProdTwoDimChart::set_colNum(const int32_t &value) {
  _flags[0] |= 256; _data_colNum = value;
}

int32_t *ProdTwoDimChart::rowNum() {
  return _flags[0] & 512 ? &_data_rowNum : nullptr;
}

const int32_t *ProdTwoDimChart::rowNum() const {
  return _flags[0] & 512 ? &_data_rowNum : nullptr;
}

void ProdTwoDimChart::set_rowNum(const int32_t &value) {
  _flags[0] |= 512; _data_rowNum = value;
}

int32_t *ProdTwoDimChart::chartMode() {
  return _flags[0] & 1024 ? &_data_chartMode : nullptr;
}

const int32_t *ProdTwoDimChart::chartMode() const {
  return _flags[0] & 1024 ? &_data_chartMode : nullptr;
}

void ProdTwoDimChart::set_chartMode(const int32_t &value) {
  _flags[0] |= 1024; _data_chartMode = value;
}

kiwi::Array<float> *ProdTwoDimChart::drawArea() {
  return _flags[0] & 2048 ? &_data_drawArea : nullptr;
}

const kiwi::Array<float> *ProdTwoDimChart::drawArea() const {
  return _flags[0] & 2048 ? &_data_drawArea : nullptr;
}

kiwi::Array<float> &ProdTwoDimChart::set_drawArea(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 2048; return _data_drawArea = pool.array<float>(count);
}

kiwi::Array<float> *ProdTwoDimChart::legendSymPos() {
  return _flags[0] & 4096 ? &_data_legendSymPos : nullptr;
}

const kiwi::Array<float> *ProdTwoDimChart::legendSymPos() const {
  return _flags[0] & 4096 ? &_data_legendSymPos : nullptr;
}

kiwi::Array<float> &ProdTwoDimChart::set_legendSymPos(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 4096; return _data_legendSymPos = pool.array<float>(count);
}

kiwi::Array<float> *ProdTwoDimChart::axisScale() {
  return _flags[0] & 8192 ? &_data_axisScale : nullptr;
}

const kiwi::Array<float> *ProdTwoDimChart::axisScale() const {
  return _flags[0] & 8192 ? &_data_axisScale : nullptr;
}

kiwi::Array<float> &ProdTwoDimChart::set_axisScale(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 8192; return _data_axisScale = pool.array<float>(count);
}

bool ProdTwoDimChart::encode(kiwi::ByteBuffer &_bb) {
  if (TDCElementInfo() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(_data_TDCElementInfo.size());
    for (ProdTDCElementinfo &_it : _data_TDCElementInfo) if (!_it.encode(_bb)) return false;
  }
  if (axisSwitch() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeByte(_data_axisSwitch);
  }
  if (gridSwitch() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeByte(_data_gridSwitch);
  }
  if (titleSwitch() != nullptr) {
    _bb.writeVarUint(4);
    _bb.writeByte(_data_titleSwitch);
  }
  if (legendSwitch() != nullptr) {
    _bb.writeVarUint(5);
    _bb.writeByte(_data_legendSwitch);
  }
  if (dataLableSwitch() != nullptr) {
    _bb.writeVarUint(6);
    _bb.writeByte(_data_dataLableSwitch);
  }
  if (dataWinSwitch() != nullptr) {
    _bb.writeVarUint(7);
    _bb.writeByte(_data_dataWinSwitch);
  }
  if (legendDir() != nullptr) {
    _bb.writeVarUint(8);
    _bb.writeVarInt(_data_legendDir);
  }
  if (colNum() != nullptr) {
    _bb.writeVarUint(9);
    _bb.writeVarInt(_data_colNum);
  }
  if (rowNum() != nullptr) {
    _bb.writeVarUint(10);
    _bb.writeVarInt(_data_rowNum);
  }
  if (chartMode() != nullptr) {
    _bb.writeVarUint(11);
    _bb.writeVarInt(_data_chartMode);
  }
  if (drawArea() != nullptr) {
    _bb.writeVarUint(12);
    _bb.writeVarUint(_data_drawArea.size());
    for (float &_it : _data_drawArea) _bb.writeVarFloat(_it);
  }
  if (legendSymPos() != nullptr) {
    _bb.writeVarUint(13);
    _bb.writeVarUint(_data_legendSymPos.size());
    for (float &_it : _data_legendSymPos) _bb.writeVarFloat(_it);
  }
  if (axisScale() != nullptr) {
    _bb.writeVarUint(14);
    _bb.writeVarUint(_data_axisScale.size());
    for (float &_it : _data_axisScale) _bb.writeVarFloat(_it);
  }
  _bb.writeVarUint(0);
  return true;
}

bool ProdTwoDimChart::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(_count)) return false;
        for (ProdTDCElementinfo &_it : set_TDCElementInfo(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        if (!_bb.readByte(_data_axisSwitch)) return false;
        set_axisSwitch(_data_axisSwitch);
        break;
      }
      case 3: {
        if (!_bb.readByte(_data_gridSwitch)) return false;
        set_gridSwitch(_data_gridSwitch);
        break;
      }
      case 4: {
        if (!_bb.readByte(_data_titleSwitch)) return false;
        set_titleSwitch(_data_titleSwitch);
        break;
      }
      case 5: {
        if (!_bb.readByte(_data_legendSwitch)) return false;
        set_legendSwitch(_data_legendSwitch);
        break;
      }
      case 6: {
        if (!_bb.readByte(_data_dataLableSwitch)) return false;
        set_dataLableSwitch(_data_dataLableSwitch);
        break;
      }
      case 7: {
        if (!_bb.readByte(_data_dataWinSwitch)) return false;
        set_dataWinSwitch(_data_dataWinSwitch);
        break;
      }
      case 8: {
        if (!_bb.readVarInt(_data_legendDir)) return false;
        set_legendDir(_data_legendDir);
        break;
      }
      case 9: {
        if (!_bb.readVarInt(_data_colNum)) return false;
        set_colNum(_data_colNum);
        break;
      }
      case 10: {
        if (!_bb.readVarInt(_data_rowNum)) return false;
        set_rowNum(_data_rowNum);
        break;
      }
      case 11: {
        if (!_bb.readVarInt(_data_chartMode)) return false;
        set_chartMode(_data_chartMode);
        break;
      }
      case 12: {
        if (!_bb.readVarUint(_count)) return false;
        for (float &_it : set_drawArea(_pool, _count)) if (!_bb.readVarFloat(_it)) return false;
        break;
      }
      case 13: {
        if (!_bb.readVarUint(_count)) return false;
        for (float &_it : set_legendSymPos(_pool, _count)) if (!_bb.readVarFloat(_it)) return false;
        break;
      }
      case 14: {
        if (!_bb.readVarUint(_count)) return false;
        for (float &_it : set_axisScale(_pool, _count)) if (!_bb.readVarFloat(_it)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipProdTwoDimChartField(_bb, _type)) return false;
        break;
      }
    }
  }
}

Axis *Guide::axis() {
  return _flags[0] & 1 ? &_data_axis : nullptr;
}

const Axis *Guide::axis() const {
  return _flags[0] & 1 ? &_data_axis : nullptr;
}

void Guide::set_axis(const Axis &value) {
  _flags[0] |= 1; _data_axis = value;
}

float *Guide::offset() {
  return _flags[0] & 2 ? &_data_offset : nullptr;
}

const float *Guide::offset() const {
  return _flags[0] & 2 ? &_data_offset : nullptr;
}

void Guide::set_offset(const float &value) {
  _flags[0] |= 2; _data_offset = value;
}

GUID *Guide::guid() {
  return _data_guid;
}

const GUID *Guide::guid() const {
  return _data_guid;
}

void Guide::set_guid(GUID *value) {
  _data_guid = value;
}

float *Guide::distance() {
  return _flags[0] & 8 ? &_data_distance : nullptr;
}

const float *Guide::distance() const {
  return _flags[0] & 8 ? &_data_distance : nullptr;
}

void Guide::set_distance(const float &value) {
  _flags[0] |= 8; _data_distance = value;
}

bool Guide::encode(kiwi::ByteBuffer &_bb) {
  if (axis() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(static_cast<uint32_t>(_data_axis));
  }
  if (offset() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarFloat(_data_offset);
  }
  if (guid() != nullptr) {
    _bb.writeVarUint(3);
    if (!_data_guid->encode(_bb)) return false;
  }
  if (distance() != nullptr) {
    _bb.writeVarUint(4);
    _bb.writeVarFloat(_data_distance);
  }
  _bb.writeVarUint(0);
  return true;
}

bool Guide::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_axis))) return false;
        set_axis(_data_axis);
        break;
      }
      case 2: {
        if (!_bb.readVarFloat(_data_offset)) return false;
        set_offset(_data_offset);
        break;
      }
      case 3: {
        _data_guid = _pool.allocate<GUID>();
        if (!_data_guid->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 4: {
        if (!_bb.readVarFloat(_data_distance)) return false;
        set_distance(_data_distance);
        break;
      }
      default: {
        if (!_schema || !_schema->skipGuideField(_bb, _type)) return false;
        break;
      }
    }
  }
}

OverlayBackgroundType *OverlayBackgroundAppearance::backgroundType() {
  return _flags[0] & 1 ? &_data_backgroundType : nullptr;
}

const OverlayBackgroundType *OverlayBackgroundAppearance::backgroundType() const {
  return _flags[0] & 1 ? &_data_backgroundType : nullptr;
}

void OverlayBackgroundAppearance::set_backgroundType(const OverlayBackgroundType &value) {
  _flags[0] |= 1; _data_backgroundType = value;
}

Color *OverlayBackgroundAppearance::backgroundColor() {
  return _data_backgroundColor;
}

const Color *OverlayBackgroundAppearance::backgroundColor() const {
  return _data_backgroundColor;
}

void OverlayBackgroundAppearance::set_backgroundColor(Color *value) {
  _data_backgroundColor = value;
}

bool OverlayBackgroundAppearance::encode(kiwi::ByteBuffer &_bb) {
  if (backgroundType() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(static_cast<uint32_t>(_data_backgroundType));
  }
  if (backgroundColor() != nullptr) {
    _bb.writeVarUint(2);
    if (!_data_backgroundColor->encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool OverlayBackgroundAppearance::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_backgroundType))) return false;
        set_backgroundType(_data_backgroundType);
        break;
      }
      case 2: {
        _data_backgroundColor = _pool.allocate<Color>();
        if (!_data_backgroundColor->decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipOverlayBackgroundAppearanceField(_bb, _type)) return false;
        break;
      }
    }
  }
}

float *Number::value() {
  return _flags[0] & 1 ? &_data_value : nullptr;
}

const float *Number::value() const {
  return _flags[0] & 1 ? &_data_value : nullptr;
}

void Number::set_value(const float &value) {
  _flags[0] |= 1; _data_value = value;
}

NumberUnits *Number::units() {
  return _flags[0] & 2 ? &_data_units : nullptr;
}

const NumberUnits *Number::units() const {
  return _flags[0] & 2 ? &_data_units : nullptr;
}

void Number::set_units(const NumberUnits &value) {
  _flags[0] |= 2; _data_units = value;
}

bool Number::encode(kiwi::ByteBuffer &_bb) {
  if (value() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarFloat(_data_value);
  }
  if (units() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarUint(static_cast<uint32_t>(_data_units));
  }
  _bb.writeVarUint(0);
  return true;
}

bool Number::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarFloat(_data_value)) return false;
        set_value(_data_value);
        break;
      }
      case 2: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_units))) return false;
        set_units(_data_units);
        break;
      }
      default: {
        if (!_schema || !_schema->skipNumberField(_bb, _type)) return false;
        break;
      }
    }
  }
}

GUID *ParentIndex::guid() {
  return _data_guid;
}

const GUID *ParentIndex::guid() const {
  return _data_guid;
}

void ParentIndex::set_guid(GUID *value) {
  _data_guid = value;
}

kiwi::String *ParentIndex::position() {
  return _flags[0] & 2 ? &_data_position : nullptr;
}

const kiwi::String *ParentIndex::position() const {
  return _flags[0] & 2 ? &_data_position : nullptr;
}

void ParentIndex::set_position(const kiwi::String &value) {
  _flags[0] |= 2; _data_position = value;
}

bool ParentIndex::encode(kiwi::ByteBuffer &_bb) {
  if (guid() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_guid->encode(_bb)) return false;
  }
  if (position() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeString(_data_position.c_str());
  }
  _bb.writeVarUint(0);
  return true;
}

bool ParentIndex::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_guid = _pool.allocate<GUID>();
        if (!_data_guid->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        if (!_bb.readString(_data_position, _pool)) return false;
        set_position(_data_position);
        break;
      }
      default: {
        if (!_schema || !_schema->skipParentIndexField(_bb, _type)) return false;
        break;
      }
    }
  }
}

uint32_t *UserInfo::sessionID() {
  return _flags[0] & 1 ? &_data_sessionID : nullptr;
}

const uint32_t *UserInfo::sessionID() const {
  return _flags[0] & 1 ? &_data_sessionID : nullptr;
}

void UserInfo::set_sessionID(const uint32_t &value) {
  _flags[0] |= 1; _data_sessionID = value;
}

bool *UserInfo::connected() {
  return _flags[0] & 2 ? &_data_connected : nullptr;
}

const bool *UserInfo::connected() const {
  return _flags[0] & 2 ? &_data_connected : nullptr;
}

void UserInfo::set_connected(const bool &value) {
  _flags[0] |= 2; _data_connected = value;
}

kiwi::String *UserInfo::name() {
  return _flags[0] & 4 ? &_data_name : nullptr;
}

const kiwi::String *UserInfo::name() const {
  return _flags[0] & 4 ? &_data_name : nullptr;
}

void UserInfo::set_name(const kiwi::String &value) {
  _flags[0] |= 4; _data_name = value;
}

Color *UserInfo::color() {
  return _data_color;
}

const Color *UserInfo::color() const {
  return _data_color;
}

void UserInfo::set_color(Color *value) {
  _data_color = value;
}

kiwi::String *UserInfo::imageURL() {
  return _flags[0] & 16 ? &_data_imageURL : nullptr;
}

const kiwi::String *UserInfo::imageURL() const {
  return _flags[0] & 16 ? &_data_imageURL : nullptr;
}

void UserInfo::set_imageURL(const kiwi::String &value) {
  _flags[0] |= 16; _data_imageURL = value;
}

Viewport *UserInfo::viewport() {
  return _data_viewport;
}

const Viewport *UserInfo::viewport() const {
  return _data_viewport;
}

void UserInfo::set_viewport(Viewport *value) {
  _data_viewport = value;
}

Mouse *UserInfo::mouse() {
  return _data_mouse;
}

const Mouse *UserInfo::mouse() const {
  return _data_mouse;
}

void UserInfo::set_mouse(Mouse *value) {
  _data_mouse = value;
}

kiwi::Array<GUID> *UserInfo::selection() {
  return _flags[0] & 128 ? &_data_selection : nullptr;
}

const kiwi::Array<GUID> *UserInfo::selection() const {
  return _flags[0] & 128 ? &_data_selection : nullptr;
}

kiwi::Array<GUID> &UserInfo::set_selection(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 128; return _data_selection = pool.array<GUID>(count);
}

kiwi::Array<uint32_t> *UserInfo::observing() {
  return _flags[0] & 256 ? &_data_observing : nullptr;
}

const kiwi::Array<uint32_t> *UserInfo::observing() const {
  return _flags[0] & 256 ? &_data_observing : nullptr;
}

kiwi::Array<uint32_t> &UserInfo::set_observing(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 256; return _data_observing = pool.array<uint32_t>(count);
}

kiwi::String *UserInfo::deviceName() {
  return _flags[0] & 512 ? &_data_deviceName : nullptr;
}

const kiwi::String *UserInfo::deviceName() const {
  return _flags[0] & 512 ? &_data_deviceName : nullptr;
}

void UserInfo::set_deviceName(const kiwi::String &value) {
  _flags[0] |= 512; _data_deviceName = value;
}

kiwi::Array<Click> *UserInfo::recentClicks() {
  return _flags[0] & 1024 ? &_data_recentClicks : nullptr;
}

const kiwi::Array<Click> *UserInfo::recentClicks() const {
  return _flags[0] & 1024 ? &_data_recentClicks : nullptr;
}

kiwi::Array<Click> &UserInfo::set_recentClicks(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 1024; return _data_recentClicks = pool.array<Click>(count);
}

kiwi::Array<ScrollPosition> *UserInfo::scrollPositions() {
  return _flags[0] & 2048 ? &_data_scrollPositions : nullptr;
}

const kiwi::Array<ScrollPosition> *UserInfo::scrollPositions() const {
  return _flags[0] & 2048 ? &_data_scrollPositions : nullptr;
}

kiwi::Array<ScrollPosition> &UserInfo::set_scrollPositions(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 2048; return _data_scrollPositions = pool.array<ScrollPosition>(count);
}

kiwi::String *UserInfo::userID() {
  return _flags[0] & 4096 ? &_data_userID : nullptr;
}

const kiwi::String *UserInfo::userID() const {
  return _flags[0] & 4096 ? &_data_userID : nullptr;
}

void UserInfo::set_userID(const kiwi::String &value) {
  _flags[0] |= 4096; _data_userID = value;
}

GUID *UserInfo::lastTriggeredHotspot() {
  return _data_lastTriggeredHotspot;
}

const GUID *UserInfo::lastTriggeredHotspot() const {
  return _data_lastTriggeredHotspot;
}

void UserInfo::set_lastTriggeredHotspot(GUID *value) {
  _data_lastTriggeredHotspot = value;
}

GUID *UserInfo::lastTriggeredPrototypeInteractionID() {
  return _data_lastTriggeredPrototypeInteractionID;
}

const GUID *UserInfo::lastTriggeredPrototypeInteractionID() const {
  return _data_lastTriggeredPrototypeInteractionID;
}

void UserInfo::set_lastTriggeredPrototypeInteractionID(GUID *value) {
  _data_lastTriggeredPrototypeInteractionID = value;
}

kiwi::Array<TriggeredOverlayData> *UserInfo::triggeredOverlaysData() {
  return _flags[0] & 32768 ? &_data_triggeredOverlaysData : nullptr;
}

const kiwi::Array<TriggeredOverlayData> *UserInfo::triggeredOverlaysData() const {
  return _flags[0] & 32768 ? &_data_triggeredOverlaysData : nullptr;
}

kiwi::Array<TriggeredOverlayData> &UserInfo::set_triggeredOverlaysData(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 32768; return _data_triggeredOverlaysData = pool.array<TriggeredOverlayData>(count);
}

Spotlight *UserInfo::spotlight() {
  return _data_spotlight;
}

const Spotlight *UserInfo::spotlight() const {
  return _data_spotlight;
}

void UserInfo::set_spotlight(Spotlight *value) {
  _data_spotlight = value;
}

GUID *UserInfo::lastTriggeredFlowStartPointId() {
  return _data_lastTriggeredFlowStartPointId;
}

const GUID *UserInfo::lastTriggeredFlowStartPointId() const {
  return _data_lastTriggeredFlowStartPointId;
}

void UserInfo::set_lastTriggeredFlowStartPointId(GUID *value) {
  _data_lastTriggeredFlowStartPointId = value;
}

bool UserInfo::encode(kiwi::ByteBuffer &_bb) {
  if (sessionID() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(_data_sessionID);
  }
  if (connected() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeByte(_data_connected);
  }
  if (name() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeString(_data_name.c_str());
  }
  if (color() != nullptr) {
    _bb.writeVarUint(4);
    if (!_data_color->encode(_bb)) return false;
  }
  if (imageURL() != nullptr) {
    _bb.writeVarUint(5);
    _bb.writeString(_data_imageURL.c_str());
  }
  if (viewport() != nullptr) {
    _bb.writeVarUint(6);
    if (!_data_viewport->encode(_bb)) return false;
  }
  if (mouse() != nullptr) {
    _bb.writeVarUint(7);
    if (!_data_mouse->encode(_bb)) return false;
  }
  if (selection() != nullptr) {
    _bb.writeVarUint(8);
    _bb.writeVarUint(_data_selection.size());
    for (GUID &_it : _data_selection) if (!_it.encode(_bb)) return false;
  }
  if (observing() != nullptr) {
    _bb.writeVarUint(9);
    _bb.writeVarUint(_data_observing.size());
    for (uint32_t &_it : _data_observing) _bb.writeVarUint(_it);
  }
  if (deviceName() != nullptr) {
    _bb.writeVarUint(10);
    _bb.writeString(_data_deviceName.c_str());
  }
  if (recentClicks() != nullptr) {
    _bb.writeVarUint(11);
    _bb.writeVarUint(_data_recentClicks.size());
    for (Click &_it : _data_recentClicks) if (!_it.encode(_bb)) return false;
  }
  if (scrollPositions() != nullptr) {
    _bb.writeVarUint(12);
    _bb.writeVarUint(_data_scrollPositions.size());
    for (ScrollPosition &_it : _data_scrollPositions) if (!_it.encode(_bb)) return false;
  }
  if (userID() != nullptr) {
    _bb.writeVarUint(13);
    _bb.writeString(_data_userID.c_str());
  }
  if (lastTriggeredHotspot() != nullptr) {
    _bb.writeVarUint(14);
    if (!_data_lastTriggeredHotspot->encode(_bb)) return false;
  }
  if (lastTriggeredPrototypeInteractionID() != nullptr) {
    _bb.writeVarUint(15);
    if (!_data_lastTriggeredPrototypeInteractionID->encode(_bb)) return false;
  }
  if (triggeredOverlaysData() != nullptr) {
    _bb.writeVarUint(16);
    _bb.writeVarUint(_data_triggeredOverlaysData.size());
    for (TriggeredOverlayData &_it : _data_triggeredOverlaysData) if (!_it.encode(_bb)) return false;
  }
  if (spotlight() != nullptr) {
    _bb.writeVarUint(17);
    if (!_data_spotlight->encode(_bb)) return false;
  }
  if (lastTriggeredFlowStartPointId() != nullptr) {
    _bb.writeVarUint(18);
    if (!_data_lastTriggeredFlowStartPointId->encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool UserInfo::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(_data_sessionID)) return false;
        set_sessionID(_data_sessionID);
        break;
      }
      case 2: {
        if (!_bb.readByte(_data_connected)) return false;
        set_connected(_data_connected);
        break;
      }
      case 3: {
        if (!_bb.readString(_data_name, _pool)) return false;
        set_name(_data_name);
        break;
      }
      case 4: {
        _data_color = _pool.allocate<Color>();
        if (!_data_color->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 5: {
        if (!_bb.readString(_data_imageURL, _pool)) return false;
        set_imageURL(_data_imageURL);
        break;
      }
      case 6: {
        _data_viewport = _pool.allocate<Viewport>();
        if (!_data_viewport->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 7: {
        _data_mouse = _pool.allocate<Mouse>();
        if (!_data_mouse->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 8: {
        if (!_bb.readVarUint(_count)) return false;
        for (GUID &_it : set_selection(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 9: {
        if (!_bb.readVarUint(_count)) return false;
        for (uint32_t &_it : set_observing(_pool, _count)) if (!_bb.readVarUint(_it)) return false;
        break;
      }
      case 10: {
        if (!_bb.readString(_data_deviceName, _pool)) return false;
        set_deviceName(_data_deviceName);
        break;
      }
      case 11: {
        if (!_bb.readVarUint(_count)) return false;
        for (Click &_it : set_recentClicks(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 12: {
        if (!_bb.readVarUint(_count)) return false;
        for (ScrollPosition &_it : set_scrollPositions(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 13: {
        if (!_bb.readString(_data_userID, _pool)) return false;
        set_userID(_data_userID);
        break;
      }
      case 14: {
        _data_lastTriggeredHotspot = _pool.allocate<GUID>();
        if (!_data_lastTriggeredHotspot->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 15: {
        _data_lastTriggeredPrototypeInteractionID = _pool.allocate<GUID>();
        if (!_data_lastTriggeredPrototypeInteractionID->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 16: {
        if (!_bb.readVarUint(_count)) return false;
        for (TriggeredOverlayData &_it : set_triggeredOverlaysData(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 17: {
        _data_spotlight = _pool.allocate<Spotlight>();
        if (!_data_spotlight->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 18: {
        _data_lastTriggeredFlowStartPointId = _pool.allocate<GUID>();
        if (!_data_lastTriggeredFlowStartPointId->decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipUserInfoField(_bb, _type)) return false;
        break;
      }
    }
  }
}

Rect *Viewport::canvasSpaceBounds() {
  return _data_canvasSpaceBounds;
}

const Rect *Viewport::canvasSpaceBounds() const {
  return _data_canvasSpaceBounds;
}

void Viewport::set_canvasSpaceBounds(Rect *value) {
  _data_canvasSpaceBounds = value;
}

bool *Viewport::pixelPreview() {
  return _flags[0] & 2 ? &_data_pixelPreview : nullptr;
}

const bool *Viewport::pixelPreview() const {
  return _flags[0] & 2 ? &_data_pixelPreview : nullptr;
}

void Viewport::set_pixelPreview(const bool &value) {
  _flags[0] |= 2; _data_pixelPreview = value;
}

float *Viewport::pixelDensity() {
  return _flags[0] & 4 ? &_data_pixelDensity : nullptr;
}

const float *Viewport::pixelDensity() const {
  return _flags[0] & 4 ? &_data_pixelDensity : nullptr;
}

void Viewport::set_pixelDensity(const float &value) {
  _flags[0] |= 4; _data_pixelDensity = value;
}

GUID *Viewport::canvasGuid() {
  return _data_canvasGuid;
}

const GUID *Viewport::canvasGuid() const {
  return _data_canvasGuid;
}

void Viewport::set_canvasGuid(GUID *value) {
  _data_canvasGuid = value;
}

bool Viewport::encode(kiwi::ByteBuffer &_bb) {
  if (canvasSpaceBounds() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_canvasSpaceBounds->encode(_bb)) return false;
  }
  if (pixelPreview() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeByte(_data_pixelPreview);
  }
  if (pixelDensity() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeVarFloat(_data_pixelDensity);
  }
  if (canvasGuid() != nullptr) {
    _bb.writeVarUint(4);
    if (!_data_canvasGuid->encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool Viewport::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_canvasSpaceBounds = _pool.allocate<Rect>();
        if (!_data_canvasSpaceBounds->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        if (!_bb.readByte(_data_pixelPreview)) return false;
        set_pixelPreview(_data_pixelPreview);
        break;
      }
      case 3: {
        if (!_bb.readVarFloat(_data_pixelDensity)) return false;
        set_pixelDensity(_data_pixelDensity);
        break;
      }
      case 4: {
        _data_canvasGuid = _pool.allocate<GUID>();
        if (!_data_canvasGuid->decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipViewportField(_bb, _type)) return false;
        break;
      }
    }
  }
}

MouseCursor *Mouse::cursor() {
  return _flags[0] & 1 ? &_data_cursor : nullptr;
}

const MouseCursor *Mouse::cursor() const {
  return _flags[0] & 1 ? &_data_cursor : nullptr;
}

void Mouse::set_cursor(const MouseCursor &value) {
  _flags[0] |= 1; _data_cursor = value;
}

Vector *Mouse::canvasSpaceLocation() {
  return _data_canvasSpaceLocation;
}

const Vector *Mouse::canvasSpaceLocation() const {
  return _data_canvasSpaceLocation;
}

void Mouse::set_canvasSpaceLocation(Vector *value) {
  _data_canvasSpaceLocation = value;
}

Rect *Mouse::canvasSpaceSelectionBox() {
  return _data_canvasSpaceSelectionBox;
}

const Rect *Mouse::canvasSpaceSelectionBox() const {
  return _data_canvasSpaceSelectionBox;
}

void Mouse::set_canvasSpaceSelectionBox(Rect *value) {
  _data_canvasSpaceSelectionBox = value;
}

GUID *Mouse::canvasGuid() {
  return _data_canvasGuid;
}

const GUID *Mouse::canvasGuid() const {
  return _data_canvasGuid;
}

void Mouse::set_canvasGuid(GUID *value) {
  _data_canvasGuid = value;
}

bool Mouse::encode(kiwi::ByteBuffer &_bb) {
  if (cursor() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(static_cast<uint32_t>(_data_cursor));
  }
  if (canvasSpaceLocation() != nullptr) {
    _bb.writeVarUint(2);
    if (!_data_canvasSpaceLocation->encode(_bb)) return false;
  }
  if (canvasSpaceSelectionBox() != nullptr) {
    _bb.writeVarUint(3);
    if (!_data_canvasSpaceSelectionBox->encode(_bb)) return false;
  }
  if (canvasGuid() != nullptr) {
    _bb.writeVarUint(4);
    if (!_data_canvasGuid->encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool Mouse::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_cursor))) return false;
        set_cursor(_data_cursor);
        break;
      }
      case 2: {
        _data_canvasSpaceLocation = _pool.allocate<Vector>();
        if (!_data_canvasSpaceLocation->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 3: {
        _data_canvasSpaceSelectionBox = _pool.allocate<Rect>();
        if (!_data_canvasSpaceSelectionBox->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 4: {
        _data_canvasGuid = _pool.allocate<GUID>();
        if (!_data_canvasGuid->decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipMouseField(_bb, _type)) return false;
        break;
      }
    }
  }
}

uint32_t *Click::id() {
  return _flags[0] & 1 ? &_data_id : nullptr;
}

const uint32_t *Click::id() const {
  return _flags[0] & 1 ? &_data_id : nullptr;
}

void Click::set_id(const uint32_t &value) {
  _flags[0] |= 1; _data_id = value;
}

Vector *Click::point() {
  return _data_point;
}

const Vector *Click::point() const {
  return _data_point;
}

void Click::set_point(Vector *value) {
  _data_point = value;
}

bool Click::encode(kiwi::ByteBuffer &_bb) {
  if (id() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(_data_id);
  }
  if (point() != nullptr) {
    _bb.writeVarUint(2);
    if (!_data_point->encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool Click::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(_data_id)) return false;
        set_id(_data_id);
        break;
      }
      case 2: {
        _data_point = _pool.allocate<Vector>();
        if (!_data_point->decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipClickField(_bb, _type)) return false;
        break;
      }
    }
  }
}

GUID *ScrollPosition::node() {
  return _data_node;
}

const GUID *ScrollPosition::node() const {
  return _data_node;
}

void ScrollPosition::set_node(GUID *value) {
  _data_node = value;
}

Vector *ScrollPosition::scrollOffset() {
  return _data_scrollOffset;
}

const Vector *ScrollPosition::scrollOffset() const {
  return _data_scrollOffset;
}

void ScrollPosition::set_scrollOffset(Vector *value) {
  _data_scrollOffset = value;
}

bool ScrollPosition::encode(kiwi::ByteBuffer &_bb) {
  if (node() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_node->encode(_bb)) return false;
  }
  if (scrollOffset() != nullptr) {
    _bb.writeVarUint(2);
    if (!_data_scrollOffset->encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool ScrollPosition::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_node = _pool.allocate<GUID>();
        if (!_data_node->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        _data_scrollOffset = _pool.allocate<Vector>();
        if (!_data_scrollOffset->decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipScrollPositionField(_bb, _type)) return false;
        break;
      }
    }
  }
}

GUID *TriggeredOverlayData::overlayGuid() {
  return _data_overlayGuid;
}

const GUID *TriggeredOverlayData::overlayGuid() const {
  return _data_overlayGuid;
}

void TriggeredOverlayData::set_overlayGuid(GUID *value) {
  _data_overlayGuid = value;
}

GUID *TriggeredOverlayData::hotspotGuid() {
  return _data_hotspotGuid;
}

const GUID *TriggeredOverlayData::hotspotGuid() const {
  return _data_hotspotGuid;
}

void TriggeredOverlayData::set_hotspotGuid(GUID *value) {
  _data_hotspotGuid = value;
}

GUID *TriggeredOverlayData::swapGuid() {
  return _data_swapGuid;
}

const GUID *TriggeredOverlayData::swapGuid() const {
  return _data_swapGuid;
}

void TriggeredOverlayData::set_swapGuid(GUID *value) {
  _data_swapGuid = value;
}

GUID *TriggeredOverlayData::prototypeInteractionGuid() {
  return _data_prototypeInteractionGuid;
}

const GUID *TriggeredOverlayData::prototypeInteractionGuid() const {
  return _data_prototypeInteractionGuid;
}

void TriggeredOverlayData::set_prototypeInteractionGuid(GUID *value) {
  _data_prototypeInteractionGuid = value;
}

bool TriggeredOverlayData::encode(kiwi::ByteBuffer &_bb) {
  if (overlayGuid() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_overlayGuid->encode(_bb)) return false;
  }
  if (hotspotGuid() != nullptr) {
    _bb.writeVarUint(2);
    if (!_data_hotspotGuid->encode(_bb)) return false;
  }
  if (swapGuid() != nullptr) {
    _bb.writeVarUint(3);
    if (!_data_swapGuid->encode(_bb)) return false;
  }
  if (prototypeInteractionGuid() != nullptr) {
    _bb.writeVarUint(4);
    if (!_data_prototypeInteractionGuid->encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool TriggeredOverlayData::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_overlayGuid = _pool.allocate<GUID>();
        if (!_data_overlayGuid->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        _data_hotspotGuid = _pool.allocate<GUID>();
        if (!_data_hotspotGuid->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 3: {
        _data_swapGuid = _pool.allocate<GUID>();
        if (!_data_swapGuid->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 4: {
        _data_prototypeInteractionGuid = _pool.allocate<GUID>();
        if (!_data_prototypeInteractionGuid->decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipTriggeredOverlayDataField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::String *Hyperlink::url() {
  return _flags[0] & 1 ? &_data_url : nullptr;
}

const kiwi::String *Hyperlink::url() const {
  return _flags[0] & 1 ? &_data_url : nullptr;
}

void Hyperlink::set_url(const kiwi::String &value) {
  _flags[0] |= 1; _data_url = value;
}

GUID *Hyperlink::guid() {
  return _data_guid;
}

const GUID *Hyperlink::guid() const {
  return _data_guid;
}

void Hyperlink::set_guid(GUID *value) {
  _data_guid = value;
}

bool Hyperlink::encode(kiwi::ByteBuffer &_bb) {
  if (url() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeString(_data_url.c_str());
  }
  if (guid() != nullptr) {
    _bb.writeVarUint(2);
    if (!_data_guid->encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool Hyperlink::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readString(_data_url, _pool)) return false;
        set_url(_data_url);
        break;
      }
      case 2: {
        _data_guid = _pool.allocate<GUID>();
        if (!_data_guid->decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipHyperlinkField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::String *SharedStyleMasterData::styleKey() {
  return _flags[0] & 1 ? &_data_styleKey : nullptr;
}

const kiwi::String *SharedStyleMasterData::styleKey() const {
  return _flags[0] & 1 ? &_data_styleKey : nullptr;
}

void SharedStyleMasterData::set_styleKey(const kiwi::String &value) {
  _flags[0] |= 1; _data_styleKey = value;
}

kiwi::String *SharedStyleMasterData::sortPosition() {
  return _flags[0] & 2 ? &_data_sortPosition : nullptr;
}

const kiwi::String *SharedStyleMasterData::sortPosition() const {
  return _flags[0] & 2 ? &_data_sortPosition : nullptr;
}

void SharedStyleMasterData::set_sortPosition(const kiwi::String &value) {
  _flags[0] |= 2; _data_sortPosition = value;
}

kiwi::String *SharedStyleMasterData::fileKey() {
  return _flags[0] & 4 ? &_data_fileKey : nullptr;
}

const kiwi::String *SharedStyleMasterData::fileKey() const {
  return _flags[0] & 4 ? &_data_fileKey : nullptr;
}

void SharedStyleMasterData::set_fileKey(const kiwi::String &value) {
  _flags[0] |= 4; _data_fileKey = value;
}

bool SharedStyleMasterData::encode(kiwi::ByteBuffer &_bb) {
  if (styleKey() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeString(_data_styleKey.c_str());
  }
  if (sortPosition() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeString(_data_sortPosition.c_str());
  }
  if (fileKey() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeString(_data_fileKey.c_str());
  }
  _bb.writeVarUint(0);
  return true;
}

bool SharedStyleMasterData::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readString(_data_styleKey, _pool)) return false;
        set_styleKey(_data_styleKey);
        break;
      }
      case 2: {
        if (!_bb.readString(_data_sortPosition, _pool)) return false;
        set_sortPosition(_data_sortPosition);
        break;
      }
      case 3: {
        if (!_bb.readString(_data_fileKey, _pool)) return false;
        set_fileKey(_data_fileKey);
        break;
      }
      default: {
        if (!_schema || !_schema->skipSharedStyleMasterDataField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::String *SharedStyleReference::styleKey() {
  return _flags[0] & 1 ? &_data_styleKey : nullptr;
}

const kiwi::String *SharedStyleReference::styleKey() const {
  return _flags[0] & 1 ? &_data_styleKey : nullptr;
}

void SharedStyleReference::set_styleKey(const kiwi::String &value) {
  _flags[0] |= 1; _data_styleKey = value;
}

kiwi::String *SharedStyleReference::versionHash() {
  return _flags[0] & 2 ? &_data_versionHash : nullptr;
}

const kiwi::String *SharedStyleReference::versionHash() const {
  return _flags[0] & 2 ? &_data_versionHash : nullptr;
}

void SharedStyleReference::set_versionHash(const kiwi::String &value) {
  _flags[0] |= 2; _data_versionHash = value;
}

bool SharedStyleReference::encode(kiwi::ByteBuffer &_bb) {
  if (styleKey() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeString(_data_styleKey.c_str());
  }
  if (versionHash() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeString(_data_versionHash.c_str());
  }
  _bb.writeVarUint(0);
  return true;
}

bool SharedStyleReference::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readString(_data_styleKey, _pool)) return false;
        set_styleKey(_data_styleKey);
        break;
      }
      case 2: {
        if (!_bb.readString(_data_versionHash, _pool)) return false;
        set_versionHash(_data_versionHash);
        break;
      }
      default: {
        if (!_schema || !_schema->skipSharedStyleReferenceField(_bb, _type)) return false;
        break;
      }
    }
  }
}

PixsoMsgType *PixsoMsg::type() {
  return _flags[0] & 1 ? &_data_type : nullptr;
}

const PixsoMsgType *PixsoMsg::type() const {
  return _flags[0] & 1 ? &_data_type : nullptr;
}

void PixsoMsg::set_type(const PixsoMsgType &value) {
  _flags[0] |= 1; _data_type = value;
}

int32_t *PixsoMsg::sessionID() {
  return _flags[0] & 2 ? &_data_sessionID : nullptr;
}

const int32_t *PixsoMsg::sessionID() const {
  return _flags[0] & 2 ? &_data_sessionID : nullptr;
}

void PixsoMsg::set_sessionID(const int32_t &value) {
  _flags[0] |= 2; _data_sessionID = value;
}

kiwi::Array<PixsoNode> *PixsoMsg::pixsoNodes() {
  return _flags[0] & 4 ? &_data_pixsoNodes : nullptr;
}

const kiwi::Array<PixsoNode> *PixsoMsg::pixsoNodes() const {
  return _flags[0] & 4 ? &_data_pixsoNodes : nullptr;
}

kiwi::Array<PixsoNode> &PixsoMsg::set_pixsoNodes(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 4; return _data_pixsoNodes = pool.array<PixsoNode>(count);
}

kiwi::Array<Blob> *PixsoMsg::blobs() {
  return _flags[0] & 8 ? &_data_blobs : nullptr;
}

const kiwi::Array<Blob> *PixsoMsg::blobs() const {
  return _flags[0] & 8 ? &_data_blobs : nullptr;
}

kiwi::Array<Blob> &PixsoMsg::set_blobs(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 8; return _data_blobs = pool.array<Blob>(count);
}

int32_t *PixsoMsg::ackID() {
  return _flags[0] & 16 ? &_data_ackID : nullptr;
}

const int32_t *PixsoMsg::ackID() const {
  return _flags[0] & 16 ? &_data_ackID : nullptr;
}

void PixsoMsg::set_ackID(const int32_t &value) {
  _flags[0] |= 16; _data_ackID = value;
}

kiwi::Array<UserInfo> *PixsoMsg::userInfos() {
  return _flags[0] & 32 ? &_data_userInfos : nullptr;
}

const kiwi::Array<UserInfo> *PixsoMsg::userInfos() const {
  return _flags[0] & 32 ? &_data_userInfos : nullptr;
}

kiwi::Array<UserInfo> &PixsoMsg::set_userInfos(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 32; return _data_userInfos = pool.array<UserInfo>(count);
}

Access *PixsoMsg::access() {
  return _flags[0] & 64 ? &_data_access : nullptr;
}

const Access *PixsoMsg::access() const {
  return _flags[0] & 64 ? &_data_access : nullptr;
}

void PixsoMsg::set_access(const Access &value) {
  _flags[0] |= 64; _data_access = value;
}

uint32_t *PixsoMsg::fileVersion() {
  return _flags[0] & 128 ? &_data_fileVersion : nullptr;
}

const uint32_t *PixsoMsg::fileVersion() const {
  return _flags[0] & 128 ? &_data_fileVersion : nullptr;
}

void PixsoMsg::set_fileVersion(const uint32_t &value) {
  _flags[0] |= 128; _data_fileVersion = value;
}

kiwi::String *PixsoMsg::styleSetName() {
  return _flags[0] & 256 ? &_data_styleSetName : nullptr;
}

const kiwi::String *PixsoMsg::styleSetName() const {
  return _flags[0] & 256 ? &_data_styleSetName : nullptr;
}

void PixsoMsg::set_styleSetName(const kiwi::String &value) {
  _flags[0] |= 256; _data_styleSetName = value;
}

StyleSetType *PixsoMsg::styleSetType() {
  return _flags[0] & 512 ? &_data_styleSetType : nullptr;
}

const StyleSetType *PixsoMsg::styleSetType() const {
  return _flags[0] & 512 ? &_data_styleSetType : nullptr;
}

void PixsoMsg::set_styleSetType(const StyleSetType &value) {
  _flags[0] |= 512; _data_styleSetType = value;
}

StyleSetContentType *PixsoMsg::styleSetContentType() {
  return _flags[0] & 1024 ? &_data_styleSetContentType : nullptr;
}

const StyleSetContentType *PixsoMsg::styleSetContentType() const {
  return _flags[0] & 1024 ? &_data_styleSetContentType : nullptr;
}

void PixsoMsg::set_styleSetContentType(const StyleSetContentType &value) {
  _flags[0] |= 1024; _data_styleSetContentType = value;
}

GUID *PixsoMsg::pastePageId() {
  return _data_pastePageId;
}

const GUID *PixsoMsg::pastePageId() const {
  return _data_pastePageId;
}

void PixsoMsg::set_pastePageId(GUID *value) {
  _data_pastePageId = value;
}

kiwi::Array<SceneGraphQuery> *PixsoMsg::sceneGraphQueries() {
  return _flags[0] & 4096 ? &_data_sceneGraphQueries : nullptr;
}

const kiwi::Array<SceneGraphQuery> *PixsoMsg::sceneGraphQueries() const {
  return _flags[0] & 4096 ? &_data_sceneGraphQueries : nullptr;
}

kiwi::Array<SceneGraphQuery> &PixsoMsg::set_sceneGraphQueries(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 4096; return _data_sceneGraphQueries = pool.array<SceneGraphQuery>(count);
}

kiwi::String *PixsoMsg::signalName() {
  return _flags[0] & 8192 ? &_data_signalName : nullptr;
}

const kiwi::String *PixsoMsg::signalName() const {
  return _flags[0] & 8192 ? &_data_signalName : nullptr;
}

void PixsoMsg::set_signalName(const kiwi::String &value) {
  _flags[0] |= 8192; _data_signalName = value;
}

kiwi::String *PixsoMsg::signalPayload() {
  return _flags[0] & 16384 ? &_data_signalPayload : nullptr;
}

const kiwi::String *PixsoMsg::signalPayload() const {
  return _flags[0] & 16384 ? &_data_signalPayload : nullptr;
}

void PixsoMsg::set_signalPayload(const kiwi::String &value) {
  _flags[0] |= 16384; _data_signalPayload = value;
}

kiwi::String *PixsoMsg::createVersion() {
  return _flags[0] & 32768 ? &_data_createVersion : nullptr;
}

const kiwi::String *PixsoMsg::createVersion() const {
  return _flags[0] & 32768 ? &_data_createVersion : nullptr;
}

void PixsoMsg::set_createVersion(const kiwi::String &value) {
  _flags[0] |= 32768; _data_createVersion = value;
}

kiwi::String *PixsoMsg::lastOpenVersion() {
  return _flags[0] & 65536 ? &_data_lastOpenVersion : nullptr;
}

const kiwi::String *PixsoMsg::lastOpenVersion() const {
  return _flags[0] & 65536 ? &_data_lastOpenVersion : nullptr;
}

void PixsoMsg::set_lastOpenVersion(const kiwi::String &value) {
  _flags[0] |= 65536; _data_lastOpenVersion = value;
}

CommandNum *PixsoMsg::cmdNum() {
  return _data_cmdNum;
}

const CommandNum *PixsoMsg::cmdNum() const {
  return _data_cmdNum;
}

void PixsoMsg::set_cmdNum(CommandNum *value) {
  _data_cmdNum = value;
}

FileMeta *PixsoMsg::fileMeta() {
  return _data_fileMeta;
}

const FileMeta *PixsoMsg::fileMeta() const {
  return _data_fileMeta;
}

void PixsoMsg::set_fileMeta(FileMeta *value) {
  _data_fileMeta = value;
}

kiwi::String *PixsoMsg::pasteFileKey() {
  return _flags[0] & 524288 ? &_data_pasteFileKey : nullptr;
}

const kiwi::String *PixsoMsg::pasteFileKey() const {
  return _flags[0] & 524288 ? &_data_pasteFileKey : nullptr;
}

void PixsoMsg::set_pasteFileKey(const kiwi::String &value) {
  _flags[0] |= 524288; _data_pasteFileKey = value;
}

bool PixsoMsg::encode(kiwi::ByteBuffer &_bb) {
  if (type() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(static_cast<uint32_t>(_data_type));
  }
  if (sessionID() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarInt(_data_sessionID);
  }
  if (pixsoNodes() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeVarUint(_data_pixsoNodes.size());
    for (PixsoNode &_it : _data_pixsoNodes) if (!_it.encode(_bb)) return false;
  }
  if (blobs() != nullptr) {
    _bb.writeVarUint(4);
    _bb.writeVarUint(_data_blobs.size());
    for (Blob &_it : _data_blobs) if (!_it.encode(_bb)) return false;
  }
  if (ackID() != nullptr) {
    _bb.writeVarUint(5);
    _bb.writeVarInt(_data_ackID);
  }
  if (userInfos() != nullptr) {
    _bb.writeVarUint(6);
    _bb.writeVarUint(_data_userInfos.size());
    for (UserInfo &_it : _data_userInfos) if (!_it.encode(_bb)) return false;
  }
  if (access() != nullptr) {
    _bb.writeVarUint(7);
    _bb.writeVarUint(static_cast<uint32_t>(_data_access));
  }
  if (fileVersion() != nullptr) {
    _bb.writeVarUint(8);
    _bb.writeVarUint(_data_fileVersion);
  }
  if (styleSetName() != nullptr) {
    _bb.writeVarUint(9);
    _bb.writeString(_data_styleSetName.c_str());
  }
  if (styleSetType() != nullptr) {
    _bb.writeVarUint(10);
    _bb.writeVarUint(static_cast<uint32_t>(_data_styleSetType));
  }
  if (styleSetContentType() != nullptr) {
    _bb.writeVarUint(11);
    _bb.writeVarUint(static_cast<uint32_t>(_data_styleSetContentType));
  }
  if (pastePageId() != nullptr) {
    _bb.writeVarUint(12);
    if (!_data_pastePageId->encode(_bb)) return false;
  }
  if (sceneGraphQueries() != nullptr) {
    _bb.writeVarUint(13);
    _bb.writeVarUint(_data_sceneGraphQueries.size());
    for (SceneGraphQuery &_it : _data_sceneGraphQueries) if (!_it.encode(_bb)) return false;
  }
  if (signalName() != nullptr) {
    _bb.writeVarUint(14);
    _bb.writeString(_data_signalName.c_str());
  }
  if (signalPayload() != nullptr) {
    _bb.writeVarUint(15);
    _bb.writeString(_data_signalPayload.c_str());
  }
  if (createVersion() != nullptr) {
    _bb.writeVarUint(16);
    _bb.writeString(_data_createVersion.c_str());
  }
  if (lastOpenVersion() != nullptr) {
    _bb.writeVarUint(17);
    _bb.writeString(_data_lastOpenVersion.c_str());
  }
  if (cmdNum() != nullptr) {
    _bb.writeVarUint(18);
    if (!_data_cmdNum->encode(_bb)) return false;
  }
  if (fileMeta() != nullptr) {
    _bb.writeVarUint(19);
    if (!_data_fileMeta->encode(_bb)) return false;
  }
  if (pasteFileKey() != nullptr) {
    _bb.writeVarUint(20);
    _bb.writeString(_data_pasteFileKey.c_str());
  }
  _bb.writeVarUint(0);
  return true;
}

bool PixsoMsg::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_type))) return false;
        set_type(_data_type);
        break;
      }
      case 2: {
        if (!_bb.readVarInt(_data_sessionID)) return false;
        set_sessionID(_data_sessionID);
        break;
      }
      case 3: {
        if (!_bb.readVarUint(_count)) return false;
        for (PixsoNode &_it : set_pixsoNodes(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 4: {
        if (!_bb.readVarUint(_count)) return false;
        for (Blob &_it : set_blobs(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 5: {
        if (!_bb.readVarInt(_data_ackID)) return false;
        set_ackID(_data_ackID);
        break;
      }
      case 6: {
        if (!_bb.readVarUint(_count)) return false;
        for (UserInfo &_it : set_userInfos(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 7: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_access))) return false;
        set_access(_data_access);
        break;
      }
      case 8: {
        if (!_bb.readVarUint(_data_fileVersion)) return false;
        set_fileVersion(_data_fileVersion);
        break;
      }
      case 9: {
        if (!_bb.readString(_data_styleSetName, _pool)) return false;
        set_styleSetName(_data_styleSetName);
        break;
      }
      case 10: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_styleSetType))) return false;
        set_styleSetType(_data_styleSetType);
        break;
      }
      case 11: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_styleSetContentType))) return false;
        set_styleSetContentType(_data_styleSetContentType);
        break;
      }
      case 12: {
        _data_pastePageId = _pool.allocate<GUID>();
        if (!_data_pastePageId->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 13: {
        if (!_bb.readVarUint(_count)) return false;
        for (SceneGraphQuery &_it : set_sceneGraphQueries(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 14: {
        if (!_bb.readString(_data_signalName, _pool)) return false;
        set_signalName(_data_signalName);
        break;
      }
      case 15: {
        if (!_bb.readString(_data_signalPayload, _pool)) return false;
        set_signalPayload(_data_signalPayload);
        break;
      }
      case 16: {
        if (!_bb.readString(_data_createVersion, _pool)) return false;
        set_createVersion(_data_createVersion);
        break;
      }
      case 17: {
        if (!_bb.readString(_data_lastOpenVersion, _pool)) return false;
        set_lastOpenVersion(_data_lastOpenVersion);
        break;
      }
      case 18: {
        _data_cmdNum = _pool.allocate<CommandNum>();
        if (!_data_cmdNum->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 19: {
        _data_fileMeta = _pool.allocate<FileMeta>();
        if (!_data_fileMeta->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 20: {
        if (!_bb.readString(_data_pasteFileKey, _pool)) return false;
        set_pasteFileKey(_data_pasteFileKey);
        break;
      }
      default: {
        if (!_schema || !_schema->skipPixsoMsgField(_bb, _type)) return false;
        break;
      }
    }
  }
}

int32_t *VectorStyleData::styleID() {
  return _flags[0] & 1 ? &_data_styleID : nullptr;
}

const int32_t *VectorStyleData::styleID() const {
  return _flags[0] & 1 ? &_data_styleID : nullptr;
}

void VectorStyleData::set_styleID(const int32_t &value) {
  _flags[0] |= 1; _data_styleID = value;
}

float *VectorStyleData::cornerRadius() {
  return _flags[0] & 2 ? &_data_cornerRadius : nullptr;
}

const float *VectorStyleData::cornerRadius() const {
  return _flags[0] & 2 ? &_data_cornerRadius : nullptr;
}

void VectorStyleData::set_cornerRadius(const float &value) {
  _flags[0] |= 2; _data_cornerRadius = value;
}

StrokeCap *VectorStyleData::strokeCap() {
  return _flags[0] & 4 ? &_data_strokeCap : nullptr;
}

const StrokeCap *VectorStyleData::strokeCap() const {
  return _flags[0] & 4 ? &_data_strokeCap : nullptr;
}

void VectorStyleData::set_strokeCap(const StrokeCap &value) {
  _flags[0] |= 4; _data_strokeCap = value;
}

StrokeJoin *VectorStyleData::strokeJoin() {
  return _flags[0] & 8 ? &_data_strokeJoin : nullptr;
}

const StrokeJoin *VectorStyleData::strokeJoin() const {
  return _flags[0] & 8 ? &_data_strokeJoin : nullptr;
}

void VectorStyleData::set_strokeJoin(const StrokeJoin &value) {
  _flags[0] |= 8; _data_strokeJoin = value;
}

VectorMirror *VectorStyleData::handleMirroring() {
  return _flags[0] & 16 ? &_data_handleMirroring : nullptr;
}

const VectorMirror *VectorStyleData::handleMirroring() const {
  return _flags[0] & 16 ? &_data_handleMirroring : nullptr;
}

void VectorStyleData::set_handleMirroring(const VectorMirror &value) {
  _flags[0] |= 16; _data_handleMirroring = value;
}

bool VectorStyleData::encode(kiwi::ByteBuffer &_bb) {
  if (styleID() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarInt(_data_styleID);
  }
  if (cornerRadius() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarFloat(_data_cornerRadius);
  }
  if (strokeCap() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeVarUint(static_cast<uint32_t>(_data_strokeCap));
  }
  if (strokeJoin() != nullptr) {
    _bb.writeVarUint(4);
    _bb.writeVarUint(static_cast<uint32_t>(_data_strokeJoin));
  }
  if (handleMirroring() != nullptr) {
    _bb.writeVarUint(5);
    _bb.writeVarUint(static_cast<uint32_t>(_data_handleMirroring));
  }
  _bb.writeVarUint(0);
  return true;
}

bool VectorStyleData::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarInt(_data_styleID)) return false;
        set_styleID(_data_styleID);
        break;
      }
      case 2: {
        if (!_bb.readVarFloat(_data_cornerRadius)) return false;
        set_cornerRadius(_data_cornerRadius);
        break;
      }
      case 3: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_strokeCap))) return false;
        set_strokeCap(_data_strokeCap);
        break;
      }
      case 4: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_strokeJoin))) return false;
        set_strokeJoin(_data_strokeJoin);
        break;
      }
      case 5: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_handleMirroring))) return false;
        set_handleMirroring(_data_handleMirroring);
        break;
      }
      default: {
        if (!_schema || !_schema->skipVectorStyleDataField(_bb, _type)) return false;
        break;
      }
    }
  }
}

int32_t *TextStyleData::styleID() {
  return _flags[0] & 1 ? &_data_styleID : nullptr;
}

const int32_t *TextStyleData::styleID() const {
  return _flags[0] & 1 ? &_data_styleID : nullptr;
}

void TextStyleData::set_styleID(const int32_t &value) {
  _flags[0] |= 1; _data_styleID = value;
}

float *TextStyleData::fontSize() {
  return _flags[0] & 2 ? &_data_fontSize : nullptr;
}

const float *TextStyleData::fontSize() const {
  return _flags[0] & 2 ? &_data_fontSize : nullptr;
}

void TextStyleData::set_fontSize(const float &value) {
  _flags[0] |= 2; _data_fontSize = value;
}

float *TextStyleData::paragraphIndent() {
  return _flags[0] & 4 ? &_data_paragraphIndent : nullptr;
}

const float *TextStyleData::paragraphIndent() const {
  return _flags[0] & 4 ? &_data_paragraphIndent : nullptr;
}

void TextStyleData::set_paragraphIndent(const float &value) {
  _flags[0] |= 4; _data_paragraphIndent = value;
}

float *TextStyleData::paragraphSpacing() {
  return _flags[0] & 8 ? &_data_paragraphSpacing : nullptr;
}

const float *TextStyleData::paragraphSpacing() const {
  return _flags[0] & 8 ? &_data_paragraphSpacing : nullptr;
}

void TextStyleData::set_paragraphSpacing(const float &value) {
  _flags[0] |= 8; _data_paragraphSpacing = value;
}

Number *TextStyleData::letterSpacing() {
  return _data_letterSpacing;
}

const Number *TextStyleData::letterSpacing() const {
  return _data_letterSpacing;
}

void TextStyleData::set_letterSpacing(Number *value) {
  _data_letterSpacing = value;
}

Number *TextStyleData::lineHeight() {
  return _data_lineHeight;
}

const Number *TextStyleData::lineHeight() const {
  return _data_lineHeight;
}

void TextStyleData::set_lineHeight(Number *value) {
  _data_lineHeight = value;
}

TextCase *TextStyleData::textCase() {
  return _flags[0] & 64 ? &_data_textCase : nullptr;
}

const TextCase *TextStyleData::textCase() const {
  return _flags[0] & 64 ? &_data_textCase : nullptr;
}

void TextStyleData::set_textCase(const TextCase &value) {
  _flags[0] |= 64; _data_textCase = value;
}

TextDecoration *TextStyleData::textDecoration() {
  return _flags[0] & 128 ? &_data_textDecoration : nullptr;
}

const TextDecoration *TextStyleData::textDecoration() const {
  return _flags[0] & 128 ? &_data_textDecoration : nullptr;
}

void TextStyleData::set_textDecoration(const TextDecoration &value) {
  _flags[0] |= 128; _data_textDecoration = value;
}

TextAlignHorizontal *TextStyleData::textAlignHorizontal() {
  return _flags[0] & 256 ? &_data_textAlignHorizontal : nullptr;
}

const TextAlignHorizontal *TextStyleData::textAlignHorizontal() const {
  return _flags[0] & 256 ? &_data_textAlignHorizontal : nullptr;
}

void TextStyleData::set_textAlignHorizontal(const TextAlignHorizontal &value) {
  _flags[0] |= 256; _data_textAlignHorizontal = value;
}

TextAlignVertical *TextStyleData::textAlignVertical() {
  return _flags[0] & 512 ? &_data_textAlignVertical : nullptr;
}

const TextAlignVertical *TextStyleData::textAlignVertical() const {
  return _flags[0] & 512 ? &_data_textAlignVertical : nullptr;
}

void TextStyleData::set_textAlignVertical(const TextAlignVertical &value) {
  _flags[0] |= 512; _data_textAlignVertical = value;
}

TextAutoResize *TextStyleData::textAutoResize() {
  return _flags[0] & 1024 ? &_data_textAutoResize : nullptr;
}

const TextAutoResize *TextStyleData::textAutoResize() const {
  return _flags[0] & 1024 ? &_data_textAutoResize : nullptr;
}

void TextStyleData::set_textAutoResize(const TextAutoResize &value) {
  _flags[0] |= 1024; _data_textAutoResize = value;
}

FontName *TextStyleData::fontName() {
  return _data_fontName;
}

const FontName *TextStyleData::fontName() const {
  return _data_fontName;
}

void TextStyleData::set_fontName(FontName *value) {
  _data_fontName = value;
}

Hyperlink *TextStyleData::hyperlink() {
  return _data_hyperlink;
}

const Hyperlink *TextStyleData::hyperlink() const {
  return _data_hyperlink;
}

void TextStyleData::set_hyperlink(Hyperlink *value) {
  _data_hyperlink = value;
}

kiwi::Array<Paint> *TextStyleData::fillPaints() {
  return _flags[0] & 8192 ? &_data_fillPaints : nullptr;
}

const kiwi::Array<Paint> *TextStyleData::fillPaints() const {
  return _flags[0] & 8192 ? &_data_fillPaints : nullptr;
}

kiwi::Array<Paint> &TextStyleData::set_fillPaints(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 8192; return _data_fillPaints = pool.array<Paint>(count);
}

GUID *TextStyleData::inheritFillStyleID() {
  return _data_inheritFillStyleID;
}

const GUID *TextStyleData::inheritFillStyleID() const {
  return _data_inheritFillStyleID;
}

void TextStyleData::set_inheritFillStyleID(GUID *value) {
  _data_inheritFillStyleID = value;
}

GUID *TextStyleData::inheritTextStyleID() {
  return _data_inheritTextStyleID;
}

const GUID *TextStyleData::inheritTextStyleID() const {
  return _data_inheritTextStyleID;
}

void TextStyleData::set_inheritTextStyleID(GUID *value) {
  _data_inheritTextStyleID = value;
}

FontVariantNumericFigure *TextStyleData::fontVariantNumericFigure() {
  return _flags[0] & 65536 ? &_data_fontVariantNumericFigure : nullptr;
}

const FontVariantNumericFigure *TextStyleData::fontVariantNumericFigure() const {
  return _flags[0] & 65536 ? &_data_fontVariantNumericFigure : nullptr;
}

void TextStyleData::set_fontVariantNumericFigure(const FontVariantNumericFigure &value) {
  _flags[0] |= 65536; _data_fontVariantNumericFigure = value;
}

FontVariantNumericSpacing *TextStyleData::fontVariantNumericSpacing() {
  return _flags[0] & 131072 ? &_data_fontVariantNumericSpacing : nullptr;
}

const FontVariantNumericSpacing *TextStyleData::fontVariantNumericSpacing() const {
  return _flags[0] & 131072 ? &_data_fontVariantNumericSpacing : nullptr;
}

void TextStyleData::set_fontVariantNumericSpacing(const FontVariantNumericSpacing &value) {
  _flags[0] |= 131072; _data_fontVariantNumericSpacing = value;
}

FontVariantNumericFraction *TextStyleData::fontVariantNumericFraction() {
  return _flags[0] & 262144 ? &_data_fontVariantNumericFraction : nullptr;
}

const FontVariantNumericFraction *TextStyleData::fontVariantNumericFraction() const {
  return _flags[0] & 262144 ? &_data_fontVariantNumericFraction : nullptr;
}

void TextStyleData::set_fontVariantNumericFraction(const FontVariantNumericFraction &value) {
  _flags[0] |= 262144; _data_fontVariantNumericFraction = value;
}

FontVariantPosition *TextStyleData::fontVariantPosition() {
  return _flags[0] & 524288 ? &_data_fontVariantPosition : nullptr;
}

const FontVariantPosition *TextStyleData::fontVariantPosition() const {
  return _flags[0] & 524288 ? &_data_fontVariantPosition : nullptr;
}

void TextStyleData::set_fontVariantPosition(const FontVariantPosition &value) {
  _flags[0] |= 524288; _data_fontVariantPosition = value;
}

kiwi::Array<OpenTypeFeature> *TextStyleData::toggledOnOTFeatures() {
  return _flags[0] & 1048576 ? &_data_toggledOnOTFeatures : nullptr;
}

const kiwi::Array<OpenTypeFeature> *TextStyleData::toggledOnOTFeatures() const {
  return _flags[0] & 1048576 ? &_data_toggledOnOTFeatures : nullptr;
}

kiwi::Array<OpenTypeFeature> &TextStyleData::set_toggledOnOTFeatures(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 1048576; return _data_toggledOnOTFeatures = pool.array<OpenTypeFeature>(count);
}

kiwi::Array<OpenTypeFeature> *TextStyleData::toggledOffOTFeatures() {
  return _flags[0] & 2097152 ? &_data_toggledOffOTFeatures : nullptr;
}

const kiwi::Array<OpenTypeFeature> *TextStyleData::toggledOffOTFeatures() const {
  return _flags[0] & 2097152 ? &_data_toggledOffOTFeatures : nullptr;
}

kiwi::Array<OpenTypeFeature> &TextStyleData::set_toggledOffOTFeatures(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 2097152; return _data_toggledOffOTFeatures = pool.array<OpenTypeFeature>(count);
}

kiwi::Array<FontVariation> *TextStyleData::fontVariations() {
  return _flags[0] & 4194304 ? &_data_fontVariations : nullptr;
}

const kiwi::Array<FontVariation> *TextStyleData::fontVariations() const {
  return _flags[0] & 4194304 ? &_data_fontVariations : nullptr;
}

kiwi::Array<FontVariation> &TextStyleData::set_fontVariations(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 4194304; return _data_fontVariations = pool.array<FontVariation>(count);
}

bool *TextStyleData::detachOpticalSizeFromFontSize() {
  return _flags[0] & 8388608 ? &_data_detachOpticalSizeFromFontSize : nullptr;
}

const bool *TextStyleData::detachOpticalSizeFromFontSize() const {
  return _flags[0] & 8388608 ? &_data_detachOpticalSizeFromFontSize : nullptr;
}

void TextStyleData::set_detachOpticalSizeFromFontSize(const bool &value) {
  _flags[0] |= 8388608; _data_detachOpticalSizeFromFontSize = value;
}

VariableDataMap *TextStyleData::variableConsumptionMap() {
  return _data_variableConsumptionMap;
}

const VariableDataMap *TextStyleData::variableConsumptionMap() const {
  return _data_variableConsumptionMap;
}

void TextStyleData::set_variableConsumptionMap(VariableDataMap *value) {
  _data_variableConsumptionMap = value;
}

bool TextStyleData::encode(kiwi::ByteBuffer &_bb) {
  if (styleID() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarInt(_data_styleID);
  }
  if (fontSize() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarFloat(_data_fontSize);
  }
  if (paragraphIndent() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeVarFloat(_data_paragraphIndent);
  }
  if (paragraphSpacing() != nullptr) {
    _bb.writeVarUint(4);
    _bb.writeVarFloat(_data_paragraphSpacing);
  }
  if (letterSpacing() != nullptr) {
    _bb.writeVarUint(5);
    if (!_data_letterSpacing->encode(_bb)) return false;
  }
  if (lineHeight() != nullptr) {
    _bb.writeVarUint(6);
    if (!_data_lineHeight->encode(_bb)) return false;
  }
  if (textCase() != nullptr) {
    _bb.writeVarUint(7);
    _bb.writeVarUint(static_cast<uint32_t>(_data_textCase));
  }
  if (textDecoration() != nullptr) {
    _bb.writeVarUint(8);
    _bb.writeVarUint(static_cast<uint32_t>(_data_textDecoration));
  }
  if (textAlignHorizontal() != nullptr) {
    _bb.writeVarUint(9);
    _bb.writeVarUint(static_cast<uint32_t>(_data_textAlignHorizontal));
  }
  if (textAlignVertical() != nullptr) {
    _bb.writeVarUint(10);
    _bb.writeVarUint(static_cast<uint32_t>(_data_textAlignVertical));
  }
  if (textAutoResize() != nullptr) {
    _bb.writeVarUint(11);
    _bb.writeVarUint(static_cast<uint32_t>(_data_textAutoResize));
  }
  if (fontName() != nullptr) {
    _bb.writeVarUint(12);
    if (!_data_fontName->encode(_bb)) return false;
  }
  if (hyperlink() != nullptr) {
    _bb.writeVarUint(13);
    if (!_data_hyperlink->encode(_bb)) return false;
  }
  if (fillPaints() != nullptr) {
    _bb.writeVarUint(14);
    _bb.writeVarUint(_data_fillPaints.size());
    for (Paint &_it : _data_fillPaints) if (!_it.encode(_bb)) return false;
  }
  if (inheritFillStyleID() != nullptr) {
    _bb.writeVarUint(15);
    if (!_data_inheritFillStyleID->encode(_bb)) return false;
  }
  if (inheritTextStyleID() != nullptr) {
    _bb.writeVarUint(16);
    if (!_data_inheritTextStyleID->encode(_bb)) return false;
  }
  if (fontVariantNumericFigure() != nullptr) {
    _bb.writeVarUint(17);
    _bb.writeVarUint(static_cast<uint32_t>(_data_fontVariantNumericFigure));
  }
  if (fontVariantNumericSpacing() != nullptr) {
    _bb.writeVarUint(18);
    _bb.writeVarUint(static_cast<uint32_t>(_data_fontVariantNumericSpacing));
  }
  if (fontVariantNumericFraction() != nullptr) {
    _bb.writeVarUint(19);
    _bb.writeVarUint(static_cast<uint32_t>(_data_fontVariantNumericFraction));
  }
  if (fontVariantPosition() != nullptr) {
    _bb.writeVarUint(20);
    _bb.writeVarUint(static_cast<uint32_t>(_data_fontVariantPosition));
  }
  if (toggledOnOTFeatures() != nullptr) {
    _bb.writeVarUint(21);
    _bb.writeVarUint(_data_toggledOnOTFeatures.size());
    for (OpenTypeFeature &_it : _data_toggledOnOTFeatures) _bb.writeVarUint(static_cast<uint32_t>(_it));
  }
  if (toggledOffOTFeatures() != nullptr) {
    _bb.writeVarUint(22);
    _bb.writeVarUint(_data_toggledOffOTFeatures.size());
    for (OpenTypeFeature &_it : _data_toggledOffOTFeatures) _bb.writeVarUint(static_cast<uint32_t>(_it));
  }
  if (fontVariations() != nullptr) {
    _bb.writeVarUint(23);
    _bb.writeVarUint(_data_fontVariations.size());
    for (FontVariation &_it : _data_fontVariations) if (!_it.encode(_bb)) return false;
  }
  if (detachOpticalSizeFromFontSize() != nullptr) {
    _bb.writeVarUint(24);
    _bb.writeByte(_data_detachOpticalSizeFromFontSize);
  }
  if (variableConsumptionMap() != nullptr) {
    _bb.writeVarUint(25);
    if (!_data_variableConsumptionMap->encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool TextStyleData::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarInt(_data_styleID)) return false;
        set_styleID(_data_styleID);
        break;
      }
      case 2: {
        if (!_bb.readVarFloat(_data_fontSize)) return false;
        set_fontSize(_data_fontSize);
        break;
      }
      case 3: {
        if (!_bb.readVarFloat(_data_paragraphIndent)) return false;
        set_paragraphIndent(_data_paragraphIndent);
        break;
      }
      case 4: {
        if (!_bb.readVarFloat(_data_paragraphSpacing)) return false;
        set_paragraphSpacing(_data_paragraphSpacing);
        break;
      }
      case 5: {
        _data_letterSpacing = _pool.allocate<Number>();
        if (!_data_letterSpacing->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 6: {
        _data_lineHeight = _pool.allocate<Number>();
        if (!_data_lineHeight->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 7: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_textCase))) return false;
        set_textCase(_data_textCase);
        break;
      }
      case 8: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_textDecoration))) return false;
        set_textDecoration(_data_textDecoration);
        break;
      }
      case 9: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_textAlignHorizontal))) return false;
        set_textAlignHorizontal(_data_textAlignHorizontal);
        break;
      }
      case 10: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_textAlignVertical))) return false;
        set_textAlignVertical(_data_textAlignVertical);
        break;
      }
      case 11: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_textAutoResize))) return false;
        set_textAutoResize(_data_textAutoResize);
        break;
      }
      case 12: {
        _data_fontName = _pool.allocate<FontName>();
        if (!_data_fontName->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 13: {
        _data_hyperlink = _pool.allocate<Hyperlink>();
        if (!_data_hyperlink->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 14: {
        if (!_bb.readVarUint(_count)) return false;
        for (Paint &_it : set_fillPaints(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 15: {
        _data_inheritFillStyleID = _pool.allocate<GUID>();
        if (!_data_inheritFillStyleID->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 16: {
        _data_inheritTextStyleID = _pool.allocate<GUID>();
        if (!_data_inheritTextStyleID->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 17: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_fontVariantNumericFigure))) return false;
        set_fontVariantNumericFigure(_data_fontVariantNumericFigure);
        break;
      }
      case 18: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_fontVariantNumericSpacing))) return false;
        set_fontVariantNumericSpacing(_data_fontVariantNumericSpacing);
        break;
      }
      case 19: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_fontVariantNumericFraction))) return false;
        set_fontVariantNumericFraction(_data_fontVariantNumericFraction);
        break;
      }
      case 20: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_fontVariantPosition))) return false;
        set_fontVariantPosition(_data_fontVariantPosition);
        break;
      }
      case 21: {
        if (!_bb.readVarUint(_count)) return false;
        for (OpenTypeFeature &_it : set_toggledOnOTFeatures(_pool, _count)) if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_it))) return false;
        break;
      }
      case 22: {
        if (!_bb.readVarUint(_count)) return false;
        for (OpenTypeFeature &_it : set_toggledOffOTFeatures(_pool, _count)) if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_it))) return false;
        break;
      }
      case 23: {
        if (!_bb.readVarUint(_count)) return false;
        for (FontVariation &_it : set_fontVariations(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 24: {
        if (!_bb.readByte(_data_detachOpticalSizeFromFontSize)) return false;
        set_detachOpticalSizeFromFontSize(_data_detachOpticalSizeFromFontSize);
        break;
      }
      case 25: {
        _data_variableConsumptionMap = _pool.allocate<VariableDataMap>();
        if (!_data_variableConsumptionMap->decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipTextStyleDataField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::String *PropValueData::property() {
  return _flags[0] & 1 ? &_data_property : nullptr;
}

const kiwi::String *PropValueData::property() const {
  return _flags[0] & 1 ? &_data_property : nullptr;
}

void PropValueData::set_property(const kiwi::String &value) {
  _flags[0] |= 1; _data_property = value;
}

kiwi::Array<kiwi::String> *PropValueData::values() {
  return _flags[0] & 2 ? &_data_values : nullptr;
}

const kiwi::Array<kiwi::String> *PropValueData::values() const {
  return _flags[0] & 2 ? &_data_values : nullptr;
}

kiwi::Array<kiwi::String> &PropValueData::set_values(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 2; return _data_values = pool.array<kiwi::String>(count);
}

kiwi::String *PropValueData::aliasProperty() {
  return _flags[0] & 4 ? &_data_aliasProperty : nullptr;
}

const kiwi::String *PropValueData::aliasProperty() const {
  return _flags[0] & 4 ? &_data_aliasProperty : nullptr;
}

void PropValueData::set_aliasProperty(const kiwi::String &value) {
  _flags[0] |= 4; _data_aliasProperty = value;
}

kiwi::Array<kiwi::String> *PropValueData::aliasValues() {
  return _flags[0] & 8 ? &_data_aliasValues : nullptr;
}

const kiwi::Array<kiwi::String> *PropValueData::aliasValues() const {
  return _flags[0] & 8 ? &_data_aliasValues : nullptr;
}

kiwi::Array<kiwi::String> &PropValueData::set_aliasValues(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 8; return _data_aliasValues = pool.array<kiwi::String>(count);
}

bool PropValueData::encode(kiwi::ByteBuffer &_bb) {
  if (property() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeString(_data_property.c_str());
  }
  if (values() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarUint(_data_values.size());
    for (kiwi::String &_it : _data_values) _bb.writeString(_it.c_str());
  }
  if (aliasProperty() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeString(_data_aliasProperty.c_str());
  }
  if (aliasValues() != nullptr) {
    _bb.writeVarUint(4);
    _bb.writeVarUint(_data_aliasValues.size());
    for (kiwi::String &_it : _data_aliasValues) _bb.writeString(_it.c_str());
  }
  _bb.writeVarUint(0);
  return true;
}

bool PropValueData::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readString(_data_property, _pool)) return false;
        set_property(_data_property);
        break;
      }
      case 2: {
        if (!_bb.readVarUint(_count)) return false;
        for (kiwi::String &_it : set_values(_pool, _count)) if (!_bb.readString(_it, _pool)) return false;
        break;
      }
      case 3: {
        if (!_bb.readString(_data_aliasProperty, _pool)) return false;
        set_aliasProperty(_data_aliasProperty);
        break;
      }
      case 4: {
        if (!_bb.readVarUint(_count)) return false;
        for (kiwi::String &_it : set_aliasValues(_pool, _count)) if (!_bb.readString(_it, _pool)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipPropValueDataField(_bb, _type)) return false;
        break;
      }
    }
  }
}

int32_t *SceneGraphQuery::depth() {
  return _flags[0] & 1 ? &_data_depth : nullptr;
}

const int32_t *SceneGraphQuery::depth() const {
  return _flags[0] & 1 ? &_data_depth : nullptr;
}

void SceneGraphQuery::set_depth(const int32_t &value) {
  _flags[0] |= 1; _data_depth = value;
}

GUID *SceneGraphQuery::startingNode() {
  return _data_startingNode;
}

const GUID *SceneGraphQuery::startingNode() const {
  return _data_startingNode;
}

void SceneGraphQuery::set_startingNode(GUID *value) {
  _data_startingNode = value;
}

bool SceneGraphQuery::encode(kiwi::ByteBuffer &_bb) {
  if (depth() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarInt(_data_depth);
  }
  if (startingNode() != nullptr) {
    _bb.writeVarUint(2);
    if (!_data_startingNode->encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool SceneGraphQuery::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarInt(_data_depth)) return false;
        set_depth(_data_depth);
        break;
      }
      case 2: {
        _data_startingNode = _pool.allocate<GUID>();
        if (!_data_startingNode->decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipSceneGraphQueryField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::String *PrototypeStartPoint::description() {
  return _flags[0] & 1 ? &_data_description : nullptr;
}

const kiwi::String *PrototypeStartPoint::description() const {
  return _flags[0] & 1 ? &_data_description : nullptr;
}

void PrototypeStartPoint::set_description(const kiwi::String &value) {
  _flags[0] |= 1; _data_description = value;
}

kiwi::String *PrototypeStartPoint::name() {
  return _flags[0] & 2 ? &_data_name : nullptr;
}

const kiwi::String *PrototypeStartPoint::name() const {
  return _flags[0] & 2 ? &_data_name : nullptr;
}

void PrototypeStartPoint::set_name(const kiwi::String &value) {
  _flags[0] |= 2; _data_name = value;
}

kiwi::String *PrototypeStartPoint::position() {
  return _flags[0] & 4 ? &_data_position : nullptr;
}

const kiwi::String *PrototypeStartPoint::position() const {
  return _flags[0] & 4 ? &_data_position : nullptr;
}

void PrototypeStartPoint::set_position(const kiwi::String &value) {
  _flags[0] |= 4; _data_position = value;
}

bool PrototypeStartPoint::encode(kiwi::ByteBuffer &_bb) {
  if (description() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeString(_data_description.c_str());
  }
  if (name() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeString(_data_name.c_str());
  }
  if (position() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeString(_data_position.c_str());
  }
  _bb.writeVarUint(0);
  return true;
}

bool PrototypeStartPoint::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readString(_data_description, _pool)) return false;
        set_description(_data_description);
        break;
      }
      case 2: {
        if (!_bb.readString(_data_name, _pool)) return false;
        set_name(_data_name);
        break;
      }
      case 3: {
        if (!_bb.readString(_data_position, _pool)) return false;
        set_position(_data_position);
        break;
      }
      default: {
        if (!_schema || !_schema->skipPrototypeStartPointField(_bb, _type)) return false;
        break;
      }
    }
  }
}

ConnectLineType *ConnectLineInfo::connlineType() {
  return _flags[0] & 1 ? &_data_connlineType : nullptr;
}

const ConnectLineType *ConnectLineInfo::connlineType() const {
  return _flags[0] & 1 ? &_data_connlineType : nullptr;
}

void ConnectLineInfo::set_connlineType(const ConnectLineType &value) {
  _flags[0] |= 1; _data_connlineType = value;
}

bool *ConnectLineInfo::isFree() {
  return _flags[0] & 2 ? &_data_isFree : nullptr;
}

const bool *ConnectLineInfo::isFree() const {
  return _flags[0] & 2 ? &_data_isFree : nullptr;
}

void ConnectLineInfo::set_isFree(const bool &value) {
  _flags[0] |= 2; _data_isFree = value;
}

kiwi::Array<GUID> *ConnectLineInfo::connlineSnapObj() {
  return _flags[0] & 4 ? &_data_connlineSnapObj : nullptr;
}

const kiwi::Array<GUID> *ConnectLineInfo::connlineSnapObj() const {
  return _flags[0] & 4 ? &_data_connlineSnapObj : nullptr;
}

kiwi::Array<GUID> &ConnectLineInfo::set_connlineSnapObj(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 4; return _data_connlineSnapObj = pool.array<GUID>(count);
}

ConnLineTextAngleType *ConnectLineInfo::textAngleType() {
  return _flags[0] & 8 ? &_data_textAngleType : nullptr;
}

const ConnLineTextAngleType *ConnectLineInfo::textAngleType() const {
  return _flags[0] & 8 ? &_data_textAngleType : nullptr;
}

void ConnectLineInfo::set_textAngleType(const ConnLineTextAngleType &value) {
  _flags[0] |= 8; _data_textAngleType = value;
}

bool ConnectLineInfo::encode(kiwi::ByteBuffer &_bb) {
  if (connlineType() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(static_cast<uint32_t>(_data_connlineType));
  }
  if (isFree() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeByte(_data_isFree);
  }
  if (connlineSnapObj() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeVarUint(_data_connlineSnapObj.size());
    for (GUID &_it : _data_connlineSnapObj) if (!_it.encode(_bb)) return false;
  }
  if (textAngleType() != nullptr) {
    _bb.writeVarUint(4);
    _bb.writeVarUint(static_cast<uint32_t>(_data_textAngleType));
  }
  _bb.writeVarUint(0);
  return true;
}

bool ConnectLineInfo::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_connlineType))) return false;
        set_connlineType(_data_connlineType);
        break;
      }
      case 2: {
        if (!_bb.readByte(_data_isFree)) return false;
        set_isFree(_data_isFree);
        break;
      }
      case 3: {
        if (!_bb.readVarUint(_count)) return false;
        for (GUID &_it : set_connlineSnapObj(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 4: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_textAngleType))) return false;
        set_textAngleType(_data_textAngleType);
        break;
      }
      default: {
        if (!_schema || !_schema->skipConnectLineInfoField(_bb, _type)) return false;
        break;
      }
    }
  }
}

GUID *ObjSnapConnline::guid() {
  return _data_guid;
}

const GUID *ObjSnapConnline::guid() const {
  return _data_guid;
}

void ObjSnapConnline::set_guid(GUID *value) {
  _data_guid = value;
}

ConnectPointType *ObjSnapConnline::connectPointType() {
  return _flags[0] & 2 ? &_data_connectPointType : nullptr;
}

const ConnectPointType *ObjSnapConnline::connectPointType() const {
  return _flags[0] & 2 ? &_data_connectPointType : nullptr;
}

void ObjSnapConnline::set_connectPointType(const ConnectPointType &value) {
  _flags[0] |= 2; _data_connectPointType = value;
}

SnapToObjType *ObjSnapConnline::snapToObjType() {
  return _flags[0] & 4 ? &_data_snapToObjType : nullptr;
}

const SnapToObjType *ObjSnapConnline::snapToObjType() const {
  return _flags[0] & 4 ? &_data_snapToObjType : nullptr;
}

void ObjSnapConnline::set_snapToObjType(const SnapToObjType &value) {
  _flags[0] |= 4; _data_snapToObjType = value;
}

Vector *ObjSnapConnline::rate() {
  return _data_rate;
}

const Vector *ObjSnapConnline::rate() const {
  return _data_rate;
}

void ObjSnapConnline::set_rate(Vector *value) {
  _data_rate = value;
}

bool ObjSnapConnline::encode(kiwi::ByteBuffer &_bb) {
  if (guid() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_guid->encode(_bb)) return false;
  }
  if (connectPointType() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarUint(static_cast<uint32_t>(_data_connectPointType));
  }
  if (snapToObjType() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeVarUint(static_cast<uint32_t>(_data_snapToObjType));
  }
  if (rate() != nullptr) {
    _bb.writeVarUint(4);
    if (!_data_rate->encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool ObjSnapConnline::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_guid = _pool.allocate<GUID>();
        if (!_data_guid->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_connectPointType))) return false;
        set_connectPointType(_data_connectPointType);
        break;
      }
      case 3: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_snapToObjType))) return false;
        set_snapToObjType(_data_snapToObjType);
        break;
      }
      case 4: {
        _data_rate = _pool.allocate<Vector>();
        if (!_data_rate->decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipObjSnapConnlineField(_bb, _type)) return false;
        break;
      }
    }
  }
}

GUID *ConnlineTextInfo::textGuid() {
  return _data_textGuid;
}

const GUID *ConnlineTextInfo::textGuid() const {
  return _data_textGuid;
}

void ConnlineTextInfo::set_textGuid(GUID *value) {
  _data_textGuid = value;
}

float *ConnlineTextInfo::rate() {
  return _flags[0] & 2 ? &_data_rate : nullptr;
}

const float *ConnlineTextInfo::rate() const {
  return _flags[0] & 2 ? &_data_rate : nullptr;
}

void ConnlineTextInfo::set_rate(const float &value) {
  _flags[0] |= 2; _data_rate = value;
}

bool ConnlineTextInfo::encode(kiwi::ByteBuffer &_bb) {
  if (textGuid() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_textGuid->encode(_bb)) return false;
  }
  if (rate() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarFloat(_data_rate);
  }
  _bb.writeVarUint(0);
  return true;
}

bool ConnlineTextInfo::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_textGuid = _pool.allocate<GUID>();
        if (!_data_textGuid->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        if (!_bb.readVarFloat(_data_rate)) return false;
        set_rate(_data_rate);
        break;
      }
      default: {
        if (!_schema || !_schema->skipConnlineTextInfoField(_bb, _type)) return false;
        break;
      }
    }
  }
}

int32_t *VectorPaint::regionId() {
  return _flags[0] & 1 ? &_data_regionId : nullptr;
}

const int32_t *VectorPaint::regionId() const {
  return _flags[0] & 1 ? &_data_regionId : nullptr;
}

void VectorPaint::set_regionId(const int32_t &value) {
  _flags[0] |= 1; _data_regionId = value;
}

kiwi::Array<Paint> *VectorPaint::paints() {
  return _flags[0] & 2 ? &_data_paints : nullptr;
}

const kiwi::Array<Paint> *VectorPaint::paints() const {
  return _flags[0] & 2 ? &_data_paints : nullptr;
}

kiwi::Array<Paint> &VectorPaint::set_paints(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 2; return _data_paints = pool.array<Paint>(count);
}

bool VectorPaint::encode(kiwi::ByteBuffer &_bb) {
  if (regionId() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarInt(_data_regionId);
  }
  if (paints() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarUint(_data_paints.size());
    for (Paint &_it : _data_paints) if (!_it.encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool VectorPaint::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarInt(_data_regionId)) return false;
        set_regionId(_data_regionId);
        break;
      }
      case 2: {
        if (!_bb.readVarUint(_count)) return false;
        for (Paint &_it : set_paints(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipVectorPaintField(_bb, _type)) return false;
        break;
      }
    }
  }
}

int32_t *VectorStyle::regionId() {
  return _flags[0] & 1 ? &_data_regionId : nullptr;
}

const int32_t *VectorStyle::regionId() const {
  return _flags[0] & 1 ? &_data_regionId : nullptr;
}

void VectorStyle::set_regionId(const int32_t &value) {
  _flags[0] |= 1; _data_regionId = value;
}

GUID *VectorStyle::id() {
  return _data_id;
}

const GUID *VectorStyle::id() const {
  return _data_id;
}

void VectorStyle::set_id(GUID *value) {
  _data_id = value;
}

bool VectorStyle::encode(kiwi::ByteBuffer &_bb) {
  if (regionId() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarInt(_data_regionId);
  }
  if (id() != nullptr) {
    _bb.writeVarUint(2);
    if (!_data_id->encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool VectorStyle::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarInt(_data_regionId)) return false;
        set_regionId(_data_regionId);
        break;
      }
      case 2: {
        _data_id = _pool.allocate<GUID>();
        if (!_data_id->decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipVectorStyleField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::String *PluginData::pluginID() {
  return _flags[0] & 1 ? &_data_pluginID : nullptr;
}

const kiwi::String *PluginData::pluginID() const {
  return _flags[0] & 1 ? &_data_pluginID : nullptr;
}

void PluginData::set_pluginID(const kiwi::String &value) {
  _flags[0] |= 1; _data_pluginID = value;
}

kiwi::String *PluginData::value() {
  return _flags[0] & 2 ? &_data_value : nullptr;
}

const kiwi::String *PluginData::value() const {
  return _flags[0] & 2 ? &_data_value : nullptr;
}

void PluginData::set_value(const kiwi::String &value) {
  _flags[0] |= 2; _data_value = value;
}

kiwi::String *PluginData::key() {
  return _flags[0] & 4 ? &_data_key : nullptr;
}

const kiwi::String *PluginData::key() const {
  return _flags[0] & 4 ? &_data_key : nullptr;
}

void PluginData::set_key(const kiwi::String &value) {
  _flags[0] |= 4; _data_key = value;
}

bool PluginData::encode(kiwi::ByteBuffer &_bb) {
  if (pluginID() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeString(_data_pluginID.c_str());
  }
  if (value() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeString(_data_value.c_str());
  }
  if (key() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeString(_data_key.c_str());
  }
  _bb.writeVarUint(0);
  return true;
}

bool PluginData::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readString(_data_pluginID, _pool)) return false;
        set_pluginID(_data_pluginID);
        break;
      }
      case 2: {
        if (!_bb.readString(_data_value, _pool)) return false;
        set_value(_data_value);
        break;
      }
      case 3: {
        if (!_bb.readString(_data_key, _pool)) return false;
        set_key(_data_key);
        break;
      }
      default: {
        if (!_schema || !_schema->skipPluginDataField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::String *PluginRelaunchData::pluginID() {
  return _flags[0] & 1 ? &_data_pluginID : nullptr;
}

const kiwi::String *PluginRelaunchData::pluginID() const {
  return _flags[0] & 1 ? &_data_pluginID : nullptr;
}

void PluginRelaunchData::set_pluginID(const kiwi::String &value) {
  _flags[0] |= 1; _data_pluginID = value;
}

kiwi::String *PluginRelaunchData::message() {
  return _flags[0] & 2 ? &_data_message : nullptr;
}

const kiwi::String *PluginRelaunchData::message() const {
  return _flags[0] & 2 ? &_data_message : nullptr;
}

void PluginRelaunchData::set_message(const kiwi::String &value) {
  _flags[0] |= 2; _data_message = value;
}

kiwi::String *PluginRelaunchData::command() {
  return _flags[0] & 4 ? &_data_command : nullptr;
}

const kiwi::String *PluginRelaunchData::command() const {
  return _flags[0] & 4 ? &_data_command : nullptr;
}

void PluginRelaunchData::set_command(const kiwi::String &value) {
  _flags[0] |= 4; _data_command = value;
}

bool *PluginRelaunchData::isDeleted() {
  return _flags[0] & 8 ? &_data_isDeleted : nullptr;
}

const bool *PluginRelaunchData::isDeleted() const {
  return _flags[0] & 8 ? &_data_isDeleted : nullptr;
}

void PluginRelaunchData::set_isDeleted(const bool &value) {
  _flags[0] |= 8; _data_isDeleted = value;
}

bool PluginRelaunchData::encode(kiwi::ByteBuffer &_bb) {
  if (pluginID() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeString(_data_pluginID.c_str());
  }
  if (message() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeString(_data_message.c_str());
  }
  if (command() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeString(_data_command.c_str());
  }
  if (isDeleted() != nullptr) {
    _bb.writeVarUint(4);
    _bb.writeByte(_data_isDeleted);
  }
  _bb.writeVarUint(0);
  return true;
}

bool PluginRelaunchData::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readString(_data_pluginID, _pool)) return false;
        set_pluginID(_data_pluginID);
        break;
      }
      case 2: {
        if (!_bb.readString(_data_message, _pool)) return false;
        set_message(_data_message);
        break;
      }
      case 3: {
        if (!_bb.readString(_data_command, _pool)) return false;
        set_command(_data_command);
        break;
      }
      case 4: {
        if (!_bb.readByte(_data_isDeleted)) return false;
        set_isDeleted(_data_isDeleted);
        break;
      }
      default: {
        if (!_schema || !_schema->skipPluginRelaunchDataField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::Array<int32_t> *PlaceHolder::emojiCodePoints() {
  return _flags[0] & 1 ? &_data_emojiCodePoints : nullptr;
}

const kiwi::Array<int32_t> *PlaceHolder::emojiCodePoints() const {
  return _flags[0] & 1 ? &_data_emojiCodePoints : nullptr;
}

kiwi::Array<int32_t> &PlaceHolder::set_emojiCodePoints(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 1; return _data_emojiCodePoints = pool.array<int32_t>(count);
}

Rect *PlaceHolder::bound() {
  return _data_bound;
}

const Rect *PlaceHolder::bound() const {
  return _data_bound;
}

void PlaceHolder::set_bound(Rect *value) {
  _data_bound = value;
}

int32_t *PlaceHolder::firstCharacter() {
  return _flags[0] & 4 ? &_data_firstCharacter : nullptr;
}

const int32_t *PlaceHolder::firstCharacter() const {
  return _flags[0] & 4 ? &_data_firstCharacter : nullptr;
}

void PlaceHolder::set_firstCharacter(const int32_t &value) {
  _flags[0] |= 4; _data_firstCharacter = value;
}

GlyphPose *PlaceHolder::pose() {
  return _data_pose;
}

const GlyphPose *PlaceHolder::pose() const {
  return _data_pose;
}

void PlaceHolder::set_pose(GlyphPose *value) {
  _data_pose = value;
}

bool PlaceHolder::encode(kiwi::ByteBuffer &_bb) {
  if (emojiCodePoints() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(_data_emojiCodePoints.size());
    for (int32_t &_it : _data_emojiCodePoints) _bb.writeVarInt(_it);
  }
  if (bound() != nullptr) {
    _bb.writeVarUint(2);
    if (!_data_bound->encode(_bb)) return false;
  }
  if (firstCharacter() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeVarInt(_data_firstCharacter);
  }
  if (pose() != nullptr) {
    _bb.writeVarUint(4);
    if (!_data_pose->encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool PlaceHolder::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(_count)) return false;
        for (int32_t &_it : set_emojiCodePoints(_pool, _count)) if (!_bb.readVarInt(_it)) return false;
        break;
      }
      case 2: {
        _data_bound = _pool.allocate<Rect>();
        if (!_data_bound->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 3: {
        if (!_bb.readVarInt(_data_firstCharacter)) return false;
        set_firstCharacter(_data_firstCharacter);
        break;
      }
      case 4: {
        _data_pose = _pool.allocate<GlyphPose>();
        if (!_data_pose->decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipPlaceHolderField(_bb, _type)) return false;
        break;
      }
    }
  }
}

uint32_t *Spotlight::sessionID() {
  return _flags[0] & 1 ? &_data_sessionID : nullptr;
}

const uint32_t *Spotlight::sessionID() const {
  return _flags[0] & 1 ? &_data_sessionID : nullptr;
}

void Spotlight::set_sessionID(const uint32_t &value) {
  _flags[0] |= 1; _data_sessionID = value;
}

kiwi::String *Spotlight::userID() {
  return _flags[0] & 2 ? &_data_userID : nullptr;
}

const kiwi::String *Spotlight::userID() const {
  return _flags[0] & 2 ? &_data_userID : nullptr;
}

void Spotlight::set_userID(const kiwi::String &value) {
  _flags[0] |= 2; _data_userID = value;
}

bool Spotlight::encode(kiwi::ByteBuffer &_bb) {
  if (sessionID() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(_data_sessionID);
  }
  if (userID() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeString(_data_userID.c_str());
  }
  _bb.writeVarUint(0);
  return true;
}

bool Spotlight::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(_data_sessionID)) return false;
        set_sessionID(_data_sessionID);
        break;
      }
      case 2: {
        if (!_bb.readString(_data_userID, _pool)) return false;
        set_userID(_data_userID);
        break;
      }
      default: {
        if (!_schema || !_schema->skipSpotlightField(_bb, _type)) return false;
        break;
      }
    }
  }
}

FileSource *FileMeta::fileSource() {
  return _flags[0] & 1 ? &_data_fileSource : nullptr;
}

const FileSource *FileMeta::fileSource() const {
  return _flags[0] & 1 ? &_data_fileSource : nullptr;
}

void FileMeta::set_fileSource(const FileSource &value) {
  _flags[0] |= 1; _data_fileSource = value;
}

FontIncorrect *FileMeta::fontIncorrect() {
  return _flags[0] & 2 ? &_data_fontIncorrect : nullptr;
}

const FontIncorrect *FileMeta::fontIncorrect() const {
  return _flags[0] & 2 ? &_data_fontIncorrect : nullptr;
}

void FileMeta::set_fontIncorrect(const FontIncorrect &value) {
  _flags[0] |= 2; _data_fontIncorrect = value;
}

bool FileMeta::encode(kiwi::ByteBuffer &_bb) {
  if (fileSource() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(static_cast<uint32_t>(_data_fileSource));
  }
  if (fontIncorrect() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarUint(static_cast<uint32_t>(_data_fontIncorrect));
  }
  _bb.writeVarUint(0);
  return true;
}

bool FileMeta::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_fileSource))) return false;
        set_fileSource(_data_fileSource);
        break;
      }
      case 2: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_fontIncorrect))) return false;
        set_fontIncorrect(_data_fontIncorrect);
        break;
      }
      default: {
        if (!_schema || !_schema->skipFileMetaField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::String *EditInfo::userID() {
  return _flags[0] & 1 ? &_data_userID : nullptr;
}

const kiwi::String *EditInfo::userID() const {
  return _flags[0] & 1 ? &_data_userID : nullptr;
}

void EditInfo::set_userID(const kiwi::String &value) {
  _flags[0] |= 1; _data_userID = value;
}

uint32_t *EditInfo::lastEditedAt() {
  return _flags[0] & 2 ? &_data_lastEditedAt : nullptr;
}

const uint32_t *EditInfo::lastEditedAt() const {
  return _flags[0] & 2 ? &_data_lastEditedAt : nullptr;
}

void EditInfo::set_lastEditedAt(const uint32_t &value) {
  _flags[0] |= 2; _data_lastEditedAt = value;
}

uint32_t *EditInfo::createAt() {
  return _flags[0] & 4 ? &_data_createAt : nullptr;
}

const uint32_t *EditInfo::createAt() const {
  return _flags[0] & 4 ? &_data_createAt : nullptr;
}

void EditInfo::set_createAt(const uint32_t &value) {
  _flags[0] |= 4; _data_createAt = value;
}

bool EditInfo::encode(kiwi::ByteBuffer &_bb) {
  if (userID() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeString(_data_userID.c_str());
  }
  if (lastEditedAt() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarUint(_data_lastEditedAt);
  }
  if (createAt() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeVarUint(_data_createAt);
  }
  _bb.writeVarUint(0);
  return true;
}

bool EditInfo::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readString(_data_userID, _pool)) return false;
        set_userID(_data_userID);
        break;
      }
      case 2: {
        if (!_bb.readVarUint(_data_lastEditedAt)) return false;
        set_lastEditedAt(_data_lastEditedAt);
        break;
      }
      case 3: {
        if (!_bb.readVarUint(_data_createAt)) return false;
        set_createAt(_data_createAt);
        break;
      }
      default: {
        if (!_schema || !_schema->skipEditInfoField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::String *SymbolLink::uri() {
  return _flags[0] & 1 ? &_data_uri : nullptr;
}

const kiwi::String *SymbolLink::uri() const {
  return _flags[0] & 1 ? &_data_uri : nullptr;
}

void SymbolLink::set_uri(const kiwi::String &value) {
  _flags[0] |= 1; _data_uri = value;
}

kiwi::String *SymbolLink::displayName() {
  return _flags[0] & 2 ? &_data_displayName : nullptr;
}

const kiwi::String *SymbolLink::displayName() const {
  return _flags[0] & 2 ? &_data_displayName : nullptr;
}

void SymbolLink::set_displayName(const kiwi::String &value) {
  _flags[0] |= 2; _data_displayName = value;
}

kiwi::String *SymbolLink::displayText() {
  return _flags[0] & 4 ? &_data_displayText : nullptr;
}

const kiwi::String *SymbolLink::displayText() const {
  return _flags[0] & 4 ? &_data_displayText : nullptr;
}

void SymbolLink::set_displayText(const kiwi::String &value) {
  _flags[0] |= 4; _data_displayText = value;
}

bool SymbolLink::encode(kiwi::ByteBuffer &_bb) {
  if (uri() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeString(_data_uri.c_str());
  }
  if (displayName() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeString(_data_displayName.c_str());
  }
  if (displayText() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeString(_data_displayText.c_str());
  }
  _bb.writeVarUint(0);
  return true;
}

bool SymbolLink::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readString(_data_uri, _pool)) return false;
        set_uri(_data_uri);
        break;
      }
      case 2: {
        if (!_bb.readString(_data_displayName, _pool)) return false;
        set_displayName(_data_displayName);
        break;
      }
      case 3: {
        if (!_bb.readString(_data_displayText, _pool)) return false;
        set_displayText(_data_displayText);
        break;
      }
      default: {
        if (!_schema || !_schema->skipSymbolLinkField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::String *DeveloperRelatedLink::linkName() {
  return _flags[0] & 1 ? &_data_linkName : nullptr;
}

const kiwi::String *DeveloperRelatedLink::linkName() const {
  return _flags[0] & 1 ? &_data_linkName : nullptr;
}

void DeveloperRelatedLink::set_linkName(const kiwi::String &value) {
  _flags[0] |= 1; _data_linkName = value;
}

kiwi::String *DeveloperRelatedLink::linkUrl() {
  return _flags[0] & 2 ? &_data_linkUrl : nullptr;
}

const kiwi::String *DeveloperRelatedLink::linkUrl() const {
  return _flags[0] & 2 ? &_data_linkUrl : nullptr;
}

void DeveloperRelatedLink::set_linkUrl(const kiwi::String &value) {
  _flags[0] |= 2; _data_linkUrl = value;
}

bool DeveloperRelatedLink::encode(kiwi::ByteBuffer &_bb) {
  if (linkName() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeString(_data_linkName.c_str());
  }
  if (linkUrl() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeString(_data_linkUrl.c_str());
  }
  _bb.writeVarUint(0);
  return true;
}

bool DeveloperRelatedLink::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readString(_data_linkName, _pool)) return false;
        set_linkName(_data_linkName);
        break;
      }
      case 2: {
        if (!_bb.readString(_data_linkUrl, _pool)) return false;
        set_linkUrl(_data_linkUrl);
        break;
      }
      default: {
        if (!_schema || !_schema->skipDeveloperRelatedLinkField(_bb, _type)) return false;
        break;
      }
    }
  }
}

uint32_t *FontVariation::axisTag() {
  return _flags[0] & 1 ? &_data_axisTag : nullptr;
}

const uint32_t *FontVariation::axisTag() const {
  return _flags[0] & 1 ? &_data_axisTag : nullptr;
}

void FontVariation::set_axisTag(const uint32_t &value) {
  _flags[0] |= 1; _data_axisTag = value;
}

kiwi::String *FontVariation::axisName() {
  return _flags[0] & 2 ? &_data_axisName : nullptr;
}

const kiwi::String *FontVariation::axisName() const {
  return _flags[0] & 2 ? &_data_axisName : nullptr;
}

void FontVariation::set_axisName(const kiwi::String &value) {
  _flags[0] |= 2; _data_axisName = value;
}

float *FontVariation::value() {
  return _flags[0] & 4 ? &_data_value : nullptr;
}

const float *FontVariation::value() const {
  return _flags[0] & 4 ? &_data_value : nullptr;
}

void FontVariation::set_value(const float &value) {
  _flags[0] |= 4; _data_value = value;
}

bool FontVariation::encode(kiwi::ByteBuffer &_bb) {
  if (axisTag() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(_data_axisTag);
  }
  if (axisName() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeString(_data_axisName.c_str());
  }
  if (value() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeVarFloat(_data_value);
  }
  _bb.writeVarUint(0);
  return true;
}

bool FontVariation::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(_data_axisTag)) return false;
        set_axisTag(_data_axisTag);
        break;
      }
      case 2: {
        if (!_bb.readString(_data_axisName, _pool)) return false;
        set_axisName(_data_axisName);
        break;
      }
      case 3: {
        if (!_bb.readVarFloat(_data_value)) return false;
        set_value(_data_value);
        break;
      }
      default: {
        if (!_schema || !_schema->skipFontVariationField(_bb, _type)) return false;
        break;
      }
    }
  }
}

bool *PathTextInfo::flipGlyphs() {
  return _flags[0] & 1 ? &_data_flipGlyphs : nullptr;
}

const bool *PathTextInfo::flipGlyphs() const {
  return _flags[0] & 1 ? &_data_flipGlyphs : nullptr;
}

void PathTextInfo::set_flipGlyphs(const bool &value) {
  _flags[0] |= 1; _data_flipGlyphs = value;
}

bool *PathTextInfo::reverse() {
  return _flags[0] & 2 ? &_data_reverse : nullptr;
}

const bool *PathTextInfo::reverse() const {
  return _flags[0] & 2 ? &_data_reverse : nullptr;
}

void PathTextInfo::set_reverse(const bool &value) {
  _flags[0] |= 2; _data_reverse = value;
}

float *PathTextInfo::hOffset() {
  return _flags[0] & 4 ? &_data_hOffset : nullptr;
}

const float *PathTextInfo::hOffset() const {
  return _flags[0] & 4 ? &_data_hOffset : nullptr;
}

void PathTextInfo::set_hOffset(const float &value) {
  _flags[0] |= 4; _data_hOffset = value;
}

float *PathTextInfo::vOffset() {
  return _flags[0] & 8 ? &_data_vOffset : nullptr;
}

const float *PathTextInfo::vOffset() const {
  return _flags[0] & 8 ? &_data_vOffset : nullptr;
}

void PathTextInfo::set_vOffset(const float &value) {
  _flags[0] |= 8; _data_vOffset = value;
}

float *PathTextInfo::tValue() {
  return _flags[0] & 16 ? &_data_tValue : nullptr;
}

const float *PathTextInfo::tValue() const {
  return _flags[0] & 16 ? &_data_tValue : nullptr;
}

void PathTextInfo::set_tValue(const float &value) {
  _flags[0] |= 16; _data_tValue = value;
}

bool PathTextInfo::encode(kiwi::ByteBuffer &_bb) {
  if (flipGlyphs() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeByte(_data_flipGlyphs);
  }
  if (reverse() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeByte(_data_reverse);
  }
  if (hOffset() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeVarFloat(_data_hOffset);
  }
  if (vOffset() != nullptr) {
    _bb.writeVarUint(4);
    _bb.writeVarFloat(_data_vOffset);
  }
  if (tValue() != nullptr) {
    _bb.writeVarUint(5);
    _bb.writeVarFloat(_data_tValue);
  }
  _bb.writeVarUint(0);
  return true;
}

bool PathTextInfo::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readByte(_data_flipGlyphs)) return false;
        set_flipGlyphs(_data_flipGlyphs);
        break;
      }
      case 2: {
        if (!_bb.readByte(_data_reverse)) return false;
        set_reverse(_data_reverse);
        break;
      }
      case 3: {
        if (!_bb.readVarFloat(_data_hOffset)) return false;
        set_hOffset(_data_hOffset);
        break;
      }
      case 4: {
        if (!_bb.readVarFloat(_data_vOffset)) return false;
        set_vOffset(_data_vOffset);
        break;
      }
      case 5: {
        if (!_bb.readVarFloat(_data_tValue)) return false;
        set_tValue(_data_tValue);
        break;
      }
      default: {
        if (!_schema || !_schema->skipPathTextInfoField(_bb, _type)) return false;
        break;
      }
    }
  }
}

float *GlyphPose::x() {
  return _flags[0] & 1 ? &_data_x : nullptr;
}

const float *GlyphPose::x() const {
  return _flags[0] & 1 ? &_data_x : nullptr;
}

void GlyphPose::set_x(const float &value) {
  _flags[0] |= 1; _data_x = value;
}

float *GlyphPose::y() {
  return _flags[0] & 2 ? &_data_y : nullptr;
}

const float *GlyphPose::y() const {
  return _flags[0] & 2 ? &_data_y : nullptr;
}

void GlyphPose::set_y(const float &value) {
  _flags[0] |= 2; _data_y = value;
}

float *GlyphPose::angle() {
  return _flags[0] & 4 ? &_data_angle : nullptr;
}

const float *GlyphPose::angle() const {
  return _flags[0] & 4 ? &_data_angle : nullptr;
}

void GlyphPose::set_angle(const float &value) {
  _flags[0] |= 4; _data_angle = value;
}

bool GlyphPose::encode(kiwi::ByteBuffer &_bb) {
  if (x() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarFloat(_data_x);
  }
  if (y() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarFloat(_data_y);
  }
  if (angle() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeVarFloat(_data_angle);
  }
  _bb.writeVarUint(0);
  return true;
}

bool GlyphPose::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarFloat(_data_x)) return false;
        set_x(_data_x);
        break;
      }
      case 2: {
        if (!_bb.readVarFloat(_data_y)) return false;
        set_y(_data_y);
        break;
      }
      case 3: {
        if (!_bb.readVarFloat(_data_angle)) return false;
        set_angle(_data_angle);
        break;
      }
      default: {
        if (!_schema || !_schema->skipGlyphPoseField(_bb, _type)) return false;
        break;
      }
    }
  }
}

int32_t *RadialRepeatData::copies() {
  return _flags[0] & 1 ? &_data_copies : nullptr;
}

const int32_t *RadialRepeatData::copies() const {
  return _flags[0] & 1 ? &_data_copies : nullptr;
}

void RadialRepeatData::set_copies(const int32_t &value) {
  _flags[0] |= 1; _data_copies = value;
}

float *RadialRepeatData::radius() {
  return _flags[0] & 2 ? &_data_radius : nullptr;
}

const float *RadialRepeatData::radius() const {
  return _flags[0] & 2 ? &_data_radius : nullptr;
}

void RadialRepeatData::set_radius(const float &value) {
  _flags[0] |= 2; _data_radius = value;
}

bool RadialRepeatData::encode(kiwi::ByteBuffer &_bb) {
  if (copies() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarInt(_data_copies);
  }
  if (radius() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarFloat(_data_radius);
  }
  _bb.writeVarUint(0);
  return true;
}

bool RadialRepeatData::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarInt(_data_copies)) return false;
        set_copies(_data_copies);
        break;
      }
      case 2: {
        if (!_bb.readVarFloat(_data_radius)) return false;
        set_radius(_data_radius);
        break;
      }
      default: {
        if (!_schema || !_schema->skipRadialRepeatDataField(_bb, _type)) return false;
        break;
      }
    }
  }
}

TransformModifierType *TransformModifier::type() {
  return _flags[0] & 1 ? &_data_type : nullptr;
}

const TransformModifierType *TransformModifier::type() const {
  return _flags[0] & 1 ? &_data_type : nullptr;
}

void TransformModifier::set_type(const TransformModifierType &value) {
  _flags[0] |= 1; _data_type = value;
}

Vector *TransformModifier::offset() {
  return _data_offset;
}

const Vector *TransformModifier::offset() const {
  return _data_offset;
}

void TransformModifier::set_offset(Vector *value) {
  _data_offset = value;
}

bool *TransformModifier::visible() {
  return _flags[0] & 4 ? &_data_visible : nullptr;
}

const bool *TransformModifier::visible() const {
  return _flags[0] & 4 ? &_data_visible : nullptr;
}

void TransformModifier::set_visible(const bool &value) {
  _flags[0] |= 4; _data_visible = value;
}

uint32_t *TransformModifier::count() {
  return _flags[0] & 8 ? &_data_count : nullptr;
}

const uint32_t *TransformModifier::count() const {
  return _flags[0] & 8 ? &_data_count : nullptr;
}

void TransformModifier::set_count(const uint32_t &value) {
  _flags[0] |= 8; _data_count = value;
}

RepeatType *TransformModifier::repeatType() {
  return _flags[0] & 16 ? &_data_repeatType : nullptr;
}

const RepeatType *TransformModifier::repeatType() const {
  return _flags[0] & 16 ? &_data_repeatType : nullptr;
}

void TransformModifier::set_repeatType(const RepeatType &value) {
  _flags[0] |= 16; _data_repeatType = value;
}

Axis *TransformModifier::axis() {
  return _flags[0] & 32 ? &_data_axis : nullptr;
}

const Axis *TransformModifier::axis() const {
  return _flags[0] & 32 ? &_data_axis : nullptr;
}

void TransformModifier::set_axis(const Axis &value) {
  _flags[0] |= 32; _data_axis = value;
}

UnitType *TransformModifier::unitType() {
  return _flags[0] & 64 ? &_data_unitType : nullptr;
}

const UnitType *TransformModifier::unitType() const {
  return _flags[0] & 64 ? &_data_unitType : nullptr;
}

void TransformModifier::set_unitType(const UnitType &value) {
  _flags[0] |= 64; _data_unitType = value;
}

RepeatOrder *TransformModifier::order() {
  return _flags[0] & 128 ? &_data_order : nullptr;
}

const RepeatOrder *TransformModifier::order() const {
  return _flags[0] & 128 ? &_data_order : nullptr;
}

void TransformModifier::set_order(const RepeatOrder &value) {
  _flags[0] |= 128; _data_order = value;
}

bool TransformModifier::encode(kiwi::ByteBuffer &_bb) {
  if (type() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(static_cast<uint32_t>(_data_type));
  }
  if (offset() != nullptr) {
    _bb.writeVarUint(2);
    if (!_data_offset->encode(_bb)) return false;
  }
  if (visible() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeByte(_data_visible);
  }
  if (count() != nullptr) {
    _bb.writeVarUint(4);
    _bb.writeVarUint(_data_count);
  }
  if (repeatType() != nullptr) {
    _bb.writeVarUint(5);
    _bb.writeVarUint(static_cast<uint32_t>(_data_repeatType));
  }
  if (axis() != nullptr) {
    _bb.writeVarUint(6);
    _bb.writeVarUint(static_cast<uint32_t>(_data_axis));
  }
  if (unitType() != nullptr) {
    _bb.writeVarUint(7);
    _bb.writeVarUint(static_cast<uint32_t>(_data_unitType));
  }
  if (order() != nullptr) {
    _bb.writeVarUint(8);
    _bb.writeVarUint(static_cast<uint32_t>(_data_order));
  }
  _bb.writeVarUint(0);
  return true;
}

bool TransformModifier::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_type))) return false;
        set_type(_data_type);
        break;
      }
      case 2: {
        _data_offset = _pool.allocate<Vector>();
        if (!_data_offset->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 3: {
        if (!_bb.readByte(_data_visible)) return false;
        set_visible(_data_visible);
        break;
      }
      case 4: {
        if (!_bb.readVarUint(_data_count)) return false;
        set_count(_data_count);
        break;
      }
      case 5: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_repeatType))) return false;
        set_repeatType(_data_repeatType);
        break;
      }
      case 6: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_axis))) return false;
        set_axis(_data_axis);
        break;
      }
      case 7: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_unitType))) return false;
        set_unitType(_data_unitType);
        break;
      }
      case 8: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_order))) return false;
        set_order(_data_order);
        break;
      }
      default: {
        if (!_schema || !_schema->skipTransformModifierField(_bb, _type)) return false;
        break;
      }
    }
  }
}

GUID *AssetID::guid() {
  return _data_guid;
}

const GUID *AssetID::guid() const {
  return _data_guid;
}

void AssetID::set_guid(GUID *value) {
  _data_guid = value;
}

AssetRef *AssetID::assetRef() {
  return _data_assetRef;
}

const AssetRef *AssetID::assetRef() const {
  return _data_assetRef;
}

void AssetID::set_assetRef(AssetRef *value) {
  _data_assetRef = value;
}

bool AssetID::encode(kiwi::ByteBuffer &_bb) {
  if (guid() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_guid->encode(_bb)) return false;
  }
  if (assetRef() != nullptr) {
    _bb.writeVarUint(2);
    if (!_data_assetRef->encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool AssetID::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_guid = _pool.allocate<GUID>();
        if (!_data_guid->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        _data_assetRef = _pool.allocate<AssetRef>();
        if (!_data_assetRef->decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipAssetIDField(_bb, _type)) return false;
        break;
      }
    }
  }
}

GUID *VariableSetMode::id() {
  return _data_id;
}

const GUID *VariableSetMode::id() const {
  return _data_id;
}

void VariableSetMode::set_id(GUID *value) {
  _data_id = value;
}

kiwi::String *VariableSetMode::name() {
  return _flags[0] & 2 ? &_data_name : nullptr;
}

const kiwi::String *VariableSetMode::name() const {
  return _flags[0] & 2 ? &_data_name : nullptr;
}

void VariableSetMode::set_name(const kiwi::String &value) {
  _flags[0] |= 2; _data_name = value;
}

kiwi::String *VariableSetMode::sortPosition() {
  return _flags[0] & 4 ? &_data_sortPosition : nullptr;
}

const kiwi::String *VariableSetMode::sortPosition() const {
  return _flags[0] & 4 ? &_data_sortPosition : nullptr;
}

void VariableSetMode::set_sortPosition(const kiwi::String &value) {
  _flags[0] |= 4; _data_sortPosition = value;
}

bool VariableSetMode::encode(kiwi::ByteBuffer &_bb) {
  if (id() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_id->encode(_bb)) return false;
  }
  if (name() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeString(_data_name.c_str());
  }
  if (sortPosition() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeString(_data_sortPosition.c_str());
  }
  _bb.writeVarUint(0);
  return true;
}

bool VariableSetMode::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_id = _pool.allocate<GUID>();
        if (!_data_id->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        if (!_bb.readString(_data_name, _pool)) return false;
        set_name(_data_name);
        break;
      }
      case 3: {
        if (!_bb.readString(_data_sortPosition, _pool)) return false;
        set_sortPosition(_data_sortPosition);
        break;
      }
      default: {
        if (!_schema || !_schema->skipVariableSetModeField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::Array<VariableDataValuesEntry> *VariableDataValues::entries() {
  return _flags[0] & 1 ? &_data_entries : nullptr;
}

const kiwi::Array<VariableDataValuesEntry> *VariableDataValues::entries() const {
  return _flags[0] & 1 ? &_data_entries : nullptr;
}

kiwi::Array<VariableDataValuesEntry> &VariableDataValues::set_entries(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 1; return _data_entries = pool.array<VariableDataValuesEntry>(count);
}

bool VariableDataValues::encode(kiwi::ByteBuffer &_bb) {
  if (entries() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(_data_entries.size());
    for (VariableDataValuesEntry &_it : _data_entries) if (!_it.encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool VariableDataValues::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(_count)) return false;
        for (VariableDataValuesEntry &_it : set_entries(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipVariableDataValuesField(_bb, _type)) return false;
        break;
      }
    }
  }
}

GUID *VariableDataValuesEntry::modeID() {
  return _data_modeID;
}

const GUID *VariableDataValuesEntry::modeID() const {
  return _data_modeID;
}

void VariableDataValuesEntry::set_modeID(GUID *value) {
  _data_modeID = value;
}

VariableData *VariableDataValuesEntry::variableData() {
  return _data_variableData;
}

const VariableData *VariableDataValuesEntry::variableData() const {
  return _data_variableData;
}

void VariableDataValuesEntry::set_variableData(VariableData *value) {
  _data_variableData = value;
}

bool VariableDataValuesEntry::encode(kiwi::ByteBuffer &_bb) {
  if (modeID() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_modeID->encode(_bb)) return false;
  }
  if (variableData() != nullptr) {
    _bb.writeVarUint(2);
    if (!_data_variableData->encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool VariableDataValuesEntry::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_modeID = _pool.allocate<GUID>();
        if (!_data_modeID->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        _data_variableData = _pool.allocate<VariableData>();
        if (!_data_variableData->decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipVariableDataValuesEntryField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::Array<VariableDataMapEntry> *VariableDataMap::entries() {
  return _flags[0] & 1 ? &_data_entries : nullptr;
}

const kiwi::Array<VariableDataMapEntry> *VariableDataMap::entries() const {
  return _flags[0] & 1 ? &_data_entries : nullptr;
}

kiwi::Array<VariableDataMapEntry> &VariableDataMap::set_entries(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 1; return _data_entries = pool.array<VariableDataMapEntry>(count);
}

bool VariableDataMap::encode(kiwi::ByteBuffer &_bb) {
  if (entries() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(_data_entries.size());
    for (VariableDataMapEntry &_it : _data_entries) if (!_it.encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool VariableDataMap::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(_count)) return false;
        for (VariableDataMapEntry &_it : set_entries(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipVariableDataMapField(_bb, _type)) return false;
        break;
      }
    }
  }
}

uint32_t *VariableDataMapEntry::nodeField() {
  return _flags[0] & 1 ? &_data_nodeField : nullptr;
}

const uint32_t *VariableDataMapEntry::nodeField() const {
  return _flags[0] & 1 ? &_data_nodeField : nullptr;
}

void VariableDataMapEntry::set_nodeField(const uint32_t &value) {
  _flags[0] |= 1; _data_nodeField = value;
}

VariableData *VariableDataMapEntry::variableData() {
  return _data_variableData;
}

const VariableData *VariableDataMapEntry::variableData() const {
  return _data_variableData;
}

void VariableDataMapEntry::set_variableData(VariableData *value) {
  _data_variableData = value;
}

VariableField *VariableDataMapEntry::variableField() {
  return _flags[0] & 4 ? &_data_variableField : nullptr;
}

const VariableField *VariableDataMapEntry::variableField() const {
  return _flags[0] & 4 ? &_data_variableField : nullptr;
}

void VariableDataMapEntry::set_variableField(const VariableField &value) {
  _flags[0] |= 4; _data_variableField = value;
}

bool VariableDataMapEntry::encode(kiwi::ByteBuffer &_bb) {
  if (nodeField() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(_data_nodeField);
  }
  if (variableData() != nullptr) {
    _bb.writeVarUint(2);
    if (!_data_variableData->encode(_bb)) return false;
  }
  if (variableField() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeVarUint(static_cast<uint32_t>(_data_variableField));
  }
  _bb.writeVarUint(0);
  return true;
}

bool VariableDataMapEntry::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(_data_nodeField)) return false;
        set_nodeField(_data_nodeField);
        break;
      }
      case 2: {
        _data_variableData = _pool.allocate<VariableData>();
        if (!_data_variableData->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 3: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_variableField))) return false;
        set_variableField(_data_variableField);
        break;
      }
      default: {
        if (!_schema || !_schema->skipVariableDataMapEntryField(_bb, _type)) return false;
        break;
      }
    }
  }
}

VariableAnyValue *VariableData::value() {
  return _data_value;
}

const VariableAnyValue *VariableData::value() const {
  return _data_value;
}

void VariableData::set_value(VariableAnyValue *value) {
  _data_value = value;
}

VariableDataType *VariableData::dataType() {
  return _flags[0] & 2 ? &_data_dataType : nullptr;
}

const VariableDataType *VariableData::dataType() const {
  return _flags[0] & 2 ? &_data_dataType : nullptr;
}

void VariableData::set_dataType(const VariableDataType &value) {
  _flags[0] |= 2; _data_dataType = value;
}

VariableResolvedDataType *VariableData::resolvedDataType() {
  return _flags[0] & 4 ? &_data_resolvedDataType : nullptr;
}

const VariableResolvedDataType *VariableData::resolvedDataType() const {
  return _flags[0] & 4 ? &_data_resolvedDataType : nullptr;
}

void VariableData::set_resolvedDataType(const VariableResolvedDataType &value) {
  _flags[0] |= 4; _data_resolvedDataType = value;
}

bool VariableData::encode(kiwi::ByteBuffer &_bb) {
  if (value() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_value->encode(_bb)) return false;
  }
  if (dataType() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarUint(static_cast<uint32_t>(_data_dataType));
  }
  if (resolvedDataType() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeVarUint(static_cast<uint32_t>(_data_resolvedDataType));
  }
  _bb.writeVarUint(0);
  return true;
}

bool VariableData::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_value = _pool.allocate<VariableAnyValue>();
        if (!_data_value->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_dataType))) return false;
        set_dataType(_data_dataType);
        break;
      }
      case 3: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_resolvedDataType))) return false;
        set_resolvedDataType(_data_resolvedDataType);
        break;
      }
      default: {
        if (!_schema || !_schema->skipVariableDataField(_bb, _type)) return false;
        break;
      }
    }
  }
}

bool *VariableAnyValue::boolValue() {
  return _flags[0] & 1 ? &_data_boolValue : nullptr;
}

const bool *VariableAnyValue::boolValue() const {
  return _flags[0] & 1 ? &_data_boolValue : nullptr;
}

void VariableAnyValue::set_boolValue(const bool &value) {
  _flags[0] |= 1; _data_boolValue = value;
}

kiwi::String *VariableAnyValue::textValue() {
  return _flags[0] & 2 ? &_data_textValue : nullptr;
}

const kiwi::String *VariableAnyValue::textValue() const {
  return _flags[0] & 2 ? &_data_textValue : nullptr;
}

void VariableAnyValue::set_textValue(const kiwi::String &value) {
  _flags[0] |= 2; _data_textValue = value;
}

float *VariableAnyValue::floatValue() {
  return _flags[0] & 4 ? &_data_floatValue : nullptr;
}

const float *VariableAnyValue::floatValue() const {
  return _flags[0] & 4 ? &_data_floatValue : nullptr;
}

void VariableAnyValue::set_floatValue(const float &value) {
  _flags[0] |= 4; _data_floatValue = value;
}

AssetID *VariableAnyValue::alias() {
  return _data_alias;
}

const AssetID *VariableAnyValue::alias() const {
  return _data_alias;
}

void VariableAnyValue::set_alias(AssetID *value) {
  _data_alias = value;
}

Color *VariableAnyValue::colorValue() {
  return _data_colorValue;
}

const Color *VariableAnyValue::colorValue() const {
  return _data_colorValue;
}

void VariableAnyValue::set_colorValue(Color *value) {
  _data_colorValue = value;
}

Expression *VariableAnyValue::expressionValue() {
  return _data_expressionValue;
}

const Expression *VariableAnyValue::expressionValue() const {
  return _data_expressionValue;
}

void VariableAnyValue::set_expressionValue(Expression *value) {
  _data_expressionValue = value;
}

VariableMap *VariableAnyValue::mapValue() {
  return _data_mapValue;
}

const VariableMap *VariableAnyValue::mapValue() const {
  return _data_mapValue;
}

void VariableAnyValue::set_mapValue(VariableMap *value) {
  _data_mapValue = value;
}

AssetID *VariableAnyValue::symbolIdValue() {
  return _data_symbolIdValue;
}

const AssetID *VariableAnyValue::symbolIdValue() const {
  return _data_symbolIdValue;
}

void VariableAnyValue::set_symbolIdValue(AssetID *value) {
  _data_symbolIdValue = value;
}

VariableFontStyle *VariableAnyValue::fontStyleValue() {
  return _data_fontStyleValue;
}

const VariableFontStyle *VariableAnyValue::fontStyleValue() const {
  return _data_fontStyleValue;
}

void VariableAnyValue::set_fontStyleValue(VariableFontStyle *value) {
  _data_fontStyleValue = value;
}

TextData *VariableAnyValue::textDataValue() {
  return _data_textDataValue;
}

const TextData *VariableAnyValue::textDataValue() const {
  return _data_textDataValue;
}

void VariableAnyValue::set_textDataValue(TextData *value) {
  _data_textDataValue = value;
}

NodeFieldAlias *VariableAnyValue::nodeFieldAliasValue() {
  return _data_nodeFieldAliasValue;
}

const NodeFieldAlias *VariableAnyValue::nodeFieldAliasValue() const {
  return _data_nodeFieldAliasValue;
}

void VariableAnyValue::set_nodeFieldAliasValue(NodeFieldAlias *value) {
  _data_nodeFieldAliasValue = value;
}

bool VariableAnyValue::encode(kiwi::ByteBuffer &_bb) {
  if (boolValue() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeByte(_data_boolValue);
  }
  if (textValue() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeString(_data_textValue.c_str());
  }
  if (floatValue() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeVarFloat(_data_floatValue);
  }
  if (alias() != nullptr) {
    _bb.writeVarUint(4);
    if (!_data_alias->encode(_bb)) return false;
  }
  if (colorValue() != nullptr) {
    _bb.writeVarUint(5);
    if (!_data_colorValue->encode(_bb)) return false;
  }
  if (expressionValue() != nullptr) {
    _bb.writeVarUint(6);
    if (!_data_expressionValue->encode(_bb)) return false;
  }
  if (mapValue() != nullptr) {
    _bb.writeVarUint(7);
    if (!_data_mapValue->encode(_bb)) return false;
  }
  if (symbolIdValue() != nullptr) {
    _bb.writeVarUint(8);
    if (!_data_symbolIdValue->encode(_bb)) return false;
  }
  if (fontStyleValue() != nullptr) {
    _bb.writeVarUint(9);
    if (!_data_fontStyleValue->encode(_bb)) return false;
  }
  if (textDataValue() != nullptr) {
    _bb.writeVarUint(10);
    if (!_data_textDataValue->encode(_bb)) return false;
  }
  if (nodeFieldAliasValue() != nullptr) {
    _bb.writeVarUint(11);
    if (!_data_nodeFieldAliasValue->encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool VariableAnyValue::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readByte(_data_boolValue)) return false;
        set_boolValue(_data_boolValue);
        break;
      }
      case 2: {
        if (!_bb.readString(_data_textValue, _pool)) return false;
        set_textValue(_data_textValue);
        break;
      }
      case 3: {
        if (!_bb.readVarFloat(_data_floatValue)) return false;
        set_floatValue(_data_floatValue);
        break;
      }
      case 4: {
        _data_alias = _pool.allocate<AssetID>();
        if (!_data_alias->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 5: {
        _data_colorValue = _pool.allocate<Color>();
        if (!_data_colorValue->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 6: {
        _data_expressionValue = _pool.allocate<Expression>();
        if (!_data_expressionValue->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 7: {
        _data_mapValue = _pool.allocate<VariableMap>();
        if (!_data_mapValue->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 8: {
        _data_symbolIdValue = _pool.allocate<AssetID>();
        if (!_data_symbolIdValue->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 9: {
        _data_fontStyleValue = _pool.allocate<VariableFontStyle>();
        if (!_data_fontStyleValue->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 10: {
        _data_textDataValue = _pool.allocate<TextData>();
        if (!_data_textDataValue->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 11: {
        _data_nodeFieldAliasValue = _pool.allocate<NodeFieldAlias>();
        if (!_data_nodeFieldAliasValue->decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipVariableAnyValueField(_bb, _type)) return false;
        break;
      }
    }
  }
}

ExpressionFunction *Expression::expressionFunction() {
  return _flags[0] & 1 ? &_data_expressionFunction : nullptr;
}

const ExpressionFunction *Expression::expressionFunction() const {
  return _flags[0] & 1 ? &_data_expressionFunction : nullptr;
}

void Expression::set_expressionFunction(const ExpressionFunction &value) {
  _flags[0] |= 1; _data_expressionFunction = value;
}

kiwi::Array<VariableData> *Expression::expressionArguments() {
  return _flags[0] & 2 ? &_data_expressionArguments : nullptr;
}

const kiwi::Array<VariableData> *Expression::expressionArguments() const {
  return _flags[0] & 2 ? &_data_expressionArguments : nullptr;
}

kiwi::Array<VariableData> &Expression::set_expressionArguments(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 2; return _data_expressionArguments = pool.array<VariableData>(count);
}

bool Expression::encode(kiwi::ByteBuffer &_bb) {
  if (expressionFunction() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(static_cast<uint32_t>(_data_expressionFunction));
  }
  if (expressionArguments() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarUint(_data_expressionArguments.size());
    for (VariableData &_it : _data_expressionArguments) if (!_it.encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool Expression::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_expressionFunction))) return false;
        set_expressionFunction(_data_expressionFunction);
        break;
      }
      case 2: {
        if (!_bb.readVarUint(_count)) return false;
        for (VariableData &_it : set_expressionArguments(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipExpressionField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::String *AssetRef::key() {
  return _flags[0] & 1 ? &_data_key : nullptr;
}

const kiwi::String *AssetRef::key() const {
  return _flags[0] & 1 ? &_data_key : nullptr;
}

void AssetRef::set_key(const kiwi::String &value) {
  _flags[0] |= 1; _data_key = value;
}

kiwi::String *AssetRef::version() {
  return _flags[0] & 2 ? &_data_version : nullptr;
}

const kiwi::String *AssetRef::version() const {
  return _flags[0] & 2 ? &_data_version : nullptr;
}

void AssetRef::set_version(const kiwi::String &value) {
  _flags[0] |= 2; _data_version = value;
}

bool AssetRef::encode(kiwi::ByteBuffer &_bb) {
  if (key() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeString(_data_key.c_str());
  }
  if (version() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeString(_data_version.c_str());
  }
  _bb.writeVarUint(0);
  return true;
}

bool AssetRef::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readString(_data_key, _pool)) return false;
        set_key(_data_key);
        break;
      }
      case 2: {
        if (!_bb.readString(_data_version, _pool)) return false;
        set_version(_data_version);
        break;
      }
      default: {
        if (!_schema || !_schema->skipAssetRefField(_bb, _type)) return false;
        break;
      }
    }
  }
}

VariableData *VariableFontStyle::asString() {
  return _data_asString;
}

const VariableData *VariableFontStyle::asString() const {
  return _data_asString;
}

void VariableFontStyle::set_asString(VariableData *value) {
  _data_asString = value;
}

VariableData *VariableFontStyle::asFloat() {
  return _data_asFloat;
}

const VariableData *VariableFontStyle::asFloat() const {
  return _data_asFloat;
}

void VariableFontStyle::set_asFloat(VariableData *value) {
  _data_asFloat = value;
}

bool VariableFontStyle::encode(kiwi::ByteBuffer &_bb) {
  if (asString() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_asString->encode(_bb)) return false;
  }
  if (asFloat() != nullptr) {
    _bb.writeVarUint(2);
    if (!_data_asFloat->encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool VariableFontStyle::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_asString = _pool.allocate<VariableData>();
        if (!_data_asString->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        _data_asFloat = _pool.allocate<VariableData>();
        if (!_data_asFloat->decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipVariableFontStyleField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::Array<VariableMapValue> *VariableMap::values() {
  return _flags[0] & 1 ? &_data_values : nullptr;
}

const kiwi::Array<VariableMapValue> *VariableMap::values() const {
  return _flags[0] & 1 ? &_data_values : nullptr;
}

kiwi::Array<VariableMapValue> &VariableMap::set_values(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 1; return _data_values = pool.array<VariableMapValue>(count);
}

bool VariableMap::encode(kiwi::ByteBuffer &_bb) {
  if (values() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(_data_values.size());
    for (VariableMapValue &_it : _data_values) if (!_it.encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool VariableMap::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(_count)) return false;
        for (VariableMapValue &_it : set_values(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipVariableMapField(_bb, _type)) return false;
        break;
      }
    }
  }
}

Color *ColorStopVar::color() {
  return _data_color;
}

const Color *ColorStopVar::color() const {
  return _data_color;
}

void ColorStopVar::set_color(Color *value) {
  _data_color = value;
}

VariableData *ColorStopVar::colorVar() {
  return _data_colorVar;
}

const VariableData *ColorStopVar::colorVar() const {
  return _data_colorVar;
}

void ColorStopVar::set_colorVar(VariableData *value) {
  _data_colorVar = value;
}

float *ColorStopVar::position() {
  return _flags[0] & 4 ? &_data_position : nullptr;
}

const float *ColorStopVar::position() const {
  return _flags[0] & 4 ? &_data_position : nullptr;
}

void ColorStopVar::set_position(const float &value) {
  _flags[0] |= 4; _data_position = value;
}

bool ColorStopVar::encode(kiwi::ByteBuffer &_bb) {
  if (color() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_color->encode(_bb)) return false;
  }
  if (colorVar() != nullptr) {
    _bb.writeVarUint(2);
    if (!_data_colorVar->encode(_bb)) return false;
  }
  if (position() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeVarFloat(_data_position);
  }
  _bb.writeVarUint(0);
  return true;
}

bool ColorStopVar::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_color = _pool.allocate<Color>();
        if (!_data_color->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        _data_colorVar = _pool.allocate<VariableData>();
        if (!_data_colorVar->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 3: {
        if (!_bb.readVarFloat(_data_position)) return false;
        set_position(_data_position);
        break;
      }
      default: {
        if (!_schema || !_schema->skipColorStopVarField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::Array<VariableModeBySetMapEntry> *VariableModeBySetMap::entries() {
  return _flags[0] & 1 ? &_data_entries : nullptr;
}

const kiwi::Array<VariableModeBySetMapEntry> *VariableModeBySetMap::entries() const {
  return _flags[0] & 1 ? &_data_entries : nullptr;
}

kiwi::Array<VariableModeBySetMapEntry> &VariableModeBySetMap::set_entries(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 1; return _data_entries = pool.array<VariableModeBySetMapEntry>(count);
}

bool VariableModeBySetMap::encode(kiwi::ByteBuffer &_bb) {
  if (entries() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(_data_entries.size());
    for (VariableModeBySetMapEntry &_it : _data_entries) if (!_it.encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool VariableModeBySetMap::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(_count)) return false;
        for (VariableModeBySetMapEntry &_it : set_entries(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipVariableModeBySetMapField(_bb, _type)) return false;
        break;
      }
    }
  }
}

AssetID *VariableModeBySetMapEntry::variableSetID() {
  return _data_variableSetID;
}

const AssetID *VariableModeBySetMapEntry::variableSetID() const {
  return _data_variableSetID;
}

void VariableModeBySetMapEntry::set_variableSetID(AssetID *value) {
  _data_variableSetID = value;
}

GUID *VariableModeBySetMapEntry::variableModeID() {
  return _data_variableModeID;
}

const GUID *VariableModeBySetMapEntry::variableModeID() const {
  return _data_variableModeID;
}

void VariableModeBySetMapEntry::set_variableModeID(GUID *value) {
  _data_variableModeID = value;
}

bool VariableModeBySetMapEntry::encode(kiwi::ByteBuffer &_bb) {
  if (variableSetID() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_variableSetID->encode(_bb)) return false;
  }
  if (variableModeID() != nullptr) {
    _bb.writeVarUint(2);
    if (!_data_variableModeID->encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool VariableModeBySetMapEntry::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_variableSetID = _pool.allocate<AssetID>();
        if (!_data_variableSetID->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        _data_variableModeID = _pool.allocate<GUID>();
        if (!_data_variableModeID->decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipVariableModeBySetMapEntryField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::String *VariableMapValue::key() {
  return _flags[0] & 1 ? &_data_key : nullptr;
}

const kiwi::String *VariableMapValue::key() const {
  return _flags[0] & 1 ? &_data_key : nullptr;
}

void VariableMapValue::set_key(const kiwi::String &value) {
  _flags[0] |= 1; _data_key = value;
}

VariableData *VariableMapValue::value() {
  return _data_value;
}

const VariableData *VariableMapValue::value() const {
  return _data_value;
}

void VariableMapValue::set_value(VariableData *value) {
  _data_value = value;
}

bool VariableMapValue::encode(kiwi::ByteBuffer &_bb) {
  if (key() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeString(_data_key.c_str());
  }
  if (value() != nullptr) {
    _bb.writeVarUint(2);
    if (!_data_value->encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool VariableMapValue::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readString(_data_key, _pool)) return false;
        set_key(_data_key);
        break;
      }
      case 2: {
        _data_value = _pool.allocate<VariableData>();
        if (!_data_value->decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipVariableMapValueField(_bb, _type)) return false;
        break;
      }
    }
  }
}

AssetID *VariableIdOrVariableOverrideId::variableId() {
  return _data_variableId;
}

const AssetID *VariableIdOrVariableOverrideId::variableId() const {
  return _data_variableId;
}

void VariableIdOrVariableOverrideId::set_variableId(AssetID *value) {
  _data_variableId = value;
}

VariableOverrideId *VariableIdOrVariableOverrideId::variableOverrideId() {
  return _data_variableOverrideId;
}

const VariableOverrideId *VariableIdOrVariableOverrideId::variableOverrideId() const {
  return _data_variableOverrideId;
}

void VariableIdOrVariableOverrideId::set_variableOverrideId(VariableOverrideId *value) {
  _data_variableOverrideId = value;
}

bool VariableIdOrVariableOverrideId::encode(kiwi::ByteBuffer &_bb) {
  if (variableId() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_variableId->encode(_bb)) return false;
  }
  if (variableOverrideId() != nullptr) {
    _bb.writeVarUint(2);
    if (!_data_variableOverrideId->encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool VariableIdOrVariableOverrideId::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_variableId = _pool.allocate<AssetID>();
        if (!_data_variableId->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        _data_variableOverrideId = _pool.allocate<VariableOverrideId>();
        if (!_data_variableOverrideId->decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipVariableIdOrVariableOverrideIdField(_bb, _type)) return false;
        break;
      }
    }
  }
}

GUID *VariableOverrideId::guid() {
  return _data_guid;
}

const GUID *VariableOverrideId::guid() const {
  return _data_guid;
}

void VariableOverrideId::set_guid(GUID *value) {
  _data_guid = value;
}

AssetRef *VariableOverrideId::assetRef() {
  return _data_assetRef;
}

const AssetRef *VariableOverrideId::assetRef() const {
  return _data_assetRef;
}

void VariableOverrideId::set_assetRef(AssetRef *value) {
  _data_assetRef = value;
}

bool VariableOverrideId::encode(kiwi::ByteBuffer &_bb) {
  if (guid() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_guid->encode(_bb)) return false;
  }
  if (assetRef() != nullptr) {
    _bb.writeVarUint(2);
    if (!_data_assetRef->encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool VariableOverrideId::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_guid = _pool.allocate<GUID>();
        if (!_data_guid->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        _data_assetRef = _pool.allocate<AssetRef>();
        if (!_data_assetRef->decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipVariableOverrideIdField(_bb, _type)) return false;
        break;
      }
    }
  }
}

AssetID *PrototypeVariableTarget::id() {
  return _data_id;
}

const AssetID *PrototypeVariableTarget::id() const {
  return _data_id;
}

void PrototypeVariableTarget::set_id(AssetID *value) {
  _data_id = value;
}

NodeFieldAlias *PrototypeVariableTarget::nodeFieldAlias() {
  return _data_nodeFieldAlias;
}

const NodeFieldAlias *PrototypeVariableTarget::nodeFieldAlias() const {
  return _data_nodeFieldAlias;
}

void PrototypeVariableTarget::set_nodeFieldAlias(NodeFieldAlias *value) {
  _data_nodeFieldAlias = value;
}

bool PrototypeVariableTarget::encode(kiwi::ByteBuffer &_bb) {
  if (id() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_id->encode(_bb)) return false;
  }
  if (nodeFieldAlias() != nullptr) {
    _bb.writeVarUint(2);
    if (!_data_nodeFieldAlias->encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool PrototypeVariableTarget::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_id = _pool.allocate<AssetID>();
        if (!_data_id->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        _data_nodeFieldAlias = _pool.allocate<NodeFieldAlias>();
        if (!_data_nodeFieldAlias->decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipPrototypeVariableTargetField(_bb, _type)) return false;
        break;
      }
    }
  }
}

GUID *TriggeredSetVariableActionData::nodeForFindingTopmostScreenId() {
  return _data_nodeForFindingTopmostScreenId;
}

const GUID *TriggeredSetVariableActionData::nodeForFindingTopmostScreenId() const {
  return _data_nodeForFindingTopmostScreenId;
}

void TriggeredSetVariableActionData::set_nodeForFindingTopmostScreenId(GUID *value) {
  _data_nodeForFindingTopmostScreenId = value;
}

kiwi::String *TriggeredSetVariableActionData::targetVariableId() {
  return _flags[0] & 2 ? &_data_targetVariableId : nullptr;
}

const kiwi::String *TriggeredSetVariableActionData::targetVariableId() const {
  return _flags[0] & 2 ? &_data_targetVariableId : nullptr;
}

void TriggeredSetVariableActionData::set_targetVariableId(const kiwi::String &value) {
  _flags[0] |= 2; _data_targetVariableId = value;
}

kiwi::String *TriggeredSetVariableActionData::targetVariableData() {
  return _flags[0] & 4 ? &_data_targetVariableData : nullptr;
}

const kiwi::String *TriggeredSetVariableActionData::targetVariableData() const {
  return _flags[0] & 4 ? &_data_targetVariableData : nullptr;
}

void TriggeredSetVariableActionData::set_targetVariableData(const kiwi::String &value) {
  _flags[0] |= 4; _data_targetVariableData = value;
}

kiwi::String *TriggeredSetVariableActionData::resolvedVariableModes() {
  return _flags[0] & 8 ? &_data_resolvedVariableModes : nullptr;
}

const kiwi::String *TriggeredSetVariableActionData::resolvedVariableModes() const {
  return _flags[0] & 8 ? &_data_resolvedVariableModes : nullptr;
}

void TriggeredSetVariableActionData::set_resolvedVariableModes(const kiwi::String &value) {
  _flags[0] |= 8; _data_resolvedVariableModes = value;
}

bool TriggeredSetVariableActionData::encode(kiwi::ByteBuffer &_bb) {
  if (nodeForFindingTopmostScreenId() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_nodeForFindingTopmostScreenId->encode(_bb)) return false;
  }
  if (targetVariableId() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeString(_data_targetVariableId.c_str());
  }
  if (targetVariableData() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeString(_data_targetVariableData.c_str());
  }
  if (resolvedVariableModes() != nullptr) {
    _bb.writeVarUint(4);
    _bb.writeString(_data_resolvedVariableModes.c_str());
  }
  _bb.writeVarUint(0);
  return true;
}

bool TriggeredSetVariableActionData::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_nodeForFindingTopmostScreenId = _pool.allocate<GUID>();
        if (!_data_nodeForFindingTopmostScreenId->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        if (!_bb.readString(_data_targetVariableId, _pool)) return false;
        set_targetVariableId(_data_targetVariableId);
        break;
      }
      case 3: {
        if (!_bb.readString(_data_targetVariableData, _pool)) return false;
        set_targetVariableData(_data_targetVariableData);
        break;
      }
      case 4: {
        if (!_bb.readString(_data_resolvedVariableModes, _pool)) return false;
        set_resolvedVariableModes(_data_resolvedVariableModes);
        break;
      }
      default: {
        if (!_schema || !_schema->skipTriggeredSetVariableActionDataField(_bb, _type)) return false;
        break;
      }
    }
  }
}

GUID *TriggeredSetVariableModeActionData::nodeForFindingTopmostScreenId() {
  return _data_nodeForFindingTopmostScreenId;
}

const GUID *TriggeredSetVariableModeActionData::nodeForFindingTopmostScreenId() const {
  return _data_nodeForFindingTopmostScreenId;
}

void TriggeredSetVariableModeActionData::set_nodeForFindingTopmostScreenId(GUID *value) {
  _data_nodeForFindingTopmostScreenId = value;
}

kiwi::String *TriggeredSetVariableModeActionData::targetVariableSetKey() {
  return _flags[0] & 2 ? &_data_targetVariableSetKey : nullptr;
}

const kiwi::String *TriggeredSetVariableModeActionData::targetVariableSetKey() const {
  return _flags[0] & 2 ? &_data_targetVariableSetKey : nullptr;
}

void TriggeredSetVariableModeActionData::set_targetVariableSetKey(const kiwi::String &value) {
  _flags[0] |= 2; _data_targetVariableSetKey = value;
}

kiwi::String *TriggeredSetVariableModeActionData::targetVariableModeId() {
  return _flags[0] & 4 ? &_data_targetVariableModeId : nullptr;
}

const kiwi::String *TriggeredSetVariableModeActionData::targetVariableModeId() const {
  return _flags[0] & 4 ? &_data_targetVariableModeId : nullptr;
}

void TriggeredSetVariableModeActionData::set_targetVariableModeId(const kiwi::String &value) {
  _flags[0] |= 4; _data_targetVariableModeId = value;
}

AssetID *TriggeredSetVariableModeActionData::targetVariableSetId() {
  return _data_targetVariableSetId;
}

const AssetID *TriggeredSetVariableModeActionData::targetVariableSetId() const {
  return _data_targetVariableSetId;
}

void TriggeredSetVariableModeActionData::set_targetVariableSetId(AssetID *value) {
  _data_targetVariableSetId = value;
}

bool TriggeredSetVariableModeActionData::encode(kiwi::ByteBuffer &_bb) {
  if (nodeForFindingTopmostScreenId() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_nodeForFindingTopmostScreenId->encode(_bb)) return false;
  }
  if (targetVariableSetKey() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeString(_data_targetVariableSetKey.c_str());
  }
  if (targetVariableModeId() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeString(_data_targetVariableModeId.c_str());
  }
  if (targetVariableSetId() != nullptr) {
    _bb.writeVarUint(4);
    if (!_data_targetVariableSetId->encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool TriggeredSetVariableModeActionData::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_nodeForFindingTopmostScreenId = _pool.allocate<GUID>();
        if (!_data_nodeForFindingTopmostScreenId->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        if (!_bb.readString(_data_targetVariableSetKey, _pool)) return false;
        set_targetVariableSetKey(_data_targetVariableSetKey);
        break;
      }
      case 3: {
        if (!_bb.readString(_data_targetVariableModeId, _pool)) return false;
        set_targetVariableModeId(_data_targetVariableModeId);
        break;
      }
      case 4: {
        _data_targetVariableSetId = _pool.allocate<AssetID>();
        if (!_data_targetVariableSetId->decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipTriggeredSetVariableModeActionDataField(_bb, _type)) return false;
        break;
      }
    }
  }
}

GUIDPath *NodeFieldAlias::stablePathToNode() {
  return _data_stablePathToNode;
}

const GUIDPath *NodeFieldAlias::stablePathToNode() const {
  return _data_stablePathToNode;
}

void NodeFieldAlias::set_stablePathToNode(GUIDPath *value) {
  _data_stablePathToNode = value;
}

NodeFieldAliasType *NodeFieldAlias::nodeField() {
  return _flags[0] & 2 ? &_data_nodeField : nullptr;
}

const NodeFieldAliasType *NodeFieldAlias::nodeField() const {
  return _flags[0] & 2 ? &_data_nodeField : nullptr;
}

void NodeFieldAlias::set_nodeField(const NodeFieldAliasType &value) {
  _flags[0] |= 2; _data_nodeField = value;
}

kiwi::String *NodeFieldAlias::indexOrKey() {
  return _flags[0] & 4 ? &_data_indexOrKey : nullptr;
}

const kiwi::String *NodeFieldAlias::indexOrKey() const {
  return _flags[0] & 4 ? &_data_indexOrKey : nullptr;
}

void NodeFieldAlias::set_indexOrKey(const kiwi::String &value) {
  _flags[0] |= 4; _data_indexOrKey = value;
}

bool NodeFieldAlias::encode(kiwi::ByteBuffer &_bb) {
  if (stablePathToNode() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_stablePathToNode->encode(_bb)) return false;
  }
  if (nodeField() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarUint(static_cast<uint32_t>(_data_nodeField));
  }
  if (indexOrKey() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeString(_data_indexOrKey.c_str());
  }
  _bb.writeVarUint(0);
  return true;
}

bool NodeFieldAlias::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_stablePathToNode = _pool.allocate<GUIDPath>();
        if (!_data_stablePathToNode->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_nodeField))) return false;
        set_nodeField(_data_nodeField);
        break;
      }
      case 3: {
        if (!_bb.readString(_data_indexOrKey, _pool)) return false;
        set_indexOrKey(_data_indexOrKey);
        break;
      }
      default: {
        if (!_schema || !_schema->skipNodeFieldAliasField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::Array<CodeSyntaxMapEntry> *CodeSyntaxMap::entries() {
  return _flags[0] & 1 ? &_data_entries : nullptr;
}

const kiwi::Array<CodeSyntaxMapEntry> *CodeSyntaxMap::entries() const {
  return _flags[0] & 1 ? &_data_entries : nullptr;
}

kiwi::Array<CodeSyntaxMapEntry> &CodeSyntaxMap::set_entries(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 1; return _data_entries = pool.array<CodeSyntaxMapEntry>(count);
}

bool CodeSyntaxMap::encode(kiwi::ByteBuffer &_bb) {
  if (entries() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(_data_entries.size());
    for (CodeSyntaxMapEntry &_it : _data_entries) if (!_it.encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool CodeSyntaxMap::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(_count)) return false;
        for (CodeSyntaxMapEntry &_it : set_entries(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipCodeSyntaxMapField(_bb, _type)) return false;
        break;
      }
    }
  }
}

CodeSyntaxPlatform *CodeSyntaxMapEntry::platform() {
  return _flags[0] & 1 ? &_data_platform : nullptr;
}

const CodeSyntaxPlatform *CodeSyntaxMapEntry::platform() const {
  return _flags[0] & 1 ? &_data_platform : nullptr;
}

void CodeSyntaxMapEntry::set_platform(const CodeSyntaxPlatform &value) {
  _flags[0] |= 1; _data_platform = value;
}

kiwi::String *CodeSyntaxMapEntry::value() {
  return _flags[0] & 2 ? &_data_value : nullptr;
}

const kiwi::String *CodeSyntaxMapEntry::value() const {
  return _flags[0] & 2 ? &_data_value : nullptr;
}

void CodeSyntaxMapEntry::set_value(const kiwi::String &value) {
  _flags[0] |= 2; _data_value = value;
}

bool CodeSyntaxMapEntry::encode(kiwi::ByteBuffer &_bb) {
  if (platform() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(static_cast<uint32_t>(_data_platform));
  }
  if (value() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeString(_data_value.c_str());
  }
  _bb.writeVarUint(0);
  return true;
}

bool CodeSyntaxMapEntry::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_platform))) return false;
        set_platform(_data_platform);
        break;
      }
      case 2: {
        if (!_bb.readString(_data_value, _pool)) return false;
        set_value(_data_value);
        break;
      }
      default: {
        if (!_schema || !_schema->skipCodeSyntaxMapEntryField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::String *DeliverInfo::publishedVersion() {
  return _flags[0] & 1 ? &_data_publishedVersion : nullptr;
}

const kiwi::String *DeliverInfo::publishedVersion() const {
  return _flags[0] & 1 ? &_data_publishedVersion : nullptr;
}

void DeliverInfo::set_publishedVersion(const kiwi::String &value) {
  _flags[0] |= 1; _data_publishedVersion = value;
}

kiwi::String *DeliverInfo::currentVersion() {
  return _flags[0] & 2 ? &_data_currentVersion : nullptr;
}

const kiwi::String *DeliverInfo::currentVersion() const {
  return _flags[0] & 2 ? &_data_currentVersion : nullptr;
}

void DeliverInfo::set_currentVersion(const kiwi::String &value) {
  _flags[0] |= 2; _data_currentVersion = value;
}

bool DeliverInfo::encode(kiwi::ByteBuffer &_bb) {
  if (publishedVersion() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeString(_data_publishedVersion.c_str());
  }
  if (currentVersion() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeString(_data_currentVersion.c_str());
  }
  _bb.writeVarUint(0);
  return true;
}

bool DeliverInfo::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readString(_data_publishedVersion, _pool)) return false;
        set_publishedVersion(_data_publishedVersion);
        break;
      }
      case 2: {
        if (!_bb.readString(_data_currentVersion, _pool)) return false;
        set_currentVersion(_data_currentVersion);
        break;
      }
      default: {
        if (!_schema || !_schema->skipDeliverInfoField(_bb, _type)) return false;
        break;
      }
    }
  }
}

AnnotationPropertyType *AnnotationProperty::type() {
  return _flags[0] & 1 ? &_data_type : nullptr;
}

const AnnotationPropertyType *AnnotationProperty::type() const {
  return _flags[0] & 1 ? &_data_type : nullptr;
}

void AnnotationProperty::set_type(const AnnotationPropertyType &value) {
  _flags[0] |= 1; _data_type = value;
}

bool AnnotationProperty::encode(kiwi::ByteBuffer &_bb) {
  if (type() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(static_cast<uint32_t>(_data_type));
  }
  _bb.writeVarUint(0);
  return true;
}

bool AnnotationProperty::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_type))) return false;
        set_type(_data_type);
        break;
      }
      default: {
        if (!_schema || !_schema->skipAnnotationPropertyField(_bb, _type)) return false;
        break;
      }
    }
  }
}

Color *AnnotationCategoryCustom::color() {
  return _data_color;
}

const Color *AnnotationCategoryCustom::color() const {
  return _data_color;
}

void AnnotationCategoryCustom::set_color(Color *value) {
  _data_color = value;
}

kiwi::String *AnnotationCategoryCustom::label() {
  return _flags[0] & 2 ? &_data_label : nullptr;
}

const kiwi::String *AnnotationCategoryCustom::label() const {
  return _flags[0] & 2 ? &_data_label : nullptr;
}

void AnnotationCategoryCustom::set_label(const kiwi::String &value) {
  _flags[0] |= 2; _data_label = value;
}

bool AnnotationCategoryCustom::encode(kiwi::ByteBuffer &_bb) {
  if (color() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_color->encode(_bb)) return false;
  }
  if (label() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeString(_data_label.c_str());
  }
  _bb.writeVarUint(0);
  return true;
}

bool AnnotationCategoryCustom::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_color = _pool.allocate<Color>();
        if (!_data_color->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        if (!_bb.readString(_data_label, _pool)) return false;
        set_label(_data_label);
        break;
      }
      default: {
        if (!_schema || !_schema->skipAnnotationCategoryCustomField(_bb, _type)) return false;
        break;
      }
    }
  }
}

GUID *AnnotationCategory::id() {
  return _data_id;
}

const GUID *AnnotationCategory::id() const {
  return _data_id;
}

void AnnotationCategory::set_id(GUID *value) {
  _data_id = value;
}

AnnotationCategoryPreset *AnnotationCategory::preset() {
  return _flags[0] & 2 ? &_data_preset : nullptr;
}

const AnnotationCategoryPreset *AnnotationCategory::preset() const {
  return _flags[0] & 2 ? &_data_preset : nullptr;
}

void AnnotationCategory::set_preset(const AnnotationCategoryPreset &value) {
  _flags[0] |= 2; _data_preset = value;
}

AnnotationCategoryCustom *AnnotationCategory::custom() {
  return _data_custom;
}

const AnnotationCategoryCustom *AnnotationCategory::custom() const {
  return _data_custom;
}

void AnnotationCategory::set_custom(AnnotationCategoryCustom *value) {
  _data_custom = value;
}

bool AnnotationCategory::encode(kiwi::ByteBuffer &_bb) {
  if (id() != nullptr) {
    _bb.writeVarUint(1);
    if (!_data_id->encode(_bb)) return false;
  }
  if (preset() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarUint(static_cast<uint32_t>(_data_preset));
  }
  if (custom() != nullptr) {
    _bb.writeVarUint(3);
    if (!_data_custom->encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool AnnotationCategory::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        _data_id = _pool.allocate<GUID>();
        if (!_data_id->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_preset))) return false;
        set_preset(_data_preset);
        break;
      }
      case 3: {
        _data_custom = _pool.allocate<AnnotationCategoryCustom>();
        if (!_data_custom->decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipAnnotationCategoryField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::Array<AnnotationCategory> *AnnotationCategories::items() {
  return _flags[0] & 1 ? &_data_items : nullptr;
}

const kiwi::Array<AnnotationCategory> *AnnotationCategories::items() const {
  return _flags[0] & 1 ? &_data_items : nullptr;
}

kiwi::Array<AnnotationCategory> &AnnotationCategories::set_items(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 1; return _data_items = pool.array<AnnotationCategory>(count);
}

bool AnnotationCategories::encode(kiwi::ByteBuffer &_bb) {
  if (items() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(_data_items.size());
    for (AnnotationCategory &_it : _data_items) if (!_it.encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool AnnotationCategories::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(_count)) return false;
        for (AnnotationCategory &_it : set_items(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipAnnotationCategoriesField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::String *Annotation::label() {
  return _flags[0] & 1 ? &_data_label : nullptr;
}

const kiwi::String *Annotation::label() const {
  return _flags[0] & 1 ? &_data_label : nullptr;
}

void Annotation::set_label(const kiwi::String &value) {
  _flags[0] |= 1; _data_label = value;
}

kiwi::Array<AnnotationProperty> *Annotation::properties() {
  return _flags[0] & 2 ? &_data_properties : nullptr;
}

const kiwi::Array<AnnotationProperty> *Annotation::properties() const {
  return _flags[0] & 2 ? &_data_properties : nullptr;
}

kiwi::Array<AnnotationProperty> &Annotation::set_properties(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 2; return _data_properties = pool.array<AnnotationProperty>(count);
}

GUID *Annotation::categoryId() {
  return _data_categoryId;
}

const GUID *Annotation::categoryId() const {
  return _data_categoryId;
}

void Annotation::set_categoryId(GUID *value) {
  _data_categoryId = value;
}

bool Annotation::encode(kiwi::ByteBuffer &_bb) {
  if (label() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeString(_data_label.c_str());
  }
  if (properties() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarUint(_data_properties.size());
    for (AnnotationProperty &_it : _data_properties) if (!_it.encode(_bb)) return false;
  }
  if (categoryId() != nullptr) {
    _bb.writeVarUint(3);
    if (!_data_categoryId->encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool Annotation::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readString(_data_label, _pool)) return false;
        set_label(_data_label);
        break;
      }
      case 2: {
        if (!_bb.readVarUint(_count)) return false;
        for (AnnotationProperty &_it : set_properties(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 3: {
        _data_categoryId = _pool.allocate<GUID>();
        if (!_data_categoryId->decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipAnnotationField(_bb, _type)) return false;
        break;
      }
    }
  }
}

uint32_t *GUID::sessionID() {
  return _flags[0] & 1 ? &_data_sessionID : nullptr;
}

const uint32_t *GUID::sessionID() const {
  return _flags[0] & 1 ? &_data_sessionID : nullptr;
}

void GUID::set_sessionID(const uint32_t &value) {
  _flags[0] |= 1; _data_sessionID = value;
}

uint32_t *GUID::localID() {
  return _flags[0] & 2 ? &_data_localID : nullptr;
}

const uint32_t *GUID::localID() const {
  return _flags[0] & 2 ? &_data_localID : nullptr;
}

void GUID::set_localID(const uint32_t &value) {
  _flags[0] |= 2; _data_localID = value;
}

bool GUID::encode(kiwi::ByteBuffer &_bb) {
  if (sessionID() == nullptr) return false;
  _bb.writeVarUint(_data_sessionID);
  if (localID() == nullptr) return false;
  _bb.writeVarUint(_data_localID);
  return true;
}

bool GUID::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  if (!_bb.readVarUint(_data_sessionID)) return false;
  set_sessionID(_data_sessionID);
  if (!_bb.readVarUint(_data_localID)) return false;
  set_localID(_data_localID);
  return true;
}

float *Vector::x() {
  return _flags[0] & 1 ? &_data_x : nullptr;
}

const float *Vector::x() const {
  return _flags[0] & 1 ? &_data_x : nullptr;
}

void Vector::set_x(const float &value) {
  _flags[0] |= 1; _data_x = value;
}

float *Vector::y() {
  return _flags[0] & 2 ? &_data_y : nullptr;
}

const float *Vector::y() const {
  return _flags[0] & 2 ? &_data_y : nullptr;
}

void Vector::set_y(const float &value) {
  _flags[0] |= 2; _data_y = value;
}

bool Vector::encode(kiwi::ByteBuffer &_bb) {
  if (x() == nullptr) return false;
  _bb.writeVarFloat(_data_x);
  if (y() == nullptr) return false;
  _bb.writeVarFloat(_data_y);
  return true;
}

bool Vector::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  if (!_bb.readVarFloat(_data_x)) return false;
  set_x(_data_x);
  if (!_bb.readVarFloat(_data_y)) return false;
  set_y(_data_y);
  return true;
}

float *Matrix::m00() {
  return _flags[0] & 1 ? &_data_m00 : nullptr;
}

const float *Matrix::m00() const {
  return _flags[0] & 1 ? &_data_m00 : nullptr;
}

void Matrix::set_m00(const float &value) {
  _flags[0] |= 1; _data_m00 = value;
}

float *Matrix::m01() {
  return _flags[0] & 2 ? &_data_m01 : nullptr;
}

const float *Matrix::m01() const {
  return _flags[0] & 2 ? &_data_m01 : nullptr;
}

void Matrix::set_m01(const float &value) {
  _flags[0] |= 2; _data_m01 = value;
}

float *Matrix::m02() {
  return _flags[0] & 4 ? &_data_m02 : nullptr;
}

const float *Matrix::m02() const {
  return _flags[0] & 4 ? &_data_m02 : nullptr;
}

void Matrix::set_m02(const float &value) {
  _flags[0] |= 4; _data_m02 = value;
}

float *Matrix::m10() {
  return _flags[0] & 8 ? &_data_m10 : nullptr;
}

const float *Matrix::m10() const {
  return _flags[0] & 8 ? &_data_m10 : nullptr;
}

void Matrix::set_m10(const float &value) {
  _flags[0] |= 8; _data_m10 = value;
}

float *Matrix::m11() {
  return _flags[0] & 16 ? &_data_m11 : nullptr;
}

const float *Matrix::m11() const {
  return _flags[0] & 16 ? &_data_m11 : nullptr;
}

void Matrix::set_m11(const float &value) {
  _flags[0] |= 16; _data_m11 = value;
}

float *Matrix::m12() {
  return _flags[0] & 32 ? &_data_m12 : nullptr;
}

const float *Matrix::m12() const {
  return _flags[0] & 32 ? &_data_m12 : nullptr;
}

void Matrix::set_m12(const float &value) {
  _flags[0] |= 32; _data_m12 = value;
}

bool Matrix::encode(kiwi::ByteBuffer &_bb) {
  if (m00() == nullptr) return false;
  _bb.writeVarFloat(_data_m00);
  if (m01() == nullptr) return false;
  _bb.writeVarFloat(_data_m01);
  if (m02() == nullptr) return false;
  _bb.writeVarFloat(_data_m02);
  if (m10() == nullptr) return false;
  _bb.writeVarFloat(_data_m10);
  if (m11() == nullptr) return false;
  _bb.writeVarFloat(_data_m11);
  if (m12() == nullptr) return false;
  _bb.writeVarFloat(_data_m12);
  return true;
}

bool Matrix::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  if (!_bb.readVarFloat(_data_m00)) return false;
  set_m00(_data_m00);
  if (!_bb.readVarFloat(_data_m01)) return false;
  set_m01(_data_m01);
  if (!_bb.readVarFloat(_data_m02)) return false;
  set_m02(_data_m02);
  if (!_bb.readVarFloat(_data_m10)) return false;
  set_m10(_data_m10);
  if (!_bb.readVarFloat(_data_m11)) return false;
  set_m11(_data_m11);
  if (!_bb.readVarFloat(_data_m12)) return false;
  set_m12(_data_m12);
  return true;
}

float *Matrix3f::m00() {
  return _flags[0] & 1 ? &_data_m00 : nullptr;
}

const float *Matrix3f::m00() const {
  return _flags[0] & 1 ? &_data_m00 : nullptr;
}

void Matrix3f::set_m00(const float &value) {
  _flags[0] |= 1; _data_m00 = value;
}

float *Matrix3f::m01() {
  return _flags[0] & 2 ? &_data_m01 : nullptr;
}

const float *Matrix3f::m01() const {
  return _flags[0] & 2 ? &_data_m01 : nullptr;
}

void Matrix3f::set_m01(const float &value) {
  _flags[0] |= 2; _data_m01 = value;
}

float *Matrix3f::m02() {
  return _flags[0] & 4 ? &_data_m02 : nullptr;
}

const float *Matrix3f::m02() const {
  return _flags[0] & 4 ? &_data_m02 : nullptr;
}

void Matrix3f::set_m02(const float &value) {
  _flags[0] |= 4; _data_m02 = value;
}

float *Matrix3f::m10() {
  return _flags[0] & 8 ? &_data_m10 : nullptr;
}

const float *Matrix3f::m10() const {
  return _flags[0] & 8 ? &_data_m10 : nullptr;
}

void Matrix3f::set_m10(const float &value) {
  _flags[0] |= 8; _data_m10 = value;
}

float *Matrix3f::m11() {
  return _flags[0] & 16 ? &_data_m11 : nullptr;
}

const float *Matrix3f::m11() const {
  return _flags[0] & 16 ? &_data_m11 : nullptr;
}

void Matrix3f::set_m11(const float &value) {
  _flags[0] |= 16; _data_m11 = value;
}

float *Matrix3f::m12() {
  return _flags[0] & 32 ? &_data_m12 : nullptr;
}

const float *Matrix3f::m12() const {
  return _flags[0] & 32 ? &_data_m12 : nullptr;
}

void Matrix3f::set_m12(const float &value) {
  _flags[0] |= 32; _data_m12 = value;
}

float *Matrix3f::m20() {
  return _flags[0] & 64 ? &_data_m20 : nullptr;
}

const float *Matrix3f::m20() const {
  return _flags[0] & 64 ? &_data_m20 : nullptr;
}

void Matrix3f::set_m20(const float &value) {
  _flags[0] |= 64; _data_m20 = value;
}

float *Matrix3f::m21() {
  return _flags[0] & 128 ? &_data_m21 : nullptr;
}

const float *Matrix3f::m21() const {
  return _flags[0] & 128 ? &_data_m21 : nullptr;
}

void Matrix3f::set_m21(const float &value) {
  _flags[0] |= 128; _data_m21 = value;
}

float *Matrix3f::m22() {
  return _flags[0] & 256 ? &_data_m22 : nullptr;
}

const float *Matrix3f::m22() const {
  return _flags[0] & 256 ? &_data_m22 : nullptr;
}

void Matrix3f::set_m22(const float &value) {
  _flags[0] |= 256; _data_m22 = value;
}

bool Matrix3f::encode(kiwi::ByteBuffer &_bb) {
  if (m00() == nullptr) return false;
  _bb.writeVarFloat(_data_m00);
  if (m01() == nullptr) return false;
  _bb.writeVarFloat(_data_m01);
  if (m02() == nullptr) return false;
  _bb.writeVarFloat(_data_m02);
  if (m10() == nullptr) return false;
  _bb.writeVarFloat(_data_m10);
  if (m11() == nullptr) return false;
  _bb.writeVarFloat(_data_m11);
  if (m12() == nullptr) return false;
  _bb.writeVarFloat(_data_m12);
  if (m20() == nullptr) return false;
  _bb.writeVarFloat(_data_m20);
  if (m21() == nullptr) return false;
  _bb.writeVarFloat(_data_m21);
  if (m22() == nullptr) return false;
  _bb.writeVarFloat(_data_m22);
  return true;
}

bool Matrix3f::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  if (!_bb.readVarFloat(_data_m00)) return false;
  set_m00(_data_m00);
  if (!_bb.readVarFloat(_data_m01)) return false;
  set_m01(_data_m01);
  if (!_bb.readVarFloat(_data_m02)) return false;
  set_m02(_data_m02);
  if (!_bb.readVarFloat(_data_m10)) return false;
  set_m10(_data_m10);
  if (!_bb.readVarFloat(_data_m11)) return false;
  set_m11(_data_m11);
  if (!_bb.readVarFloat(_data_m12)) return false;
  set_m12(_data_m12);
  if (!_bb.readVarFloat(_data_m20)) return false;
  set_m20(_data_m20);
  if (!_bb.readVarFloat(_data_m21)) return false;
  set_m21(_data_m21);
  if (!_bb.readVarFloat(_data_m22)) return false;
  set_m22(_data_m22);
  return true;
}

float *Color::r() {
  return _flags[0] & 1 ? &_data_r : nullptr;
}

const float *Color::r() const {
  return _flags[0] & 1 ? &_data_r : nullptr;
}

void Color::set_r(const float &value) {
  _flags[0] |= 1; _data_r = value;
}

float *Color::g() {
  return _flags[0] & 2 ? &_data_g : nullptr;
}

const float *Color::g() const {
  return _flags[0] & 2 ? &_data_g : nullptr;
}

void Color::set_g(const float &value) {
  _flags[0] |= 2; _data_g = value;
}

float *Color::b() {
  return _flags[0] & 4 ? &_data_b : nullptr;
}

const float *Color::b() const {
  return _flags[0] & 4 ? &_data_b : nullptr;
}

void Color::set_b(const float &value) {
  _flags[0] |= 4; _data_b = value;
}

float *Color::a() {
  return _flags[0] & 8 ? &_data_a : nullptr;
}

const float *Color::a() const {
  return _flags[0] & 8 ? &_data_a : nullptr;
}

void Color::set_a(const float &value) {
  _flags[0] |= 8; _data_a = value;
}

bool Color::encode(kiwi::ByteBuffer &_bb) {
  if (r() == nullptr) return false;
  _bb.writeVarFloat(_data_r);
  if (g() == nullptr) return false;
  _bb.writeVarFloat(_data_g);
  if (b() == nullptr) return false;
  _bb.writeVarFloat(_data_b);
  if (a() == nullptr) return false;
  _bb.writeVarFloat(_data_a);
  return true;
}

bool Color::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  if (!_bb.readVarFloat(_data_r)) return false;
  set_r(_data_r);
  if (!_bb.readVarFloat(_data_g)) return false;
  set_g(_data_g);
  if (!_bb.readVarFloat(_data_b)) return false;
  set_b(_data_b);
  if (!_bb.readVarFloat(_data_a)) return false;
  set_a(_data_a);
  return true;
}

float *Rect::x() {
  return _flags[0] & 1 ? &_data_x : nullptr;
}

const float *Rect::x() const {
  return _flags[0] & 1 ? &_data_x : nullptr;
}

void Rect::set_x(const float &value) {
  _flags[0] |= 1; _data_x = value;
}

float *Rect::y() {
  return _flags[0] & 2 ? &_data_y : nullptr;
}

const float *Rect::y() const {
  return _flags[0] & 2 ? &_data_y : nullptr;
}

void Rect::set_y(const float &value) {
  _flags[0] |= 2; _data_y = value;
}

float *Rect::w() {
  return _flags[0] & 4 ? &_data_w : nullptr;
}

const float *Rect::w() const {
  return _flags[0] & 4 ? &_data_w : nullptr;
}

void Rect::set_w(const float &value) {
  _flags[0] |= 4; _data_w = value;
}

float *Rect::h() {
  return _flags[0] & 8 ? &_data_h : nullptr;
}

const float *Rect::h() const {
  return _flags[0] & 8 ? &_data_h : nullptr;
}

void Rect::set_h(const float &value) {
  _flags[0] |= 8; _data_h = value;
}

bool Rect::encode(kiwi::ByteBuffer &_bb) {
  if (x() == nullptr) return false;
  _bb.writeVarFloat(_data_x);
  if (y() == nullptr) return false;
  _bb.writeVarFloat(_data_y);
  if (w() == nullptr) return false;
  _bb.writeVarFloat(_data_w);
  if (h() == nullptr) return false;
  _bb.writeVarFloat(_data_h);
  return true;
}

bool Rect::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  if (!_bb.readVarFloat(_data_x)) return false;
  set_x(_data_x);
  if (!_bb.readVarFloat(_data_y)) return false;
  set_y(_data_y);
  if (!_bb.readVarFloat(_data_w)) return false;
  set_w(_data_w);
  if (!_bb.readVarFloat(_data_h)) return false;
  set_h(_data_h);
  return true;
}

uint32_t *CommandNum::round() {
  return _flags[0] & 1 ? &_data_round : nullptr;
}

const uint32_t *CommandNum::round() const {
  return _flags[0] & 1 ? &_data_round : nullptr;
}

void CommandNum::set_round(const uint32_t &value) {
  _flags[0] |= 1; _data_round = value;
}

uint32_t *CommandNum::count() {
  return _flags[0] & 2 ? &_data_count : nullptr;
}

const uint32_t *CommandNum::count() const {
  return _flags[0] & 2 ? &_data_count : nullptr;
}

void CommandNum::set_count(const uint32_t &value) {
  _flags[0] |= 2; _data_count = value;
}

bool CommandNum::encode(kiwi::ByteBuffer &_bb) {
  if (round() == nullptr) return false;
  _bb.writeVarUint(_data_round);
  if (count() == nullptr) return false;
  _bb.writeVarUint(_data_count);
  return true;
}

bool CommandNum::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  if (!_bb.readVarUint(_data_round)) return false;
  set_round(_data_round);
  if (!_bb.readVarUint(_data_count)) return false;
  set_count(_data_count);
  return true;
}

#endif
