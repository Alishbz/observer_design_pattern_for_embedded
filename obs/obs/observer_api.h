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
#pragma once
#ifndef OBSERVER_API_H
#define OBSERVER_API_H 
#ifdef __cplusplus
extern "C"
{
#endif

	#include <stdio.h> 
	#include <stdlib.h> 

    /** @config : share data type declerate  **/
    typedef unsigned char observer_data_type_1;
	typedef unsigned int  observer_data_type_2; 
	typedef float         observer_data_type_3;
	/** CAN BE ADD MORE **/

	/** @config : share data define **/
    #define OBS_DATA  observer_data_type_2 

	/** @config : importand for log and debug **/
    #define OBSERVER_SPACIAL_OBJECT_NOTIFYS_ACTIVE  1









	/** @SPECÝAL EVENTS *********/
	typedef enum {
		OBSERVER_EVENT_FAIL,
		OBSERVER_EVENT_FIRST_LOAD,
		OBSERVER_EVENT_SUBJECT_ADDED,
		OBSERVER_EVENT_SUBJECT_DELETED,
		OBSERVER_EVENT_DELETED,
		OBSERVER_EVENT_EMPTY,
		OBSERVER_EVENT_UPDATE,
		OBSERVER_EVENT_TIMEOUT,
		OBSERVER_EVENT_SAME_EVENT
		/*** CAN BE ADD MORE  ***/
	}observer_event_types;






	typedef enum {
		OBSERVER_FUNC_FAIL,
		OBSERVER_FUNC_SUCCESS
	}observer_func_out_types;




    typedef void (*observer_event_callback_fp)(observer_event_types event , OBS_DATA data);


	typedef struct {

		/** @private  **/ 
        char                        _is_observation_active;

        observer_event_types        _last_event;
		 
		observer_event_callback_fp  _e_calback; 

	} observer_obj;



	/** API USER FUNCTIONS **/

	observer_func_out_types 
	observer_create(observer_obj * me  , observer_event_callback_fp my_callback);  

	observer_func_out_types
    observer_update(observer_obj* me, observer_event_types event, OBS_DATA data );

	observer_func_out_types
    observer_stop_watch(observer_obj* me);

	observer_func_out_types
    observer_start_watch(observer_obj* me);

	observer_func_out_types
    observer_delete(observer_obj* me);

#ifdef __cplusplus
}
#endif
#endif