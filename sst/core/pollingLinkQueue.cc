// Copyright 2009-2013 Sandia Corporation. Under the terms
// of Contract DE-AC04-94AL85000 with Sandia Corporation, the U.S.
// Government retains certain rights in this software.
// 
// Copyright (c) 2009-2013, Sandia Corporation
// All rights reserved.
// 
// This file is part of the SST software package. For license
// information, see the LICENSE file in the top level directory of the
// distribution.


#include "sst_config.h"
#include "sst/core/serialization.h"

#include <sst/core/pollingLinkQueue.h>

namespace SST {

    PollingLinkQueue::PollingLinkQueue() : ActivityQueue() {}
    PollingLinkQueue::~PollingLinkQueue() {
	// Need to delete any events left in the queue
	std::multiset<Activity*,Activity::less_time>::iterator it;
	for ( it = data.begin(); it != data.end(); ++it ) {
	    delete *it;
	}
	data.clear();
    }

    bool PollingLinkQueue::empty()
    {
	return data.empty();
    }
    
    int PollingLinkQueue::size()
    {
	return data.size();
    }
    
    void PollingLinkQueue::insert(Activity* activity)
    {
	data.insert(activity);
    }
    
    Activity* PollingLinkQueue::pop()
    {
	if ( data.size() == 0 ) return NULL;
	std::multiset<Activity*,Activity::less_time>::iterator it = data.begin();
	Activity* ret_val = (*it);
	data.erase(it);
	return ret_val;
    }

    Activity* PollingLinkQueue::front()
    {
	if ( data.size() == 0 ) return NULL;
	return *data.begin();
    }


} // namespace SST

BOOST_CLASS_EXPORT_IMPLEMENT(SST::PollingLinkQueue)
