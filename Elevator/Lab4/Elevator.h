#pragma once

#include "Engine.h"
#include "Doors.h"

#include "Logger.h"

namespace Elevator
{
	using namespace System::Collections::Generic;

	public ref class Elevator
	{
	public:
		delegate void MoveUp();
		delegate void MoveDown();
		delegate void Stop();
		delegate void Open();

		event MoveUp^ doMoveUp;
		event MoveDown^ doMoveDown;
		event Stop^ doStop;
		event Open^ doOpening;

		Elevator()
			: mState(State::IDLE)
			, mEngine(gcnew Engine())
			, mDoors(gcnew Doors())
			, mCurrentLevel(0)
			, mRequestedLevels(gcnew SortedSet<int>())
		{
			doMoveUp += gcnew MoveUp(mEngine, &Engine::onMoveUp);
			doMoveDown += gcnew MoveDown(mEngine, &Engine::onMoveDown);
			doStop += gcnew Stop(mEngine, &Engine::onStop);
			mEngine->doMovedUp += gcnew Engine::MovedUp(this, &Elevator::onMovingUp);
			mEngine->doMovedDown += gcnew Engine::MovedDown(this, &Elevator::onMovingDown);
			mEngine->doStopped += gcnew Engine::Stopped(this, &Elevator::onIdle);

			doOpening += gcnew Open(mDoors, &Doors::onOpening);
			mDoors->doOpening += gcnew Doors::Opening(this, &Elevator::onOpening);
			mDoors->doOpened+= gcnew Doors::Opened(this, &Elevator::onOpened);
			mDoors->doClosing += gcnew Doors::Closing(this, &Elevator::onClosing);
			mDoors->doClosed += gcnew Doors::Closed(this, &Elevator::onIdle);
		}

		void onRequested(int level)
		{
			Logger::Log("# Calling from floor: " + level.ToString());
			mRequestedLevels->Add(level);
			if (mState == State::IDLE)
			{
				int nearestRequestedLevel = getNearestRequestedLevel();
				if (nearestRequestedLevel != -1)
					if (nearestRequestedLevel > mCurrentLevel)
						doMoveUp();
					else if (nearestRequestedLevel < mCurrentLevel)
						doMoveDown();
					else
						doOpening();
			}
		}

		void onMovingUp()
		{
			++mCurrentLevel;
			Logger::Log("- Passing floor: " + mCurrentLevel.ToString());
			if (mRequestedLevels->Contains(mCurrentLevel))
				doStop();
			mState = State::MOVING_UP;
		}

		void onMovingDown()
		{
			--mCurrentLevel;
			Logger::Log("- Passing floor: " + mCurrentLevel.ToString());
			if (mRequestedLevels->Contains(mCurrentLevel))
				doStop();
			mState = State::MOVING_DOWN;
		}

		void onIdle()
		{
			if(mState == State::CLOSING)
				onClosed();
			else if(mState == State::MOVING_UP || mState == State::MOVING_DOWN)
				onStop();
				    
			if (mState == State::IDLE)
			{	
				int nearestRequestedLevel = getNearestRequestedLevel();
				if (nearestRequestedLevel != -1)
					if(nearestRequestedLevel > mCurrentLevel)
						doMoveUp();
					else if(nearestRequestedLevel < mCurrentLevel)
					    doMoveDown();
				    else
					    doOpening();
			}
		}

		void onOpening()
		{
			Logger::Log("  Door is now opening...");
			mState = State::OPENING;
		}

		void onOpened()
		{
			Logger::Log(". Door is opened!");
			mRequestedLevels->Remove(mCurrentLevel);
			mState = State::OPENED;
		}

		void onClosing()
		{
			Logger::Log("  Door is now closing...");
			mState = State::CLOSING;
		}

		void onClosed()
		{
			Logger::Log(". Door is closed!");
			mState = State::IDLE;
		}

		void onStop()
		{
			Logger::Log(". Elevator has stopped.");
			mState = State::IDLE;
		}

	private:
		enum class State
		{
			MOVING_UP,
			MOVING_DOWN, 
			IDLE,
			OPENING,
			OPENED,
			CLOSING,
		};

		State mState;
		Engine^ mEngine;
		Doors^ mDoors;
		int mCurrentLevel;
		SortedSet<int>^ mRequestedLevels;

		int getNearestRequestedLevel()
		{
			int nearestRequestedLevel = -1;
			for (auto requestedLevel = mRequestedLevels->GetEnumerator(); requestedLevel.MoveNext();)
				if ((nearestRequestedLevel == -1) || (Math::Abs(mCurrentLevel - requestedLevel.Current) < 
					                                  Math::Abs(mCurrentLevel - nearestRequestedLevel)))
					nearestRequestedLevel = requestedLevel.Current;
			return nearestRequestedLevel;
		}
	};
}