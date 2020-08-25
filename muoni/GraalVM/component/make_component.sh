#!/usr/bin/env bash

if [[ $HADRON_BUILD_COMPONENT == "false" ]]; then
    echo "Skipping the native image build because HADRON_BUILD_COMPONENT is set to false."
    exit 0
fi

COMPONENT_DIR="component_temp_dir"
LANGUAGE_PATH="$COMPONENT_DIR/jre/languages/hadron"
if [[ -f ../native/hadronnative ]]; then
    INCLUDE_HADRONNATIVE="TRUE"
fi

rm -rf COMPONENT_DIR

mkdir -p "$LANGUAGE_PATH"
cp ../language/target/hadron.jar "$LANGUAGE_PATH"

mkdir -p "$LANGUAGE_PATH/launcher"
cp ../launcher/target/hadron-launcher.jar "$LANGUAGE_PATH/launcher/"

mkdir -p "$LANGUAGE_PATH/bin"
cp ../hadron $LANGUAGE_PATH/bin/
if [[ $INCLUDE_HADRONNATIVE = "TRUE" ]]; then
    cp ../native/hadronnative $LANGUAGE_PATH/bin/
fi

touch "$LANGUAGE_PATH/native-image.properties"

mkdir -p "$COMPONENT_DIR/META-INF"
{
    echo "Bundle-Name: Hadron";
    echo "Bundle-Symbolic-Name: net.joelcourtney.hadron";
    echo "Bundle-Version: 19.2.0";
    echo 'Bundle-RequireCapability: org.graalvm; filter:="(&(graalvm_version=19.2.0)(os_arch=amd64))"';
    echo "x-GraalVM-Polyglot-Part: True"
} > "$COMPONENT_DIR/META-INF/MANIFEST.MF"

(
cd $COMPONENT_DIR || exit 1
jar cfm ../hadron-component.jar META-INF/MANIFEST.MF .

echo "bin/hadron = ../jre/languages/hadron/bin/hadron" > META-INF/symlinks
if [[ $INCLUDE_HADRONNATIVE = "TRUE" ]]; then
    echo "bin/hadronnative = ../jre/languages/hadron/bin/hadronnative" >> META-INF/symlinks
fi
jar uf ../hadron-component.jar META-INF/symlinks

{
    echo "jre/languages/hadron/bin/hadron = rwxrwxr-x"
    echo "jre/languages/hadron/bin/hadronnative = rwxrwxr-x"
} > META-INF/permissions
jar uf ../hadron-component.jar META-INF/permissions
)
rm -rf $COMPONENT_DIR
