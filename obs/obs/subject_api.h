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
#ifndef SUBJECT_API_H
#define SUBJECT_API_H

#ifdef __cplusplus
extern "C"
{
#endif

	#include "observer_api.h"


	/** @config : share data define **/
	#define SBJ_DATA  OBS_DATA 

    /** @config : memory container for observers , must be bigger than 2 **/
    #define SUBJECT_S_MAX_OBSERVER_COUNT      10










	typedef enum {
		SUBJECT_FUNC_FAIL,
		SUBJECT_FUNC_SUCCESS
	}subject_func_out_types;



	typedef struct {

		SBJ_DATA *    data;
		 
		observer_obj* observers[SUBJECT_S_MAX_OBSERVER_COUNT];

		unsigned int  observer_count;

		char          _is_created;

	} subject_obj;



	/** API USER FUNCTIONS **/

	subject_func_out_types 
	subject_create(          subject_obj* me , SBJ_DATA* subject_data);

	subject_func_out_types 
	subject_add_observer(    subject_obj* me , observer_obj* observer);

	subject_func_out_types 
	subject_remove_observer( subject_obj* me , observer_obj* observer);

	subject_func_out_types
	subject_update_observers(subject_obj* me);

	subject_func_out_types
    subject_delete(subject_obj* me);


#ifdef __cplusplus
}
#endif

#endif