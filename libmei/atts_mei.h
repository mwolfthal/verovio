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

#ifndef __VRV_ATTS_MEI_H__
#define __VRV_ATTS_MEI_H__

#include "att.h"
#include "att_classes.h"
#include "pugixml.hpp"

//----------------------------------------------------------------------------

#include <string>

namespace vrv {
    
//----------------------------------------------------------------------------
// AttNotationtype
//----------------------------------------------------------------------------

class AttNotationtype: public Att
{
public:
    AttNotationtype();
    virtual ~AttNotationtype();
    
    /** Reset the default values for the attribute class **/
    void ResetNotationtype();
    
    /** Read the values for the attribute class **/
    bool ReadNotationtype( pugi::xml_node element );
    
    /** Write the values for the attribute class **/
    bool WriteNotationtype( pugi::xml_node element );
    
    /**
     * @name Setters, getters and presence checker for class members.
     * The checker returns true if the attribute class is set (e.g., not equal 
     * to the default value)
     **/
    ///@{
    void SetNotationtype(std::string notationtype_) { m_notationtype = notationtype_; };
    std::string GetNotationtype() const { return m_notationtype; };    
    bool HasNotationtype( );
    
    //
    void SetNotationsubtype(std::string notationsubtype_) { m_notationsubtype = notationsubtype_; };
    std::string GetNotationsubtype() const { return m_notationsubtype; };    
    bool HasNotationsubtype( );
    
    ///@}

private:
    /**
     * Contains classification of the notation contained or described by the element
     * bearing this attribute.
     **/
    std::string m_notationtype;
    /**
     * Provides any sub-classification of the notation contained or described by the
     * element, additional to that given by its notationtype attribute.
     **/
    std::string m_notationsubtype;

/* include <attnotationsubtype> */
};

} // vrv namespace

#endif  // __VRV_ATTS_MEI_H__

