// BSD 3-Clause License

// Copyright (c) 2019, SCALE Lab, Brown University
// All rights reserved.

// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:

// * Redistributions of source code must retain the above copyright notice, this
//   list of conditions and the following disclaimer.

// * Redistributions in binary form must reproduce the above copyright notice,
//   this list of conditions and the following disclaimer in the documentation
//   and/or other materials provided with the distribution.

// * Neither the name of the copyright holder nor the names of its
//   contributors may be used to endorse or promote products derived from
//   this software without specific prior written permission.

// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
#include "Psn/Psn.hpp"
#include "PsnException/PsnException.hpp"
#include "Utils/FileUtils.hpp"
#include "doctest.h"

namespace psn
{

TEST_CASE("testing pin_swap -power transform")
{
    Psn& psn_inst = Psn::instance();
    try
    {
        psn_inst.clearDatabase();
        psn_inst.readLib("../tests/data/libraries/Nangate45/"
                         "NangateOpenCellLibrary_typical.lib");
        psn_inst.readLef(
            "../tests/data/libraries/Nangate45/NangateOpenCellLibrary.mod.lef");
        psn_inst.readDef("../tests/data/designs/gcd/gcd.def");
        CHECK(psn_inst.database()->getChip() != nullptr);
        CHECK(psn_inst.hasTransform("pin_swap"));
        auto& handler = *(psn_inst.handler());
        handler.createClock("core_clock", {"clk"}, 10E-09);
        auto result = psn_inst.runTransform(
            "pin_swap", std::vector<std::string>({"50", "-power"}));
        CHECK(result == 18);
    }
    catch (PsnException& e)
    {
        FAIL(e.what());
    }
}
} // namespace psn