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
#include "observer_api.h"
  

observer_func_out_types
observer_create(observer_obj* me, observer_event_callback_fp my_callback)
{
	if (me == NULL || my_callback == NULL) { 
		return OBSERVER_FUNC_FAIL; 
	}
	me->_e_calback = my_callback;

	me->_is_observation_active = 1;
	 
	me->_last_event = OBSERVER_EVENT_EMPTY;

#ifdef OBSERVER_SPACIAL_OBJECT_NOTIFYS_ACTIVE
	/** first call for notify load success **/
	observer_update(me,OBSERVER_EVENT_FIRST_LOAD , NULL);
#endif

	/** @ATTANTION, AFTER CREATION YOU MUST CALL -> observer_start_watch ***/
	observer_stop_watch(me);

	return OBSERVER_FUNC_SUCCESS; 
}




observer_func_out_types
observer_update(observer_obj* me, observer_event_types event, OBS_DATA data)
{
	if ( me == NULL || event == OBSERVER_EVENT_FAIL || me->_is_observation_active == 0 ) {
		return OBSERVER_FUNC_FAIL;
	}

	/*** @callback for MASTER App  ***/
	me->_e_calback(event , data);

	me->_last_event = event;

	return OBSERVER_FUNC_SUCCESS;
}

observer_func_out_types
observer_stop_watch(observer_obj* me)
{
	if (me == NULL) {
		return OBSERVER_FUNC_FAIL;
	}

	me->_is_observation_active = 0;

	return OBSERVER_FUNC_SUCCESS;
}

observer_func_out_types
observer_start_watch(observer_obj* me)
{
	if (me == NULL) {
		return OBSERVER_FUNC_FAIL;
	}

	me->_is_observation_active = 1;

	return OBSERVER_FUNC_SUCCESS;
}

observer_func_out_types
observer_delete(observer_obj* me)
{ 
	if (me == NULL  ) {
		return OBSERVER_FUNC_FAIL;
	}

#ifdef OBSERVER_SPACIAL_OBJECT_NOTIFYS_ACTIVE  
	/** first call for notify load success **/
	observer_update(me, OBSERVER_EVENT_DELETED, NULL);
#endif

	observer_stop_watch(me);

	me->_e_calback = NULL;
	  
	me->_last_event = OBSERVER_EVENT_FAIL;
	  
	return OBSERVER_FUNC_SUCCESS;
}