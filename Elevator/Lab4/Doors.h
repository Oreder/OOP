#pragma once

#include "Logger.h"

namespace Elevator
{
	public ref class Doors
	{
	public:
		delegate void Opening();
		delegate void Opened();
		delegate void Closing();
		delegate void Closed();

		event Opening^ doOpening;
		event Opened^ doOpened;
		event Closing^ doClosing;
		event Closed^ doClosed;

		Doors()
			: mState(State::CLOSED)
			, mTimer(nullptr)
		{}

		void onOpening()
		{
			if (mState != State::CLOSED)
				throw gcnew InvalidOperationException();
			doOpening();
			mTimer = gcnew Timer();
			mTimer->Interval = 800;
			mTimer->Tick += gcnew EventHandler(this, &Doors::onOpened);
			mTimer->Enabled = true;
			mState = State::OPENING;
		}

		void onOpened(Object^, EventArgs^)
		{
			if (mState != State::OPENING)
				throw gcnew InvalidOperationException();
			delete mTimer;
			doOpened();
			mTimer = gcnew Timer();
			mTimer->Interval = 2500;
			mTimer->Tick += gcnew EventHandler(this, &Doors::onClosing);
			mTimer->Enabled = true;
			mState = State::OPENED;
		}

		void onClosing(Object^, EventArgs^)
		{
			if (mState != State::OPENED)
				throw gcnew InvalidOperationException();
			delete mTimer;
			doClosing();
			mTimer = gcnew Timer();
			mTimer->Interval = 800;
			mTimer->Tick += gcnew EventHandler(this, &Doors::onClosed);
			mTimer->Enabled = true;
			mState = State::CLOSING;
		}

		void onClosed(Object^, EventArgs^)
		{
			if (mState != State::CLOSING)
				throw gcnew InvalidOperationException();
			delete mTimer;
			doClosed();
			mState = State::CLOSED;
		}

	private:
		enum class State
		{
			CLOSED,
			OPENING,
			OPENED,
			CLOSING,
		};

		State mState;
		Timer^ mTimer;
	};
}