#ifndef _Aligner_H_
#define _Aligner_H_

#include "BioSeq.h"

class PairwiseAlign {
private:
	int gap_open, gap_extension, gap_frame, stop_cost;
	int nt_score_matrix[128*128];
	int aa_score_matrix[128*128];
	
	int n, m;
	int size = 0;
	int* F = NULL; // score matrix
	int* W = NULL; // way matrix
	
	void NewScoreMatrix(const char* file_name, int* score_matrix);
	
public:
	PairwiseAlign(const char* nt_score_matrix, const char* aa_score_matrix,
			int stop_cost, int gap_open, int gap_extension, int frame_gap);
	~PairwiseAlign() { if (F) delete[] F; }
	//====================
	int Align(const BioSeq* s1, const BioSeq* s2);
	//====================
	void ChangeNTscoreMatrix(const char* file_name) {
		NewScoreMatrix(file_name, nt_score_matrix);
	}
	void ChangeAAscoreMatrix(const char* file_name) {
		NewScoreMatrix(file_name, aa_score_matrix);
	}
};

#endif