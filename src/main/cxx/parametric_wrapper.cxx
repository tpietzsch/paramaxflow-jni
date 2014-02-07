#include <iostream>

#include "net_imglib2_paramaxflow_Parametric.h"
#include "parametric.h"
#include <jni.h>

/*
 * Class:     net_imglib2_paramaxflow_Parametric
 * Method:    constructor
 * Signature: (II)J
 */
JNIEXPORT jlong JNICALL Java_net_imglib2_paramaxflow_Parametric_constructor
  (JNIEnv *, jclass, jint nodeNumMax, jint edgeNumMax )
{
	return reinterpret_cast< jlong >( new Parametric( nodeNumMax, edgeNumMax ) );
}

/*
 * Class:     net_imglib2_paramaxflow_Parametric
 * Method:    destructor
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_net_imglib2_paramaxflow_Parametric_destructor
  (JNIEnv *, jclass, jlong ptr_this)
{
	Parametric* p = reinterpret_cast< Parametric* >( ptr_this );
	delete p;
}

/*
 * Class:     net_imglib2_paramaxflow_Parametric
 * Method:    AddNode
 * Signature: (JI)J
 */
JNIEXPORT jlong JNICALL Java_net_imglib2_paramaxflow_Parametric_AddNode
  (JNIEnv *, jclass, jlong ptr_this, jint num)
{
	Parametric* p = reinterpret_cast< Parametric* >( ptr_this );
	return p->AddNode( num );
}

/*
 * Class:     net_imglib2_paramaxflow_Parametric
 * Method:    AddUnaryTerm
 * Signature: (JJDD)V
 */
JNIEXPORT void JNICALL Java_net_imglib2_paramaxflow_Parametric_AddUnaryTerm
  (JNIEnv *, jclass, jlong ptr_this, jlong i, jdouble A, jdouble B)
{
	Parametric* p = reinterpret_cast< Parametric* >( ptr_this );
	return p->AddUnaryTerm( i, A, B );
}

/*
 * Class:     net_imglib2_paramaxflow_Parametric
 * Method:    AddPairwiseTerm
 * Signature: (JJJDDDD)V
 */
JNIEXPORT void JNICALL Java_net_imglib2_paramaxflow_Parametric_AddPairwiseTerm
  (JNIEnv *, jclass, jlong ptr_this, jlong i, jlong j, jdouble E00, jdouble E01, jdouble E10, jdouble E11)
{
	Parametric* p = reinterpret_cast< Parametric* >( ptr_this );
	p->AddPairwiseTerm( i, j, E00, E01, E10, E11 );
}

/*
 * Class:     net_imglib2_paramaxflow_Parametric
 * Method:    Solve
 * Signature: (JDD)J
 */
JNIEXPORT jlong JNICALL Java_net_imglib2_paramaxflow_Parametric_Solve
  (JNIEnv *, jclass, jlong ptr_this, jdouble lambdaMin, jdouble lambdaMax)
{
	Parametric* p = reinterpret_cast< Parametric* >( ptr_this );
	return p->Solve( lambdaMin, lambdaMax );
}

/*
 * Class:     net_imglib2_paramaxflow_Parametric
 * Method:    GetRegionCount
 * Signature: (JJ)J
 */
JNIEXPORT jlong JNICALL Java_net_imglib2_paramaxflow_Parametric_GetRegionCount
  (JNIEnv *, jclass, jlong ptr_this, jlong ptr_r)
{
	Parametric* p = reinterpret_cast< Parametric* >( ptr_this );
	return p->GetRegionCount( reinterpret_cast< Parametric::RegionId >( ptr_r ) );
}

/*
 * Class:     net_imglib2_paramaxflow_Parametric
 * Method:    GetRegion
 * Signature: (JJ)J
 */
JNIEXPORT jlong JNICALL Java_net_imglib2_paramaxflow_Parametric_GetRegion
  (JNIEnv *, jclass, jlong ptr_this, jlong i)
{
	Parametric* p = reinterpret_cast< Parametric* >( ptr_this );
	return reinterpret_cast< jlong >( p->GetRegion( i ) );
}

/*
 * Class:     net_imglib2_paramaxflow_Parametric
 * Method:    GetFirstRegion
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_net_imglib2_paramaxflow_Parametric_GetFirstRegion
  (JNIEnv *, jclass, jlong ptr_this)
{
	Parametric* p = reinterpret_cast< Parametric* >( ptr_this );
	return reinterpret_cast< jlong >( p->GetFirstRegion() );
}

/*
 * Class:     net_imglib2_paramaxflow_Parametric
 * Method:    GetLastRegion
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_net_imglib2_paramaxflow_Parametric_GetLastRegion
  (JNIEnv *, jclass, jlong ptr_this)
{
	Parametric* p = reinterpret_cast< Parametric* >( ptr_this );
	return reinterpret_cast< jlong >( p->GetLastRegion() );
}

/*
 * Class:     net_imglib2_paramaxflow_Parametric
 * Method:    GetNextRegion
 * Signature: (JJ)J
 */
JNIEXPORT jlong JNICALL Java_net_imglib2_paramaxflow_Parametric_GetNextRegion
  (JNIEnv *, jclass, jlong ptr_this, jlong ptr_r)
{
	Parametric* p = reinterpret_cast< Parametric* >( ptr_this );
	return reinterpret_cast< jlong>( p->GetNextRegion( reinterpret_cast< Parametric::RegionId >( ptr_r ) ) );
}

/*
 * Class:     net_imglib2_paramaxflow_Parametric
 * Method:    GetPreviousRegion
 * Signature: (JJ)J
 */
JNIEXPORT jlong JNICALL Java_net_imglib2_paramaxflow_Parametric_GetPrevRegion
  (JNIEnv *, jclass, jlong ptr_this, jlong ptr_r)
{
	Parametric* p = reinterpret_cast< Parametric* >( ptr_this );
	return reinterpret_cast< jlong>( p->GetPrevRegion( reinterpret_cast< Parametric::RegionId >( ptr_r ) ) );
}

/*
 * Class:     net_imglib2_paramaxflow_Parametric
 * Method:    GetRegionLambda
 * Signature: (JJ)D
 */
JNIEXPORT jdouble JNICALL Java_net_imglib2_paramaxflow_Parametric_GetRegionLambda
  (JNIEnv *, jclass, jlong ptr_this, jlong ptr_r)
{
	Parametric* p = reinterpret_cast< Parametric* >( ptr_this );
	return p->GetRegionLambda( reinterpret_cast< Parametric::RegionId >( ptr_r ) );
}
