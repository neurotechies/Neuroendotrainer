#ifndef Scorer_Included
#define Scorer_Included

#include <vector>
#include <string>
#include <iostream>
using namespace std;
#define HITTING_THRESHOLD_SENSOR1 10
#define HITTING_THRESHOLD_SENSOR2 10


struct Activity
{
	// struct definitions
	struct stationary
	{
        int startIndex, endIndex;
        string startTime, endTime;  // Time of starting and ending of the activity
        vector<pair<string, pair<int, int> > > hitting; // Hitting values in these times
        vector<pair<string, pair<double, double> > > trackingData; // Tracking Data in the stationary activity
        //vector<int> framesForTrackingFailure;
        //vector<int> framesForTrackingReinit;
        //vector<int> framesForRingHitting;
		stationary()
		{
            startIndex = -1;
            endIndex = -1;
            startTime = "";
            endTime = "";
		}
		void clear()
		{
            startIndex = -1;
            endIndex = -1;
            startTime = "";
            endTime = "";
			hitting.clear();
			trackingData.clear();
            //framesForTrackingFailure.clear();
            //framesForRingHitting.clear();
            //framesForTrackingReinit.clear();
		}
	};
	struct Picking
	{
        int startIndex, endIndex;
        string startTime, endTime;
		int from_peg;
        vector<pair<string, pair<int, int> > > hitting;
        vector<pair<string, pair<double, double> > > trackingData;
        //vector<int> framesForTrackingFailure;
        //vector<int> framesForRingHitting;
        //vector<int> framesForTrackingReinit;
		Picking()
		{
            startIndex = -1;
            endIndex = -1;
            startTime = "";
            endTime = "";
            from_peg = -1;
		}
		void clear()
		{
            startIndex = -1;
            endIndex = -1;
            startTime = "";
            endTime = "";
            from_peg = -1;
			hitting.clear();
			trackingData.clear();
            //framesForTrackingFailure.clear();
            //framesForRingHitting.clear();
            //framesForTrackingReinit.clear();
		}
	};
	struct Moving
	{
        int startIndex, endIndex;
        string startTime, endTime;
        int from_peg, to_peg;
        vector<pair<string, pair<int, int> > > hitting;
        vector<pair<string, pair<double, double> > > trackingData;
        //vector<int> framesForTrackingFailure;
        //vector<int> framesForRingHitting;
        //vector<int> framesForTrackingReinit;
		Moving()
		{
            startIndex = -1;
            endIndex = -1;
            startTime = "";
            endTime = "";
            from_peg = -1;
            to_peg = -1;
		}
		void clear()
		{
            startIndex = -1;
            endIndex = -1;
            startTime = "";
            endTime = "";
            from_peg = -1;
            to_peg = -1;
			hitting.clear();
			trackingData.clear();
            //framesForTrackingFailure.clear();
            //framesForRingHitting.clear();
            //framesForTrackingReinit.clear();
		}
	};
	string  type;
	stationary s;
	Picking p;
	Moving m;

	Activity()
	{
		type = "";
	}
	void clear()
	{
		type = "";
		s.clear();
		p.clear();
		m.clear();
	}
    void print()
    {
        if(type == "stationary")
        {
            cout << "\nActivity -> Stationary\n" << "Start-Time -> " << s.startTime << " End-Time->" << s.endTime << endl;
            cout << "Hitting Data\n";
            for(unsigned int i = 0; i <  s.hitting.size(); i++)
            {
                cout << "time->" << s.hitting[i].first << "  vals->(" << s.hitting[i].second.first << "," << s.hitting[i].second.second << ")\n";
            }
            cout << "Tracking Data\n";
            for(unsigned int i = 0; i <  s.trackingData.size(); i++)
            {
                cout << "time->" << s.trackingData[i].first << "  vals->(" << s.trackingData[i].second.first << "," << s.trackingData[i].second.second << ")\n";
            }
        }
        else if(type == "picking")
        {
            cout << "\nActivity -> Picking\n" << "Start-Time -> " << p.startTime << " End-Time->" << p.endTime << endl;
            cout << "From-Peg -> " << p.from_peg << endl;
            cout << "Hitting Data\n";
            for(unsigned int i = 0; i <  p.hitting.size(); i++)
            {
                cout << "time->" << p.hitting[i].first << "  vals->(" << p.hitting[i].second.first << "," << p.hitting[i].second.second << ")\n";
            }
            cout << "Tracking Data\n";
            for(unsigned int i = 0; i <  p.trackingData.size(); i++)
            {
                cout << "time->" << p.trackingData[i].first << "  vals->(" << p.trackingData[i].second.first << "," << p.trackingData[i].second.second << ")\n";
            }

        }
        else if(type == "moving")
        {
            cout << "\nActivity -> Moving\n" << "Start-Time -> " << m.startTime << " End-Time->" << m.endTime << endl;
            cout << "From-Peg-> " << m.from_peg <<  " To-Peg-> " << m.to_peg << endl;
            cout << "Hitting Data\n";
            for(unsigned int i = 0; i <  m.hitting.size(); i++)
            {
                cout << "time->" << m.hitting[i].first << "  vals->(" << m.hitting[i].second.first << "," << m.hitting[i].second.second << ")\n";
            }
            cout << "Tracking Data\n";
            for(unsigned int i = 0; i <  m.trackingData.size(); i++)
            {
                cout << "time->" << m.trackingData[i].first << "  vals->(" << m.trackingData[i].second.first << "," << m.trackingData[i].second.second << ")\n";
            }
        }
    }
};

