#ifndef _ClientSubView_H
#define _ClientSubView_H
#include "Frostbite_Classes.h"
#include "SubView.h"
namespace fb
{
	class ClientSubView
		: public SubView,						// 0x00
		public network::IClientNetworkable		// 0x08
	{
	public:
		ClientPlayerView* m_playerView;			// 0x10
	}; // 0x14
};

#endif