#pragma once

#include "Logger.h"

namespace Elevator
{
	using namespace System;

	public ref class Engine
	{
	public:
		delegate void Started();
		delegate void MovedUp();
		delegate void MovedDown();
		delegate void Stopped();

		event Started^ doStarted;
		event MovedUp^ doMovedUp;
		event MovedDown^ doMovedDown;
		event Stopped^ doStopped;

		Engine()
			: mState(State::IDLE)
			, mTimer(nullptr)
		{}

		void onStop()
		{
			if (mState == State::IDLE)
				throw gcnew InvalidOperationException();
			delete mTimer;
			doStopped();
			mState = State::IDLE;
		}

		void onMoveUp()
		{
			if (mState != State::IDLE)
				throw gcnew InvalidOperationException();
			doStarted();
			mTimer = gcnew Timer();
			mTimer->Interval = 1500;
			mTimer->Tick += gcnew EventHandler(this, &Engine::doMovedUpEmitter);
			mTimer->Enabled = true;
			mState = State::MOVING_UP;
		}

		void onMoveDown()
		{
			if (mState != State::IDLE)
				throw gcnew InvalidOperationException();
			doStarted();
			mTimer = gcnew Timer();
			mTimer->Interval = 1500;
			mTimer->Tick += gcnew EventHandler(this, &Engine::doMovedDownEmitter);
			mTimer->Enabled = true;
			mState = State::MOVING_DOWN;
		}

	private:
		enum class State
		{
			IDLE,
			MOVING_UP,
			MOVING_DOWN,
		};

		State mState;
		Timer^ mTimer;

		void doMovedUpEmitter(Object^, EventArgs^)
		{
			doMovedUp();
		}

		void doMovedDownEmitter(Object^, EventArgs^)
		{
			doMovedDown();
		}
	};
}