/////////////////////////////////////////////////////////////////////////////
// Authors:     Laurent Pugin and Rodolfo Zitellini
// Created:     2014
// Copyright (c) Authors and others. All rights reserved.
//
// Code generated using a modified version of libmei 
// by Andrew Hankinson, Alastair Porter, and Others
/////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////// 
// NOTE: this file was generated with the Verovio libmei version and 
// should not be edited because changes will be lost.
/////////////////////////////////////////////////////////////////////////////

#include "atts_shared.h"

//----------------------------------------------------------------------------

#include <assert.h>

//----------------------------------------------------------------------------

#include "object.h"

/* #include_block */

namespace vrv {
    
//----------------------------------------------------------------------------
// AttAccidLog
//----------------------------------------------------------------------------

AttAccidLog::AttAccidLog(): Att() {
    ResetAccidLog();
}

AttAccidLog::~AttAccidLog() {

}

void AttAccidLog::ResetAccidLog() {
    m_func = FUNC_NONE;
}

bool AttAccidLog::ReadAccidLog(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("func")) {
        this->SetFunc(StrToFunc(element.attribute("func").value()));
        element.remove_attribute("func");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttAccidLog::WriteAccidLog(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasFunc()) {
        element.append_attribute("func") = FuncToStr(this->GetFunc()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttAccidLog::HasFunc( )
{
    return (m_func != FUNC_NONE);
}


/* include <attfunc> */

//----------------------------------------------------------------------------
// AttAccidental
//----------------------------------------------------------------------------

AttAccidental::AttAccidental(): Att() {
    ResetAccidental();
}

AttAccidental::~AttAccidental() {

}

void AttAccidental::ResetAccidental() {
    m_accid = ACCIDENTAL_EXPLICIT_NONE;
}

bool AttAccidental::ReadAccidental(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("accid")) {
        this->SetAccid(StrToAccidentalExplicit(element.attribute("accid").value()));
        element.remove_attribute("accid");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttAccidental::WriteAccidental(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasAccid()) {
        element.append_attribute("accid") = AccidentalExplicitToStr(this->GetAccid()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttAccidental::HasAccid( )
{
    return (m_accid != ACCIDENTAL_EXPLICIT_NONE);
}


/* include <attaccid> */

//----------------------------------------------------------------------------
// AttAccidentalPerformed
//----------------------------------------------------------------------------

AttAccidentalPerformed::AttAccidentalPerformed(): Att() {
    ResetAccidentalPerformed();
}

AttAccidentalPerformed::~AttAccidentalPerformed() {

}

void AttAccidentalPerformed::ResetAccidentalPerformed() {
    m_accidGes = "";
}

bool AttAccidentalPerformed::ReadAccidentalPerformed(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("accid.ges")) {
        this->SetAccidGes(StrToStr(element.attribute("accid.ges").value()));
        element.remove_attribute("accid.ges");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttAccidentalPerformed::WriteAccidentalPerformed(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasAccidGes()) {
        element.append_attribute("accid.ges") = StrToStr(this->GetAccidGes()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttAccidentalPerformed::HasAccidGes( )
{
    return (m_accidGes != "");
}


/* include <attaccid.ges> */

//----------------------------------------------------------------------------
// AttArticulation
//----------------------------------------------------------------------------

AttArticulation::AttArticulation(): Att() {
    ResetArticulation();
}

AttArticulation::~AttArticulation() {

}

void AttArticulation::ResetArticulation() {
    m_artic = "";
}

bool AttArticulation::ReadArticulation(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("artic")) {
        this->SetArtic(StrToStr(element.attribute("artic").value()));
        element.remove_attribute("artic");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttArticulation::WriteArticulation(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasArtic()) {
        element.append_attribute("artic") = StrToStr(this->GetArtic()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttArticulation::HasArtic( )
{
    return (m_artic != "");
}


/* include <attartic> */

//----------------------------------------------------------------------------
// AttArticulationPerformed
//----------------------------------------------------------------------------

AttArticulationPerformed::AttArticulationPerformed(): Att() {
    ResetArticulationPerformed();
}

AttArticulationPerformed::~AttArticulationPerformed() {

}

void AttArticulationPerformed::ResetArticulationPerformed() {
    m_articGes = "";
}

bool AttArticulationPerformed::ReadArticulationPerformed(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("artic.ges")) {
        this->SetArticGes(StrToStr(element.attribute("artic.ges").value()));
        element.remove_attribute("artic.ges");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttArticulationPerformed::WriteArticulationPerformed(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasArticGes()) {
        element.append_attribute("artic.ges") = StrToStr(this->GetArticGes()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttArticulationPerformed::HasArticGes( )
{
    return (m_articGes != "");
}


/* include <attartic.ges> */

//----------------------------------------------------------------------------
// AttAugmentdots
//----------------------------------------------------------------------------

AttAugmentdots::AttAugmentdots(): Att() {
    ResetAugmentdots();
}

AttAugmentdots::~AttAugmentdots() {

}

void AttAugmentdots::ResetAugmentdots() {
    m_dots = 0;
}

bool AttAugmentdots::ReadAugmentdots(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("dots")) {
        this->SetDots(StrToInt(element.attribute("dots").value()));
        element.remove_attribute("dots");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttAugmentdots::WriteAugmentdots(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasDots()) {
        element.append_attribute("dots") = IntToStr(this->GetDots()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttAugmentdots::HasDots( )
{
    return (m_dots != 0);
}


/* include <attdots> */

//----------------------------------------------------------------------------
// AttAuthorized
//----------------------------------------------------------------------------

AttAuthorized::AttAuthorized(): Att() {
    ResetAuthorized();
}

AttAuthorized::~AttAuthorized() {

}

void AttAuthorized::ResetAuthorized() {
    m_authority = "";
    m_authURI = "";
}

bool AttAuthorized::ReadAuthorized(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("authority")) {
        this->SetAuthority(StrToStr(element.attribute("authority").value()));
        element.remove_attribute("authority");
        hasAttribute = true;
    }
    if (element.attribute("authURI")) {
        this->SetAuthURI(StrToStr(element.attribute("authURI").value()));
        element.remove_attribute("authURI");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttAuthorized::WriteAuthorized(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasAuthority()) {
        element.append_attribute("authority") = StrToStr(this->GetAuthority()).c_str();
        wroteAttribute = true;
    }
    if (this->HasAuthURI()) {
        element.append_attribute("authURI") = StrToStr(this->GetAuthURI()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttAuthorized::HasAuthority( )
{
    return (m_authority != "");
}

bool AttAuthorized::HasAuthURI( )
{
    return (m_authURI != "");
}


/* include <attauthURI> */

//----------------------------------------------------------------------------
// AttBarLineLog
//----------------------------------------------------------------------------

AttBarLineLog::AttBarLineLog(): Att() {
    ResetBarLineLog();
}

AttBarLineLog::~AttBarLineLog() {

}

void AttBarLineLog::ResetBarLineLog() {
    m_form = BARRENDITION_single;
}

bool AttBarLineLog::ReadBarLineLog(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("form")) {
        this->SetForm(StrToBarRendition(element.attribute("form").value()));
        element.remove_attribute("form");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttBarLineLog::WriteBarLineLog(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasForm()) {
        element.append_attribute("form") = BarRenditionToStr(this->GetForm()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttBarLineLog::HasForm( )
{
    return (m_form != BARRENDITION_single);
}


/* include <attform> */

//----------------------------------------------------------------------------
// AttBarplacement
//----------------------------------------------------------------------------

AttBarplacement::AttBarplacement(): Att() {
    ResetBarplacement();
}

AttBarplacement::~AttBarplacement() {

}

void AttBarplacement::ResetBarplacement() {
    m_barplace = "";
    m_taktplace = "";
}

bool AttBarplacement::ReadBarplacement(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("barplace")) {
        this->SetBarplace(StrToStr(element.attribute("barplace").value()));
        element.remove_attribute("barplace");
        hasAttribute = true;
    }
    if (element.attribute("taktplace")) {
        this->SetTaktplace(StrToStr(element.attribute("taktplace").value()));
        element.remove_attribute("taktplace");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttBarplacement::WriteBarplacement(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasBarplace()) {
        element.append_attribute("barplace") = StrToStr(this->GetBarplace()).c_str();
        wroteAttribute = true;
    }
    if (this->HasTaktplace()) {
        element.append_attribute("taktplace") = StrToStr(this->GetTaktplace()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttBarplacement::HasBarplace( )
{
    return (m_barplace != "");
}

bool AttBarplacement::HasTaktplace( )
{
    return (m_taktplace != "");
}


/* include <atttaktplace> */

//----------------------------------------------------------------------------
// AttBeamingVis
//----------------------------------------------------------------------------

AttBeamingVis::AttBeamingVis(): Att() {
    ResetBeamingVis();
}

AttBeamingVis::~AttBeamingVis() {

}

void AttBeamingVis::ResetBeamingVis() {
    m_beamColor = "";
    m_beamRend = "";
    m_beamSlopeDbl = 0.0;
}

bool AttBeamingVis::ReadBeamingVis(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("beam.color")) {
        this->SetBeamColor(StrToStr(element.attribute("beam.color").value()));
        element.remove_attribute("beam.color");
        hasAttribute = true;
    }
    if (element.attribute("beam.rend")) {
        this->SetBeamRend(StrToStr(element.attribute("beam.rend").value()));
        element.remove_attribute("beam.rend");
        hasAttribute = true;
    }
    if (element.attribute("beam.slope")) {
        this->SetBeamSlope(StrToDbl(element.attribute("beam.slope").value()));
        element.remove_attribute("beam.slope");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttBeamingVis::WriteBeamingVis(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasBeamColor()) {
        element.append_attribute("beam.color") = StrToStr(this->GetBeamColor()).c_str();
        wroteAttribute = true;
    }
    if (this->HasBeamRend()) {
        element.append_attribute("beam.rend") = StrToStr(this->GetBeamRend()).c_str();
        wroteAttribute = true;
    }
    if (this->HasBeamSlope()) {
        element.append_attribute("beam.slope") = DblToStr(this->GetBeamSlope()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttBeamingVis::HasBeamColor( )
{
    return (m_beamColor != "");
}

bool AttBeamingVis::HasBeamRend( )
{
    return (m_beamRend != "");
}

bool AttBeamingVis::HasBeamSlope( )
{
    return (m_beamSlopeDbl != 0.0);
}


/* include <attbeam.slope> */

//----------------------------------------------------------------------------
// AttBibl
//----------------------------------------------------------------------------

AttBibl::AttBibl(): Att() {
    ResetBibl();
}

AttBibl::~AttBibl() {

}

void AttBibl::ResetBibl() {
    m_analog = "";
}

bool AttBibl::ReadBibl(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("analog")) {
        this->SetAnalog(StrToStr(element.attribute("analog").value()));
        element.remove_attribute("analog");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttBibl::WriteBibl(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasAnalog()) {
        element.append_attribute("analog") = StrToStr(this->GetAnalog()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttBibl::HasAnalog( )
{
    return (m_analog != "");
}


/* include <attanalog> */

//----------------------------------------------------------------------------
// AttCalendared
//----------------------------------------------------------------------------

AttCalendared::AttCalendared(): Att() {
    ResetCalendared();
}

AttCalendared::~AttCalendared() {

}

void AttCalendared::ResetCalendared() {
    m_calendar = "";
}

bool AttCalendared::ReadCalendared(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("calendar")) {
        this->SetCalendar(StrToStr(element.attribute("calendar").value()));
        element.remove_attribute("calendar");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttCalendared::WriteCalendared(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasCalendar()) {
        element.append_attribute("calendar") = StrToStr(this->GetCalendar()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttCalendared::HasCalendar( )
{
    return (m_calendar != "");
}


/* include <attcalendar> */

//----------------------------------------------------------------------------
// AttCanonical
//----------------------------------------------------------------------------

AttCanonical::AttCanonical(): Att() {
    ResetCanonical();
}

AttCanonical::~AttCanonical() {

}

void AttCanonical::ResetCanonical() {
    m_codedval = "";
}

bool AttCanonical::ReadCanonical(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("codedval")) {
        this->SetCodedval(StrToStr(element.attribute("codedval").value()));
        element.remove_attribute("codedval");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttCanonical::WriteCanonical(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasCodedval()) {
        element.append_attribute("codedval") = StrToStr(this->GetCodedval()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttCanonical::HasCodedval( )
{
    return (m_codedval != "");
}


/* include <attcodedval> */

//----------------------------------------------------------------------------
// AttChordVis
//----------------------------------------------------------------------------

AttChordVis::AttChordVis(): Att() {
    ResetChordVis();
}

AttChordVis::~AttChordVis() {

}

void AttChordVis::ResetChordVis() {
    m_cluster = "";
}

bool AttChordVis::ReadChordVis(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("cluster")) {
        this->SetCluster(StrToStr(element.attribute("cluster").value()));
        element.remove_attribute("cluster");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttChordVis::WriteChordVis(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasCluster()) {
        element.append_attribute("cluster") = StrToStr(this->GetCluster()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttChordVis::HasCluster( )
{
    return (m_cluster != "");
}


/* include <attcluster> */

//----------------------------------------------------------------------------
// AttClasscodeident
//----------------------------------------------------------------------------

AttClasscodeident::AttClasscodeident(): Att() {
    ResetClasscodeident();
}

AttClasscodeident::~AttClasscodeident() {

}

void AttClasscodeident::ResetClasscodeident() {
    m_classcode = "";
}

bool AttClasscodeident::ReadClasscodeident(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("classcode")) {
        this->SetClasscode(StrToStr(element.attribute("classcode").value()));
        element.remove_attribute("classcode");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttClasscodeident::WriteClasscodeident(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasClasscode()) {
        element.append_attribute("classcode") = StrToStr(this->GetClasscode()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttClasscodeident::HasClasscode( )
{
    return (m_classcode != "");
}


/* include <attclasscode> */

//----------------------------------------------------------------------------
// AttClefLog
//----------------------------------------------------------------------------

AttClefLog::AttClefLog(): Att() {
    ResetClefLog();
}

AttClefLog::~AttClefLog() {

}

void AttClefLog::ResetClefLog() {
    m_cautionary = "";
}

bool AttClefLog::ReadClefLog(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("cautionary")) {
        this->SetCautionary(StrToStr(element.attribute("cautionary").value()));
        element.remove_attribute("cautionary");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttClefLog::WriteClefLog(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasCautionary()) {
        element.append_attribute("cautionary") = StrToStr(this->GetCautionary()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttClefLog::HasCautionary( )
{
    return (m_cautionary != "");
}


/* include <attcautionary> */

//----------------------------------------------------------------------------
// AttCleffingLog
//----------------------------------------------------------------------------

AttCleffingLog::AttCleffingLog(): Att() {
    ResetCleffingLog();
}

AttCleffingLog::~AttCleffingLog() {

}

void AttCleffingLog::ResetCleffingLog() {
    m_clefShape = CLEFSHAPE_NONE;
    m_clefLine = 0;
    m_clefDis = OCTAVE_DIS_NONE;
    m_clefDisPlace = PLACE_NONE;
}

bool AttCleffingLog::ReadCleffingLog(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("clef.shape")) {
        this->SetClefShape(StrToClefShape(element.attribute("clef.shape").value()));
        element.remove_attribute("clef.shape");
        hasAttribute = true;
    }
    if (element.attribute("clef.line")) {
        this->SetClefLine(StrToInt(element.attribute("clef.line").value()));
        element.remove_attribute("clef.line");
        hasAttribute = true;
    }
    if (element.attribute("clef.dis")) {
        this->SetClefDis(StrToOctaveDis(element.attribute("clef.dis").value()));
        element.remove_attribute("clef.dis");
        hasAttribute = true;
    }
    if (element.attribute("clef.dis.place")) {
        this->SetClefDisPlace(StrToPlace(element.attribute("clef.dis.place").value()));
        element.remove_attribute("clef.dis.place");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttCleffingLog::WriteCleffingLog(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasClefShape()) {
        element.append_attribute("clef.shape") = ClefShapeToStr(this->GetClefShape()).c_str();
        wroteAttribute = true;
    }
    if (this->HasClefLine()) {
        element.append_attribute("clef.line") = IntToStr(this->GetClefLine()).c_str();
        wroteAttribute = true;
    }
    if (this->HasClefDis()) {
        element.append_attribute("clef.dis") = OctaveDisToStr(this->GetClefDis()).c_str();
        wroteAttribute = true;
    }
    if (this->HasClefDisPlace()) {
        element.append_attribute("clef.dis.place") = PlaceToStr(this->GetClefDisPlace()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttCleffingLog::HasClefShape( )
{
    return (m_clefShape != CLEFSHAPE_NONE);
}

bool AttCleffingLog::HasClefLine( )
{
    return (m_clefLine != 0);
}

bool AttCleffingLog::HasClefDis( )
{
    return (m_clefDis != OCTAVE_DIS_NONE);
}

bool AttCleffingLog::HasClefDisPlace( )
{
    return (m_clefDisPlace != PLACE_NONE);
}


/* include <attclef.dis.place> */

//----------------------------------------------------------------------------
// AttCleffingVis
//----------------------------------------------------------------------------

AttCleffingVis::AttCleffingVis(): Att() {
    ResetCleffingVis();
}

AttCleffingVis::~AttCleffingVis() {

}

void AttCleffingVis::ResetCleffingVis() {
    m_clefColor = "";
    m_clefVisible = "";
}

bool AttCleffingVis::ReadCleffingVis(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("clef.color")) {
        this->SetClefColor(StrToStr(element.attribute("clef.color").value()));
        element.remove_attribute("clef.color");
        hasAttribute = true;
    }
    if (element.attribute("clef.visible")) {
        this->SetClefVisible(StrToStr(element.attribute("clef.visible").value()));
        element.remove_attribute("clef.visible");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttCleffingVis::WriteCleffingVis(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasClefColor()) {
        element.append_attribute("clef.color") = StrToStr(this->GetClefColor()).c_str();
        wroteAttribute = true;
    }
    if (this->HasClefVisible()) {
        element.append_attribute("clef.visible") = StrToStr(this->GetClefVisible()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttCleffingVis::HasClefColor( )
{
    return (m_clefColor != "");
}

bool AttCleffingVis::HasClefVisible( )
{
    return (m_clefVisible != "");
}


/* include <attclef.visible> */

//----------------------------------------------------------------------------
// AttClefshape
//----------------------------------------------------------------------------

AttClefshape::AttClefshape(): Att() {
    ResetClefshape();
}

AttClefshape::~AttClefshape() {

}

void AttClefshape::ResetClefshape() {
    m_shape = CLEFSHAPE_NONE;
}

bool AttClefshape::ReadClefshape(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("shape")) {
        this->SetShape(StrToClefShape(element.attribute("shape").value()));
        element.remove_attribute("shape");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttClefshape::WriteClefshape(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasShape()) {
        element.append_attribute("shape") = ClefShapeToStr(this->GetShape()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttClefshape::HasShape( )
{
    return (m_shape != CLEFSHAPE_NONE);
}


/* include <attshape> */

//----------------------------------------------------------------------------
// AttColor
//----------------------------------------------------------------------------

AttColor::AttColor(): Att() {
    ResetColor();
}

AttColor::~AttColor() {

}

void AttColor::ResetColor() {
    m_color = "";
}

bool AttColor::ReadColor(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("color")) {
        this->SetColor(StrToStr(element.attribute("color").value()));
        element.remove_attribute("color");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttColor::WriteColor(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasColor()) {
        element.append_attribute("color") = StrToStr(this->GetColor()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttColor::HasColor( )
{
    return (m_color != "");
}


/* include <attcolor> */

//----------------------------------------------------------------------------
// AttColoration
//----------------------------------------------------------------------------

AttColoration::AttColoration(): Att() {
    ResetColoration();
}

AttColoration::~AttColoration() {

}

void AttColoration::ResetColoration() {
    m_colored = BOOLEAN_NONE;
}

bool AttColoration::ReadColoration(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("colored")) {
        this->SetColored(StrToBool(element.attribute("colored").value()));
        element.remove_attribute("colored");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttColoration::WriteColoration(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasColored()) {
        element.append_attribute("colored") = BoolToStr(this->GetColored()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttColoration::HasColored( )
{
    return (m_colored != BOOLEAN_NONE);
}


/* include <attcolored> */

//----------------------------------------------------------------------------
// AttCommon
//----------------------------------------------------------------------------

AttCommon::AttCommon(): Att() {
    ResetCommon();
}

AttCommon::~AttCommon() {

}

void AttCommon::ResetCommon() {
    m_n = 0;
}

bool AttCommon::ReadCommon(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("n")) {
        this->SetN(StrToInt(element.attribute("n").value()));
        element.remove_attribute("n");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttCommon::WriteCommon(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasN()) {
        element.append_attribute("n") = IntToStr(this->GetN()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttCommon::HasN( )
{
    return (m_n != 0);
}


/* include <attn> */

//----------------------------------------------------------------------------
// AttCommonPart
//----------------------------------------------------------------------------

AttCommonPart::AttCommonPart(): Att() {
    ResetCommonPart();
}

AttCommonPart::~AttCommonPart() {

}

void AttCommonPart::ResetCommonPart() {
    m_label = "";
    m_base = "";
}

bool AttCommonPart::ReadCommonPart(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("label")) {
        this->SetLabel(StrToStr(element.attribute("label").value()));
        element.remove_attribute("label");
        hasAttribute = true;
    }
    if (element.attribute("base")) {
        this->SetBase(StrToStr(element.attribute("base").value()));
        element.remove_attribute("base");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttCommonPart::WriteCommonPart(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasLabel()) {
        element.append_attribute("label") = StrToStr(this->GetLabel()).c_str();
        wroteAttribute = true;
    }
    if (this->HasBase()) {
        element.append_attribute("base") = StrToStr(this->GetBase()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttCommonPart::HasLabel( )
{
    return (m_label != "");
}

bool AttCommonPart::HasBase( )
{
    return (m_base != "");
}


/* include <attbase> */

//----------------------------------------------------------------------------
// AttCoordinated
//----------------------------------------------------------------------------

AttCoordinated::AttCoordinated(): Att() {
    ResetCoordinated();
}

AttCoordinated::~AttCoordinated() {

}

void AttCoordinated::ResetCoordinated() {
    m_ulxInt = 0;
    m_ulyInt = 0;
    m_lrxInt = 0;
    m_lryInt = 0;
}

bool AttCoordinated::ReadCoordinated(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("ulx")) {
        this->SetUlx(StrToInt(element.attribute("ulx").value()));
        element.remove_attribute("ulx");
        hasAttribute = true;
    }
    if (element.attribute("uly")) {
        this->SetUly(StrToInt(element.attribute("uly").value()));
        element.remove_attribute("uly");
        hasAttribute = true;
    }
    if (element.attribute("lrx")) {
        this->SetLrx(StrToInt(element.attribute("lrx").value()));
        element.remove_attribute("lrx");
        hasAttribute = true;
    }
    if (element.attribute("lry")) {
        this->SetLry(StrToInt(element.attribute("lry").value()));
        element.remove_attribute("lry");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttCoordinated::WriteCoordinated(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasUlx()) {
        element.append_attribute("ulx") = IntToStr(this->GetUlx()).c_str();
        wroteAttribute = true;
    }
    if (this->HasUly()) {
        element.append_attribute("uly") = IntToStr(this->GetUly()).c_str();
        wroteAttribute = true;
    }
    if (this->HasLrx()) {
        element.append_attribute("lrx") = IntToStr(this->GetLrx()).c_str();
        wroteAttribute = true;
    }
    if (this->HasLry()) {
        element.append_attribute("lry") = IntToStr(this->GetLry()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttCoordinated::HasUlx( )
{
    return (m_ulxInt != 0);
}

bool AttCoordinated::HasUly( )
{
    return (m_ulyInt != 0);
}

bool AttCoordinated::HasLrx( )
{
    return (m_lrxInt != 0);
}

bool AttCoordinated::HasLry( )
{
    return (m_lryInt != 0);
}


/* include <attlry> */

//----------------------------------------------------------------------------
// AttCurvature
//----------------------------------------------------------------------------

AttCurvature::AttCurvature(): Att() {
    ResetCurvature();
}

AttCurvature::~AttCurvature() {

}

void AttCurvature::ResetCurvature() {
    m_bezier = "";
    m_bulge = 0.0;
    m_curvedir = CURVEDIR_NONE;
}

bool AttCurvature::ReadCurvature(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("bezier")) {
        this->SetBezier(StrToStr(element.attribute("bezier").value()));
        element.remove_attribute("bezier");
        hasAttribute = true;
    }
    if (element.attribute("bulge")) {
        this->SetBulge(StrToDbl(element.attribute("bulge").value()));
        element.remove_attribute("bulge");
        hasAttribute = true;
    }
    if (element.attribute("curvedir")) {
        this->SetCurvedir(StrToCurvedir(element.attribute("curvedir").value()));
        element.remove_attribute("curvedir");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttCurvature::WriteCurvature(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasBezier()) {
        element.append_attribute("bezier") = StrToStr(this->GetBezier()).c_str();
        wroteAttribute = true;
    }
    if (this->HasBulge()) {
        element.append_attribute("bulge") = DblToStr(this->GetBulge()).c_str();
        wroteAttribute = true;
    }
    if (this->HasCurvedir()) {
        element.append_attribute("curvedir") = CurvedirToStr(this->GetCurvedir()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttCurvature::HasBezier( )
{
    return (m_bezier != "");
}

bool AttCurvature::HasBulge( )
{
    return (m_bulge != 0.0);
}

bool AttCurvature::HasCurvedir( )
{
    return (m_curvedir != CURVEDIR_NONE);
}


/* include <attcurvedir> */

//----------------------------------------------------------------------------
// AttCurverend
//----------------------------------------------------------------------------

AttCurverend::AttCurverend(): Att() {
    ResetCurverend();
}

AttCurverend::~AttCurverend() {

}

void AttCurverend::ResetCurverend() {
    m_lform = "";
    m_lwidth = "";
}

bool AttCurverend::ReadCurverend(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("lform")) {
        this->SetLform(StrToStr(element.attribute("lform").value()));
        element.remove_attribute("lform");
        hasAttribute = true;
    }
    if (element.attribute("lwidth")) {
        this->SetLwidth(StrToStr(element.attribute("lwidth").value()));
        element.remove_attribute("lwidth");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttCurverend::WriteCurverend(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasLform()) {
        element.append_attribute("lform") = StrToStr(this->GetLform()).c_str();
        wroteAttribute = true;
    }
    if (this->HasLwidth()) {
        element.append_attribute("lwidth") = StrToStr(this->GetLwidth()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttCurverend::HasLform( )
{
    return (m_lform != "");
}

bool AttCurverend::HasLwidth( )
{
    return (m_lwidth != "");
}


/* include <attlwidth> */

//----------------------------------------------------------------------------
// AttCustosLog
//----------------------------------------------------------------------------

AttCustosLog::AttCustosLog(): Att() {
    ResetCustosLog();
}

AttCustosLog::~AttCustosLog() {

}

void AttCustosLog::ResetCustosLog() {
    m_target = "";
}

bool AttCustosLog::ReadCustosLog(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("target")) {
        this->SetTarget(StrToStr(element.attribute("target").value()));
        element.remove_attribute("target");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttCustosLog::WriteCustosLog(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasTarget()) {
        element.append_attribute("target") = StrToStr(this->GetTarget()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttCustosLog::HasTarget( )
{
    return (m_target != "");
}


/* include <atttarget> */

//----------------------------------------------------------------------------
// AttDatable
//----------------------------------------------------------------------------

AttDatable::AttDatable(): Att() {
    ResetDatable();
}

AttDatable::~AttDatable() {

}

void AttDatable::ResetDatable() {
    m_enddate = "";
    m_isodate = "";
    m_notafter = "";
    m_notbefore = "";
    m_startdate = "";
}

bool AttDatable::ReadDatable(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("enddate")) {
        this->SetEnddate(StrToStr(element.attribute("enddate").value()));
        element.remove_attribute("enddate");
        hasAttribute = true;
    }
    if (element.attribute("isodate")) {
        this->SetIsodate(StrToStr(element.attribute("isodate").value()));
        element.remove_attribute("isodate");
        hasAttribute = true;
    }
    if (element.attribute("notafter")) {
        this->SetNotafter(StrToStr(element.attribute("notafter").value()));
        element.remove_attribute("notafter");
        hasAttribute = true;
    }
    if (element.attribute("notbefore")) {
        this->SetNotbefore(StrToStr(element.attribute("notbefore").value()));
        element.remove_attribute("notbefore");
        hasAttribute = true;
    }
    if (element.attribute("startdate")) {
        this->SetStartdate(StrToStr(element.attribute("startdate").value()));
        element.remove_attribute("startdate");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttDatable::WriteDatable(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasEnddate()) {
        element.append_attribute("enddate") = StrToStr(this->GetEnddate()).c_str();
        wroteAttribute = true;
    }
    if (this->HasIsodate()) {
        element.append_attribute("isodate") = StrToStr(this->GetIsodate()).c_str();
        wroteAttribute = true;
    }
    if (this->HasNotafter()) {
        element.append_attribute("notafter") = StrToStr(this->GetNotafter()).c_str();
        wroteAttribute = true;
    }
    if (this->HasNotbefore()) {
        element.append_attribute("notbefore") = StrToStr(this->GetNotbefore()).c_str();
        wroteAttribute = true;
    }
    if (this->HasStartdate()) {
        element.append_attribute("startdate") = StrToStr(this->GetStartdate()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttDatable::HasEnddate( )
{
    return (m_enddate != "");
}

bool AttDatable::HasIsodate( )
{
    return (m_isodate != "");
}

bool AttDatable::HasNotafter( )
{
    return (m_notafter != "");
}

bool AttDatable::HasNotbefore( )
{
    return (m_notbefore != "");
}

bool AttDatable::HasStartdate( )
{
    return (m_startdate != "");
}


/* include <attstartdate> */

//----------------------------------------------------------------------------
// AttDatapointing
//----------------------------------------------------------------------------

AttDatapointing::AttDatapointing(): Att() {
    ResetDatapointing();
}

AttDatapointing::~AttDatapointing() {

}

void AttDatapointing::ResetDatapointing() {
    m_data = "";
}

bool AttDatapointing::ReadDatapointing(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("data")) {
        this->SetData(StrToStr(element.attribute("data").value()));
        element.remove_attribute("data");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttDatapointing::WriteDatapointing(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasData()) {
        element.append_attribute("data") = StrToStr(this->GetData()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttDatapointing::HasData( )
{
    return (m_data != "");
}


/* include <attdata> */

//----------------------------------------------------------------------------
// AttDeclaring
//----------------------------------------------------------------------------

AttDeclaring::AttDeclaring(): Att() {
    ResetDeclaring();
}

AttDeclaring::~AttDeclaring() {

}

void AttDeclaring::ResetDeclaring() {
    m_decls = "";
}

bool AttDeclaring::ReadDeclaring(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("decls")) {
        this->SetDecls(StrToStr(element.attribute("decls").value()));
        element.remove_attribute("decls");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttDeclaring::WriteDeclaring(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasDecls()) {
        element.append_attribute("decls") = StrToStr(this->GetDecls()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttDeclaring::HasDecls( )
{
    return (m_decls != "");
}


/* include <attdecls> */

//----------------------------------------------------------------------------
// AttDistances
//----------------------------------------------------------------------------

AttDistances::AttDistances(): Att() {
    ResetDistances();
}

AttDistances::~AttDistances() {

}

void AttDistances::ResetDistances() {
    m_dynamDist = "";
    m_harmDist = "";
    m_textDist = "";
}

bool AttDistances::ReadDistances(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("dynam.dist")) {
        this->SetDynamDist(StrToStr(element.attribute("dynam.dist").value()));
        element.remove_attribute("dynam.dist");
        hasAttribute = true;
    }
    if (element.attribute("harm.dist")) {
        this->SetHarmDist(StrToStr(element.attribute("harm.dist").value()));
        element.remove_attribute("harm.dist");
        hasAttribute = true;
    }
    if (element.attribute("text.dist")) {
        this->SetTextDist(StrToStr(element.attribute("text.dist").value()));
        element.remove_attribute("text.dist");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttDistances::WriteDistances(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasDynamDist()) {
        element.append_attribute("dynam.dist") = StrToStr(this->GetDynamDist()).c_str();
        wroteAttribute = true;
    }
    if (this->HasHarmDist()) {
        element.append_attribute("harm.dist") = StrToStr(this->GetHarmDist()).c_str();
        wroteAttribute = true;
    }
    if (this->HasTextDist()) {
        element.append_attribute("text.dist") = StrToStr(this->GetTextDist()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttDistances::HasDynamDist( )
{
    return (m_dynamDist != "");
}

bool AttDistances::HasHarmDist( )
{
    return (m_harmDist != "");
}

bool AttDistances::HasTextDist( )
{
    return (m_textDist != "");
}


/* include <atttext.dist> */

//----------------------------------------------------------------------------
// AttDotLog
//----------------------------------------------------------------------------

AttDotLog::AttDotLog(): Att() {
    ResetDotLog();
}

AttDotLog::~AttDotLog() {

}

void AttDotLog::ResetDotLog() {
    m_form = BARRENDITION_single;
}

bool AttDotLog::ReadDotLog(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("form")) {
        this->SetForm(StrToBarRendition(element.attribute("form").value()));
        element.remove_attribute("form");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttDotLog::WriteDotLog(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasForm()) {
        element.append_attribute("form") = BarRenditionToStr(this->GetForm()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttDotLog::HasForm( )
{
    return (m_form != BARRENDITION_single);
}


/* include <attform> */

//----------------------------------------------------------------------------
// AttDurationAdditive
//----------------------------------------------------------------------------

AttDurationAdditive::AttDurationAdditive(): Att() {
    ResetDurationAdditive();
}

AttDurationAdditive::~AttDurationAdditive() {

}

void AttDurationAdditive::ResetDurationAdditive() {
    m_dur = DURATION_NONE;
}

bool AttDurationAdditive::ReadDurationAdditive(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("dur")) {
        this->SetDur(StrToDur(element.attribute("dur").value()));
        element.remove_attribute("dur");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttDurationAdditive::WriteDurationAdditive(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasDur()) {
        element.append_attribute("dur") = DurToStr(this->GetDur()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttDurationAdditive::HasDur( )
{
    return (m_dur != DURATION_NONE);
}


/* include <attdur> */

//----------------------------------------------------------------------------
// AttDurationDefault
//----------------------------------------------------------------------------

AttDurationDefault::AttDurationDefault(): Att() {
    ResetDurationDefault();
}

AttDurationDefault::~AttDurationDefault() {

}

void AttDurationDefault::ResetDurationDefault() {
    m_durDefault = "";
    m_numDefaultInt = 0;
    m_numbaseDefaultInt = 0;
}

bool AttDurationDefault::ReadDurationDefault(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("dur.default")) {
        this->SetDurDefault(StrToStr(element.attribute("dur.default").value()));
        element.remove_attribute("dur.default");
        hasAttribute = true;
    }
    if (element.attribute("num.default")) {
        this->SetNumDefault(StrToInt(element.attribute("num.default").value()));
        element.remove_attribute("num.default");
        hasAttribute = true;
    }
    if (element.attribute("numbase.default")) {
        this->SetNumbaseDefault(StrToInt(element.attribute("numbase.default").value()));
        element.remove_attribute("numbase.default");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttDurationDefault::WriteDurationDefault(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasDurDefault()) {
        element.append_attribute("dur.default") = StrToStr(this->GetDurDefault()).c_str();
        wroteAttribute = true;
    }
    if (this->HasNumDefault()) {
        element.append_attribute("num.default") = IntToStr(this->GetNumDefault()).c_str();
        wroteAttribute = true;
    }
    if (this->HasNumbaseDefault()) {
        element.append_attribute("numbase.default") = IntToStr(this->GetNumbaseDefault()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttDurationDefault::HasDurDefault( )
{
    return (m_durDefault != "");
}

bool AttDurationDefault::HasNumDefault( )
{
    return (m_numDefaultInt != 0);
}

bool AttDurationDefault::HasNumbaseDefault( )
{
    return (m_numbaseDefaultInt != 0);
}


/* include <attnumbase.default> */

//----------------------------------------------------------------------------
// AttDurationMusical
//----------------------------------------------------------------------------

AttDurationMusical::AttDurationMusical(): Att() {
    ResetDurationMusical();
}

AttDurationMusical::~AttDurationMusical() {

}

void AttDurationMusical::ResetDurationMusical() {
    m_dur = DURATION_NONE;
}

bool AttDurationMusical::ReadDurationMusical(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("dur")) {
        this->SetDur(StrToDur(element.attribute("dur").value()));
        element.remove_attribute("dur");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttDurationMusical::WriteDurationMusical(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasDur()) {
        element.append_attribute("dur") = DurToStr(this->GetDur()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttDurationMusical::HasDur( )
{
    return (m_dur != DURATION_NONE);
}


/* include <attdur> */

//----------------------------------------------------------------------------
// AttDurationPerformed
//----------------------------------------------------------------------------

AttDurationPerformed::AttDurationPerformed(): Att() {
    ResetDurationPerformed();
}

AttDurationPerformed::~AttDurationPerformed() {

}

void AttDurationPerformed::ResetDurationPerformed() {
    m_durGes = DURATION_NONE;
}

bool AttDurationPerformed::ReadDurationPerformed(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("dur.ges")) {
        this->SetDurGes(StrToDur(element.attribute("dur.ges").value()));
        element.remove_attribute("dur.ges");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttDurationPerformed::WriteDurationPerformed(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasDurGes()) {
        element.append_attribute("dur.ges") = DurToStr(this->GetDurGes()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttDurationPerformed::HasDurGes( )
{
    return (m_durGes != DURATION_NONE);
}


/* include <attdur.ges> */

//----------------------------------------------------------------------------
// AttDurationRatio
//----------------------------------------------------------------------------

AttDurationRatio::AttDurationRatio(): Att() {
    ResetDurationRatio();
}

AttDurationRatio::~AttDurationRatio() {

}

void AttDurationRatio::ResetDurationRatio() {
    m_num = -1;
    m_numbase = -1;
}

bool AttDurationRatio::ReadDurationRatio(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("num")) {
        this->SetNum(StrToInt(element.attribute("num").value()));
        element.remove_attribute("num");
        hasAttribute = true;
    }
    if (element.attribute("numbase")) {
        this->SetNumbase(StrToInt(element.attribute("numbase").value()));
        element.remove_attribute("numbase");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttDurationRatio::WriteDurationRatio(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasNum()) {
        element.append_attribute("num") = IntToStr(this->GetNum()).c_str();
        wroteAttribute = true;
    }
    if (this->HasNumbase()) {
        element.append_attribute("numbase") = IntToStr(this->GetNumbase()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttDurationRatio::HasNum( )
{
    return (m_num != -1);
}

bool AttDurationRatio::HasNumbase( )
{
    return (m_numbase != -1);
}


/* include <attnumbase> */

//----------------------------------------------------------------------------
// AttEnclosingchars
//----------------------------------------------------------------------------

AttEnclosingchars::AttEnclosingchars(): Att() {
    ResetEnclosingchars();
}

AttEnclosingchars::~AttEnclosingchars() {

}

void AttEnclosingchars::ResetEnclosingchars() {
    m_enclose = "";
}

bool AttEnclosingchars::ReadEnclosingchars(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("enclose")) {
        this->SetEnclose(StrToStr(element.attribute("enclose").value()));
        element.remove_attribute("enclose");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttEnclosingchars::WriteEnclosingchars(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasEnclose()) {
        element.append_attribute("enclose") = StrToStr(this->GetEnclose()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttEnclosingchars::HasEnclose( )
{
    return (m_enclose != "");
}


/* include <attenclose> */

//----------------------------------------------------------------------------
// AttEndings
//----------------------------------------------------------------------------

AttEndings::AttEndings(): Att() {
    ResetEndings();
}

AttEndings::~AttEndings() {

}

void AttEndings::ResetEndings() {
    m_endingRend = "";
}

bool AttEndings::ReadEndings(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("ending.rend")) {
        this->SetEndingRend(StrToStr(element.attribute("ending.rend").value()));
        element.remove_attribute("ending.rend");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttEndings::WriteEndings(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasEndingRend()) {
        element.append_attribute("ending.rend") = StrToStr(this->GetEndingRend()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttEndings::HasEndingRend( )
{
    return (m_endingRend != "");
}


/* include <attending.rend> */

//----------------------------------------------------------------------------
// AttExtender
//----------------------------------------------------------------------------

AttExtender::AttExtender(): Att() {
    ResetExtender();
}

AttExtender::~AttExtender() {

}

void AttExtender::ResetExtender() {
    m_extender = "";
}

bool AttExtender::ReadExtender(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("extender")) {
        this->SetExtender(StrToStr(element.attribute("extender").value()));
        element.remove_attribute("extender");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttExtender::WriteExtender(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasExtender()) {
        element.append_attribute("extender") = StrToStr(this->GetExtender()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttExtender::HasExtender( )
{
    return (m_extender != "");
}


/* include <attextender> */

//----------------------------------------------------------------------------
// AttFermatapresent
//----------------------------------------------------------------------------

AttFermatapresent::AttFermatapresent(): Att() {
    ResetFermatapresent();
}

AttFermatapresent::~AttFermatapresent() {

}

void AttFermatapresent::ResetFermatapresent() {
    m_fermata = PLACE_NONE;
}

bool AttFermatapresent::ReadFermatapresent(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("fermata")) {
        this->SetFermata(StrToPlace(element.attribute("fermata").value()));
        element.remove_attribute("fermata");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttFermatapresent::WriteFermatapresent(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasFermata()) {
        element.append_attribute("fermata") = PlaceToStr(this->GetFermata()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttFermatapresent::HasFermata( )
{
    return (m_fermata != PLACE_NONE);
}


/* include <attfermata> */

//----------------------------------------------------------------------------
// AttFiling
//----------------------------------------------------------------------------

AttFiling::AttFiling(): Att() {
    ResetFiling();
}

AttFiling::~AttFiling() {

}

void AttFiling::ResetFiling() {
    m_nonfilingInt = 0;
}

bool AttFiling::ReadFiling(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("nonfiling")) {
        this->SetNonfiling(StrToInt(element.attribute("nonfiling").value()));
        element.remove_attribute("nonfiling");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttFiling::WriteFiling(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasNonfiling()) {
        element.append_attribute("nonfiling") = IntToStr(this->GetNonfiling()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttFiling::HasNonfiling( )
{
    return (m_nonfilingInt != 0);
}


/* include <attnonfiling> */

//----------------------------------------------------------------------------
// AttGrpSymLog
//----------------------------------------------------------------------------

AttGrpSymLog::AttGrpSymLog(): Att() {
    ResetGrpSymLog();
}

AttGrpSymLog::~AttGrpSymLog() {

}

void AttGrpSymLog::ResetGrpSymLog() {
    m_levelInt = 0;
}

bool AttGrpSymLog::ReadGrpSymLog(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("level")) {
        this->SetLevel(StrToInt(element.attribute("level").value()));
        element.remove_attribute("level");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttGrpSymLog::WriteGrpSymLog(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasLevel()) {
        element.append_attribute("level") = IntToStr(this->GetLevel()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttGrpSymLog::HasLevel( )
{
    return (m_levelInt != 0);
}


/* include <attlevel> */

//----------------------------------------------------------------------------
// AttHandident
//----------------------------------------------------------------------------

AttHandident::AttHandident(): Att() {
    ResetHandident();
}

AttHandident::~AttHandident() {

}

void AttHandident::ResetHandident() {
    m_hand = "";
}

bool AttHandident::ReadHandident(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("hand")) {
        this->SetHand(StrToStr(element.attribute("hand").value()));
        element.remove_attribute("hand");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttHandident::WriteHandident(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasHand()) {
        element.append_attribute("hand") = StrToStr(this->GetHand()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttHandident::HasHand( )
{
    return (m_hand != "");
}


/* include <atthand> */

//----------------------------------------------------------------------------
// AttHeight
//----------------------------------------------------------------------------

AttHeight::AttHeight(): Att() {
    ResetHeight();
}

AttHeight::~AttHeight() {

}

void AttHeight::ResetHeight() {
    m_height = "";
}

bool AttHeight::ReadHeight(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("height")) {
        this->SetHeight(StrToStr(element.attribute("height").value()));
        element.remove_attribute("height");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttHeight::WriteHeight(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasHeight()) {
        element.append_attribute("height") = StrToStr(this->GetHeight()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttHeight::HasHeight( )
{
    return (m_height != "");
}


/* include <attheight> */

//----------------------------------------------------------------------------
// AttHorizontalalign
//----------------------------------------------------------------------------

AttHorizontalalign::AttHorizontalalign(): Att() {
    ResetHorizontalalign();
}

AttHorizontalalign::~AttHorizontalalign() {

}

void AttHorizontalalign::ResetHorizontalalign() {
    m_halign = "";
}

bool AttHorizontalalign::ReadHorizontalalign(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("halign")) {
        this->SetHalign(StrToStr(element.attribute("halign").value()));
        element.remove_attribute("halign");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttHorizontalalign::WriteHorizontalalign(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasHalign()) {
        element.append_attribute("halign") = StrToStr(this->GetHalign()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttHorizontalalign::HasHalign( )
{
    return (m_halign != "");
}


/* include <atthalign> */

//----------------------------------------------------------------------------
// AttInstrumentident
//----------------------------------------------------------------------------

AttInstrumentident::AttInstrumentident(): Att() {
    ResetInstrumentident();
}

AttInstrumentident::~AttInstrumentident() {

}

void AttInstrumentident::ResetInstrumentident() {
    m_instr = "";
}

bool AttInstrumentident::ReadInstrumentident(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("instr")) {
        this->SetInstr(StrToStr(element.attribute("instr").value()));
        element.remove_attribute("instr");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttInstrumentident::WriteInstrumentident(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasInstr()) {
        element.append_attribute("instr") = StrToStr(this->GetInstr()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttInstrumentident::HasInstr( )
{
    return (m_instr != "");
}


/* include <attinstr> */

//----------------------------------------------------------------------------
// AttInternetmedia
//----------------------------------------------------------------------------

AttInternetmedia::AttInternetmedia(): Att() {
    ResetInternetmedia();
}

AttInternetmedia::~AttInternetmedia() {

}

void AttInternetmedia::ResetInternetmedia() {
    m_mimetype = "";
}

bool AttInternetmedia::ReadInternetmedia(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("mimetype")) {
        this->SetMimetype(StrToStr(element.attribute("mimetype").value()));
        element.remove_attribute("mimetype");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttInternetmedia::WriteInternetmedia(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasMimetype()) {
        element.append_attribute("mimetype") = StrToStr(this->GetMimetype()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttInternetmedia::HasMimetype( )
{
    return (m_mimetype != "");
}


/* include <attmimetype> */

//----------------------------------------------------------------------------
// AttJoined
//----------------------------------------------------------------------------

AttJoined::AttJoined(): Att() {
    ResetJoined();
}

AttJoined::~AttJoined() {

}

void AttJoined::ResetJoined() {
    m_join = "";
}

bool AttJoined::ReadJoined(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("join")) {
        this->SetJoin(StrToStr(element.attribute("join").value()));
        element.remove_attribute("join");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttJoined::WriteJoined(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasJoin()) {
        element.append_attribute("join") = StrToStr(this->GetJoin()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttJoined::HasJoin( )
{
    return (m_join != "");
}


/* include <attjoin> */

//----------------------------------------------------------------------------
// AttKeySigLog
//----------------------------------------------------------------------------

AttKeySigLog::AttKeySigLog(): Att() {
    ResetKeySigLog();
}

AttKeySigLog::~AttKeySigLog() {

}

void AttKeySigLog::ResetKeySigLog() {
    m_mode = "";
}

bool AttKeySigLog::ReadKeySigLog(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("mode")) {
        this->SetMode(StrToStr(element.attribute("mode").value()));
        element.remove_attribute("mode");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttKeySigLog::WriteKeySigLog(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasMode()) {
        element.append_attribute("mode") = StrToStr(this->GetMode()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttKeySigLog::HasMode( )
{
    return (m_mode != "");
}


/* include <attmode> */

//----------------------------------------------------------------------------
// AttKeySigDefaultLog
//----------------------------------------------------------------------------

AttKeySigDefaultLog::AttKeySigDefaultLog(): Att() {
    ResetKeySigDefaultLog();
}

AttKeySigDefaultLog::~AttKeySigDefaultLog() {

}

void AttKeySigDefaultLog::ResetKeySigDefaultLog() {
    m_keyAccid = ACCIDENTAL_IMPLICIT_NONE;
    m_keyMode = MODE_NONE;
    m_keyPname = PITCHNAME_NONE;
    m_keySig = KEYSIGNATURE_NONE;
    m_keySigMixed = "";
}

bool AttKeySigDefaultLog::ReadKeySigDefaultLog(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("key.accid")) {
        this->SetKeyAccid(StrToAccidentalImplicit(element.attribute("key.accid").value()));
        element.remove_attribute("key.accid");
        hasAttribute = true;
    }
    if (element.attribute("key.mode")) {
        this->SetKeyMode(StrToMode(element.attribute("key.mode").value()));
        element.remove_attribute("key.mode");
        hasAttribute = true;
    }
    if (element.attribute("key.pname")) {
        this->SetKeyPname(StrToPitchName(element.attribute("key.pname").value()));
        element.remove_attribute("key.pname");
        hasAttribute = true;
    }
    if (element.attribute("key.sig")) {
        this->SetKeySig(StrToKeySignature(element.attribute("key.sig").value()));
        element.remove_attribute("key.sig");
        hasAttribute = true;
    }
    if (element.attribute("key.sig.mixed")) {
        this->SetKeySigMixed(StrToStr(element.attribute("key.sig.mixed").value()));
        element.remove_attribute("key.sig.mixed");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttKeySigDefaultLog::WriteKeySigDefaultLog(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasKeyAccid()) {
        element.append_attribute("key.accid") = AccidentalImplicitToStr(this->GetKeyAccid()).c_str();
        wroteAttribute = true;
    }
    if (this->HasKeyMode()) {
        element.append_attribute("key.mode") = ModeToStr(this->GetKeyMode()).c_str();
        wroteAttribute = true;
    }
    if (this->HasKeyPname()) {
        element.append_attribute("key.pname") = PitchNameToStr(this->GetKeyPname()).c_str();
        wroteAttribute = true;
    }
    if (this->HasKeySig()) {
        element.append_attribute("key.sig") = KeySignatureToStr(this->GetKeySig()).c_str();
        wroteAttribute = true;
    }
    if (this->HasKeySigMixed()) {
        element.append_attribute("key.sig.mixed") = StrToStr(this->GetKeySigMixed()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttKeySigDefaultLog::HasKeyAccid( )
{
    return (m_keyAccid != ACCIDENTAL_IMPLICIT_NONE);
}

bool AttKeySigDefaultLog::HasKeyMode( )
{
    return (m_keyMode != MODE_NONE);
}

bool AttKeySigDefaultLog::HasKeyPname( )
{
    return (m_keyPname != PITCHNAME_NONE);
}

bool AttKeySigDefaultLog::HasKeySig( )
{
    return (m_keySig != KEYSIGNATURE_NONE);
}

bool AttKeySigDefaultLog::HasKeySigMixed( )
{
    return (m_keySigMixed != "");
}


/* include <attkey.sig.mixed> */

//----------------------------------------------------------------------------
// AttKeySigDefaultVis
//----------------------------------------------------------------------------

AttKeySigDefaultVis::AttKeySigDefaultVis(): Att() {
    ResetKeySigDefaultVis();
}

AttKeySigDefaultVis::~AttKeySigDefaultVis() {

}

void AttKeySigDefaultVis::ResetKeySigDefaultVis() {
    m_keySigShow = BOOLEAN_NONE;
    m_keySigShowchange = BOOLEAN_NONE;
}

bool AttKeySigDefaultVis::ReadKeySigDefaultVis(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("key.sig.show")) {
        this->SetKeySigShow(StrToBool(element.attribute("key.sig.show").value()));
        element.remove_attribute("key.sig.show");
        hasAttribute = true;
    }
    if (element.attribute("key.sig.showchange")) {
        this->SetKeySigShowchange(StrToBool(element.attribute("key.sig.showchange").value()));
        element.remove_attribute("key.sig.showchange");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttKeySigDefaultVis::WriteKeySigDefaultVis(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasKeySigShow()) {
        element.append_attribute("key.sig.show") = BoolToStr(this->GetKeySigShow()).c_str();
        wroteAttribute = true;
    }
    if (this->HasKeySigShowchange()) {
        element.append_attribute("key.sig.showchange") = BoolToStr(this->GetKeySigShowchange()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttKeySigDefaultVis::HasKeySigShow( )
{
    return (m_keySigShow != BOOLEAN_NONE);
}

bool AttKeySigDefaultVis::HasKeySigShowchange( )
{
    return (m_keySigShowchange != BOOLEAN_NONE);
}


/* include <attkey.sig.showchange> */

//----------------------------------------------------------------------------
// AttLabelsAddl
//----------------------------------------------------------------------------

AttLabelsAddl::AttLabelsAddl(): Att() {
    ResetLabelsAddl();
}

AttLabelsAddl::~AttLabelsAddl() {

}

void AttLabelsAddl::ResetLabelsAddl() {
    m_labelAbbr = "";
}

bool AttLabelsAddl::ReadLabelsAddl(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("label.abbr")) {
        this->SetLabelAbbr(StrToStr(element.attribute("label.abbr").value()));
        element.remove_attribute("label.abbr");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttLabelsAddl::WriteLabelsAddl(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasLabelAbbr()) {
        element.append_attribute("label.abbr") = StrToStr(this->GetLabelAbbr()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttLabelsAddl::HasLabelAbbr( )
{
    return (m_labelAbbr != "");
}


/* include <attlabel.abbr> */

//----------------------------------------------------------------------------
// AttLang
//----------------------------------------------------------------------------

AttLang::AttLang(): Att() {
    ResetLang();
}

AttLang::~AttLang() {

}

void AttLang::ResetLang() {
    m_lang = "";
    m_translit = "";
}

bool AttLang::ReadLang(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("lang")) {
        this->SetLang(StrToStr(element.attribute("lang").value()));
        element.remove_attribute("lang");
        hasAttribute = true;
    }
    if (element.attribute("translit")) {
        this->SetTranslit(StrToStr(element.attribute("translit").value()));
        element.remove_attribute("translit");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttLang::WriteLang(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasLang()) {
        element.append_attribute("lang") = StrToStr(this->GetLang()).c_str();
        wroteAttribute = true;
    }
    if (this->HasTranslit()) {
        element.append_attribute("translit") = StrToStr(this->GetTranslit()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttLang::HasLang( )
{
    return (m_lang != "");
}

bool AttLang::HasTranslit( )
{
    return (m_translit != "");
}


/* include <atttranslit> */

//----------------------------------------------------------------------------
// AttLayerLog
//----------------------------------------------------------------------------

AttLayerLog::AttLayerLog(): Att() {
    ResetLayerLog();
}

AttLayerLog::~AttLayerLog() {

}

void AttLayerLog::ResetLayerLog() {
    m_def = "";
}

bool AttLayerLog::ReadLayerLog(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("def")) {
        this->SetDef(StrToStr(element.attribute("def").value()));
        element.remove_attribute("def");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttLayerLog::WriteLayerLog(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasDef()) {
        element.append_attribute("def") = StrToStr(this->GetDef()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttLayerLog::HasDef( )
{
    return (m_def != "");
}


/* include <attdef> */

//----------------------------------------------------------------------------
// AttLayerident
//----------------------------------------------------------------------------

AttLayerident::AttLayerident(): Att() {
    ResetLayerident();
}

AttLayerident::~AttLayerident() {

}

void AttLayerident::ResetLayerident() {
    m_layerInt = 0;
}

bool AttLayerident::ReadLayerident(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("layer")) {
        this->SetLayer(StrToInt(element.attribute("layer").value()));
        element.remove_attribute("layer");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttLayerident::WriteLayerident(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasLayer()) {
        element.append_attribute("layer") = IntToStr(this->GetLayer()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttLayerident::HasLayer( )
{
    return (m_layerInt != 0);
}


/* include <attlayer> */

//----------------------------------------------------------------------------
// AttLineVis
//----------------------------------------------------------------------------

AttLineVis::AttLineVis(): Att() {
    ResetLineVis();
}

AttLineVis::~AttLineVis() {

}

void AttLineVis::ResetLineVis() {
    m_form = BARRENDITION_single;
    m_width = "";
    m_endsym = "";
    m_endsymsize = "";
    m_startsym = "";
    m_startsymsize = "";
}

bool AttLineVis::ReadLineVis(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("form")) {
        this->SetForm(StrToBarRendition(element.attribute("form").value()));
        element.remove_attribute("form");
        hasAttribute = true;
    }
    if (element.attribute("width")) {
        this->SetWidth(StrToStr(element.attribute("width").value()));
        element.remove_attribute("width");
        hasAttribute = true;
    }
    if (element.attribute("endsym")) {
        this->SetEndsym(StrToStr(element.attribute("endsym").value()));
        element.remove_attribute("endsym");
        hasAttribute = true;
    }
    if (element.attribute("endsymsize")) {
        this->SetEndsymsize(StrToStr(element.attribute("endsymsize").value()));
        element.remove_attribute("endsymsize");
        hasAttribute = true;
    }
    if (element.attribute("startsym")) {
        this->SetStartsym(StrToStr(element.attribute("startsym").value()));
        element.remove_attribute("startsym");
        hasAttribute = true;
    }
    if (element.attribute("startsymsize")) {
        this->SetStartsymsize(StrToStr(element.attribute("startsymsize").value()));
        element.remove_attribute("startsymsize");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttLineVis::WriteLineVis(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasForm()) {
        element.append_attribute("form") = BarRenditionToStr(this->GetForm()).c_str();
        wroteAttribute = true;
    }
    if (this->HasWidth()) {
        element.append_attribute("width") = StrToStr(this->GetWidth()).c_str();
        wroteAttribute = true;
    }
    if (this->HasEndsym()) {
        element.append_attribute("endsym") = StrToStr(this->GetEndsym()).c_str();
        wroteAttribute = true;
    }
    if (this->HasEndsymsize()) {
        element.append_attribute("endsymsize") = StrToStr(this->GetEndsymsize()).c_str();
        wroteAttribute = true;
    }
    if (this->HasStartsym()) {
        element.append_attribute("startsym") = StrToStr(this->GetStartsym()).c_str();
        wroteAttribute = true;
    }
    if (this->HasStartsymsize()) {
        element.append_attribute("startsymsize") = StrToStr(this->GetStartsymsize()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttLineVis::HasForm( )
{
    return (m_form != BARRENDITION_single);
}

bool AttLineVis::HasWidth( )
{
    return (m_width != "");
}

bool AttLineVis::HasEndsym( )
{
    return (m_endsym != "");
}

bool AttLineVis::HasEndsymsize( )
{
    return (m_endsymsize != "");
}

bool AttLineVis::HasStartsym( )
{
    return (m_startsym != "");
}

bool AttLineVis::HasStartsymsize( )
{
    return (m_startsymsize != "");
}


/* include <attstartsymsize> */

//----------------------------------------------------------------------------
// AttLineloc
//----------------------------------------------------------------------------

AttLineloc::AttLineloc(): Att() {
    ResetLineloc();
}

AttLineloc::~AttLineloc() {

}

void AttLineloc::ResetLineloc() {
    m_line = 0;
}

bool AttLineloc::ReadLineloc(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("line")) {
        this->SetLine(StrToInt(element.attribute("line").value()));
        element.remove_attribute("line");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttLineloc::WriteLineloc(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasLine()) {
        element.append_attribute("line") = IntToStr(this->GetLine()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttLineloc::HasLine( )
{
    return (m_line != 0);
}


/* include <attline> */

//----------------------------------------------------------------------------
// AttLinerend
//----------------------------------------------------------------------------

AttLinerend::AttLinerend(): Att() {
    ResetLinerend();
}

AttLinerend::~AttLinerend() {

}

void AttLinerend::ResetLinerend() {
    m_lendsym = "";
    m_lendsymsize = "";
    m_lstartsym = "";
    m_lstartsymsize = "";
}

bool AttLinerend::ReadLinerend(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("lendsym")) {
        this->SetLendsym(StrToStr(element.attribute("lendsym").value()));
        element.remove_attribute("lendsym");
        hasAttribute = true;
    }
    if (element.attribute("lendsymsize")) {
        this->SetLendsymsize(StrToStr(element.attribute("lendsymsize").value()));
        element.remove_attribute("lendsymsize");
        hasAttribute = true;
    }
    if (element.attribute("lstartsym")) {
        this->SetLstartsym(StrToStr(element.attribute("lstartsym").value()));
        element.remove_attribute("lstartsym");
        hasAttribute = true;
    }
    if (element.attribute("lstartsymsize")) {
        this->SetLstartsymsize(StrToStr(element.attribute("lstartsymsize").value()));
        element.remove_attribute("lstartsymsize");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttLinerend::WriteLinerend(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasLendsym()) {
        element.append_attribute("lendsym") = StrToStr(this->GetLendsym()).c_str();
        wroteAttribute = true;
    }
    if (this->HasLendsymsize()) {
        element.append_attribute("lendsymsize") = StrToStr(this->GetLendsymsize()).c_str();
        wroteAttribute = true;
    }
    if (this->HasLstartsym()) {
        element.append_attribute("lstartsym") = StrToStr(this->GetLstartsym()).c_str();
        wroteAttribute = true;
    }
    if (this->HasLstartsymsize()) {
        element.append_attribute("lstartsymsize") = StrToStr(this->GetLstartsymsize()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttLinerend::HasLendsym( )
{
    return (m_lendsym != "");
}

bool AttLinerend::HasLendsymsize( )
{
    return (m_lendsymsize != "");
}

bool AttLinerend::HasLstartsym( )
{
    return (m_lstartsym != "");
}

bool AttLinerend::HasLstartsymsize( )
{
    return (m_lstartsymsize != "");
}


/* include <attlstartsymsize> */

//----------------------------------------------------------------------------
// AttLinerendBase
//----------------------------------------------------------------------------

AttLinerendBase::AttLinerendBase(): Att() {
    ResetLinerendBase();
}

AttLinerendBase::~AttLinerendBase() {

}

void AttLinerendBase::ResetLinerendBase() {
    m_lform = "";
    m_lwidth = "";
}

bool AttLinerendBase::ReadLinerendBase(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("lform")) {
        this->SetLform(StrToStr(element.attribute("lform").value()));
        element.remove_attribute("lform");
        hasAttribute = true;
    }
    if (element.attribute("lwidth")) {
        this->SetLwidth(StrToStr(element.attribute("lwidth").value()));
        element.remove_attribute("lwidth");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttLinerendBase::WriteLinerendBase(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasLform()) {
        element.append_attribute("lform") = StrToStr(this->GetLform()).c_str();
        wroteAttribute = true;
    }
    if (this->HasLwidth()) {
        element.append_attribute("lwidth") = StrToStr(this->GetLwidth()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttLinerendBase::HasLform( )
{
    return (m_lform != "");
}

bool AttLinerendBase::HasLwidth( )
{
    return (m_lwidth != "");
}


/* include <attlwidth> */

//----------------------------------------------------------------------------
// AttLyricstyle
//----------------------------------------------------------------------------

AttLyricstyle::AttLyricstyle(): Att() {
    ResetLyricstyle();
}

AttLyricstyle::~AttLyricstyle() {

}

void AttLyricstyle::ResetLyricstyle() {
    m_lyricAlign = "";
    m_lyricFam = "";
    m_lyricName = "";
    m_lyricSize = "";
    m_lyricStyle = "";
    m_lyricWeight = "";
}

bool AttLyricstyle::ReadLyricstyle(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("lyric.align")) {
        this->SetLyricAlign(StrToStr(element.attribute("lyric.align").value()));
        element.remove_attribute("lyric.align");
        hasAttribute = true;
    }
    if (element.attribute("lyric.fam")) {
        this->SetLyricFam(StrToStr(element.attribute("lyric.fam").value()));
        element.remove_attribute("lyric.fam");
        hasAttribute = true;
    }
    if (element.attribute("lyric.name")) {
        this->SetLyricName(StrToStr(element.attribute("lyric.name").value()));
        element.remove_attribute("lyric.name");
        hasAttribute = true;
    }
    if (element.attribute("lyric.size")) {
        this->SetLyricSize(StrToStr(element.attribute("lyric.size").value()));
        element.remove_attribute("lyric.size");
        hasAttribute = true;
    }
    if (element.attribute("lyric.style")) {
        this->SetLyricStyle(StrToStr(element.attribute("lyric.style").value()));
        element.remove_attribute("lyric.style");
        hasAttribute = true;
    }
    if (element.attribute("lyric.weight")) {
        this->SetLyricWeight(StrToStr(element.attribute("lyric.weight").value()));
        element.remove_attribute("lyric.weight");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttLyricstyle::WriteLyricstyle(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasLyricAlign()) {
        element.append_attribute("lyric.align") = StrToStr(this->GetLyricAlign()).c_str();
        wroteAttribute = true;
    }
    if (this->HasLyricFam()) {
        element.append_attribute("lyric.fam") = StrToStr(this->GetLyricFam()).c_str();
        wroteAttribute = true;
    }
    if (this->HasLyricName()) {
        element.append_attribute("lyric.name") = StrToStr(this->GetLyricName()).c_str();
        wroteAttribute = true;
    }
    if (this->HasLyricSize()) {
        element.append_attribute("lyric.size") = StrToStr(this->GetLyricSize()).c_str();
        wroteAttribute = true;
    }
    if (this->HasLyricStyle()) {
        element.append_attribute("lyric.style") = StrToStr(this->GetLyricStyle()).c_str();
        wroteAttribute = true;
    }
    if (this->HasLyricWeight()) {
        element.append_attribute("lyric.weight") = StrToStr(this->GetLyricWeight()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttLyricstyle::HasLyricAlign( )
{
    return (m_lyricAlign != "");
}

bool AttLyricstyle::HasLyricFam( )
{
    return (m_lyricFam != "");
}

bool AttLyricstyle::HasLyricName( )
{
    return (m_lyricName != "");
}

bool AttLyricstyle::HasLyricSize( )
{
    return (m_lyricSize != "");
}

bool AttLyricstyle::HasLyricStyle( )
{
    return (m_lyricStyle != "");
}

bool AttLyricstyle::HasLyricWeight( )
{
    return (m_lyricWeight != "");
}


/* include <attlyric.weight> */

//----------------------------------------------------------------------------
// AttMeasureLog
//----------------------------------------------------------------------------

AttMeasureLog::AttMeasureLog(): Att() {
    ResetMeasureLog();
}

AttMeasureLog::~AttMeasureLog() {

}

void AttMeasureLog::ResetMeasureLog() {
    m_left = BARRENDITION_NONE;
    m_right = BARRENDITION_single;
}

bool AttMeasureLog::ReadMeasureLog(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("left")) {
        this->SetLeft(StrToBarRendition(element.attribute("left").value()));
        element.remove_attribute("left");
        hasAttribute = true;
    }
    if (element.attribute("right")) {
        this->SetRight(StrToBarRendition(element.attribute("right").value()));
        element.remove_attribute("right");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttMeasureLog::WriteMeasureLog(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasLeft()) {
        element.append_attribute("left") = BarRenditionToStr(this->GetLeft()).c_str();
        wroteAttribute = true;
    }
    if (this->HasRight()) {
        element.append_attribute("right") = BarRenditionToStr(this->GetRight()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttMeasureLog::HasLeft( )
{
    return (m_left != BARRENDITION_NONE);
}

bool AttMeasureLog::HasRight( )
{
    return (m_right != BARRENDITION_single);
}


/* include <attright> */

//----------------------------------------------------------------------------
// AttMeasurement
//----------------------------------------------------------------------------

AttMeasurement::AttMeasurement(): Att() {
    ResetMeasurement();
}

AttMeasurement::~AttMeasurement() {

}

void AttMeasurement::ResetMeasurement() {
    m_unit = 0;
}

bool AttMeasurement::ReadMeasurement(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("unit")) {
        this->SetUnit(StrToInt(element.attribute("unit").value()));
        element.remove_attribute("unit");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttMeasurement::WriteMeasurement(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasUnit()) {
        element.append_attribute("unit") = IntToStr(this->GetUnit()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttMeasurement::HasUnit( )
{
    return (m_unit != 0);
}


/* include <attunit> */

//----------------------------------------------------------------------------
// AttMeasurenumbers
//----------------------------------------------------------------------------

AttMeasurenumbers::AttMeasurenumbers(): Att() {
    ResetMeasurenumbers();
}

AttMeasurenumbers::~AttMeasurenumbers() {

}

void AttMeasurenumbers::ResetMeasurenumbers() {
    m_mnumVisible = "";
}

bool AttMeasurenumbers::ReadMeasurenumbers(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("mnum.visible")) {
        this->SetMnumVisible(StrToStr(element.attribute("mnum.visible").value()));
        element.remove_attribute("mnum.visible");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttMeasurenumbers::WriteMeasurenumbers(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasMnumVisible()) {
        element.append_attribute("mnum.visible") = StrToStr(this->GetMnumVisible()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttMeasurenumbers::HasMnumVisible( )
{
    return (m_mnumVisible != "");
}


/* include <attmnum.visible> */

//----------------------------------------------------------------------------
// AttMediabounds
//----------------------------------------------------------------------------

AttMediabounds::AttMediabounds(): Att() {
    ResetMediabounds();
}

AttMediabounds::~AttMediabounds() {

}

void AttMediabounds::ResetMediabounds() {
    m_begin = "";
    m_end = "";
    m_betype = "";
}

bool AttMediabounds::ReadMediabounds(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("begin")) {
        this->SetBegin(StrToStr(element.attribute("begin").value()));
        element.remove_attribute("begin");
        hasAttribute = true;
    }
    if (element.attribute("end")) {
        this->SetEnd(StrToStr(element.attribute("end").value()));
        element.remove_attribute("end");
        hasAttribute = true;
    }
    if (element.attribute("betype")) {
        this->SetBetype(StrToStr(element.attribute("betype").value()));
        element.remove_attribute("betype");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttMediabounds::WriteMediabounds(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasBegin()) {
        element.append_attribute("begin") = StrToStr(this->GetBegin()).c_str();
        wroteAttribute = true;
    }
    if (this->HasEnd()) {
        element.append_attribute("end") = StrToStr(this->GetEnd()).c_str();
        wroteAttribute = true;
    }
    if (this->HasBetype()) {
        element.append_attribute("betype") = StrToStr(this->GetBetype()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttMediabounds::HasBegin( )
{
    return (m_begin != "");
}

bool AttMediabounds::HasEnd( )
{
    return (m_end != "");
}

bool AttMediabounds::HasBetype( )
{
    return (m_betype != "");
}


/* include <attbetype> */

//----------------------------------------------------------------------------
// AttMedium
//----------------------------------------------------------------------------

AttMedium::AttMedium(): Att() {
    ResetMedium();
}

AttMedium::~AttMedium() {

}

void AttMedium::ResetMedium() {
    m_medium = "";
}

bool AttMedium::ReadMedium(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("medium")) {
        this->SetMedium(StrToStr(element.attribute("medium").value()));
        element.remove_attribute("medium");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttMedium::WriteMedium(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasMedium()) {
        element.append_attribute("medium") = StrToStr(this->GetMedium()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttMedium::HasMedium( )
{
    return (m_medium != "");
}


/* include <attmedium> */

//----------------------------------------------------------------------------
// AttMeiversion
//----------------------------------------------------------------------------

AttMeiversion::AttMeiversion(): Att() {
    ResetMeiversion();
}

AttMeiversion::~AttMeiversion() {

}

void AttMeiversion::ResetMeiversion() {
    m_meiversion = "";
}

bool AttMeiversion::ReadMeiversion(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("meiversion")) {
        this->SetMeiversion(StrToStr(element.attribute("meiversion").value()));
        element.remove_attribute("meiversion");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttMeiversion::WriteMeiversion(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasMeiversion()) {
        element.append_attribute("meiversion") = StrToStr(this->GetMeiversion()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttMeiversion::HasMeiversion( )
{
    return (m_meiversion != "");
}


/* include <attmeiversion> */

//----------------------------------------------------------------------------
// AttMensurLog
//----------------------------------------------------------------------------

AttMensurLog::AttMensurLog(): Att() {
    ResetMensurLog();
}

AttMensurLog::~AttMensurLog() {

}

void AttMensurLog::ResetMensurLog() {
    m_dot = BOOLEAN_NONE;
    m_sign = MENSURATIONSIGN_NONE;
}

bool AttMensurLog::ReadMensurLog(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("dot")) {
        this->SetDot(StrToBool(element.attribute("dot").value()));
        element.remove_attribute("dot");
        hasAttribute = true;
    }
    if (element.attribute("sign")) {
        this->SetSign(StrToMensurationSign(element.attribute("sign").value()));
        element.remove_attribute("sign");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttMensurLog::WriteMensurLog(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasDot()) {
        element.append_attribute("dot") = BoolToStr(this->GetDot()).c_str();
        wroteAttribute = true;
    }
    if (this->HasSign()) {
        element.append_attribute("sign") = MensurationSignToStr(this->GetSign()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttMensurLog::HasDot( )
{
    return (m_dot != BOOLEAN_NONE);
}

bool AttMensurLog::HasSign( )
{
    return (m_sign != MENSURATIONSIGN_NONE);
}


/* include <attsign> */

//----------------------------------------------------------------------------
// AttMeterSigLog
//----------------------------------------------------------------------------

AttMeterSigLog::AttMeterSigLog(): Att() {
    ResetMeterSigLog();
}

AttMeterSigLog::~AttMeterSigLog() {

}

void AttMeterSigLog::ResetMeterSigLog() {
    m_count = 0;
    m_sym = METERSIGN_NONE;
    m_unit = 0;
}

bool AttMeterSigLog::ReadMeterSigLog(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("count")) {
        this->SetCount(StrToInt(element.attribute("count").value()));
        element.remove_attribute("count");
        hasAttribute = true;
    }
    if (element.attribute("sym")) {
        this->SetSym(StrToMeterSign(element.attribute("sym").value()));
        element.remove_attribute("sym");
        hasAttribute = true;
    }
    if (element.attribute("unit")) {
        this->SetUnit(StrToInt(element.attribute("unit").value()));
        element.remove_attribute("unit");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttMeterSigLog::WriteMeterSigLog(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasCount()) {
        element.append_attribute("count") = IntToStr(this->GetCount()).c_str();
        wroteAttribute = true;
    }
    if (this->HasSym()) {
        element.append_attribute("sym") = MeterSignToStr(this->GetSym()).c_str();
        wroteAttribute = true;
    }
    if (this->HasUnit()) {
        element.append_attribute("unit") = IntToStr(this->GetUnit()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttMeterSigLog::HasCount( )
{
    return (m_count != 0);
}

bool AttMeterSigLog::HasSym( )
{
    return (m_sym != METERSIGN_NONE);
}

bool AttMeterSigLog::HasUnit( )
{
    return (m_unit != 0);
}


/* include <attunit> */

//----------------------------------------------------------------------------
// AttMeterSigVis
//----------------------------------------------------------------------------

AttMeterSigVis::AttMeterSigVis(): Att() {
    ResetMeterSigVis();
}

AttMeterSigVis::~AttMeterSigVis() {

}

void AttMeterSigVis::ResetMeterSigVis() {
    m_form = BARRENDITION_single;
}

bool AttMeterSigVis::ReadMeterSigVis(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("form")) {
        this->SetForm(StrToBarRendition(element.attribute("form").value()));
        element.remove_attribute("form");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttMeterSigVis::WriteMeterSigVis(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasForm()) {
        element.append_attribute("form") = BarRenditionToStr(this->GetForm()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttMeterSigVis::HasForm( )
{
    return (m_form != BARRENDITION_single);
}


/* include <attform> */

//----------------------------------------------------------------------------
// AttMeterSigDefaultLog
//----------------------------------------------------------------------------

AttMeterSigDefaultLog::AttMeterSigDefaultLog(): Att() {
    ResetMeterSigDefaultLog();
}

AttMeterSigDefaultLog::~AttMeterSigDefaultLog() {

}

void AttMeterSigDefaultLog::ResetMeterSigDefaultLog() {
    m_meterCount = 0;
    m_meterUnit = 0;
}

bool AttMeterSigDefaultLog::ReadMeterSigDefaultLog(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("meter.count")) {
        this->SetMeterCount(StrToInt(element.attribute("meter.count").value()));
        element.remove_attribute("meter.count");
        hasAttribute = true;
    }
    if (element.attribute("meter.unit")) {
        this->SetMeterUnit(StrToInt(element.attribute("meter.unit").value()));
        element.remove_attribute("meter.unit");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttMeterSigDefaultLog::WriteMeterSigDefaultLog(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasMeterCount()) {
        element.append_attribute("meter.count") = IntToStr(this->GetMeterCount()).c_str();
        wroteAttribute = true;
    }
    if (this->HasMeterUnit()) {
        element.append_attribute("meter.unit") = IntToStr(this->GetMeterUnit()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttMeterSigDefaultLog::HasMeterCount( )
{
    return (m_meterCount != 0);
}

bool AttMeterSigDefaultLog::HasMeterUnit( )
{
    return (m_meterUnit != 0);
}


/* include <attmeter.unit> */

//----------------------------------------------------------------------------
// AttMeterSigDefaultVis
//----------------------------------------------------------------------------

AttMeterSigDefaultVis::AttMeterSigDefaultVis(): Att() {
    ResetMeterSigDefaultVis();
}

AttMeterSigDefaultVis::~AttMeterSigDefaultVis() {

}

void AttMeterSigDefaultVis::ResetMeterSigDefaultVis() {
    m_meterRend = "";
    m_meterShowchange = "";
    m_meterSym = METERSIGN_NONE;
}

bool AttMeterSigDefaultVis::ReadMeterSigDefaultVis(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("meter.rend")) {
        this->SetMeterRend(StrToStr(element.attribute("meter.rend").value()));
        element.remove_attribute("meter.rend");
        hasAttribute = true;
    }
    if (element.attribute("meter.showchange")) {
        this->SetMeterShowchange(StrToStr(element.attribute("meter.showchange").value()));
        element.remove_attribute("meter.showchange");
        hasAttribute = true;
    }
    if (element.attribute("meter.sym")) {
        this->SetMeterSym(StrToMeterSign(element.attribute("meter.sym").value()));
        element.remove_attribute("meter.sym");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttMeterSigDefaultVis::WriteMeterSigDefaultVis(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasMeterRend()) {
        element.append_attribute("meter.rend") = StrToStr(this->GetMeterRend()).c_str();
        wroteAttribute = true;
    }
    if (this->HasMeterShowchange()) {
        element.append_attribute("meter.showchange") = StrToStr(this->GetMeterShowchange()).c_str();
        wroteAttribute = true;
    }
    if (this->HasMeterSym()) {
        element.append_attribute("meter.sym") = MeterSignToStr(this->GetMeterSym()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttMeterSigDefaultVis::HasMeterRend( )
{
    return (m_meterRend != "");
}

bool AttMeterSigDefaultVis::HasMeterShowchange( )
{
    return (m_meterShowchange != "");
}

bool AttMeterSigDefaultVis::HasMeterSym( )
{
    return (m_meterSym != METERSIGN_NONE);
}


/* include <attmeter.sym> */

//----------------------------------------------------------------------------
// AttMeterconformance
//----------------------------------------------------------------------------

AttMeterconformance::AttMeterconformance(): Att() {
    ResetMeterconformance();
}

AttMeterconformance::~AttMeterconformance() {

}

void AttMeterconformance::ResetMeterconformance() {
    m_metcon = "";
}

bool AttMeterconformance::ReadMeterconformance(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("metcon")) {
        this->SetMetcon(StrToStr(element.attribute("metcon").value()));
        element.remove_attribute("metcon");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttMeterconformance::WriteMeterconformance(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasMetcon()) {
        element.append_attribute("metcon") = StrToStr(this->GetMetcon()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttMeterconformance::HasMetcon( )
{
    return (m_metcon != "");
}


/* include <attmetcon> */

//----------------------------------------------------------------------------
// AttMeterconformanceBar
//----------------------------------------------------------------------------

AttMeterconformanceBar::AttMeterconformanceBar(): Att() {
    ResetMeterconformanceBar();
}

AttMeterconformanceBar::~AttMeterconformanceBar() {

}

void AttMeterconformanceBar::ResetMeterconformanceBar() {
    m_metcon = "";
    m_control = "";
}

bool AttMeterconformanceBar::ReadMeterconformanceBar(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("metcon")) {
        this->SetMetcon(StrToStr(element.attribute("metcon").value()));
        element.remove_attribute("metcon");
        hasAttribute = true;
    }
    if (element.attribute("control")) {
        this->SetControl(StrToStr(element.attribute("control").value()));
        element.remove_attribute("control");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttMeterconformanceBar::WriteMeterconformanceBar(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasMetcon()) {
        element.append_attribute("metcon") = StrToStr(this->GetMetcon()).c_str();
        wroteAttribute = true;
    }
    if (this->HasControl()) {
        element.append_attribute("control") = StrToStr(this->GetControl()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttMeterconformanceBar::HasMetcon( )
{
    return (m_metcon != "");
}

bool AttMeterconformanceBar::HasControl( )
{
    return (m_control != "");
}


/* include <attcontrol> */

//----------------------------------------------------------------------------
// AttMmtempo
//----------------------------------------------------------------------------

AttMmtempo::AttMmtempo(): Att() {
    ResetMmtempo();
}

AttMmtempo::~AttMmtempo() {

}

void AttMmtempo::ResetMmtempo() {
    m_mm = "";
    m_mmUnit = "";
    m_mmDots = "";
}

bool AttMmtempo::ReadMmtempo(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("mm")) {
        this->SetMm(StrToStr(element.attribute("mm").value()));
        element.remove_attribute("mm");
        hasAttribute = true;
    }
    if (element.attribute("mm.unit")) {
        this->SetMmUnit(StrToStr(element.attribute("mm.unit").value()));
        element.remove_attribute("mm.unit");
        hasAttribute = true;
    }
    if (element.attribute("mm.dots")) {
        this->SetMmDots(StrToStr(element.attribute("mm.dots").value()));
        element.remove_attribute("mm.dots");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttMmtempo::WriteMmtempo(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasMm()) {
        element.append_attribute("mm") = StrToStr(this->GetMm()).c_str();
        wroteAttribute = true;
    }
    if (this->HasMmUnit()) {
        element.append_attribute("mm.unit") = StrToStr(this->GetMmUnit()).c_str();
        wroteAttribute = true;
    }
    if (this->HasMmDots()) {
        element.append_attribute("mm.dots") = StrToStr(this->GetMmDots()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttMmtempo::HasMm( )
{
    return (m_mm != "");
}

bool AttMmtempo::HasMmUnit( )
{
    return (m_mmUnit != "");
}

bool AttMmtempo::HasMmDots( )
{
    return (m_mmDots != "");
}


/* include <attmm.dots> */

//----------------------------------------------------------------------------
// AttMultinummeasures
//----------------------------------------------------------------------------

AttMultinummeasures::AttMultinummeasures(): Att() {
    ResetMultinummeasures();
}

AttMultinummeasures::~AttMultinummeasures() {

}

void AttMultinummeasures::ResetMultinummeasures() {
    m_multiNumber = BOOLEAN_NONE;
}

bool AttMultinummeasures::ReadMultinummeasures(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("multi.number")) {
        this->SetMultiNumber(StrToBool(element.attribute("multi.number").value()));
        element.remove_attribute("multi.number");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttMultinummeasures::WriteMultinummeasures(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasMultiNumber()) {
        element.append_attribute("multi.number") = BoolToStr(this->GetMultiNumber()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttMultinummeasures::HasMultiNumber( )
{
    return (m_multiNumber != BOOLEAN_NONE);
}


/* include <attmulti.number> */

//----------------------------------------------------------------------------
// AttName
//----------------------------------------------------------------------------

AttName::AttName(): Att() {
    ResetName();
}

AttName::~AttName() {

}

void AttName::ResetName() {
    m_nymref = "";
    m_role = "";
}

bool AttName::ReadName(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("nymref")) {
        this->SetNymref(StrToStr(element.attribute("nymref").value()));
        element.remove_attribute("nymref");
        hasAttribute = true;
    }
    if (element.attribute("role")) {
        this->SetRole(StrToStr(element.attribute("role").value()));
        element.remove_attribute("role");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttName::WriteName(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasNymref()) {
        element.append_attribute("nymref") = StrToStr(this->GetNymref()).c_str();
        wroteAttribute = true;
    }
    if (this->HasRole()) {
        element.append_attribute("role") = StrToStr(this->GetRole()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttName::HasNymref( )
{
    return (m_nymref != "");
}

bool AttName::HasRole( )
{
    return (m_role != "");
}


/* include <attrole> */

//----------------------------------------------------------------------------
// AttNotationstyle
//----------------------------------------------------------------------------

AttNotationstyle::AttNotationstyle(): Att() {
    ResetNotationstyle();
}

AttNotationstyle::~AttNotationstyle() {

}

void AttNotationstyle::ResetNotationstyle() {
    m_musicName = "";
    m_musicSize = "";
}

bool AttNotationstyle::ReadNotationstyle(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("music.name")) {
        this->SetMusicName(StrToStr(element.attribute("music.name").value()));
        element.remove_attribute("music.name");
        hasAttribute = true;
    }
    if (element.attribute("music.size")) {
        this->SetMusicSize(StrToStr(element.attribute("music.size").value()));
        element.remove_attribute("music.size");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttNotationstyle::WriteNotationstyle(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasMusicName()) {
        element.append_attribute("music.name") = StrToStr(this->GetMusicName()).c_str();
        wroteAttribute = true;
    }
    if (this->HasMusicSize()) {
        element.append_attribute("music.size") = StrToStr(this->GetMusicSize()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttNotationstyle::HasMusicName( )
{
    return (m_musicName != "");
}

bool AttNotationstyle::HasMusicSize( )
{
    return (m_musicSize != "");
}


/* include <attmusic.size> */

//----------------------------------------------------------------------------
// AttNoteGes
//----------------------------------------------------------------------------

AttNoteGes::AttNoteGes(): Att() {
    ResetNoteGes();
}

AttNoteGes::~AttNoteGes() {

}

void AttNoteGes::ResetNoteGes() {
    m_octGes = "";
    m_pnameGes = "";
    m_pnum = "";
}

bool AttNoteGes::ReadNoteGes(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("oct.ges")) {
        this->SetOctGes(StrToStr(element.attribute("oct.ges").value()));
        element.remove_attribute("oct.ges");
        hasAttribute = true;
    }
    if (element.attribute("pname.ges")) {
        this->SetPnameGes(StrToStr(element.attribute("pname.ges").value()));
        element.remove_attribute("pname.ges");
        hasAttribute = true;
    }
    if (element.attribute("pnum")) {
        this->SetPnum(StrToStr(element.attribute("pnum").value()));
        element.remove_attribute("pnum");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttNoteGes::WriteNoteGes(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasOctGes()) {
        element.append_attribute("oct.ges") = StrToStr(this->GetOctGes()).c_str();
        wroteAttribute = true;
    }
    if (this->HasPnameGes()) {
        element.append_attribute("pname.ges") = StrToStr(this->GetPnameGes()).c_str();
        wroteAttribute = true;
    }
    if (this->HasPnum()) {
        element.append_attribute("pnum") = StrToStr(this->GetPnum()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttNoteGes::HasOctGes( )
{
    return (m_octGes != "");
}

bool AttNoteGes::HasPnameGes( )
{
    return (m_pnameGes != "");
}

bool AttNoteGes::HasPnum( )
{
    return (m_pnum != "");
}


/* include <attpnum> */

//----------------------------------------------------------------------------
// AttNoteheads
//----------------------------------------------------------------------------

AttNoteheads::AttNoteheads(): Att() {
    ResetNoteheads();
}

AttNoteheads::~AttNoteheads() {

}

void AttNoteheads::ResetNoteheads() {
    m_headColor = "";
    m_headFill = "";
    m_headFillcolor = "";
    m_headMod = "";
    m_headRotation = "";
    m_headShape = "";
    m_headVisible = "";
}

bool AttNoteheads::ReadNoteheads(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("head.color")) {
        this->SetHeadColor(StrToStr(element.attribute("head.color").value()));
        element.remove_attribute("head.color");
        hasAttribute = true;
    }
    if (element.attribute("head.fill")) {
        this->SetHeadFill(StrToStr(element.attribute("head.fill").value()));
        element.remove_attribute("head.fill");
        hasAttribute = true;
    }
    if (element.attribute("head.fillcolor")) {
        this->SetHeadFillcolor(StrToStr(element.attribute("head.fillcolor").value()));
        element.remove_attribute("head.fillcolor");
        hasAttribute = true;
    }
    if (element.attribute("head.mod")) {
        this->SetHeadMod(StrToStr(element.attribute("head.mod").value()));
        element.remove_attribute("head.mod");
        hasAttribute = true;
    }
    if (element.attribute("head.rotation")) {
        this->SetHeadRotation(StrToStr(element.attribute("head.rotation").value()));
        element.remove_attribute("head.rotation");
        hasAttribute = true;
    }
    if (element.attribute("head.shape")) {
        this->SetHeadShape(StrToStr(element.attribute("head.shape").value()));
        element.remove_attribute("head.shape");
        hasAttribute = true;
    }
    if (element.attribute("head.visible")) {
        this->SetHeadVisible(StrToStr(element.attribute("head.visible").value()));
        element.remove_attribute("head.visible");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttNoteheads::WriteNoteheads(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasHeadColor()) {
        element.append_attribute("head.color") = StrToStr(this->GetHeadColor()).c_str();
        wroteAttribute = true;
    }
    if (this->HasHeadFill()) {
        element.append_attribute("head.fill") = StrToStr(this->GetHeadFill()).c_str();
        wroteAttribute = true;
    }
    if (this->HasHeadFillcolor()) {
        element.append_attribute("head.fillcolor") = StrToStr(this->GetHeadFillcolor()).c_str();
        wroteAttribute = true;
    }
    if (this->HasHeadMod()) {
        element.append_attribute("head.mod") = StrToStr(this->GetHeadMod()).c_str();
        wroteAttribute = true;
    }
    if (this->HasHeadRotation()) {
        element.append_attribute("head.rotation") = StrToStr(this->GetHeadRotation()).c_str();
        wroteAttribute = true;
    }
    if (this->HasHeadShape()) {
        element.append_attribute("head.shape") = StrToStr(this->GetHeadShape()).c_str();
        wroteAttribute = true;
    }
    if (this->HasHeadVisible()) {
        element.append_attribute("head.visible") = StrToStr(this->GetHeadVisible()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttNoteheads::HasHeadColor( )
{
    return (m_headColor != "");
}

bool AttNoteheads::HasHeadFill( )
{
    return (m_headFill != "");
}

bool AttNoteheads::HasHeadFillcolor( )
{
    return (m_headFillcolor != "");
}

bool AttNoteheads::HasHeadMod( )
{
    return (m_headMod != "");
}

bool AttNoteheads::HasHeadRotation( )
{
    return (m_headRotation != "");
}

bool AttNoteheads::HasHeadShape( )
{
    return (m_headShape != "");
}

bool AttNoteheads::HasHeadVisible( )
{
    return (m_headVisible != "");
}


/* include <atthead.visible> */

//----------------------------------------------------------------------------
// AttOctave
//----------------------------------------------------------------------------

AttOctave::AttOctave(): Att() {
    ResetOctave();
}

AttOctave::~AttOctave() {

}

void AttOctave::ResetOctave() {
    m_oct = 0;
}

bool AttOctave::ReadOctave(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("oct")) {
        this->SetOct(StrToInt(element.attribute("oct").value()));
        element.remove_attribute("oct");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttOctave::WriteOctave(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasOct()) {
        element.append_attribute("oct") = IntToStr(this->GetOct()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttOctave::HasOct( )
{
    return (m_oct != 0);
}


/* include <attoct> */

//----------------------------------------------------------------------------
// AttOctavedefault
//----------------------------------------------------------------------------

AttOctavedefault::AttOctavedefault(): Att() {
    ResetOctavedefault();
}

AttOctavedefault::~AttOctavedefault() {

}

void AttOctavedefault::ResetOctavedefault() {
    m_octaveDefault = "";
}

bool AttOctavedefault::ReadOctavedefault(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("octave.default")) {
        this->SetOctaveDefault(StrToStr(element.attribute("octave.default").value()));
        element.remove_attribute("octave.default");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttOctavedefault::WriteOctavedefault(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasOctaveDefault()) {
        element.append_attribute("octave.default") = StrToStr(this->GetOctaveDefault()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttOctavedefault::HasOctaveDefault( )
{
    return (m_octaveDefault != "");
}


/* include <attoctave.default> */

//----------------------------------------------------------------------------
// AttOctavedisplacement
//----------------------------------------------------------------------------

AttOctavedisplacement::AttOctavedisplacement(): Att() {
    ResetOctavedisplacement();
}

AttOctavedisplacement::~AttOctavedisplacement() {

}

void AttOctavedisplacement::ResetOctavedisplacement() {
    m_dis = OCTAVE_DIS_NONE;
    m_disPlace = PLACE_NONE;
}

bool AttOctavedisplacement::ReadOctavedisplacement(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("dis")) {
        this->SetDis(StrToOctaveDis(element.attribute("dis").value()));
        element.remove_attribute("dis");
        hasAttribute = true;
    }
    if (element.attribute("dis.place")) {
        this->SetDisPlace(StrToPlace(element.attribute("dis.place").value()));
        element.remove_attribute("dis.place");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttOctavedisplacement::WriteOctavedisplacement(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasDis()) {
        element.append_attribute("dis") = OctaveDisToStr(this->GetDis()).c_str();
        wroteAttribute = true;
    }
    if (this->HasDisPlace()) {
        element.append_attribute("dis.place") = PlaceToStr(this->GetDisPlace()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttOctavedisplacement::HasDis( )
{
    return (m_dis != OCTAVE_DIS_NONE);
}

bool AttOctavedisplacement::HasDisPlace( )
{
    return (m_disPlace != PLACE_NONE);
}


/* include <attdis.place> */

//----------------------------------------------------------------------------
// AttOnelinestaff
//----------------------------------------------------------------------------

AttOnelinestaff::AttOnelinestaff(): Att() {
    ResetOnelinestaff();
}

AttOnelinestaff::~AttOnelinestaff() {

}

void AttOnelinestaff::ResetOnelinestaff() {
    m_ontheline = "";
}

bool AttOnelinestaff::ReadOnelinestaff(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("ontheline")) {
        this->SetOntheline(StrToStr(element.attribute("ontheline").value()));
        element.remove_attribute("ontheline");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttOnelinestaff::WriteOnelinestaff(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasOntheline()) {
        element.append_attribute("ontheline") = StrToStr(this->GetOntheline()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttOnelinestaff::HasOntheline( )
{
    return (m_ontheline != "");
}


/* include <attontheline> */

//----------------------------------------------------------------------------
// AttOptimization
//----------------------------------------------------------------------------

AttOptimization::AttOptimization(): Att() {
    ResetOptimization();
}

AttOptimization::~AttOptimization() {

}

void AttOptimization::ResetOptimization() {
    m_optimize = "";
}

bool AttOptimization::ReadOptimization(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("optimize")) {
        this->SetOptimize(StrToStr(element.attribute("optimize").value()));
        element.remove_attribute("optimize");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttOptimization::WriteOptimization(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasOptimize()) {
        element.append_attribute("optimize") = StrToStr(this->GetOptimize()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttOptimization::HasOptimize( )
{
    return (m_optimize != "");
}


/* include <attoptimize> */

//----------------------------------------------------------------------------
// AttPadLog
//----------------------------------------------------------------------------

AttPadLog::AttPadLog(): Att() {
    ResetPadLog();
}

AttPadLog::~AttPadLog() {

}

void AttPadLog::ResetPadLog() {
    m_num = -1;
}

bool AttPadLog::ReadPadLog(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("num")) {
        this->SetNum(StrToInt(element.attribute("num").value()));
        element.remove_attribute("num");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttPadLog::WritePadLog(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasNum()) {
        element.append_attribute("num") = IntToStr(this->GetNum()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttPadLog::HasNum( )
{
    return (m_num != -1);
}


/* include <attnum> */

//----------------------------------------------------------------------------
// AttPages
//----------------------------------------------------------------------------

AttPages::AttPages(): Att() {
    ResetPages();
}

AttPages::~AttPages() {

}

void AttPages::ResetPages() {
    m_pageHeight = "";
    m_pageWidth = "";
    m_pageTopmar = "";
    m_pageBotmar = "";
    m_pageLeftmar = "";
    m_pageRightmar = "";
    m_pagePanels = "";
    m_pageScale = "";
}

bool AttPages::ReadPages(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("page.height")) {
        this->SetPageHeight(StrToStr(element.attribute("page.height").value()));
        element.remove_attribute("page.height");
        hasAttribute = true;
    }
    if (element.attribute("page.width")) {
        this->SetPageWidth(StrToStr(element.attribute("page.width").value()));
        element.remove_attribute("page.width");
        hasAttribute = true;
    }
    if (element.attribute("page.topmar")) {
        this->SetPageTopmar(StrToStr(element.attribute("page.topmar").value()));
        element.remove_attribute("page.topmar");
        hasAttribute = true;
    }
    if (element.attribute("page.botmar")) {
        this->SetPageBotmar(StrToStr(element.attribute("page.botmar").value()));
        element.remove_attribute("page.botmar");
        hasAttribute = true;
    }
    if (element.attribute("page.leftmar")) {
        this->SetPageLeftmar(StrToStr(element.attribute("page.leftmar").value()));
        element.remove_attribute("page.leftmar");
        hasAttribute = true;
    }
    if (element.attribute("page.rightmar")) {
        this->SetPageRightmar(StrToStr(element.attribute("page.rightmar").value()));
        element.remove_attribute("page.rightmar");
        hasAttribute = true;
    }
    if (element.attribute("page.panels")) {
        this->SetPagePanels(StrToStr(element.attribute("page.panels").value()));
        element.remove_attribute("page.panels");
        hasAttribute = true;
    }
    if (element.attribute("page.scale")) {
        this->SetPageScale(StrToStr(element.attribute("page.scale").value()));
        element.remove_attribute("page.scale");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttPages::WritePages(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasPageHeight()) {
        element.append_attribute("page.height") = StrToStr(this->GetPageHeight()).c_str();
        wroteAttribute = true;
    }
    if (this->HasPageWidth()) {
        element.append_attribute("page.width") = StrToStr(this->GetPageWidth()).c_str();
        wroteAttribute = true;
    }
    if (this->HasPageTopmar()) {
        element.append_attribute("page.topmar") = StrToStr(this->GetPageTopmar()).c_str();
        wroteAttribute = true;
    }
    if (this->HasPageBotmar()) {
        element.append_attribute("page.botmar") = StrToStr(this->GetPageBotmar()).c_str();
        wroteAttribute = true;
    }
    if (this->HasPageLeftmar()) {
        element.append_attribute("page.leftmar") = StrToStr(this->GetPageLeftmar()).c_str();
        wroteAttribute = true;
    }
    if (this->HasPageRightmar()) {
        element.append_attribute("page.rightmar") = StrToStr(this->GetPageRightmar()).c_str();
        wroteAttribute = true;
    }
    if (this->HasPagePanels()) {
        element.append_attribute("page.panels") = StrToStr(this->GetPagePanels()).c_str();
        wroteAttribute = true;
    }
    if (this->HasPageScale()) {
        element.append_attribute("page.scale") = StrToStr(this->GetPageScale()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttPages::HasPageHeight( )
{
    return (m_pageHeight != "");
}

bool AttPages::HasPageWidth( )
{
    return (m_pageWidth != "");
}

bool AttPages::HasPageTopmar( )
{
    return (m_pageTopmar != "");
}

bool AttPages::HasPageBotmar( )
{
    return (m_pageBotmar != "");
}

bool AttPages::HasPageLeftmar( )
{
    return (m_pageLeftmar != "");
}

bool AttPages::HasPageRightmar( )
{
    return (m_pageRightmar != "");
}

bool AttPages::HasPagePanels( )
{
    return (m_pagePanels != "");
}

bool AttPages::HasPageScale( )
{
    return (m_pageScale != "");
}


/* include <attpage.scale> */

//----------------------------------------------------------------------------
// AttPbVis
//----------------------------------------------------------------------------

AttPbVis::AttPbVis(): Att() {
    ResetPbVis();
}

AttPbVis::~AttPbVis() {

}

void AttPbVis::ResetPbVis() {
    m_folium = "";
}

bool AttPbVis::ReadPbVis(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("folium")) {
        this->SetFolium(StrToStr(element.attribute("folium").value()));
        element.remove_attribute("folium");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttPbVis::WritePbVis(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasFolium()) {
        element.append_attribute("folium") = StrToStr(this->GetFolium()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttPbVis::HasFolium( )
{
    return (m_folium != "");
}


/* include <attfolium> */

//----------------------------------------------------------------------------
// AttPitch
//----------------------------------------------------------------------------

AttPitch::AttPitch(): Att() {
    ResetPitch();
}

AttPitch::~AttPitch() {

}

void AttPitch::ResetPitch() {
    m_pname = PITCHNAME_NONE;
}

bool AttPitch::ReadPitch(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("pname")) {
        this->SetPname(StrToPitchName(element.attribute("pname").value()));
        element.remove_attribute("pname");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttPitch::WritePitch(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasPname()) {
        element.append_attribute("pname") = PitchNameToStr(this->GetPname()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttPitch::HasPname( )
{
    return (m_pname != PITCHNAME_NONE);
}


/* include <attpname> */

//----------------------------------------------------------------------------
// AttPlacement
//----------------------------------------------------------------------------

AttPlacement::AttPlacement(): Att() {
    ResetPlacement();
}

AttPlacement::~AttPlacement() {

}

void AttPlacement::ResetPlacement() {
    m_place = STAFFREL_NONE;
}

bool AttPlacement::ReadPlacement(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("place")) {
        this->SetPlace(StrToStaffRel(element.attribute("place").value()));
        element.remove_attribute("place");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttPlacement::WritePlacement(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasPlace()) {
        element.append_attribute("place") = StaffRelToStr(this->GetPlace()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttPlacement::HasPlace( )
{
    return (m_place != STAFFREL_NONE);
}


/* include <attplace> */

//----------------------------------------------------------------------------
// AttPlist
//----------------------------------------------------------------------------

AttPlist::AttPlist(): Att() {
    ResetPlist();
}

AttPlist::~AttPlist() {

}

void AttPlist::ResetPlist() {
    m_plist = "";
    m_evaluate = "";
}

bool AttPlist::ReadPlist(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("plist")) {
        this->SetPlist(StrToStr(element.attribute("plist").value()));
        element.remove_attribute("plist");
        hasAttribute = true;
    }
    if (element.attribute("evaluate")) {
        this->SetEvaluate(StrToStr(element.attribute("evaluate").value()));
        element.remove_attribute("evaluate");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttPlist::WritePlist(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasPlist()) {
        element.append_attribute("plist") = StrToStr(this->GetPlist()).c_str();
        wroteAttribute = true;
    }
    if (this->HasEvaluate()) {
        element.append_attribute("evaluate") = StrToStr(this->GetEvaluate()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttPlist::HasPlist( )
{
    return (m_plist != "");
}

bool AttPlist::HasEvaluate( )
{
    return (m_evaluate != "");
}


/* include <attevaluate> */

//----------------------------------------------------------------------------
// AttPointing
//----------------------------------------------------------------------------

AttPointing::AttPointing(): Att() {
    ResetPointing();
}

AttPointing::~AttPointing() {

}

void AttPointing::ResetPointing() {
    m_actuate = "";
    m_role = "";
    m_show = "";
    m_target = "";
    m_targettype = "";
    m_title = "";
}

bool AttPointing::ReadPointing(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("actuate")) {
        this->SetActuate(StrToStr(element.attribute("actuate").value()));
        element.remove_attribute("actuate");
        hasAttribute = true;
    }
    if (element.attribute("role")) {
        this->SetRole(StrToStr(element.attribute("role").value()));
        element.remove_attribute("role");
        hasAttribute = true;
    }
    if (element.attribute("show")) {
        this->SetShow(StrToStr(element.attribute("show").value()));
        element.remove_attribute("show");
        hasAttribute = true;
    }
    if (element.attribute("target")) {
        this->SetTarget(StrToStr(element.attribute("target").value()));
        element.remove_attribute("target");
        hasAttribute = true;
    }
    if (element.attribute("targettype")) {
        this->SetTargettype(StrToStr(element.attribute("targettype").value()));
        element.remove_attribute("targettype");
        hasAttribute = true;
    }
    if (element.attribute("title")) {
        this->SetTitle(StrToStr(element.attribute("title").value()));
        element.remove_attribute("title");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttPointing::WritePointing(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasActuate()) {
        element.append_attribute("actuate") = StrToStr(this->GetActuate()).c_str();
        wroteAttribute = true;
    }
    if (this->HasRole()) {
        element.append_attribute("role") = StrToStr(this->GetRole()).c_str();
        wroteAttribute = true;
    }
    if (this->HasShow()) {
        element.append_attribute("show") = StrToStr(this->GetShow()).c_str();
        wroteAttribute = true;
    }
    if (this->HasTarget()) {
        element.append_attribute("target") = StrToStr(this->GetTarget()).c_str();
        wroteAttribute = true;
    }
    if (this->HasTargettype()) {
        element.append_attribute("targettype") = StrToStr(this->GetTargettype()).c_str();
        wroteAttribute = true;
    }
    if (this->HasTitle()) {
        element.append_attribute("title") = StrToStr(this->GetTitle()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttPointing::HasActuate( )
{
    return (m_actuate != "");
}

bool AttPointing::HasRole( )
{
    return (m_role != "");
}

bool AttPointing::HasShow( )
{
    return (m_show != "");
}

bool AttPointing::HasTarget( )
{
    return (m_target != "");
}

bool AttPointing::HasTargettype( )
{
    return (m_targettype != "");
}

bool AttPointing::HasTitle( )
{
    return (m_title != "");
}


/* include <atttitle> */

//----------------------------------------------------------------------------
// AttQuantity
//----------------------------------------------------------------------------

AttQuantity::AttQuantity(): Att() {
    ResetQuantity();
}

AttQuantity::~AttQuantity() {

}

void AttQuantity::ResetQuantity() {
    m_quantityDbl = 0.0;
}

bool AttQuantity::ReadQuantity(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("quantity")) {
        this->SetQuantity(StrToDbl(element.attribute("quantity").value()));
        element.remove_attribute("quantity");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttQuantity::WriteQuantity(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasQuantity()) {
        element.append_attribute("quantity") = DblToStr(this->GetQuantity()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttQuantity::HasQuantity( )
{
    return (m_quantityDbl != 0.0);
}


/* include <attquantity> */

//----------------------------------------------------------------------------
// AttRelativesize
//----------------------------------------------------------------------------

AttRelativesize::AttRelativesize(): Att() {
    ResetRelativesize();
}

AttRelativesize::~AttRelativesize() {

}

void AttRelativesize::ResetRelativesize() {
    m_size = "";
}

bool AttRelativesize::ReadRelativesize(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("size")) {
        this->SetSize(StrToStr(element.attribute("size").value()));
        element.remove_attribute("size");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttRelativesize::WriteRelativesize(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasSize()) {
        element.append_attribute("size") = StrToStr(this->GetSize()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttRelativesize::HasSize( )
{
    return (m_size != "");
}


/* include <attsize> */

//----------------------------------------------------------------------------
// AttResponsibility
//----------------------------------------------------------------------------

AttResponsibility::AttResponsibility(): Att() {
    ResetResponsibility();
}

AttResponsibility::~AttResponsibility() {

}

void AttResponsibility::ResetResponsibility() {
    m_resp = "";
}

bool AttResponsibility::ReadResponsibility(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("resp")) {
        this->SetResp(StrToStr(element.attribute("resp").value()));
        element.remove_attribute("resp");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttResponsibility::WriteResponsibility(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasResp()) {
        element.append_attribute("resp") = StrToStr(this->GetResp()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttResponsibility::HasResp( )
{
    return (m_resp != "");
}


/* include <attresp> */

//----------------------------------------------------------------------------
// AttSbVis
//----------------------------------------------------------------------------

AttSbVis::AttSbVis(): Att() {
    ResetSbVis();
}

AttSbVis::~AttSbVis() {

}

void AttSbVis::ResetSbVis() {
    m_form = BARRENDITION_single;
}

bool AttSbVis::ReadSbVis(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("form")) {
        this->SetForm(StrToBarRendition(element.attribute("form").value()));
        element.remove_attribute("form");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttSbVis::WriteSbVis(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasForm()) {
        element.append_attribute("form") = BarRenditionToStr(this->GetForm()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttSbVis::HasForm( )
{
    return (m_form != BARRENDITION_single);
}


/* include <attform> */

//----------------------------------------------------------------------------
// AttScalable
//----------------------------------------------------------------------------

AttScalable::AttScalable(): Att() {
    ResetScalable();
}

AttScalable::~AttScalable() {

}

void AttScalable::ResetScalable() {
    m_scale = 0;
}

bool AttScalable::ReadScalable(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("scale")) {
        this->SetScale(StrToPercent(element.attribute("scale").value()));
        element.remove_attribute("scale");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttScalable::WriteScalable(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasScale()) {
        element.append_attribute("scale") = PercentToStr(this->GetScale()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttScalable::HasScale( )
{
    return (m_scale != 0);
}


/* include <attscale> */

//----------------------------------------------------------------------------
// AttScoreDefGes
//----------------------------------------------------------------------------

AttScoreDefGes::AttScoreDefGes(): Att() {
    ResetScoreDefGes();
}

AttScoreDefGes::~AttScoreDefGes() {

}

void AttScoreDefGes::ResetScoreDefGes() {
    m_tunePname = "";
    m_tuneHzDbl = 0.0;
    m_tuneTemper = "";
}

bool AttScoreDefGes::ReadScoreDefGes(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("tune.pname")) {
        this->SetTunePname(StrToStr(element.attribute("tune.pname").value()));
        element.remove_attribute("tune.pname");
        hasAttribute = true;
    }
    if (element.attribute("tune.Hz")) {
        this->SetTuneHz(StrToDbl(element.attribute("tune.Hz").value()));
        element.remove_attribute("tune.Hz");
        hasAttribute = true;
    }
    if (element.attribute("tune.temper")) {
        this->SetTuneTemper(StrToStr(element.attribute("tune.temper").value()));
        element.remove_attribute("tune.temper");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttScoreDefGes::WriteScoreDefGes(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasTunePname()) {
        element.append_attribute("tune.pname") = StrToStr(this->GetTunePname()).c_str();
        wroteAttribute = true;
    }
    if (this->HasTuneHz()) {
        element.append_attribute("tune.Hz") = DblToStr(this->GetTuneHz()).c_str();
        wroteAttribute = true;
    }
    if (this->HasTuneTemper()) {
        element.append_attribute("tune.temper") = StrToStr(this->GetTuneTemper()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttScoreDefGes::HasTunePname( )
{
    return (m_tunePname != "");
}

bool AttScoreDefGes::HasTuneHz( )
{
    return (m_tuneHzDbl != 0.0);
}

bool AttScoreDefGes::HasTuneTemper( )
{
    return (m_tuneTemper != "");
}


/* include <atttune.temper> */

//----------------------------------------------------------------------------
// AttScoreDefVis
//----------------------------------------------------------------------------

AttScoreDefVis::AttScoreDefVis(): Att() {
    ResetScoreDefVis();
}

AttScoreDefVis::~AttScoreDefVis() {

}

void AttScoreDefVis::ResetScoreDefVis() {
    m_vuHeight = "";
}

bool AttScoreDefVis::ReadScoreDefVis(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("vu.height")) {
        this->SetVuHeight(StrToStr(element.attribute("vu.height").value()));
        element.remove_attribute("vu.height");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttScoreDefVis::WriteScoreDefVis(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasVuHeight()) {
        element.append_attribute("vu.height") = StrToStr(this->GetVuHeight()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttScoreDefVis::HasVuHeight( )
{
    return (m_vuHeight != "");
}


/* include <attvu.height> */

//----------------------------------------------------------------------------
// AttSectionVis
//----------------------------------------------------------------------------

AttSectionVis::AttSectionVis(): Att() {
    ResetSectionVis();
}

AttSectionVis::~AttSectionVis() {

}

void AttSectionVis::ResetSectionVis() {
    m_restart = "";
}

bool AttSectionVis::ReadSectionVis(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("restart")) {
        this->SetRestart(StrToStr(element.attribute("restart").value()));
        element.remove_attribute("restart");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttSectionVis::WriteSectionVis(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasRestart()) {
        element.append_attribute("restart") = StrToStr(this->GetRestart()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttSectionVis::HasRestart( )
{
    return (m_restart != "");
}


/* include <attrestart> */

//----------------------------------------------------------------------------
// AttSequence
//----------------------------------------------------------------------------

AttSequence::AttSequence(): Att() {
    ResetSequence();
}

AttSequence::~AttSequence() {

}

void AttSequence::ResetSequence() {
    m_seqInt = 0;
}

bool AttSequence::ReadSequence(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("seq")) {
        this->SetSeq(StrToInt(element.attribute("seq").value()));
        element.remove_attribute("seq");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttSequence::WriteSequence(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasSeq()) {
        element.append_attribute("seq") = IntToStr(this->GetSeq()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttSequence::HasSeq( )
{
    return (m_seqInt != 0);
}


/* include <attseq> */

//----------------------------------------------------------------------------
// AttSlashcount
//----------------------------------------------------------------------------

AttSlashcount::AttSlashcount(): Att() {
    ResetSlashcount();
}

AttSlashcount::~AttSlashcount() {

}

void AttSlashcount::ResetSlashcount() {
    m_slash = 0;
}

bool AttSlashcount::ReadSlashcount(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("slash")) {
        this->SetSlash(StrToInt(element.attribute("slash").value()));
        element.remove_attribute("slash");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttSlashcount::WriteSlashcount(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasSlash()) {
        element.append_attribute("slash") = IntToStr(this->GetSlash()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttSlashcount::HasSlash( )
{
    return (m_slash != 0);
}


/* include <attslash> */

//----------------------------------------------------------------------------
// AttSlurpresent
//----------------------------------------------------------------------------

AttSlurpresent::AttSlurpresent(): Att() {
    ResetSlurpresent();
}

AttSlurpresent::~AttSlurpresent() {

}

void AttSlurpresent::ResetSlurpresent() {
    m_slur = "";
}

bool AttSlurpresent::ReadSlurpresent(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("slur")) {
        this->SetSlur(StrToStr(element.attribute("slur").value()));
        element.remove_attribute("slur");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttSlurpresent::WriteSlurpresent(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasSlur()) {
        element.append_attribute("slur") = StrToStr(this->GetSlur()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttSlurpresent::HasSlur( )
{
    return (m_slur != "");
}


/* include <attslur> */

//----------------------------------------------------------------------------
// AttSpaceVis
//----------------------------------------------------------------------------

AttSpaceVis::AttSpaceVis(): Att() {
    ResetSpaceVis();
}

AttSpaceVis::~AttSpaceVis() {

}

void AttSpaceVis::ResetSpaceVis() {
    m_compressable = "";
}

bool AttSpaceVis::ReadSpaceVis(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("compressable")) {
        this->SetCompressable(StrToStr(element.attribute("compressable").value()));
        element.remove_attribute("compressable");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttSpaceVis::WriteSpaceVis(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasCompressable()) {
        element.append_attribute("compressable") = StrToStr(this->GetCompressable()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttSpaceVis::HasCompressable( )
{
    return (m_compressable != "");
}


/* include <attcompressable> */

//----------------------------------------------------------------------------
// AttSpacing
//----------------------------------------------------------------------------

AttSpacing::AttSpacing(): Att() {
    ResetSpacing();
}

AttSpacing::~AttSpacing() {

}

void AttSpacing::ResetSpacing() {
    m_spacingPackexpDbl = 0.0;
    m_spacingPackfactDbl = 0.0;
    m_spacingStaff = "";
    m_spacingSystem = "";
}

bool AttSpacing::ReadSpacing(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("spacing.packexp")) {
        this->SetSpacingPackexp(StrToDbl(element.attribute("spacing.packexp").value()));
        element.remove_attribute("spacing.packexp");
        hasAttribute = true;
    }
    if (element.attribute("spacing.packfact")) {
        this->SetSpacingPackfact(StrToDbl(element.attribute("spacing.packfact").value()));
        element.remove_attribute("spacing.packfact");
        hasAttribute = true;
    }
    if (element.attribute("spacing.staff")) {
        this->SetSpacingStaff(StrToStr(element.attribute("spacing.staff").value()));
        element.remove_attribute("spacing.staff");
        hasAttribute = true;
    }
    if (element.attribute("spacing.system")) {
        this->SetSpacingSystem(StrToStr(element.attribute("spacing.system").value()));
        element.remove_attribute("spacing.system");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttSpacing::WriteSpacing(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasSpacingPackexp()) {
        element.append_attribute("spacing.packexp") = DblToStr(this->GetSpacingPackexp()).c_str();
        wroteAttribute = true;
    }
    if (this->HasSpacingPackfact()) {
        element.append_attribute("spacing.packfact") = DblToStr(this->GetSpacingPackfact()).c_str();
        wroteAttribute = true;
    }
    if (this->HasSpacingStaff()) {
        element.append_attribute("spacing.staff") = StrToStr(this->GetSpacingStaff()).c_str();
        wroteAttribute = true;
    }
    if (this->HasSpacingSystem()) {
        element.append_attribute("spacing.system") = StrToStr(this->GetSpacingSystem()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttSpacing::HasSpacingPackexp( )
{
    return (m_spacingPackexpDbl != 0.0);
}

bool AttSpacing::HasSpacingPackfact( )
{
    return (m_spacingPackfactDbl != 0.0);
}

bool AttSpacing::HasSpacingStaff( )
{
    return (m_spacingStaff != "");
}

bool AttSpacing::HasSpacingSystem( )
{
    return (m_spacingSystem != "");
}


/* include <attspacing.system> */

//----------------------------------------------------------------------------
// AttStaffLog
//----------------------------------------------------------------------------

AttStaffLog::AttStaffLog(): Att() {
    ResetStaffLog();
}

AttStaffLog::~AttStaffLog() {

}

void AttStaffLog::ResetStaffLog() {
    m_def = "";
}

bool AttStaffLog::ReadStaffLog(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("def")) {
        this->SetDef(StrToStr(element.attribute("def").value()));
        element.remove_attribute("def");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttStaffLog::WriteStaffLog(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasDef()) {
        element.append_attribute("def") = StrToStr(this->GetDef()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttStaffLog::HasDef( )
{
    return (m_def != "");
}


/* include <attdef> */

//----------------------------------------------------------------------------
// AttStaffDefVis
//----------------------------------------------------------------------------

AttStaffDefVis::AttStaffDefVis(): Att() {
    ResetStaffDefVis();
}

AttStaffDefVis::~AttStaffDefVis() {

}

void AttStaffDefVis::ResetStaffDefVis() {
    m_gridShow = BOOLEAN_NONE;
    m_layerscheme = LAYERSCHEME_NONE;
    m_linesInt = 0;
    m_linesColor = "";
    m_linesVisible = BOOLEAN_NONE;
    m_spacing = "";
}

bool AttStaffDefVis::ReadStaffDefVis(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("grid.show")) {
        this->SetGridShow(StrToBool(element.attribute("grid.show").value()));
        element.remove_attribute("grid.show");
        hasAttribute = true;
    }
    if (element.attribute("layerscheme")) {
        this->SetLayerscheme(StrToLayerscheme(element.attribute("layerscheme").value()));
        element.remove_attribute("layerscheme");
        hasAttribute = true;
    }
    if (element.attribute("lines")) {
        this->SetLines(StrToInt(element.attribute("lines").value()));
        element.remove_attribute("lines");
        hasAttribute = true;
    }
    if (element.attribute("lines.color")) {
        this->SetLinesColor(StrToStr(element.attribute("lines.color").value()));
        element.remove_attribute("lines.color");
        hasAttribute = true;
    }
    if (element.attribute("lines.visible")) {
        this->SetLinesVisible(StrToBool(element.attribute("lines.visible").value()));
        element.remove_attribute("lines.visible");
        hasAttribute = true;
    }
    if (element.attribute("spacing")) {
        this->SetSpacing(StrToStr(element.attribute("spacing").value()));
        element.remove_attribute("spacing");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttStaffDefVis::WriteStaffDefVis(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasGridShow()) {
        element.append_attribute("grid.show") = BoolToStr(this->GetGridShow()).c_str();
        wroteAttribute = true;
    }
    if (this->HasLayerscheme()) {
        element.append_attribute("layerscheme") = LayerschemeToStr(this->GetLayerscheme()).c_str();
        wroteAttribute = true;
    }
    if (this->HasLines()) {
        element.append_attribute("lines") = IntToStr(this->GetLines()).c_str();
        wroteAttribute = true;
    }
    if (this->HasLinesColor()) {
        element.append_attribute("lines.color") = StrToStr(this->GetLinesColor()).c_str();
        wroteAttribute = true;
    }
    if (this->HasLinesVisible()) {
        element.append_attribute("lines.visible") = BoolToStr(this->GetLinesVisible()).c_str();
        wroteAttribute = true;
    }
    if (this->HasSpacing()) {
        element.append_attribute("spacing") = StrToStr(this->GetSpacing()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttStaffDefVis::HasGridShow( )
{
    return (m_gridShow != BOOLEAN_NONE);
}

bool AttStaffDefVis::HasLayerscheme( )
{
    return (m_layerscheme != LAYERSCHEME_NONE);
}

bool AttStaffDefVis::HasLines( )
{
    return (m_linesInt != 0);
}

bool AttStaffDefVis::HasLinesColor( )
{
    return (m_linesColor != "");
}

bool AttStaffDefVis::HasLinesVisible( )
{
    return (m_linesVisible != BOOLEAN_NONE);
}

bool AttStaffDefVis::HasSpacing( )
{
    return (m_spacing != "");
}


/* include <attspacing> */

//----------------------------------------------------------------------------
// AttStaffGrpVis
//----------------------------------------------------------------------------

AttStaffGrpVis::AttStaffGrpVis(): Att() {
    ResetStaffGrpVis();
}

AttStaffGrpVis::~AttStaffGrpVis() {

}

void AttStaffGrpVis::ResetStaffGrpVis() {
    m_barthru = BOOLEAN_NONE;
}

bool AttStaffGrpVis::ReadStaffGrpVis(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("barthru")) {
        this->SetBarthru(StrToBool(element.attribute("barthru").value()));
        element.remove_attribute("barthru");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttStaffGrpVis::WriteStaffGrpVis(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasBarthru()) {
        element.append_attribute("barthru") = BoolToStr(this->GetBarthru()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttStaffGrpVis::HasBarthru( )
{
    return (m_barthru != BOOLEAN_NONE);
}


/* include <attbarthru> */

//----------------------------------------------------------------------------
// AttStaffgroupingsym
//----------------------------------------------------------------------------

AttStaffgroupingsym::AttStaffgroupingsym(): Att() {
    ResetStaffgroupingsym();
}

AttStaffgroupingsym::~AttStaffgroupingsym() {

}

void AttStaffgroupingsym::ResetStaffgroupingsym() {
    m_symbol = SYMBOL_NONE;
}

bool AttStaffgroupingsym::ReadStaffgroupingsym(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("symbol")) {
        this->SetSymbol(StrToSymbol(element.attribute("symbol").value()));
        element.remove_attribute("symbol");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttStaffgroupingsym::WriteStaffgroupingsym(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasSymbol()) {
        element.append_attribute("symbol") = SymbolToStr(this->GetSymbol()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttStaffgroupingsym::HasSymbol( )
{
    return (m_symbol != SYMBOL_NONE);
}


/* include <attsymbol> */

//----------------------------------------------------------------------------
// AttStaffident
//----------------------------------------------------------------------------

AttStaffident::AttStaffident(): Att() {
    ResetStaffident();
}

AttStaffident::~AttStaffident() {

}

void AttStaffident::ResetStaffident() {
    m_staff = 0;
}

bool AttStaffident::ReadStaffident(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("staff")) {
        this->SetStaff(StrToInt(element.attribute("staff").value()));
        element.remove_attribute("staff");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttStaffident::WriteStaffident(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasStaff()) {
        element.append_attribute("staff") = IntToStr(this->GetStaff()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttStaffident::HasStaff( )
{
    return (m_staff != 0);
}


/* include <attstaff> */

//----------------------------------------------------------------------------
// AttStaffloc
//----------------------------------------------------------------------------

AttStaffloc::AttStaffloc(): Att() {
    ResetStaffloc();
}

AttStaffloc::~AttStaffloc() {

}

void AttStaffloc::ResetStaffloc() {
    m_loc = "";
}

bool AttStaffloc::ReadStaffloc(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("loc")) {
        this->SetLoc(StrToStr(element.attribute("loc").value()));
        element.remove_attribute("loc");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttStaffloc::WriteStaffloc(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasLoc()) {
        element.append_attribute("loc") = StrToStr(this->GetLoc()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttStaffloc::HasLoc( )
{
    return (m_loc != "");
}


/* include <attloc> */

//----------------------------------------------------------------------------
// AttStafflocPitched
//----------------------------------------------------------------------------

AttStafflocPitched::AttStafflocPitched(): Att() {
    ResetStafflocPitched();
}

AttStafflocPitched::~AttStafflocPitched() {

}

void AttStafflocPitched::ResetStafflocPitched() {
    m_ploc = PITCHNAME_NONE;
    m_oloc = 0;
}

bool AttStafflocPitched::ReadStafflocPitched(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("ploc")) {
        this->SetPloc(StrToPitchName(element.attribute("ploc").value()));
        element.remove_attribute("ploc");
        hasAttribute = true;
    }
    if (element.attribute("oloc")) {
        this->SetOloc(StrToInt(element.attribute("oloc").value()));
        element.remove_attribute("oloc");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttStafflocPitched::WriteStafflocPitched(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasPloc()) {
        element.append_attribute("ploc") = PitchNameToStr(this->GetPloc()).c_str();
        wroteAttribute = true;
    }
    if (this->HasOloc()) {
        element.append_attribute("oloc") = IntToStr(this->GetOloc()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttStafflocPitched::HasPloc( )
{
    return (m_ploc != PITCHNAME_NONE);
}

bool AttStafflocPitched::HasOloc( )
{
    return (m_oloc != 0);
}


/* include <attoloc> */

//----------------------------------------------------------------------------
// AttStartendid
//----------------------------------------------------------------------------

AttStartendid::AttStartendid(): Att() {
    ResetStartendid();
}

AttStartendid::~AttStartendid() {

}

void AttStartendid::ResetStartendid() {
    m_endid = "";
}

bool AttStartendid::ReadStartendid(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("endid")) {
        this->SetEndid(StrToStr(element.attribute("endid").value()));
        element.remove_attribute("endid");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttStartendid::WriteStartendid(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasEndid()) {
        element.append_attribute("endid") = StrToStr(this->GetEndid()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttStartendid::HasEndid( )
{
    return (m_endid != "");
}


/* include <attendid> */

//----------------------------------------------------------------------------
// AttStartid
//----------------------------------------------------------------------------

AttStartid::AttStartid(): Att() {
    ResetStartid();
}

AttStartid::~AttStartid() {

}

void AttStartid::ResetStartid() {
    m_startid = "";
}

bool AttStartid::ReadStartid(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("startid")) {
        this->SetStartid(StrToStr(element.attribute("startid").value()));
        element.remove_attribute("startid");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttStartid::WriteStartid(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasStartid()) {
        element.append_attribute("startid") = StrToStr(this->GetStartid()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttStartid::HasStartid( )
{
    return (m_startid != "");
}


/* include <attstartid> */

//----------------------------------------------------------------------------
// AttStems
//----------------------------------------------------------------------------

AttStems::AttStems(): Att() {
    ResetStems();
}

AttStems::~AttStems() {

}

void AttStems::ResetStems() {
    m_stemDir = STEMDIRECTION_NONE;
    m_stemLen = 0;
    m_stemMod = STEMMODIFIER_NONE;
    m_stemPos = STEMPOSITION_NONE;
    m_stemX = 0;
    m_stemY = 0;
}

bool AttStems::ReadStems(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("stem.dir")) {
        this->SetStemDir(StrToStemDirection(element.attribute("stem.dir").value()));
        element.remove_attribute("stem.dir");
        hasAttribute = true;
    }
    if (element.attribute("stem.len")) {
        this->SetStemLen(StrToInt(element.attribute("stem.len").value()));
        element.remove_attribute("stem.len");
        hasAttribute = true;
    }
    if (element.attribute("stem.mod")) {
        this->SetStemMod(StrToStemModifier(element.attribute("stem.mod").value()));
        element.remove_attribute("stem.mod");
        hasAttribute = true;
    }
    if (element.attribute("stem.pos")) {
        this->SetStemPos(StrToStemPosition(element.attribute("stem.pos").value()));
        element.remove_attribute("stem.pos");
        hasAttribute = true;
    }
    if (element.attribute("stem.x")) {
        this->SetStemX(StrToInt(element.attribute("stem.x").value()));
        element.remove_attribute("stem.x");
        hasAttribute = true;
    }
    if (element.attribute("stem.y")) {
        this->SetStemY(StrToInt(element.attribute("stem.y").value()));
        element.remove_attribute("stem.y");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttStems::WriteStems(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasStemDir()) {
        element.append_attribute("stem.dir") = StemDirectionToStr(this->GetStemDir()).c_str();
        wroteAttribute = true;
    }
    if (this->HasStemLen()) {
        element.append_attribute("stem.len") = IntToStr(this->GetStemLen()).c_str();
        wroteAttribute = true;
    }
    if (this->HasStemMod()) {
        element.append_attribute("stem.mod") = StemModifierToStr(this->GetStemMod()).c_str();
        wroteAttribute = true;
    }
    if (this->HasStemPos()) {
        element.append_attribute("stem.pos") = StemPositionToStr(this->GetStemPos()).c_str();
        wroteAttribute = true;
    }
    if (this->HasStemX()) {
        element.append_attribute("stem.x") = IntToStr(this->GetStemX()).c_str();
        wroteAttribute = true;
    }
    if (this->HasStemY()) {
        element.append_attribute("stem.y") = IntToStr(this->GetStemY()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttStems::HasStemDir( )
{
    return (m_stemDir != STEMDIRECTION_NONE);
}

bool AttStems::HasStemLen( )
{
    return (m_stemLen != 0);
}

bool AttStems::HasStemMod( )
{
    return (m_stemMod != STEMMODIFIER_NONE);
}

bool AttStems::HasStemPos( )
{
    return (m_stemPos != STEMPOSITION_NONE);
}

bool AttStems::HasStemX( )
{
    return (m_stemX != 0);
}

bool AttStems::HasStemY( )
{
    return (m_stemY != 0);
}


/* include <attstem.y> */

//----------------------------------------------------------------------------
// AttSylLog
//----------------------------------------------------------------------------

AttSylLog::AttSylLog(): Att() {
    ResetSylLog();
}

AttSylLog::~AttSylLog() {

}

void AttSylLog::ResetSylLog() {
    m_con = CON_NONE;
    m_wordpos = WORDPOS_NONE;
}

bool AttSylLog::ReadSylLog(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("con")) {
        this->SetCon(StrToCon(element.attribute("con").value()));
        element.remove_attribute("con");
        hasAttribute = true;
    }
    if (element.attribute("wordpos")) {
        this->SetWordpos(StrToWordPos(element.attribute("wordpos").value()));
        element.remove_attribute("wordpos");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttSylLog::WriteSylLog(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasCon()) {
        element.append_attribute("con") = ConToStr(this->GetCon()).c_str();
        wroteAttribute = true;
    }
    if (this->HasWordpos()) {
        element.append_attribute("wordpos") = WordPosToStr(this->GetWordpos()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttSylLog::HasCon( )
{
    return (m_con != CON_NONE);
}

bool AttSylLog::HasWordpos( )
{
    return (m_wordpos != WORDPOS_NONE);
}


/* include <attwordpos> */

//----------------------------------------------------------------------------
// AttSyltext
//----------------------------------------------------------------------------

AttSyltext::AttSyltext(): Att() {
    ResetSyltext();
}

AttSyltext::~AttSyltext() {

}

void AttSyltext::ResetSyltext() {
    m_syl = "";
}

bool AttSyltext::ReadSyltext(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("syl")) {
        this->SetSyl(StrToStr(element.attribute("syl").value()));
        element.remove_attribute("syl");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttSyltext::WriteSyltext(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasSyl()) {
        element.append_attribute("syl") = StrToStr(this->GetSyl()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttSyltext::HasSyl( )
{
    return (m_syl != "");
}


/* include <attsyl> */

//----------------------------------------------------------------------------
// AttSystems
//----------------------------------------------------------------------------

AttSystems::AttSystems(): Att() {
    ResetSystems();
}

AttSystems::~AttSystems() {

}

void AttSystems::ResetSystems() {
    m_systemLeftline = "";
    m_systemLeftmar = "";
    m_systemRightmar = "";
    m_systemTopmar = "";
}

bool AttSystems::ReadSystems(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("system.leftline")) {
        this->SetSystemLeftline(StrToStr(element.attribute("system.leftline").value()));
        element.remove_attribute("system.leftline");
        hasAttribute = true;
    }
    if (element.attribute("system.leftmar")) {
        this->SetSystemLeftmar(StrToStr(element.attribute("system.leftmar").value()));
        element.remove_attribute("system.leftmar");
        hasAttribute = true;
    }
    if (element.attribute("system.rightmar")) {
        this->SetSystemRightmar(StrToStr(element.attribute("system.rightmar").value()));
        element.remove_attribute("system.rightmar");
        hasAttribute = true;
    }
    if (element.attribute("system.topmar")) {
        this->SetSystemTopmar(StrToStr(element.attribute("system.topmar").value()));
        element.remove_attribute("system.topmar");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttSystems::WriteSystems(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasSystemLeftline()) {
        element.append_attribute("system.leftline") = StrToStr(this->GetSystemLeftline()).c_str();
        wroteAttribute = true;
    }
    if (this->HasSystemLeftmar()) {
        element.append_attribute("system.leftmar") = StrToStr(this->GetSystemLeftmar()).c_str();
        wroteAttribute = true;
    }
    if (this->HasSystemRightmar()) {
        element.append_attribute("system.rightmar") = StrToStr(this->GetSystemRightmar()).c_str();
        wroteAttribute = true;
    }
    if (this->HasSystemTopmar()) {
        element.append_attribute("system.topmar") = StrToStr(this->GetSystemTopmar()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttSystems::HasSystemLeftline( )
{
    return (m_systemLeftline != "");
}

bool AttSystems::HasSystemLeftmar( )
{
    return (m_systemLeftmar != "");
}

bool AttSystems::HasSystemRightmar( )
{
    return (m_systemRightmar != "");
}

bool AttSystems::HasSystemTopmar( )
{
    return (m_systemTopmar != "");
}


/* include <attsystem.topmar> */

//----------------------------------------------------------------------------
// AttTextstyle
//----------------------------------------------------------------------------

AttTextstyle::AttTextstyle(): Att() {
    ResetTextstyle();
}

AttTextstyle::~AttTextstyle() {

}

void AttTextstyle::ResetTextstyle() {
    m_textFam = "";
    m_textName = "";
    m_textSize = "";
    m_textStyle = "";
    m_textWeight = "";
}

bool AttTextstyle::ReadTextstyle(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("text.fam")) {
        this->SetTextFam(StrToStr(element.attribute("text.fam").value()));
        element.remove_attribute("text.fam");
        hasAttribute = true;
    }
    if (element.attribute("text.name")) {
        this->SetTextName(StrToStr(element.attribute("text.name").value()));
        element.remove_attribute("text.name");
        hasAttribute = true;
    }
    if (element.attribute("text.size")) {
        this->SetTextSize(StrToStr(element.attribute("text.size").value()));
        element.remove_attribute("text.size");
        hasAttribute = true;
    }
    if (element.attribute("text.style")) {
        this->SetTextStyle(StrToStr(element.attribute("text.style").value()));
        element.remove_attribute("text.style");
        hasAttribute = true;
    }
    if (element.attribute("text.weight")) {
        this->SetTextWeight(StrToStr(element.attribute("text.weight").value()));
        element.remove_attribute("text.weight");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttTextstyle::WriteTextstyle(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasTextFam()) {
        element.append_attribute("text.fam") = StrToStr(this->GetTextFam()).c_str();
        wroteAttribute = true;
    }
    if (this->HasTextName()) {
        element.append_attribute("text.name") = StrToStr(this->GetTextName()).c_str();
        wroteAttribute = true;
    }
    if (this->HasTextSize()) {
        element.append_attribute("text.size") = StrToStr(this->GetTextSize()).c_str();
        wroteAttribute = true;
    }
    if (this->HasTextStyle()) {
        element.append_attribute("text.style") = StrToStr(this->GetTextStyle()).c_str();
        wroteAttribute = true;
    }
    if (this->HasTextWeight()) {
        element.append_attribute("text.weight") = StrToStr(this->GetTextWeight()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttTextstyle::HasTextFam( )
{
    return (m_textFam != "");
}

bool AttTextstyle::HasTextName( )
{
    return (m_textName != "");
}

bool AttTextstyle::HasTextSize( )
{
    return (m_textSize != "");
}

bool AttTextstyle::HasTextStyle( )
{
    return (m_textStyle != "");
}

bool AttTextstyle::HasTextWeight( )
{
    return (m_textWeight != "");
}


/* include <atttext.weight> */

//----------------------------------------------------------------------------
// AttTiepresent
//----------------------------------------------------------------------------

AttTiepresent::AttTiepresent(): Att() {
    ResetTiepresent();
}

AttTiepresent::~AttTiepresent() {

}

void AttTiepresent::ResetTiepresent() {
    m_tie = TIE_NONE;
}

bool AttTiepresent::ReadTiepresent(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("tie")) {
        this->SetTie(StrToTie(element.attribute("tie").value()));
        element.remove_attribute("tie");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttTiepresent::WriteTiepresent(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasTie()) {
        element.append_attribute("tie") = TieToStr(this->GetTie()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttTiepresent::HasTie( )
{
    return (m_tie != TIE_NONE);
}


/* include <atttie> */

//----------------------------------------------------------------------------
// AttTimestampMusical
//----------------------------------------------------------------------------

AttTimestampMusical::AttTimestampMusical(): Att() {
    ResetTimestampMusical();
}

AttTimestampMusical::~AttTimestampMusical() {

}

void AttTimestampMusical::ResetTimestampMusical() {
    m_tstamp = -1.0;
}

bool AttTimestampMusical::ReadTimestampMusical(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("tstamp")) {
        this->SetTstamp(StrToDbl(element.attribute("tstamp").value()));
        element.remove_attribute("tstamp");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttTimestampMusical::WriteTimestampMusical(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasTstamp()) {
        element.append_attribute("tstamp") = DblToStr(this->GetTstamp()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttTimestampMusical::HasTstamp( )
{
    return (m_tstamp != -1.0);
}


/* include <atttstamp> */

//----------------------------------------------------------------------------
// AttTimestampPerformed
//----------------------------------------------------------------------------

AttTimestampPerformed::AttTimestampPerformed(): Att() {
    ResetTimestampPerformed();
}

AttTimestampPerformed::~AttTimestampPerformed() {

}

void AttTimestampPerformed::ResetTimestampPerformed() {
    m_tstampGes = "";
    m_tstampReal = "";
}

bool AttTimestampPerformed::ReadTimestampPerformed(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("tstamp.ges")) {
        this->SetTstampGes(StrToStr(element.attribute("tstamp.ges").value()));
        element.remove_attribute("tstamp.ges");
        hasAttribute = true;
    }
    if (element.attribute("tstamp.real")) {
        this->SetTstampReal(StrToStr(element.attribute("tstamp.real").value()));
        element.remove_attribute("tstamp.real");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttTimestampPerformed::WriteTimestampPerformed(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasTstampGes()) {
        element.append_attribute("tstamp.ges") = StrToStr(this->GetTstampGes()).c_str();
        wroteAttribute = true;
    }
    if (this->HasTstampReal()) {
        element.append_attribute("tstamp.real") = StrToStr(this->GetTstampReal()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttTimestampPerformed::HasTstampGes( )
{
    return (m_tstampGes != "");
}

bool AttTimestampPerformed::HasTstampReal( )
{
    return (m_tstampReal != "");
}


/* include <atttstamp.real> */

//----------------------------------------------------------------------------
// AttTimestamp2Musical
//----------------------------------------------------------------------------

AttTimestamp2Musical::AttTimestamp2Musical(): Att() {
    ResetTimestamp2Musical();
}

AttTimestamp2Musical::~AttTimestamp2Musical() {

}

void AttTimestamp2Musical::ResetTimestamp2Musical() {
    m_tstamp2 = std::make_pair(-1,-1.0);
}

bool AttTimestamp2Musical::ReadTimestamp2Musical(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("tstamp2")) {
        this->SetTstamp2(StrToTstamp2(element.attribute("tstamp2").value()));
        element.remove_attribute("tstamp2");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttTimestamp2Musical::WriteTimestamp2Musical(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasTstamp2()) {
        element.append_attribute("tstamp2") = Tstamp2ToStr(this->GetTstamp2()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttTimestamp2Musical::HasTstamp2( )
{
    return (m_tstamp2 != std::make_pair(-1,-1.0));
}


/* include <atttstamp2> */

//----------------------------------------------------------------------------
// AttTransposition
//----------------------------------------------------------------------------

AttTransposition::AttTransposition(): Att() {
    ResetTransposition();
}

AttTransposition::~AttTransposition() {

}

void AttTransposition::ResetTransposition() {
    m_transDiatDbl = 0.0;
    m_transSemiDbl = 0.0;
}

bool AttTransposition::ReadTransposition(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("trans.diat")) {
        this->SetTransDiat(StrToDbl(element.attribute("trans.diat").value()));
        element.remove_attribute("trans.diat");
        hasAttribute = true;
    }
    if (element.attribute("trans.semi")) {
        this->SetTransSemi(StrToDbl(element.attribute("trans.semi").value()));
        element.remove_attribute("trans.semi");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttTransposition::WriteTransposition(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasTransDiat()) {
        element.append_attribute("trans.diat") = DblToStr(this->GetTransDiat()).c_str();
        wroteAttribute = true;
    }
    if (this->HasTransSemi()) {
        element.append_attribute("trans.semi") = DblToStr(this->GetTransSemi()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttTransposition::HasTransDiat( )
{
    return (m_transDiatDbl != 0.0);
}

bool AttTransposition::HasTransSemi( )
{
    return (m_transSemiDbl != 0.0);
}


/* include <atttrans.semi> */

//----------------------------------------------------------------------------
// AttTupletpresent
//----------------------------------------------------------------------------

AttTupletpresent::AttTupletpresent(): Att() {
    ResetTupletpresent();
}

AttTupletpresent::~AttTupletpresent() {

}

void AttTupletpresent::ResetTupletpresent() {
    m_tuplet = "";
}

bool AttTupletpresent::ReadTupletpresent(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("tuplet")) {
        this->SetTuplet(StrToStr(element.attribute("tuplet").value()));
        element.remove_attribute("tuplet");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttTupletpresent::WriteTupletpresent(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasTuplet()) {
        element.append_attribute("tuplet") = StrToStr(this->GetTuplet()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttTupletpresent::HasTuplet( )
{
    return (m_tuplet != "");
}


/* include <atttuplet> */

//----------------------------------------------------------------------------
// AttTyped
//----------------------------------------------------------------------------

AttTyped::AttTyped(): Att() {
    ResetTyped();
}

AttTyped::~AttTyped() {

}

void AttTyped::ResetTyped() {
    m_type = "";
    m_subtype = "";
}

bool AttTyped::ReadTyped(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("type")) {
        this->SetType(StrToStr(element.attribute("type").value()));
        element.remove_attribute("type");
        hasAttribute = true;
    }
    if (element.attribute("subtype")) {
        this->SetSubtype(StrToStr(element.attribute("subtype").value()));
        element.remove_attribute("subtype");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttTyped::WriteTyped(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasType()) {
        element.append_attribute("type") = StrToStr(this->GetType()).c_str();
        wroteAttribute = true;
    }
    if (this->HasSubtype()) {
        element.append_attribute("subtype") = StrToStr(this->GetSubtype()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttTyped::HasType( )
{
    return (m_type != "");
}

bool AttTyped::HasSubtype( )
{
    return (m_subtype != "");
}


/* include <attsubtype> */

//----------------------------------------------------------------------------
// AttTypography
//----------------------------------------------------------------------------

AttTypography::AttTypography(): Att() {
    ResetTypography();
}

AttTypography::~AttTypography() {

}

void AttTypography::ResetTypography() {
    m_fontfam = "";
    m_fontname = "";
    m_fontsizeDbl = 0.0;
    m_fontstyle = FONTSTYLE_NONE;
    m_fontweight = FONTWEIGHT_NONE;
}

bool AttTypography::ReadTypography(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("fontfam")) {
        this->SetFontfam(StrToStr(element.attribute("fontfam").value()));
        element.remove_attribute("fontfam");
        hasAttribute = true;
    }
    if (element.attribute("fontname")) {
        this->SetFontname(StrToStr(element.attribute("fontname").value()));
        element.remove_attribute("fontname");
        hasAttribute = true;
    }
    if (element.attribute("fontsize")) {
        this->SetFontsize(StrToDbl(element.attribute("fontsize").value()));
        element.remove_attribute("fontsize");
        hasAttribute = true;
    }
    if (element.attribute("fontstyle")) {
        this->SetFontstyle(StrToFontstyle(element.attribute("fontstyle").value()));
        element.remove_attribute("fontstyle");
        hasAttribute = true;
    }
    if (element.attribute("fontweight")) {
        this->SetFontweight(StrToFontweight(element.attribute("fontweight").value()));
        element.remove_attribute("fontweight");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttTypography::WriteTypography(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasFontfam()) {
        element.append_attribute("fontfam") = StrToStr(this->GetFontfam()).c_str();
        wroteAttribute = true;
    }
    if (this->HasFontname()) {
        element.append_attribute("fontname") = StrToStr(this->GetFontname()).c_str();
        wroteAttribute = true;
    }
    if (this->HasFontsize()) {
        element.append_attribute("fontsize") = DblToStr(this->GetFontsize()).c_str();
        wroteAttribute = true;
    }
    if (this->HasFontstyle()) {
        element.append_attribute("fontstyle") = FontstyleToStr(this->GetFontstyle()).c_str();
        wroteAttribute = true;
    }
    if (this->HasFontweight()) {
        element.append_attribute("fontweight") = FontweightToStr(this->GetFontweight()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttTypography::HasFontfam( )
{
    return (m_fontfam != "");
}

bool AttTypography::HasFontname( )
{
    return (m_fontname != "");
}

bool AttTypography::HasFontsize( )
{
    return (m_fontsizeDbl != 0.0);
}

bool AttTypography::HasFontstyle( )
{
    return (m_fontstyle != FONTSTYLE_NONE);
}

bool AttTypography::HasFontweight( )
{
    return (m_fontweight != FONTWEIGHT_NONE);
}


/* include <attfontweight> */

//----------------------------------------------------------------------------
// AttVisibility
//----------------------------------------------------------------------------

AttVisibility::AttVisibility(): Att() {
    ResetVisibility();
}

AttVisibility::~AttVisibility() {

}

void AttVisibility::ResetVisibility() {
    m_visible = "";
}

bool AttVisibility::ReadVisibility(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("visible")) {
        this->SetVisible(StrToStr(element.attribute("visible").value()));
        element.remove_attribute("visible");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttVisibility::WriteVisibility(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasVisible()) {
        element.append_attribute("visible") = StrToStr(this->GetVisible()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttVisibility::HasVisible( )
{
    return (m_visible != "");
}


/* include <attvisible> */

//----------------------------------------------------------------------------
// AttVisualoffsetHo
//----------------------------------------------------------------------------

AttVisualoffsetHo::AttVisualoffsetHo(): Att() {
    ResetVisualoffsetHo();
}

AttVisualoffsetHo::~AttVisualoffsetHo() {

}

void AttVisualoffsetHo::ResetVisualoffsetHo() {
    m_ho = "";
}

bool AttVisualoffsetHo::ReadVisualoffsetHo(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("ho")) {
        this->SetHo(StrToStr(element.attribute("ho").value()));
        element.remove_attribute("ho");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttVisualoffsetHo::WriteVisualoffsetHo(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasHo()) {
        element.append_attribute("ho") = StrToStr(this->GetHo()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttVisualoffsetHo::HasHo( )
{
    return (m_ho != "");
}


/* include <attho> */

//----------------------------------------------------------------------------
// AttVisualoffsetTo
//----------------------------------------------------------------------------

AttVisualoffsetTo::AttVisualoffsetTo(): Att() {
    ResetVisualoffsetTo();
}

AttVisualoffsetTo::~AttVisualoffsetTo() {

}

void AttVisualoffsetTo::ResetVisualoffsetTo() {
    m_to = "";
}

bool AttVisualoffsetTo::ReadVisualoffsetTo(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("to")) {
        this->SetTo(StrToStr(element.attribute("to").value()));
        element.remove_attribute("to");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttVisualoffsetTo::WriteVisualoffsetTo(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasTo()) {
        element.append_attribute("to") = StrToStr(this->GetTo()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttVisualoffsetTo::HasTo( )
{
    return (m_to != "");
}


/* include <attto> */

//----------------------------------------------------------------------------
// AttVisualoffsetVo
//----------------------------------------------------------------------------

AttVisualoffsetVo::AttVisualoffsetVo(): Att() {
    ResetVisualoffsetVo();
}

AttVisualoffsetVo::~AttVisualoffsetVo() {

}

void AttVisualoffsetVo::ResetVisualoffsetVo() {
    m_vo = "";
}

bool AttVisualoffsetVo::ReadVisualoffsetVo(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("vo")) {
        this->SetVo(StrToStr(element.attribute("vo").value()));
        element.remove_attribute("vo");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttVisualoffsetVo::WriteVisualoffsetVo(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasVo()) {
        element.append_attribute("vo") = StrToStr(this->GetVo()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttVisualoffsetVo::HasVo( )
{
    return (m_vo != "");
}


/* include <attvo> */

//----------------------------------------------------------------------------
// AttVisualoffset2Ho
//----------------------------------------------------------------------------

AttVisualoffset2Ho::AttVisualoffset2Ho(): Att() {
    ResetVisualoffset2Ho();
}

AttVisualoffset2Ho::~AttVisualoffset2Ho() {

}

void AttVisualoffset2Ho::ResetVisualoffset2Ho() {
    m_startho = "";
    m_endho = "";
}

bool AttVisualoffset2Ho::ReadVisualoffset2Ho(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("startho")) {
        this->SetStartho(StrToStr(element.attribute("startho").value()));
        element.remove_attribute("startho");
        hasAttribute = true;
    }
    if (element.attribute("endho")) {
        this->SetEndho(StrToStr(element.attribute("endho").value()));
        element.remove_attribute("endho");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttVisualoffset2Ho::WriteVisualoffset2Ho(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasStartho()) {
        element.append_attribute("startho") = StrToStr(this->GetStartho()).c_str();
        wroteAttribute = true;
    }
    if (this->HasEndho()) {
        element.append_attribute("endho") = StrToStr(this->GetEndho()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttVisualoffset2Ho::HasStartho( )
{
    return (m_startho != "");
}

bool AttVisualoffset2Ho::HasEndho( )
{
    return (m_endho != "");
}


/* include <attendho> */

//----------------------------------------------------------------------------
// AttVisualoffset2To
//----------------------------------------------------------------------------

AttVisualoffset2To::AttVisualoffset2To(): Att() {
    ResetVisualoffset2To();
}

AttVisualoffset2To::~AttVisualoffset2To() {

}

void AttVisualoffset2To::ResetVisualoffset2To() {
    m_startto = "";
    m_endto = "";
}

bool AttVisualoffset2To::ReadVisualoffset2To(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("startto")) {
        this->SetStartto(StrToStr(element.attribute("startto").value()));
        element.remove_attribute("startto");
        hasAttribute = true;
    }
    if (element.attribute("endto")) {
        this->SetEndto(StrToStr(element.attribute("endto").value()));
        element.remove_attribute("endto");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttVisualoffset2To::WriteVisualoffset2To(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasStartto()) {
        element.append_attribute("startto") = StrToStr(this->GetStartto()).c_str();
        wroteAttribute = true;
    }
    if (this->HasEndto()) {
        element.append_attribute("endto") = StrToStr(this->GetEndto()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttVisualoffset2To::HasStartto( )
{
    return (m_startto != "");
}

bool AttVisualoffset2To::HasEndto( )
{
    return (m_endto != "");
}


/* include <attendto> */

//----------------------------------------------------------------------------
// AttVisualoffset2Vo
//----------------------------------------------------------------------------

AttVisualoffset2Vo::AttVisualoffset2Vo(): Att() {
    ResetVisualoffset2Vo();
}

AttVisualoffset2Vo::~AttVisualoffset2Vo() {

}

void AttVisualoffset2Vo::ResetVisualoffset2Vo() {
    m_startvo = "";
    m_endvo = "";
}

bool AttVisualoffset2Vo::ReadVisualoffset2Vo(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("startvo")) {
        this->SetStartvo(StrToStr(element.attribute("startvo").value()));
        element.remove_attribute("startvo");
        hasAttribute = true;
    }
    if (element.attribute("endvo")) {
        this->SetEndvo(StrToStr(element.attribute("endvo").value()));
        element.remove_attribute("endvo");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttVisualoffset2Vo::WriteVisualoffset2Vo(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasStartvo()) {
        element.append_attribute("startvo") = StrToStr(this->GetStartvo()).c_str();
        wroteAttribute = true;
    }
    if (this->HasEndvo()) {
        element.append_attribute("endvo") = StrToStr(this->GetEndvo()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttVisualoffset2Vo::HasStartvo( )
{
    return (m_startvo != "");
}

bool AttVisualoffset2Vo::HasEndvo( )
{
    return (m_endvo != "");
}


/* include <attendvo> */

//----------------------------------------------------------------------------
// AttWhitespace
//----------------------------------------------------------------------------

AttWhitespace::AttWhitespace(): Att() {
    ResetWhitespace();
}

AttWhitespace::~AttWhitespace() {

}

void AttWhitespace::ResetWhitespace() {
    m_space = "";
}

bool AttWhitespace::ReadWhitespace(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("space")) {
        this->SetSpace(StrToStr(element.attribute("space").value()));
        element.remove_attribute("space");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttWhitespace::WriteWhitespace(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasSpace()) {
        element.append_attribute("space") = StrToStr(this->GetSpace()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttWhitespace::HasSpace( )
{
    return (m_space != "");
}


/* include <attspace> */

//----------------------------------------------------------------------------
// AttWidth
//----------------------------------------------------------------------------

AttWidth::AttWidth(): Att() {
    ResetWidth();
}

AttWidth::~AttWidth() {

}

void AttWidth::ResetWidth() {
    m_width = "";
}

bool AttWidth::ReadWidth(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("width")) {
        this->SetWidth(StrToStr(element.attribute("width").value()));
        element.remove_attribute("width");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttWidth::WriteWidth(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasWidth()) {
        element.append_attribute("width") = StrToStr(this->GetWidth()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttWidth::HasWidth( )
{
    return (m_width != "");
}


/* include <attwidth> */

//----------------------------------------------------------------------------
// AttXy
//----------------------------------------------------------------------------

AttXy::AttXy(): Att() {
    ResetXy();
}

AttXy::~AttXy() {

}

void AttXy::ResetXy() {
    m_xDbl = 0.0;
    m_yDbl = 0.0;
}

bool AttXy::ReadXy(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("x")) {
        this->SetX(StrToDbl(element.attribute("x").value()));
        element.remove_attribute("x");
        hasAttribute = true;
    }
    if (element.attribute("y")) {
        this->SetY(StrToDbl(element.attribute("y").value()));
        element.remove_attribute("y");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttXy::WriteXy(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasX()) {
        element.append_attribute("x") = DblToStr(this->GetX()).c_str();
        wroteAttribute = true;
    }
    if (this->HasY()) {
        element.append_attribute("y") = DblToStr(this->GetY()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttXy::HasX( )
{
    return (m_xDbl != 0.0);
}

bool AttXy::HasY( )
{
    return (m_yDbl != 0.0);
}


/* include <atty> */

//----------------------------------------------------------------------------
// AttXy2
//----------------------------------------------------------------------------

AttXy2::AttXy2(): Att() {
    ResetXy2();
}

AttXy2::~AttXy2() {

}

void AttXy2::ResetXy2() {
    m_x2Dbl = 0.0;
    m_y2Dbl = 0.0;
}

bool AttXy2::ReadXy2(  pugi::xml_node element ) {
    bool hasAttribute = false;
    if (element.attribute("x2")) {
        this->SetX2(StrToDbl(element.attribute("x2").value()));
        element.remove_attribute("x2");
        hasAttribute = true;
    }
    if (element.attribute("y2")) {
        this->SetY2(StrToDbl(element.attribute("y2").value()));
        element.remove_attribute("y2");
        hasAttribute = true;
    }
    return hasAttribute;
}

bool AttXy2::WriteXy2(  pugi::xml_node element ) {
    bool wroteAttribute = false;
    if (this->HasX2()) {
        element.append_attribute("x2") = DblToStr(this->GetX2()).c_str();
        wroteAttribute = true;
    }
    if (this->HasY2()) {
        element.append_attribute("y2") = DblToStr(this->GetY2()).c_str();
        wroteAttribute = true;
    }
    return wroteAttribute;
}

bool AttXy2::HasX2( )
{
    return (m_x2Dbl != 0.0);
}

bool AttXy2::HasY2( )
{
    return (m_y2Dbl != 0.0);
}


/* include <atty2> */

bool Att::SetShared( Object *element, std::string attrType, std::string attrValue ) {
    if (element->HasAttClass( ATT_ACCIDLOG ) ) {
        AttAccidLog *att = dynamic_cast<AttAccidLog*>(element);
        assert( att );
        if (attrType == "func") {
            att->SetFunc(att->StrToFunc(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_ACCIDENTAL ) ) {
        AttAccidental *att = dynamic_cast<AttAccidental*>(element);
        assert( att );
        if (attrType == "accid") {
            att->SetAccid(att->StrToAccidentalExplicit(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_ACCIDENTALPERFORMED ) ) {
        AttAccidentalPerformed *att = dynamic_cast<AttAccidentalPerformed*>(element);
        assert( att );
        if (attrType == "accidGes") {
            att->SetAccidGes(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_ARTICULATION ) ) {
        AttArticulation *att = dynamic_cast<AttArticulation*>(element);
        assert( att );
        if (attrType == "artic") {
            att->SetArtic(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_ARTICULATIONPERFORMED ) ) {
        AttArticulationPerformed *att = dynamic_cast<AttArticulationPerformed*>(element);
        assert( att );
        if (attrType == "articGes") {
            att->SetArticGes(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_AUGMENTDOTS ) ) {
        AttAugmentdots *att = dynamic_cast<AttAugmentdots*>(element);
        assert( att );
        if (attrType == "dots") {
            att->SetDots(att->StrToInt(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_AUTHORIZED ) ) {
        AttAuthorized *att = dynamic_cast<AttAuthorized*>(element);
        assert( att );
        if (attrType == "authority") {
            att->SetAuthority(att->StrToStr(attrValue));
            return true;
        }
        if (attrType == "authURI") {
            att->SetAuthURI(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_BARLINELOG ) ) {
        AttBarLineLog *att = dynamic_cast<AttBarLineLog*>(element);
        assert( att );
        if (attrType == "form") {
            att->SetForm(att->StrToBarRendition(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_BARPLACEMENT ) ) {
        AttBarplacement *att = dynamic_cast<AttBarplacement*>(element);
        assert( att );
        if (attrType == "barplace") {
            att->SetBarplace(att->StrToStr(attrValue));
            return true;
        }
        if (attrType == "taktplace") {
            att->SetTaktplace(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_BEAMINGVIS ) ) {
        AttBeamingVis *att = dynamic_cast<AttBeamingVis*>(element);
        assert( att );
        if (attrType == "beamColor") {
            att->SetBeamColor(att->StrToStr(attrValue));
            return true;
        }
        if (attrType == "beamRend") {
            att->SetBeamRend(att->StrToStr(attrValue));
            return true;
        }
        if (attrType == "beamSlopeDbl") {
            att->SetBeamSlope(att->StrToDbl(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_BIBL ) ) {
        AttBibl *att = dynamic_cast<AttBibl*>(element);
        assert( att );
        if (attrType == "analog") {
            att->SetAnalog(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_CALENDARED ) ) {
        AttCalendared *att = dynamic_cast<AttCalendared*>(element);
        assert( att );
        if (attrType == "calendar") {
            att->SetCalendar(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_CANONICAL ) ) {
        AttCanonical *att = dynamic_cast<AttCanonical*>(element);
        assert( att );
        if (attrType == "codedval") {
            att->SetCodedval(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_CHORDVIS ) ) {
        AttChordVis *att = dynamic_cast<AttChordVis*>(element);
        assert( att );
        if (attrType == "cluster") {
            att->SetCluster(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_CLASSCODEIDENT ) ) {
        AttClasscodeident *att = dynamic_cast<AttClasscodeident*>(element);
        assert( att );
        if (attrType == "classcode") {
            att->SetClasscode(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_CLEFLOG ) ) {
        AttClefLog *att = dynamic_cast<AttClefLog*>(element);
        assert( att );
        if (attrType == "cautionary") {
            att->SetCautionary(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_CLEFFINGLOG ) ) {
        AttCleffingLog *att = dynamic_cast<AttCleffingLog*>(element);
        assert( att );
        if (attrType == "clefShape") {
            att->SetClefShape(att->StrToClefShape(attrValue));
            return true;
        }
        if (attrType == "clefLine") {
            att->SetClefLine(att->StrToInt(attrValue));
            return true;
        }
        if (attrType == "clefDis") {
            att->SetClefDis(att->StrToOctaveDis(attrValue));
            return true;
        }
        if (attrType == "clefDisPlace") {
            att->SetClefDisPlace(att->StrToPlace(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_CLEFFINGVIS ) ) {
        AttCleffingVis *att = dynamic_cast<AttCleffingVis*>(element);
        assert( att );
        if (attrType == "clefColor") {
            att->SetClefColor(att->StrToStr(attrValue));
            return true;
        }
        if (attrType == "clefVisible") {
            att->SetClefVisible(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_CLEFSHAPE ) ) {
        AttClefshape *att = dynamic_cast<AttClefshape*>(element);
        assert( att );
        if (attrType == "shape") {
            att->SetShape(att->StrToClefShape(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_COLOR ) ) {
        AttColor *att = dynamic_cast<AttColor*>(element);
        assert( att );
        if (attrType == "color") {
            att->SetColor(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_COLORATION ) ) {
        AttColoration *att = dynamic_cast<AttColoration*>(element);
        assert( att );
        if (attrType == "colored") {
            att->SetColored(att->StrToBool(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_COMMON ) ) {
        AttCommon *att = dynamic_cast<AttCommon*>(element);
        assert( att );
        if (attrType == "n") {
            att->SetN(att->StrToInt(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_COMMONPART ) ) {
        AttCommonPart *att = dynamic_cast<AttCommonPart*>(element);
        assert( att );
        if (attrType == "label") {
            att->SetLabel(att->StrToStr(attrValue));
            return true;
        }
        if (attrType == "base") {
            att->SetBase(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_COORDINATED ) ) {
        AttCoordinated *att = dynamic_cast<AttCoordinated*>(element);
        assert( att );
        if (attrType == "ulxInt") {
            att->SetUlx(att->StrToInt(attrValue));
            return true;
        }
        if (attrType == "ulyInt") {
            att->SetUly(att->StrToInt(attrValue));
            return true;
        }
        if (attrType == "lrxInt") {
            att->SetLrx(att->StrToInt(attrValue));
            return true;
        }
        if (attrType == "lryInt") {
            att->SetLry(att->StrToInt(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_CURVATURE ) ) {
        AttCurvature *att = dynamic_cast<AttCurvature*>(element);
        assert( att );
        if (attrType == "bezier") {
            att->SetBezier(att->StrToStr(attrValue));
            return true;
        }
        if (attrType == "bulge") {
            att->SetBulge(att->StrToDbl(attrValue));
            return true;
        }
        if (attrType == "curvedir") {
            att->SetCurvedir(att->StrToCurvedir(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_CURVEREND ) ) {
        AttCurverend *att = dynamic_cast<AttCurverend*>(element);
        assert( att );
        if (attrType == "lform") {
            att->SetLform(att->StrToStr(attrValue));
            return true;
        }
        if (attrType == "lwidth") {
            att->SetLwidth(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_CUSTOSLOG ) ) {
        AttCustosLog *att = dynamic_cast<AttCustosLog*>(element);
        assert( att );
        if (attrType == "target") {
            att->SetTarget(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_DATABLE ) ) {
        AttDatable *att = dynamic_cast<AttDatable*>(element);
        assert( att );
        if (attrType == "enddate") {
            att->SetEnddate(att->StrToStr(attrValue));
            return true;
        }
        if (attrType == "isodate") {
            att->SetIsodate(att->StrToStr(attrValue));
            return true;
        }
        if (attrType == "notafter") {
            att->SetNotafter(att->StrToStr(attrValue));
            return true;
        }
        if (attrType == "notbefore") {
            att->SetNotbefore(att->StrToStr(attrValue));
            return true;
        }
        if (attrType == "startdate") {
            att->SetStartdate(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_DATAPOINTING ) ) {
        AttDatapointing *att = dynamic_cast<AttDatapointing*>(element);
        assert( att );
        if (attrType == "data") {
            att->SetData(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_DECLARING ) ) {
        AttDeclaring *att = dynamic_cast<AttDeclaring*>(element);
        assert( att );
        if (attrType == "decls") {
            att->SetDecls(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_DISTANCES ) ) {
        AttDistances *att = dynamic_cast<AttDistances*>(element);
        assert( att );
        if (attrType == "dynamDist") {
            att->SetDynamDist(att->StrToStr(attrValue));
            return true;
        }
        if (attrType == "harmDist") {
            att->SetHarmDist(att->StrToStr(attrValue));
            return true;
        }
        if (attrType == "textDist") {
            att->SetTextDist(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_DOTLOG ) ) {
        AttDotLog *att = dynamic_cast<AttDotLog*>(element);
        assert( att );
        if (attrType == "form") {
            att->SetForm(att->StrToBarRendition(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_DURATIONADDITIVE ) ) {
        AttDurationAdditive *att = dynamic_cast<AttDurationAdditive*>(element);
        assert( att );
        if (attrType == "dur") {
            att->SetDur(att->StrToDur(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_DURATIONDEFAULT ) ) {
        AttDurationDefault *att = dynamic_cast<AttDurationDefault*>(element);
        assert( att );
        if (attrType == "durDefault") {
            att->SetDurDefault(att->StrToStr(attrValue));
            return true;
        }
        if (attrType == "numDefaultInt") {
            att->SetNumDefault(att->StrToInt(attrValue));
            return true;
        }
        if (attrType == "numbaseDefaultInt") {
            att->SetNumbaseDefault(att->StrToInt(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_DURATIONMUSICAL ) ) {
        AttDurationMusical *att = dynamic_cast<AttDurationMusical*>(element);
        assert( att );
        if (attrType == "dur") {
            att->SetDur(att->StrToDur(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_DURATIONPERFORMED ) ) {
        AttDurationPerformed *att = dynamic_cast<AttDurationPerformed*>(element);
        assert( att );
        if (attrType == "durGes") {
            att->SetDurGes(att->StrToDur(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_DURATIONRATIO ) ) {
        AttDurationRatio *att = dynamic_cast<AttDurationRatio*>(element);
        assert( att );
        if (attrType == "num") {
            att->SetNum(att->StrToInt(attrValue));
            return true;
        }
        if (attrType == "numbase") {
            att->SetNumbase(att->StrToInt(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_ENCLOSINGCHARS ) ) {
        AttEnclosingchars *att = dynamic_cast<AttEnclosingchars*>(element);
        assert( att );
        if (attrType == "enclose") {
            att->SetEnclose(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_ENDINGS ) ) {
        AttEndings *att = dynamic_cast<AttEndings*>(element);
        assert( att );
        if (attrType == "endingRend") {
            att->SetEndingRend(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_EXTENDER ) ) {
        AttExtender *att = dynamic_cast<AttExtender*>(element);
        assert( att );
        if (attrType == "extender") {
            att->SetExtender(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_FERMATAPRESENT ) ) {
        AttFermatapresent *att = dynamic_cast<AttFermatapresent*>(element);
        assert( att );
        if (attrType == "fermata") {
            att->SetFermata(att->StrToPlace(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_FILING ) ) {
        AttFiling *att = dynamic_cast<AttFiling*>(element);
        assert( att );
        if (attrType == "nonfilingInt") {
            att->SetNonfiling(att->StrToInt(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_GRPSYMLOG ) ) {
        AttGrpSymLog *att = dynamic_cast<AttGrpSymLog*>(element);
        assert( att );
        if (attrType == "levelInt") {
            att->SetLevel(att->StrToInt(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_HANDIDENT ) ) {
        AttHandident *att = dynamic_cast<AttHandident*>(element);
        assert( att );
        if (attrType == "hand") {
            att->SetHand(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_HEIGHT ) ) {
        AttHeight *att = dynamic_cast<AttHeight*>(element);
        assert( att );
        if (attrType == "height") {
            att->SetHeight(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_HORIZONTALALIGN ) ) {
        AttHorizontalalign *att = dynamic_cast<AttHorizontalalign*>(element);
        assert( att );
        if (attrType == "halign") {
            att->SetHalign(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_INSTRUMENTIDENT ) ) {
        AttInstrumentident *att = dynamic_cast<AttInstrumentident*>(element);
        assert( att );
        if (attrType == "instr") {
            att->SetInstr(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_INTERNETMEDIA ) ) {
        AttInternetmedia *att = dynamic_cast<AttInternetmedia*>(element);
        assert( att );
        if (attrType == "mimetype") {
            att->SetMimetype(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_JOINED ) ) {
        AttJoined *att = dynamic_cast<AttJoined*>(element);
        assert( att );
        if (attrType == "join") {
            att->SetJoin(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_KEYSIGLOG ) ) {
        AttKeySigLog *att = dynamic_cast<AttKeySigLog*>(element);
        assert( att );
        if (attrType == "mode") {
            att->SetMode(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_KEYSIGDEFAULTLOG ) ) {
        AttKeySigDefaultLog *att = dynamic_cast<AttKeySigDefaultLog*>(element);
        assert( att );
        if (attrType == "keyAccid") {
            att->SetKeyAccid(att->StrToAccidentalImplicit(attrValue));
            return true;
        }
        if (attrType == "keyMode") {
            att->SetKeyMode(att->StrToMode(attrValue));
            return true;
        }
        if (attrType == "keyPname") {
            att->SetKeyPname(att->StrToPitchName(attrValue));
            return true;
        }
        if (attrType == "keySig") {
            att->SetKeySig(att->StrToKeySignature(attrValue));
            return true;
        }
        if (attrType == "keySigMixed") {
            att->SetKeySigMixed(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_KEYSIGDEFAULTVIS ) ) {
        AttKeySigDefaultVis *att = dynamic_cast<AttKeySigDefaultVis*>(element);
        assert( att );
        if (attrType == "keySigShow") {
            att->SetKeySigShow(att->StrToBool(attrValue));
            return true;
        }
        if (attrType == "keySigShowchange") {
            att->SetKeySigShowchange(att->StrToBool(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_LABELSADDL ) ) {
        AttLabelsAddl *att = dynamic_cast<AttLabelsAddl*>(element);
        assert( att );
        if (attrType == "labelAbbr") {
            att->SetLabelAbbr(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_LANG ) ) {
        AttLang *att = dynamic_cast<AttLang*>(element);
        assert( att );
        if (attrType == "lang") {
            att->SetLang(att->StrToStr(attrValue));
            return true;
        }
        if (attrType == "translit") {
            att->SetTranslit(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_LAYERLOG ) ) {
        AttLayerLog *att = dynamic_cast<AttLayerLog*>(element);
        assert( att );
        if (attrType == "def") {
            att->SetDef(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_LAYERIDENT ) ) {
        AttLayerident *att = dynamic_cast<AttLayerident*>(element);
        assert( att );
        if (attrType == "layerInt") {
            att->SetLayer(att->StrToInt(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_LINEVIS ) ) {
        AttLineVis *att = dynamic_cast<AttLineVis*>(element);
        assert( att );
        if (attrType == "form") {
            att->SetForm(att->StrToBarRendition(attrValue));
            return true;
        }
        if (attrType == "width") {
            att->SetWidth(att->StrToStr(attrValue));
            return true;
        }
        if (attrType == "endsym") {
            att->SetEndsym(att->StrToStr(attrValue));
            return true;
        }
        if (attrType == "endsymsize") {
            att->SetEndsymsize(att->StrToStr(attrValue));
            return true;
        }
        if (attrType == "startsym") {
            att->SetStartsym(att->StrToStr(attrValue));
            return true;
        }
        if (attrType == "startsymsize") {
            att->SetStartsymsize(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_LINELOC ) ) {
        AttLineloc *att = dynamic_cast<AttLineloc*>(element);
        assert( att );
        if (attrType == "line") {
            att->SetLine(att->StrToInt(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_LINEREND ) ) {
        AttLinerend *att = dynamic_cast<AttLinerend*>(element);
        assert( att );
        if (attrType == "lendsym") {
            att->SetLendsym(att->StrToStr(attrValue));
            return true;
        }
        if (attrType == "lendsymsize") {
            att->SetLendsymsize(att->StrToStr(attrValue));
            return true;
        }
        if (attrType == "lstartsym") {
            att->SetLstartsym(att->StrToStr(attrValue));
            return true;
        }
        if (attrType == "lstartsymsize") {
            att->SetLstartsymsize(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_LINERENDBASE ) ) {
        AttLinerendBase *att = dynamic_cast<AttLinerendBase*>(element);
        assert( att );
        if (attrType == "lform") {
            att->SetLform(att->StrToStr(attrValue));
            return true;
        }
        if (attrType == "lwidth") {
            att->SetLwidth(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_LYRICSTYLE ) ) {
        AttLyricstyle *att = dynamic_cast<AttLyricstyle*>(element);
        assert( att );
        if (attrType == "lyricAlign") {
            att->SetLyricAlign(att->StrToStr(attrValue));
            return true;
        }
        if (attrType == "lyricFam") {
            att->SetLyricFam(att->StrToStr(attrValue));
            return true;
        }
        if (attrType == "lyricName") {
            att->SetLyricName(att->StrToStr(attrValue));
            return true;
        }
        if (attrType == "lyricSize") {
            att->SetLyricSize(att->StrToStr(attrValue));
            return true;
        }
        if (attrType == "lyricStyle") {
            att->SetLyricStyle(att->StrToStr(attrValue));
            return true;
        }
        if (attrType == "lyricWeight") {
            att->SetLyricWeight(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_MEASURELOG ) ) {
        AttMeasureLog *att = dynamic_cast<AttMeasureLog*>(element);
        assert( att );
        if (attrType == "left") {
            att->SetLeft(att->StrToBarRendition(attrValue));
            return true;
        }
        if (attrType == "right") {
            att->SetRight(att->StrToBarRendition(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_MEASUREMENT ) ) {
        AttMeasurement *att = dynamic_cast<AttMeasurement*>(element);
        assert( att );
        if (attrType == "unit") {
            att->SetUnit(att->StrToInt(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_MEASURENUMBERS ) ) {
        AttMeasurenumbers *att = dynamic_cast<AttMeasurenumbers*>(element);
        assert( att );
        if (attrType == "mnumVisible") {
            att->SetMnumVisible(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_MEDIABOUNDS ) ) {
        AttMediabounds *att = dynamic_cast<AttMediabounds*>(element);
        assert( att );
        if (attrType == "begin") {
            att->SetBegin(att->StrToStr(attrValue));
            return true;
        }
        if (attrType == "end") {
            att->SetEnd(att->StrToStr(attrValue));
            return true;
        }
        if (attrType == "betype") {
            att->SetBetype(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_MEDIUM ) ) {
        AttMedium *att = dynamic_cast<AttMedium*>(element);
        assert( att );
        if (attrType == "medium") {
            att->SetMedium(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_MEIVERSION ) ) {
        AttMeiversion *att = dynamic_cast<AttMeiversion*>(element);
        assert( att );
        if (attrType == "meiversion") {
            att->SetMeiversion(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_MENSURLOG ) ) {
        AttMensurLog *att = dynamic_cast<AttMensurLog*>(element);
        assert( att );
        if (attrType == "dot") {
            att->SetDot(att->StrToBool(attrValue));
            return true;
        }
        if (attrType == "sign") {
            att->SetSign(att->StrToMensurationSign(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_METERSIGLOG ) ) {
        AttMeterSigLog *att = dynamic_cast<AttMeterSigLog*>(element);
        assert( att );
        if (attrType == "count") {
            att->SetCount(att->StrToInt(attrValue));
            return true;
        }
        if (attrType == "sym") {
            att->SetSym(att->StrToMeterSign(attrValue));
            return true;
        }
        if (attrType == "unit") {
            att->SetUnit(att->StrToInt(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_METERSIGVIS ) ) {
        AttMeterSigVis *att = dynamic_cast<AttMeterSigVis*>(element);
        assert( att );
        if (attrType == "form") {
            att->SetForm(att->StrToBarRendition(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_METERSIGDEFAULTLOG ) ) {
        AttMeterSigDefaultLog *att = dynamic_cast<AttMeterSigDefaultLog*>(element);
        assert( att );
        if (attrType == "meterCount") {
            att->SetMeterCount(att->StrToInt(attrValue));
            return true;
        }
        if (attrType == "meterUnit") {
            att->SetMeterUnit(att->StrToInt(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_METERSIGDEFAULTVIS ) ) {
        AttMeterSigDefaultVis *att = dynamic_cast<AttMeterSigDefaultVis*>(element);
        assert( att );
        if (attrType == "meterRend") {
            att->SetMeterRend(att->StrToStr(attrValue));
            return true;
        }
        if (attrType == "meterShowchange") {
            att->SetMeterShowchange(att->StrToStr(attrValue));
            return true;
        }
        if (attrType == "meterSym") {
            att->SetMeterSym(att->StrToMeterSign(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_METERCONFORMANCE ) ) {
        AttMeterconformance *att = dynamic_cast<AttMeterconformance*>(element);
        assert( att );
        if (attrType == "metcon") {
            att->SetMetcon(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_METERCONFORMANCEBAR ) ) {
        AttMeterconformanceBar *att = dynamic_cast<AttMeterconformanceBar*>(element);
        assert( att );
        if (attrType == "metcon") {
            att->SetMetcon(att->StrToStr(attrValue));
            return true;
        }
        if (attrType == "control") {
            att->SetControl(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_MMTEMPO ) ) {
        AttMmtempo *att = dynamic_cast<AttMmtempo*>(element);
        assert( att );
        if (attrType == "mm") {
            att->SetMm(att->StrToStr(attrValue));
            return true;
        }
        if (attrType == "mmUnit") {
            att->SetMmUnit(att->StrToStr(attrValue));
            return true;
        }
        if (attrType == "mmDots") {
            att->SetMmDots(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_MULTINUMMEASURES ) ) {
        AttMultinummeasures *att = dynamic_cast<AttMultinummeasures*>(element);
        assert( att );
        if (attrType == "multiNumber") {
            att->SetMultiNumber(att->StrToBool(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_NAME ) ) {
        AttName *att = dynamic_cast<AttName*>(element);
        assert( att );
        if (attrType == "nymref") {
            att->SetNymref(att->StrToStr(attrValue));
            return true;
        }
        if (attrType == "role") {
            att->SetRole(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_NOTATIONSTYLE ) ) {
        AttNotationstyle *att = dynamic_cast<AttNotationstyle*>(element);
        assert( att );
        if (attrType == "musicName") {
            att->SetMusicName(att->StrToStr(attrValue));
            return true;
        }
        if (attrType == "musicSize") {
            att->SetMusicSize(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_NOTEGES ) ) {
        AttNoteGes *att = dynamic_cast<AttNoteGes*>(element);
        assert( att );
        if (attrType == "octGes") {
            att->SetOctGes(att->StrToStr(attrValue));
            return true;
        }
        if (attrType == "pnameGes") {
            att->SetPnameGes(att->StrToStr(attrValue));
            return true;
        }
        if (attrType == "pnum") {
            att->SetPnum(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_NOTEHEADS ) ) {
        AttNoteheads *att = dynamic_cast<AttNoteheads*>(element);
        assert( att );
        if (attrType == "headColor") {
            att->SetHeadColor(att->StrToStr(attrValue));
            return true;
        }
        if (attrType == "headFill") {
            att->SetHeadFill(att->StrToStr(attrValue));
            return true;
        }
        if (attrType == "headFillcolor") {
            att->SetHeadFillcolor(att->StrToStr(attrValue));
            return true;
        }
        if (attrType == "headMod") {
            att->SetHeadMod(att->StrToStr(attrValue));
            return true;
        }
        if (attrType == "headRotation") {
            att->SetHeadRotation(att->StrToStr(attrValue));
            return true;
        }
        if (attrType == "headShape") {
            att->SetHeadShape(att->StrToStr(attrValue));
            return true;
        }
        if (attrType == "headVisible") {
            att->SetHeadVisible(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_OCTAVE ) ) {
        AttOctave *att = dynamic_cast<AttOctave*>(element);
        assert( att );
        if (attrType == "oct") {
            att->SetOct(att->StrToInt(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_OCTAVEDEFAULT ) ) {
        AttOctavedefault *att = dynamic_cast<AttOctavedefault*>(element);
        assert( att );
        if (attrType == "octaveDefault") {
            att->SetOctaveDefault(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_OCTAVEDISPLACEMENT ) ) {
        AttOctavedisplacement *att = dynamic_cast<AttOctavedisplacement*>(element);
        assert( att );
        if (attrType == "dis") {
            att->SetDis(att->StrToOctaveDis(attrValue));
            return true;
        }
        if (attrType == "disPlace") {
            att->SetDisPlace(att->StrToPlace(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_ONELINESTAFF ) ) {
        AttOnelinestaff *att = dynamic_cast<AttOnelinestaff*>(element);
        assert( att );
        if (attrType == "ontheline") {
            att->SetOntheline(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_OPTIMIZATION ) ) {
        AttOptimization *att = dynamic_cast<AttOptimization*>(element);
        assert( att );
        if (attrType == "optimize") {
            att->SetOptimize(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_PADLOG ) ) {
        AttPadLog *att = dynamic_cast<AttPadLog*>(element);
        assert( att );
        if (attrType == "num") {
            att->SetNum(att->StrToInt(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_PAGES ) ) {
        AttPages *att = dynamic_cast<AttPages*>(element);
        assert( att );
        if (attrType == "pageHeight") {
            att->SetPageHeight(att->StrToStr(attrValue));
            return true;
        }
        if (attrType == "pageWidth") {
            att->SetPageWidth(att->StrToStr(attrValue));
            return true;
        }
        if (attrType == "pageTopmar") {
            att->SetPageTopmar(att->StrToStr(attrValue));
            return true;
        }
        if (attrType == "pageBotmar") {
            att->SetPageBotmar(att->StrToStr(attrValue));
            return true;
        }
        if (attrType == "pageLeftmar") {
            att->SetPageLeftmar(att->StrToStr(attrValue));
            return true;
        }
        if (attrType == "pageRightmar") {
            att->SetPageRightmar(att->StrToStr(attrValue));
            return true;
        }
        if (attrType == "pagePanels") {
            att->SetPagePanels(att->StrToStr(attrValue));
            return true;
        }
        if (attrType == "pageScale") {
            att->SetPageScale(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_PBVIS ) ) {
        AttPbVis *att = dynamic_cast<AttPbVis*>(element);
        assert( att );
        if (attrType == "folium") {
            att->SetFolium(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_PITCH ) ) {
        AttPitch *att = dynamic_cast<AttPitch*>(element);
        assert( att );
        if (attrType == "pname") {
            att->SetPname(att->StrToPitchName(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_PLACEMENT ) ) {
        AttPlacement *att = dynamic_cast<AttPlacement*>(element);
        assert( att );
        if (attrType == "place") {
            att->SetPlace(att->StrToStaffRel(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_PLIST ) ) {
        AttPlist *att = dynamic_cast<AttPlist*>(element);
        assert( att );
        if (attrType == "plist") {
            att->SetPlist(att->StrToStr(attrValue));
            return true;
        }
        if (attrType == "evaluate") {
            att->SetEvaluate(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_POINTING ) ) {
        AttPointing *att = dynamic_cast<AttPointing*>(element);
        assert( att );
        if (attrType == "actuate") {
            att->SetActuate(att->StrToStr(attrValue));
            return true;
        }
        if (attrType == "role") {
            att->SetRole(att->StrToStr(attrValue));
            return true;
        }
        if (attrType == "show") {
            att->SetShow(att->StrToStr(attrValue));
            return true;
        }
        if (attrType == "target") {
            att->SetTarget(att->StrToStr(attrValue));
            return true;
        }
        if (attrType == "targettype") {
            att->SetTargettype(att->StrToStr(attrValue));
            return true;
        }
        if (attrType == "title") {
            att->SetTitle(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_QUANTITY ) ) {
        AttQuantity *att = dynamic_cast<AttQuantity*>(element);
        assert( att );
        if (attrType == "quantityDbl") {
            att->SetQuantity(att->StrToDbl(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_RELATIVESIZE ) ) {
        AttRelativesize *att = dynamic_cast<AttRelativesize*>(element);
        assert( att );
        if (attrType == "size") {
            att->SetSize(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_RESPONSIBILITY ) ) {
        AttResponsibility *att = dynamic_cast<AttResponsibility*>(element);
        assert( att );
        if (attrType == "resp") {
            att->SetResp(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_SBVIS ) ) {
        AttSbVis *att = dynamic_cast<AttSbVis*>(element);
        assert( att );
        if (attrType == "form") {
            att->SetForm(att->StrToBarRendition(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_SCALABLE ) ) {
        AttScalable *att = dynamic_cast<AttScalable*>(element);
        assert( att );
        if (attrType == "scale") {
            att->SetScale(att->StrToPercent(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_SCOREDEFGES ) ) {
        AttScoreDefGes *att = dynamic_cast<AttScoreDefGes*>(element);
        assert( att );
        if (attrType == "tunePname") {
            att->SetTunePname(att->StrToStr(attrValue));
            return true;
        }
        if (attrType == "tuneHzDbl") {
            att->SetTuneHz(att->StrToDbl(attrValue));
            return true;
        }
        if (attrType == "tuneTemper") {
            att->SetTuneTemper(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_SCOREDEFVIS ) ) {
        AttScoreDefVis *att = dynamic_cast<AttScoreDefVis*>(element);
        assert( att );
        if (attrType == "vuHeight") {
            att->SetVuHeight(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_SECTIONVIS ) ) {
        AttSectionVis *att = dynamic_cast<AttSectionVis*>(element);
        assert( att );
        if (attrType == "restart") {
            att->SetRestart(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_SEQUENCE ) ) {
        AttSequence *att = dynamic_cast<AttSequence*>(element);
        assert( att );
        if (attrType == "seqInt") {
            att->SetSeq(att->StrToInt(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_SLASHCOUNT ) ) {
        AttSlashcount *att = dynamic_cast<AttSlashcount*>(element);
        assert( att );
        if (attrType == "slash") {
            att->SetSlash(att->StrToInt(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_SLURPRESENT ) ) {
        AttSlurpresent *att = dynamic_cast<AttSlurpresent*>(element);
        assert( att );
        if (attrType == "slur") {
            att->SetSlur(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_SPACEVIS ) ) {
        AttSpaceVis *att = dynamic_cast<AttSpaceVis*>(element);
        assert( att );
        if (attrType == "compressable") {
            att->SetCompressable(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_SPACING ) ) {
        AttSpacing *att = dynamic_cast<AttSpacing*>(element);
        assert( att );
        if (attrType == "spacingPackexpDbl") {
            att->SetSpacingPackexp(att->StrToDbl(attrValue));
            return true;
        }
        if (attrType == "spacingPackfactDbl") {
            att->SetSpacingPackfact(att->StrToDbl(attrValue));
            return true;
        }
        if (attrType == "spacingStaff") {
            att->SetSpacingStaff(att->StrToStr(attrValue));
            return true;
        }
        if (attrType == "spacingSystem") {
            att->SetSpacingSystem(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_STAFFLOG ) ) {
        AttStaffLog *att = dynamic_cast<AttStaffLog*>(element);
        assert( att );
        if (attrType == "def") {
            att->SetDef(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_STAFFDEFVIS ) ) {
        AttStaffDefVis *att = dynamic_cast<AttStaffDefVis*>(element);
        assert( att );
        if (attrType == "gridShow") {
            att->SetGridShow(att->StrToBool(attrValue));
            return true;
        }
        if (attrType == "layerscheme") {
            att->SetLayerscheme(att->StrToLayerscheme(attrValue));
            return true;
        }
        if (attrType == "linesInt") {
            att->SetLines(att->StrToInt(attrValue));
            return true;
        }
        if (attrType == "linesColor") {
            att->SetLinesColor(att->StrToStr(attrValue));
            return true;
        }
        if (attrType == "linesVisible") {
            att->SetLinesVisible(att->StrToBool(attrValue));
            return true;
        }
        if (attrType == "spacing") {
            att->SetSpacing(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_STAFFGRPVIS ) ) {
        AttStaffGrpVis *att = dynamic_cast<AttStaffGrpVis*>(element);
        assert( att );
        if (attrType == "barthru") {
            att->SetBarthru(att->StrToBool(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_STAFFGROUPINGSYM ) ) {
        AttStaffgroupingsym *att = dynamic_cast<AttStaffgroupingsym*>(element);
        assert( att );
        if (attrType == "symbol") {
            att->SetSymbol(att->StrToSymbol(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_STAFFIDENT ) ) {
        AttStaffident *att = dynamic_cast<AttStaffident*>(element);
        assert( att );
        if (attrType == "staff") {
            att->SetStaff(att->StrToInt(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_STAFFLOC ) ) {
        AttStaffloc *att = dynamic_cast<AttStaffloc*>(element);
        assert( att );
        if (attrType == "loc") {
            att->SetLoc(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_STAFFLOCPITCHED ) ) {
        AttStafflocPitched *att = dynamic_cast<AttStafflocPitched*>(element);
        assert( att );
        if (attrType == "ploc") {
            att->SetPloc(att->StrToPitchName(attrValue));
            return true;
        }
        if (attrType == "oloc") {
            att->SetOloc(att->StrToInt(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_STARTENDID ) ) {
        AttStartendid *att = dynamic_cast<AttStartendid*>(element);
        assert( att );
        if (attrType == "endid") {
            att->SetEndid(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_STARTID ) ) {
        AttStartid *att = dynamic_cast<AttStartid*>(element);
        assert( att );
        if (attrType == "startid") {
            att->SetStartid(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_STEMS ) ) {
        AttStems *att = dynamic_cast<AttStems*>(element);
        assert( att );
        if (attrType == "stemDir") {
            att->SetStemDir(att->StrToStemDirection(attrValue));
            return true;
        }
        if (attrType == "stemLen") {
            att->SetStemLen(att->StrToInt(attrValue));
            return true;
        }
        if (attrType == "stemMod") {
            att->SetStemMod(att->StrToStemModifier(attrValue));
            return true;
        }
        if (attrType == "stemPos") {
            att->SetStemPos(att->StrToStemPosition(attrValue));
            return true;
        }
        if (attrType == "stemX") {
            att->SetStemX(att->StrToInt(attrValue));
            return true;
        }
        if (attrType == "stemY") {
            att->SetStemY(att->StrToInt(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_SYLLOG ) ) {
        AttSylLog *att = dynamic_cast<AttSylLog*>(element);
        assert( att );
        if (attrType == "con") {
            att->SetCon(att->StrToCon(attrValue));
            return true;
        }
        if (attrType == "wordpos") {
            att->SetWordpos(att->StrToWordPos(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_SYLTEXT ) ) {
        AttSyltext *att = dynamic_cast<AttSyltext*>(element);
        assert( att );
        if (attrType == "syl") {
            att->SetSyl(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_SYSTEMS ) ) {
        AttSystems *att = dynamic_cast<AttSystems*>(element);
        assert( att );
        if (attrType == "systemLeftline") {
            att->SetSystemLeftline(att->StrToStr(attrValue));
            return true;
        }
        if (attrType == "systemLeftmar") {
            att->SetSystemLeftmar(att->StrToStr(attrValue));
            return true;
        }
        if (attrType == "systemRightmar") {
            att->SetSystemRightmar(att->StrToStr(attrValue));
            return true;
        }
        if (attrType == "systemTopmar") {
            att->SetSystemTopmar(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_TEXTSTYLE ) ) {
        AttTextstyle *att = dynamic_cast<AttTextstyle*>(element);
        assert( att );
        if (attrType == "textFam") {
            att->SetTextFam(att->StrToStr(attrValue));
            return true;
        }
        if (attrType == "textName") {
            att->SetTextName(att->StrToStr(attrValue));
            return true;
        }
        if (attrType == "textSize") {
            att->SetTextSize(att->StrToStr(attrValue));
            return true;
        }
        if (attrType == "textStyle") {
            att->SetTextStyle(att->StrToStr(attrValue));
            return true;
        }
        if (attrType == "textWeight") {
            att->SetTextWeight(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_TIEPRESENT ) ) {
        AttTiepresent *att = dynamic_cast<AttTiepresent*>(element);
        assert( att );
        if (attrType == "tie") {
            att->SetTie(att->StrToTie(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_TIMESTAMPMUSICAL ) ) {
        AttTimestampMusical *att = dynamic_cast<AttTimestampMusical*>(element);
        assert( att );
        if (attrType == "tstamp") {
            att->SetTstamp(att->StrToDbl(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_TIMESTAMPPERFORMED ) ) {
        AttTimestampPerformed *att = dynamic_cast<AttTimestampPerformed*>(element);
        assert( att );
        if (attrType == "tstampGes") {
            att->SetTstampGes(att->StrToStr(attrValue));
            return true;
        }
        if (attrType == "tstampReal") {
            att->SetTstampReal(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_TIMESTAMP2MUSICAL ) ) {
        AttTimestamp2Musical *att = dynamic_cast<AttTimestamp2Musical*>(element);
        assert( att );
        if (attrType == "tstamp2") {
            att->SetTstamp2(att->StrToTstamp2(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_TRANSPOSITION ) ) {
        AttTransposition *att = dynamic_cast<AttTransposition*>(element);
        assert( att );
        if (attrType == "transDiatDbl") {
            att->SetTransDiat(att->StrToDbl(attrValue));
            return true;
        }
        if (attrType == "transSemiDbl") {
            att->SetTransSemi(att->StrToDbl(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_TUPLETPRESENT ) ) {
        AttTupletpresent *att = dynamic_cast<AttTupletpresent*>(element);
        assert( att );
        if (attrType == "tuplet") {
            att->SetTuplet(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_TYPED ) ) {
        AttTyped *att = dynamic_cast<AttTyped*>(element);
        assert( att );
        if (attrType == "type") {
            att->SetType(att->StrToStr(attrValue));
            return true;
        }
        if (attrType == "subtype") {
            att->SetSubtype(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_TYPOGRAPHY ) ) {
        AttTypography *att = dynamic_cast<AttTypography*>(element);
        assert( att );
        if (attrType == "fontfam") {
            att->SetFontfam(att->StrToStr(attrValue));
            return true;
        }
        if (attrType == "fontname") {
            att->SetFontname(att->StrToStr(attrValue));
            return true;
        }
        if (attrType == "fontsizeDbl") {
            att->SetFontsize(att->StrToDbl(attrValue));
            return true;
        }
        if (attrType == "fontstyle") {
            att->SetFontstyle(att->StrToFontstyle(attrValue));
            return true;
        }
        if (attrType == "fontweight") {
            att->SetFontweight(att->StrToFontweight(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_VISIBILITY ) ) {
        AttVisibility *att = dynamic_cast<AttVisibility*>(element);
        assert( att );
        if (attrType == "visible") {
            att->SetVisible(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_VISUALOFFSETHO ) ) {
        AttVisualoffsetHo *att = dynamic_cast<AttVisualoffsetHo*>(element);
        assert( att );
        if (attrType == "ho") {
            att->SetHo(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_VISUALOFFSETTO ) ) {
        AttVisualoffsetTo *att = dynamic_cast<AttVisualoffsetTo*>(element);
        assert( att );
        if (attrType == "to") {
            att->SetTo(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_VISUALOFFSETVO ) ) {
        AttVisualoffsetVo *att = dynamic_cast<AttVisualoffsetVo*>(element);
        assert( att );
        if (attrType == "vo") {
            att->SetVo(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_VISUALOFFSET2HO ) ) {
        AttVisualoffset2Ho *att = dynamic_cast<AttVisualoffset2Ho*>(element);
        assert( att );
        if (attrType == "startho") {
            att->SetStartho(att->StrToStr(attrValue));
            return true;
        }
        if (attrType == "endho") {
            att->SetEndho(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_VISUALOFFSET2TO ) ) {
        AttVisualoffset2To *att = dynamic_cast<AttVisualoffset2To*>(element);
        assert( att );
        if (attrType == "startto") {
            att->SetStartto(att->StrToStr(attrValue));
            return true;
        }
        if (attrType == "endto") {
            att->SetEndto(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_VISUALOFFSET2VO ) ) {
        AttVisualoffset2Vo *att = dynamic_cast<AttVisualoffset2Vo*>(element);
        assert( att );
        if (attrType == "startvo") {
            att->SetStartvo(att->StrToStr(attrValue));
            return true;
        }
        if (attrType == "endvo") {
            att->SetEndvo(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_WHITESPACE ) ) {
        AttWhitespace *att = dynamic_cast<AttWhitespace*>(element);
        assert( att );
        if (attrType == "space") {
            att->SetSpace(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_WIDTH ) ) {
        AttWidth *att = dynamic_cast<AttWidth*>(element);
        assert( att );
        if (attrType == "width") {
            att->SetWidth(att->StrToStr(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_XY ) ) {
        AttXy *att = dynamic_cast<AttXy*>(element);
        assert( att );
        if (attrType == "xDbl") {
            att->SetX(att->StrToDbl(attrValue));
            return true;
        }
        if (attrType == "yDbl") {
            att->SetY(att->StrToDbl(attrValue));
            return true;
        }
    }
    if (element->HasAttClass( ATT_XY2 ) ) {
        AttXy2 *att = dynamic_cast<AttXy2*>(element);
        assert( att );
        if (attrType == "x2Dbl") {
            att->SetX2(att->StrToDbl(attrValue));
            return true;
        }
        if (attrType == "y2Dbl") {
            att->SetY2(att->StrToDbl(attrValue));
            return true;
        }
    }

    return false;
}

void Att::GetShared( Object *element, ArrayOfStrAttr *attributes ) {
    if (element->HasAttClass( ATT_ACCIDLOG ) ) {
        AttAccidLog *att = dynamic_cast<AttAccidLog*>(element);
        assert( att );
        if (att->HasFunc()) {
            attributes->push_back(std::make_pair("func", att->FuncToStr(att->GetFunc())));
        }
    }
    if (element->HasAttClass( ATT_ACCIDENTAL ) ) {
        AttAccidental *att = dynamic_cast<AttAccidental*>(element);
        assert( att );
        if (att->HasAccid()) {
            attributes->push_back(std::make_pair("accid", att->AccidentalExplicitToStr(att->GetAccid())));
        }
    }
    if (element->HasAttClass( ATT_ACCIDENTALPERFORMED ) ) {
        AttAccidentalPerformed *att = dynamic_cast<AttAccidentalPerformed*>(element);
        assert( att );
        if (att->HasAccidGes()) {
            attributes->push_back(std::make_pair("accidGes", att->StrToStr(att->GetAccidGes())));
        }
    }
    if (element->HasAttClass( ATT_ARTICULATION ) ) {
        AttArticulation *att = dynamic_cast<AttArticulation*>(element);
        assert( att );
        if (att->HasArtic()) {
            attributes->push_back(std::make_pair("artic", att->StrToStr(att->GetArtic())));
        }
    }
    if (element->HasAttClass( ATT_ARTICULATIONPERFORMED ) ) {
        AttArticulationPerformed *att = dynamic_cast<AttArticulationPerformed*>(element);
        assert( att );
        if (att->HasArticGes()) {
            attributes->push_back(std::make_pair("articGes", att->StrToStr(att->GetArticGes())));
        }
    }
    if (element->HasAttClass( ATT_AUGMENTDOTS ) ) {
        AttAugmentdots *att = dynamic_cast<AttAugmentdots*>(element);
        assert( att );
        if (att->HasDots()) {
            attributes->push_back(std::make_pair("dots", att->IntToStr(att->GetDots())));
        }
    }
    if (element->HasAttClass( ATT_AUTHORIZED ) ) {
        AttAuthorized *att = dynamic_cast<AttAuthorized*>(element);
        assert( att );
        if (att->HasAuthority()) {
            attributes->push_back(std::make_pair("authority", att->StrToStr(att->GetAuthority())));
        }
        if (att->HasAuthURI()) {
            attributes->push_back(std::make_pair("authURI", att->StrToStr(att->GetAuthURI())));
        }
    }
    if (element->HasAttClass( ATT_BARLINELOG ) ) {
        AttBarLineLog *att = dynamic_cast<AttBarLineLog*>(element);
        assert( att );
        if (att->HasForm()) {
            attributes->push_back(std::make_pair("form", att->BarRenditionToStr(att->GetForm())));
        }
    }
    if (element->HasAttClass( ATT_BARPLACEMENT ) ) {
        AttBarplacement *att = dynamic_cast<AttBarplacement*>(element);
        assert( att );
        if (att->HasBarplace()) {
            attributes->push_back(std::make_pair("barplace", att->StrToStr(att->GetBarplace())));
        }
        if (att->HasTaktplace()) {
            attributes->push_back(std::make_pair("taktplace", att->StrToStr(att->GetTaktplace())));
        }
    }
    if (element->HasAttClass( ATT_BEAMINGVIS ) ) {
        AttBeamingVis *att = dynamic_cast<AttBeamingVis*>(element);
        assert( att );
        if (att->HasBeamColor()) {
            attributes->push_back(std::make_pair("beamColor", att->StrToStr(att->GetBeamColor())));
        }
        if (att->HasBeamRend()) {
            attributes->push_back(std::make_pair("beamRend", att->StrToStr(att->GetBeamRend())));
        }
        if (att->HasBeamSlope()) {
            attributes->push_back(std::make_pair("beamSlopeDbl", att->DblToStr(att->GetBeamSlope())));
        }
    }
    if (element->HasAttClass( ATT_BIBL ) ) {
        AttBibl *att = dynamic_cast<AttBibl*>(element);
        assert( att );
        if (att->HasAnalog()) {
            attributes->push_back(std::make_pair("analog", att->StrToStr(att->GetAnalog())));
        }
    }
    if (element->HasAttClass( ATT_CALENDARED ) ) {
        AttCalendared *att = dynamic_cast<AttCalendared*>(element);
        assert( att );
        if (att->HasCalendar()) {
            attributes->push_back(std::make_pair("calendar", att->StrToStr(att->GetCalendar())));
        }
    }
    if (element->HasAttClass( ATT_CANONICAL ) ) {
        AttCanonical *att = dynamic_cast<AttCanonical*>(element);
        assert( att );
        if (att->HasCodedval()) {
            attributes->push_back(std::make_pair("codedval", att->StrToStr(att->GetCodedval())));
        }
    }
    if (element->HasAttClass( ATT_CHORDVIS ) ) {
        AttChordVis *att = dynamic_cast<AttChordVis*>(element);
        assert( att );
        if (att->HasCluster()) {
            attributes->push_back(std::make_pair("cluster", att->StrToStr(att->GetCluster())));
        }
    }
    if (element->HasAttClass( ATT_CLASSCODEIDENT ) ) {
        AttClasscodeident *att = dynamic_cast<AttClasscodeident*>(element);
        assert( att );
        if (att->HasClasscode()) {
            attributes->push_back(std::make_pair("classcode", att->StrToStr(att->GetClasscode())));
        }
    }
    if (element->HasAttClass( ATT_CLEFLOG ) ) {
        AttClefLog *att = dynamic_cast<AttClefLog*>(element);
        assert( att );
        if (att->HasCautionary()) {
            attributes->push_back(std::make_pair("cautionary", att->StrToStr(att->GetCautionary())));
        }
    }
    if (element->HasAttClass( ATT_CLEFFINGLOG ) ) {
        AttCleffingLog *att = dynamic_cast<AttCleffingLog*>(element);
        assert( att );
        if (att->HasClefShape()) {
            attributes->push_back(std::make_pair("clefShape", att->ClefShapeToStr(att->GetClefShape())));
        }
        if (att->HasClefLine()) {
            attributes->push_back(std::make_pair("clefLine", att->IntToStr(att->GetClefLine())));
        }
        if (att->HasClefDis()) {
            attributes->push_back(std::make_pair("clefDis", att->OctaveDisToStr(att->GetClefDis())));
        }
        if (att->HasClefDisPlace()) {
            attributes->push_back(std::make_pair("clefDisPlace", att->PlaceToStr(att->GetClefDisPlace())));
        }
    }
    if (element->HasAttClass( ATT_CLEFFINGVIS ) ) {
        AttCleffingVis *att = dynamic_cast<AttCleffingVis*>(element);
        assert( att );
        if (att->HasClefColor()) {
            attributes->push_back(std::make_pair("clefColor", att->StrToStr(att->GetClefColor())));
        }
        if (att->HasClefVisible()) {
            attributes->push_back(std::make_pair("clefVisible", att->StrToStr(att->GetClefVisible())));
        }
    }
    if (element->HasAttClass( ATT_CLEFSHAPE ) ) {
        AttClefshape *att = dynamic_cast<AttClefshape*>(element);
        assert( att );
        if (att->HasShape()) {
            attributes->push_back(std::make_pair("shape", att->ClefShapeToStr(att->GetShape())));
        }
    }
    if (element->HasAttClass( ATT_COLOR ) ) {
        AttColor *att = dynamic_cast<AttColor*>(element);
        assert( att );
        if (att->HasColor()) {
            attributes->push_back(std::make_pair("color", att->StrToStr(att->GetColor())));
        }
    }
    if (element->HasAttClass( ATT_COLORATION ) ) {
        AttColoration *att = dynamic_cast<AttColoration*>(element);
        assert( att );
        if (att->HasColored()) {
            attributes->push_back(std::make_pair("colored", att->BoolToStr(att->GetColored())));
        }
    }
    if (element->HasAttClass( ATT_COMMON ) ) {
        AttCommon *att = dynamic_cast<AttCommon*>(element);
        assert( att );
        if (att->HasN()) {
            attributes->push_back(std::make_pair("n", att->IntToStr(att->GetN())));
        }
    }
    if (element->HasAttClass( ATT_COMMONPART ) ) {
        AttCommonPart *att = dynamic_cast<AttCommonPart*>(element);
        assert( att );
        if (att->HasLabel()) {
            attributes->push_back(std::make_pair("label", att->StrToStr(att->GetLabel())));
        }
        if (att->HasBase()) {
            attributes->push_back(std::make_pair("base", att->StrToStr(att->GetBase())));
        }
    }
    if (element->HasAttClass( ATT_COORDINATED ) ) {
        AttCoordinated *att = dynamic_cast<AttCoordinated*>(element);
        assert( att );
        if (att->HasUlx()) {
            attributes->push_back(std::make_pair("ulxInt", att->IntToStr(att->GetUlx())));
        }
        if (att->HasUly()) {
            attributes->push_back(std::make_pair("ulyInt", att->IntToStr(att->GetUly())));
        }
        if (att->HasLrx()) {
            attributes->push_back(std::make_pair("lrxInt", att->IntToStr(att->GetLrx())));
        }
        if (att->HasLry()) {
            attributes->push_back(std::make_pair("lryInt", att->IntToStr(att->GetLry())));
        }
    }
    if (element->HasAttClass( ATT_CURVATURE ) ) {
        AttCurvature *att = dynamic_cast<AttCurvature*>(element);
        assert( att );
        if (att->HasBezier()) {
            attributes->push_back(std::make_pair("bezier", att->StrToStr(att->GetBezier())));
        }
        if (att->HasBulge()) {
            attributes->push_back(std::make_pair("bulge", att->DblToStr(att->GetBulge())));
        }
        if (att->HasCurvedir()) {
            attributes->push_back(std::make_pair("curvedir", att->CurvedirToStr(att->GetCurvedir())));
        }
    }
    if (element->HasAttClass( ATT_CURVEREND ) ) {
        AttCurverend *att = dynamic_cast<AttCurverend*>(element);
        assert( att );
        if (att->HasLform()) {
            attributes->push_back(std::make_pair("lform", att->StrToStr(att->GetLform())));
        }
        if (att->HasLwidth()) {
            attributes->push_back(std::make_pair("lwidth", att->StrToStr(att->GetLwidth())));
        }
    }
    if (element->HasAttClass( ATT_CUSTOSLOG ) ) {
        AttCustosLog *att = dynamic_cast<AttCustosLog*>(element);
        assert( att );
        if (att->HasTarget()) {
            attributes->push_back(std::make_pair("target", att->StrToStr(att->GetTarget())));
        }
    }
    if (element->HasAttClass( ATT_DATABLE ) ) {
        AttDatable *att = dynamic_cast<AttDatable*>(element);
        assert( att );
        if (att->HasEnddate()) {
            attributes->push_back(std::make_pair("enddate", att->StrToStr(att->GetEnddate())));
        }
        if (att->HasIsodate()) {
            attributes->push_back(std::make_pair("isodate", att->StrToStr(att->GetIsodate())));
        }
        if (att->HasNotafter()) {
            attributes->push_back(std::make_pair("notafter", att->StrToStr(att->GetNotafter())));
        }
        if (att->HasNotbefore()) {
            attributes->push_back(std::make_pair("notbefore", att->StrToStr(att->GetNotbefore())));
        }
        if (att->HasStartdate()) {
            attributes->push_back(std::make_pair("startdate", att->StrToStr(att->GetStartdate())));
        }
    }
    if (element->HasAttClass( ATT_DATAPOINTING ) ) {
        AttDatapointing *att = dynamic_cast<AttDatapointing*>(element);
        assert( att );
        if (att->HasData()) {
            attributes->push_back(std::make_pair("data", att->StrToStr(att->GetData())));
        }
    }
    if (element->HasAttClass( ATT_DECLARING ) ) {
        AttDeclaring *att = dynamic_cast<AttDeclaring*>(element);
        assert( att );
        if (att->HasDecls()) {
            attributes->push_back(std::make_pair("decls", att->StrToStr(att->GetDecls())));
        }
    }
    if (element->HasAttClass( ATT_DISTANCES ) ) {
        AttDistances *att = dynamic_cast<AttDistances*>(element);
        assert( att );
        if (att->HasDynamDist()) {
            attributes->push_back(std::make_pair("dynamDist", att->StrToStr(att->GetDynamDist())));
        }
        if (att->HasHarmDist()) {
            attributes->push_back(std::make_pair("harmDist", att->StrToStr(att->GetHarmDist())));
        }
        if (att->HasTextDist()) {
            attributes->push_back(std::make_pair("textDist", att->StrToStr(att->GetTextDist())));
        }
    }
    if (element->HasAttClass( ATT_DOTLOG ) ) {
        AttDotLog *att = dynamic_cast<AttDotLog*>(element);
        assert( att );
        if (att->HasForm()) {
            attributes->push_back(std::make_pair("form", att->BarRenditionToStr(att->GetForm())));
        }
    }
    if (element->HasAttClass( ATT_DURATIONADDITIVE ) ) {
        AttDurationAdditive *att = dynamic_cast<AttDurationAdditive*>(element);
        assert( att );
        if (att->HasDur()) {
            attributes->push_back(std::make_pair("dur", att->DurToStr(att->GetDur())));
        }
    }
    if (element->HasAttClass( ATT_DURATIONDEFAULT ) ) {
        AttDurationDefault *att = dynamic_cast<AttDurationDefault*>(element);
        assert( att );
        if (att->HasDurDefault()) {
            attributes->push_back(std::make_pair("durDefault", att->StrToStr(att->GetDurDefault())));
        }
        if (att->HasNumDefault()) {
            attributes->push_back(std::make_pair("numDefaultInt", att->IntToStr(att->GetNumDefault())));
        }
        if (att->HasNumbaseDefault()) {
            attributes->push_back(std::make_pair("numbaseDefaultInt", att->IntToStr(att->GetNumbaseDefault())));
        }
    }
    if (element->HasAttClass( ATT_DURATIONMUSICAL ) ) {
        AttDurationMusical *att = dynamic_cast<AttDurationMusical*>(element);
        assert( att );
        if (att->HasDur()) {
            attributes->push_back(std::make_pair("dur", att->DurToStr(att->GetDur())));
        }
    }
    if (element->HasAttClass( ATT_DURATIONPERFORMED ) ) {
        AttDurationPerformed *att = dynamic_cast<AttDurationPerformed*>(element);
        assert( att );
        if (att->HasDurGes()) {
            attributes->push_back(std::make_pair("durGes", att->DurToStr(att->GetDurGes())));
        }
    }
    if (element->HasAttClass( ATT_DURATIONRATIO ) ) {
        AttDurationRatio *att = dynamic_cast<AttDurationRatio*>(element);
        assert( att );
        if (att->HasNum()) {
            attributes->push_back(std::make_pair("num", att->IntToStr(att->GetNum())));
        }
        if (att->HasNumbase()) {
            attributes->push_back(std::make_pair("numbase", att->IntToStr(att->GetNumbase())));
        }
    }
    if (element->HasAttClass( ATT_ENCLOSINGCHARS ) ) {
        AttEnclosingchars *att = dynamic_cast<AttEnclosingchars*>(element);
        assert( att );
        if (att->HasEnclose()) {
            attributes->push_back(std::make_pair("enclose", att->StrToStr(att->GetEnclose())));
        }
    }
    if (element->HasAttClass( ATT_ENDINGS ) ) {
        AttEndings *att = dynamic_cast<AttEndings*>(element);
        assert( att );
        if (att->HasEndingRend()) {
            attributes->push_back(std::make_pair("endingRend", att->StrToStr(att->GetEndingRend())));
        }
    }
    if (element->HasAttClass( ATT_EXTENDER ) ) {
        AttExtender *att = dynamic_cast<AttExtender*>(element);
        assert( att );
        if (att->HasExtender()) {
            attributes->push_back(std::make_pair("extender", att->StrToStr(att->GetExtender())));
        }
    }
    if (element->HasAttClass( ATT_FERMATAPRESENT ) ) {
        AttFermatapresent *att = dynamic_cast<AttFermatapresent*>(element);
        assert( att );
        if (att->HasFermata()) {
            attributes->push_back(std::make_pair("fermata", att->PlaceToStr(att->GetFermata())));
        }
    }
    if (element->HasAttClass( ATT_FILING ) ) {
        AttFiling *att = dynamic_cast<AttFiling*>(element);
        assert( att );
        if (att->HasNonfiling()) {
            attributes->push_back(std::make_pair("nonfilingInt", att->IntToStr(att->GetNonfiling())));
        }
    }
    if (element->HasAttClass( ATT_GRPSYMLOG ) ) {
        AttGrpSymLog *att = dynamic_cast<AttGrpSymLog*>(element);
        assert( att );
        if (att->HasLevel()) {
            attributes->push_back(std::make_pair("levelInt", att->IntToStr(att->GetLevel())));
        }
    }
    if (element->HasAttClass( ATT_HANDIDENT ) ) {
        AttHandident *att = dynamic_cast<AttHandident*>(element);
        assert( att );
        if (att->HasHand()) {
            attributes->push_back(std::make_pair("hand", att->StrToStr(att->GetHand())));
        }
    }
    if (element->HasAttClass( ATT_HEIGHT ) ) {
        AttHeight *att = dynamic_cast<AttHeight*>(element);
        assert( att );
        if (att->HasHeight()) {
            attributes->push_back(std::make_pair("height", att->StrToStr(att->GetHeight())));
        }
    }
    if (element->HasAttClass( ATT_HORIZONTALALIGN ) ) {
        AttHorizontalalign *att = dynamic_cast<AttHorizontalalign*>(element);
        assert( att );
        if (att->HasHalign()) {
            attributes->push_back(std::make_pair("halign", att->StrToStr(att->GetHalign())));
        }
    }
    if (element->HasAttClass( ATT_INSTRUMENTIDENT ) ) {
        AttInstrumentident *att = dynamic_cast<AttInstrumentident*>(element);
        assert( att );
        if (att->HasInstr()) {
            attributes->push_back(std::make_pair("instr", att->StrToStr(att->GetInstr())));
        }
    }
    if (element->HasAttClass( ATT_INTERNETMEDIA ) ) {
        AttInternetmedia *att = dynamic_cast<AttInternetmedia*>(element);
        assert( att );
        if (att->HasMimetype()) {
            attributes->push_back(std::make_pair("mimetype", att->StrToStr(att->GetMimetype())));
        }
    }
    if (element->HasAttClass( ATT_JOINED ) ) {
        AttJoined *att = dynamic_cast<AttJoined*>(element);
        assert( att );
        if (att->HasJoin()) {
            attributes->push_back(std::make_pair("join", att->StrToStr(att->GetJoin())));
        }
    }
    if (element->HasAttClass( ATT_KEYSIGLOG ) ) {
        AttKeySigLog *att = dynamic_cast<AttKeySigLog*>(element);
        assert( att );
        if (att->HasMode()) {
            attributes->push_back(std::make_pair("mode", att->StrToStr(att->GetMode())));
        }
    }
    if (element->HasAttClass( ATT_KEYSIGDEFAULTLOG ) ) {
        AttKeySigDefaultLog *att = dynamic_cast<AttKeySigDefaultLog*>(element);
        assert( att );
        if (att->HasKeyAccid()) {
            attributes->push_back(std::make_pair("keyAccid", att->AccidentalImplicitToStr(att->GetKeyAccid())));
        }
        if (att->HasKeyMode()) {
            attributes->push_back(std::make_pair("keyMode", att->ModeToStr(att->GetKeyMode())));
        }
        if (att->HasKeyPname()) {
            attributes->push_back(std::make_pair("keyPname", att->PitchNameToStr(att->GetKeyPname())));
        }
        if (att->HasKeySig()) {
            attributes->push_back(std::make_pair("keySig", att->KeySignatureToStr(att->GetKeySig())));
        }
        if (att->HasKeySigMixed()) {
            attributes->push_back(std::make_pair("keySigMixed", att->StrToStr(att->GetKeySigMixed())));
        }
    }
    if (element->HasAttClass( ATT_KEYSIGDEFAULTVIS ) ) {
        AttKeySigDefaultVis *att = dynamic_cast<AttKeySigDefaultVis*>(element);
        assert( att );
        if (att->HasKeySigShow()) {
            attributes->push_back(std::make_pair("keySigShow", att->BoolToStr(att->GetKeySigShow())));
        }
        if (att->HasKeySigShowchange()) {
            attributes->push_back(std::make_pair("keySigShowchange", att->BoolToStr(att->GetKeySigShowchange())));
        }
    }
    if (element->HasAttClass( ATT_LABELSADDL ) ) {
        AttLabelsAddl *att = dynamic_cast<AttLabelsAddl*>(element);
        assert( att );
        if (att->HasLabelAbbr()) {
            attributes->push_back(std::make_pair("labelAbbr", att->StrToStr(att->GetLabelAbbr())));
        }
    }
    if (element->HasAttClass( ATT_LANG ) ) {
        AttLang *att = dynamic_cast<AttLang*>(element);
        assert( att );
        if (att->HasLang()) {
            attributes->push_back(std::make_pair("lang", att->StrToStr(att->GetLang())));
        }
        if (att->HasTranslit()) {
            attributes->push_back(std::make_pair("translit", att->StrToStr(att->GetTranslit())));
        }
    }
    if (element->HasAttClass( ATT_LAYERLOG ) ) {
        AttLayerLog *att = dynamic_cast<AttLayerLog*>(element);
        assert( att );
        if (att->HasDef()) {
            attributes->push_back(std::make_pair("def", att->StrToStr(att->GetDef())));
        }
    }
    if (element->HasAttClass( ATT_LAYERIDENT ) ) {
        AttLayerident *att = dynamic_cast<AttLayerident*>(element);
        assert( att );
        if (att->HasLayer()) {
            attributes->push_back(std::make_pair("layerInt", att->IntToStr(att->GetLayer())));
        }
    }
    if (element->HasAttClass( ATT_LINEVIS ) ) {
        AttLineVis *att = dynamic_cast<AttLineVis*>(element);
        assert( att );
        if (att->HasForm()) {
            attributes->push_back(std::make_pair("form", att->BarRenditionToStr(att->GetForm())));
        }
        if (att->HasWidth()) {
            attributes->push_back(std::make_pair("width", att->StrToStr(att->GetWidth())));
        }
        if (att->HasEndsym()) {
            attributes->push_back(std::make_pair("endsym", att->StrToStr(att->GetEndsym())));
        }
        if (att->HasEndsymsize()) {
            attributes->push_back(std::make_pair("endsymsize", att->StrToStr(att->GetEndsymsize())));
        }
        if (att->HasStartsym()) {
            attributes->push_back(std::make_pair("startsym", att->StrToStr(att->GetStartsym())));
        }
        if (att->HasStartsymsize()) {
            attributes->push_back(std::make_pair("startsymsize", att->StrToStr(att->GetStartsymsize())));
        }
    }
    if (element->HasAttClass( ATT_LINELOC ) ) {
        AttLineloc *att = dynamic_cast<AttLineloc*>(element);
        assert( att );
        if (att->HasLine()) {
            attributes->push_back(std::make_pair("line", att->IntToStr(att->GetLine())));
        }
    }
    if (element->HasAttClass( ATT_LINEREND ) ) {
        AttLinerend *att = dynamic_cast<AttLinerend*>(element);
        assert( att );
        if (att->HasLendsym()) {
            attributes->push_back(std::make_pair("lendsym", att->StrToStr(att->GetLendsym())));
        }
        if (att->HasLendsymsize()) {
            attributes->push_back(std::make_pair("lendsymsize", att->StrToStr(att->GetLendsymsize())));
        }
        if (att->HasLstartsym()) {
            attributes->push_back(std::make_pair("lstartsym", att->StrToStr(att->GetLstartsym())));
        }
        if (att->HasLstartsymsize()) {
            attributes->push_back(std::make_pair("lstartsymsize", att->StrToStr(att->GetLstartsymsize())));
        }
    }
    if (element->HasAttClass( ATT_LINERENDBASE ) ) {
        AttLinerendBase *att = dynamic_cast<AttLinerendBase*>(element);
        assert( att );
        if (att->HasLform()) {
            attributes->push_back(std::make_pair("lform", att->StrToStr(att->GetLform())));
        }
        if (att->HasLwidth()) {
            attributes->push_back(std::make_pair("lwidth", att->StrToStr(att->GetLwidth())));
        }
    }
    if (element->HasAttClass( ATT_LYRICSTYLE ) ) {
        AttLyricstyle *att = dynamic_cast<AttLyricstyle*>(element);
        assert( att );
        if (att->HasLyricAlign()) {
            attributes->push_back(std::make_pair("lyricAlign", att->StrToStr(att->GetLyricAlign())));
        }
        if (att->HasLyricFam()) {
            attributes->push_back(std::make_pair("lyricFam", att->StrToStr(att->GetLyricFam())));
        }
        if (att->HasLyricName()) {
            attributes->push_back(std::make_pair("lyricName", att->StrToStr(att->GetLyricName())));
        }
        if (att->HasLyricSize()) {
            attributes->push_back(std::make_pair("lyricSize", att->StrToStr(att->GetLyricSize())));
        }
        if (att->HasLyricStyle()) {
            attributes->push_back(std::make_pair("lyricStyle", att->StrToStr(att->GetLyricStyle())));
        }
        if (att->HasLyricWeight()) {
            attributes->push_back(std::make_pair("lyricWeight", att->StrToStr(att->GetLyricWeight())));
        }
    }
    if (element->HasAttClass( ATT_MEASURELOG ) ) {
        AttMeasureLog *att = dynamic_cast<AttMeasureLog*>(element);
        assert( att );
        if (att->HasLeft()) {
            attributes->push_back(std::make_pair("left", att->BarRenditionToStr(att->GetLeft())));
        }
        if (att->HasRight()) {
            attributes->push_back(std::make_pair("right", att->BarRenditionToStr(att->GetRight())));
        }
    }
    if (element->HasAttClass( ATT_MEASUREMENT ) ) {
        AttMeasurement *att = dynamic_cast<AttMeasurement*>(element);
        assert( att );
        if (att->HasUnit()) {
            attributes->push_back(std::make_pair("unit", att->IntToStr(att->GetUnit())));
        }
    }
    if (element->HasAttClass( ATT_MEASURENUMBERS ) ) {
        AttMeasurenumbers *att = dynamic_cast<AttMeasurenumbers*>(element);
        assert( att );
        if (att->HasMnumVisible()) {
            attributes->push_back(std::make_pair("mnumVisible", att->StrToStr(att->GetMnumVisible())));
        }
    }
    if (element->HasAttClass( ATT_MEDIABOUNDS ) ) {
        AttMediabounds *att = dynamic_cast<AttMediabounds*>(element);
        assert( att );
        if (att->HasBegin()) {
            attributes->push_back(std::make_pair("begin", att->StrToStr(att->GetBegin())));
        }
        if (att->HasEnd()) {
            attributes->push_back(std::make_pair("end", att->StrToStr(att->GetEnd())));
        }
        if (att->HasBetype()) {
            attributes->push_back(std::make_pair("betype", att->StrToStr(att->GetBetype())));
        }
    }
    if (element->HasAttClass( ATT_MEDIUM ) ) {
        AttMedium *att = dynamic_cast<AttMedium*>(element);
        assert( att );
        if (att->HasMedium()) {
            attributes->push_back(std::make_pair("medium", att->StrToStr(att->GetMedium())));
        }
    }
    if (element->HasAttClass( ATT_MEIVERSION ) ) {
        AttMeiversion *att = dynamic_cast<AttMeiversion*>(element);
        assert( att );
        if (att->HasMeiversion()) {
            attributes->push_back(std::make_pair("meiversion", att->StrToStr(att->GetMeiversion())));
        }
    }
    if (element->HasAttClass( ATT_MENSURLOG ) ) {
        AttMensurLog *att = dynamic_cast<AttMensurLog*>(element);
        assert( att );
        if (att->HasDot()) {
            attributes->push_back(std::make_pair("dot", att->BoolToStr(att->GetDot())));
        }
        if (att->HasSign()) {
            attributes->push_back(std::make_pair("sign", att->MensurationSignToStr(att->GetSign())));
        }
    }
    if (element->HasAttClass( ATT_METERSIGLOG ) ) {
        AttMeterSigLog *att = dynamic_cast<AttMeterSigLog*>(element);
        assert( att );
        if (att->HasCount()) {
            attributes->push_back(std::make_pair("count", att->IntToStr(att->GetCount())));
        }
        if (att->HasSym()) {
            attributes->push_back(std::make_pair("sym", att->MeterSignToStr(att->GetSym())));
        }
        if (att->HasUnit()) {
            attributes->push_back(std::make_pair("unit", att->IntToStr(att->GetUnit())));
        }
    }
    if (element->HasAttClass( ATT_METERSIGVIS ) ) {
        AttMeterSigVis *att = dynamic_cast<AttMeterSigVis*>(element);
        assert( att );
        if (att->HasForm()) {
            attributes->push_back(std::make_pair("form", att->BarRenditionToStr(att->GetForm())));
        }
    }
    if (element->HasAttClass( ATT_METERSIGDEFAULTLOG ) ) {
        AttMeterSigDefaultLog *att = dynamic_cast<AttMeterSigDefaultLog*>(element);
        assert( att );
        if (att->HasMeterCount()) {
            attributes->push_back(std::make_pair("meterCount", att->IntToStr(att->GetMeterCount())));
        }
        if (att->HasMeterUnit()) {
            attributes->push_back(std::make_pair("meterUnit", att->IntToStr(att->GetMeterUnit())));
        }
    }
    if (element->HasAttClass( ATT_METERSIGDEFAULTVIS ) ) {
        AttMeterSigDefaultVis *att = dynamic_cast<AttMeterSigDefaultVis*>(element);
        assert( att );
        if (att->HasMeterRend()) {
            attributes->push_back(std::make_pair("meterRend", att->StrToStr(att->GetMeterRend())));
        }
        if (att->HasMeterShowchange()) {
            attributes->push_back(std::make_pair("meterShowchange", att->StrToStr(att->GetMeterShowchange())));
        }
        if (att->HasMeterSym()) {
            attributes->push_back(std::make_pair("meterSym", att->MeterSignToStr(att->GetMeterSym())));
        }
    }
    if (element->HasAttClass( ATT_METERCONFORMANCE ) ) {
        AttMeterconformance *att = dynamic_cast<AttMeterconformance*>(element);
        assert( att );
        if (att->HasMetcon()) {
            attributes->push_back(std::make_pair("metcon", att->StrToStr(att->GetMetcon())));
        }
    }
    if (element->HasAttClass( ATT_METERCONFORMANCEBAR ) ) {
        AttMeterconformanceBar *att = dynamic_cast<AttMeterconformanceBar*>(element);
        assert( att );
        if (att->HasMetcon()) {
            attributes->push_back(std::make_pair("metcon", att->StrToStr(att->GetMetcon())));
        }
        if (att->HasControl()) {
            attributes->push_back(std::make_pair("control", att->StrToStr(att->GetControl())));
        }
    }
    if (element->HasAttClass( ATT_MMTEMPO ) ) {
        AttMmtempo *att = dynamic_cast<AttMmtempo*>(element);
        assert( att );
        if (att->HasMm()) {
            attributes->push_back(std::make_pair("mm", att->StrToStr(att->GetMm())));
        }
        if (att->HasMmUnit()) {
            attributes->push_back(std::make_pair("mmUnit", att->StrToStr(att->GetMmUnit())));
        }
        if (att->HasMmDots()) {
            attributes->push_back(std::make_pair("mmDots", att->StrToStr(att->GetMmDots())));
        }
    }
    if (element->HasAttClass( ATT_MULTINUMMEASURES ) ) {
        AttMultinummeasures *att = dynamic_cast<AttMultinummeasures*>(element);
        assert( att );
        if (att->HasMultiNumber()) {
            attributes->push_back(std::make_pair("multiNumber", att->BoolToStr(att->GetMultiNumber())));
        }
    }
    if (element->HasAttClass( ATT_NAME ) ) {
        AttName *att = dynamic_cast<AttName*>(element);
        assert( att );
        if (att->HasNymref()) {
            attributes->push_back(std::make_pair("nymref", att->StrToStr(att->GetNymref())));
        }
        if (att->HasRole()) {
            attributes->push_back(std::make_pair("role", att->StrToStr(att->GetRole())));
        }
    }
    if (element->HasAttClass( ATT_NOTATIONSTYLE ) ) {
        AttNotationstyle *att = dynamic_cast<AttNotationstyle*>(element);
        assert( att );
        if (att->HasMusicName()) {
            attributes->push_back(std::make_pair("musicName", att->StrToStr(att->GetMusicName())));
        }
        if (att->HasMusicSize()) {
            attributes->push_back(std::make_pair("musicSize", att->StrToStr(att->GetMusicSize())));
        }
    }
    if (element->HasAttClass( ATT_NOTEGES ) ) {
        AttNoteGes *att = dynamic_cast<AttNoteGes*>(element);
        assert( att );
        if (att->HasOctGes()) {
            attributes->push_back(std::make_pair("octGes", att->StrToStr(att->GetOctGes())));
        }
        if (att->HasPnameGes()) {
            attributes->push_back(std::make_pair("pnameGes", att->StrToStr(att->GetPnameGes())));
        }
        if (att->HasPnum()) {
            attributes->push_back(std::make_pair("pnum", att->StrToStr(att->GetPnum())));
        }
    }
    if (element->HasAttClass( ATT_NOTEHEADS ) ) {
        AttNoteheads *att = dynamic_cast<AttNoteheads*>(element);
        assert( att );
        if (att->HasHeadColor()) {
            attributes->push_back(std::make_pair("headColor", att->StrToStr(att->GetHeadColor())));
        }
        if (att->HasHeadFill()) {
            attributes->push_back(std::make_pair("headFill", att->StrToStr(att->GetHeadFill())));
        }
        if (att->HasHeadFillcolor()) {
            attributes->push_back(std::make_pair("headFillcolor", att->StrToStr(att->GetHeadFillcolor())));
        }
        if (att->HasHeadMod()) {
            attributes->push_back(std::make_pair("headMod", att->StrToStr(att->GetHeadMod())));
        }
        if (att->HasHeadRotation()) {
            attributes->push_back(std::make_pair("headRotation", att->StrToStr(att->GetHeadRotation())));
        }
        if (att->HasHeadShape()) {
            attributes->push_back(std::make_pair("headShape", att->StrToStr(att->GetHeadShape())));
        }
        if (att->HasHeadVisible()) {
            attributes->push_back(std::make_pair("headVisible", att->StrToStr(att->GetHeadVisible())));
        }
    }
    if (element->HasAttClass( ATT_OCTAVE ) ) {
        AttOctave *att = dynamic_cast<AttOctave*>(element);
        assert( att );
        if (att->HasOct()) {
            attributes->push_back(std::make_pair("oct", att->IntToStr(att->GetOct())));
        }
    }
    if (element->HasAttClass( ATT_OCTAVEDEFAULT ) ) {
        AttOctavedefault *att = dynamic_cast<AttOctavedefault*>(element);
        assert( att );
        if (att->HasOctaveDefault()) {
            attributes->push_back(std::make_pair("octaveDefault", att->StrToStr(att->GetOctaveDefault())));
        }
    }
    if (element->HasAttClass( ATT_OCTAVEDISPLACEMENT ) ) {
        AttOctavedisplacement *att = dynamic_cast<AttOctavedisplacement*>(element);
        assert( att );
        if (att->HasDis()) {
            attributes->push_back(std::make_pair("dis", att->OctaveDisToStr(att->GetDis())));
        }
        if (att->HasDisPlace()) {
            attributes->push_back(std::make_pair("disPlace", att->PlaceToStr(att->GetDisPlace())));
        }
    }
    if (element->HasAttClass( ATT_ONELINESTAFF ) ) {
        AttOnelinestaff *att = dynamic_cast<AttOnelinestaff*>(element);
        assert( att );
        if (att->HasOntheline()) {
            attributes->push_back(std::make_pair("ontheline", att->StrToStr(att->GetOntheline())));
        }
    }
    if (element->HasAttClass( ATT_OPTIMIZATION ) ) {
        AttOptimization *att = dynamic_cast<AttOptimization*>(element);
        assert( att );
        if (att->HasOptimize()) {
            attributes->push_back(std::make_pair("optimize", att->StrToStr(att->GetOptimize())));
        }
    }
    if (element->HasAttClass( ATT_PADLOG ) ) {
        AttPadLog *att = dynamic_cast<AttPadLog*>(element);
        assert( att );
        if (att->HasNum()) {
            attributes->push_back(std::make_pair("num", att->IntToStr(att->GetNum())));
        }
    }
    if (element->HasAttClass( ATT_PAGES ) ) {
        AttPages *att = dynamic_cast<AttPages*>(element);
        assert( att );
        if (att->HasPageHeight()) {
            attributes->push_back(std::make_pair("pageHeight", att->StrToStr(att->GetPageHeight())));
        }
        if (att->HasPageWidth()) {
            attributes->push_back(std::make_pair("pageWidth", att->StrToStr(att->GetPageWidth())));
        }
        if (att->HasPageTopmar()) {
            attributes->push_back(std::make_pair("pageTopmar", att->StrToStr(att->GetPageTopmar())));
        }
        if (att->HasPageBotmar()) {
            attributes->push_back(std::make_pair("pageBotmar", att->StrToStr(att->GetPageBotmar())));
        }
        if (att->HasPageLeftmar()) {
            attributes->push_back(std::make_pair("pageLeftmar", att->StrToStr(att->GetPageLeftmar())));
        }
        if (att->HasPageRightmar()) {
            attributes->push_back(std::make_pair("pageRightmar", att->StrToStr(att->GetPageRightmar())));
        }
        if (att->HasPagePanels()) {
            attributes->push_back(std::make_pair("pagePanels", att->StrToStr(att->GetPagePanels())));
        }
        if (att->HasPageScale()) {
            attributes->push_back(std::make_pair("pageScale", att->StrToStr(att->GetPageScale())));
        }
    }
    if (element->HasAttClass( ATT_PBVIS ) ) {
        AttPbVis *att = dynamic_cast<AttPbVis*>(element);
        assert( att );
        if (att->HasFolium()) {
            attributes->push_back(std::make_pair("folium", att->StrToStr(att->GetFolium())));
        }
    }
    if (element->HasAttClass( ATT_PITCH ) ) {
        AttPitch *att = dynamic_cast<AttPitch*>(element);
        assert( att );
        if (att->HasPname()) {
            attributes->push_back(std::make_pair("pname", att->PitchNameToStr(att->GetPname())));
        }
    }
    if (element->HasAttClass( ATT_PLACEMENT ) ) {
        AttPlacement *att = dynamic_cast<AttPlacement*>(element);
        assert( att );
        if (att->HasPlace()) {
            attributes->push_back(std::make_pair("place", att->StaffRelToStr(att->GetPlace())));
        }
    }
    if (element->HasAttClass( ATT_PLIST ) ) {
        AttPlist *att = dynamic_cast<AttPlist*>(element);
        assert( att );
        if (att->HasPlist()) {
            attributes->push_back(std::make_pair("plist", att->StrToStr(att->GetPlist())));
        }
        if (att->HasEvaluate()) {
            attributes->push_back(std::make_pair("evaluate", att->StrToStr(att->GetEvaluate())));
        }
    }
    if (element->HasAttClass( ATT_POINTING ) ) {
        AttPointing *att = dynamic_cast<AttPointing*>(element);
        assert( att );
        if (att->HasActuate()) {
            attributes->push_back(std::make_pair("actuate", att->StrToStr(att->GetActuate())));
        }
        if (att->HasRole()) {
            attributes->push_back(std::make_pair("role", att->StrToStr(att->GetRole())));
        }
        if (att->HasShow()) {
            attributes->push_back(std::make_pair("show", att->StrToStr(att->GetShow())));
        }
        if (att->HasTarget()) {
            attributes->push_back(std::make_pair("target", att->StrToStr(att->GetTarget())));
        }
        if (att->HasTargettype()) {
            attributes->push_back(std::make_pair("targettype", att->StrToStr(att->GetTargettype())));
        }
        if (att->HasTitle()) {
            attributes->push_back(std::make_pair("title", att->StrToStr(att->GetTitle())));
        }
    }
    if (element->HasAttClass( ATT_QUANTITY ) ) {
        AttQuantity *att = dynamic_cast<AttQuantity*>(element);
        assert( att );
        if (att->HasQuantity()) {
            attributes->push_back(std::make_pair("quantityDbl", att->DblToStr(att->GetQuantity())));
        }
    }
    if (element->HasAttClass( ATT_RELATIVESIZE ) ) {
        AttRelativesize *att = dynamic_cast<AttRelativesize*>(element);
        assert( att );
        if (att->HasSize()) {
            attributes->push_back(std::make_pair("size", att->StrToStr(att->GetSize())));
        }
    }
    if (element->HasAttClass( ATT_RESPONSIBILITY ) ) {
        AttResponsibility *att = dynamic_cast<AttResponsibility*>(element);
        assert( att );
        if (att->HasResp()) {
            attributes->push_back(std::make_pair("resp", att->StrToStr(att->GetResp())));
        }
    }
    if (element->HasAttClass( ATT_SBVIS ) ) {
        AttSbVis *att = dynamic_cast<AttSbVis*>(element);
        assert( att );
        if (att->HasForm()) {
            attributes->push_back(std::make_pair("form", att->BarRenditionToStr(att->GetForm())));
        }
    }
    if (element->HasAttClass( ATT_SCALABLE ) ) {
        AttScalable *att = dynamic_cast<AttScalable*>(element);
        assert( att );
        if (att->HasScale()) {
            attributes->push_back(std::make_pair("scale", att->PercentToStr(att->GetScale())));
        }
    }
    if (element->HasAttClass( ATT_SCOREDEFGES ) ) {
        AttScoreDefGes *att = dynamic_cast<AttScoreDefGes*>(element);
        assert( att );
        if (att->HasTunePname()) {
            attributes->push_back(std::make_pair("tunePname", att->StrToStr(att->GetTunePname())));
        }
        if (att->HasTuneHz()) {
            attributes->push_back(std::make_pair("tuneHzDbl", att->DblToStr(att->GetTuneHz())));
        }
        if (att->HasTuneTemper()) {
            attributes->push_back(std::make_pair("tuneTemper", att->StrToStr(att->GetTuneTemper())));
        }
    }
    if (element->HasAttClass( ATT_SCOREDEFVIS ) ) {
        AttScoreDefVis *att = dynamic_cast<AttScoreDefVis*>(element);
        assert( att );
        if (att->HasVuHeight()) {
            attributes->push_back(std::make_pair("vuHeight", att->StrToStr(att->GetVuHeight())));
        }
    }
    if (element->HasAttClass( ATT_SECTIONVIS ) ) {
        AttSectionVis *att = dynamic_cast<AttSectionVis*>(element);
        assert( att );
        if (att->HasRestart()) {
            attributes->push_back(std::make_pair("restart", att->StrToStr(att->GetRestart())));
        }
    }
    if (element->HasAttClass( ATT_SEQUENCE ) ) {
        AttSequence *att = dynamic_cast<AttSequence*>(element);
        assert( att );
        if (att->HasSeq()) {
            attributes->push_back(std::make_pair("seqInt", att->IntToStr(att->GetSeq())));
        }
    }
    if (element->HasAttClass( ATT_SLASHCOUNT ) ) {
        AttSlashcount *att = dynamic_cast<AttSlashcount*>(element);
        assert( att );
        if (att->HasSlash()) {
            attributes->push_back(std::make_pair("slash", att->IntToStr(att->GetSlash())));
        }
    }
    if (element->HasAttClass( ATT_SLURPRESENT ) ) {
        AttSlurpresent *att = dynamic_cast<AttSlurpresent*>(element);
        assert( att );
        if (att->HasSlur()) {
            attributes->push_back(std::make_pair("slur", att->StrToStr(att->GetSlur())));
        }
    }
    if (element->HasAttClass( ATT_SPACEVIS ) ) {
        AttSpaceVis *att = dynamic_cast<AttSpaceVis*>(element);
        assert( att );
        if (att->HasCompressable()) {
            attributes->push_back(std::make_pair("compressable", att->StrToStr(att->GetCompressable())));
        }
    }
    if (element->HasAttClass( ATT_SPACING ) ) {
        AttSpacing *att = dynamic_cast<AttSpacing*>(element);
        assert( att );
        if (att->HasSpacingPackexp()) {
            attributes->push_back(std::make_pair("spacingPackexpDbl", att->DblToStr(att->GetSpacingPackexp())));
        }
        if (att->HasSpacingPackfact()) {
            attributes->push_back(std::make_pair("spacingPackfactDbl", att->DblToStr(att->GetSpacingPackfact())));
        }
        if (att->HasSpacingStaff()) {
            attributes->push_back(std::make_pair("spacingStaff", att->StrToStr(att->GetSpacingStaff())));
        }
        if (att->HasSpacingSystem()) {
            attributes->push_back(std::make_pair("spacingSystem", att->StrToStr(att->GetSpacingSystem())));
        }
    }
    if (element->HasAttClass( ATT_STAFFLOG ) ) {
        AttStaffLog *att = dynamic_cast<AttStaffLog*>(element);
        assert( att );
        if (att->HasDef()) {
            attributes->push_back(std::make_pair("def", att->StrToStr(att->GetDef())));
        }
    }
    if (element->HasAttClass( ATT_STAFFDEFVIS ) ) {
        AttStaffDefVis *att = dynamic_cast<AttStaffDefVis*>(element);
        assert( att );
        if (att->HasGridShow()) {
            attributes->push_back(std::make_pair("gridShow", att->BoolToStr(att->GetGridShow())));
        }
        if (att->HasLayerscheme()) {
            attributes->push_back(std::make_pair("layerscheme", att->LayerschemeToStr(att->GetLayerscheme())));
        }
        if (att->HasLines()) {
            attributes->push_back(std::make_pair("linesInt", att->IntToStr(att->GetLines())));
        }
        if (att->HasLinesColor()) {
            attributes->push_back(std::make_pair("linesColor", att->StrToStr(att->GetLinesColor())));
        }
        if (att->HasLinesVisible()) {
            attributes->push_back(std::make_pair("linesVisible", att->BoolToStr(att->GetLinesVisible())));
        }
        if (att->HasSpacing()) {
            attributes->push_back(std::make_pair("spacing", att->StrToStr(att->GetSpacing())));
        }
    }
    if (element->HasAttClass( ATT_STAFFGRPVIS ) ) {
        AttStaffGrpVis *att = dynamic_cast<AttStaffGrpVis*>(element);
        assert( att );
        if (att->HasBarthru()) {
            attributes->push_back(std::make_pair("barthru", att->BoolToStr(att->GetBarthru())));
        }
    }
    if (element->HasAttClass( ATT_STAFFGROUPINGSYM ) ) {
        AttStaffgroupingsym *att = dynamic_cast<AttStaffgroupingsym*>(element);
        assert( att );
        if (att->HasSymbol()) {
            attributes->push_back(std::make_pair("symbol", att->SymbolToStr(att->GetSymbol())));
        }
    }
    if (element->HasAttClass( ATT_STAFFIDENT ) ) {
        AttStaffident *att = dynamic_cast<AttStaffident*>(element);
        assert( att );
        if (att->HasStaff()) {
            attributes->push_back(std::make_pair("staff", att->IntToStr(att->GetStaff())));
        }
    }
    if (element->HasAttClass( ATT_STAFFLOC ) ) {
        AttStaffloc *att = dynamic_cast<AttStaffloc*>(element);
        assert( att );
        if (att->HasLoc()) {
            attributes->push_back(std::make_pair("loc", att->StrToStr(att->GetLoc())));
        }
    }
    if (element->HasAttClass( ATT_STAFFLOCPITCHED ) ) {
        AttStafflocPitched *att = dynamic_cast<AttStafflocPitched*>(element);
        assert( att );
        if (att->HasPloc()) {
            attributes->push_back(std::make_pair("ploc", att->PitchNameToStr(att->GetPloc())));
        }
        if (att->HasOloc()) {
            attributes->push_back(std::make_pair("oloc", att->IntToStr(att->GetOloc())));
        }
    }
    if (element->HasAttClass( ATT_STARTENDID ) ) {
        AttStartendid *att = dynamic_cast<AttStartendid*>(element);
        assert( att );
        if (att->HasEndid()) {
            attributes->push_back(std::make_pair("endid", att->StrToStr(att->GetEndid())));
        }
    }
    if (element->HasAttClass( ATT_STARTID ) ) {
        AttStartid *att = dynamic_cast<AttStartid*>(element);
        assert( att );
        if (att->HasStartid()) {
            attributes->push_back(std::make_pair("startid", att->StrToStr(att->GetStartid())));
        }
    }
    if (element->HasAttClass( ATT_STEMS ) ) {
        AttStems *att = dynamic_cast<AttStems*>(element);
        assert( att );
        if (att->HasStemDir()) {
            attributes->push_back(std::make_pair("stemDir", att->StemDirectionToStr(att->GetStemDir())));
        }
        if (att->HasStemLen()) {
            attributes->push_back(std::make_pair("stemLen", att->IntToStr(att->GetStemLen())));
        }
        if (att->HasStemMod()) {
            attributes->push_back(std::make_pair("stemMod", att->StemModifierToStr(att->GetStemMod())));
        }
        if (att->HasStemPos()) {
            attributes->push_back(std::make_pair("stemPos", att->StemPositionToStr(att->GetStemPos())));
        }
        if (att->HasStemX()) {
            attributes->push_back(std::make_pair("stemX", att->IntToStr(att->GetStemX())));
        }
        if (att->HasStemY()) {
            attributes->push_back(std::make_pair("stemY", att->IntToStr(att->GetStemY())));
        }
    }
    if (element->HasAttClass( ATT_SYLLOG ) ) {
        AttSylLog *att = dynamic_cast<AttSylLog*>(element);
        assert( att );
        if (att->HasCon()) {
            attributes->push_back(std::make_pair("con", att->ConToStr(att->GetCon())));
        }
        if (att->HasWordpos()) {
            attributes->push_back(std::make_pair("wordpos", att->WordPosToStr(att->GetWordpos())));
        }
    }
    if (element->HasAttClass( ATT_SYLTEXT ) ) {
        AttSyltext *att = dynamic_cast<AttSyltext*>(element);
        assert( att );
        if (att->HasSyl()) {
            attributes->push_back(std::make_pair("syl", att->StrToStr(att->GetSyl())));
        }
    }
    if (element->HasAttClass( ATT_SYSTEMS ) ) {
        AttSystems *att = dynamic_cast<AttSystems*>(element);
        assert( att );
        if (att->HasSystemLeftline()) {
            attributes->push_back(std::make_pair("systemLeftline", att->StrToStr(att->GetSystemLeftline())));
        }
        if (att->HasSystemLeftmar()) {
            attributes->push_back(std::make_pair("systemLeftmar", att->StrToStr(att->GetSystemLeftmar())));
        }
        if (att->HasSystemRightmar()) {
            attributes->push_back(std::make_pair("systemRightmar", att->StrToStr(att->GetSystemRightmar())));
        }
        if (att->HasSystemTopmar()) {
            attributes->push_back(std::make_pair("systemTopmar", att->StrToStr(att->GetSystemTopmar())));
        }
    }
    if (element->HasAttClass( ATT_TEXTSTYLE ) ) {
        AttTextstyle *att = dynamic_cast<AttTextstyle*>(element);
        assert( att );
        if (att->HasTextFam()) {
            attributes->push_back(std::make_pair("textFam", att->StrToStr(att->GetTextFam())));
        }
        if (att->HasTextName()) {
            attributes->push_back(std::make_pair("textName", att->StrToStr(att->GetTextName())));
        }
        if (att->HasTextSize()) {
            attributes->push_back(std::make_pair("textSize", att->StrToStr(att->GetTextSize())));
        }
        if (att->HasTextStyle()) {
            attributes->push_back(std::make_pair("textStyle", att->StrToStr(att->GetTextStyle())));
        }
        if (att->HasTextWeight()) {
            attributes->push_back(std::make_pair("textWeight", att->StrToStr(att->GetTextWeight())));
        }
    }
    if (element->HasAttClass( ATT_TIEPRESENT ) ) {
        AttTiepresent *att = dynamic_cast<AttTiepresent*>(element);
        assert( att );
        if (att->HasTie()) {
            attributes->push_back(std::make_pair("tie", att->TieToStr(att->GetTie())));
        }
    }
    if (element->HasAttClass( ATT_TIMESTAMPMUSICAL ) ) {
        AttTimestampMusical *att = dynamic_cast<AttTimestampMusical*>(element);
        assert( att );
        if (att->HasTstamp()) {
            attributes->push_back(std::make_pair("tstamp", att->DblToStr(att->GetTstamp())));
        }
    }
    if (element->HasAttClass( ATT_TIMESTAMPPERFORMED ) ) {
        AttTimestampPerformed *att = dynamic_cast<AttTimestampPerformed*>(element);
        assert( att );
        if (att->HasTstampGes()) {
            attributes->push_back(std::make_pair("tstampGes", att->StrToStr(att->GetTstampGes())));
        }
        if (att->HasTstampReal()) {
            attributes->push_back(std::make_pair("tstampReal", att->StrToStr(att->GetTstampReal())));
        }
    }
    if (element->HasAttClass( ATT_TIMESTAMP2MUSICAL ) ) {
        AttTimestamp2Musical *att = dynamic_cast<AttTimestamp2Musical*>(element);
        assert( att );
        if (att->HasTstamp2()) {
            attributes->push_back(std::make_pair("tstamp2", att->Tstamp2ToStr(att->GetTstamp2())));
        }
    }
    if (element->HasAttClass( ATT_TRANSPOSITION ) ) {
        AttTransposition *att = dynamic_cast<AttTransposition*>(element);
        assert( att );
        if (att->HasTransDiat()) {
            attributes->push_back(std::make_pair("transDiatDbl", att->DblToStr(att->GetTransDiat())));
        }
        if (att->HasTransSemi()) {
            attributes->push_back(std::make_pair("transSemiDbl", att->DblToStr(att->GetTransSemi())));
        }
    }
    if (element->HasAttClass( ATT_TUPLETPRESENT ) ) {
        AttTupletpresent *att = dynamic_cast<AttTupletpresent*>(element);
        assert( att );
        if (att->HasTuplet()) {
            attributes->push_back(std::make_pair("tuplet", att->StrToStr(att->GetTuplet())));
        }
    }
    if (element->HasAttClass( ATT_TYPED ) ) {
        AttTyped *att = dynamic_cast<AttTyped*>(element);
        assert( att );
        if (att->HasType()) {
            attributes->push_back(std::make_pair("type", att->StrToStr(att->GetType())));
        }
        if (att->HasSubtype()) {
            attributes->push_back(std::make_pair("subtype", att->StrToStr(att->GetSubtype())));
        }
    }
    if (element->HasAttClass( ATT_TYPOGRAPHY ) ) {
        AttTypography *att = dynamic_cast<AttTypography*>(element);
        assert( att );
        if (att->HasFontfam()) {
            attributes->push_back(std::make_pair("fontfam", att->StrToStr(att->GetFontfam())));
        }
        if (att->HasFontname()) {
            attributes->push_back(std::make_pair("fontname", att->StrToStr(att->GetFontname())));
        }
        if (att->HasFontsize()) {
            attributes->push_back(std::make_pair("fontsizeDbl", att->DblToStr(att->GetFontsize())));
        }
        if (att->HasFontstyle()) {
            attributes->push_back(std::make_pair("fontstyle", att->FontstyleToStr(att->GetFontstyle())));
        }
        if (att->HasFontweight()) {
            attributes->push_back(std::make_pair("fontweight", att->FontweightToStr(att->GetFontweight())));
        }
    }
    if (element->HasAttClass( ATT_VISIBILITY ) ) {
        AttVisibility *att = dynamic_cast<AttVisibility*>(element);
        assert( att );
        if (att->HasVisible()) {
            attributes->push_back(std::make_pair("visible", att->StrToStr(att->GetVisible())));
        }
    }
    if (element->HasAttClass( ATT_VISUALOFFSETHO ) ) {
        AttVisualoffsetHo *att = dynamic_cast<AttVisualoffsetHo*>(element);
        assert( att );
        if (att->HasHo()) {
            attributes->push_back(std::make_pair("ho", att->StrToStr(att->GetHo())));
        }
    }
    if (element->HasAttClass( ATT_VISUALOFFSETTO ) ) {
        AttVisualoffsetTo *att = dynamic_cast<AttVisualoffsetTo*>(element);
        assert( att );
        if (att->HasTo()) {
            attributes->push_back(std::make_pair("to", att->StrToStr(att->GetTo())));
        }
    }
    if (element->HasAttClass( ATT_VISUALOFFSETVO ) ) {
        AttVisualoffsetVo *att = dynamic_cast<AttVisualoffsetVo*>(element);
        assert( att );
        if (att->HasVo()) {
            attributes->push_back(std::make_pair("vo", att->StrToStr(att->GetVo())));
        }
    }
    if (element->HasAttClass( ATT_VISUALOFFSET2HO ) ) {
        AttVisualoffset2Ho *att = dynamic_cast<AttVisualoffset2Ho*>(element);
        assert( att );
        if (att->HasStartho()) {
            attributes->push_back(std::make_pair("startho", att->StrToStr(att->GetStartho())));
        }
        if (att->HasEndho()) {
            attributes->push_back(std::make_pair("endho", att->StrToStr(att->GetEndho())));
        }
    }
    if (element->HasAttClass( ATT_VISUALOFFSET2TO ) ) {
        AttVisualoffset2To *att = dynamic_cast<AttVisualoffset2To*>(element);
        assert( att );
        if (att->HasStartto()) {
            attributes->push_back(std::make_pair("startto", att->StrToStr(att->GetStartto())));
        }
        if (att->HasEndto()) {
            attributes->push_back(std::make_pair("endto", att->StrToStr(att->GetEndto())));
        }
    }
    if (element->HasAttClass( ATT_VISUALOFFSET2VO ) ) {
        AttVisualoffset2Vo *att = dynamic_cast<AttVisualoffset2Vo*>(element);
        assert( att );
        if (att->HasStartvo()) {
            attributes->push_back(std::make_pair("startvo", att->StrToStr(att->GetStartvo())));
        }
        if (att->HasEndvo()) {
            attributes->push_back(std::make_pair("endvo", att->StrToStr(att->GetEndvo())));
        }
    }
    if (element->HasAttClass( ATT_WHITESPACE ) ) {
        AttWhitespace *att = dynamic_cast<AttWhitespace*>(element);
        assert( att );
        if (att->HasSpace()) {
            attributes->push_back(std::make_pair("space", att->StrToStr(att->GetSpace())));
        }
    }
    if (element->HasAttClass( ATT_WIDTH ) ) {
        AttWidth *att = dynamic_cast<AttWidth*>(element);
        assert( att );
        if (att->HasWidth()) {
            attributes->push_back(std::make_pair("width", att->StrToStr(att->GetWidth())));
        }
    }
    if (element->HasAttClass( ATT_XY ) ) {
        AttXy *att = dynamic_cast<AttXy*>(element);
        assert( att );
        if (att->HasX()) {
            attributes->push_back(std::make_pair("xDbl", att->DblToStr(att->GetX())));
        }
        if (att->HasY()) {
            attributes->push_back(std::make_pair("yDbl", att->DblToStr(att->GetY())));
        }
    }
    if (element->HasAttClass( ATT_XY2 ) ) {
        AttXy2 *att = dynamic_cast<AttXy2*>(element);
        assert( att );
        if (att->HasX2()) {
            attributes->push_back(std::make_pair("x2Dbl", att->DblToStr(att->GetX2())));
        }
        if (att->HasY2()) {
            attributes->push_back(std::make_pair("y2Dbl", att->DblToStr(att->GetY2())));
        }
    }

}
    
} // vrv namespace
    
