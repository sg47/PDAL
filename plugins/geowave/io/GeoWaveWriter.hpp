/******************************************************************************
* Copyright (c) 2015, James W. O'Meara (james.w.omeara@gmail.com)
*
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following
* conditions are met:
*
*     * Redistributions of source code must retain the above copyright
*       notice, this list of conditions and the following disclaimer.
*     * Redistributions in binary form must reproduce the above copyright
*       notice, this list of conditions and the following disclaimer in
*       the documentation and/or other materials provided
*       with the distribution.
*     * Neither the name of Hobu, Inc. or Flaxen Geo Consulting nor the
*       names of its contributors may be used to endorse or promote
*       products derived from this software without specific prior
*       written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
* "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
* LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
* FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
* COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
* INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
* BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
* OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
* AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
* OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
* OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
* OF SUCH DAMAGE.
****************************************************************************/

#pragma once

#include <pdal/Writer.hpp>
#include <pdal/StageFactory.hpp>

#include <vector>
#include <string>

namespace pdal
{

    class PDAL_DLL GeoWaveWriter : public Writer
    {
    public:
        SET_STAGE_NAME("writers.geowave", "GeoWave Writer")
        SET_STAGE_LINK("http://pdal.io/stages/drivers.geowave.writer.html")
        SET_PLUGIN_VERSION("1.0.0")

        static Options getDefaultOptions();

    private:
        virtual void initialize();
        virtual void processOptions(const Options&);
        virtual void ready(PointContext ctx);
        virtual void write(const PointBuffer& buf);

        int createJvm();

        std::string m_zookeeperUrl;
        std::string m_instanceName;
        std::string m_username;
        std::string m_password;
        std::string m_tableNamespace;
        std::string m_featureTypeName;
        bool m_useFeatCollDataAdapter;
        uint32_t m_pointsPerEntry;
        Dimension::IdList m_dims;
        std::vector<Dimension::Type::Enum> m_dimTypes;
    };

} // namespace pdal
