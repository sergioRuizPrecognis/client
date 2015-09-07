/*
 * Copyright (C) by Roeland Jago Douma <roeland@famdouma.nl>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 */

#ifndef OCSSHAREJOB_H
#define OCSSHAREJOB_H

#include "networkjobs.h"
#include "accountfwd.h"
#include <QVector>
#include <QList>
#include <QPair>

namespace OCC {

/**
 * @brief The OcsShareJob class
 * @ingroup gui
 */
class OcsShareJob : public AbstractNetworkJob {
    Q_OBJECT
public:

    /**
     * Create a call the OCS Share API
     *
     * @param verb Http verb (GET, PUT, DELETE)
     * @param path Path relative to base url: ocs/v1.php/apps/files_sharing/api/v1/shares
     * @param account The account to send this request to
     * @param parent The parent object
     */
    explicit OcsShareJob(const QByteArray& verb, const QString& path, AccountPtr account, QObject* parent = 0);

    /**
     * Set the get params to the url
     *
     * @param getParams list of pairs to add
     */
    void setGetParams(const QList<QPair<QString, QString> >& getParams);

    void setPostParams(const QList<QPair<QString, QString> >& postParams);
    void addPassStatusCode(int code);

    static int getJsonReturnCode(const QVariantMap &json, QString &message);

public slots:
    void start() Q_DECL_OVERRIDE;
signals:
    void jobFinished(QVariantMap reply);
private slots:
    virtual bool finished() Q_DECL_OVERRIDE;
private:
    QByteArray _verb;
    QUrl _url;
    QList<QPair<QString, QString> > _postParams;
    QVector<int> _passStatusCodes;
};

}

#endif // OCSSHAREJOB_H
