module org.rismch.verovio
{
    requires java.base;
    requires java.compiler;
    requires java.desktop;
    requires java.naming;
    requires java.sql;
    requires java.sql.rowset;
    requires java.xml;
    requires java.management;

    requires ch.qos.logback.core;
    requires org.apache.commons.lang3;
    requires org.jetbrains.annotations;
    requires org.slf4j;
    exports org.rismch.verovio.logging to ch.qos.logback.core;
}
