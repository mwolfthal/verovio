/*
 * Copyright (c) 2005 - 2023 Marvin Wolfthal. All Rights Reserved.
 */
package org.rismch.verovio.utils;

import org.rismch.verovio.VrvException;

import java.util.concurrent.atomic.AtomicBoolean;

/**
 * @param <T1>
 * @param <T2>
 * @author Marvin Wolfthal
 * @since 12/10/11
 * <p>
 * Immutable class wraps a pair of objects of arbitrary types
 */
public class ObjectPair<T1, T2>
{
    private final String LEFT_BRACKET_STR = "[";
    private final String RIGHT_BRACKET_STR = "]";
    private T1 o1;
    private T2 o2;
    /**
     * serialize access to the flag
     */
    private final AtomicBoolean isSet =
        new AtomicBoolean( false );

    public ObjectPair()
    {
    }

    /**
     * @param o1
     *     the {@code T1} object
     * @param o2
     *     the {@code T2} object
     */
    public ObjectPair(
        final T1 o1,
        final T2 o2 )
    {
        this.o1 = o1;
        this.o2 = o2;
        isSet.set( true );
    }

    /**
     * @return boolean
     * Whether the objects have been set.
     */
    public synchronized boolean isSet()
    {
        return isSet.get();
    }

    /**
     * @param o1
     *     {@code T1}
     * @param o2
     *     {@code T2}
     * @throws org.rismch.verovio.VrvException
     *     if the objects have already been set
     */
    public synchronized void setObjects(
        final T1 o1,
        final T2 o2 )
        throws VrvException
    {
        if ( isSet.get() )
        {
            throw new VrvException( "Objects already set" );
        }
        this.o1 = o1;
        this.o2 = o2;
        isSet.set( true );
    }

    public T1 getO1()
    {
        return o1;
    }

    public T2 getO2()
    {
        return o2;
    }

    @Override
    public String toString()
    {
        return LEFT_BRACKET_STR +
               "o1:" + o1.getClass().getName() +
               ":" + o1.toString() +
               " " +
               "o2:" + o2.getClass().getName() +
               ":" + o2.toString() +
               RIGHT_BRACKET_STR;
    }
}
