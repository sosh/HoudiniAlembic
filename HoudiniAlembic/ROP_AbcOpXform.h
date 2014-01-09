/*
 * Copyright (c) 2014
 *	Side Effects Software Inc.  All rights reserved.
 *
 * Redistribution and use of Houdini Development Kit samples in source and
 * binary forms, with or without modification, are permitted provided that the
 * following conditions are met:
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. The name of Side Effects Software may not be used to endorse or
 *    promote products derived from this software without specific prior
 *    written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY SIDE EFFECTS SOFTWARE `AS IS' AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN
 * NO EVENT SHALL SIDE EFFECTS SOFTWARE BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *----------------------------------------------------------------------------
 */

#ifndef __ROP_AbcOpXform__
#define __ROP_AbcOpXform__

#include "ROP_AbcObject.h"
#include "ROP_AbcContext.h"

class OBJ_Node;

/// Transform node defined by a Houdini object node
class ROP_AbcOpXform : public ROP_AbcObject
{
public:
    typedef Alembic::AbcGeom::OXform	OXform;
    typedef Alembic::Abc::OObject	OObject;

    ROP_AbcOpXform(OBJ_Node *node, const ROP_AbcContext &ctx);
    virtual ~ROP_AbcOpXform();

    /// @{
    /// Interface defined on ROP_AbcObject
    virtual const char	*className() const	{ return "OpXform"; }
    virtual bool	start(const OObject &parent,
				GABC_OError &err,
				const ROP_AbcContext &ctx,
				UT_BoundingBox &box);
    virtual bool	update(GABC_OError &err,
				const ROP_AbcContext &ctx,
				UT_BoundingBox &box);
    virtual bool	selfTimeDependent() const;
    virtual bool	getLastBounds(UT_BoundingBox &box) const;
    /// @}

private:
    UT_Matrix4D		 myMatrix;
    UT_BoundingBox	 myBox;
    OXform		 myOXform;
    int			 myNodeId;
    bool		 myTimeDependent;
    bool		 myIdentity;
    bool		 myGeometryContainer;
};

#endif

