/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef STARTREK_DOSDEMOBATTLE_H
#define STARTREK_DOSDEMOBATTLE_H

#include "common/keyboard.h"
#include "common/list.h"
#include "common/str.h"

#include "startrek/sprite.h"

namespace StarTrek {

struct Bitmap;
class StarTrekEngine;
struct R3;
struct TrekEvent;

// The space battle of the DOS demo, which uses the space flight of the engine
class DosDemoBattle {
public:
	DosDemoBattle(StarTrekEngine *vm);

	void play();
	void addBridgeMessage(const Common::String &speaker, const Common::String &text, int16 x, int16 y);
	void reportLostShield(const char *side);

private:
	// A message on the bridge
	struct Message {
		Common::String speaker;
		Common::String text;
		int16 x;
		int16 y;
	};

	void init();
	void cleanup();
	void initShip(R3 *ship, int16 shape, int16 size, const int16 *strengths);
	void update();
	void runScript();
	void moveKlingons();
	void fireKlingon(R3 *ship);
	void fireEnterprise();
	void moveShip(R3 *ship);
	void updateShipEnergy(R3 *ship);
	void repairShip(R3 *ship);
	void handleEvent(const TrekEvent &event);
	void handleKey(Common::KeyCode key);
	void toggleShields();
	void toggleWeapons();
	void showCrewMenu(int actor);
	void updateBridgeMessages();
	void drawShipPanels();
	void drawPanelBitmap(Bitmap *bitmap, int16 x, int16 y);

	StarTrekEngine *_vm;
	int _frame;
	int _fireTime;
	uint32 _shieldMessageTime;
	Common::List<Message> _messages;
	Sprite _messageSprite;
	int _messageEnd;
};

} // End of namespace StarTrek

#endif
