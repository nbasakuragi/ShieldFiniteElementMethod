#----------------------------------------------------------------------------------
# File:        jni/nv_math/Android.mk
# SDK Version: v10.14 
# Email:       tegradev@nvidia.com
# Site:        http://developer.nvidia.com/
#
# Copyright (c) 2007-2012, NVIDIA CORPORATION.  All rights reserved.
#
# TO  THE MAXIMUM  EXTENT PERMITTED  BY APPLICABLE  LAW, THIS SOFTWARE  IS PROVIDED
# *AS IS*  AND NVIDIA AND  ITS SUPPLIERS DISCLAIM  ALL WARRANTIES,  EITHER  EXPRESS
# OR IMPLIED, INCLUDING, BUT NOT LIMITED  TO, IMPLIED WARRANTIES OF MERCHANTABILITY
# AND FITNESS FOR A PARTICULAR PURPOSE.  IN NO EVENT SHALL  NVIDIA OR ITS SUPPLIERS
# BE  LIABLE  FOR  ANY  SPECIAL,  INCIDENTAL,  INDIRECT,  OR  CONSEQUENTIAL DAMAGES
# WHATSOEVER (INCLUDING, WITHOUT LIMITATION,  DAMAGES FOR LOSS OF BUSINESS PROFITS,
# BUSINESS INTERRUPTION, LOSS OF BUSINESS INFORMATION, OR ANY OTHER PECUNIARY LOSS)
# ARISING OUT OF THE  USE OF OR INABILITY  TO USE THIS SOFTWARE, EVEN IF NVIDIA HAS
# BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
#
#
#----------------------------------------------------------------------------------

LOCAL_PATH := $(subst //,/,$(call my-dir))

include $(CLEAR_VARS)

LOCAL_MODULE := nv_math
MY_LOCAL_SRC_FILES := nv_math.cpp nv_matrix.cpp nv_quat.cpp

include $(LOCAL_PATH)/../nv_static_lib.mk
