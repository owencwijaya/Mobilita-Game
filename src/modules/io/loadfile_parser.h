#include <stdio.h>

#include "../../models/location.h"
#include "../../models/location_list.h"
#include "../../models/point.h"
#include "../../models/boolean_matrix.h"
#include "../../models/item_queue.h"
#include "../../models/item.h"
#include "../../models/game_map.h"
#include "../../models/macros.h"
#include "../core/globals.h"
#include "./machines/wordmachine.h"
#include "word_utils.h"

void parseLoad(char *path);