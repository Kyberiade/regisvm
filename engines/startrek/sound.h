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

#ifndef STARTREK_SOUND_H
#define STARTREK_SOUND_H

#include "startrek/soundeffects.h"
#include "startrek/startrek.h"

#include "audio/midiparser.h"
#include "audio/mididrv.h"
#include "audio/mixer.h"

namespace Common {
class MacResManager;
}

namespace Audio {
class RewindableAudioStream;
}

namespace StarTrek {

class AmigaSoundPlayer;
class MacSoundPlayer;
class StarTrekEngine;


// Max # of VOC files that can play at once
const int MAX_SFX_PLAYING = 4;

const int NUM_MIDI_SLOTS = 8;

struct MidiPlaybackSlot {
	int slot;
	int track;
	MidiParser *midiParser;
};


class Sound {
public:
	Sound(StarTrekEngine *vm);
	~Sound();

	void clearAllMidiSlots();
	/**
	 * Plays a midi track as a sound effect (one of midi slots 1-7)
	 */
	void playMidiTrack(MidiTracks track);
	void playMidiTrackInSlot(int slot, MidiTracks track);
	bool isMidiPlaying();
	bool isMT32() const;
	void loadMusicFile(const Common::String &baseSoundName);
	void playMidiMusicTracks(MidiTracks startTrack, MidiLoopType loopType = kLoopTypeNone);
	void playVoc(const Common::String &baseSoundName);
	void playSpeech(const Common::String &basename);
	void stopAllVocSounds();
	void stopPlayingSpeech();
	void playSoundEffectIndex(SoundEffects index);
	void setMusicEnabled(bool enable);
	void setSfxEnabled(bool enable);
	bool canToggleSfx() const;
	void toggleMusic();
	void toggleSfx();
	void syncSoundSettings();

	// The DOS demo plays MIDI files, for the MT-32 only. The setup of the
	// MT-32 plays along the music.
	void playDemoMusic(const Common::String &name);
	void startDemoMusicSetup();
	bool isDemoMusicSetupPlaying();
	void stopDemoMusic();
	void playDemoJingle(const Common::String &name);
	void restartDemoMusic();

	void checkLoopMusic();
	MidiTracks getPlayingMidiTrack();
	bool isPlayingSpeech() const;

private:
	StarTrekEngine *_vm;
	Audio::SoundHandle *_soundHandle;

	void loadPCMusicFile(const Common::String &baseSoundName);
	void clearMidiSlot(int slot);

	/**
	 * Opens a sound of the CD versions, given as "<dir>\\<name>": a VOC file in "voc",
	 * or a QuickTime movie in "Voice Data" on the Mac. Sets loop if a VOC file repeats.
	 */
	Audio::RewindableAudioStream *openCDSound(const Common::String &name, bool *loop);

	// The players of the Amiga and Mac versions, which replace the MIDI tracks
	AmigaSoundPlayer *_amigaPlayer;
	MacSoundPlayer *_macPlayer;

	// MIDI-Related Variables
	MidiDriver *_midiDriver;
	MidiPlaybackSlot _midiSlots[NUM_MIDI_SLOTS]; // 0 is for music; 1-7 are for sfx
	Common::List<MidiPlaybackSlot *> _midiSlotList; // Sorts midi slots by most recently used

	byte *_loadedSoundData;
	int _loadedSoundDataSize;
	byte *_demoMusicData[2];
	Common::String _demoBackgroundMusic;

	void playDemoMidiFile(int slot, const Common::String &name);
	uint32 _midiDevice;

	// VOC-related variables
	Audio::SoundHandle _sfxHandles[MAX_SFX_PLAYING];
	Audio::SoundHandle _speechHandle;
	bool _playingSpeech;

public:
	Common::String _loopingAudioName;
	Common::String _loadedMidiFilename;
	MidiTracks _loopingMidiTrack;

private:
	// Driver callback
	static void midiDriverCallback(void *data);
};

} // End of namespace StarTrek

#endif
