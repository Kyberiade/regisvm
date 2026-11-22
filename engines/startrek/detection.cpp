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

#include "base/plugins.h"

#include "engines/advancedDetector.h"

#include "common/config-manager.h"
#include "common/file.h"

#include "startrek/detection.h"
#include "startrek/detection_tables.h"

static const PlainGameDescriptor starTrekGames[] = {
	{"st25", "Star Trek: 25th Anniversary"},
	{"stjr", "Star Trek: Judgment Rites"},
	{0, 0}
};

static const DebugChannelDef debugFlagList[] = {
	{StarTrek::kDebugSound, "sound", "Sound"},
	{StarTrek::kDebugGraphics, "graphics", "Graphics"},
	{StarTrek::kDebugSavegame, "savegame", "Savegames"},
	{StarTrek::kDebugSpace, "space", "Space and Pseudo-3D"},
	{StarTrek::kDebugGeneral, "general", "General"},
	DEBUG_CHANNEL_END
};


namespace StarTrek {

static const char *const directoryGlobs[] = {
	"misc",
	"database",
	0
};

} // End of namespace StarTrek

class StarTrekMetaEngineDetection : public AdvancedMetaEngineDetection<StarTrek::StarTrekGameDescription> {
public:
	StarTrekMetaEngineDetection() : AdvancedMetaEngineDetection(StarTrek::gameDescriptions, starTrekGames) {
		_maxScanDepth = 2;
		_directoryGlobs = StarTrek::directoryGlobs;
	}

	const DebugChannelDef *getDebugChannels() const override {
		return debugFlagList;
	}

	const char *getName() const override {
		return "startrek";
	}

	const char *getEngineName() const override {
		return "Star Trek";
	}

	const char *getOriginalCopyright() const override {
		return "Star Trek: 25th Anniversary, Star Trek: Judgment Rites (C) Interplay";
	}
};



REGISTER_PLUGIN_STATIC(STARTREK_DETECTION, PLUGIN_TYPE_ENGINE_DETECTION, StarTrekMetaEngineDetection);
