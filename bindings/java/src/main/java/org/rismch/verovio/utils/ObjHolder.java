
package org.rismch.verovio.utils;

import org.rismch.verovio.VrvException;

/**
 * A simple parameterized container to be used as
 * an inout parameter.
 * <p/>
 * If the contained object is null, then it can be replaced.
 * Otherwise isReplaceable determines whether the contained
 * object can be reset to another instance.
 * <p/>
 * There is no mutator for the flag to prevent it from being reset.
 *
 * @param <T>
 */
public class ObjHolder<T>
{
    private T obj;
    /**
     * isRepleaceable
     * true by default
     */
    private boolean isReplaceable = true;

    public ObjHolder()
    {
    }

    public ObjHolder( final T obj )
    {
        this.obj = obj;
    }

    /**
     * @throws org.rismch.verovio.VrvException
     *     if obj is null and isRepleaceable is false
     *     Of course the object may become null later if
     *     it is not null now and replacement is allowed
     */
    public ObjHolder(
        final T obj,
        final boolean isReplaceable )
        throws VrvException
    {
        if ( null == obj && !isReplaceable )
        {
            throw new VrvException( "isReplaceable may not be false if obj is null" );
        }
        this.obj = obj;
        this.isReplaceable = isReplaceable;
    }

    /**
     * @return T
     * the contained object
     */
    public synchronized T getObj()
    {
        return obj;
    }

    /**
     * @param obj
     *     the contained object
     * @throws VrvException
     *     if isReplaceable is false and
     *     an attempt is made to replace the contained object.
     *     Note that we don't check whether {@code obj} is null - it may
     *     not have been null to begin with and the flag set to true,
     *     allowing it to become null.
     */
    public synchronized void setObj( final T obj ) throws VrvException
    {
        if ( !isReplaceable )
        {
            throw new VrvException( "replacement not allowed" );
        }
        this.obj = obj;
    }

    /**
     * @return boolean
     */
    public boolean getIsReplaceable()
    {
        return isReplaceable;
    }
}
