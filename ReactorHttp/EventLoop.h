#pragma once
#include "Dispatcher.h"

struct EventLoop {
	Dispatcher* dispatcher;
	void* dispatcherData;
};