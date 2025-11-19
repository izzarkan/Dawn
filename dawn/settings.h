#pragma once
#ifndef SETTINGS_H
#define SETTINGS_H

struct Settings {
    int difficulty;
    bool fullscreen;
};

void loadSettings(Settings& s);
void saveSettings(const Settings& s);
void settingsMenu(Settings& s);
void openSettings();

#endif