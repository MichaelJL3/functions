
#include "metrics.h"

double getStrength(int posts, int totPosts, int known){
	return 1+((double)posts/totPosts)*known;
}