struct Result
{
	struct Hitting
	{
		vector<pair <int, int> > hittingData;
		double hittingScore;
		Hitting()
		{
			hittingScore = 0;
			hittingData.clear();
		}
		void clear()
		{
			hittingScore = 0;
			hittingData.clear();
		}
	};

	struct Grasping
	{
		vector<pair <int, int> > NoFramesPicking;
		vector <vector <pair<double, double> > > trackingData;
		vector<pair <int, double> > trackingMean;
		double grapspingScore;
		double grapspingTrackingScore;
		Grasping()
		{
			NoFramesPicking.clear();
			trackingMean.clear();
			grapspingScore = 0;
			grapspingTrackingScore = 0;
		}
		void clear()
		{
			NoFramesPicking.clear();
			trackingMean.clear();
			grapspingScore = 0;
			grapspingTrackingScore = 0;
		}
	};
	
	struct WavyMotion
	{
		vector<pair<pair<int, int>, int> > NoFramesMoving;     //               to,  from, No of frames  
		vector <vector <pair<double, double> > > trackingData; //           tracking Data
		vector<pair<pair<int, int>, double> > trackingMean;    //               to,  from, trackingResult  
		double wavyMotionScore;
		double wavyMotionTrackingScore;
		WavyMotion()
		{
			NoFramesMoving.clear();
			trackingMean.clear();
			wavyMotionScore = 0; 
			wavyMotionTrackingScore = 0;
		}
		void clear()
		{
			NoFramesMoving.clear();
			trackingMean.clear();
			wavyMotionScore = 0;
			wavyMotionTrackingScore = 0;
		}

	};

	struct RingHitting_wrongPlacement
	{
		vector<pair<string, int> > frameRingHitting;  // activity , frame no
		double ringHittingScore;
		RingHitting_wrongPlacement()
		{
			frameRingHitting.clear();
			ringHittingScore = 0;
		}
		void clear()
		{
			frameRingHitting.clear();
			ringHittingScore = 0;
		}
	};

	struct suddenMovement
	{
		vector<pair<string, int> > frameTrackingFailed;
		double suddenMovementScore;
		suddenMovement()
		{
			frameTrackingFailed.clear();
			suddenMovementScore = 0;
		}
		void clear()
		{
			frameTrackingFailed.clear();
			suddenMovementScore = 0;
		}
	};

	struct wrongMoves
	{
		vector<pair<int, int> > rightMoves;
		vector<pair<int, int> > wrong_moves;
		double wrongMovesScore;
		wrongMoves()
		{
			wrongMovesScore = 0;
			rightMoves.clear();
			rightMoves.push_back(make_pair(5, 8));
			rightMoves.push_back(make_pair(2, 11));
			rightMoves.push_back(make_pair(4, 7));
			rightMoves.push_back(make_pair(1, 10));
			rightMoves.push_back(make_pair(3, 6));
			rightMoves.push_back(make_pair(0, 9));

			rightMoves.push_back(make_pair(9, 2));
			rightMoves.push_back(make_pair(6, 5)); 
			rightMoves.push_back(make_pair(10, 1));
			rightMoves.push_back(make_pair(7, 4));
			rightMoves.push_back(make_pair(11, 0));
			rightMoves.push_back(make_pair(8, 3));
		}

		void clear()
		{
			wrongMovesScore = 0;
			rightMoves.clear();
			rightMoves.push_back(make_pair(5, 8));
			rightMoves.push_back(make_pair(2, 11));
			rightMoves.push_back(make_pair(4, 7));
			rightMoves.push_back(make_pair(1, 10));
			rightMoves.push_back(make_pair(3, 6));
			rightMoves.push_back(make_pair(0, 9));

			rightMoves.push_back(make_pair(9, 2));
			rightMoves.push_back(make_pair(6, 5));
			rightMoves.push_back(make_pair(10, 1));
			rightMoves.push_back(make_pair(7, 4));
			rightMoves.push_back(make_pair(11, 0));
			rightMoves.push_back(make_pair(8, 3));
		}
	};
	struct No_Activity
	{
		int no_frames;
		vector<vector<pair <double, double > > > trackingData;
		double trackingScore;
		double trackingScore2;
		No_Activity()
		{
			no_frames = 0;
			trackingScore = 0;
			trackingScore2 = 0;
		}
		void clear()
		{
			no_frames = 0;
			trackingScore = 0;
			trackingScore2 = 0;
			trackingData.clear();
		}
	};


	double totalScore;
	Hitting hitting;
	Grasping grasping;
	WavyMotion wavymotion;
	RingHitting_wrongPlacement ringHItting;
	suddenMovement suddenmovement;
	wrongMoves wrongmoves;
	No_Activity noactivity;
	Result()
	{
		totalScore = 0;
	}

	void clear()
	{
		totalScore = 0;
		hitting.clear();
		grasping.clear();
		wavymotion.clear();
		ringHItting.clear();
		suddenmovement.clear();
		wrongmoves.clear();
		noactivity.clear();
	}
};

#endif
