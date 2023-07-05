/****************************************************************************************
* ALI SAHBAZ
*
*
* ASZ Framework
*
* Date          : 05.07.2023
* By            : Ali Þahbaz
* e-mail        : ali_sahbaz@outlook.com
*/
#include <stdio.h> 
#include <stdlib.h> 
#include "subject_api.h"

static SBJ_DATA temp_sensor_test_data = 4;

#define TEST_EVENT_PRINT(event_str)     printf("%s : %s ; %d , %d\n", print_str,(const char*)event_str,(int)event, (int)data);

static void _event_test_print(const char* print_str, observer_event_types event, OBS_DATA data)
{
    switch (event)
    {
    case OBSERVER_EVENT_FAIL:
        TEST_EVENT_PRINT("OBSERVER_EVENT_FAIL");
        break;
    case OBSERVER_EVENT_FIRST_LOAD:
        TEST_EVENT_PRINT("OBSERVER_EVENT_FIRST_LOAD");
        break;
    case OBSERVER_EVENT_SUBJECT_ADDED:
        TEST_EVENT_PRINT("OBSERVER_EVENT_SUBJECT_ADDED");
        break;
    case OBSERVER_EVENT_SUBJECT_DELETED:
        TEST_EVENT_PRINT("OBSERVER_EVENT_SUBJECT_DELETED");
        break;
    case OBSERVER_EVENT_DELETED:
        TEST_EVENT_PRINT("OBSERVER_EVENT_DELETED");
        break;
    case OBSERVER_EVENT_EMPTY:
        TEST_EVENT_PRINT("OBSERVER_EVENT_EMPTY");
        break;
    case OBSERVER_EVENT_UPDATE:
        TEST_EVENT_PRINT("OBSERVER_EVENT_UPDATE");
        break;
    case OBSERVER_EVENT_TIMEOUT:
        TEST_EVENT_PRINT("OBSERVER_EVENT_TIMEOUT");
        break;
    case OBSERVER_EVENT_SAME_EVENT:
        TEST_EVENT_PRINT("OBSERVER_EVENT_SAME_EVENT");
        break;
        /**** can be more event  ***/
    default:
        TEST_EVENT_PRINT("undefined event");
        break;
    }
}

static void _test_callback_fp_1(observer_event_types event, OBS_DATA data)
{
    // todo
    _event_test_print("_test_callback_fp_1", event, data);
}

static void _test_callback_fp_2(observer_event_types event, OBS_DATA data)
{
    // todo 
    _event_test_print("_test_callback_fp_2", event, data);
}

static void _test_callback_fp_3(observer_event_types event, OBS_DATA data)
{
    // todo 
    _event_test_print("_test_callback_fp_3", event, data);
}


void OBSERVER_SUBJECT_TEST_1(void) {

    printf("Observer Pattern Design Test Starting ...\n");
    printf("Created by Ali Þahbaz ...\n\n\n");
      
    subject_obj temp_sensor;
    subject_create(&temp_sensor, &temp_sensor_test_data);

    observer_obj display_1;
    observer_create(&display_1, &_test_callback_fp_1);

    observer_obj display_2;
    observer_create(&display_2, &_test_callback_fp_2);

    observer_obj display_3;
    observer_create(&display_3, &_test_callback_fp_3);

    observer_start_watch(&display_1);
    observer_start_watch(&display_2);
    observer_start_watch(&display_3);

    subject_add_observer(&temp_sensor, &display_1);
    subject_add_observer(&temp_sensor, &display_2);
    subject_add_observer(&temp_sensor, &display_3);

    temp_sensor_test_data = 8;
    subject_update_observers(&temp_sensor);
    temp_sensor_test_data = 9;
    subject_update_observers(&temp_sensor);
    temp_sensor_test_data = 10;
    subject_update_observers(&temp_sensor);
    temp_sensor_test_data = 11;
    subject_update_observers(&temp_sensor);


    subject_remove_observer(&temp_sensor, &display_2);

    temp_sensor_test_data = 12;
    subject_update_observers(&temp_sensor);
    temp_sensor_test_data = 13;
    subject_update_observers(&temp_sensor);
    temp_sensor_test_data = 14;
    subject_update_observers(&temp_sensor);
    temp_sensor_test_data = 15;
    subject_update_observers(&temp_sensor);

    /** optional ;
    observer_delete(&display_1);   ...
    **/

    observer_delete(&display_1);
    observer_delete(&display_2);
    observer_delete(&display_3);

    subject_delete(&temp_sensor);

    printf("\n\n\nTEST END ...\n\n\n");
}