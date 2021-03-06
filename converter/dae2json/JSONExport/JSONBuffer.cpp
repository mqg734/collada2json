// Copyright (c) 2012, Motorola Mobility, Inc.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
//  * Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
//  * Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
//  * Neither the name of the Motorola Mobility, Inc. nor the names of its
//    contributors may be used to endorse or promote products derived from this
//    software without specific prior written permission.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
// DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
// ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
// THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#include "JSONExport.h"

using namespace rapidjson;

namespace JSONExport 
{    
    JSONBuffer::JSONBuffer() {}     //private

    JSONBuffer::~JSONBuffer() {
        
    }    

    JSONBuffer::JSONBuffer(size_t byteSize):
    _byteSize(byteSize)
    {
    }     //protected

    JSONBuffer::JSONBuffer(std::string ID, size_t byteSize):
    _ID(ID),
    _byteSize(byteSize)
    {
    }     //protected

    size_t const JSONBuffer::getByteSize()
    {
        return this->_byteSize;
    }
        
    const std::string const JSONBuffer::getID()
    {
        return this->_ID;
    }
    
    //--------------------------------------------------------------------------------------------------------------------------------    
    
    JSONDataBuffer::JSONDataBuffer(void *data, size_t byteSize, bool ownData): 
    _data((unsigned char*)data),
    JSONBuffer(byteSize),
    _ownData(ownData)
    {
        this->_ID = JSONUtils::generateIDForType("buffer");
    }
    
    JSONDataBuffer::JSONDataBuffer(std::string ID,void *data, size_t byteSize, bool ownData): 
    _data((unsigned char*)data),
    JSONBuffer(ID, byteSize),
    _ownData(ownData)
    {
    }

    JSONDataBuffer::~JSONDataBuffer()
    {
        if (this->_ownData && this->_data) 
            free(this->_data);
    }

    const void* const JSONDataBuffer::getData()
    {
        return this->_data;
    }   
    
}
