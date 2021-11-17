#include <stdio.h>

#include "../models/map/location/location.h"
#include "../models/map/location/location_list.h"
#include "../models/map/location/point.h"
#include "../models/map/boolean_matrix.h"
#include "../models/item/item_queue.h"
#include "../models/item/item.h"
#include "../models/map/game_map.h"
#include "../models/shared/macros.h"
#include "../core/globals.h"
#include "./machines/wordmachine.h"
#include "word_utils.h"

void parseConfig(char *path);