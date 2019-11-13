// Copyright 2009-2019 NTESS. Under the terms
// of Contract DE-NA0003525 with NTESS, the U.S.
// Government retains certain rights in this software.
// 
// Copyright (c) 2009-2019, NTESS
// All rights reserved.
// 
// This file is part of the SST software package. For license
// information, see the LICENSE file in the top level directory of the
// distribution.

#include <sst_config.h>
#include <sst/core/subcomponent.h>
#include <sst/core/factory.h>

namespace SST {

SST_ELI_DEFINE_INFO_EXTERN(SubComponent)
SST_ELI_DEFINE_CTOR_EXTERN(SubComponent)

SubComponent::SubComponent(Component* parent) :
    BaseComponent(parent->getCurrentlyLoadingSubComponentID())
#ifdef SST_ENABLE_DEPRECATED
    ,parent(parent)
#endif
{
    loadedWithLegacyAPI = true;
}

SubComponent::SubComponent(ComponentId_t id) :
    BaseComponent(id)
#ifdef SST_ENABLE_DEPRECATED
    ,parent(getTrueComponentPrivate())
#endif
{}


#ifdef SST_ENABLE_DEPRECATED
SubComponent*
SubComponent::loadSubComponent(std::string type, Params& params)
{
    return BaseComponent::loadSubComponent(type, getTrueComponentPrivate(), params);
}
#endif

} // namespace SST
