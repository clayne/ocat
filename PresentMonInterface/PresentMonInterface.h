/*
Copyright 2017 Intel Corporation

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
of the Software, and to permit persons to whom the Software is furnished to do
so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#pragma once

#include "Recording.h"
#include "Config\BlackList.h"

#include <Windows.h>
#include <string>

struct CommandLineArgs;

class PresentMonInterface
{
public:
  PresentMonInterface();
  ~PresentMonInterface();

  bool Init(HWND hwnd);
  void ToggleRecording(bool recordAllProcesses, unsigned int hotkey, unsigned int timer, int recordingDetail);
  const std::wstring GetRecordedProcess();
  bool CurrentlyRecording();
  int GetPresentMonRecordingStopMessage();


private:
  void StartRecording(bool recordAllProcesses, unsigned int hotkey, unsigned int timer, int recordingDetail);
  void StopRecording();
  void SetPresentMonArgs(unsigned int hotkey, unsigned int timer, int recordingDetail);

  Recording recording_;
  CommandLineArgs* args_ = nullptr;
  std::vector<std::string> blackList_;
};
